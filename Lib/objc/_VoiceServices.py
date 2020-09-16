'''
Classes from the 'VoiceServices' framework.
'''

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

    
VSGenericBlockHolder = _Class('VSGenericBlockHolder')
VSGenericUpdateEndpoint = _Class('VSGenericUpdateEndpoint')
VSSpeechConnectionDelegateWrapper = _Class('VSSpeechConnectionDelegateWrapper')
VSSpeechConnection = _Class('VSSpeechConnection')
VSKeepAlive = _Class('VSKeepAlive')
VSPreferencesInterface = _Class('VSPreferencesInterface')
VSSpeechSynthesizer = _Class('VSSpeechSynthesizer')
VSDurationRequest = _Class('VSDurationRequest')
VSAudioPreviewDelegate = _Class('VSAudioPreviewDelegate')
VSMappedData = _Class('VSMappedData')
VSSpeechRequest = _Class('VSSpeechRequest')
VSFormatArgument = _Class('VSFormatArgument')
VSTextPreProcessorRule = _Class('VSTextPreProcessorRule')
VSTextPreProcessor = _Class('VSTextPreProcessor')
VSRecognitionResultHandlingRequest = _Class('VSRecognitionResultHandlingRequest')
VSRecognitionResultHandlingThread = _Class('VSRecognitionResultHandlingThread')
VSPresynthesizedAudioRequest = _Class('VSPresynthesizedAudioRequest')
VSCacheUpdateRequest = _Class('VSCacheUpdateRequest')
VSCacheUpdateListener = _Class('VSCacheUpdateListener')
VSNeuralTTSUtils = _Class('VSNeuralTTSUtils')
VSSpeechWordTimingInfo = _Class('VSSpeechWordTimingInfo')
VSAnalytics = _Class('VSAnalytics')
VSSpeechCharacterSet = _Class('VSSpeechCharacterSet')
VSLocalizedString = _Class('VSLocalizedString')
VSRecognitionAction = _Class('VSRecognitionAction')
VSRecognitionSpeakAction = _Class('VSRecognitionSpeakAction')
VSRecognitionURLAction = _Class('VSRecognitionURLAction')
VSRecognitionRecognizeAction = _Class('VSRecognitionRecognizeAction')
VSRecognitionConfirmAction = _Class('VSRecognitionConfirmAction')
VSRecognitionDisambiguateAction = _Class('VSRecognitionDisambiguateAction')
VSOpusDecoder = _Class('VSOpusDecoder')
VSOpusEncoder = _Class('VSOpusEncoder')
VSRecognitionSession = _Class('VSRecognitionSession')
VSRecognitionResult = _Class('VSRecognitionResult')
VSWordTimingService = _Class('VSWordTimingService')
VSUtilities = _Class('VSUtilities')
VSDownloadMetrics = _Class('VSDownloadMetrics')
VSSpeechSynthesizerPreference = _Class('VSSpeechSynthesizerPreference')
VSSpeechInternalSettings = _Class('VSSpeechInternalSettings')
VSMobileAssetsManager = _Class('VSMobileAssetsManager')
VSVoiceAssetSelection = _Class('VSVoiceAssetSelection')
VSInstrumentMetrics = _Class('VSInstrumentMetrics')
VSAssetBase = _Class('VSAssetBase')
VSVoiceAsset = _Class('VSVoiceAsset')
VSVoiceResourceAsset = _Class('VSVoiceResourceAsset')
