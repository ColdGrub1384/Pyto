"""
Classes from the 'MIME' framework.
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


MFWeakProxy = _Class("MFWeakProxy")
MFWeakReferenceHolder = _Class("MFWeakReferenceHolder")
MFArrayDiff = _Class("MFArrayDiff")
MFMutableMessageHeadersFactory = _Class("MFMutableMessageHeadersFactory")
MFTypeInfo = _Class("MFTypeInfo")
MFMessageTextAttachment = _Class("MFMessageTextAttachment")
MFMimeTextAttachment = _Class("MFMimeTextAttachment")
MFPartialNetworkDataConsumer = _Class("MFPartialNetworkDataConsumer")
MFMimePart = _Class("MFMimePart")
MFMimeCharset = _Class("MFMimeCharset")
MFMessageStoreObjectCache = _Class("MFMessageStoreObjectCache")
MFHTMLParser = _Class("MFHTMLParser")
MFDiagnostics = _Class("MFDiagnostics")
MFZeroCopyDataConsumer = _Class("MFZeroCopyDataConsumer")
MFDataHolder = _Class("MFDataHolder")
MFBlockDataConsumer = _Class("MFBlockDataConsumer")
MFNullDataConsumer = _Class("MFNullDataConsumer")
MFCountingDataConsumer = _Class("MFCountingDataConsumer")
MFBufferedDataConsumer = _Class("MFBufferedDataConsumer")
MFMessageDataContainer = _Class("MFMessageDataContainer")
MFMessageStore = _Class("MFMessageStore")
MFDataMessageStore = _Class("MFDataMessageStore")
MFMessageHeaders = _Class("MFMessageHeaders")
MFMutableMessageHeaders = _Class("MFMutableMessageHeaders")
MFMessageFileWrapper = _Class("MFMessageFileWrapper")
MFPlaceholderFileWrapper = _Class("MFPlaceholderFileWrapper")
MFMessageBody = _Class("MFMessageBody")
MFMimeBody = _Class("MFMimeBody")
MFMessage = _Class("MFMessage")
_MFEmailSetEmail = _Class("_MFEmailSetEmail")
MFBaseFilterDataConsumer = _Class("MFBaseFilterDataConsumer")
MFUUDecoder = _Class("MFUUDecoder")
MFQuotedPrintableDecoder = _Class("MFQuotedPrintableDecoder")
MFQuotedPrintableEncoder = _Class("MFQuotedPrintableEncoder")
MFProgressFilterDataConsumer = _Class("MFProgressFilterDataConsumer")
MFRangedDataFilter = _Class("MFRangedDataFilter")
MFLineEndingConverterFilter = _Class("MFLineEndingConverterFilter")
MFMutableFilterDataConsumer = _Class("MFMutableFilterDataConsumer")
MFBase64Decoder = _Class("MFBase64Decoder")
MFBase64Encoder = _Class("MFBase64Encoder")
MFConditionLock = _Class("MFConditionLock")
MFRecursiveLock = _Class("MFRecursiveLock")
MFLock = _Class("MFLock")
_MFEmailSetEnumerator = _Class("_MFEmailSetEnumerator")
MFData = _Class("MFData")
MFMutableData = _Class("MFMutableData")
MFWeakSet = _Class("MFWeakSet")
MFEmailSet = _Class("MFEmailSet")
