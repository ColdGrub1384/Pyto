"""
Classes from the 'DistributedEvaluation' framework.
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


DESEvaluationSession = _Class("DESEvaluationSession")
DESExceptionCatchingEvaluator = _Class("DESExceptionCatchingEvaluator")
DESServiceConnection = _Class("DESServiceConnection")
DESPFLEncryptableBuffer = _Class("DESPFLEncryptableBuffer")
DESPFLEncryptor = _Class("DESPFLEncryptor")
DESRecipe = _Class("DESRecipe")
DESRecordStore = _Class("DESRecordStore")
DESJSONPredicate = _Class("DESJSONPredicate")
DESRecipeEvaluationSession = _Class("DESRecipeEvaluationSession")
DESBundleRegistry = _Class("DESBundleRegistry")
DESSignatureKey = _Class("DESSignatureKey")
DESDeviceIdentifierStore = _Class("DESDeviceIdentifierStore")
DESRecordSet = _Class("DESRecordSet")
DESDataTransport = _Class("DESDataTransport")
DESEncryptedData = _Class("DESEncryptedData")
DESPFLNoisable = _Class("DESPFLNoisable")
DESBinary64Transport = _Class("DESBinary64Transport")
DESBinary32Transport = _Class("DESBinary32Transport")
DESBfloat16Transport = _Class("DESBfloat16Transport")
