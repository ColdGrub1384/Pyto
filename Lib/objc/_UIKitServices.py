'''
Classes from the 'UIKitServices' framework.
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

    
UISApplicationSupportService = _Class('UISApplicationSupportService')
UISCurrentUserInterfaceStyleValue = _Class('UISCurrentUserInterfaceStyleValue')
UISApplicationSupportDisplayEdgeInsetsWrapper = _Class('UISApplicationSupportDisplayEdgeInsetsWrapper')
UISApplicationStateService = _Class('UISApplicationStateService')
UISUserInterfaceStyleMode = _Class('UISUserInterfaceStyleMode')
UISFetchContentInBackgroundActionResponse = _Class('UISFetchContentInBackgroundActionResponse')
UISIntentForwardingActionResponse = _Class('UISIntentForwardingActionResponse')
UISDeviceContext = _Class('UISDeviceContext')
UISMutableDeviceContext = _Class('UISMutableDeviceContext')
UISApplicationSupportDisplayEdgeInfo = _Class('UISApplicationSupportDisplayEdgeInfo')
UISDisplayContext = _Class('UISDisplayContext')
UISMutableDisplayContext = _Class('UISMutableDisplayContext')
UISApplicationInitializationContext = _Class('UISApplicationInitializationContext')
UISMutableApplicationInitializationContext = _Class('UISMutableApplicationInitializationContext')
UISApplicationInitializationContextParameters = _Class('UISApplicationInitializationContextParameters')
UISFetchContentInBackgroundAction = _Class('UISFetchContentInBackgroundAction')
UISIntentForwardingAction = _Class('UISIntentForwardingAction')
UISHandleRemoteNotificationAction = _Class('UISHandleRemoteNotificationAction')
UISApplicationStateClient = _Class('UISApplicationStateClient')
UISApplicationState = _Class('UISApplicationState')
UISApplicationSupportClient = _Class('UISApplicationSupportClient')
