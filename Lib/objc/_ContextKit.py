"""
Classes from the 'ContextKit' framework.
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


CKContextResponse = _Class("CKContextResponse")
CKContextResult = _Class("CKContextResult")
CKContextXPCClient = _Class("CKContextXPCClient")
CKContextCompleter = _Class("CKContextCompleter")
CKContextSemaphore = _Class("CKContextSemaphore")
CKContextClient = _Class("CKContextClient")
CKContextCountedItem = _Class("CKContextCountedItem")
CKContextGlobals = _Class("CKContextGlobals")
CKContextRequest = _Class("CKContextRequest")
