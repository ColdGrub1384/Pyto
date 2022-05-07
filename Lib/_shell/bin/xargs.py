"""
Pass the input as arguments to the command passed as an argument.
"""

import sys
from _shell.bin.echo import main as echo
from _shell.shell import process_command
import shlex

def main():
    if len(sys.argv) == 1:
        echo()
    else:
        args = sys.argv[1:]+shlex.split(sys.stdin.read())
        process_command(shlex.join(args))


if __name__ == "__main__":
    main()