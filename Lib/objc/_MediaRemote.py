"""
Classes from the 'MediaRemote' framework.
"""

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


MRAVRoutingDiscoverySessionWrapper = _Class("MRAVRoutingDiscoverySessionWrapper")
MRVirtualVoiceInputDeviceDescriptor = _Class("MRVirtualVoiceInputDeviceDescriptor")
MRMutableVirtualVoiceInputDeviceDescriptor = _Class(
    "MRMutableVirtualVoiceInputDeviceDescriptor"
)
MRProtocolMessageLogger = _Class("MRProtocolMessageLogger")
MRPasscodeCredentials = _Class("MRPasscodeCredentials")
MRApplicationActivity = _Class("MRApplicationActivity")
MRMutableApplicationActivity = _Class("MRMutableApplicationActivity")
MRAVLightweightReconnaissanceSession = _Class("MRAVLightweightReconnaissanceSession")
MRAVReconnaissanceSession = _Class("MRAVReconnaissanceSession")
MRTextEditingSession = _Class("MRTextEditingSession")
MRMutableTextEditingSession = _Class("MRMutableTextEditingSession")
MRTextEditingAttributes = _Class("MRTextEditingAttributes")
MRMutableTextEditingAttributes = _Class("MRMutableTextEditingAttributes")
MRVirtualTouchDeviceDescriptor = _Class("MRVirtualTouchDeviceDescriptor")
MRMutableVirtualTouchDeviceDescriptor = _Class("MRMutableVirtualTouchDeviceDescriptor")
MRLanguageOptionGroup = _Class("MRLanguageOptionGroup")
MRNowPlayingOriginClientManager = _Class("MRNowPlayingOriginClientManager")
MRPlaybackQueue = _Class("MRPlaybackQueue")
MREmulatedGameController = _Class("MREmulatedGameController")
MRNowPlayingPlayerClient = _Class("MRNowPlayingPlayerClient")
MRGameControllerDelayedEvent = _Class("MRGameControllerDelayedEvent")
MRGameControllerDelayedEvents = _Class("MRGameControllerDelayedEvents")
MRGameControllerDaemonProxy = _Class("MRGameControllerDaemonProxy")
MRVVIClient = _Class("MRVVIClient")
MRNowPlayingClient = _Class("MRNowPlayingClient")
MRNowPlayingOriginClient = _Class("MRNowPlayingOriginClient")
MRNowPlayingArtwork = _Class("MRNowPlayingArtwork")
MRNowPlayingArtworkImage = _Class("MRNowPlayingArtworkImage")
MRNowPlayingPlayerClientRequests = _Class("MRNowPlayingPlayerClientRequests")
MRPlayer = _Class("MRPlayer")
MRPlayerPathDictionaryKey = _Class("MRPlayerPathDictionaryKey")
MRPlaybackQueueClient = _Class("MRPlaybackQueueClient")
MRPlaybackQueueSubscriptionController = _Class("MRPlaybackQueueSubscriptionController")
MRColorComponents = _Class("MRColorComponents")
MRNowPlayingPlayerPathInvalidationHandler = _Class(
    "MRNowPlayingPlayerPathInvalidationHandler"
)
MRUpdateActiveSystemEndpointRequest = _Class("MRUpdateActiveSystemEndpointRequest")
MRUpdateActiveSystemEndpointResponse = _Class("MRUpdateActiveSystemEndpointResponse")
MRNowPlayingPlayerClientCallbacks = _Class("MRNowPlayingPlayerClientCallbacks")
MRSupportedProtocolMessages = _Class("MRSupportedProtocolMessages")
MRClient = _Class("MRClient")
MRTransactionDestination = _Class("MRTransactionDestination")
MRTransactionSource = _Class("MRTransactionSource")
MRTransactionPacketizer = _Class("MRTransactionPacketizer")
MRTransactionPacketAccumulator = _Class("MRTransactionPacketAccumulator")
MRTransactionPacket = _Class("MRTransactionPacket")
MRContentItem = _Class("MRContentItem")
MRCryptoPairingSessionBlockDelegate = _Class("MRCryptoPairingSessionBlockDelegate")
MRAVRoutingClientController = _Class("MRAVRoutingClientController")
MRAVRoutingDiscoverySessionConfiguration = _Class(
    "MRAVRoutingDiscoverySessionConfiguration"
)
MRCommandInfo = _Class("MRCommandInfo")
_MRTelevisionControllerBlockCallback = _Class("_MRTelevisionControllerBlockCallback")
MRNotificationServiceClient = _Class("MRNotificationServiceClient")
MRExternalDeviceController = _Class("MRExternalDeviceController")
MRTelevisionController = _Class("MRTelevisionController")
MRContentItemRequest = _Class("MRContentItemRequest")
MRPlaybackQueueRequest = _Class("MRPlaybackQueueRequest")
MRUserSettings = _Class("MRUserSettings")
MRNotification = _Class("MRNotification")
MRNotificationClient = _Class("MRNotificationClient")
MRPlaybackSessionRequest = _Class("MRPlaybackSessionRequest")
MRMediaRemoteServiceClient = _Class("MRMediaRemoteServiceClient")
MRAudioDataBlock = _Class("MRAudioDataBlock")
MRMutableAudioDataBlock = _Class("MRMutableAudioDataBlock")
MRXPCConnection = _Class("MRXPCConnection")
MRVirtualVoiceInputDevice = _Class("MRVirtualVoiceInputDevice")
MRCryptoPairingIdentity = _Class("MRCryptoPairingIdentity")
MRAVClusterController = _Class("MRAVClusterController")
MRNowPlayingClientRequests = _Class("MRNowPlayingClientRequests")
MRNowPlayingOriginClientRequests = _Class("MRNowPlayingOriginClientRequests")
MRExternalDeviceMessageMetricsEntry = _Class("MRExternalDeviceMessageMetricsEntry")
MRExternalDeviceMessageMetrics = _Class("MRExternalDeviceMessageMetrics")
MRAVRoutingDiscoverySession = _Class("MRAVRoutingDiscoverySession")
MRAVConcreteRoutingDiscoverySession = _Class("MRAVConcreteRoutingDiscoverySession")
MRAVConcreteRoutingDiscoverySession_APSync = _Class(
    "MRAVConcreteRoutingDiscoverySession_APSync"
)
MRIDSDiscoverySession = _Class("MRIDSDiscoverySession")
MRAVDistantRoutingDiscoverySession = _Class("MRAVDistantRoutingDiscoverySession")
MRAVEndpointObserver = _Class("MRAVEndpointObserver")
MROSTransaction = _Class("MROSTransaction")
MRRemoteControl = _Class("MRRemoteControl")
MRNowPlayingRequest = _Class("MRNowPlayingRequest")
MRWeakProxy = _Class("MRWeakProxy")
MRPlayerPath = _Class("MRPlayerPath")
MRAVOutputDeviceSourceInfo = _Class("MRAVOutputDeviceSourceInfo")
MRExternalDeviceTransport = _Class("MRExternalDeviceTransport")
MRAVOutputContextTransport = _Class("MRAVOutputContextTransport")
MRAVOutputDeviceTransport = _Class("MRAVOutputDeviceTransport")
MRIDSTransport = _Class("MRIDSTransport")
MRNetServiceTransport = _Class("MRNetServiceTransport")
MRAVXPCPipeTransport = _Class("MRAVXPCPipeTransport")
MRPlaybackSessionMigrateRequest = _Class("MRPlaybackSessionMigrateRequest")
MRExternalDeviceManager = _Class("MRExternalDeviceManager")
MRProtocolClientConnection = _Class("MRProtocolClientConnection")
MRIDSClientConnection = _Class("MRIDSClientConnection")
MRExternalClientConnection = _Class("MRExternalClientConnection")
MRExternalJSONClientConnection = _Class("MRExternalJSONClientConnection")
MRDeviceInfo = _Class("MRDeviceInfo")
MRAVOutputContextModification = _Class("MRAVOutputContextModification")
MRAVOutputContext = _Class("MRAVOutputContext")
MRNowPlayingState = _Class("MRNowPlayingState")
MROutputContextDataSource = _Class("MROutputContextDataSource")
MROutputContextController = _Class("MROutputContextController")
MRExternalOutputContextDataSource = _Class("MRExternalOutputContextDataSource")
MRProtobufSerialization = _Class("MRProtobufSerialization")
MRArtwork = _Class("MRArtwork")
MRIDSConnectivityManager = _Class("MRIDSConnectivityManager")
MROrigin = _Class("MROrigin")
MRMediaRemoteService = _Class("MRMediaRemoteService")
MRLanguageOption = _Class("MRLanguageOption")
MRExternalDevice = _Class("MRExternalDevice")
MRTransportExternalDevice = _Class("MRTransportExternalDevice")
MRJSONTransportExternalDevice = _Class("MRJSONTransportExternalDevice")
MRTelevisionDevice = _Class("MRTelevisionDevice")
MRDistantExternalDevice = _Class("MRDistantExternalDevice")
MRAVDistantExternalDeviceMetadata = _Class("MRAVDistantExternalDeviceMetadata")
MRAVMutableDistantExternalDeviceMetadata = _Class(
    "MRAVMutableDistantExternalDeviceMetadata"
)
MRAVOutputDevice = _Class("MRAVOutputDevice")
MRAVConcreteOutputDevice = _Class("MRAVConcreteOutputDevice")
MRAVClusterOutputDevice = _Class("MRAVClusterOutputDevice")
MRAVVirtualOutputDevice = _Class("MRAVVirtualOutputDevice")
MRAVDistantOutputDevice = _Class("MRAVDistantOutputDevice")
MRAVExternalOutputDevice = _Class("MRAVExternalOutputDevice")
MRContentItemMetadata = _Class("MRContentItemMetadata")
MRAudioBuffer = _Class("MRAudioBuffer")
MRAVEndpoint = _Class("MRAVEndpoint")
MRAVDistantEndpoint = _Class("MRAVDistantEndpoint")
MRAVLocalEndpoint = _Class("MRAVLocalEndpoint")
MRConcreteEndpoint = _Class("MRConcreteEndpoint")
MRAVConcreteEndpoint = _Class("MRAVConcreteEndpoint")
MRPendingMessageQueue = _Class("MRPendingMessageQueue")
MRMessageData = _Class("MRMessageData")
MRProtocolMessageQueue = _Class("MRProtocolMessageQueue")
MRMessageReplyIdentifier = _Class("MRMessageReplyIdentifier")
MRCryptoPairingSession = _Class("MRCryptoPairingSession")
MRExternalDevicePairingSession = _Class("MRExternalDevicePairingSession")
MRCoreUtilsPairingSession = _Class("MRCoreUtilsPairingSession")
MRCoreUtilsSystemPairingSession = _Class("MRCoreUtilsSystemPairingSession")
MRAVOutputDeviceDescription = _Class("MRAVOutputDeviceDescription")
MRProtocolMessage = _Class("MRProtocolMessage")
MRCryptoPairingMessage = _Class("MRCryptoPairingMessage")
MRTextInputMessage = _Class("MRTextInputMessage")
MRKeyboardMessage = _Class("MRKeyboardMessage")
MRGenericMessage = _Class("MRGenericMessage")
MRRemoteTextInputMessage = _Class("MRRemoteTextInputMessage")
MRPlaybackSessionMigrateEndMessage = _Class("MRPlaybackSessionMigrateEndMessage")
MRPlaybackSessionMigrateBeginMessage = _Class("MRPlaybackSessionMigrateBeginMessage")
MRPlaybackSessionMigrateResponseMessage = _Class(
    "MRPlaybackSessionMigrateResponseMessage"
)
MRPlaybackSessionMigrateRequestMessage = _Class(
    "MRPlaybackSessionMigrateRequestMessage"
)
MRPlaybackSessionResponseMessage = _Class("MRPlaybackSessionResponseMessage")
MRPlaybackSessionRequestMessage = _Class("MRPlaybackSessionRequestMessage")
MRSendLyricsEventMessage = _Class("MRSendLyricsEventMessage")
MRRegisterHIDDeviceMessage = _Class("MRRegisterHIDDeviceMessage")
MRSetArtworkMessage = _Class("MRSetArtworkMessage")
MRNotificationMessage = _Class("MRNotificationMessage")
MRSendCommandResultMessage = _Class("MRSendCommandResultMessage")
MRCompositeMessage = _Class("MRCompositeMessage")
MRPlaybackQueueRequestMessage = _Class("MRPlaybackQueueRequestMessage")
MRGetRemoteTextInputSessionMessage = _Class("MRGetRemoteTextInputSessionMessage")
MRSendButtonEventMessage = _Class("MRSendButtonEventMessage")
MRLegacySendHIDEventMessage = _Class("MRLegacySendHIDEventMessage")
MRSendPackedVirtualTouchEventMessage = _Class("MRSendPackedVirtualTouchEventMessage")
MRSendVirtualTouchEventMessage = _Class("MRSendVirtualTouchEventMessage")
MRPresentRouteAuthorizationStatusMessage = _Class(
    "MRPresentRouteAuthorizationStatusMessage"
)
MRPromptForRouteAuthorizationResponseMessage = _Class(
    "MRPromptForRouteAuthorizationResponseMessage"
)
MRPromptForRouteAuthorizationMessage = _Class("MRPromptForRouteAuthorizationMessage")
MRSendCommandMessage = _Class("MRSendCommandMessage")
MROriginClientPropertiesMessage = _Class("MROriginClientPropertiesMessage")
MRPlayerClientPropertiesMessage = _Class("MRPlayerClientPropertiesMessage")
MRVolumeControlCapabilitiesDidChangeMessage = _Class(
    "MRVolumeControlCapabilitiesDidChangeMessage"
)
MRLegacyVolumeControlCapabilitiesDidChangeMessage = _Class(
    "MRLegacyVolumeControlCapabilitiesDidChangeMessage"
)
MRGetVolumeControlCapabilitiesResultMessage = _Class(
    "MRGetVolumeControlCapabilitiesResultMessage"
)
MRGetVolumeControlCapabilitiesMessage = _Class("MRGetVolumeControlCapabilitiesMessage")
MRVolumeDidChangeMessage = _Class("MRVolumeDidChangeMessage")
MRGetVolumeResultMessage = _Class("MRGetVolumeResultMessage")
MRGetVolumeMessage = _Class("MRGetVolumeMessage")
MRTransactionMessage = _Class("MRTransactionMessage")
MRRegisterHIDDeviceResultMessage = _Class("MRRegisterHIDDeviceResultMessage")
MRSetDiscoveryModeMessage = _Class("MRSetDiscoveryModeMessage")
MRSendVoiceInputMessage = _Class("MRSendVoiceInputMessage")
MRSetRecordingStateMessage = _Class("MRSetRecordingStateMessage")
MRRegisterVoiceInputDeviceResponseMessage = _Class(
    "MRRegisterVoiceInputDeviceResponseMessage"
)
MRRegisterVoiceInputDeviceMessage = _Class("MRRegisterVoiceInputDeviceMessage")
MRGetVoiceInputDevicesResponseMessage = _Class("MRGetVoiceInputDevicesResponseMessage")
MRGetVoiceInputDevicesMessage = _Class("MRGetVoiceInputDevicesMessage")
MRGetKeyboardSessionMessage = _Class("MRGetKeyboardSessionMessage")
MRSetVolumeMessage = _Class("MRSetVolumeMessage")
MRDeviceInfoMessage = _Class("MRDeviceInfoMessage")
MRDeviceInfoUpdateMessage = _Class("MRDeviceInfoUpdateMessage")
MRRegisterForGameControllerEventsMessage = _Class(
    "MRRegisterForGameControllerEventsMessage"
)
MRUnregisterGameControllerMessage = _Class("MRUnregisterGameControllerMessage")
MRRegisterGameControllerResponseMessage = _Class(
    "MRRegisterGameControllerResponseMessage"
)
MRRegisterGameControllerMessage = _Class("MRRegisterGameControllerMessage")
MRGameControllerPropertiesMessage = _Class("MRGameControllerPropertiesMessage")
MRGameControllerMessage = _Class("MRGameControllerMessage")
MRSetDefaultSupportedCommandsMessage = _Class("MRSetDefaultSupportedCommandsMessage")
MRUpdateContentItemArtworkMessage = _Class("MRUpdateContentItemArtworkMessage")
MRUpdateContentItemMessage = _Class("MRUpdateContentItemMessage")
MRUpdatePlayerMessage = _Class("MRUpdatePlayerMessage")
MRUpdateClientMessage = _Class("MRUpdateClientMessage")
MRRemovePlayerMessage = _Class("MRRemovePlayerMessage")
MRRemoveClientMessage = _Class("MRRemoveClientMessage")
MRSetNowPlayingPlayerMessage = _Class("MRSetNowPlayingPlayerMessage")
MRSetNowPlayingClientMessage = _Class("MRSetNowPlayingClientMessage")
MRWakeDeviceMessage = _Class("MRWakeDeviceMessage")
MRSetHiliteModeMessage = _Class("MRSetHiliteModeMessage")
MRSetConnectionStateMessage = _Class("MRSetConnectionStateMessage")
MRSetReadyStateMessage = _Class("MRSetReadyStateMessage")
MRSetStateMessage = _Class("MRSetStateMessage")
MRRemoveEndpointsMessage = _Class("MRRemoveEndpointsMessage")
MRUpdateEndpointsMessage = _Class("MRUpdateEndpointsMessage")
MRUpdateActiveSystemEndpointMessage = _Class("MRUpdateActiveSystemEndpointMessage")
MRRemoveOutputDevicesMessage = _Class("MRRemoveOutputDevicesMessage")
MRRemoveFromParentGroupMessage = _Class("MRRemoveFromParentGroupMessage")
MRUpdateOutputDevicesMessage = _Class("MRUpdateOutputDevicesMessage")
MRModifyOutputContextRequestMessage = _Class("MRModifyOutputContextRequestMessage")
MRClientUpdatesConfigMessage = _Class("MRClientUpdatesConfigMessage")
MRPlaybackSession = _Class("MRPlaybackSession")
MRLegacyController = _Class("MRLegacyController")
MRBlockGuard = _Class("MRBlockGuard")
_MRGameControllerMotionProtobuf = _Class("_MRGameControllerMotionProtobuf")
_MRNowPlayingPlayerPathProtobuf = _Class("_MRNowPlayingPlayerPathProtobuf")
_MRTransactionKeyProtobuf = _Class("_MRTransactionKeyProtobuf")
_MRRegisterHIDDeviceMessageProtobuf = _Class("_MRRegisterHIDDeviceMessageProtobuf")
_MRVideoThumbnailProtobuf = _Class("_MRVideoThumbnailProtobuf")
_MRPlaybackQueueProtobuf = _Class("_MRPlaybackQueueProtobuf")
_MRSendVoiceInputMessageProtobuf = _Class("_MRSendVoiceInputMessageProtobuf")
_MRGameControllerMessageProtobuf = _Class("_MRGameControllerMessageProtobuf")
_MRUnregisterGameControllerMessageProtobuf = _Class(
    "_MRUnregisterGameControllerMessageProtobuf"
)
_MRNowPlayingPlayerProtobuf = _Class("_MRNowPlayingPlayerProtobuf")
_MRGetVoiceInputDevicesMessageProtobuf = _Class(
    "_MRGetVoiceInputDevicesMessageProtobuf"
)
_MRUpdateEndpointsMessageProtobuf = _Class("_MRUpdateEndpointsMessageProtobuf")
_MRSetNowPlayingClientMessageProtobuf = _Class("_MRSetNowPlayingClientMessageProtobuf")
_MRUpdateOutputDevicesMessageProtobuf = _Class("_MRUpdateOutputDevicesMessageProtobuf")
_MRRegisterVoiceInputDeviceResponseMessageProtobuf = _Class(
    "_MRRegisterVoiceInputDeviceResponseMessageProtobuf"
)
_MRColorProtobuf = _Class("_MRColorProtobuf")
_MRVoiceInputDevice = _Class("_MRVoiceInputDevice")
_MRSetVolumeMessageProtobuf = _Class("_MRSetVolumeMessageProtobuf")
_MRLanguageOptionGroupProtobuf = _Class("_MRLanguageOptionGroupProtobuf")
_MRLyricsItemProtobuf = _Class("_MRLyricsItemProtobuf")
_MRWakeDeviceMessageProtobuf = _Class("_MRWakeDeviceMessageProtobuf")
_MRGetVoiceInputDevicesResponseMessageProtobuf = _Class(
    "_MRGetVoiceInputDevicesResponseMessageProtobuf"
)
_MRPlaybackSessionRequestMessageProtobuf = _Class(
    "_MRPlaybackSessionRequestMessageProtobuf"
)
_MRGameControllerButtonsProtobuf = _Class("_MRGameControllerButtonsProtobuf")
_MRRemoveEndpointsMessageProtobuf = _Class("_MRRemoveEndpointsMessageProtobuf")
_MRRegisterForGameControllerEventsMessageProtobuf = _Class(
    "_MRRegisterForGameControllerEventsMessageProtobuf"
)
_MRRegisterGameControllerResponseMessageProtobuf = _Class(
    "_MRRegisterGameControllerResponseMessageProtobuf"
)
_MRTextInputTraitsProtobuf = _Class("_MRTextInputTraitsProtobuf")
_MRSendHIDEventMessageProtobuf = _Class("_MRSendHIDEventMessageProtobuf")
_MRDeviceInfoMessageProtobuf = _Class("_MRDeviceInfoMessageProtobuf")
_MRTransactionPacketsProtobuf = _Class("_MRTransactionPacketsProtobuf")
_MRUpdateClientMessageProtobuf = _Class("_MRUpdateClientMessageProtobuf")
_MRNotificationMessageProtobuf = _Class("_MRNotificationMessageProtobuf")
_MRGetVolumeMessageProtobuf = _Class("_MRGetVolumeMessageProtobuf")
_MRPlaybackSessionMigrateBeginMessageProtobuf = _Class(
    "_MRPlaybackSessionMigrateBeginMessageProtobuf"
)
_MRPresentRouteAuthorizationStatusMessageProtobuf = _Class(
    "_MRPresentRouteAuthorizationStatusMessageProtobuf"
)
_MRUpdateActiveSystemEndpointRequestProtobuf = _Class(
    "_MRUpdateActiveSystemEndpointRequestProtobuf"
)
_MRPlaybackSessionMigrateRequestEventProtobuf = _Class(
    "_MRPlaybackSessionMigrateRequestEventProtobuf"
)
_MRCommandOptionsProtobuf = _Class("_MRCommandOptionsProtobuf")
_MRAudioFormatSettingsProtobuf = _Class("_MRAudioFormatSettingsProtobuf")
_MRGetRemoteTextInputSessionProtobuf = _Class("_MRGetRemoteTextInputSessionProtobuf")
_MRSetConnectionStateMessageProtobuf = _Class("_MRSetConnectionStateMessageProtobuf")
_MRGetVolumeControlCapabilitiesResultMessageProtobuf = _Class(
    "_MRGetVolumeControlCapabilitiesResultMessageProtobuf"
)
_MRPlaybackQueueContextProtobuf = _Class("_MRPlaybackQueueContextProtobuf")
_MRTransactionPacketProtobuf = _Class("_MRTransactionPacketProtobuf")
_MRRemoteTextInputMessageProtobuf = _Class("_MRRemoteTextInputMessageProtobuf")
_MRPlaybackSessionMigrateResponseMessageProtobuf = _Class(
    "_MRPlaybackSessionMigrateResponseMessageProtobuf"
)
_MRSetReadyStateMessageProtobuf = _Class("_MRSetReadyStateMessageProtobuf")
_MRPlaybackSessionResponseMessageProtobuf = _Class(
    "_MRPlaybackSessionResponseMessageProtobuf"
)
_MRVolumeDidChangeMessageProtobuf = _Class("_MRVolumeDidChangeMessageProtobuf")
_MRGameControllerAccelerationProtobuf = _Class("_MRGameControllerAccelerationProtobuf")
_MRUpdatePlayerMessageProtobuf = _Class("_MRUpdatePlayerMessageProtobuf")
_MRPlaybackSessionMigrateEndMessageProtobuf = _Class(
    "_MRPlaybackSessionMigrateEndMessageProtobuf"
)
_MRRegisterHIDDeviceResultMessageProtobuf = _Class(
    "_MRRegisterHIDDeviceResultMessageProtobuf"
)
_MRPlaybackSessionMigrateRequestMessageProtobuf = _Class(
    "_MRPlaybackSessionMigrateRequestMessageProtobuf"
)
_MRAudioStreamPacketDescriptionProtobuf = _Class(
    "_MRAudioStreamPacketDescriptionProtobuf"
)
_MRSendPackedVirtualTouchEventMessageProtobuf = _Class(
    "_MRSendPackedVirtualTouchEventMessageProtobuf"
)
_MRGameControllerPropertiesProtobuf = _Class("_MRGameControllerPropertiesProtobuf")
_MRAVAirPlaySecuritySettingsProtobuf = _Class("_MRAVAirPlaySecuritySettingsProtobuf")
_MRNowPlayingClientProtobuf = _Class("_MRNowPlayingClientProtobuf")
_MRRegisterGameControllerMessageProtobuf = _Class(
    "_MRRegisterGameControllerMessageProtobuf"
)
_MRVirtualTouchEventProtobuf = _Class("_MRVirtualTouchEventProtobuf")
_MRRegisterVoiceInputDeviceMessageProtobuf = _Class(
    "_MRRegisterVoiceInputDeviceMessageProtobuf"
)
_MRMediaRemoteMessageProtobuf = _Class("_MRMediaRemoteMessageProtobuf")
_MRAVOutputDeviceDescriptorProtobuf = _Class("_MRAVOutputDeviceDescriptorProtobuf")
_MRPlaybackSessionProtobuf = _Class("_MRPlaybackSessionProtobuf")
_MRPlaybackSessionRequestProtobuf = _Class("_MRPlaybackSessionRequestProtobuf")
_MRKeyboardMessageProtobuf = _Class("_MRKeyboardMessageProtobuf")
_MROriginProtobuf = _Class("_MROriginProtobuf")
_MRSendButtonEventMessageProtobuf = _Class("_MRSendButtonEventMessageProtobuf")
_MRCommandInfoProtobuf = _Class("_MRCommandInfoProtobuf")
_MRSetHiliteModeMessageProtobuf = _Class("_MRSetHiliteModeMessageProtobuf")
_MRLyricsTokenProtobuf = _Class("_MRLyricsTokenProtobuf")
_MRSetArtworkMessageProtobuf = _Class("_MRSetArtworkMessageProtobuf")
_MRAVModifyOutputContextRequestProtobuf = _Class(
    "_MRAVModifyOutputContextRequestProtobuf"
)
_MRGameControllerDigitizerProtobuf = _Class("_MRGameControllerDigitizerProtobuf")
_MRTransactionMessageProtobuf = _Class("_MRTransactionMessageProtobuf")
_MRUpdateContentItemArtworkMessageProtobuf = _Class(
    "_MRUpdateContentItemArtworkMessageProtobuf"
)
_MRClientUpdatesConfigurationProtobuf = _Class("_MRClientUpdatesConfigurationProtobuf")
_MRTextEditingAttributesProtobuf = _Class("_MRTextEditingAttributesProtobuf")
_MRSendHIDReportMessageProtobuf = _Class("_MRSendHIDReportMessageProtobuf")
_MRSendCommandMessageProtobuf = _Class("_MRSendCommandMessageProtobuf")
_MRVolumeControlAvailabilityProtobuf = _Class("_MRVolumeControlAvailabilityProtobuf")
_MRSendLyricsEventMessageProtobuf = _Class("_MRSendLyricsEventMessageProtobuf")
_MRRemovePlayerMessageProtobuf = _Class("_MRRemovePlayerMessageProtobuf")
_MRPlaybackSessionMigrateRequestProtobuf = _Class(
    "_MRPlaybackSessionMigrateRequestProtobuf"
)
_MRUpdateContentItemMessageProtobuf = _Class("_MRUpdateContentItemMessageProtobuf")
_MRVirtualTouchDeviceDescriptorProtobuf = _Class(
    "_MRVirtualTouchDeviceDescriptorProtobuf"
)
_MRTextInputMessageProtobuf = _Class("_MRTextInputMessageProtobuf")
_MRGenericMessageProtobuf = _Class("_MRGenericMessageProtobuf")
_MRPromptForRouteAuthorizationResponseMessageProtobuf = _Class(
    "_MRPromptForRouteAuthorizationResponseMessageProtobuf"
)
_MRAVEndpointDescriptorProtobuf = _Class("_MRAVEndpointDescriptorProtobuf")
_MRCryptoPairingMessageProtobuf = _Class("_MRCryptoPairingMessageProtobuf")
_MRRemoveOutputDevicesMessageProtobuf = _Class("_MRRemoveOutputDevicesMessageProtobuf")
_MRRemoveClientMessageProtobuf = _Class("_MRRemoveClientMessageProtobuf")
_MRSetDiscoveryModeProtobufMessage = _Class("_MRSetDiscoveryModeProtobufMessage")
_MROriginClientPropertiesMessageProtobuf = _Class(
    "_MROriginClientPropertiesMessageProtobuf"
)
_MRPlaybackQueueCapabilitiesProtobuf = _Class("_MRPlaybackQueueCapabilitiesProtobuf")
_MRAVOutputDeviceSourceInfoProtobuf = _Class("_MRAVOutputDeviceSourceInfoProtobuf")
_MRAudioBufferProtobuf = _Class("_MRAudioBufferProtobuf")
_MRVoiceInputDeviceDescriptorProtobuf = _Class("_MRVoiceInputDeviceDescriptorProtobuf")
_MRPlayerClientPropertiesMessageProtobuf = _Class(
    "_MRPlayerClientPropertiesMessageProtobuf"
)
_MRGetStateMessageProtobuf = _Class("_MRGetStateMessageProtobuf")
_MRSendCommandResultMessageProtobuf = _Class("_MRSendCommandResultMessageProtobuf")
_MRDiagnosticProtobuf = _Class("_MRDiagnosticProtobuf")
_MRContentItemMetadataProtobuf = _Class("_MRContentItemMetadataProtobuf")
_MRSendVirtualTouchEventMessageProtobuf = _Class(
    "_MRSendVirtualTouchEventMessageProtobuf"
)
_MRVolumeControlCapabilitiesDidChangeMessageProtobuf = _Class(
    "_MRVolumeControlCapabilitiesDidChangeMessageProtobuf"
)
_MRUpdateActiveSystemEndpointMessageProtobuf = _Class(
    "_MRUpdateActiveSystemEndpointMessageProtobuf"
)
_MRGetVolumeResultMessageProtobuf = _Class("_MRGetVolumeResultMessageProtobuf")
_MRAVRouteQueryProtobuf = _Class("_MRAVRouteQueryProtobuf")
_MRSetRecordingStateMessageProtobuf = _Class("_MRSetRecordingStateMessageProtobuf")
_MRReceivedCommandAppOptionsProtobuf = _Class("_MRReceivedCommandAppOptionsProtobuf")
_MRContentItemProtobuf = _Class("_MRContentItemProtobuf")
_MRGetKeyboardSessionProtobuf = _Class("_MRGetKeyboardSessionProtobuf")
_MRReceivedCommandProtobuf = _Class("_MRReceivedCommandProtobuf")
_MRAudioTimeProtobuf = _Class("_MRAudioTimeProtobuf")
_MRNowPlayingInfoProtobuf = _Class("_MRNowPlayingInfoProtobuf")
_MRLanguageOptionProtobuf = _Class("_MRLanguageOptionProtobuf")
_MRSetStateMessageProtobuf = _Class("_MRSetStateMessageProtobuf")
_MRSupportedCommandsProtobuf = _Class("_MRSupportedCommandsProtobuf")
_MRPromptForRouteAuthorizationMessageProtobuf = _Class(
    "_MRPromptForRouteAuthorizationMessageProtobuf"
)
_MRGetVolumeControlCapabilitiesMessageProtobuf = _Class(
    "_MRGetVolumeControlCapabilitiesMessageProtobuf"
)
_MRSetNowPlayingPlayerMessageProtobuf = _Class("_MRSetNowPlayingPlayerMessageProtobuf")
_MRAudioDataBlockProtobuf = _Class("_MRAudioDataBlockProtobuf")
_MRLyricsEventProtobuf = _Class("_MRLyricsEventProtobuf")
_MRGameControllerPropertiesMessageProtobuf = _Class(
    "_MRGameControllerPropertiesMessageProtobuf"
)
_MRPlaybackQueueRequestProtobuf = _Class("_MRPlaybackQueueRequestProtobuf")
_MRVideoThumbnailRequestProtobuf = _Class("_MRVideoThumbnailRequestProtobuf")
MRAVBufferedOutputStream = _Class("MRAVBufferedOutputStream")
MRAVOutputStream = _Class("MRAVOutputStream")
MRAVOutputDeviceOutputStream = _Class("MRAVOutputDeviceOutputStream")
MRIDSOutputStream = _Class("MRIDSOutputStream")
MRAVBufferedInputStream = _Class("MRAVBufferedInputStream")
MRAVInputStream = _Class("MRAVInputStream")
MRAVOutputDeviceInputStream = _Class("MRAVOutputDeviceInputStream")
MRIDSInputStream = _Class("MRIDSInputStream")
