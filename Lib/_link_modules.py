"""
Link modules and the necessary glue code during C extension compilation.
(Internal use only).
"""

import os
import sys
import shlex
from _extensionsimporter import system

def main():
    args = list(sys.argv)
    args.pop(0)
    try:
        args.remove("-S")
        args.remove("-emit-llvm")
    except ValueError:
        pass

    mod = None
    for arg in args:
        if arg.endswith(".cpython-310-darwin.so") or arg.endswith(".abi3.so"):
            mod = arg
            break
    
    glue_path = None
    if mod is not None:
        mod_name = os.path.basename(mod).split(".cpython-310-darwin.so")[0]
        init_function = "PyInit_"+mod_name

        glue_path = os.path.expandvars("$TMP/"+init_function+".ll")

        system(f"clang -S -emit-llvm -DPy_BUILD_CORE=1 -DPy_BUILD_CORE_BUILTIN=1 -I{os.path.expanduser('~/Documents/include/python3.10')} {os.path.expanduser('~/Documents/lib/cext_glue.c')} -DPYINIT_FUNCTION={init_function} -o {glue_path}")

    if glue_path is None or not os.path.isfile(glue_path):
        raise RuntimeError("The compilation of the C extension glue code failed.")

    ret = system("llvm-link "+glue_path+" "+(shlex.join(args)))

    if os.path.isfile(glue_path):
        os.remove(glue_path)
    
    sys.exit(ret)

if __name__ == "__main__":
    main()