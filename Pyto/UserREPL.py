"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController
import console
import sys

try:

    banner = None
    if "no-banner" in sys.argv:
        banner = "\n\n* REPL restored *\n"

    console.__runREPL__(__file__.split("/")[-1], banner=banner)
<<<<<<< HEAD
    print("Done")
except Exception as e:
    print(str(e))
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
finally:
    del console.__repl_namespace__[__file__.split("/")[-1]]
    REPLViewController.goToFileBrowser()

