"""
Classes from the 'GenerationalStorage' framework.
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


GSDaemonProxySync = _Class("GSDaemonProxySync")
GSTemporaryStorage = _Class("GSTemporaryStorage")
GSClientManagedLibrary = _Class("GSClientManagedLibrary")
_CopyfileCallbackCtx = _Class("_CopyfileCallbackCtx")
GSAddition = _Class("GSAddition")
GSStagingPrefix = _Class("GSStagingPrefix")
GSPermanentStorage = _Class("GSPermanentStorage")
GSDocumentIdentifier = _Class("GSDocumentIdentifier")
GSStorageManager = _Class("GSStorageManager")
GSTemporaryAddtionEnumerator = _Class("GSTemporaryAddtionEnumerator")
GSPermanentAdditionEnumerator = _Class("GSPermanentAdditionEnumerator")
