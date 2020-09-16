'''
Classes from the 'PointerUIServices' framework.
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

    
PSPointerClientDefaultLaunchingServiceSpecification = _Class('PSPointerClientDefaultLaunchingServiceSpecification')
PSPortalSource = _Class('PSPortalSource')
PSPointerShape = _Class('PSPointerShape')
PSPointerSettings = _Class('PSPointerSettings')
PSPointerSettingsDomain = _Class('PSPointerSettingsDomain')
PSMatchMoveSource = _Class('PSMatchMoveSource')
PSPointerPortalSourceCollection = _Class('PSPointerPortalSourceCollection')
PSPointerHoverRegion = _Class('PSPointerHoverRegion')
PSMutablePointerHoverRegion = _Class('PSMutablePointerHoverRegion')
PSPointerClientDefaultServiceSpecification = _Class('PSPointerClientDefaultServiceSpecification')
PSPointerClientController = _Class('PSPointerClientController')
