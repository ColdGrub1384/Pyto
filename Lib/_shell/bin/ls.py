"""
List directory contents.

usage: ls [-h] [-a] [-l] [directory ...]
positional arguments:
  directory
options:
  -h, --help  show this help message and exit
  -a          show hidden files
  -l          list with long format
"""

import sys
import argparse
import os
import stat
import datetime
from colorama import Fore
from pwd import getpwuid
from grp import getgrgid

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", default=".", nargs="*")
    parser.add_argument("-a", action="store_true", help="show hidden files")
    parser.add_argument("-l", action="store_true", help="list with long format")
    args = parser.parse_args()

    dirs = args.directory
    if isinstance(dirs, str):
        dirs = [dirs]
    
    output = ""
    
    i = 0
    for dir in dirs:
        path = os.path.expanduser(dir)
        path = os.path.abspath(path)
        
        if len(dirs) > 1:
            print(dir+":", end="\n\n")
        
        files = os.listdir(path)
        files.sort()
        
        if args.a:
            files.insert(0, "..")
            files.insert(0, ".")
        
        for file in files:
           if not file.startswith(".") or args.a:
               
               full_path = os.path.join(path, file)
               
               if not sys.stdout.isatty:
                   file = file
               elif os.path.islink(full_path):
                   file = Fore.MAGENTA+file+Fore.RESET
               elif os.path.isdir(full_path):
                   file = Fore.BLUE+file+Fore.RESET
               
               if not args.l:
                   print(file)
               else:
                   try:
                       _stat = os.stat(full_path, follow_symlinks=False)
                       perm = stat.filemode(_stat.st_mode)
                       owner = getpwuid(_stat.st_uid).pw_name
                       group = getgrgid(_stat.st_uid).gr_name
                       modified = os.path.getctime(full_path)
                       modified = datetime.datetime.fromtimestamp(modified)
                       modified = modified.strftime("%b %d")
                       
                       print(" ".join([perm, owner, group, modified, file]))
                   except PermissionError:
                       print(file)
        
        i += 1
        
        if i != len(dirs) and len(dirs) > 1:
            print()
    
        
if __name__ == "__main__":
    main()