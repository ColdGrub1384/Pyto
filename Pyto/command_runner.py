"""
This script asks user for input and runs the given command.
"""

import os
import os.path
import sys
import traceback
import pyto
import runpy
from console import __clear_mods__

if len(sys.argv) == 1:
    usage = "Usage: <module-name> [<args>]"
    print(usage)

# For some reason, after running a module that has a `main()` function,
# the `main()` function from here was replaced by the `main()` function
# from the executed module, like if the namespace from here was merged
# from the namespace of the executed module. Idk how, that's why the weird name.
# I'm pretty sure it's for something I did recently because it worked before.
def _main_function_no_one_calls_a_function_like_that():
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

    __clear_mods__()

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
    _main_function_no_one_calls_a_function_like_that()
else:
    while True:
        _main_function_no_one_calls_a_function_like_that()
