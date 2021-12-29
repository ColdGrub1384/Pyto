"""Show the help text of the given program.

usage: man program """

import sys
import runpy

def main():
    
    if len(sys.argv) != 2:
        print(__doc__)
        raise SystemExit
    
    mod = runpy.run_module(sys.argv[1], run_name=sys.argv[1])
    
    print(mod["__doc__"])

if __name__ == "__main__":
    main()