"""
Copy files.

usage: cp [-h] [-r] source target
"""

import argparse
import os
import shutil


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('source', metavar='source', type=str, nargs=1,
                        help='file to copy')
    parser.add_argument('target', metavar='target', type=str, nargs=1,
                        help='the target directory or file')
    parser.add_argument("-r", dest='recursive', action='store_true',
                        help='copy a directory and its content')

    args = parser.parse_args()

    if os.path.isdir(args.source[0]):
        if not args.recursive:
            raise IsADirectoryError(f"{args.source[0]} is a directory")
        else:
            target = args.target[0]
            if os.path.isdir(target):
                target = os.path.join(target, os.path.basename(os.path.abspath(args.source[0])))
            shutil.copytree(args.source[0], target)
    else:
        shutil.copy(args.source[0], args.target[0])
    


if __name__ == "__main__":
    main()