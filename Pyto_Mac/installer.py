"""
Use this script for accessing to pip installer.
    
After executing this script, type arguments you want to pass to pip.
"""

from pip._internal import main
import os

os.environ["COLUMNS"] = "100" # Sets terminal's horizontal size

args = input("pip ") # Asks for arguments

main(args.split(" ")) # Runs pip with typed arguments
