'''
Classes from the 'AppleNeuralEngine' framework.
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

    
_ANECloneHelper = _Class('_ANECloneHelper')
_ANEErrors = _Class('_ANEErrors')
_ANEClient = _Class('_ANEClient')
_ANEDeviceController = _Class('_ANEDeviceController')
_ANEIOSurfaceObject = _Class('_ANEIOSurfaceObject')
_ANEPerformanceStats = _Class('_ANEPerformanceStats')
_ANEDaemonConnection = _Class('_ANEDaemonConnection')
_ANEStrings = _Class('_ANEStrings')
_ANEQoSMapper = _Class('_ANEQoSMapper')
_ANELog = _Class('_ANELog')
_ANERequest = _Class('_ANERequest')
_ANEHashEncoding = _Class('_ANEHashEncoding')
_ANEModel = _Class('_ANEModel')
_ANEProgramForEvaluation = _Class('_ANEProgramForEvaluation')
_ANEDataReporter = _Class('_ANEDataReporter')
_ANEDeviceInfo = _Class('_ANEDeviceInfo')
