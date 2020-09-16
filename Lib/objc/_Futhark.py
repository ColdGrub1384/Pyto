'''
Classes from the 'Futhark' framework.
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

    
FKTextDetector = _Class('FKTextDetector')
FKTextCandidate = _Class('FKTextCandidate')
FKTextFeature = _Class('FKTextFeature')
