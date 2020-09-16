'''
Classes from the 'AppSSO' framework.
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

    
SOExtensionFinder = _Class('SOExtensionFinder')
SOConfigurationHost = _Class('SOConfigurationHost')
SOAuthorizationRequest = _Class('SOAuthorizationRequest')
SOConfigurationManager = _Class('SOConfigurationManager')
SOPreferences = _Class('SOPreferences')
SODebugHints = _Class('SODebugHints')
SOAuthorizationCredential = _Class('SOAuthorizationCredential')
SORequestQueue = _Class('SORequestQueue')
SOAuthorizationRequestParameters = _Class('SOAuthorizationRequestParameters')
SOExtensionManager = _Class('SOExtensionManager')
SOAuthorizationParameters = _Class('SOAuthorizationParameters')
SOExtension = _Class('SOExtension')
SORequestQueueItem = _Class('SORequestQueueItem')
SOAuthorizationHints = _Class('SOAuthorizationHints')
SOExtensionServiceConnection = _Class('SOExtensionServiceConnection')
SOAuthorization = _Class('SOAuthorization')
SOHostExtensionContext = _Class('SOHostExtensionContext')
SORemoteExtensionContext = _Class('SORemoteExtensionContext')
SOExtensionViewService = _Class('SOExtensionViewService')
SORemoteExtensionViewController = _Class('SORemoteExtensionViewController')
