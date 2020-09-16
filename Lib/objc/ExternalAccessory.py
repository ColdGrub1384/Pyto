'''
Classes from the 'ExternalAccessory' framework.
'''

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

    
WACLogging = _Class('WACLogging')
EAWiFiUnconfiguredAccessory = _Class('EAWiFiUnconfiguredAccessory')
EAWiFiUnconfiguredAccessoryBrowser = _Class('EAWiFiUnconfiguredAccessoryBrowser')
EABluetoothAccessoryPicker = _Class('EABluetoothAccessoryPicker')
EAAccessoryInternal = _Class('EAAccessoryInternal')
EAAccessory = _Class('EAAccessory')
EASession = _Class('EASession')
EAAccessoryManager = _Class('EAAccessoryManager')
EAOutputStream = _Class('EAOutputStream')
EAInputStream = _Class('EAInputStream')
