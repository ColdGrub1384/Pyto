"""
Python interpreter.

usage: python [-c cmd | -m mod | file] [arg]
"""

import sys
import os
import runpy
import _shell
import shlex
import traceback as tb
from user_repl import main as repl_main
from console import __clear_mods__

_usage = "usage: python [-c cmd | -m mod | file | -] [arg]"


class Path:
    
    def __init__(self, path):
        self.path = path
        self.old_path = sys.path
    
    def __enter__(self):
        sys.path = self.path
    
    def __exit__(self, exc_type, exc, tb):
        sys.path = self.old_path
        if exc is not None:
            raise exc


def main():
    if len(sys.argv) == 1:
        if sys.stdin.isatty():
            repl_main()
        else:
            exec(sys.stdin.read())
        return

    __clear_mods__()

    if sys.argv[1] == "-u":
        del sys.argv[1]

    if sys.argv[1] == "-c":
        try:
            _code = sys.argv[2] # python -c "import sys; print(sys.argv)" foo bar
            sys.argv.pop(0) # -c "import sys; print(sys.argv)" foo bar
            sys.argv.pop(0) # "import sys; print(sys.argv)" foo bar
            sys.argv[0] = "-c" # -c foo bar
        except IndexError:
            print(_usage, file=sys.stderr)
            sys.exit(1)
        
        exec(_code)
    elif sys.argv[1] == "-m":
        try:
            sys.argv.pop(0)
            sys.argv.pop(0)

            for mod in list(sys.modules.keys()):
                if mod.startswith(sys.argv[0]):
                    del sys.modules[mod]
        except IndexError:
            print(_usage, file=sys.stderr)
            sys.exit(1)

        runpy.run_module(sys.argv[0], run_name="__main__")

    elif sys.argv[1] == "-h" or sys.argv[1] == "--help":
        print(_usage, file=sys.stderr)
        sys.exit(1)

    else:
        
        sys.argv.pop(0)
        
        try:
            with Path(sys.path+[os.path.dirname(sys.argv[0])]):
                runpy.run_path(sys.argv[0], run_name="__main__")
        except Exception as e:
            tb.print_exc()
            sys.exit(1)

if __name__ == "__main__":
    main()
