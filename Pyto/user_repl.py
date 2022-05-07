"""
The REPL. Goes to the file browser when exited.
"""

import console
import sys
import traceback
import threading

def main():
    try:

        banner = None
        if "no-banner" in sys.argv:
            banner = "\n\n* REPL restored *\n"

        console.__runREPL__(threading.current_thread().script_path, banner=banner)
    except Exception:
        traceback.print_exc()
    finally:
        del console.__repl_namespace__[threading.current_thread().script_path]

if __name__ == "__main__":
    main()
