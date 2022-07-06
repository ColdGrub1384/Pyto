import builtins
import shlex
import runpy
import sys
import os
import glob
import io
from .bin import which
from subprocess import Popen
from console import __clear_mods__
from pyto import FileBrowserViewController
from Foundation import NSFileManager

def get_scripts():
    scripts = {}
    for path in sys.path:
        try:
            for file in os.listdir(os.path.join(path, "bin")):
                scripts[file] = os.path.join(path, "bin", file)
        except OSError:
            continue
    return scripts

class ShellExit(BaseException):
    pass


class Arguments:
    
    def __init__(self, args):
        self.args = args
        self.old_args = sys.argv
    
    def __enter__(self):
        sys.argv = self.args
    
    def __exit__(self, exc_type, exc, tb):
        sys.argv = self.old_args
        if exc is not None and exc_type is not SystemExit:
            raise exc


class Path:
    
    def __init__(self, path):
        self.path = path
        self.old_path = sys.path
    
    def __enter__(self):
        sys.path = self.path
    
    def __exit__(self, exc_type, exc, tb):
        sys.path = self.old_path
        if exc is not None and exc_type is not SystemExit:
            raise exc


def get_cwd_title():
    cwd = os.path.abspath(".")
    if FileBrowserViewController.iCloudContainerURL and str(FileBrowserViewController.iCloudContainerURL.path) == cwd:
        title = "iCloud Drive"
    else:
        title = str(NSFileManager.defaultManager.displayNameAtPath(cwd))
    return title

def input():
    print("\x1b]2;"+get_cwd_title()+"\007", end="")
    return builtins.input("$ ")


working_directories = {}

def parse(cmd: str) -> str:
    lex = shlex.shlex(cmd, posix=True, punctuation_chars=True)
    lex.whitespace_split = True
    command = list(lex)
    return command

def process_command(cmd: str, name: str = "__main__"):

    args = ""
    quote = None
    prev = ""
    for char in cmd:
        if char == "'" and quote is None:
            quote = "'"
        elif char == '"' and quote is None:
            quote = '"'
        elif char == "'" and quote == "'":
            quote = None
        elif char == '"' and quote == '"':
            quote = None

        if (char == "*" and quote is not None and prev != "\\") or (char == "*" and quote is None and prev == "\\"):
            char = "$ESCAPED_GLOB$"
        
        if (char == ">" and quote is not None and prev != "\\") or (char == ">" and quote is None and prev == "\\"):
            char = "$ESCAPED_ARROW_RIGHT$"

        if (char == "<" and quote is not None and prev != "\\") or (char == "<" and quote is None and prev == "\\"):
            char = "$ESCAPED_ARROW_LEFT$"
        
        args += char
        prev = char

    cmd = args
    cmd = cmd.replace("\\*", "$ESCAPED_GLOB$") # Don't glob escaped *

    comp = parse(cmd)

    commands = [[]]
    i = 0
    for arg in comp:

        if arg == ";":
            i += 1
            commands.append([])
            continue

        commands[i].append(arg)

    for command in commands:

        pipes = [[]]
        i = 0
        for arg in command:

            if arg == "|":
                i += 1
                pipes.append([])
                continue

            pipes[i].append(arg)
        
        i = 0
        stdin = None
        for pipe in pipes:
            try:
                pipes[i+1]
                stdout = io.StringIO()
            except IndexError:
                stdout = None
            
            parse_args(pipe, name, stdout, stdin)
            if stdout is not None:
                output = stdout.getvalue()
                if output.endswith("\n"):
                    output = output[:-1]
                stdin = io.StringIO(output)
            i += 1

def parse_args(comp: list[str], name: str, _stdout = None, _stdin = None):

    comp = list(map(os.path.expanduser, comp))
    comp = list(map(os.path.expandvars, comp))

    new_comp = []
    for arg in comp:
        arg = arg.replace("$ESCAPED_ARROW_RIGHT$", ">")
        arg = arg.replace("$ESCAPED_ARROW_LEFT$", "<")

        if "$ESCAPED_GLOB$" in arg:
            new_comp.append(arg.replace("$ESCAPED_GLOB$", "*"))
            continue

        files = glob.glob(arg)
        if len(files) > 0:
            new_comp += files
        else:
            new_comp.append(arg)
    
    comp = []

    stdout_path = None
    stdout_mode = None

    stdin_path = None

    i = 0
    ignore_index = None
    for arg in new_comp:
        if ignore_index is not None and ignore_index == i:
            i += 1
            ignore_index = None
            continue

        if arg == ">" or arg == ">>":
            try:
                stdout_path = new_comp[i+1]
                if arg == ">":
                    stdout_mode = "w+"
                elif arg == ">>":
                    stdout_mode = "a+"

                ignore_index = i+1
                i += 1
                continue
            except IndexError:
                msg = "no stdout file specified"
                raise IndexError(msg)
        
        if arg == "<":
            try:
                stdin_path = new_comp[i+1]
                ignore_index = i+1
                i += 1
                continue
            except IndexError:
                msg = "no stdout file specified"
                raise IndexError(msg)


        comp.append(arg)
        i += 1

    try:
        prog = comp[0]
    except IndexError:
        return

    _dict = None

    __clear_mods__()        

    scripts = get_scripts()

    def run_binary(path):
        with open(path, "r") as f:
            _dict = { "__name__": name, "__file__": path }
            if name == "__main__":
                try:
                    code = f.read()
                    exec(code, _dict, {})
                finally:
                    return _dict
            else:
                return _dict

    og_stdout = sys.stdout
    if stdout_path is not None:
        stdout = open(stdout_path, stdout_mode)
    elif _stdout is not None:
        stdout = _stdout
    else:
        stdout = sys.stdout

    og_stdin = sys.stdin
    if stdin_path is not None:
        stdin = open(stdin_path, "r")
    elif _stdin is not None:
        stdin = _stdin
    else:
        stdin = sys.stdin

    sys.stdout = stdout
    sys.stdin = stdin
    try:
        with Arguments(comp) as _:
            script_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "bin", prog+".py")
            documents_bin_script_path = os.path.join(os.path.expanduser("~/Documents/bin"), prog+".py")
            binary_path = os.path.join(os.path.expanduser("~/Documents/bin"), prog)
            if os.path.isfile(script_path):
                with Path(sys.path+[os.path.dirname(script_path)]) as _:
                    _dict = runpy.run_path(script_path, run_name=name)
            elif os.path.isfile(documents_bin_script_path):
                with Path(sys.path+[os.path.dirname(documents_bin_script_path)]) as _:
                    _dict = runpy.run_path(documents_bin_script_path, run_name=name)
            elif prog in scripts:
                _dict = run_binary(scripts[prog])
            elif prog+".py" in scripts:
                _dict = run_binary(scripts[prog])
            elif os.path.isfile(binary_path):
                _dict = run_binary(binary_path)
            elif prog in which.commands:
                return Popen(comp)
            else:
                print(f"{prog}: command not found", file=sys.stderr)
                sys.exit(1)
    finally:
        sys.stdout = og_stdout
        sys.stdin = og_stdin
        if stdout_path is not None:
            stdout.close()
        if stdin_path is not None:
            stdin.close()
    
    for key in list(sys.modules.keys()):
        if key.startswith("setuptools") or key.startswith("distutils") or key.startswith("_distutils"):
            del sys.modules[key]

    if _dict is not None and "__file__" in _dict:
        return _dict["__file__"] 
