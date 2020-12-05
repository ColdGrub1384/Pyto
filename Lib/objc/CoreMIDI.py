"""
Classes from the 'CoreMIDI' framework.
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


MIDINetworkConnection = _Class("MIDINetworkConnection")
MIDINetworkHost = _Class("MIDINetworkHost")
MIDINetworkSession = _Class("MIDINetworkSession")
MIDICIResponder = _Class("MIDICIResponder")
MIDICIDiscoveryManager = _Class("MIDICIDiscoveryManager")
MIDICIDiscoveredNode = _Class("MIDICIDiscoveredNode")
BLEMIDIAccessor = _Class("BLEMIDIAccessor")
MIDICISession = _Class("MIDICISession")
MIDICIProfileState = _Class("MIDICIProfileState")
MIDICIProfile = _Class("MIDICIProfile")
MIDICIDeviceInfo = _Class("MIDICIDeviceInfo")
