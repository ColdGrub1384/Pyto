"""
All included third party librairies will be downloaded for offline usage.
This may take a while. Some libraries will be stuck at 0% for a few moments but will be downloaded after a while.
"""

from rubicon.objc import ObjCClass
from plistlib import load
import importlib

NSBundle = ObjCClass("NSBundle")

plist_path = str(NSBundle.mainBundle.pathForResource("OnDemandLibraries", ofType="plist"))

print(__doc__)

with open(plist_path, "rb") as p:
    dict = load(p)
    for key in list(dict.keys()):
        try:
            mod = importlib.__import__(key.replace("bio", "Bio"))
            print(mod)
        except ModuleNotFoundError:
            pass

print("Done")
