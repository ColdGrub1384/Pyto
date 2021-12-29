"""
A shell for running Python modules
"""

import sys
import os

bin_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "bin")


if bin_path not in sys.path:
    sys.path.append(bin_path)


from . import shell

def main(print_header=True):
    
    if print_header:
        print("Type the name of a module to run it as '__main__'.\nRun 'help' to show a list of executable modules.")
    
    try:
        while True:
            
            command = shell.input()
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

if __name__ == "__main__":
    main()