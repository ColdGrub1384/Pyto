"""
Classes from the 'IDSKVStore' framework.
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


IDSKVStore = _Class("IDSKVStore")
IDSKVDeleteContext = _Class("IDSKVDeleteContext")
