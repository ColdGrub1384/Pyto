'''
Classes from the 'PersonaUI' framework.
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

    
PRMonogramColor = _Class('PRMonogramColor')
PRLikenessCache = _Class('PRLikenessCache')
PRLikenessCacheContext = _Class('PRLikenessCacheContext')
_PRMonogramFontSpec = _Class('_PRMonogramFontSpec')
PRMonogram = _Class('PRMonogram')
PRLocalization = _Class('PRLocalization')
PRMonogramView = _Class('PRMonogramView')
PRLikenessView = _Class('PRLikenessView')
PRImageView = _Class('PRImageView')
