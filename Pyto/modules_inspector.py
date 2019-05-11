"""
Retrieves modules to show them.
"""

import sys
import pyto

def main():
    mods = []
    paths = []

    for key, mod in sys.modules.copy().items():
        mods.append(str(key))
        try:
            paths.append(mod.__file__ or "")
        except Exception:
            paths.append("built-in")

    pyto.ModulesTableViewController.modules = reversed(mods)
    pyto.ModulesTableViewController.paths = reversed(paths)
