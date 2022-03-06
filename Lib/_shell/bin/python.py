"""
Python interpreter.

usage: python [-c cmd | -m mod | file] [arg]
"""

import sys
import os
import runpy
import code
import _shell
import shlex

_usage = "usage: python [-c cmd | -m mod | file | -] [arg]"


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


def main():
    if len(sys.argv) == 1:
        code.interact()
        return

    if sys.argv[1] == "-u":
        del sys.argv[1]

    if sys.argv[1] == "-c":
        try:
            _code = sys.argv[2] # python -c "import sys; print(sys.argv)" foo bar
            sys.argv.pop(0) # -c "import sys; print(sys.argv)" foo bar
            sys.argv.pop(0) # "import sys; print(sys.argv)" foo bar
            sys.argv[0] = "-c" # -c foo bar

            exec(_code)
        except IndexError:
            print(_usage)
    elif sys.argv[1] == "-m":
        sys.argv.pop(0)
        sys.argv.pop(0)

        for mod in list(sys.modules.keys()):
            if mod.startswith(sys.argv[0]):
                del sys.modules[mod]

        _shell.shell.process_command(shlex.join(sys.argv))

    elif os.path.isfile(sys.argv[1]):
        
        sys.argv.pop(0)
        
        with Path(sys.path+[os.path.dirname(sys.argv[0])]):
            runpy.run_path(sys.argv[0], run_name="__main__")

    else:
        print(_usage)

if __name__ == "__main__":
    main()
