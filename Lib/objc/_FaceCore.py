'''
Classes from the 'FaceCore' framework.
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

    
AEVConversionUtils = _Class('AEVConversionUtils')
FCRExceptionUtils = _Class('FCRExceptionUtils')
FCRImageConversionUtils = _Class('FCRImageConversionUtils')
FCRLandmark = _Class('FCRLandmark')
FCRImage = _Class('FCRImage')
FCRFaceDetector = _Class('FCRFaceDetector')
FCRFace = _Class('FCRFace')
