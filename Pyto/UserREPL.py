"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController
import console
import sys
import traceback

try:

    banner = None
    if "no-banner" in sys.argv:
        banner = "\n\n* REPL restored *\n"

    console.__runREPL__(__file__, banner=banner)
    print("Done")
except Exception:
    traceback.print_exc()
finally:
    del console.__repl_namespace__[__file__]
    REPLViewController.goToFileBrowser()

