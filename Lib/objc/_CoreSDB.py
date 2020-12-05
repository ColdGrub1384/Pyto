"""
Classes from the 'CoreSDB' framework.
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


CSDBThreadedRecordStore = _Class("CSDBThreadedRecordStore")
_CSDBThreadObject = _Class("_CSDBThreadObject")
