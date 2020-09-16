'''
Classes from the 'MetadataUtilities' framework.
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

    
MDPathFilterGenerator = _Class('MDPathFilterGenerator')
FilterElementDefinition = _Class('FilterElementDefinition')
_MDPlistBytes = _Class('_MDPlistBytes')
_MDMutablePlistBytes = _Class('_MDMutablePlistBytes')
MDPathFilter = _Class('MDPathFilter')
