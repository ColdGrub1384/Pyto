"""
Classes from the 'LocalAuthentication' framework.
"""

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None


LAContext = _Class("LAContext")
LAStorage = _Class("LAStorage")
LAClient = _Class("LAClient")
Invalidation = _Class("Invalidation")
