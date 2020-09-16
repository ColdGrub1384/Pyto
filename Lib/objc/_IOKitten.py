'''
Classes from the 'IOKitten' framework.
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

    
IOKInterestNotificationRef = _Class('IOKInterestNotificationRef')
IOKMatchingNotificationRef = _Class('IOKMatchingNotificationRef')
IOKInterestNotification = _Class('IOKInterestNotification')
IOKMatchingNotification = _Class('IOKMatchingNotification')
IOKNotificationPort = _Class('IOKNotificationPort')
IOKConnection = _Class('IOKConnection')
IOKPowerManagerPowerAssertion = _Class('IOKPowerManagerPowerAssertion')
IOKPowerNotifier = _Class('IOKPowerNotifier')
IOKPowerManager = _Class('IOKPowerManager')
IOKObject = _Class('IOKObject')
IOKRegistryEntry = _Class('IOKRegistryEntry')
IOKService = _Class('IOKService')
IOKIterator = _Class('IOKIterator')
IORegistryIterator = _Class('IORegistryIterator')
