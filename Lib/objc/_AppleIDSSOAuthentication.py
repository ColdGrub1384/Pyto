"""
Classes from the 'AppleIDSSOAuthentication' framework.
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


AIDAServiceOwnersManager = _Class("AIDAServiceOwnersManager")
AIDAServiceOperationResult = _Class("AIDAServiceOperationResult")
AIDAServiceContext = _Class("AIDAServiceContext")
AIDAMutableServiceContext = _Class("AIDAMutableServiceContext")
AIDAAccountManager = _Class("AIDAAccountManager")
