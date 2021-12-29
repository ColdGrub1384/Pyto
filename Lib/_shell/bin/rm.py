"""
Remove files.

usage: rm [-h] [-r] [-d] files [files ...]
positional arguments:
  files       files to remove
options:
  -h, --help  show this help message and exit
  -r          remove files recursively
  -d          remove directories
"""

import argparse
import shutil
import os


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('files', metavar='files', type=str, nargs='+',
                        help='files to remove')
    parser.add_argument('-r', dest='recursively', action='store_true',
                        help='remove files recursively')
    parser.add_argument('-d', dest='directories', action='store_true',
                        help='remove directories')
    
    args = parser.parse_args()

    for file in args.files:
        if os.path.isdir(file):
            if args.recursively:
                shutil.rmtree(file)
            elif args.directories:
                os.rmdir(file)
            else:
                os.remove(file)
        else:
            os.remove(file)

if __name__ == "__main__":
    main()