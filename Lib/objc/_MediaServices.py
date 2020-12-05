"""
Classes from the 'MediaServices' framework.
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


MSVWeakProxy = _Class("MSVWeakProxy")
MSVFinally = _Class("MSVFinally")
MSVMultiCallback = _Class("MSVMultiCallback")
MSVCallback = _Class("MSVCallback")
MSVPair = _Class("MSVPair")
MSVArtworkServiceResizeRequestDestination = _Class(
    "MSVArtworkServiceResizeRequestDestination"
)
MSVBlockGuard = _Class("MSVBlockGuard")
_MSVStreamWriterPendingData = _Class("_MSVStreamWriterPendingData")
MSVStreamWriter = _Class("MSVStreamWriter")
MSVLRUDictionary = _Class("MSVLRUDictionary")
MSVLRUDictionaryNode = _Class("MSVLRUDictionaryNode")
MSVBloomFilter = _Class("MSVBloomFilter")
MSVPropertyListEncoder = _Class("MSVPropertyListEncoder")
MSVSystemDialogManager = _Class("MSVSystemDialogManager")
MSVSystemDialogResponse = _Class("MSVSystemDialogResponse")
MSVSystemDialogOptions = _Class("MSVSystemDialogOptions")
MSVSystemDialogTextField = _Class("MSVSystemDialogTextField")
MSVSystemDialog = _Class("MSVSystemDialog")
MSVMessageParser = _Class("MSVMessageParser")
_MSVSQLDatabaseTransactionSavepoint = _Class("_MSVSQLDatabaseTransactionSavepoint")
MSVSQLDatabaseTransaction = _Class("MSVSQLDatabaseTransaction")
MSVSQLStatement = _Class("MSVSQLStatement")
MSVSQLDatabase = _Class("MSVSQLDatabase")
MSVZipArchive = _Class("MSVZipArchive")
MSVArtworkService = _Class("MSVArtworkService")
MSVStreamReader = _Class("MSVStreamReader")
MSVEntitlementUtilities = _Class("MSVEntitlementUtilities")
_EntitlementCheckResult = _Class("_EntitlementCheckResult")
MSVXPCTransaction = _Class("MSVXPCTransaction")
MSVRandomDistribution = _Class("MSVRandomDistribution")
MSVARC4RandomSource = _Class("MSVARC4RandomSource")
MSVCLICommand = _Class("MSVCLICommand")
MSVPersistentTimer = _Class("MSVPersistentTimer")
MSVTimer = _Class("MSVTimer")
MSVWatchdog = _Class("MSVWatchdog")
MSVFileBufferedPipe = _Class("MSVFileBufferedPipe")
MSVCLIBlockHandler = _Class("MSVCLIBlockHandler")
MSVCLICommandInterpreter = _Class("MSVCLICommandInterpreter")
MSVLyricsXMLElement = _Class("MSVLyricsXMLElement")
MSVLyricsTranslationText = _Class("MSVLyricsTranslationText")
MSVLyricsTranslation = _Class("MSVLyricsTranslation")
MSVLyricsAgent = _Class("MSVLyricsAgent")
MSVLyricsSongWriter = _Class("MSVLyricsSongWriter")
MSVLyricsElement = _Class("MSVLyricsElement")
MSVLyricsSection = _Class("MSVLyricsSection")
MSVLyricsTextElement = _Class("MSVLyricsTextElement")
MSVLyricsWord = _Class("MSVLyricsWord")
MSVLyricsLine = _Class("MSVLyricsLine")
MSVLyricsSongInfo = _Class("MSVLyricsSongInfo")
MSVDistributedNotificationObserver = _Class("MSVDistributedNotificationObserver")
MSVSegmentedCodingPackage = _Class("MSVSegmentedCodingPackage")
MSVTaskAssertion = _Class("MSVTaskAssertion")
MSVArtworkServiceRequest = _Class("MSVArtworkServiceRequest")
MSVArtworkServiceResizeRequest = _Class("MSVArtworkServiceResizeRequest")
MSVArtworkServiceConversionRequest = _Class("MSVArtworkServiceConversionRequest")
MSVBidirectionalDictionary = _Class("MSVBidirectionalDictionary")
MSVMutableBidirectionalDictionary = _Class("MSVMutableBidirectionalDictionary")
MSVLyricsTTMLParser = _Class("MSVLyricsTTMLParser")
MSVOPACKDecoder = _Class("MSVOPACKDecoder")
MSVOPACKEncoder = _Class("MSVOPACKEncoder")
MSVSegmentedDecoder = _Class("MSVSegmentedDecoder")
MSVSegmentedEncoder = _Class("MSVSegmentedEncoder")
MSVAsyncOperation = _Class("MSVAsyncOperation")
MSVArtworkServiceOperation = _Class("MSVArtworkServiceOperation")
MSVArtworkServiceConversionOperation = _Class("MSVArtworkServiceConversionOperation")
MSVArtworkServiceResizeOperation = _Class("MSVArtworkServiceResizeOperation")
MSVSQLRowEnumerator = _Class("MSVSQLRowEnumerator")
