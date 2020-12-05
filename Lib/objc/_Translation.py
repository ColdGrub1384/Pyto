"""
Classes from the 'Translation' framework.
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


_LTTranslationToken = _Class("_LTTranslationToken")
_LTLoggingRequestHandler = _Class("_LTLoggingRequestHandler")
_LTLocalePair = _Class("_LTLocalePair")
_LTSpeechTranscription = _Class("_LTSpeechTranscription")
_LTInstallRequest = _Class("_LTInstallRequest")
FTLanguageDetectionStreamingContext = _Class("FTLanguageDetectionStreamingContext")
FTTextToSpeechStreamingStreamingContext = _Class(
    "FTTextToSpeechStreamingStreamingContext"
)
FTTextToSpeechRouterStreamingStreamingContext = _Class(
    "FTTextToSpeechRouterStreamingStreamingContext"
)
FTBatchTranslationStreamingContext = _Class("FTBatchTranslationStreamingContext")
FTSpeechTranslationStreamingContext = _Class("FTSpeechTranslationStreamingContext")
FTMultilingualStreamingContext = _Class("FTMultilingualStreamingContext")
FTMultiUserStreamingContext = _Class("FTMultiUserStreamingContext")
FTRecognitionStreamingContext = _Class("FTRecognitionStreamingContext")
FTBatchRecoverStreamingContext = _Class("FTBatchRecoverStreamingContext")
FTPronGuessStreamingContext = _Class("FTPronGuessStreamingContext")
_LTSpeechRecognitionTokensAlternative = _Class("_LTSpeechRecognitionTokensAlternative")
_LTSpeechRecognitionBin = _Class("_LTSpeechRecognitionBin")
_LTSpeechRecognitionSausage = _Class("_LTSpeechRecognitionSausage")
_LTTranslationParagraph = _Class("_LTTranslationParagraph")
_LTTextLanguageDetector = _Class("_LTTextLanguageDetector")
_LTAnalyticsEvent = _Class("_LTAnalyticsEvent")
_LTSpeechRecognitionResult = _Class("_LTSpeechRecognitionResult")
_LTOspreySpeechTranslationSession = _Class("_LTOspreySpeechTranslationSession")
_LTClientConnection = _Class("_LTClientConnection")
_LTTranslationCandidate = _Class("_LTTranslationCandidate")
_LTServerSpeechSession = _Class("_LTServerSpeechSession")
_LTTranslationServer = _Class("_LTTranslationServer")
_LTPlaybackService = _Class("_LTPlaybackService")
_LTSpeechRecognizer = _Class("_LTSpeechRecognizer")
_LTEtiquetteSanitizer = _Class("_LTEtiquetteSanitizer")
_LTMatch = _Class("_LTMatch")
_LTTranslator = _Class("_LTTranslator")
_LTTranslationFeedback = _Class("_LTTranslationFeedback")
_LTCombinedEngine = _Class("_LTCombinedEngine")
_LTTranslationResult = _Class("_LTTranslationResult")
_LTTranslationSpan = _Class("_LTTranslationSpan")
_LTSpeechCompressor = _Class("_LTSpeechCompressor")
_LTTranslationRange = _Class("_LTTranslationRange")
_LTTranslationSession = _Class("_LTTranslationSession")
_LTSafariLatencyLoggingRequest = _Class("_LTSafariLatencyLoggingRequest")
_LTSpeechLIDLoggingRequest = _Class("_LTSpeechLIDLoggingRequest")
_LTTranslationSense = _Class("_LTTranslationSense")
_LTMultilingualSpeechRecognizer = _Class("_LTMultilingualSpeechRecognizer")
_LTLanguageDetectorAssetInfo = _Class("_LTLanguageDetectorAssetInfo")
_LTOfflineSpeechSynthesizer = _Class("_LTOfflineSpeechSynthesizer")
_LTOfflineTranslationEngine = _Class("_LTOfflineTranslationEngine")
_LTLanguagePairOfflineAvailability = _Class("_LTLanguagePairOfflineAvailability")
FTLanguageDetectionStreamingResponse = _Class("FTLanguageDetectionStreamingResponse")
FTMutableLanguageDetectionStreamingResponse = _Class(
    "FTMutableLanguageDetectionStreamingResponse"
)
FTLanguageDetectionStreamingRequest = _Class("FTLanguageDetectionStreamingRequest")
FTMutableLanguageDetectionStreamingRequest = _Class(
    "FTMutableLanguageDetectionStreamingRequest"
)
FTTextToSpeechStreamingStreamingResponse = _Class(
    "FTTextToSpeechStreamingStreamingResponse"
)
FTMutableTextToSpeechStreamingStreamingResponse = _Class(
    "FTMutableTextToSpeechStreamingStreamingResponse"
)
FTTextToSpeechStreamingStreamingRequest = _Class(
    "FTTextToSpeechStreamingStreamingRequest"
)
FTMutableTextToSpeechStreamingStreamingRequest = _Class(
    "FTMutableTextToSpeechStreamingStreamingRequest"
)
FTTextToSpeechRouterStreamingStreamingResponse = _Class(
    "FTTextToSpeechRouterStreamingStreamingResponse"
)
FTMutableTextToSpeechRouterStreamingStreamingResponse = _Class(
    "FTMutableTextToSpeechRouterStreamingStreamingResponse"
)
FTTextToSpeechRouterStreamingStreamingRequest = _Class(
    "FTTextToSpeechRouterStreamingStreamingRequest"
)
FTMutableTextToSpeechRouterStreamingStreamingRequest = _Class(
    "FTMutableTextToSpeechRouterStreamingStreamingRequest"
)
FTBatchTranslationStreamingResponse = _Class("FTBatchTranslationStreamingResponse")
FTMutableBatchTranslationStreamingResponse = _Class(
    "FTMutableBatchTranslationStreamingResponse"
)
FTBatchTranslationStreamingRequest = _Class("FTBatchTranslationStreamingRequest")
FTMutableBatchTranslationStreamingRequest = _Class(
    "FTMutableBatchTranslationStreamingRequest"
)
FTSpeechTranslationStreamingResponse = _Class("FTSpeechTranslationStreamingResponse")
FTMutableSpeechTranslationStreamingResponse = _Class(
    "FTMutableSpeechTranslationStreamingResponse"
)
FTSpeechTranslationStreamingRequest = _Class("FTSpeechTranslationStreamingRequest")
FTMutableSpeechTranslationStreamingRequest = _Class(
    "FTMutableSpeechTranslationStreamingRequest"
)
FTMultilingualStreamingResponse = _Class("FTMultilingualStreamingResponse")
FTMutableMultilingualStreamingResponse = _Class(
    "FTMutableMultilingualStreamingResponse"
)
FTMultilingualStreamingRequest = _Class("FTMultilingualStreamingRequest")
FTMutableMultilingualStreamingRequest = _Class("FTMutableMultilingualStreamingRequest")
FTMultiUserStreamingResponse = _Class("FTMultiUserStreamingResponse")
FTMutableMultiUserStreamingResponse = _Class("FTMutableMultiUserStreamingResponse")
FTMultiUserStreamingRequest = _Class("FTMultiUserStreamingRequest")
FTMutableMultiUserStreamingRequest = _Class("FTMutableMultiUserStreamingRequest")
FTRecognitionStreamingResponse = _Class("FTRecognitionStreamingResponse")
FTMutableRecognitionStreamingResponse = _Class("FTMutableRecognitionStreamingResponse")
FTRecognitionStreamingRequest = _Class("FTRecognitionStreamingRequest")
FTMutableRecognitionStreamingRequest = _Class("FTMutableRecognitionStreamingRequest")
FTBatchRecoverStreamingResponse = _Class("FTBatchRecoverStreamingResponse")
FTMutableBatchRecoverStreamingResponse = _Class(
    "FTMutableBatchRecoverStreamingResponse"
)
FTBatchRecoverStreamingRequest = _Class("FTBatchRecoverStreamingRequest")
FTMutableBatchRecoverStreamingRequest = _Class("FTMutableBatchRecoverStreamingRequest")
FTPronGuessStreamingResponse = _Class("FTPronGuessStreamingResponse")
FTMutablePronGuessStreamingResponse = _Class("FTMutablePronGuessStreamingResponse")
FTPronGuessStreamingRequest = _Class("FTPronGuessStreamingRequest")
FTMutablePronGuessStreamingRequest = _Class("FTMutablePronGuessStreamingRequest")
FTLanguageDetectionResponse = _Class("FTLanguageDetectionResponse")
FTMutableLanguageDetectionResponse = _Class("FTMutableLanguageDetectionResponse")
FTStartLanguageDetectionRequest = _Class("FTStartLanguageDetectionRequest")
FTMutableStartLanguageDetectionRequest = _Class(
    "FTMutableStartLanguageDetectionRequest"
)
FTBatchTranslationCacheContainer = _Class("FTBatchTranslationCacheContainer")
FTMutableBatchTranslationCacheContainer = _Class(
    "FTMutableBatchTranslationCacheContainer"
)
FTBatchTranslationResponse = _Class("FTBatchTranslationResponse")
FTMutableBatchTranslationResponse = _Class("FTMutableBatchTranslationResponse")
FTBatchTranslationRequest_Paragraph = _Class("FTBatchTranslationRequest_Paragraph")
FTMutableBatchTranslationRequest_Paragraph = _Class(
    "FTMutableBatchTranslationRequest_Paragraph"
)
FTBatchTranslationRequest = _Class("FTBatchTranslationRequest")
FTMutableBatchTranslationRequest = _Class("FTMutableBatchTranslationRequest")
FTFinalBlazarResponse = _Class("FTFinalBlazarResponse")
FTMutableFinalBlazarResponse = _Class("FTMutableFinalBlazarResponse")
FTLanguageDetected = _Class("FTLanguageDetected")
FTMutableLanguageDetected = _Class("FTMutableLanguageDetected")
FTLanguageDetectionPrediction = _Class("FTLanguageDetectionPrediction")
FTMutableLanguageDetectionPrediction = _Class("FTMutableLanguageDetectionPrediction")
FTStartMultilingualSpeechRequest = _Class("FTStartMultilingualSpeechRequest")
FTMutableStartMultilingualSpeechRequest = _Class(
    "FTMutableStartMultilingualSpeechRequest"
)
FTLanguageParameters = _Class("FTLanguageParameters")
FTMutableLanguageParameters = _Class("FTMutableLanguageParameters")
FTShortcutFuzzyMatchResponse_ShortcutScorePair = _Class(
    "FTShortcutFuzzyMatchResponse_ShortcutScorePair"
)
FTMutableShortcutFuzzyMatchResponse_ShortcutScorePair = _Class(
    "FTMutableShortcutFuzzyMatchResponse_ShortcutScorePair"
)
FTShortcutFuzzyMatchResponse = _Class("FTShortcutFuzzyMatchResponse")
FTMutableShortcutFuzzyMatchResponse = _Class("FTMutableShortcutFuzzyMatchResponse")
FTShortcutFuzzyMatchRequest_StringTokenPair = _Class(
    "FTShortcutFuzzyMatchRequest_StringTokenPair"
)
FTMutableShortcutFuzzyMatchRequest_StringTokenPair = _Class(
    "FTMutableShortcutFuzzyMatchRequest_StringTokenPair"
)
FTShortcutFuzzyMatchRequest = _Class("FTShortcutFuzzyMatchRequest")
FTMutableShortcutFuzzyMatchRequest = _Class("FTMutableShortcutFuzzyMatchRequest")
FTSpeechTranslationServerEndpointFeatures = _Class(
    "FTSpeechTranslationServerEndpointFeatures"
)
FTMutableSpeechTranslationServerEndpointFeatures = _Class(
    "FTMutableSpeechTranslationServerEndpointFeatures"
)
FTSpeechTranslationTextToSpeechResponse = _Class(
    "FTSpeechTranslationTextToSpeechResponse"
)
FTMutableSpeechTranslationTextToSpeechResponse = _Class(
    "FTMutableSpeechTranslationTextToSpeechResponse"
)
FTSpeechTranslationMtResponse_TranslationPhrase = _Class(
    "FTSpeechTranslationMtResponse_TranslationPhrase"
)
FTMutableSpeechTranslationMtResponse_TranslationPhrase = _Class(
    "FTMutableSpeechTranslationMtResponse_TranslationPhrase"
)
FTSpeechTranslationMtResponse = _Class("FTSpeechTranslationMtResponse")
FTMutableSpeechTranslationMtResponse = _Class("FTMutableSpeechTranslationMtResponse")
FTSpeechTranslationFinalRecognitionResponse = _Class(
    "FTSpeechTranslationFinalRecognitionResponse"
)
FTMutableSpeechTranslationFinalRecognitionResponse = _Class(
    "FTMutableSpeechTranslationFinalRecognitionResponse"
)
FTSpeechTranslationPartialRecognitionResponse = _Class(
    "FTSpeechTranslationPartialRecognitionResponse"
)
FTMutableSpeechTranslationPartialRecognitionResponse = _Class(
    "FTMutableSpeechTranslationPartialRecognitionResponse"
)
FTStartSpeechTranslationLoggingRequest = _Class(
    "FTStartSpeechTranslationLoggingRequest"
)
FTMutableStartSpeechTranslationLoggingRequest = _Class(
    "FTMutableStartSpeechTranslationLoggingRequest"
)
FTStartSpeechTranslationRequest = _Class("FTStartSpeechTranslationRequest")
FTMutableStartSpeechTranslationRequest = _Class(
    "FTMutableStartSpeechTranslationRequest"
)
FTTranslationLocalePair = _Class("FTTranslationLocalePair")
FTMutableTranslationLocalePair = _Class("FTMutableTranslationLocalePair")
FTSpeechTranslationAudioPacket = _Class("FTSpeechTranslationAudioPacket")
FTMutableSpeechTranslationAudioPacket = _Class("FTMutableSpeechTranslationAudioPacket")
FTAudioFrame = _Class("FTAudioFrame")
FTMutableAudioFrame = _Class("FTMutableAudioFrame")
FTAudioLimitExceeded = _Class("FTAudioLimitExceeded")
FTMutableAudioLimitExceeded = _Class("FTMutableAudioLimitExceeded")
FTClientSetupInfo = _Class("FTClientSetupInfo")
FTMutableClientSetupInfo = _Class("FTMutableClientSetupInfo")
FTQssAckResponse = _Class("FTQssAckResponse")
FTMutableQssAckResponse = _Class("FTMutableQssAckResponse")
FTTextToSpeechCacheContainer = _Class("FTTextToSpeechCacheContainer")
FTMutableTextToSpeechCacheContainer = _Class("FTMutableTextToSpeechCacheContainer")
FTTextToSpeechCacheObject = _Class("FTTextToSpeechCacheObject")
FTMutableTextToSpeechCacheObject = _Class("FTMutableTextToSpeechCacheObject")
FTTextToSpeechCacheMetaInfo = _Class("FTTextToSpeechCacheMetaInfo")
FTMutableTextToSpeechCacheMetaInfo = _Class("FTMutableTextToSpeechCacheMetaInfo")
FTFinalTextToSpeechStreamingResponse = _Class("FTFinalTextToSpeechStreamingResponse")
FTMutableFinalTextToSpeechStreamingResponse = _Class(
    "FTMutableFinalTextToSpeechStreamingResponse"
)
FTPartialTextToSpeechStreamingResponse = _Class(
    "FTPartialTextToSpeechStreamingResponse"
)
FTMutablePartialTextToSpeechStreamingResponse = _Class(
    "FTMutablePartialTextToSpeechStreamingResponse"
)
FTBeginTextToSpeechStreamingResponse = _Class("FTBeginTextToSpeechStreamingResponse")
FTMutableBeginTextToSpeechStreamingResponse = _Class(
    "FTMutableBeginTextToSpeechStreamingResponse"
)
FTStartTextToSpeechStreamingRequest_ContextInfoEntry = _Class(
    "FTStartTextToSpeechStreamingRequest_ContextInfoEntry"
)
FTMutableStartTextToSpeechStreamingRequest_ContextInfoEntry = _Class(
    "FTMutableStartTextToSpeechStreamingRequest_ContextInfoEntry"
)
FTStartTextToSpeechStreamingRequest = _Class("FTStartTextToSpeechStreamingRequest")
FTMutableStartTextToSpeechStreamingRequest = _Class(
    "FTMutableStartTextToSpeechStreamingRequest"
)
FTTextToSpeechResponse = _Class("FTTextToSpeechResponse")
FTMutableTextToSpeechResponse = _Class("FTMutableTextToSpeechResponse")
FTWordTimingInfo = _Class("FTWordTimingInfo")
FTMutableWordTimingInfo = _Class("FTMutableWordTimingInfo")
FTAudioDescription = _Class("FTAudioDescription")
FTMutableAudioDescription = _Class("FTMutableAudioDescription")
FTTextToSpeechRequest_ContextInfoEntry = _Class(
    "FTTextToSpeechRequest_ContextInfoEntry"
)
FTMutableTextToSpeechRequest_ContextInfoEntry = _Class(
    "FTMutableTextToSpeechRequest_ContextInfoEntry"
)
FTTextToSpeechRequest = _Class("FTTextToSpeechRequest")
FTMutableTextToSpeechRequest = _Class("FTMutableTextToSpeechRequest")
FTTextToSpeechUserProfile = _Class("FTTextToSpeechUserProfile")
FTMutableTextToSpeechUserProfile = _Class("FTMutableTextToSpeechUserProfile")
FTTextToSpeechVoiceResource = _Class("FTTextToSpeechVoiceResource")
FTMutableTextToSpeechVoiceResource = _Class("FTMutableTextToSpeechVoiceResource")
FTTextToSpeechRequestDebug = _Class("FTTextToSpeechRequestDebug")
FTMutableTextToSpeechRequestDebug = _Class("FTMutableTextToSpeechRequestDebug")
FTTextToSpeechFeature = _Class("FTTextToSpeechFeature")
FTMutableTextToSpeechFeature = _Class("FTMutableTextToSpeechFeature")
FTTTSNormalizedText = _Class("FTTTSNormalizedText")
FTMutableTTSNormalizedText = _Class("FTMutableTTSNormalizedText")
FTTTSReplacement = _Class("FTTTSReplacement")
FTMutableTTSReplacement = _Class("FTMutableTTSReplacement")
FTTTSPrompts = _Class("FTTTSPrompts")
FTMutableTTSPrompts = _Class("FTMutableTTSPrompts")
FTTTSPhonemeSequence = _Class("FTTTSPhonemeSequence")
FTMutableTTSPhonemeSequence = _Class("FTMutableTTSPhonemeSequence")
FTTTSWordPhonemes = _Class("FTTTSWordPhonemes")
FTMutableTTSWordPhonemes = _Class("FTMutableTTSWordPhonemes")
FTTextToSpeechRequestExperiment = _Class("FTTextToSpeechRequestExperiment")
FTMutableTextToSpeechRequestExperiment = _Class(
    "FTMutableTextToSpeechRequestExperiment"
)
FTTextToSpeechRequestContext_ContextInfoEntry = _Class(
    "FTTextToSpeechRequestContext_ContextInfoEntry"
)
FTMutableTextToSpeechRequestContext_ContextInfoEntry = _Class(
    "FTMutableTextToSpeechRequestContext_ContextInfoEntry"
)
FTTextToSpeechRequestContext = _Class("FTTextToSpeechRequestContext")
FTMutableTextToSpeechRequestContext = _Class("FTMutableTextToSpeechRequestContext")
FTTextToSpeechRequestMeta = _Class("FTTextToSpeechRequestMeta")
FTMutableTextToSpeechRequestMeta = _Class("FTMutableTextToSpeechRequestMeta")
FTTextToSpeechMeta = _Class("FTTextToSpeechMeta")
FTMutableTextToSpeechMeta = _Class("FTMutableTextToSpeechMeta")
FTTextToSpeechResource = _Class("FTTextToSpeechResource")
FTMutableTextToSpeechResource = _Class("FTMutableTextToSpeechResource")
FTTextToSpeechVoice = _Class("FTTextToSpeechVoice")
FTMutableTextToSpeechVoice = _Class("FTMutableTextToSpeechVoice")
FTTTSRequestFeatureFlags = _Class("FTTTSRequestFeatureFlags")
FTMutableTTSRequestFeatureFlags = _Class("FTMutableTTSRequestFeatureFlags")
FTCorrectionsValidatorResponse = _Class("FTCorrectionsValidatorResponse")
FTMutableCorrectionsValidatorResponse = _Class("FTMutableCorrectionsValidatorResponse")
FTCorrectionsAlignment = _Class("FTCorrectionsAlignment")
FTMutableCorrectionsAlignment = _Class("FTMutableCorrectionsAlignment")
FTCorrectionsValidatorRequest = _Class("FTCorrectionsValidatorRequest")
FTMutableCorrectionsValidatorRequest = _Class("FTMutableCorrectionsValidatorRequest")
FTServerEndpointFeatures = _Class("FTServerEndpointFeatures")
FTMutableServerEndpointFeatures = _Class("FTMutableServerEndpointFeatures")
FTKeywordFinderResponse = _Class("FTKeywordFinderResponse")
FTMutableKeywordFinderResponse = _Class("FTMutableKeywordFinderResponse")
FTKeywordFinderRequest = _Class("FTKeywordFinderRequest")
FTMutableKeywordFinderRequest = _Class("FTMutableKeywordFinderRequest")
FTKeyword = _Class("FTKeyword")
FTMutableKeyword = _Class("FTMutableKeyword")
FTAStarFuzzyMatchingResponse = _Class("FTAStarFuzzyMatchingResponse")
FTMutableAStarFuzzyMatchingResponse = _Class("FTMutableAStarFuzzyMatchingResponse")
FTAStarFuzzyMatchingRequest = _Class("FTAStarFuzzyMatchingRequest")
FTMutableAStarFuzzyMatchingRequest = _Class("FTMutableAStarFuzzyMatchingRequest")
FTAStarFuzzyMatchingResult = _Class("FTAStarFuzzyMatchingResult")
FTMutableAStarFuzzyMatchingResult = _Class("FTMutableAStarFuzzyMatchingResult")
FTAStarFuzzyMatchingConfig = _Class("FTAStarFuzzyMatchingConfig")
FTMutableAStarFuzzyMatchingConfig = _Class("FTMutableAStarFuzzyMatchingConfig")
FTLmScorerResponse = _Class("FTLmScorerResponse")
FTMutableLmScorerResponse = _Class("FTMutableLmScorerResponse")
FTLmScorerRequest = _Class("FTLmScorerRequest")
FTMutableLmScorerRequest = _Class("FTMutableLmScorerRequest")
FTLmScorerToken = _Class("FTLmScorerToken")
FTMutableLmScorerToken = _Class("FTMutableLmScorerToken")
FTErrorBlamerResponse = _Class("FTErrorBlamerResponse")
FTMutableErrorBlamerResponse = _Class("FTMutableErrorBlamerResponse")
FTErrorBlamerRequest = _Class("FTErrorBlamerRequest")
FTMutableErrorBlamerRequest = _Class("FTMutableErrorBlamerRequest")
FTCheckForSpeechResponse = _Class("FTCheckForSpeechResponse")
FTMutableCheckForSpeechResponse = _Class("FTMutableCheckForSpeechResponse")
FTCheckForSpeechRequest = _Class("FTCheckForSpeechRequest")
FTMutableCheckForSpeechRequest = _Class("FTMutableCheckForSpeechRequest")
FTRecognitionCandidate = _Class("FTRecognitionCandidate")
FTMutableRecognitionCandidate = _Class("FTMutableRecognitionCandidate")
FTLatnnMitigatorResult = _Class("FTLatnnMitigatorResult")
FTMutableLatnnMitigatorResult = _Class("FTMutableLatnnMitigatorResult")
FTResetServerEndpointer = _Class("FTResetServerEndpointer")
FTMutableResetServerEndpointer = _Class("FTMutableResetServerEndpointer")
FTRecognitionProgress = _Class("FTRecognitionProgress")
FTMutableRecognitionProgress = _Class("FTMutableRecognitionProgress")
FTSetRequestOrigin = _Class("FTSetRequestOrigin")
FTMutableSetRequestOrigin = _Class("FTMutableSetRequestOrigin")
FTEndPointCandidate = _Class("FTEndPointCandidate")
FTMutableEndPointCandidate = _Class("FTMutableEndPointCandidate")
FTEndPointLikelihood = _Class("FTEndPointLikelihood")
FTMutableEndPointLikelihood = _Class("FTMutableEndPointLikelihood")
FTTranslationResponse_TranslationPhrase = _Class(
    "FTTranslationResponse_TranslationPhrase"
)
FTMutableTranslationResponse_TranslationPhrase = _Class(
    "FTMutableTranslationResponse_TranslationPhrase"
)
FTTranslationResponse_TranslationToken = _Class(
    "FTTranslationResponse_TranslationToken"
)
FTMutableTranslationResponse_TranslationToken = _Class(
    "FTMutableTranslationResponse_TranslationToken"
)
FTTranslationResponse = _Class("FTTranslationResponse")
FTMutableTranslationResponse = _Class("FTMutableTranslationResponse")
FTTranslationRequest = _Class("FTTranslationRequest")
FTMutableTranslationRequest = _Class("FTMutableTranslationRequest")
FTWebTranslationInfo = _Class("FTWebTranslationInfo")
FTMutableWebTranslationInfo = _Class("FTMutableWebTranslationInfo")
FTSiriPayloadTranslationInfo = _Class("FTSiriPayloadTranslationInfo")
FTMutableSiriPayloadTranslationInfo = _Class("FTMutableSiriPayloadTranslationInfo")
FTSiriTranslationInfo = _Class("FTSiriTranslationInfo")
FTMutableSiriTranslationInfo = _Class("FTMutableSiriTranslationInfo")
FTSpeechTranslationInfo = _Class("FTSpeechTranslationInfo")
FTMutableSpeechTranslationInfo = _Class("FTMutableSpeechTranslationInfo")
FTRepeatedSpan = _Class("FTRepeatedSpan")
FTMutableRepeatedSpan = _Class("FTMutableRepeatedSpan")
FTSpan = _Class("FTSpan")
FTMutableSpan = _Class("FTMutableSpan")
FTAlignment = _Class("FTAlignment")
FTMutableAlignment = _Class("FTMutableAlignment")
FTGraphemeToPhonemeResponse = _Class("FTGraphemeToPhonemeResponse")
FTMutableGraphemeToPhonemeResponse = _Class("FTMutableGraphemeToPhonemeResponse")
FTGraphemeToPhonemeRequest = _Class("FTGraphemeToPhonemeRequest")
FTMutableGraphemeToPhonemeRequest = _Class("FTMutableGraphemeToPhonemeRequest")
FTTokenProns_SanitizedSequence = _Class("FTTokenProns_SanitizedSequence")
FTMutableTokenProns_SanitizedSequence = _Class("FTMutableTokenProns_SanitizedSequence")
FTTokenProns = _Class("FTTokenProns")
FTMutableTokenProns = _Class("FTMutableTokenProns")
FTSanitizedPronToken = _Class("FTSanitizedPronToken")
FTMutableSanitizedPronToken = _Class("FTMutableSanitizedPronToken")
FTPronChoice = _Class("FTPronChoice")
FTMutablePronChoice = _Class("FTMutablePronChoice")
FTTextNormalizationResponse = _Class("FTTextNormalizationResponse")
FTMutableTextNormalizationResponse = _Class("FTMutableTextNormalizationResponse")
FTNormalizedToken = _Class("FTNormalizedToken")
FTMutableNormalizedToken = _Class("FTMutableNormalizedToken")
FTNormalizedTokenVariant = _Class("FTNormalizedTokenVariant")
FTMutableNormalizedTokenVariant = _Class("FTMutableNormalizedTokenVariant")
FTTextNormalizationRequest = _Class("FTTextNormalizationRequest")
FTMutableTextNormalizationRequest = _Class("FTMutableTextNormalizationRequest")
FTPostItnHammerResponse = _Class("FTPostItnHammerResponse")
FTMutablePostItnHammerResponse = _Class("FTMutablePostItnHammerResponse")
FTPostItnHammerRequest = _Class("FTPostItnHammerRequest")
FTMutablePostItnHammerRequest = _Class("FTMutablePostItnHammerRequest")
FTItnResponse = _Class("FTItnResponse")
FTMutableItnResponse = _Class("FTMutableItnResponse")
FTItnRequest = _Class("FTItnRequest")
FTMutableItnRequest = _Class("FTMutableItnRequest")
FTBatchRecoverFinalResponse = _Class("FTBatchRecoverFinalResponse")
FTMutableBatchRecoverFinalResponse = _Class("FTMutableBatchRecoverFinalResponse")
FTStartBatchRecoverRequest = _Class("FTStartBatchRecoverRequest")
FTMutableStartBatchRecoverRequest = _Class("FTMutableStartBatchRecoverRequest")
FTRecoverPronsResponse = _Class("FTRecoverPronsResponse")
FTMutableRecoverPronsResponse = _Class("FTMutableRecoverPronsResponse")
FTRecoverPronsRequest = _Class("FTRecoverPronsRequest")
FTMutableRecoverPronsRequest = _Class("FTMutableRecoverPronsRequest")
FTPronGuessResponse = _Class("FTPronGuessResponse")
FTMutablePronGuessResponse = _Class("FTMutablePronGuessResponse")
FTVocToken = _Class("FTVocToken")
FTMutableVocToken = _Class("FTMutableVocToken")
FTPronunciation = _Class("FTPronunciation")
FTMutablePronunciation = _Class("FTMutablePronunciation")
FTCancelRequest = _Class("FTCancelRequest")
FTMutableCancelRequest = _Class("FTMutableCancelRequest")
FTStartPronGuessRequest = _Class("FTStartPronGuessRequest")
FTMutableStartPronGuessRequest = _Class("FTMutableStartPronGuessRequest")
FTCreateLanguageProfileResponse = _Class("FTCreateLanguageProfileResponse")
FTMutableCreateLanguageProfileResponse = _Class(
    "FTMutableCreateLanguageProfileResponse"
)
FTCreateLanguageProfileRequest = _Class("FTCreateLanguageProfileRequest")
FTMutableCreateLanguageProfileRequest = _Class("FTMutableCreateLanguageProfileRequest")
FTCategoryData = _Class("FTCategoryData")
FTMutableCategoryData = _Class("FTMutableCategoryData")
FTUserDataEntity = _Class("FTUserDataEntity")
FTMutableUserDataEntity = _Class("FTMutableUserDataEntity")
FTWord = _Class("FTWord")
FTMutableWord = _Class("FTMutableWord")
FTUpdatedAcousticProfile = _Class("FTUpdatedAcousticProfile")
FTMutableUpdatedAcousticProfile = _Class("FTMutableUpdatedAcousticProfile")
FTFinishAudio_ServerFeatureLatencyDistributionEntry = _Class(
    "FTFinishAudio_ServerFeatureLatencyDistributionEntry"
)
FTMutableFinishAudio_ServerFeatureLatencyDistributionEntry = _Class(
    "FTMutableFinishAudio_ServerFeatureLatencyDistributionEntry"
)
FTFinishAudio = _Class("FTFinishAudio")
FTMutableFinishAudio = _Class("FTMutableFinishAudio")
FTAudioPacket = _Class("FTAudioPacket")
FTMutableAudioPacket = _Class("FTMutableAudioPacket")
FTSetEndpointerState = _Class("FTSetEndpointerState")
FTMutableSetEndpointerState = _Class("FTMutableSetEndpointerState")
FTSetSpeechProfile = _Class("FTSetSpeechProfile")
FTMutableSetSpeechProfile = _Class("FTMutableSetSpeechProfile")
FTSetSpeechContext = _Class("FTSetSpeechContext")
FTMutableSetSpeechContext = _Class("FTMutableSetSpeechContext")
FTContextWithPronHints = _Class("FTContextWithPronHints")
FTMutableContextWithPronHints = _Class("FTMutableContextWithPronHints")
FTUpdateAudioInfo = _Class("FTUpdateAudioInfo")
FTMutableUpdateAudioInfo = _Class("FTMutableUpdateAudioInfo")
FTMultiUserStartSpeechRequest = _Class("FTMultiUserStartSpeechRequest")
FTMutableMultiUserStartSpeechRequest = _Class("FTMutableMultiUserStartSpeechRequest")
FTUserParameters = _Class("FTUserParameters")
FTMutableUserParameters = _Class("FTMutableUserParameters")
FTStartSpeechRequest = _Class("FTStartSpeechRequest")
FTMutableStartSpeechRequest = _Class("FTMutableStartSpeechRequest")
FTPartialSpeechRecognitionResponse = _Class("FTPartialSpeechRecognitionResponse")
FTMutablePartialSpeechRecognitionResponse = _Class(
    "FTMutablePartialSpeechRecognitionResponse"
)
FTFinalSpeechRecognitionResponse = _Class("FTFinalSpeechRecognitionResponse")
FTMutableFinalSpeechRecognitionResponse = _Class(
    "FTMutableFinalSpeechRecognitionResponse"
)
FTAudioAnalytics_AcousticFeaturesEntry = _Class(
    "FTAudioAnalytics_AcousticFeaturesEntry"
)
FTMutableAudioAnalytics_AcousticFeaturesEntry = _Class(
    "FTMutableAudioAnalytics_AcousticFeaturesEntry"
)
FTAudioAnalytics_SpeechRecognitionFeaturesEntry = _Class(
    "FTAudioAnalytics_SpeechRecognitionFeaturesEntry"
)
FTMutableAudioAnalytics_SpeechRecognitionFeaturesEntry = _Class(
    "FTMutableAudioAnalytics_SpeechRecognitionFeaturesEntry"
)
FTAudioAnalytics = _Class("FTAudioAnalytics")
FTMutableAudioAnalytics = _Class("FTMutableAudioAnalytics")
FTAcousticFeature = _Class("FTAcousticFeature")
FTMutableAcousticFeature = _Class("FTMutableAcousticFeature")
FTItnAlignment = _Class("FTItnAlignment")
FTMutableItnAlignment = _Class("FTMutableItnAlignment")
FTRequestStatsResponse_DoubleStat = _Class("FTRequestStatsResponse_DoubleStat")
FTMutableRequestStatsResponse_DoubleStat = _Class(
    "FTMutableRequestStatsResponse_DoubleStat"
)
FTRequestStatsResponse_Int32Stat = _Class("FTRequestStatsResponse_Int32Stat")
FTMutableRequestStatsResponse_Int32Stat = _Class(
    "FTMutableRequestStatsResponse_Int32Stat"
)
FTRequestStatsResponse_BoolStat = _Class("FTRequestStatsResponse_BoolStat")
FTMutableRequestStatsResponse_BoolStat = _Class(
    "FTMutableRequestStatsResponse_BoolStat"
)
FTRequestStatsResponse = _Class("FTRequestStatsResponse")
FTMutableRequestStatsResponse = _Class("FTMutableRequestStatsResponse")
FTRecognitionResult = _Class("FTRecognitionResult")
FTMutableRecognitionResult = _Class("FTMutableRecognitionResult")
FTChoiceAlignment = _Class("FTChoiceAlignment")
FTMutableChoiceAlignment = _Class("FTMutableChoiceAlignment")
FTRepeatedItnAlignment = _Class("FTRepeatedItnAlignment")
FTMutableRepeatedItnAlignment = _Class("FTMutableRepeatedItnAlignment")
FTRecognitionChoice = _Class("FTRecognitionChoice")
FTMutableRecognitionChoice = _Class("FTMutableRecognitionChoice")
FTSetAlternateRecognitionSausage = _Class("FTSetAlternateRecognitionSausage")
FTMutableSetAlternateRecognitionSausage = _Class(
    "FTMutableSetAlternateRecognitionSausage"
)
FTRecognitionSausage = _Class("FTRecognitionSausage")
FTMutableRecognitionSausage = _Class("FTMutableRecognitionSausage")
FTRecognitionPhraseTokensAlternatives = _Class("FTRecognitionPhraseTokensAlternatives")
FTMutableRecognitionPhraseTokensAlternatives = _Class(
    "FTMutableRecognitionPhraseTokensAlternatives"
)
FTRecognitionPhraseTokens = _Class("FTRecognitionPhraseTokens")
FTMutableRecognitionPhraseTokens = _Class("FTMutableRecognitionPhraseTokens")
FTRecognitionToken = _Class("FTRecognitionToken")
FTMutableRecognitionToken = _Class("FTMutableRecognitionToken")
FTUserAcousticProfile = _Class("FTUserAcousticProfile")
FTMutableUserAcousticProfile = _Class("FTMutableUserAcousticProfile")
FTUserLanguageProfile = _Class("FTUserLanguageProfile")
FTMutableUserLanguageProfile = _Class("FTMutableUserLanguageProfile")
_LTOfflineAssetManager = _Class("_LTOfflineAssetManager")
_LTTextToSpeechCache = _Class("_LTTextToSpeechCache")
_LTTokenizer = _Class("_LTTokenizer")
_LTTranslationStatistics = _Class("_LTTranslationStatistics")
_LTSpeechTranslationAssetInfo = _Class("_LTSpeechTranslationAssetInfo")
_LTTranslationRequest = _Class("_LTTranslationRequest")
_LTParagraphTranslationRequest = _Class("_LTParagraphTranslationRequest")
_LTCombinedRouteParagraphTranslationRequest = _Class(
    "_LTCombinedRouteParagraphTranslationRequest"
)
_LTTextToSpeechTranslationRequest = _Class("_LTTextToSpeechTranslationRequest")
_LTSpeechTranslationRequest = _Class("_LTSpeechTranslationRequest")
_LTBatchTextTranslationRequest = _Class("_LTBatchTextTranslationRequest")
_LTTextTranslationRequest = _Class("_LTTextTranslationRequest")
_LTSpeakRequest = _Class("_LTSpeakRequest")
_LTHybridEndpointerAssetInfo = _Class("_LTHybridEndpointerAssetInfo")
_LTTaskContext = _Class("_LTTaskContext")
_LTServerSpeakSession = _Class("_LTServerSpeakSession")
_LTAlignment = _Class("_LTAlignment")
_LTLanguageManager = _Class("_LTLanguageManager")
_LTLanguageAssetStatus = _Class("_LTLanguageAssetStatus")
_LTHybridEndpointer = _Class("_LTHybridEndpointer")
_LTServerEndpointerFeatures = _Class("_LTServerEndpointerFeatures")
_LTAudioData = _Class("_LTAudioData")
_LTOnlineTranslationEngine = _Class("_LTOnlineTranslationEngine")
_LTBatchTranslationResponseHandler = _Class("_LTBatchTranslationResponseHandler")
_FTParagraphBatchInfo = _Class("_FTParagraphBatchInfo")
_LTLanguageInstallationStatus = _Class("_LTLanguageInstallationStatus")
_LTLanguageDetector = _Class("_LTLanguageDetector")
_LTLanguageDetectionResult = _Class("_LTLanguageDetectionResult")
_LTTranslationContext = _Class("_LTTranslationContext")
_LTDaemon = _Class("_LTDaemon")
_LTLanguageDetectorFeatureCombinationModel = _Class(
    "_LTLanguageDetectorFeatureCombinationModel"
)
_LTTextLanguageDetectionResult = _Class("_LTTextLanguageDetectionResult")
_LTPowerLogger = _Class("_LTPowerLogger")
_LTSpeechTranslationResultsBuffer = _Class("_LTSpeechTranslationResultsBuffer")
FTSlsService = _Class("FTSlsService")
FTAfmService = _Class("FTAfmService")
FTNlService = _Class("FTNlService")
FTTtsService = _Class("FTTtsService")
FTMtService = _Class("FTMtService")
FTNapgService = _Class("FTNapgService")
FTLmtService = _Class("FTLmtService")
FTBlazarService = _Class("FTBlazarService")
FTAsrService = _Class("FTAsrService")
FTApgService = _Class("FTApgService")
_LTTranslateSettingsController = _Class("_LTTranslateSettingsController")
