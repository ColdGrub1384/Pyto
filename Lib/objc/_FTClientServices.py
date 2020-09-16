'''
Classes from the 'FTClientServices' framework.
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

    
FTCServiceMonitor = _Class('FTCServiceMonitor')
FTCServiceContainer = _Class('FTCServiceContainer')
FTCServiceAvailabilityCenter = _Class('FTCServiceAvailabilityCenter')
