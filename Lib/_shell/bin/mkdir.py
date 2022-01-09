"""
Make directories.

usage: mkdir [-h] [-p] directories [directories ...]
"""

import argparse
import shutil
import os


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('directories', metavar='directories', type=str, nargs='+',
                        help='directories to create')
    parser.add_argument('-p', dest='intermediate', action='store_true',
                        help='create intermediate directories if required')
    
    args = parser.parse_args()

    for dir in args.directories:
        if args.intermediate:
            os.makedirs(dir)
        else:
            os.mkdir(dir)

if __name__ == "__main__":
    main()