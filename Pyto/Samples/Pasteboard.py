import Pyto
__builtins__.input = Pyto.input
__builtins__.print = Pyto.print

from rubicon.objc import *
UIPasteboard = ObjCClass("UIPasteboard")

# Code here

print("Your pasteboard is: ")
print(UIPasteboard.generalPasteboard.string)