"""
Classes from the 'Network' framework.
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


NWTCPListener = _Class("NWTCPListener")
NWResolver = _Class("NWResolver")
NWConnectionStatistics = _Class("NWConnectionStatistics")
NWActivityEmptyTrigger = _Class("NWActivityEmptyTrigger")
NWActivityEpilogueStatistics = _Class("NWActivityEpilogueStatistics")
NWActivityStatistics = _Class("NWActivityStatistics")
NWDeviceReport = _Class("NWDeviceReport")
NWL2Report = _Class("NWL2Report")
NWMessage = _Class("NWMessage")
NWInboundMessage = _Class("NWInboundMessage")
NWOutboundMessage = _Class("NWOutboundMessage")
NWBrowseDescriptor = _Class("NWBrowseDescriptor")
NWBonjourBrowseDescriptor = _Class("NWBonjourBrowseDescriptor")
NWBrowser = _Class("NWBrowser")
NWInterface = _Class("NWInterface")
NWProtocolTransform = _Class("NWProtocolTransform")
NWRemoteConnectionActor = _Class("NWRemoteConnectionActor")
NWRemoteBrowserWrapper = _Class("NWRemoteBrowserWrapper")
NWRemoteConnectionWrapper = _Class("NWRemoteConnectionWrapper")
NWPathFlow = _Class("NWPathFlow")
NWGenericNetworkAgent = _Class("NWGenericNetworkAgent")
NWParameters = _Class("NWParameters")
NWUDPListener = _Class("NWUDPListener")
NWNetworkDescription = _Class("NWNetworkDescription")
NWRemoteConnectionDirector = _Class("NWRemoteConnectionDirector")
NWRemoteConnectionWriteRequest = _Class("NWRemoteConnectionWriteRequest")
NWUDPSession = _Class("NWUDPSession")
NWPrivilegedHelper = _Class("NWPrivilegedHelper")
NWPHHandler = _Class("NWPHHandler")
NWPHContext = _Class("NWPHContext")
NWNetworkAgentRegistration = _Class("NWNetworkAgentRegistration")
NWAdvertiseDescriptor = _Class("NWAdvertiseDescriptor")
NWCandidatePathMonitor = _Class("NWCandidatePathMonitor")
ManagedNetworkSettings = _Class("ManagedNetworkSettings")
NWRemotePacketProxy = _Class("NWRemotePacketProxy")
NWConnection = _Class("NWConnection")
NWDatagramConnection = _Class("NWDatagramConnection")
NWMessageConnection = _Class("NWMessageConnection")
NWStreamConnection = _Class("NWStreamConnection")
NWMonitor = _Class("NWMonitor")
NWEndpoint = _Class("NWEndpoint")
NWBonjourServiceEndpoint = _Class("NWBonjourServiceEndpoint")
NWHostEndpoint = _Class("NWHostEndpoint")
NWAddressEndpoint = _Class("NWAddressEndpoint")
NWAccumulator = _Class("NWAccumulator")
NWAccumulatedValue = _Class("NWAccumulatedValue")
NWAccumulation = _Class("NWAccumulation")
NWTCPConnection = _Class("NWTCPConnection")
NWSystemPathMonitor = _Class("NWSystemPathMonitor")
NWPath = _Class("NWPath")
NWPathEvaluator = _Class("NWPathEvaluator")
NWAWDLibnetcoreTCPECNStatsReport = _Class("NWAWDLibnetcoreTCPECNStatsReport")
NWPBUpdatePath = _Class("NWPBUpdatePath")
NWAWDLBClientConnectionReport = _Class("NWAWDLBClientConnectionReport")
NWPBServiceEndpoint = _Class("NWPBServiceEndpoint")
NWAWDNWActivityEmptyTrigger = _Class("NWAWDNWActivityEmptyTrigger")
NWAWDLibnetcoreTCPConnectionReport = _Class("NWAWDLibnetcoreTCPConnectionReport")
NWPBSendData = _Class("NWPBSendData")
NWPBInterface = _Class("NWPBInterface")
NWPBStopBrowse = _Class("NWPBStopBrowse")
NWAWDLibnetcoreRNFActivityNotification = _Class(
    "NWAWDLibnetcoreRNFActivityNotification"
)
NWPBPath = _Class("NWPBPath")
NWAWDMPTCPConnectionInterfaceReport = _Class("NWAWDMPTCPConnectionInterfaceReport")
NWAWDLibnetcoreConnectionDataUsageSnapshot = _Class(
    "NWAWDLibnetcoreConnectionDataUsageSnapshot"
)
NWPBStartBrowse = _Class("NWPBStartBrowse")
NWPBOpenConnection = _Class("NWPBOpenConnection")
NWPBCommandMessage = _Class("NWPBCommandMessage")
NWAWDNWL2Report = _Class("NWAWDNWL2Report")
NWAWDMPTCPSubflowSwitchingReport = _Class("NWAWDMPTCPSubflowSwitchingReport")
NWAWDNWAccumulator = _Class("NWAWDNWAccumulator")
NWPBHostEndpoint = _Class("NWPBHostEndpoint")
NWAWDLibnetcoreMbufStatsReport = _Class("NWAWDLibnetcoreMbufStatsReport")
NWPBAddressEndpoint = _Class("NWPBAddressEndpoint")
NWPBUpdateBrowse = _Class("NWPBUpdateBrowse")
NWAWDNWActivityEpilogue = _Class("NWAWDNWActivityEpilogue")
NWAWDNWDurationAccumulationState = _Class("NWAWDNWDurationAccumulationState")
NWPBParameters = _Class("NWPBParameters")
NWAWDLibnetcoreTCPTFOStatsReport = _Class("NWAWDLibnetcoreTCPTFOStatsReport")
NWAWDLBConnectionReport = _Class("NWAWDLBConnectionReport")
NWAWDNWDeviceReport = _Class("NWAWDNWDeviceReport")
NWAWDLibnetcoreCellularFallbackReport = _Class("NWAWDLibnetcoreCellularFallbackReport")
NWAWDLibnetcoreTCPStatsReport = _Class("NWAWDLibnetcoreTCPStatsReport")
NWPBAgentClass = _Class("NWPBAgentClass")
NWPBAgent = _Class("NWPBAgent")
NWPBServiceBrowse = _Class("NWPBServiceBrowse")
NWPBBrowseDescriptor = _Class("NWPBBrowseDescriptor")
NWAWDLibnetcoreNetworkdStatsReport = _Class("NWAWDLibnetcoreNetworkdStatsReport")
NWAWDNWActivity = _Class("NWAWDNWActivity")
NWAWDLibnetcoreStatsReport = _Class("NWAWDLibnetcoreStatsReport")
NWAWDLibnetcoreConnectionStatisticsReport = _Class(
    "NWAWDLibnetcoreConnectionStatisticsReport"
)
NWAWDMPTCPConnectionReport = _Class("NWAWDMPTCPConnectionReport")
NWAWDNWConnectionReport = _Class("NWAWDNWConnectionReport")
NWAWDLibnetcoreTCPKernelStats = _Class("NWAWDLibnetcoreTCPKernelStats")
NWPBEndpoint = _Class("NWPBEndpoint")
NWAWDNWAPIUsage = _Class("NWAWDNWAPIUsage")
NWAWDLibnetcoreTCPECNInterfaceStatsReport = _Class(
    "NWAWDLibnetcoreTCPECNInterfaceStatsReport"
)
NWAWDLBEndpointsFetchReport = _Class("NWAWDLBEndpointsFetchReport")
NWPBCloseConnection = _Class("NWPBCloseConnection")
NWAWDNWDurationAccumulation = _Class("NWAWDNWDurationAccumulation")
NWAWDLibnetcoreMPTCPStatsReport = _Class("NWAWDLibnetcoreMPTCPStatsReport")
