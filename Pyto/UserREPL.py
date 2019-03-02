"""
The REPL. Goes to the file browser when exited.
"""

from console import __runREPL__
from pyto import REPLViewController

try:
    __runREPL__()
finally:
    REPLViewController.goToFileBrowser()
