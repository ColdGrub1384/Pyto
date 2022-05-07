import sys
import os
import shutil
import _sharing as sharing
from glob import glob
from _shell.bin import python
from Foundation import NSURL

def clear_mods():
    for mod in list(sys.modules.keys()):
        if mod.startswith("setuptools") or mod.startswith("distutils") or mod.startswith("pkg_resources"):
            del sys.modules[mod]


def delete(paths):
    if isinstance(paths, list):
        for path in paths:
            delete(path)
    else:
        if os.path.isfile(paths):
            print(f"removing {paths}")
            os.remove(paths)
        elif os.path.isdir(paths):
            print(f"removing {paths}")
            shutil.rmtree(paths)


def clean():
    delete([
        "dist",
        "build",
        ".eggs",
    ]+glob("*.egg-info"))


def install():
    sys.argv = ["python", "-m", "pip", "install", "."]
    python.main()


def export_wheel():
    sys.argv = ["python", "setup.py", "bdist_wheel"]
    python.main()
    
    wheels = glob("dist/*.whl")
    if len(wheels) == 0:
        return
    
    wheels_urls = []
    for wheel in wheels:
        wheels_urls.append(NSURL.fileURLWithPath(os.path.abspath(wheel)))
    
    sharing.share_items(wheels_urls)


def main():
    if sys.argv[1] == "clean":
        clean()
    elif sys.argv[1] == "install":
        install()
    elif sys.argv[1] == "export":
        export_wheel()

if __name__ == "__main__":
    clear_mods()
    main()
