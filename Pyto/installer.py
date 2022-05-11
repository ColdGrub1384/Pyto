import traceback
import sys
from _shell.bin import python

def main():
    
    if hasattr(sys, "sys"):
        sys.sys.stdout = sys.sys.__stdout__
        sys.sys.stderr = sys.sys.__stderr__
        sys.stdout = sys.sys.stdout
        sys.stderr = sys.sys.stderr
        sys.__stdout__ = sys.stdout
        sys.__stderr__ = sys.stderr
    
    for mod in list(sys.modules.keys()):
        if mod.startswith("setuptools") or mod.startswith("distutils") or mod.startswith("pkg_resources"):
            del sys.modules[mod]

    try:
        del sys.argv[0]
        sys.argv.insert(0, "pip")
        sys.argv.insert(0, "-m")
        sys.argv.insert(0, "python")
        while sys.argv[-1] == "":
            del sys.argv[-1]
        python.main()
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()
