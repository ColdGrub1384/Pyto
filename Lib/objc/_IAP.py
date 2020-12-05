"""
Classes from the 'IAP' framework.
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


IAPClientPortManager = _Class("IAPClientPortManager")
IAPClientPort = _Class("IAPClientPort")
IAPNavigation = _Class("IAPNavigation")
IAPNavigationAccessoryComponent = _Class("IAPNavigationAccessoryComponent")
IAPNavigationAccessory = _Class("IAPNavigationAccessory")
IAPAudioCallbackInfo = _Class("IAPAudioCallbackInfo")
