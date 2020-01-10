"""
This script asks user for input and runs the given command.
"""

import os
import os.path
import sys
import traceback
import pyto
import runpy

if len(sys.argv) == 1:
    usage = "Usage: <module-name> [<args>]"
    print(usage)

def main():
    command = sys.argv[1:]
    if len(command) == 0:
        command = []
        for arg in list(pyto.EditorViewController.parseArguments(input("python -m "))):
            command.append(str(arg))
    if len(command) == 0:
        print(usage)
        return
    module_name = command[0]

    try:
        del sys.modules[module_name]
    except KeyError:
        pass
    
    bin = os.path.expanduser("~/Documents/stash_extensions/bin")
    sys.path.insert(-1, bin)

    sys.argv = command

    try:
        runpy._run_module_as_main(module_name)
    except KeyboardInterrupt:
        pass
    except SystemExit:
        pass
    except:
        print(traceback.format_exc())

    sys.argv = [sys.argv[0]]

if len(sys.argv) > 1:
    main()
else:
    while True:
        main()
