"""
The REPL. Goes to the file browser when exited.
"""

from console import __runREPL__, excepthook
from pyto import REPLViewController
import sys

sys.excepthook = excepthook

try:
    __runREPL__()
finally:
    REPLViewController.goToFileBrowser()
