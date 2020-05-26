"""
Bridge between Swift and Python.
"""

from rubicon.objc import ObjCClass
import sys

application = ObjCClass("Python.Application").new()
application.__doc__ = __doc__

sys.modules["application"] = application
