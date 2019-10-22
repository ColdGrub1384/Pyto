"""
This script asks user for input and runs the given command.
"""

import importlib
import os
import sys
import traceback

if len(sys.argv) == 1:
    usage = "Usage: <module-name> [<args>]"
    print(usage)

def main():
    command = sys.argv[1:]
    if len(command) == 0:
        command = input("python -m ").split()
    if len(command) == 0:
        print(usage)
        return
    module_name = command[0]

    try:
        del sys.modules[module_name]
    except KeyError:
        pass

    spec = importlib.util.find_spec(module_name)
    if spec is None:
        print("python: No module named "+module_name)
        return
    module_path = spec.origin

    __main__path = os.path.dirname(module_path)+"/__main__.py"
    if os.path.isfile(__main__path) and os.path.basename(module_path) == "__init__.py":
        module_path = __main__path

    sys.argv = command

    try:
        spec = importlib.util.spec_from_file_location("__main__", module_path)
        script = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(script)
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
