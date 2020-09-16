'''
Classes from the 'ProtocolBuffer' framework.
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

    
PBSessionRequester = _Class('PBSessionRequester')
PBUnknownFields = _Class('PBUnknownFields')
_PBProperty = _Class('_PBProperty')
PBStreamReader = _Class('PBStreamReader')
PBMessageStreamWriter = _Class('PBMessageStreamWriter')
PBMessageStreamReader = _Class('PBMessageStreamReader')
PBStreamWriter = _Class('PBStreamWriter')
PBTextReader = _Class('PBTextReader')
PBTextWriter = _Class('PBTextWriter')
PBDataWriter = _Class('PBDataWriter')
PBDataReader = _Class('PBDataReader')
PBCodable = _Class('PBCodable')
PBRequest = _Class('PBRequest')
PBMutableData = _Class('PBMutableData')
