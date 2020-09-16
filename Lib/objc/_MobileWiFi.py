'''
Classes from the 'MobileWiFi' framework.
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

    
WiFiPasswordSharingSimulator = _Class('WiFiPasswordSharingSimulator')
