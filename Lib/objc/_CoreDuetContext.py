'''
Classes from the 'CoreDuetContext' framework.
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

    
_CDUserContextService = _Class('_CDUserContextService')
_CDXPCEventSubscriber = _Class('_CDXPCEventSubscriber')
_CDXPCEventPublisher = _Class('_CDXPCEventPublisher')
_CDSystemTimeCallbackScheduler = _Class('_CDSystemTimeCallbackScheduler')
_CDUserContextServerClient = _Class('_CDUserContextServerClient')
_CDContextMonitorManager = _Class('_CDContextMonitorManager')
_CDPolicyBasedPersisting = _Class('_CDPolicyBasedPersisting')
_CDClientContext = _Class('_CDClientContext')
_CDXPCCodecs = _Class('_CDXPCCodecs')
_CDModeClassifier = _Class('_CDModeClassifier')
_CDContextPredictionQueries = _Class('_CDContextPredictionQueries')
_CDUserContextQueries = _Class('_CDUserContextQueries')
_CDInMemoryUserContext = _Class('_CDInMemoryUserContext')
_CDInMemoryContext = _Class('_CDInMemoryContext')
_CDNetworkContext = _Class('_CDNetworkContext')
_CDDevice = _Class('_CDDevice')
_CDContextValue = _Class('_CDContextValue')
_CDContextualPredicate = _Class('_CDContextualPredicate')
_CDMDCSContextualPredicate = _Class('_CDMDCSContextualPredicate')
_CDContextualLocationRegistrationMonitor = _Class('_CDContextualLocationRegistrationMonitor')
_CDContextualKeyPath = _Class('_CDContextualKeyPath')
_CDCoreDataContextPersisting = _Class('_CDCoreDataContextPersisting')
_CDContextualChangeRegistration = _Class('_CDContextualChangeRegistration')
_CDContextQueries = _Class('_CDContextQueries')
_CDSharedMemoryContextPersisting = _Class('_CDSharedMemoryContextPersisting')
_CDContextualKeyPathAndValue = _Class('_CDContextualKeyPathAndValue')
_CDContextualChangeRegistrationMO = _Class('_CDContextualChangeRegistrationMO')
_CDContextualKeyPathMO = _Class('_CDContextualKeyPathMO')
