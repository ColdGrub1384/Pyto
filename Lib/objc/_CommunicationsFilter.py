'''
Classes from the 'CommunicationsFilter' framework.
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

    
CommunicationsFilterBlockListCache = _Class('CommunicationsFilterBlockListCache')
CommunicationFilterItemCache = _Class('CommunicationFilterItemCache')
CommunicationFilterItem = _Class('CommunicationFilterItem')
CommunicationsFilterBlockList = _Class('CommunicationsFilterBlockList')
