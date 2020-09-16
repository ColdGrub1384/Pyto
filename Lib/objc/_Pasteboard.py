'''
Classes from the 'Pasteboard' framework.
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

    
PBDataTransferMonitor = _Class('PBDataTransferMonitor')
PBDataTransferRequest = _Class('PBDataTransferRequest')
PBCallbackSerialization = _Class('PBCallbackSerialization')
PBItemCollectionServicer = _Class('PBItemCollectionServicer')
PBObjectToObjectCoercion = _Class('PBObjectToObjectCoercion')
PBRepresentationToObjectCoercion = _Class('PBRepresentationToObjectCoercion')
PBObjectToRepresentationCoercion = _Class('PBObjectToRepresentationCoercion')
PBCoercionRegistry = _Class('PBCoercionRegistry')
PBItemDetection = _Class('PBItemDetection')
PBSecurityScopedURLWrapper = _Class('PBSecurityScopedURLWrapper')
PBItemCollection = _Class('PBItemCollection')
PBServerConnection = _Class('PBServerConnection')
PBItemRepresentation = _Class('PBItemRepresentation')
PBItem = _Class('PBItem')
PBKeyedUnarchiver = _Class('PBKeyedUnarchiver')
