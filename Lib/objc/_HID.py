'''
Classes from the 'HID' framework.
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

    
HIDUserDevice = _Class('HIDUserDevice')
HIDTransaction = _Class('HIDTransaction')
HIDEventSystemClient = _Class('HIDEventSystemClient')
HIDManager = _Class('HIDManager')
HIDVirtualEventService = _Class('HIDVirtualEventService')
