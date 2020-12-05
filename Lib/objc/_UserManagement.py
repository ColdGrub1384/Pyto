"""
Classes from the 'UserManagement' framework.
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


UMUserPersonaContext = _Class("UMUserPersonaContext")
UMUser = _Class("UMUser")
UMMutableUser = _Class("UMMutableUser")
UMUserSwitchContext = _Class("UMUserSwitchContext")
UMPersonaCallbackListener = _Class("UMPersonaCallbackListener")
UMXPCServer = _Class("UMXPCServer")
UMLogMessage = _Class("UMLogMessage")
UMUserPersonaAttributes = _Class("UMUserPersonaAttributes")
UMLog = _Class("UMLog")
UMAbort = _Class("UMAbort")
UMTask = _Class("UMTask")
UMUserSyncTask = _Class("UMUserSyncTask")
UMUserSwitchBlockingTask = _Class("UMUserSwitchBlockingTask")
UMError = _Class("UMError")
UMQueue = _Class("UMQueue")
UMUserPersona = _Class("UMUserPersona")
UMUserMutablePersona = _Class("UMUserMutablePersona")
UMMobileKeyBag = _Class("UMMobileKeyBag")
UMUserManager = _Class("UMUserManager")
