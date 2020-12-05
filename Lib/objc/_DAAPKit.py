"""
Classes from the 'DAAPKit' framework.
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


DKDAAPParser = _Class("DKDAAPParser")
DKDAAPParserContainer = _Class("DKDAAPParserContainer")
DKDAAPWriter = _Class("DKDAAPWriter")
DKDAAPWriterContainer = _Class("DKDAAPWriterContainer")
