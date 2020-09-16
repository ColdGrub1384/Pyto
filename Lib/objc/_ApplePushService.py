'''
Classes from the 'ApplePushService' framework.
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

    
APSMultiUserFS = _Class('APSMultiUserFS')
APSDNSRequest = _Class('APSDNSRequest')
APSDNSResponse = _Class('APSDNSResponse')
APSPair = _Class('APSPair')
APSMessage = _Class('APSMessage')
APSIncomingMessage = _Class('APSIncomingMessage')
APSOutgoingMessage = _Class('APSOutgoingMessage')
APSAccessCheck = _Class('APSAccessCheck')
APSConnection = _Class('APSConnection')
APSLog = _Class('APSLog')
APSTaskClient = _Class('APSTaskClient')
APSMultiUserMode = _Class('APSMultiUserMode')
APSIncomingMessageCheckpointTrace = _Class('APSIncomingMessageCheckpointTrace')
APSOutgoingMessageCheckpointTrace = _Class('APSOutgoingMessageCheckpointTrace')
