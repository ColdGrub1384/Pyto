"""
Classes from the 'ToneLibrary' framework.
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


TLAlertQueuePlayerController = _Class("TLAlertQueuePlayerController")
TLAlertController = _Class("TLAlertController")
TLAlert = _Class("TLAlert")
TLBacklight = _Class("TLBacklight")
TLToneImportResponse = _Class("TLToneImportResponse")
TLAlertActivationAssertion = _Class("TLAlertActivationAssertion")
TLSilentModeController = _Class("TLSilentModeController")
TLAlertSystemSoundContext = _Class("TLAlertSystemSoundContext")
TLContentProtectionStateObserver = _Class("TLContentProtectionStateObserver")
TLAttentionAwarenessObserver = _Class("TLAttentionAwarenessObserver")
TLCapabilitiesManager = _Class("TLCapabilitiesManager")
TLAttentionAwarenessEffectAudioTapContext = _Class(
    "TLAttentionAwarenessEffectAudioTapContext"
)
TLToneStoreDownload = _Class("TLToneStoreDownload")
TLAlertPlaybackCompletionContext = _Class("TLAlertPlaybackCompletionContext")
TLAlertSystemSoundController = _Class("TLAlertSystemSoundController")
TLAccessQueue = _Class("TLAccessQueue")
TLVibrationPattern = _Class("TLVibrationPattern")
TLAlertContext = _Class("TLAlertContext")
TLAttentionAwarenessEffectProcessor = _Class("TLAttentionAwarenessEffectProcessor")
TLAlertStoppingOptions = _Class("TLAlertStoppingOptions")
TLVibrationManager = _Class("TLVibrationManager")
TLToneStoreDownloadStoreServicesController = _Class(
    "TLToneStoreDownloadStoreServicesController"
)
TLAlertTone = _Class("TLAlertTone")
TLSystemSound = _Class("TLSystemSound")
TLITunesTone = _Class("TLITunesTone")
TLAlertConfiguration = _Class("TLAlertConfiguration")
TLVibrationPersistenceUtilities = _Class("TLVibrationPersistenceUtilities")
TLPreferencesUtilities = _Class("TLPreferencesUtilities")
TLAttentionAwarenessEffectCoordinator = _Class("TLAttentionAwarenessEffectCoordinator")
TLAlertPlaybackPolicy = _Class("TLAlertPlaybackPolicy")
TLSystemApplication = _Class("TLSystemApplication")
TLToneManager = _Class("TLToneManager")
