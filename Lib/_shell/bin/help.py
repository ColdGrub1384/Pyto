"""
Show a list of executable modules.
"""

import os
from colorama import Style


builtin_path = os.path.dirname(os.path.abspath(__file__))
downloaded_path = os.path.expanduser("~/Documents/bin")


def listdir(dir):
    try:
        return os.listdir(dir)
    except FileNotFoundError:
        return []


def remove_extension(file):
    return file.replace(".py", "")


def filter_init(file):
    return file != "__init__"


def main():
    builtin = listdir(builtin_path) + ["pip"]
    builtin.sort()
    builtin = map(remove_extension, builtin)
    builtin = filter(filter_init, builtin)
    
    print(f"{Style.BRIGHT}Builtins{Style.RESET_ALL}\n"+(", ".join(builtin)))
    
    downloaded = listdir(downloaded_path)
    downloaded.sort()
    downloaded = list(map(remove_extension, downloaded))
    if len(downloaded) > 0:
        print(f"\n{Style.BRIGHT}~/Documents/bin{Style.RESET_ALL}\n"+(", ".join(downloaded)))
    
    print(f"\n{Style.BRIGHT}* Everything in sys.path{Style.RESET_ALL}")

if __name__ == "__main__":
    main()