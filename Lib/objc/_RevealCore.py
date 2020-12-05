"""
Classes from the 'RevealCore' framework.
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


RVDocumentContext = _Class("RVDocumentContext")
RVSelection = _Class("RVSelection")
RVItem = _Class("RVItem")
