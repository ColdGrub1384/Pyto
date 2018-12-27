"""
Use this script for accessing to pip installer.

After executing this script, type arguments you want to pass to pip.
"""

from pip import main
import os

# Code here

os.environ["COLUMNS"] = "100"

args = input("pip ")

main(args.split(" "))

