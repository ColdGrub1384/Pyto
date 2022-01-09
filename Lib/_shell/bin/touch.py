"""
Create files

usage: touch file [files ...]
"""

import sys

def main():
    if len(sys.argv) == 1:
        print("usage: touch file [files ...]")
    else:
        for file in sys.argv[1:]:
            open(file, 'a').close()

if __name__ == "__main__":
    main()