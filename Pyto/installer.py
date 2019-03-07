"""
This version of pip is taken from StaSh: https://github.com/ywangd/stash.
    
You can only install PURE PYTHON modules. Libraries that have C, Cython or other programming languages that are not Python will fail to install. Packages can depend on Numpy, Matplotlib, Pandas or other bundled libraries.

Type your command bellow:
"""

from pip import main
import os

print(__doc__)

args = input("pip ") # Asks for arguments

main(args.split(" ")) # Runs pip with typed arguments

