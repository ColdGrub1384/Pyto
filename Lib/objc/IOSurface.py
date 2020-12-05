"""
Classes from the 'IOSurface' framework.
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


IOSurfaceDebugDescription = _Class("IOSurfaceDebugDescription")
_IOSurfaceDebugDescription = _Class("_IOSurfaceDebugDescription")
IOSurfaceRemoteRemoteClient = _Class("IOSurfaceRemoteRemoteClient")
IOSurfaceRemotePerSurfacePerClientState = _Class(
    "IOSurfaceRemotePerSurfacePerClientState"
)
IOSurfaceRemotePerSurfaceGlobalState = _Class("IOSurfaceRemotePerSurfaceGlobalState")
IOSurfaceRemoteServer = _Class("IOSurfaceRemoteServer")
IOSurfaceSharedEventListener = _Class("IOSurfaceSharedEventListener")
IOSurfaceSharedEvent = _Class("IOSurfaceSharedEvent")
IOSurface = _Class("IOSurface")
