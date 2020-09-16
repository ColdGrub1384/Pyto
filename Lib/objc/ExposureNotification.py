'''
Classes from the 'ExposureNotification' framework.
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

    
ENUserAlert = _Class('ENUserAlert')
ENProtobufCoder = _Class('ENProtobufCoder')
ENEntity = _Class('ENEntity')
ENArchive = _Class('ENArchive')
ENRegionVisit = _Class('ENRegionVisit')
ENRemotePresentationRequest = _Class('ENRemotePresentationRequest')
ENRegionConfiguration = _Class('ENRegionConfiguration')
ENRegionUserConsent = _Class('ENRegionUserConsent')
ENManager = _Class('ENManager')
ENRegion = _Class('ENRegion')
ENExposureNotification = _Class('ENExposureNotification')
ENSignature = _Class('ENSignature')
ENSignatureFile = _Class('ENSignatureFile')
ENFile = _Class('ENFile')
ENRegionServerExposureConfiguration = _Class('ENRegionServerExposureConfiguration')
ENRegionServerExposureClassificationCriteria = _Class('ENRegionServerExposureClassificationCriteria')
ENRegionServerAgencyConfiguration = _Class('ENRegionServerAgencyConfiguration')
ENRegionServerAgencyLocalizedConfiguration = _Class('ENRegionServerAgencyLocalizedConfiguration')
ENRegionServerAgencyExposureNotificationConfiguration = _Class('ENRegionServerAgencyExposureNotificationConfiguration')
ENRegionServerNKDConfiguration = _Class('ENRegionServerNKDConfiguration')
ENRegionServerConfiguration = _Class('ENRegionServerConfiguration')
ENExposureDetectionClientSession = _Class('ENExposureDetectionClientSession')
ENScanInstance = _Class('ENScanInstance')
ENExposureWindow = _Class('ENExposureWindow')
ENExposureSummaryItem = _Class('ENExposureSummaryItem')
ENExposureInfo = _Class('ENExposureInfo')
ENExposureDetectionSummary = _Class('ENExposureDetectionSummary')
ENExposureDaySummary = _Class('ENExposureDaySummary')
ENExposureConfiguration = _Class('ENExposureConfiguration')
ENExposureClassification = _Class('ENExposureClassification')
ENExposureDetectionSession = _Class('ENExposureDetectionSession')
ENExposureDetectionHistorySession = _Class('ENExposureDetectionHistorySession')
ENExposureDetectionHistoryFile = _Class('ENExposureDetectionHistoryFile')
ENExposureDetectionHistoryCheck = _Class('ENExposureDetectionHistoryCheck')
ENTemporaryExposureKey = _Class('ENTemporaryExposureKey')
