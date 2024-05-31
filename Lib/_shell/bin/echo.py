"""
Print arguments.
"""

import sys

def main():
    argv = list(sys.argv)

    try:
        del sys.argv[0]
    except IndexError:
        pass

    if len(sys.argv) > 0:
        print(" ".join(sys.argv))
    else:
        print("")

    sys.argv = argv

if __name__ == "__main__":
    main()