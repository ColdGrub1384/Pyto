"""
.. code-block:: text

    usage: setup.py [-h] {build,install,clean} ...

    Compile project

    positional arguments:
    {build,install,clean}
        build               build and link sources
        install             build everything and install to ~/Documents
        clean               remove the build directory

    options:
    -h, --help            show this help message and exit
"""

import os
import sys
import shutil
import subprocess
import argparse
import filecmp
from glob import glob
from pathlib import Path


class CompilerError(Exception):
    """ Compiler error """
    
    def __init__(self, source: str, exitcode: int):
        self.message = f"Failed to compile {source}. Exit code: {exitcode}"

class LinkerError(Exception):
    """ Linker error """
    
    def __init__(self, exitcode: int):
        self.message = f"Failed to link product. Exit code: {exitcode}"


def log(msg: str):
    print(msg, file=sys.stderr)


def get_all_sources() -> [Path]:
    gen = (p.resolve() for p in Path(SRC_DIR).glob("**/*") if p.suffix in {".c", ".cc", ".cpp", ".cxx"})
    sources = []
    for source in gen:
        sources.append(source)
    return sources


def build(source: Path) -> str:
    output = source.stem+".ll"
    output = os.path.join(OBJECTS_DIR, output)
    os.makedirs(OBJECTS_DIR, exist_ok=True)
    
    full_path = os.path.abspath(str(source))
    
    for excluded in EXCLUDE_SOURCES:
        _all = glob(os.path.join(SRC_DIR, excluded), recursive=True)
        for file in _all:
            if full_path == os.path.abspath(file):
                log(f"Skipping {file}")
                return
    
    flags = []
    for file in ADDITIONAL_FLAGS.keys():
        src = glob(os.path.join(SRC_DIR, file), recursive=True)
        for _file in src:
            src = os.path.abspath(_file)
        
            if src == full_path:
                flags = ADDITIONAL_FLAGS[file]
    
    cached_source_path = os.path.join(CACHE_DIR, os.path.relpath(str(source), SRC_DIR))

    if not os.path.isdir(os.path.dirname(cached_source_path)):
        os.makedirs(os.path.dirname(cached_source_path), exist_ok=True)
    
    if os.path.isfile(cached_source_path):
        if filecmp.cmp(str(source), cached_source_path, shallow=False):
            return # Cached
        else:
            os.remove(cached_source_path)
    
    shutil.copy(str(source), cached_source_path)
    
    command = [
        CC,
        "-S", "-emit-llvm",
        f"-I{INCLUDE_DIR}"
    ]+ flags +[str(source), "-o", output]
    
    log(" ".join(command))
    
    ret = subprocess.Popen(command).returncode
    if ret != 0:
        os.remove(cached_source_path)
        exc = CompilerError(str(source), ret)
        raise exc
    
    return output


def link_all():
    result = [os.path.join(dp, f) for dp, dn, filenames in os.walk(OBJECTS_DIR) for f in filenames if os.path.splitext(f)[1] == ".ll"]
    
    command = [LD]
    for file in result:
        command.append(file)
        
    additional_libs = (p.resolve() for p in Path(LIB_DIR).glob("**/*") if p.suffix in {".ll", ".bc"})
    for lib in additional_libs:
        command.append(str(lib))
        
    for lib in LINK_LIBRARIES:
        abspath = os.path.abspath(lib, os.path.expanduser("~/Documents/lib"))
        _all = (p.resolve() for p in Path(abspath).glob("**/*") if p.suffix in {".ll", ".bc"})
        for lib in _all:
            command.append(str(lib))
    
    command.append("-o")
    command.append(EXE_PATH)
    
    os.makedirs(os.path.dirname(EXE_PATH), exist_ok=True)
    
    log(" ".join(command))
    
    ret = subprocess.Popen(command).returncode
    if ret != 0:
        exc = LinkerError(ret)
        raise exc


def copy_headers():
    
    if os.path.exists(PUBLIC_HEADERS_PATH):
        shutil.rmtree(PUBLIC_HEADERS_PATH)
        
    shutil.copytree(INCLUDE_DIR, PUBLIC_HEADERS_PATH, dirs_exist_ok=True)
    
    for _header in PUBLIC_HEADERS:
        header = os.path.join(SRC_DIR, _header)
        paths = glob(header, recursive=True)
        for _path in paths:
            path = os.path.abspath(_path)
            rel = os.path.relpath(path, SRC_DIR)
            log(f"Copying {rel}")
            
            new_path = os.path.join(PUBLIC_HEADERS_PATH, rel)
            os.makedirs(os.path.dirname(new_path), exist_ok=True)
            shutil.copy(path, new_path)


def run():
    log(f"Running {EXE_PATH}\n")
    ret = subprocess.Popen(["lli", EXE_PATH]).returncode
    log(f"Exit code: {ret}")


def install():
    bin_path = os.path.abspath(os.getenv("PATH"))
    include_path = os.path.join(os.path.dirname(bin_path), "include", PRODUCT_NAME)    
    lib_path = os.path.join(os.path.dirname(bin_path), "lib", PRODUCT_NAME) 
    
    shutil.copytree(os.path.join(BUILD_DIR, "bin"), bin_path, dirs_exist_ok=True)
    shutil.copytree(PUBLIC_HEADERS_PATH, include_path, dirs_exist_ok=True)
    shutil.copytree(OBJECTS_DIR, lib_path, dirs_exist_ok=True)
    if os.path.isdir(os.path.join(lib_path, ".cache")):
        shutil.rmtree(os.path.join(lib_path, ".cache"))


def main(config_globals: dict):
    """
    Compile C/C++ project.

    :param config_globals: A dictionary that needs to contain the following keys:

    - ``PRODUCT_NAME``: The name of the built executable.
    - ``EXCLUDE_SOURCES``: Prevent these sources from compiling (Relative to SRC_DIR, can contain asterisks (*)).
    - ``PUBLIC_HEADERS``: Copy these headers to build/include (Relative to SRC_DIR, can contain asterisks (*)).
    - ``ADDITIONAL_FLAGS``: Additional flags passed to the compiler. A dictionary of paths and their respective flags as a list of strings. File paths can contain asterisks (*) and are relative to SRC_DIR.
    - ``LINK_LIBRARIES``: A list of directories. Will link everything inside these directories. Relative to ~/Documents/lib.
    - ``CC``: Compiler
    - ``LD``: Linker
    - ``SRC_DIR``: Compile everything here
    - ``LIB_DIR``: Link everything here that ends with .ll or .bc
    - ``INCLUDE_DIR``: Include as a header search path and copy content as public headers
    - ``BUILD_DIR``: The directory containing the build files.

    Optional values:

    - ``OBJECTS_DIR``: Default to ``BUILD_DIR``/lib/``PRODUCT_NAME``
    - ``PUBLIC_HEADERS_PATH``: Default to ``BUILD_DIR``/include
    - ``EXE_PATH``: Default to ``BUILD_DIR``/bin/``PRODUCT_NAME``.bc
    - ``CACHE_DIR``: Default to ``OBJECTS_DIR``/.cache
    """

    vars = ["PRODUCT_NAME",
        "EXCLUDE_SOURCES",
        "PUBLIC_HEADERS",
        "ADDITIONAL_FLAGS",
        "LINK_LIBRARIES",
        "CC",
        "LD",
        "SRC_DIR",
        "LIB_DIR",
        "INCLUDE_DIR",
        "BUILD_DIR",
        "OBJECTS_DIR",
        "PUBLIC_HEADERS_PATH",
        "EXE_PATH",
        "CACHE_DIR",
    ]

    for (key, value) in config_globals.items():
        if key in vars:
            globals()[key] = value

    if "BUILD_DIR" not in globals():
        print("Missing 'BUILD_DIR'", file=sys.stderr)
        raise KeyError
    
    if "PRODUCT_NAME" not in globals():
        print("Missing 'PRODUCT_NAME'", file=sys.stderr)
        raise KeyError


    if "OBJECTS_DIR" not in config_globals:
        globals()["OBJECTS_DIR"] = os.path.join(BUILD_DIR, "lib", PRODUCT_NAME)
    
    if "PUBLIC_HEADERS_PATH" not in config_globals:
        globals()["PUBLIC_HEADERS_PATH"] = os.path.join(BUILD_DIR, "include")

    if "EXE_PATH" not in config_globals:
        globals()["EXE_PATH"] = os.path.join(BUILD_DIR, "bin", PRODUCT_NAME+".bc")
    
    if "CACHE_DIR" not in config_globals:
        globals()["CACHE_DIR"] = os.path.join(os.path.dirname(OBJECTS_DIR), ".cache")
    

    for key in vars:
        if key not in globals():
            print(f"Missing '{key}'", file=sys.stderr)
            raise KeyError

    os.chdir(os.path.dirname(os.path.realpath(config_globals["__file__"])))
    
    parser = argparse.ArgumentParser(
                    prog="setup.py",
                    description="Compile project")

    subparsers = parser.add_subparsers(dest="command")
    subparsers.required = True
    build_parser = subparsers.add_parser("build", help="build and link sources")
    install_parser = subparsers.add_parser("install", help="build everything and install to ~/Documents")
    clean_parser = subparsers.add_parser("clean", help="remove the build directory")
    
    build_parser.add_argument("-r", "--run", help="run executable after compilation", action='store_true')
    build_parser.add_argument("-n", "--nocache", help="don't cache source files and compile everything", action='store_true')
    install_parser.add_argument("-r", "--run", help="run executable after compilation", action='store_true')
    args = parser.parse_args()
    
    if args.command == "clean":
        shutil.rmtree(BUILD_DIR)
        return
    
    if args.command == "install" or args.nocache:
        if os.path.exists(CACHE_DIR):
            shutil.rmtree(CACHE_DIR)
    
    for source in get_all_sources():
        build(source)
        
    link_all()
    copy_headers()
    
    if args.command == "install":
        install()
    
    if args.run:
        run()

