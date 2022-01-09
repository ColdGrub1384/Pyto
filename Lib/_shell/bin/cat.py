"""
Print the content of a file.

usage: cat file [files ...]
"""

import sys

def main():
    if len(sys.argv) == 1:
        print("usage: cat file [files ...]")
    else:
        for file in sys.argv[1:]:
            with open(file, "r", encoding="utf-8") as f:
                print(f.read())

if __name__ == "__main__":
    main()