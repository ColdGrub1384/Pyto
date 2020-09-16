'''
Classes from the 'ConstantClasses' framework.
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

    
_NSConstantDictionaryEnumerator = _Class('_NSConstantDictionaryEnumerator')
_NSConstantArrayEnumerator = _Class('_NSConstantArrayEnumerator')
_NSConstantData = _Class('_NSConstantData')
_NSConstantNumber = _Class('_NSConstantNumber')
_NSConstantNumberBool = _Class('_NSConstantNumberBool')
_NSConstantNumberFloat = _Class('_NSConstantNumberFloat')
_NSConstantNumberInt = _Class('_NSConstantNumberInt')
_NSConstantDate = _Class('_NSConstantDate')
_NSConstantDictionary = _Class('_NSConstantDictionary')
_NSConstantArray = _Class('_NSConstantArray')
