"""
Classes from the 'NetworkStatistics' framework.
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


NWStatisticsManager = _Class("NWStatisticsManager")
NWSSnapshotter = _Class("NWSSnapshotter")
NWSRouteSnapshotter = _Class("NWSRouteSnapshotter")
NWSSnapshotSource = _Class("NWSSnapshotSource")
NWStatisticsSource = _Class("NWStatisticsSource")
NWStatisticsUDPSource = _Class("NWStatisticsUDPSource")
NWStatisticsTCPSource = _Class("NWStatisticsTCPSource")
NWStatisticsRouteSource = _Class("NWStatisticsRouteSource")
NWStatisticsInterfaceSource = _Class("NWStatisticsInterfaceSource")
NWStatisticsQUICSource = _Class("NWStatisticsQUICSource")
NWSSnapshot = _Class("NWSSnapshot")
NWSProtocolSnapshot = _Class("NWSProtocolSnapshot")
NWSQUICSnapshot = _Class("NWSQUICSnapshot")
NWSUDPSnapshot = _Class("NWSUDPSnapshot")
NWSTCPSnapshot = _Class("NWSTCPSnapshot")
NWSRouteSnapshot = _Class("NWSRouteSnapshot")
NWSInterfaceSnapshot = _Class("NWSInterfaceSnapshot")
NWStatisticsDelegateBlockWrapper = _Class("NWStatisticsDelegateBlockWrapper")
