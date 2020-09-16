'''
Classes from the 'PersonaKit' framework.
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

    
PRLikenessChange = _Class('PRLikenessChange')
PRPersonaStore = _Class('PRPersonaStore')
PRPersonaServiceInterface = _Class('PRPersonaServiceInterface')
PRLikeness = _Class('PRLikeness')
PRManagedLikenessChange = _Class('PRManagedLikenessChange')
PRManagedScreenName = _Class('PRManagedScreenName')
PRManagedPropagationEvent = _Class('PRManagedPropagationEvent')
PRManagedLikeness = _Class('PRManagedLikeness')
