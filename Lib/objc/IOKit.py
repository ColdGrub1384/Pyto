'''
Classes from the 'IOKit' framework.
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

    
HIDDevice = _Class('HIDDevice')
HIDElement = _Class('HIDElement')
HIDConnection = _Class('HIDConnection')
HIDSession = _Class('HIDSession')
HIDEventService = _Class('HIDEventService')
HIDEvent = _Class('HIDEvent')
HIDServiceClient = _Class('HIDServiceClient')
