'''
Classes from the 'FontServices' framework.
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

    
FSUserFontServicesManager = _Class('FSUserFontServicesManager')
FSWebKitProcessSupportHandler = _Class('FSWebKitProcessSupportHandler')
FSWebKitHostSupportManager = _Class('FSWebKitHostSupportManager')
FSUserFontManager = _Class('FSUserFontManager')
DeleteAppFontsDialogHandler = _Class('DeleteAppFontsDialogHandler')
FontProviderManager = _Class('FontProviderManager')
FSWebKitProcessSupportManager = _Class('FSWebKitProcessSupportManager')
FontPickerSupporter = _Class('FontPickerSupporter')
FontPickerSupportHandler = _Class('FontPickerSupportHandler')
HVFPartTransform = _Class('HVFPartTransform')
HVFLoader = _Class('HVFLoader')
FontServicesDaemonManager = _Class('FontServicesDaemonManager')
