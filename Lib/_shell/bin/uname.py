"""
Print operating system name.
"""

import sys
import os
import argparse

def main():

    if len(sys.argv) == 1:
        sys.argv.append("-a")

    parser = argparse.ArgumentParser()
    parser.add_argument("directory", default=".", nargs="*")
    parser.add_argument("-a", action="store_true", help="")
    parser.add_argument("-m", action="store_true", help="")
    parser.add_argument("-n", action="store_true", help="")
    parser.add_argument("-p", action="store_true", help="")
    parser.add_argument("-r", action="store_true", help="")
    parser.add_argument("-s", action="store_true", help="")
    parser.add_argument("-v", action="store_true", help="")
    args = parser.parse_args()
    
    if args.a:
        values = list(os.uname())
    else:
        values = []
        if args.m:
            values.append(os.uname().machine)
        
        if args.n:
            values.append(os.uname().nodename)

        if args.p:
            values.append("arm")

        if args.r:
            values.append(os.uname().release)

        if args.s:
            values.append(os.uname().sysname)

        if args.v:
            values.append(os.uname().version)

    print(" ".join(values))
    
        
if __name__ == "__main__":
    main()