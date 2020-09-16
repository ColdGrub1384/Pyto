'''
Classes from the 'WatchConnectivity' framework.
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

    
WCQueuedMessage = _Class('WCQueuedMessage')
WCFileStorage = _Class('WCFileStorage')
WCSessionFile = _Class('WCSessionFile')
WCPrivateXPCManager = _Class('WCPrivateXPCManager')
WCUserInfo = _Class('WCUserInfo')
WCContentIndex = _Class('WCContentIndex')
WCComplicationManager = _Class('WCComplicationManager')
WCMessageRecord = _Class('WCMessageRecord')
WCDataMessageRecord = _Class('WCDataMessageRecord')
WCDictionaryMessageRecord = _Class('WCDictionaryMessageRecord')
WCDProtoUserInfoTransfer = _Class('WCDProtoUserInfoTransfer')
WCSessionState = _Class('WCSessionState')
WCMessage = _Class('WCMessage')
WCMessageRequest = _Class('WCMessageRequest')
WCMessageResponse = _Class('WCMessageResponse')
WCSessionUserInfoTransfer = _Class('WCSessionUserInfoTransfer')
WCSessionFileTransfer = _Class('WCSessionFileTransfer')
WCXPCManager = _Class('WCXPCManager')
WCActiveDeviceSwitchTask = _Class('WCActiveDeviceSwitchTask')
WCQueueManager = _Class('WCQueueManager')
WCSession = _Class('WCSession')
