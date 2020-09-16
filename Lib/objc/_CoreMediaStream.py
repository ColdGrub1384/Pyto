'''
Classes from the 'CoreMediaStream' framework.
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

    
MSVideoDerivativeSpecification = _Class('MSVideoDerivativeSpecification')
MSImageScalingSpecification = _Class('MSImageScalingSpecification')
MSASGroupedQueue = _Class('MSASGroupedQueue')
MSASServerSideModelGroupedCommandQueue = _Class('MSASServerSideModelGroupedCommandQueue')
MSASEnqueuedCommand = _Class('MSASEnqueuedCommand')
MSASProtocol = _Class('MSASProtocol')
MSASPConnectionGate = _Class('MSASPConnectionGate')
MSASPendingChanges = _Class('MSASPendingChanges')
MSASCommentCheckOperation = _Class('MSASCommentCheckOperation')
MSASComment = _Class('MSASComment')
MSASSharingRelationship = _Class('MSASSharingRelationship')
MSASInvitation = _Class('MSASInvitation')
MSProtocolUtilities = _Class('MSProtocolUtilities')
MSASAssetTransferer = _Class('MSASAssetTransferer')
MSASAssetDownloader = _Class('MSASAssetDownloader')
MSASAssetUploader = _Class('MSASAssetUploader')
MMCSEngine = _Class('MMCSEngine')
MMCSRequestorContext = _Class('MMCSRequestorContext')
MSFileUtilities = _Class('MSFileUtilities')
MSASModelBase = _Class('MSASModelBase')
MSPerformanceLogger = _Class('MSPerformanceLogger')
MSASServerSideModel = _Class('MSASServerSideModel')
MSASDaemonModel = _Class('MSASDaemonModel')
MSASPersonModel = _Class('MSASPersonModel')
MSASPersonModelItem = _Class('MSASPersonModelItem')
MSASStateMachine = _Class('MSASStateMachine')
MSASAssetInfoToReauthForDownload = _Class('MSASAssetInfoToReauthForDownload')
MSASCommentChange = _Class('MSASCommentChange')
MSASAssetCollectionChange = _Class('MSASAssetCollectionChange')
MSASAlbumChange = _Class('MSASAlbumChange')
MSASAssetCollection = _Class('MSASAssetCollection')
MSASAlbum = _Class('MSASAlbum')
MSBackoffManager = _Class('MSBackoffManager')
MSObjectWrapper = _Class('MSObjectWrapper')
MSObjectQueue = _Class('MSObjectQueue')
MSResetServer = _Class('MSResetServer')
MSASPersonInfoManager = _Class('MSASPersonInfoManager')
MSServerSideConfigManager = _Class('MSServerSideConfigManager')
MSServerSideConfigProtocol = _Class('MSServerSideConfigProtocol')
MSSubscribedStream = _Class('MSSubscribedStream')
MSMMCSProtocol = _Class('MSMMCSProtocol')
MSSubscribeMMCSProtocol = _Class('MSSubscribeMMCSProtocol')
MSPublishMMCSProtocol = _Class('MSPublishMMCSProtocol')
MSStreamsProtocol = _Class('MSStreamsProtocol')
MSDeleteStreamsProtocol = _Class('MSDeleteStreamsProtocol')
MSReauthorizationProtocol = _Class('MSReauthorizationProtocol')
MSResetServerProtocol = _Class('MSResetServerProtocol')
MSSubscribeStreamsProtocol = _Class('MSSubscribeStreamsProtocol')
MSPublishStreamsProtocol = _Class('MSPublishStreamsProtocol')
MSTimerGate = _Class('MSTimerGate')
MSAssetCollection = _Class('MSAssetCollection')
MSAsset = _Class('MSAsset')
MSCupidStateMachine = _Class('MSCupidStateMachine')
MSDeleter = _Class('MSDeleter')
MSSubscriber = _Class('MSSubscriber')
MSPublisher = _Class('MSPublisher')
MSDaemon = _Class('MSDaemon')
MSAlbumSharingDaemon = _Class('MSAlbumSharingDaemon')
MSMediaStreamDaemon = _Class('MSMediaStreamDaemon')
MSASPhoneInvitations = _Class('MSASPhoneInvitations')
MPSStateResponse = _Class('MPSStateResponse')
MPSStateRequest = _Class('MPSStateRequest')
MSASModelEnumerator = _Class('MSASModelEnumerator')
