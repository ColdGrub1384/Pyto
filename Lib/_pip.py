import sys
import os

def default_index():
    try:
        # https://pypi.tuna.tsinghua.edu.cn/simple -> https://pypi.tuna.tsinghua.edu.cn/
        mirror = os.environ["PYPI_MIRROR"]
        splitted = mirror.split("/")
        if splitted[-1] == "":
            splitted = splitted[:-1]
        if splitted[-1] == "simple":
            splitted = splitted[:-1]
        splitted.append("pypi")
        return "/".join(splitted)
    except KeyError:
        return "https://pypi.python.org/pypi"


def _get_modules(bundled_only=False):
    mods = ["rubicon-objc", "toga"]
    for path in sys.path:
        if path.endswith(".zip") or (bundled_only and os.access(path, os.W_OK)):
            continue

        try:
            contents = os.listdir(path)
        except OSError:
            contents = []

        for lib in contents:

            if lib.endswith(".dist-info"):
                with open(os.path.join(path, lib, "METADATA"), mode="r", encoding="utf-8") as f:
                    for line in f.read().split("\n"):
                        if line.startswith("Name: "):
                            mods.append(line.split("Name: ")[1])
                            break
                    
            elif lib.endswith(".egg-info"):
                with open(os.path.join(path, lib, "PKG-INFO"), mode="r", encoding="utf-8") as f:
                    for line in f.read().split("\n"):
                        if line.startswith("Name: "):
                            mods.append(line.split("Name: ")[1])
                            break
    return mods


BUNDLED_MODULES = _get_modules(True)
