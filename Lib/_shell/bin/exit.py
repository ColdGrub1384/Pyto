"""
Exits the Shell.
"""

import _shell

ShellExit = _shell.shell.ShellExit


def main():
    raise ShellExit()


if __name__ == "__main__":
    main()