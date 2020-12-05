"""
Classes from the 'CoreSpotlight' framework.
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


CSImportExtension = _Class("CSImportExtension")
CSFPItem = _Class("CSFPItem")
CSUserActivityTuple = _Class("CSUserActivityTuple")
CSPowerLog = _Class("CSPowerLog")
CoreSpotlightPreferences = _Class("CoreSpotlightPreferences")
CSReceiverServerPreferences = _Class("CSReceiverServerPreferences")
CSReceiverPreferences = _Class("CSReceiverPreferences")
_MDExtensionManager = _Class("_MDExtensionManager")
_MDImportExtensionManager = _Class("_MDImportExtensionManager")
_MDIndexExtensionManager = _Class("_MDIndexExtensionManager")
CSContactsWrapper = _Class("CSContactsWrapper")
CSIntentsWrapper = _Class("CSIntentsWrapper")
CoreSpotlightUtils = _Class("CoreSpotlightUtils")
_MDExtensionLoader = _Class("_MDExtensionLoader")
_MDImportExtensionLoader = _Class("_MDImportExtensionLoader")
_MDIndexExtensionLoader = _Class("_MDIndexExtensionLoader")
CSSearchQueryContext = _Class("CSSearchQueryContext")
CSDataWrapper = _Class("CSDataWrapper")
CSIndexJob = _Class("CSIndexJob")
CSAttributeEvaluator = _Class("CSAttributeEvaluator")
TokenEnumeratorContext = _Class("TokenEnumeratorContext")
_MDDateFormatterFactory = _Class("_MDDateFormatterFactory")
CSLiveFSVolume = _Class("CSLiveFSVolume")
CSUserQueryParser = _Class("CSUserQueryParser")
MDSearchQuery = _Class("MDSearchQuery")
CSIndexExtensionRequestHandler = _Class("CSIndexExtensionRequestHandler")
MDIndexExtensionRequestHandler = _Class("MDIndexExtensionRequestHandler")
CSExtension_PKSubsystem = _Class("CSExtension_PKSubsystem")
CSExtensionJobThrottle = _Class("CSExtensionJobThrottle")
CSDecoder = _Class("CSDecoder")
CSCoder = _Class("CSCoder")
CSIndexingQueue = _Class("CSIndexingQueue")
CSCustomAttributeKey = _Class("CSCustomAttributeKey")
MDCustomAttributeKey = _Class("MDCustomAttributeKey")
CSSearchableItemAttributeSet = _Class("CSSearchableItemAttributeSet")
MDSearchableItemAttributeSet = _Class("MDSearchableItemAttributeSet")
CSUserAction = _Class("CSUserAction")
_MDUserAction = _Class("_MDUserAction")
MDUserAction = _Class("MDUserAction")
CSSearchableItem = _Class("CSSearchableItem")
MDSearchableItem = _Class("MDSearchableItem")
_MDSearchableItem = _Class("_MDSearchableItem")
_MDIndexExtension = _Class("_MDIndexExtension")
CSSearchContext = _Class("CSSearchContext")
CSPerson = _Class("CSPerson")
MDPerson = _Class("MDPerson")
CSSearchQuery = _Class("CSSearchQuery")
CSPrivateSearchQuery = _Class("CSPrivateSearchQuery")
CSUserQuery = _Class("CSUserQuery")
CSTopHitSearchQuery = _Class("CSTopHitSearchQuery")
CSSubscriptionManager = _Class("CSSubscriptionManager")
_MDHTMLParsing = _Class("_MDHTMLParsing")
CSXPCConnection = _Class("CSXPCConnection")
CSSearchConnection = _Class("CSSearchConnection")
CSPrivateSearchConnection = _Class("CSPrivateSearchConnection")
CSLifeFSConnection = _Class("CSLifeFSConnection")
CSIndexConnection = _Class("CSIndexConnection")
CSPrivateIndexConnection = _Class("CSPrivateIndexConnection")
CSIndexDelegateConnection = _Class("CSIndexDelegateConnection")
CSSearchableIndexRequest = _Class("CSSearchableIndexRequest")
CSSearchableIndex = _Class("CSSearchableIndex")
_MDSearchableIndex = _Class("_MDSearchableIndex")
CSPrivateSearchableIndex = _Class("CSPrivateSearchableIndex")
MDSearchableIndex = _Class("MDSearchableIndex")
_MDExtensionContext = _Class("_MDExtensionContext")
_MDRemoteExtensionContext = _Class("_MDRemoteExtensionContext")
_MDHostExtensionContext = _Class("_MDHostExtensionContext")
CSLocalizedString = _Class("CSLocalizedString")
MDLocalizedString = _Class("MDLocalizedString")
CSSearchableItemCodedArray = _Class("CSSearchableItemCodedArray")
