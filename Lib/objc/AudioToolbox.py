'''
Classes from the 'AudioToolbox' framework.
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

    
AVHapticParameterCurveValue = _Class('AVHapticParameterCurveValue')
AVHapticSequence = _Class('AVHapticSequence')
AVHapticPlayerChannel = _Class('AVHapticPlayerChannel')
AVHapticPlayerParameterCurve = _Class('AVHapticPlayerParameterCurve')
AVHapticPlayerParameterCurveControlPoint = _Class('AVHapticPlayerParameterCurveControlPoint')
AVHapticEvent = _Class('AVHapticEvent')
AVHapticServer = _Class('AVHapticServer')
AVHapticServerInstance = _Class('AVHapticServerInstance')
AVServerWrapper = _Class('AVServerWrapper')
BorealisServer = _Class('BorealisServer')
BorealisServerSpeakerStateHysteresisNotifier = _Class('BorealisServerSpeakerStateHysteresisNotifier')
AVHapticClient = _Class('AVHapticClient')
AVHapticSequenceEntry = _Class('AVHapticSequenceEntry')
AVHapticPlayer = _Class('AVHapticPlayer')
