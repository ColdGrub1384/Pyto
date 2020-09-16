'''
Classes from the 'SharedWebCredentials' framework.
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

    
_SWCDomain = _Class('_SWCDomain')
_SWCTrackingDomainInfo = _Class('_SWCTrackingDomainInfo')
_SWCPatternMatchingResult = _Class('_SWCPatternMatchingResult')
_SWCPatternMatchingEngine = _Class('_SWCPatternMatchingEngine')
_SWCServiceDetails = _Class('_SWCServiceDetails')
_SWCApplicationIdentifier = _Class('_SWCApplicationIdentifier')
_SWCPrefs = _Class('_SWCPrefs')
_SWCServiceSpecifier = _Class('_SWCServiceSpecifier')
_SWCGeneration = _Class('_SWCGeneration')
_SWCServiceSettings = _Class('_SWCServiceSettings')
_SWCSubstitutionVariableList = _Class('_SWCSubstitutionVariableList')
_SWCPatternList = _Class('_SWCPatternList')
_SWCPattern = _Class('_SWCPattern')
