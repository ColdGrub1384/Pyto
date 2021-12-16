"""
This script asks user for input and runs the given command.
"""

import os
import os.path
import sys
import runpy
import shlex
import weakref
from console import __clear_mods__, MainModule
import threading

if len(sys.argv) == 1:
    usage = "Usage: <module-name> [<args>]"
    print(usage)

# For some reason, after running a module that has a `main()` function,
# the `main()` function from here was replaced by the `main()` function
# from the executed module, like if the namespace from here was merged
# from the namespace of the executed module. Idk how, that's why the weird name.
# I'm pretty sure it's for something I did recently because it worked before.
#
# Dec 2021: Oh I think it has to do with sys.modules["__main__"], that should be fixed now
def _main_function_no_one_calls_a_function_like_that():
    command = sys.argv[1:]
    if len(command) == 0:
        command = []
        args = shlex.split(input("python -m "))
        for arg in args:
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
    if not bin in sys.path:
        sys.path.insert(-1, bin)

    sys.argv = command

    __clear_mods__()
    
    _script_path = threading.current_thread().script_path

    try:
        try:
            sys.modules["argparse"]
        except KeyError:
            pass
        
        _globals = {}
        sys.__class__.main[_script_path] = MainModule(module_name, _globals)
        runpy.run_module(module_name, init_globals=_globals, run_name="__main__")
    except KeyboardInterrupt as e:
        print(e)
    except SystemExit as e:
        try:
            int(e)
        except:
            print(e)
    except Exception as e:
        print(e)
    finally:
        try:
            del sys.__class__.main[_script_path]
        except KeyError:
            pass

    sys.argv = [sys.argv[0]]
    
    if bin in sys.path:
        sys.path.remove(bin)

if len(sys.argv) > 1:
    _main_function_no_one_calls_a_function_like_that()
else:
    while True:
        _main_function_no_one_calls_a_function_like_that()
