"""
Print arguments.
"""

import sys

def main():
    try:
        del sys.argv[0]
        print(" ".join(sys.argv))
    except IndexError:
        pass

if __name__ == "__main__":
    main()