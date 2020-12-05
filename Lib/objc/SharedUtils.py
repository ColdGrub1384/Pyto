"""
Classes from the 'SharedUtils' framework.
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


LAPasscodeHelper = _Class("LAPasscodeHelper")
LAUtils = _Class("LAUtils")
LAADMUser = _Class("LAADMUser")
LAACMHelper = _Class("LAACMHelper")
BaseManagedService = _Class("BaseManagedService")
DefaultServiceManager = _Class("DefaultServiceManager")
DefaultServiceSession = _Class("DefaultServiceSession")
WeakBox = _Class("WeakBox")
LAErrorHelper = _Class("LAErrorHelper")
NSXPCInvocation = _Class("NSXPCInvocation")
LAStorageHelper = _Class("LAStorageHelper")
LASecureData = _Class("LASecureData")
LAParamChecker = _Class("LAParamChecker")
VirtualService = _Class("VirtualService")
LACachedExternalizedContext = _Class("LACachedExternalizedContext")
LAInternalProtocols = _Class("LAInternalProtocols")
