"""
Use this script for accessing to pip installer.
    
After executing this script, type arguments you want to pass to pip.
"""

from pip._internal import main
from sys import version
import os

os.environ["COLUMNS"] = "100" # Sets terminal's horizontal size

if version[0] > "2":
    args = input("pip ") # Asks for arguments
else:
    args = raw_input("pip ") # Asks for arguments

main(args.split(" ")) # Runs pip with typed arguments
