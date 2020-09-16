'''
Classes from the 'Rapport' framework.
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

    
RPTextInputSession = _Class('RPTextInputSession')
RPStreamSession = _Class('RPStreamSession')
RPStreamServer = _Class('RPStreamServer')
RPConnectionMetrics = _Class('RPConnectionMetrics')
RPSiriSession = _Class('RPSiriSession')
RPSiriAudioSession = _Class('RPSiriAudioSession')
RPSession = _Class('RPSession')
RPServer = _Class('RPServer')
RPRemoteXPCListener = _Class('RPRemoteXPCListener')
RPRemoteXPCConnection = _Class('RPRemoteXPCConnection')
RPRemoteDisplaySession = _Class('RPRemoteDisplaySession')
RPRemoteDisplayServer = _Class('RPRemoteDisplayServer')
RPRemoteDisplayDiscovery = _Class('RPRemoteDisplayDiscovery')
RPPrivateDiscovery = _Class('RPPrivateDiscovery')
RPPrivateAdvertiser = _Class('RPPrivateAdvertiser')
RPPerson = _Class('RPPerson')
RPPeopleDiscovery = _Class('RPPeopleDiscovery')
RPMediaControlSession = _Class('RPMediaControlSession')
RPLegacySession = _Class('RPLegacySession')
RPLegacyService = _Class('RPLegacyService')
RPDeviceContext = _Class('RPDeviceContext')
RPLegacyDeviceDiscovery = _Class('RPLegacyDeviceDiscovery')
RPLegacySessionMessage = _Class('RPLegacySessionMessage')
RPIdentity = _Class('RPIdentity')
RPHIDTouchSession = _Class('RPHIDTouchSession')
RPHIDTouchEvent = _Class('RPHIDTouchEvent')
RPHIDSession = _Class('RPHIDSession')
RPFileTransferProgress = _Class('RPFileTransferProgress')
RPFileTransferItem = _Class('RPFileTransferItem')
RPFileTransferSession = _Class('RPFileTransferSession')
RPFileTransferLargeFileReceiveTask = _Class('RPFileTransferLargeFileReceiveTask')
RPFileTransferLargeFileSendTask = _Class('RPFileTransferLargeFileSendTask')
RPFileTransferSmallFilesTask = _Class('RPFileTransferSmallFilesTask')
RPHIDGCSession = _Class('RPHIDGCSession')
RPConnection = _Class('RPConnection')
RPSendEntry = _Class('RPSendEntry')
RPRequestEntry = _Class('RPRequestEntry')
RPDiscovery = _Class('RPDiscovery')
RPDevice = _Class('RPDevice')
RPEndpoint = _Class('RPEndpoint')
RPRemoteDisplayDevice = _Class('RPRemoteDisplayDevice')
RPCompanionLinkDevice = _Class('RPCompanionLinkDevice')
RPCompanionLinkAssertion = _Class('RPCompanionLinkAssertion')
RPCompanionLinkClient = _Class('RPCompanionLinkClient')
RPRequestRegistration = _Class('RPRequestRegistration')
RPEventRegistration = _Class('RPEventRegistration')
RPClient = _Class('RPClient')
RPAppSignInService = _Class('RPAppSignInService')
