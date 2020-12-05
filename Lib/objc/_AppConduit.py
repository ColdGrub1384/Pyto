"""
Classes from the 'AppConduit' framework.
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


ACXDeviceConnection = _Class("ACXDeviceConnection")
ACXDeviceConnectionDelegateProtocolInterface = _Class(
    "ACXDeviceConnectionDelegateProtocolInterface"
)
ACXDeviceConnectionProtocolInterface = _Class("ACXDeviceConnectionProtocolInterface")
ACXRemoteApplication = _Class("ACXRemoteApplication")
ACXApplication = _Class("ACXApplication")
ACXApplicationStatus = _Class("ACXApplicationStatus")
