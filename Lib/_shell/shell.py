import builtins
import shlex
import runpy
import sys
import os
from colorama import Fore


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


def input():
    prompt = f"{Fore.GREEN}{os.path.basename(os.getcwd())}{Fore.RESET} "
    print(prompt, end="")
    return builtins.input("$ ")


def process_command(cmd):
    comp = shlex.split(cmd)
    comp = list(map(os.path.expanduser, comp))
    comp = list(map(os.path.expandvars, comp))
    try:
        prog = comp[0]
    except IndexError:
        return
    
    with Arguments(comp) as _:
        runpy.run_module(prog, run_name="__main__")
