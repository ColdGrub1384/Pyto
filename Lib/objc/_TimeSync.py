"""
Classes from the 'TimeSync' framework.
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


TSTimeConverter = _Class("TSTimeConverter")
TSTAIUTCValue = _Class("TSTAIUTCValue")
TSgPTPTime = _Class("TSgPTPTime")
TSGPSTime = _Class("TSGPSTime")
TSTime = _Class("TSTime")
TSPortInterface = _Class("TSPortInterface")
TSClockInterface = _Class("TSClockInterface")
TSBonjourAdvertise = _Class("TSBonjourAdvertise")
TSMTIEMask = _Class("TSMTIEMask")
TSMTIEMaskError = _Class("TSMTIEMaskError")
TSMTIEValue = _Class("TSMTIEValue")
TSMTIEMaskElement = _Class("TSMTIEMaskElement")
TSIntervalFilter = _Class("TSIntervalFilter")
TSMADEVValue = _Class("TSMADEVValue")
TSBonjourIPv6Address = _Class("TSBonjourIPv6Address")
TSBonjourIPv4Address = _Class("TSBonjourIPv4Address")
TSBonjourInterface = _Class("TSBonjourInterface")
TSBonjourNode = _Class("TSBonjourNode")
TSgPTPPortStatistics = _Class("TSgPTPPortStatistics")
TSgPTPPort = _Class("TSgPTPPort")
TSgPTPNetworkPort = _Class("TSgPTPNetworkPort")
TSgPTPFDEtEPort = _Class("TSgPTPFDEtEPort")
TSgPTPUnicastUDPv6EtEPort = _Class("TSgPTPUnicastUDPv6EtEPort")
TSgPTPUnicastUDPv4EtEPort = _Class("TSgPTPUnicastUDPv4EtEPort")
TSgPTPUnicastLinkLayerEtEPort = _Class("TSgPTPUnicastLinkLayerEtEPort")
TSgPTPFDPtPPort = _Class("TSgPTPFDPtPPort")
TSgPTPUnicastUDPv6PtPPort = _Class("TSgPTPUnicastUDPv6PtPPort")
TSgPTPUnicastUDPv4PtPPort = _Class("TSgPTPUnicastUDPv4PtPPort")
TSgPTPUnicastLinkLayerPtPPort = _Class("TSgPTPUnicastLinkLayerPtPPort")
TSgPTPEthernetPort = _Class("TSgPTPEthernetPort")
TSgPTPMachPort = _Class("TSgPTPMachPort")
TSADEVValue = _Class("TSADEVValue")
TSBonjourBrowser = _Class("TSBonjourBrowser")
TSRMSTIEValue = _Class("TSRMSTIEValue")
TSClockManager = _Class("TSClockManager")
TSClockPulser = _Class("TSClockPulser")
TSTDEVValue = _Class("TSTDEVValue")
TSFrequencyAnalysis = _Class("TSFrequencyAnalysis")
TSClock = _Class("TSClock")
TSMachAbsoluteNanoseconds = _Class("TSMachAbsoluteNanoseconds")
TSKernelClock = _Class("TSKernelClock")
TSUserFilteredClock = _Class("TSUserFilteredClock")
TSgPTPClock = _Class("TSgPTPClock")
TSTimeErrorSequence = _Class("TSTimeErrorSequence")
TSTimeErrorValue = _Class("TSTimeErrorValue")
TSTimeErrorAnalysis = _Class("TSTimeErrorAnalysis")
TSMaximumTimeIntervalErrorAnalysis = _Class("TSMaximumTimeIntervalErrorAnalysis")
TSModifiedAllanDeviationAnalysis = _Class("TSModifiedAllanDeviationAnalysis")
TSAllanDeviationAnalysis = _Class("TSAllanDeviationAnalysis")
TSRootMeanSquaredTimeIntervalErrorAnalysis = _Class(
    "TSRootMeanSquaredTimeIntervalErrorAnalysis"
)
TSTimeDeviationAnalysis = _Class("TSTimeDeviationAnalysis")
TSTimeLineFilter = _Class("TSTimeLineFilter")
TSIntervalTimeLineFilter = _Class("TSIntervalTimeLineFilter")
TSAudioTimeErrorValue = _Class("TSAudioTimeErrorValue")
TSAudioTimeErrorCalculator = _Class("TSAudioTimeErrorCalculator")
TSAudioTimeErrorCorrelator = _Class("TSAudioTimeErrorCorrelator")
TSAudioTimeErrorCorrelatorPostUpsampler = _Class(
    "TSAudioTimeErrorCorrelatorPostUpsampler"
)
TSAudioTimeErrorCorrelatorResampler = _Class("TSAudioTimeErrorCorrelatorResampler")
TSAudioTimeErrorCorrelatorQuick = _Class("TSAudioTimeErrorCorrelatorQuick")
TSgPTPManager = _Class("TSgPTPManager")
