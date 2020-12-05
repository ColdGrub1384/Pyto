"""
Classes from the 'MobileKeyBag' framework.
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


MKBKeyStoreDevice = _Class("MKBKeyStoreDevice")
UMPersonaMachPort = _Class("UMPersonaMachPort")
