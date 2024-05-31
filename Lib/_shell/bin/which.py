"""
Prints the path of the given module.

usage: which module
"""

import _shell
import sys
import plistlib
import os
from Foundation import NSBundle

with open(str(NSBundle.mainBundle.pathForResource("commandDictionary", ofType="plist")), "rb") as f:
    commands = plistlib.load(f)

def ios_system_command(prog):
    if prog in commands:
        return f"{commands[prog][1]} in {commands[prog][0]}"

def main():
    if len(sys.argv) == 1:
        return print("usage: which module")
    
    framework = ios_system_command(sys.argv[1])
    if framework is not None:
        return print(framework)

    scripts = _shell.shell.get_scripts()
    try:
        for script in os.listdir(os.path.expanduser(os.path.join("~", "Documents", "bin"))):
            scripts[script] = os.path.expanduser(os.path.join("~", "Documents", "bin", script))
    except OSError:
        pass
    if sys.argv[1] in scripts:
        return print(scripts[sys.argv[1]])
    if sys.argv[1]+".py" in scripts:
        return print(scripts[sys.argv[1]+".py"])
    if sys.argv[1]+".py" in os.listdir(os.path.abspath(os.path.dirname(__file__))):
        return print(os.path.join(os.path.abspath(os.path.dirname(__file__)), sys.argv[1]+".py"))
    if sys.argv[1]+".ll" in scripts:
        return print(scripts[sys.argv[1]+".ll"])
    if sys.argv[1]+".bc" in scripts:
        return print(scripts[sys.argv[1]+".bc"])

if __name__ == "__main__":
    main()
