"""Change the current working directory.

usage: cd [path]

  path: the new working directory"""

import os
import sys

def main():
    if len(sys.argv) == 2:
        path = os.path.abspath(sys.argv[1])
    elif len(sys.argv) == 1:
        print(__doc__)
        sys.exit(1)
    else:
        print(__doc__)
        raise SystemExit
    
    if path is not None and not os.path.exists(path):
        raise FileNotFoundError(f"'{sys.argv[1]}' does not exist.")
         
    os.chdir(path)
    
if __name__ == "__main__":
    main()