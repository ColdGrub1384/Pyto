#!/usr/bin/env python3

import sys
import shlex
import os
import subprocess
import numpy as np

args = sys.argv
del args[0]

new_args = ["xcrun"]

is_just_c_not_cpp = True
for arg in sys.argv:
    if arg.endswith(".cpp") or arg.endswith(".cxx") or arg.endswith(".cc"):
        is_just_c_not_cpp = False

for arg in sys.argv:

    if arg.startswith("-std=c++"):
        continue

    if arg.endswith("MacOSX.sdk/usr/include/ffi"):
        continue

    if arg == "-I"+np.get_include():
        print("Ignored Numpy include path")
        continue
    elif arg == "-march=native":
        continue
    elif "MacOSX" in arg or "macosx" in arg:
        if arg.endswith("MacOSX.sdk"):
            arg = subprocess.run("xcrun -sdk iphoneos --show-sdk-path".split(" "), capture_output=True).stdout.decode().split("\n")[0]
        else:
            continue
    else:
        if arg == "-bundle":
            arg = "-shared"
        elif arg == "fPIC":
            arg = "-fPIC"
    new_args.append(arg)

if is_just_c_not_cpp:
    if "scipy/ndimage/src/ni_morphology.c" in " ".join(new_args):
        new_args.append("-std=c11")
else:
    new_args.append("-std=gnu++11")

command = shlex.join(new_args)
sys.exit(os.system(command))
