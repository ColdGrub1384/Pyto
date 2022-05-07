"""
A shell for running Python modules
"""

import sys
import os
import threading
import shlex
from . import shell

bin_path = os.path.expanduser("~/Documents/bin")

def main(print_header=False):
    if len(sys.argv) > 1:
        shell.process_command(shlex.join(sys.argv[1:]))
        return

    if print_header:
        print("Type the name of a module to run it.\nType \"help\" to get a list of the shell builtins.")
    
    try:
        while True:
            
            try:
                shell.working_directories[threading.current_thread().script_path] = os.getcwd()
            except AttributeError:
                pass

            command = shell.input()

            if bin_path not in sys.path:
                sys.path.insert(0, bin_path)
            
            try:
                prog = command.split(" ")[0]
            except IndexError:
                prog = ""

            try:
                print("\x1b]2;"+shell.get_cwd_title()+" — "+prog+"\007", end="")
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
