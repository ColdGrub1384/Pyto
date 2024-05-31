"""
Show a list of executable modules.
"""

import os
from colorama import Style, Fore
from _shell.bin.which import commands
from Foundation import NSBundle


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
    return file != "__init__" and file != "__pycache__" and file not in ["llvm-link", "clang", "_link_modules", "_system"]


def main():
    builtin = listdir(builtin_path)
    builtin.sort()
    builtin = map(remove_extension, builtin)
    builtin = list(filter(filter_init, builtin))
    
    print("Hi! This shell behaves like most shells, you can run UNIX commands (cat, ls, cd ...).")
    print("stdout and stdin redirection is possible with >, >>, <, |.")
    print("")

    print(f"{Style.BRIGHT}{Fore.GREEN}Builtins{Style.RESET_ALL}\n"+(", ".join(builtin)))
    
    downloaded = listdir(downloaded_path)
    downloaded = list(filter(filter_init, downloaded))
    downloaded.sort()
    downloaded = list(map(remove_extension, downloaded))
    if len(downloaded) > 0:
        print(f"\n{Style.BRIGHT}{Fore.GREEN}~/Documents/bin{Style.RESET_ALL}\n"+(", ".join(downloaded)))

    bin_path = os.path.join(str(NSBundle.mainBundle.pathForResource("site-packages", ofType="")), "bin")
    progs = os.listdir(bin_path)
    progs = list(filter(filter_init, progs))
    progs.sort()
    print(f"\n{Style.BRIGHT}{Fore.GREEN}site-packages/bin{Style.RESET_ALL}\n"+(", ".join(progs)))

    print(f"\n{Style.BRIGHT}{Fore.GREEN}ios_system{Style.RESET_ALL}\n"+(", ".join(list(commands.keys()))))

if __name__ == "__main__":
    main()