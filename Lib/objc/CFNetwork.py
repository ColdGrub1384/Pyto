"""
Classes from the 'CFNetwork' framework.
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


NSURLSessionTaskTransactionMetrics = _Class("NSURLSessionTaskTransactionMetrics")
NSURLSessionTaskMetrics = _Class("NSURLSessionTaskMetrics")
NSURLSessionWebSocketMessage = _Class("NSURLSessionWebSocketMessage")
NSURLSessionTaskHTTPAuthenticator = _Class("NSURLSessionTaskHTTPAuthenticator")
NSURLSessionTaskLocalHTTPAuthenticator = _Class(
    "NSURLSessionTaskLocalHTTPAuthenticator"
)
NSURLSessionTaskBackgroundHTTPAuthenticator = _Class(
    "NSURLSessionTaskBackgroundHTTPAuthenticator"
)
NSGZipDecoder = _Class("NSGZipDecoder")
NSURLDownload = _Class("NSURLDownload")
NSURLDownloadInternal = _Class("NSURLDownloadInternal")
__CFN_CoreSchedulingSetRunnable = _Class("__CFN_CoreSchedulingSetRunnable")
__NSCFURLSessionXPC = _Class("__NSCFURLSessionXPC")
NSMemoryHTTPCookie2Storage = _Class("NSMemoryHTTPCookie2Storage")
__NSCFURLLocalStreamTaskFromDataTaskDataBlobby = _Class(
    "__NSCFURLLocalStreamTaskFromDataTaskDataBlobby"
)
NSURLConnectionInternal = _Class("NSURLConnectionInternal")
NSURLConnectionInternalConnection = _Class("NSURLConnectionInternalConnection")
NSURLConnectionInternalBackgroundDownload = _Class(
    "NSURLConnectionInternalBackgroundDownload"
)
NSAsyncSSDownloadManager = _Class("NSAsyncSSDownloadManager")
_NSURLBDOnce = _Class("_NSURLBDOnce")
NSHTTPCookie2Storage = _Class("NSHTTPCookie2Storage")
CFNetworkTimer = _Class("CFNetworkTimer")
__NSCFURLSessionTaskGroup = _Class("__NSCFURLSessionTaskGroup")
NSURLSessionTaskDependency = _Class("NSURLSessionTaskDependency")
NSURLSessionTaskDependencyTree = _Class("NSURLSessionTaskDependencyTree")
__NSCFURLSessionTaskDependencyTreeNode = _Class(
    "__NSCFURLSessionTaskDependencyTreeNode"
)
NSURLSessionTaskDependencyDescription = _Class("NSURLSessionTaskDependencyDescription")
__NSURLSessionTaskDependencyResourceIdentifier = _Class(
    "__NSURLSessionTaskDependencyResourceIdentifier"
)
__NSCFURLSessionTaskInfo = _Class("__NSCFURLSessionTaskInfo")
__CFNCoreLoggable = _Class("__CFNCoreLoggable")
NWStreamPair = _Class("NWStreamPair")
NSNetServiceBrowser = _Class("NSNetServiceBrowser")
NSNetService = _Class("NSNetService")
NSProxyConnection = _Class("NSProxyConnection")
NSProxyConnectionStreamTask = _Class("NSProxyConnectionStreamTask")
NSPersistentHTTPCookie2Storage = _Class("NSPersistentHTTPCookie2Storage")
NSHTTPURLRequestParameters = _Class("NSHTTPURLRequestParameters")
__NSURLSessionStatistics = _Class("__NSURLSessionStatistics")
PACURLSessionDelegate = _Class("PACURLSessionDelegate")
__CFN_SocksHandshake = _Class("__CFN_SocksHandshake")
__CFN_SocksHandshakev5 = _Class("__CFN_SocksHandshakev5")
NSHTTPCookie = _Class("NSHTTPCookie")
NSHTTPCookieInternal = _Class("NSHTTPCookieInternal")
NSHTTPCookieInternal_Ref = _Class("NSHTTPCookieInternal_Ref")
NSHTTPCookieInternal_Data = _Class("NSHTTPCookieInternal_Data")
NSHost = _Class("NSHost")
__NSHostExtraIvars = _Class("__NSHostExtraIvars")
_NSCFNetworkMonitor = _Class("_NSCFNetworkMonitor")
_NSHTTPConnectionInfo = _Class("_NSHTTPConnectionInfo")
NSHTTPCookie2StorageFilter = _Class("NSHTTPCookie2StorageFilter")
NSHTTPCookie2LookupFilter = _Class("NSHTTPCookie2LookupFilter")
_NSCFSocksProxy = _Class("_NSCFSocksProxy")
__NSCFTCPIO_BlockCallbacks_Referent = _Class("__NSCFTCPIO_BlockCallbacks_Referent")
NSURLProtocolInternal = _Class("NSURLProtocolInternal")
_NSCFServer = _Class("_NSCFServer")
NSHTTPCookie2 = _Class("NSHTTPCookie2")
NSMutableHTTPCookie2 = _Class("NSMutableHTTPCookie2")
_NSHTTPAlternativeServicesStorage = _Class("_NSHTTPAlternativeServicesStorage")
_NSHTTPAlternativeServicesSpeculativeEntry = _Class(
    "_NSHTTPAlternativeServicesSpeculativeEntry"
)
_NSHTTPAlternativeServicesFilter = _Class("_NSHTTPAlternativeServicesFilter")
_NSHTTPAlternativeServiceEntry = _Class("_NSHTTPAlternativeServiceEntry")
__NSCFURLLocalStreamTaskWork = _Class("__NSCFURLLocalStreamTaskWork")
__NSCFURLLocalStreamTaskWorkRead = _Class("__NSCFURLLocalStreamTaskWorkRead")
__NSCFURLLocalStreamTaskWorkWrite = _Class("__NSCFURLLocalStreamTaskWorkWrite")
__NSCFURLLocalStreamTaskWorkBlockOp = _Class("__NSCFURLLocalStreamTaskWorkBlockOp")
NSURLCredential = _Class("NSURLCredential")
NSHTTPCookie2Key = _Class("NSHTTPCookie2Key")
NSHTTPCookieStorageUtils = _Class("NSHTTPCookieStorageUtils")
NSNetServicesInternal = _Class("NSNetServicesInternal")
AuthBrokerAgentXPCListenerDelegate = _Class("AuthBrokerAgentXPCListenerDelegate")
ABRequestHandler = _Class("ABRequestHandler")
__NSCFURLProtocolClient_NS = _Class("__NSCFURLProtocolClient_NS")
__NSCFURLSessionTaskActiveStreamDependencyInfo = _Class(
    "__NSCFURLSessionTaskActiveStreamDependencyInfo"
)
__CFN_PathPolicyManager = _Class("__CFN_PathPolicyManager")
__CFN_CoalescingDomainHolder = _Class("__CFN_CoalescingDomainHolder")
_NSURLSessionConnectionEstablishProperties = _Class(
    "_NSURLSessionConnectionEstablishProperties"
)
NSURLAuthenticationChallengeInternal = _Class("NSURLAuthenticationChallengeInternal")
NSURLProtectionSpace = _Class("NSURLProtectionSpace")
NSURLAuthenticationChallenge = _Class("NSURLAuthenticationChallenge")
_NSURLSessionConnectionBeginProperties = _Class(
    "_NSURLSessionConnectionBeginProperties"
)
__CFN_ConnectionMetrics = _Class("__CFN_ConnectionMetrics")
NSHTTPCookieStorageInternal = _Class("NSHTTPCookieStorageInternal")
NSHTTPCookieStorage = _Class("NSHTTPCookieStorage")
__NSCFMemoryHTTPCookieStorage = _Class("__NSCFMemoryHTTPCookieStorage")
NSHTTPCookieStorageToCookie2Storage = _Class("NSHTTPCookieStorageToCookie2Storage")
NSURLCredentialStorage = _Class("NSURLCredentialStorage")
__NSCFMemoryURLCredentialStorage = _Class("__NSCFMemoryURLCredentialStorage")
NSHTTPURLResponseInternal = _Class("NSHTTPURLResponseInternal")
NSCachedURLResponseInternal = _Class("NSCachedURLResponseInternal")
NSCachedURLResponse = _Class("NSCachedURLResponse")
NSURLResponse = _Class("NSURLResponse")
NSHTTPURLResponse = _Class("NSHTTPURLResponse")
NSURLResponseInternal = _Class("NSURLResponseInternal")
NSURLStorageURLCacheDB = _Class("NSURLStorageURLCacheDB")
__CFN_TransactionMetrics = _Class("__CFN_TransactionMetrics")
NSURLCacheInternal = _Class("NSURLCacheInternal")
NSURLCache = _Class("NSURLCache")
__NSCFURLSessionConnection = _Class("__NSCFURLSessionConnection")
__NSCFURLProxySessionConnection = _Class("__NSCFURLProxySessionConnection")
__NSCFURLLocalSessionConnection = _Class("__NSCFURLLocalSessionConnection")
_NSHSTSStorage = _Class("_NSHSTSStorage")
CONNECTION_SessionTask = _Class("CONNECTION_SessionTask")
__NSCFLocalDownloadFile = _Class("__NSCFLocalDownloadFile")
NSURLConnection = _Class("NSURLConnection")
__CFN_TaskMetrics = _Class("__CFN_TaskMetrics")
__NSURLSessionEffectiveConfiguration_Base = _Class(
    "__NSURLSessionEffectiveConfiguration_Base"
)
NSURLSessionEffectiveConfiguration = _Class("NSURLSessionEffectiveConfiguration")
NSURLSessionMutableEffectiveConfiguration = _Class(
    "NSURLSessionMutableEffectiveConfiguration"
)
NSURLSessionTask = _Class("NSURLSessionTask")
NSURLSessionStreamTask = _Class("NSURLSessionStreamTask")
__NSCFURLLocalStreamTask = _Class("__NSCFURLLocalStreamTask")
__NSCFURLLocalStreamTaskFromDataTask = _Class("__NSCFURLLocalStreamTaskFromDataTask")
NSURLSessionDataTask = _Class("NSURLSessionDataTask")
NSURLSessionUploadTask = _Class("NSURLSessionUploadTask")
__NSCFBackgroundSessionTask = _Class("__NSCFBackgroundSessionTask")
__NSCFBackgroundAVAggregateAssetDownloadTask = _Class(
    "__NSCFBackgroundAVAggregateAssetDownloadTask"
)
__NSCFBackgroundAVAssetDownloadTask = _Class("__NSCFBackgroundAVAssetDownloadTask")
__NSCFBackgroundAVAggregateAssetDownloadTaskNoChildTask = _Class(
    "__NSCFBackgroundAVAggregateAssetDownloadTaskNoChildTask"
)
__NSCFBackgroundDownloadTask = _Class("__NSCFBackgroundDownloadTask")
__NSCFBackgroundDataTask = _Class("__NSCFBackgroundDataTask")
__NSCFBackgroundUploadTask = _Class("__NSCFBackgroundUploadTask")
__NSCFTCPIOStreamTask = _Class("__NSCFTCPIOStreamTask")
__NSCFURLLocalTCPIOStreamTaskFromDataTask = _Class(
    "__NSCFURLLocalTCPIOStreamTaskFromDataTask"
)
NSURLSessionAVAggregateAssetDownloadTask = _Class(
    "NSURLSessionAVAggregateAssetDownloadTask"
)
NSURLSessionAVAssetDownloadTask = _Class("NSURLSessionAVAssetDownloadTask")
AVAssetDownloadTask = _Class("AVAssetDownloadTask")
NSURLSessionWebSocketTask = _Class("NSURLSessionWebSocketTask")
NSURLSessionDownloadTask = _Class("NSURLSessionDownloadTask")
__NSCFLocalSessionTask = _Class("__NSCFLocalSessionTask")
__NSURLSessionWebSocketTask = _Class("__NSURLSessionWebSocketTask")
__NSCFLocalDataTask = _Class("__NSCFLocalDataTask")
__NSCFLocalUploadTask = _Class("__NSCFLocalUploadTask")
__NSCFLocalDownloadTask = _Class("__NSCFLocalDownloadTask")
NSURLRequestInternal = _Class("NSURLRequestInternal")
NSURLRequest = _Class("NSURLRequest")
NSMutableURLRequest = _Class("NSMutableURLRequest")
__NSCFTaskForClass = _Class("__NSCFTaskForClass")
__CFN_SessionMetrics = _Class("__CFN_SessionMetrics")
__CFN_GlobalMetrics = _Class("__CFN_GlobalMetrics")
__CFN_ConnectionContextManager = _Class("__CFN_ConnectionContextManager")
NSURLProtocol = _Class("NSURLProtocol")
_NSCFWikipediaProtocol = _Class("_NSCFWikipediaProtocol")
_NSCFTranslatedFileURLProtocol = _Class("_NSCFTranslatedFileURLProtocol")
_NSCFTranslatedFileURLProtocol_PIMPL_7 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_7"
)
_NSCFTranslatedFileURLProtocol_PIMPL_6 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_6"
)
_NSCFTranslatedFileURLProtocol_PIMPL_5 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_5"
)
_NSCFTranslatedFileURLProtocol_PIMPL_4 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_4"
)
_NSCFTranslatedFileURLProtocol_PIMPL_3 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_3"
)
_NSCFTranslatedFileURLProtocol_PIMPL_2 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_2"
)
_NSCFTranslatedFileURLProtocol_PIMPL_1 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_1"
)
_NSCFTranslatedFileURLProtocol_PIMPL_0 = _Class(
    "_NSCFTranslatedFileURLProtocol_PIMPL_0"
)
NSAboutURLProtocol = _Class("NSAboutURLProtocol")
_NSCFURLProtocol = _Class("_NSCFURLProtocol")
_NSURLFileProtocol = _Class("_NSURLFileProtocol")
_NSURLFTPProtocol = _Class("_NSURLFTPProtocol")
_NSURLDataProtocol = _Class("_NSURLDataProtocol")
_NSURLHTTPProtocol = _Class("_NSURLHTTPProtocol")
_NSURLAppSSOProtocol = _Class("_NSURLAppSSOProtocol")
NSURLSessionConfiguration = _Class("NSURLSessionConfiguration")
NSURLSession = _Class("NSURLSession")
__NSURLBackgroundSession = _Class("__NSURLBackgroundSession")
__NSURLAVBackgroundSession = _Class("__NSURLAVBackgroundSession")
__NSURLSessionLocal = _Class("__NSURLSessionLocal")
AVAssetDownloadURLSession = _Class("AVAssetDownloadURLSession")
