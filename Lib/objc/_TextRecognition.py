"""
Classes from the 'TextRecognition' framework.
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


CRImage = _Class("CRImage")
CRImage_PixelBuffer = _Class("CRImage_PixelBuffer")
TextResults = _Class("TextResults")
TextColumn = _Class("TextColumn")
TextRow = _Class("TextRow")
TextToken = _Class("TextToken")
CRRecognizerAsyncFeatureBatchProviderV1 = _Class(
    "CRRecognizerAsyncFeatureBatchProviderV1"
)
CRPerformanceMetric = _Class("CRPerformanceMetric")
CRPerformanceStatistics = _Class("CRPerformanceStatistics")
CRLatticeResults = _Class("CRLatticeResults")
CRLatticeRun = _Class("CRLatticeRun")
CRLatticePath = _Class("CRLatticePath")
CRLatticeEdge = _Class("CRLatticeEdge")
CREngineFast = _Class("CREngineFast")
CRFeatureSequenceRecognitionInfo = _Class("CRFeatureSequenceRecognitionInfo")
CRLanguageResourcesManager = _Class("CRLanguageResourcesManager")
CRLanguageResourcesStack = _Class("CRLanguageResourcesStack")
CRTextFeature = _Class("CRTextFeature")
CRTextFeatureMultiRegion = _Class("CRTextFeatureMultiRegion")
CRTextDecoderCTCV1 = _Class("CRTextDecoderCTCV1")
CRTextDecoderCTCCoreML = _Class("CRTextDecoderCTCCoreML")
CRNMS = _Class("CRNMS")
CRCtcBeamState = _Class("CRCtcBeamState")
CRCtcBeamSearch = _Class("CRCtcBeamSearch")
CREngineAccurate = _Class("CREngineAccurate")
CRLanguageUtils = _Class("CRLanguageUtils")
CRLanguageResources = _Class("CRLanguageResources")
CRCtcPath = _Class("CRCtcPath")
CRRecognizerConfiguration = _Class("CRRecognizerConfiguration")
CRTextDecoderCTCV2 = _Class("CRTextDecoderCTCV2")
CRTextDecoderCTCEspresso = _Class("CRTextDecoderCTCEspresso")
CRImageReaderOutput = _Class("CRImageReaderOutput")
CRIntermediateDetectorResult = _Class("CRIntermediateDetectorResult")
CRTextDecodingUtils = _Class("CRTextDecodingUtils")
CRTextRecognizerTopKModelEspressoOutput = _Class(
    "CRTextRecognizerTopKModelEspressoOutput"
)
CRRegex = _Class("CRRegex")
CRDetectorConfiguration = _Class("CRDetectorConfiguration")
ActivationMapToolsOCR = _Class("ActivationMapToolsOCR")
CRPollingTimer = _Class("CRPollingTimer")
CRCHCharacterSetRules = _Class("CRCHCharacterSetRules")
CRFuthark = _Class("CRFuthark")
CRCtcMaxDecoding = _Class("CRCtcMaxDecoding")
SymbolCandidate = _Class("SymbolCandidate")
GeometricCutTools = _Class("GeometricCutTools")
CRCtcTimeSample = _Class("CRCtcTimeSample")
CRTextResults = _Class("CRTextResults")
CRTextRecognizerResults = _Class("CRTextRecognizerResults")
CRTextDetectorResults = _Class("CRTextDetectorResults")
CRImageReader = _Class("CRImageReader")
CRTextRecognizerModelEspressoOutput = _Class("CRTextRecognizerModelEspressoOutput")
CRTextRecognizerModelEspressoInput = _Class("CRTextRecognizerModelEspressoInput")
CRTextSequenceRecognizerModel = _Class("CRTextSequenceRecognizerModel")
CRTextSequenceRecognizerModelEspresso = _Class("CRTextSequenceRecognizerModelEspresso")
CRTextRecognizerModelLatinV2 = _Class("CRTextRecognizerModelLatinV2")
CRTextSequenceRecognizerTopKModelEspresso = _Class(
    "CRTextSequenceRecognizerTopKModelEspresso"
)
CRTextRecognizerModelChineseV2 = _Class("CRTextRecognizerModelChineseV2")
CRTextSequenceRecognizerModelCoreML = _Class("CRTextSequenceRecognizerModelCoreML")
CRTextRecognizerModelV1 = _Class("CRTextRecognizerModelV1")
CRTextSequenceRecognizerModelCoreMLOutput = _Class(
    "CRTextSequenceRecognizerModelCoreMLOutput"
)
CRTextSequenceRecognizerModelCoreMLInput = _Class(
    "CRTextSequenceRecognizerModelCoreMLInput"
)
CRTextDetectorModel = _Class("CRTextDetectorModel")
CRTextDetectorModelV2 = _Class("CRTextDetectorModelV2")
CRTextDetectorModelOutput = _Class("CRTextDetectorModelOutput")
CRTextDetectorModelInput = _Class("CRTextDetectorModelInput")
CRLanguageCorrection = _Class("CRLanguageCorrection")
CRNeuralTextRecognizer = _Class("CRNeuralTextRecognizer")
CRNeuralTextDetector = _Class("CRNeuralTextDetector")
CRNeuralTextDetectorV1 = _Class("CRNeuralTextDetectorV1")
CRNeuralTextDetectorV2 = _Class("CRNeuralTextDetectorV2")
CRCHPatternNetwork = _Class("CRCHPatternNetwork")
CRCHNetworkCursor = _Class("CRCHNetworkCursor")
CRMLModel = _Class("CRMLModel")
