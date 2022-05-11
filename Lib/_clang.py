"""
The LLVM compiler.
"""

from _extensionsimporter import system
import sys
import shlex

def main():
    args = list(sys.argv)
    args.pop(0)

    try:
        args.remove("-DNDEBUG")
        args.remove("-g")
        args.remove("-fwrapv")
        args.remove("-O3")
    except ValueError:
        pass

    sys.exit(system("clang -DCYTHON_LIMITED_API=1"+shlex.join(args)))

if __name__ == "__main__":
    main()