import sys
import shlex
from _extensionsimporter import system

def main():
    return system(shlex.join(sys.argv[1:]))

if __name__ == "__main__":
    main()