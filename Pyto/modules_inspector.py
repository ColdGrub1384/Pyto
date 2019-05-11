"""
Retrieves modules to show them.
"""

import sys
import pyto

def main():
    mods = []
    paths = []

    modules = sys.modules.copy()
    for key, mod in modules.items():
        mods.append(str(key))
        try:
            file = mod.__file__
            if file != None:
                paths.append(str(file))
            else:
                paths.append("")
        except:
            paths.append("built-in")

    mods.reverse()
    paths.reverse()

    pyto.ModulesTableViewController.modules = mods
    pyto.ModulesTableViewController.paths = paths
