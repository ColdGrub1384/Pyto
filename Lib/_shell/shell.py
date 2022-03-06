import builtins
import shlex
import runpy
import sys
import os
from colorama import Fore, Style


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


def input():
    prompt = f"{Style.BRIGHT}{Fore.GREEN}{os.path.basename(os.getcwd())}{Style.RESET_ALL} "
    print(prompt, end="")
    return builtins.input("$ ")


def process_command(cmd, name="__main__"):
    comp = shlex.split(cmd)
    comp = list(map(os.path.expanduser, comp))
    comp = list(map(os.path.expandvars, comp))
    try:
        prog = comp[0]
    except IndexError:
        return

    if prog == "pip":
        for mod in list(sys.modules.keys()):
            if mod.startswith("distutils") or mod.startswith("pkg_resources") or mod.startswith("pip") or mod.startswith("wheel"):
                del sys.modules[mod]
    
    _dict = None

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
        elif os.path.isfile(binary_path):
            with open(binary_path, "r") as f:
                _dict = { "__name__": name, "__file__": binary_path }
                if name == "__main__":
                    exec(f.read(), _dict, {})
        else:
            for mod in list(sys.modules.keys()):
                if mod.startswith(prog):
                    del sys.modules[mod]
            _dict = runpy.run_module(prog, run_name=name)

    if _dict is not None and "__file__" in _dict:
        return _dict["__file__"] 