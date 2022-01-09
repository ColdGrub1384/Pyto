"""
Print arguments

usage: echo string [strings ...]
"""

import sys

def main():
    print(" ".join(sys.argv[1:]))
    
if __name__ == "__main__":
    main()