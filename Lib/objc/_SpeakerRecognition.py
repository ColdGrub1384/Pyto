"""
Classes from the 'SpeakerRecognition' framework.
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


SSRPitchExtractor = _Class("SSRPitchExtractor")
CSVTUIASRGrammars = _Class("CSVTUIASRGrammars")
SSRSpeakerRecognitionModelContext = _Class("SSRSpeakerRecognitionModelContext")
SSRSpeakerRecognitionContext = _Class("SSRSpeakerRecognitionContext")
SSRVoiceProfileStorePrefs = _Class("SSRVoiceProfileStorePrefs")
SSRSpeakerAnalyzerSAT = _Class("SSRSpeakerAnalyzerSAT")
SSRBiometricMatch = _Class("SSRBiometricMatch")
SSRVoiceProfileStore = _Class("SSRVoiceProfileStore")
SSRMobileAssetProvider = _Class("SSRMobileAssetProvider")
SSRSpeakerRecognitionController = _Class("SSRSpeakerRecognitionController")
SSRAssetManager = _Class("SSRAssetManager")
SSRVoiceProfileManager = _Class("SSRVoiceProfileManager")
CSVTUITrainingSession = _Class("CSVTUITrainingSession")
CSVTUITrainingSessionWithPayload = _Class("CSVTUITrainingSessionWithPayload")
CSVTUIRegularExpressionMatcher = _Class("CSVTUIRegularExpressionMatcher")
SSRVoiceProfileMetadataManager = _Class("SSRVoiceProfileMetadataManager")
SSRVoiceProfileModelContext = _Class("SSRVoiceProfileModelContext")
SSRVoiceProfileRetrainingContext = _Class("SSRVoiceProfileRetrainingContext")
SSRVoiceProfilePruner = _Class("SSRVoiceProfilePruner")
CSPowerAssertionGibraltar = _Class("CSPowerAssertionGibraltar")
SSRTriggerPhraseDetectorQuasar = _Class("SSRTriggerPhraseDetectorQuasar")
SSRVoiceProfile = _Class("SSRVoiceProfile")
SSRVoiceProfileStoreCleaner = _Class("SSRVoiceProfileStoreCleaner")
SSRSpeakerRecognizerSAT = _Class("SSRSpeakerRecognizerSAT")
SSRLoggingAggregator = _Class("SSRLoggingAggregator")
SSRVoiceProfileRetrainerPSR = _Class("SSRVoiceProfileRetrainerPSR")
SSRVoiceProfileComposer = _Class("SSRVoiceProfileComposer")
CSVTUIKeywordDetector = _Class("CSVTUIKeywordDetector")
SSRTrialAssetProvider = _Class("SSRTrialAssetProvider")
SSRTriggerPhraseDetector = _Class("SSRTriggerPhraseDetector")
SSRVoiceProfileMetaContext = _Class("SSRVoiceProfileMetaContext")
SSRVoiceProfileRetrainerFactory = _Class("SSRVoiceProfileRetrainerFactory")
SSRVTUITrainingManager = _Class("SSRVTUITrainingManager")
SSRSpeakerRecognitionScorer = _Class("SSRSpeakerRecognitionScorer")
SSRDESRecordWriter = _Class("SSRDESRecordWriter")
SSRVoiceProfileRetrainerSAT = _Class("SSRVoiceProfileRetrainerSAT")
SSRSpeakerRecognitionOrchestrator = _Class("SSRSpeakerRecognitionOrchestrator")
SSRSpeakerRecognizerPSR = _Class("SSRSpeakerRecognizerPSR")
SSRSpeakerAnalyzerPSR = _Class("SSRSpeakerAnalyzerPSR")
SSRVoiceActivityDetector = _Class("SSRVoiceActivityDetector")
