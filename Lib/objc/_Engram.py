'''
Classes from the 'Engram' framework.
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

    
ENCypher_AES128 = _Class('ENCypher_AES128')
ENCypher = _Class('ENCypher')
ENParticipantDevice = _Class('ENParticipantDevice')
ENParticipant = _Class('ENParticipant')
ENAsyncReducerState = _Class('ENAsyncReducerState')
ENAsyncReducer = _Class('ENAsyncReducer')
_ENGroupInfo = _Class('_ENGroupInfo')
ENGroup = _Class('ENGroup')
ENLog = _Class('ENLog')
ENAccountIdentity = _Class('ENAccountIdentity')
ENGroupContext = _Class('ENGroupContext')
ENGroupContextNotifyingObserver = _Class('ENGroupContextNotifyingObserver')
ENGroupContextInMemoryCache = _Class('ENGroupContextInMemoryCache')
ENStableGroupID = _Class('ENStableGroupID')
ENGroupID = _Class('ENGroupID')
ENPair = _Class('ENPair')
ENKeyClassRegister = _Class('ENKeyClassRegister')
ENGroupContextCoreDataCache = _Class('ENGroupContextCoreDataCache')
ENKeyedArchiverFromDataTransformer = _Class('ENKeyedArchiverFromDataTransformer')
ENCDGroup = _Class('ENCDGroup')
