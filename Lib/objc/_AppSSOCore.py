'''
Classes from the 'AppSSOCore' framework.
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

    
SOAuthorizationResult = _Class('SOAuthorizationResult')
SOAuthorizationPoolItem = _Class('SOAuthorizationPoolItem')
SOProfile = _Class('SOProfile')
SOFullProfile = _Class('SOFullProfile')
SOAuthorizationParametersCore = _Class('SOAuthorizationParametersCore')
SOConfigurationVersion = _Class('SOConfigurationVersion')
SOConfiguration = _Class('SOConfiguration')
SOAuthorizationHintsCore = _Class('SOAuthorizationHintsCore')
SOAuthorizationCredentialCore = _Class('SOAuthorizationCredentialCore')
SOAuthorizationRequestParametersCore = _Class('SOAuthorizationRequestParametersCore')
SOInternalProtocols = _Class('SOInternalProtocols')
SOServiceConnection = _Class('SOServiceConnection')
SOClient = _Class('SOClient')
SOConfigurationClient = _Class('SOConfigurationClient')
SOAuthorizationCore = _Class('SOAuthorizationCore')
SOAuthorizationPool = _Class('SOAuthorizationPool')
SOErrorHelper = _Class('SOErrorHelper')
SOUtils = _Class('SOUtils')
