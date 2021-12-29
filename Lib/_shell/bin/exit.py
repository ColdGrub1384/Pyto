"""
Exits the Shell.
"""

import __main__

ShellExit = __main__.shell.ShellExit


def main():
    raise ShellExit()


if __name__ == "__main__":
    main()