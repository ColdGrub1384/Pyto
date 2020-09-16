'''
Classes from the 'Security' framework.
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

    
SecXPCHelper = _Class('SecXPCHelper')
SecKeyProxy = _Class('SecKeyProxy')
SecKeyProxyTarget = _Class('SecKeyProxyTarget')
SecItemRateLimit = _Class('SecItemRateLimit')
SecSOSStatus = _Class('SecSOSStatus')
SOSCachedNotification = _Class('SOSCachedNotification')
OTClique = _Class('OTClique')
OTOperationConfiguration = _Class('OTOperationConfiguration')
OTBottleIDs = _Class('OTBottleIDs')
OTConfigurationContext = _Class('OTConfigurationContext')
CKKSPBFileStorage = _Class('CKKSPBFileStorage')
SFAnalyticsSampler = _Class('SFAnalyticsSampler')
SecCoreAnalytics = _Class('SecCoreAnalytics')
SecConcrete_sec_protocol_configuration = _Class('SecConcrete_sec_protocol_configuration')
SecConcrete_sec_protocol_configuration_builder = _Class('SecConcrete_sec_protocol_configuration_builder')
SecConcrete_sec_identity = _Class('SecConcrete_sec_identity')
SFObjCType = _Class('SFObjCType')
SecEscrowRequest = _Class('SecEscrowRequest')
OTControl = _Class('OTControl')
SecuritydXPCCallback = _Class('SecuritydXPCCallback')
SecuritydXPCClient = _Class('SecuritydXPCClient')
CKKSControl = _Class('CKKSControl')
SFAnalyticsActivityTracker = _Class('SFAnalyticsActivityTracker')
SFSQLiteStatement = _Class('SFSQLiteStatement')
SecExperimentConfig = _Class('SecExperimentConfig')
SecExperiment = _Class('SecExperiment')
SecExpConcrete_sec_experiment = _Class('SecExpConcrete_sec_experiment')
SFAnalytics = _Class('SFAnalytics')
SOSAnalytics = _Class('SOSAnalytics')
LocalKeychainAnalytics = _Class('LocalKeychainAnalytics')
LKAUpgradeOutcomeReport = _Class('LKAUpgradeOutcomeReport')
OTJoiningConfiguration = _Class('OTJoiningConfiguration')
SFAnalyticsMultiSampler = _Class('SFAnalyticsMultiSampler')
SFSQLite = _Class('SFSQLite')
SFAnalyticsSQLiteStore = _Class('SFAnalyticsSQLiteStore')
CTKClientSEP_TKTokenRefSEP = _Class('CTKClientSEP_TKTokenRefSEP')
CTKClientSEP_TKTLVRecord = _Class('CTKClientSEP_TKTLVRecord')
CTKClientSEP_TKCompactTLVRecord = _Class('CTKClientSEP_TKCompactTLVRecord')
CTKClientSEP_TKSimpleTLVRecord = _Class('CTKClientSEP_TKSimpleTLVRecord')
CTKClientSEP_TKBERTLVRecord = _Class('CTKClientSEP_TKBERTLVRecord')
CTKClientSEP_TKDataSource = _Class('CTKClientSEP_TKDataSource')
CTKClientSEP_SEKey = _Class('CTKClientSEP_SEKey')
CTKClientSEP_SEParameters = _Class('CTKClientSEP_SEParameters')
SecConcrete_sec_trust = _Class('SecConcrete_sec_trust')
SecConcrete_sec_certificate = _Class('SecConcrete_sec_certificate')
SecConcrete_sec_array = _Class('SecConcrete_sec_array')
