"""
Classes from the 'CacheDelete' framework.
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


CDRemoveEventsConsumer = _Class("CDRemoveEventsConsumer")
CacheDeleteListener = _Class("CacheDeleteListener")
CacheDeleteServiceListener = _Class("CacheDeleteServiceListener")
CacheDeleteVolume = _Class("CacheDeleteVolume")
CacheDeleteServiceInfo = _Class("CacheDeleteServiceInfo")
CacheManagementAsset = _Class("CacheManagementAsset")
CacheDeleteRemoteExtensionContext = _Class("CacheDeleteRemoteExtensionContext")
CacheDeleteHostExtensionContext = _Class("CacheDeleteHostExtensionContext")
