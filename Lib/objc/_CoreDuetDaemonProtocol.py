"""
Classes from the 'CoreDuetDaemonProtocol' framework.
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


CDDXPCConnection = _Class("CDDXPCConnection")
CDDHistoryWindow = _Class("CDDHistoryWindow")
CDDClientConnection = _Class("CDDClientConnection")
CDDServerResponder = _Class("CDDServerResponder")
CDPClientConnection = _Class("CDPClientConnection")
