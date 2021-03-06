"""
Classes from the 'AVFAudio' framework.
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


AVAudioEngine = _Class("AVAudioEngine")
AVVoiceTriggerClient = _Class("AVVoiceTriggerClient")
AVVoiceTriggerNotificationForwarder = _Class("AVVoiceTriggerNotificationForwarder")
AVAudioTime = _Class("AVAudioTime")
AVMusicTrack = _Class("AVMusicTrack")
AVAudioSequencer = _Class("AVAudioSequencer")
AVAudioMixingDestination = _Class("AVAudioMixingDestination")
AVAudioFile = _Class("AVAudioFile")
AVVCSessionManager = _Class("AVVCSessionManager")
AVAudioEnvironmentReverbParameters = _Class("AVAudioEnvironmentReverbParameters")
AVAudioEnvironmentDistanceAttenuationParameters = _Class(
    "AVAudioEnvironmentDistanceAttenuationParameters"
)
AVVCAudioBuffer = _Class("AVVCAudioBuffer")
AVSpeechSynthesisMarker = _Class("AVSpeechSynthesisMarker")
AVSpeechSynthesizer = _Class("AVSpeechSynthesizer")
AVSpeechUtterance = _Class("AVSpeechUtterance")
AVSpeechSynthesisVoice = _Class("AVSpeechSynthesisVoice")
AVAudioDeviceTestProcessingChain = _Class("AVAudioDeviceTestProcessingChain")
AVAudioDeviceTestSequence = _Class("AVAudioDeviceTestSequence")
AVAudioDeviceTestResult = _Class("AVAudioDeviceTestResult")
AVAudioFormat = _Class("AVAudioFormat")
AVAudioUnitEQFilterParameters = _Class("AVAudioUnitEQFilterParameters")
AVAudioBuffer = _Class("AVAudioBuffer")
AVAudioCompressedBuffer = _Class("AVAudioCompressedBuffer")
AVAudioPCMBuffer = _Class("AVAudioPCMBuffer")
AVMIDIPlayer = _Class("AVMIDIPlayer")
AVAudioClock = _Class("AVAudioClock")
AVVCMetricsManager = _Class("AVVCMetricsManager")
AVAudioConverter = _Class("AVAudioConverter")
AVAudioDeviceTest = _Class("AVAudioDeviceTest")
AVSpeechSynthesisProviderRequest = _Class("AVSpeechSynthesisProviderRequest")
AVSpeechSynthesisProviderVoice = _Class("AVSpeechSynthesisProviderVoice")
AVAudioChannelLayout = _Class("AVAudioChannelLayout")
AVAudioRecorder = _Class("AVAudioRecorder")
AVAudioPlayer = _Class("AVAudioPlayer")
AudioPlayerImpl = _Class("AudioPlayerImpl")
VoiceVerificationEndpointer = _Class("VoiceVerificationEndpointer")
AVAudioUnitComponentManager = _Class("AVAudioUnitComponentManager")
SpeexEndpointer = _Class("SpeexEndpointer")
AVAudioUnitComponent = _Class("AVAudioUnitComponent")
AVVCAlertInformation = _Class("AVVCAlertInformation")
AVVCStartRecordSettings = _Class("AVVCStartRecordSettings")
AVVCConfigureAlertBehaviorSettings = _Class("AVVCConfigureAlertBehaviorSettings")
AVVCPrepareRecordSettings = _Class("AVVCPrepareRecordSettings")
AVVCContextSettings = _Class("AVVCContextSettings")
AVVoiceController = _Class("AVVoiceController")
AVVCRecordDeviceInfo = _Class("AVVCRecordDeviceInfo")
AVVCRemoteInputHost = _Class("AVVCRemoteInputHost")
AVAudioConnectionPoint = _Class("AVAudioConnectionPoint")
AVAudioNode = _Class("AVAudioNode")
AVAudioPlayerNode = _Class("AVAudioPlayerNode")
AVAudioEnvironmentNode = _Class("AVAudioEnvironmentNode")
AVAudioSourceNode = _Class("AVAudioSourceNode")
AVAudioMixerNode = _Class("AVAudioMixerNode")
AVAudioSinkNode = _Class("AVAudioSinkNode")
AVAudioUnit = _Class("AVAudioUnit")
AVAudioUnitDSPGraph = _Class("AVAudioUnitDSPGraph")
AVAudioUnitSplitter = _Class("AVAudioUnitSplitter")
AVAudioUnitMIDIInstrument = _Class("AVAudioUnitMIDIInstrument")
AVAudioUnitSampler = _Class("AVAudioUnitSampler")
AVAudioUnitGenerator = _Class("AVAudioUnitGenerator")
AVAudioUnitEffect = _Class("AVAudioUnitEffect")
AVAudioUnitEQ = _Class("AVAudioUnitEQ")
AVAudioUnitDistortion = _Class("AVAudioUnitDistortion")
AVAudioUnitReverb = _Class("AVAudioUnitReverb")
AVAudioUnitDelay = _Class("AVAudioUnitDelay")
AVAudioUnitTimeEffect = _Class("AVAudioUnitTimeEffect")
AVAudioUnitTimePitch = _Class("AVAudioUnitTimePitch")
AVAudioUnitVarispeed = _Class("AVAudioUnitVarispeed")
AVAudioIONode = _Class("AVAudioIONode")
AVAudioInputNode = _Class("AVAudioInputNode")
AVAudioOutputNode = _Class("AVAudioOutputNode")
AVSpeechSynthesisProviderAudioUnit = _Class("AVSpeechSynthesisProviderAudioUnit")
