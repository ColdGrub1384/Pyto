"""
Classes from the 'HangTracer' framework.
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


HTFenceAssertion = _Class("HTFenceAssertion")
HTPrefs = _Class("HTPrefs")
