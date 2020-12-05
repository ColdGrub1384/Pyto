"""
Classes from the 'CoreHaptics' framework.
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


AdvancedPatternPlayer = _Class("AdvancedPatternPlayer")
PatternPlayer = _Class("PatternPlayer")
CHHapticPattern = _Class("CHHapticPattern")
CHHapticParameterCurveControlPoint = _Class("CHHapticParameterCurveControlPoint")
CHHapticParameterCurve = _Class("CHHapticParameterCurve")
CHHapticDynamicParameter = _Class("CHHapticDynamicParameter")
CHHapticEventParameter = _Class("CHHapticEventParameter")
CHHapticEvent = _Class("CHHapticEvent")
HapticDictionaryReader = _Class("HapticDictionaryReader")
HapticCommandConverter = _Class("HapticCommandConverter")
HapticDictionaryWriter = _Class("HapticDictionaryWriter")
EventToDictionaryConverter = _Class("EventToDictionaryConverter")
CHMetricsManager = _Class("CHMetricsManager")
PlaybackAction = _Class("PlaybackAction")
CHMetricsKey = _Class("CHMetricsKey")
CHMetricsPlayerData = _Class("CHMetricsPlayerData")
HapticServerConfig = _Class("HapticServerConfig")
CHDefaultHapticDeviceCapability = _Class("CHDefaultHapticDeviceCapability")
CHHapticParameterAttributesImpl = _Class("CHHapticParameterAttributesImpl")
CHHapticEngine = _Class("CHHapticEngine")
