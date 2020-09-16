'''
Classes from the 'EmailAddressing' framework.
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

    
_EAEmailAddress = _Class('_EAEmailAddress')
EAEmailAddressParser = _Class('EAEmailAddressParser')
EAEmailAddressLists = _Class('EAEmailAddressLists')
EAEmailAddressGenerator = _Class('EAEmailAddressGenerator')
_EAEmailAddressSetEnumerator = _Class('_EAEmailAddressSetEnumerator')
EAEmailAddressSet = _Class('EAEmailAddressSet')
