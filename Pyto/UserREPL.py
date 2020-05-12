"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController
import console
import sys

sys.excepthook = console.excepthook

try:
    console.__runREPL__(__file__.split("/")[-1])
finally:
    del console.__repl_namespace__[__file__.split("/")[-1]]
    REPLViewController.goToFileBrowser()
