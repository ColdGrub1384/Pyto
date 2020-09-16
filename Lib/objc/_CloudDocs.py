'''
Classes from the 'CloudDocs' framework.
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

    
BRZombie = _Class('BRZombie')
BRXPCSyncProxy = _Class('BRXPCSyncProxy')
BRNotificationQueue = _Class('BRNotificationQueue')
BRRemoteUserDefaults = _Class('BRRemoteUserDefaults')
BRQueryStitch = _Class('BRQueryStitch')
BRQueryStitchingContext = _Class('BRQueryStitchingContext')
BRTask = _Class('BRTask')
BRFrameworkSyncedRootURLCache = _Class('BRFrameworkSyncedRootURLCache')
BRFrameworkContainerHelper = _Class('BRFrameworkContainerHelper')
BRContainerCache = _Class('BRContainerCache')
BRQueryItemProgressObserver = _Class('BRQueryItemProgressObserver')
BRTransfersStatusManager = _Class('BRTransfersStatusManager')
BRNotificationReceiver = _Class('BRNotificationReceiver')
BRMangledID = _Class('BRMangledID')
BRNonLocalVersion = _Class('BRNonLocalVersion')
BRContainersMonitor = _Class('BRContainersMonitor')
BRReachabilityMonitor = _Class('BRReachabilityMonitor')
BRServerMetrics = _Class('BRServerMetrics')
br_pacer = _Class('br_pacer')
BRQuery = _Class('BRQuery')
BRServerInfoRecordInfo = _Class('BRServerInfoRecordInfo')
BRProgressUpdate = _Class('BRProgressUpdate')
BRFileObjectID = _Class('BRFileObjectID')
BRDocObjectID = _Class('BRDocObjectID')
BRInodeObjectID = _Class('BRInodeObjectID')
BRContainer = _Class('BRContainer')
BRQueryItem = _Class('BRQueryItem')
_BRContainerItem = _Class('_BRContainerItem')
BRAccount = _Class('BRAccount')
BRDownloadProgressProxy = _Class('BRDownloadProgressProxy')
BRProgressProxy = _Class('BRProgressProxy')
BRGlobalProgressProxy = _Class('BRGlobalProgressProxy')
BRDaemonConnection = _Class('BRDaemonConnection')
BRListNonLocalVersionsOperation = _Class('BRListNonLocalVersionsOperation')
BROperation = _Class('BROperation')
BREvictItemOperation = _Class('BREvictItemOperation')
BRDownloadAndUploadAllFilesForLogOutOperation = _Class('BRDownloadAndUploadAllFilesForLogOutOperation')
BRDownloadAllFilesForLogOutOperation = _Class('BRDownloadAllFilesForLogOutOperation')
BRFetchQuotaOperation = _Class('BRFetchQuotaOperation')
BRUploadAllFilesForLogOutOperation = _Class('BRUploadAllFilesForLogOutOperation')
BRUploadAllFilesOperation = _Class('BRUploadAllFilesOperation')
BRFileProvidingOperation = _Class('BRFileProvidingOperation')
BRShareProcessSubitems = _Class('BRShareProcessSubitems')
BRSharingCopyShareInfoOperation = _Class('BRSharingCopyShareInfoOperation')
BRShareCleanSubitems = _Class('BRShareCleanSubitems')
BRSharePrepFolderForSharing = _Class('BRSharePrepFolderForSharing')
BRShareCopyDocumentURLForRecordID = _Class('BRShareCopyDocumentURLForRecordID')
BRShareCopyAccessTokenOperation = _Class('BRShareCopyAccessTokenOperation')
BRShareCopyShareURLOperation = _Class('BRShareCopyShareURLOperation')
BRShareCopyiWorkShareURLOperation = _Class('BRShareCopyiWorkShareURLOperation')
BRSharingCopyEtagOperation = _Class('BRSharingCopyEtagOperation')
BRSharingCopyShortTokenOperation = _Class('BRSharingCopyShortTokenOperation')
BRSharingCopyShareTokenOperation = _Class('BRSharingCopyShareTokenOperation')
BRSharingModifyRecordAccessOperation = _Class('BRSharingModifyRecordAccessOperation')
BRShareLookupParticipantsOperation = _Class('BRShareLookupParticipantsOperation')
BRShareUnshareOperation = _Class('BRShareUnshareOperation')
BRShareDestroyOperation = _Class('BRShareDestroyOperation')
BRShareSaveOperation = _Class('BRShareSaveOperation')
BRShareCopyOperation = _Class('BRShareCopyOperation')
BRiWorkWebShareMigrateOperation = _Class('BRiWorkWebShareMigrateOperation')
BRContainerBundlePropertyEnumerator = _Class('BRContainerBundlePropertyEnumerator')
BRContainerBundleIdentifiersEnumerator = _Class('BRContainerBundleIdentifiersEnumerator')
