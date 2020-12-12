#!/usr/bin/env python3

import sys
import shlex
import os

args = sys.argv
del args[0]

new_args = ["xcrun"]

is_just_c_not_cpp = True
for arg in sys.argv:
    if arg.endswith(".cpp") or arg.endswith(".cxx"):
        is_just_c_not_cpp = False

for arg in sys.argv:

    if is_just_c_not_cpp and arg.startswith("-std=c++"):
        continue

    if arg == "-march=native":
        continue
    elif "MacOSX" in arg or "macosx" in arg:
        continue
    else:
        if arg == "-bundle":
            arg = "-shared"
        elif arg == "fPIC":
            arg = "-fPIC"
    new_args.append(arg)

command = shlex.join(new_args)
sys.exit(os.system(command))
