"""
Move files.

usage: mv [-h] source target
"""

import argparse
import shutil


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('source', metavar='source', type=str, nargs=1,
                        help='file to move')
    parser.add_argument('target', metavar='target', type=str, nargs=1,
                        help='the target directory or file')

    args = parser.parse_args()

    shutil.move(args.source[0], args.target[0])
    


if __name__ == "__main__":
    main()