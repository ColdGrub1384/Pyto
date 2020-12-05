"""
Classes from the 'EmbeddedAcousticRecognition' framework.
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


_EARTokenizer = _Class("_EARTokenizer")
_EARPlsParser = _Class("_EARPlsParser")
_EARCommandTagger = _Class("_EARCommandTagger")
_EARCommandTaggingResult = _Class("_EARCommandTaggingResult")
_EARCommandTagging = _Class("_EARCommandTagging")
_EARLanguageDetector = _Class("_EARLanguageDetector")
_EARLanguageDetectorResult = _Class("_EARLanguageDetectorResult")
_EARLanguageDetectorLoggingInfo = _Class("_EARLanguageDetectorLoggingInfo")
EARCaesuraSilencePosteriorGenerator = _Class("EARCaesuraSilencePosteriorGenerator")
EARClientSilenceFeatures = _Class("EARClientSilenceFeatures")
_EARLmHandle = _Class("_EARLmHandle")
EARSyncPSRAudioProcessor = _Class("EARSyncPSRAudioProcessor")
EMTResult = _Class("EMTResult")
_EARFormatter = _Class("_EARFormatter")
_EARLanguageModel = _Class("_EARLanguageModel")
EMTTranslator = _Class("EMTTranslator")
EARAudioResultsGenerator = _Class("EARAudioResultsGenerator")
EARAudioResult = _Class("EARAudioResult")
EMTToken = _Class("EMTToken")
_EARLanguageDetectorAudioBuffer = _Class("_EARLanguageDetectorAudioBuffer")
EARCSpeechRecognitionResultStreamGlue = _Class("EARCSpeechRecognitionResultStreamGlue")
EARPSRAudioProcessor = _Class("EARPSRAudioProcessor")
_EARCustomLMBuilder = _Class("_EARCustomLMBuilder")
_EAROovToken = _Class("_EAROovToken")
_EARLmLoader = _Class("_EARLmLoader")
_EARLmEvaluator = _Class("_EARLmEvaluator")
_EARLmModel = _Class("_EARLmModel")
_EARLmData = _Class("_EARLmData")
_EARAppLmData = _Class("_EARAppLmData")
EMTTokenizer = _Class("EMTTokenizer")
EARAudioReader = _Class("EARAudioReader")
EARKeywordFinder = _Class("EARKeywordFinder")
EARKeywordFinderResult = _Class("EARKeywordFinderResult")
EARTokenPronounciations = _Class("EARTokenPronounciations")
_EARNnetUtil = _Class("_EARNnetUtil")
_EARTextNormalization = _Class("_EARTextNormalization")
_EARLanguageDetectorRequestContext = _Class("_EARLanguageDetectorRequestContext")
_EARResultCombiner = _Class("_EARResultCombiner")
_EARSystemResult = _Class("_EARSystemResult")
_EARCombinedResult = _Class("_EARCombinedResult")
_EARSyncSpeechRecognizer = _Class("_EARSyncSpeechRecognizer")
_EARSpeechRecognitionAudioBuffer = _Class("_EARSpeechRecognitionAudioBuffer")
_EARTransformUtil = _Class("_EARTransformUtil")
EARSdapiHelper = _Class("EARSdapiHelper")
_EARSyncResultStreamHelper = _Class("_EARSyncResultStreamHelper")
_EARSpeechModelInfo = _Class("_EARSpeechModelInfo")
_EARSpeechRecognizer = _Class("_EARSpeechRecognizer")
_EARSpeechRecognitionResult = _Class("_EARSpeechRecognitionResult")
_EARSpeechRecognitionResultPackage = _Class("_EARSpeechRecognitionResultPackage")
_EARSpeechRecognition = _Class("_EARSpeechRecognition")
_EARLatticeMitigatorResult = _Class("_EARLatticeMitigatorResult")
_EARAudioAnalytics = _Class("_EARAudioAnalytics")
_EARAcousticFeature = _Class("_EARAcousticFeature")
_EARSpeechRecognitionToken = _Class("_EARSpeechRecognitionToken")
_EAREndpointer = _Class("_EAREndpointer")
_EARDefaultServerEndpointFeatures = _Class("_EARDefaultServerEndpointFeatures")
_EAREndpointFeatures = _Class("_EAREndpointFeatures")
_EARUserProfileBuilder = _Class("_EARUserProfileBuilder")
_EARUserProfile = _Class("_EARUserProfile")
_EARWordPart = _Class("_EARWordPart")
