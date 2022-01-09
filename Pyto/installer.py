import traceback
import sys
from _shell.bin import python

def main():
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
        sys.__stderr__.write(traceback.format_exc())

if __name__ == "__main__":
    main()
