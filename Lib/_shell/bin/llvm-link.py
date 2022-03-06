"""
The LLVM linker.
"""

from _extensionsimporter import system
import sys
import shlex

def main():
    args = list(sys.argv)
    args.pop(0)

    system("llvm-link "+shlex.join(args))

if __name__ == "__main__":
    main()