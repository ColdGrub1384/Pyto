'''
Classes from the 'FeatureFlagsSupport' framework.
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

    
FFConfiguration = _Class('FFConfiguration')
FFFeatureState = _Class('FFFeatureState')
FFFeatureAttribute = _Class('FFFeatureAttribute')
