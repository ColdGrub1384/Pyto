"""
The REPL with partial support for code completion and not ran on the main thread so it can be sent to the background.
"""

from console import __runREPL__
from pyto import REPLViewController

try:
    __runREPL__()
finally:
    REPLViewController.goToFileBrowser()
