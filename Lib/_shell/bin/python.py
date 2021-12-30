"""
Python interpreter.

usage: python3 [-c cmd | -m mod | file] [arg]
"""

import sys
import os.path
import pyto
import runpy
import code

_usage = "usage: python3 [-c cmd | -m mod | file | -] [arg]"

def main():
    if len(sys.argv) == 1:
        code.interact()
    elif sys.argv[1] == "-c":
        try:
            exec(sys.argv[2])
        except IndexError:
            print(_usage)
    elif sys.argv[1] == "-m":
        
        bin = os.path.expanduser("~/Documents/stash_extensions/bin")
        if not bin in sys.path:
            sys.path.insert(-1, bin)
        
        sys.argv.pop(0)
        sys.argv.pop(0)
        
        runpy._run_module_as_main(sys.argv[0])
        
        if bin in sys.path:
            sys.path.remove(bin)

    elif os.path.isfile(sys.argv[1]):
        
        sys.argv.pop(0)
        
        runpy.run_path(sys.argv[0], run_name="__main__")

    else:
        print(_usage)

if __name__ == "__main__":
    main()
