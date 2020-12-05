"""
Classes from the 'CoreRecognition' framework.
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


CRMLCCModel = _Class("CRMLCCModel")
CRMLEmbossedExpirationModel = _Class("CRMLEmbossedExpirationModel")
CRMLEmbossedCardholderModel = _Class("CRMLEmbossedCardholderModel")
CRMLEmbossedNumberModel = _Class("CRMLEmbossedNumberModel")
CRMLFlatModel = _Class("CRMLFlatModel")
ActivationMapTools = _Class("ActivationMapTools")
CRCameraReaderOutput = _Class("CRCameraReaderOutput")
CRCameraReaderOutputCameraText = _Class("CRCameraReaderOutputCameraText")
CRCameraReaderOutputIDCard = _Class("CRCameraReaderOutputIDCard")
CRCameraReaderOutputExpirationDate = _Class("CRCameraReaderOutputExpirationDate")
CRCameraReaderOutputInternal = _Class("CRCameraReaderOutputInternal")
CRInsights = _Class("CRInsights")
CRInsightsCodeSection = _Class("CRInsightsCodeSection")
CRInsightsContext = _Class("CRInsightsContext")
CRDefaultCaptureSessionManager = _Class("CRDefaultCaptureSessionManager")
CRColor = _Class("CRColor")
DiagnosticHUDLayer = _Class("DiagnosticHUDLayer")
CRAlignmentLayer = _Class("CRAlignmentLayer")
CRBoxLayer = _Class("CRBoxLayer")
CRCameraReader = _Class("CRCameraReader")
CRCodeRedeemerController = _Class("CRCodeRedeemerController")
