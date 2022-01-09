"""
Prints the path of the given module.

usage: which module
"""

import _shell
import sys

def main():
    if len(sys.argv) == 1:
        return print("usage: which module")
    
    print(_shell.shell.process_command(sys.argv[1], sys.argv[1]))

if __name__ == "__main__":
    main()
