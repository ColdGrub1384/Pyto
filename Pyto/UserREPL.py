"""
The REPL. Goes to the file browser when exited.
"""

from console import __runREPL__
from pyto import REPLViewController
import sys
import traceback as tb
from colorama import Fore, Back, Style

def catch(exc, value, traceback):
    message = tb.format_exception(exc, value, traceback)
    
    del message[1]
    
    for part in message:
        if part == message[0]: # Traceback (most recent blah blah blah)
            msg = Fore.RED + part + Style.RESET_ALL
        elif part == message[-1]: # Exception: message
            parts = part.split(":")
            parts[0] = Fore.RED + parts[0] + Style.RESET_ALL
            
            msg = ":".join(parts)
        elif part.startswith("  File"): # File "file", line 1, in function
            parts = part.split(" ")
            parts[3] = Fore.YELLOW + parts[3][:-1] + Style.RESET_ALL + ","
            
            parts = " ".join(parts).split("\n")
            first_line = parts[0].split(" ")
            first_line[-1] = Fore.YELLOW + first_line[-1] + Style.RESET_ALL
            parts[0] = " ".join(first_line)
            msg = "\n".join(parts)
        else:
            msg = part
        
        print(msg, file=sys.stderr, end="")

sys.excepthook = catch

try:
    __runREPL__()
except Exception as e:
    tb.print_exc()
finally:
    REPLViewController.goToFileBrowser()
