"""
A shell for running Python modules
"""

import sys
import os
from . import shell

bin_path = os.path.expanduser("~/Documents/bin")

def main(print_header=True):
    
    if print_header:
        print("Type the name of a module to run it as '__main__'.\nRun 'help' to show a list of executable modules.")
    
    try:
        while True:
            
            command = shell.input()

            if bin_path not in sys.path:
                sys.path.insert(0, bin_path)
            
            try:
                shell.process_command(command)
            except shell.ShellExit:
                break
            except SystemExit:
                continue
            except Exception as e:
                print(type(e).__name__+": "+str(e))
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        main(print_header=False)
    except Exception as e:
        print(type(e).__name__+": "+str(e))
        main(print_header=False)
    except SystemExit:
        main(print_header=False)

if __name__ == "__main__":
    main()
