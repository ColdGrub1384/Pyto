"""
Classes from the 'CoreLocationProtobuf' framework.
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


CLPWtwCollectionResponse = _Class("CLPWtwCollectionResponse")
CLPWifiAPLocation = _Class("CLPWifiAPLocation")
CLPTraceCollectionResponse = _Class("CLPTraceCollectionResponse")
CLPSatelliteReport = _Class("CLPSatelliteReport")
CLPSatelliteInfo = _Class("CLPSatelliteInfo")
CLPSCdmaCellTowerLocation = _Class("CLPSCdmaCellTowerLocation")
CLPRTVisit = _Class("CLPRTVisit")
CLPQuaternion = _Class("CLPQuaternion")
CLPPressureCollectionResponse = _Class("CLPPressureCollectionResponse")
CLPPressure = _Class("CLPPressure")
CLPPoiWifiAccessPoint = _Class("CLPPoiWifiAccessPoint")
CLPPoiTriggerEvent = _Class("CLPPoiTriggerEvent")
CLPPoiHarvest = _Class("CLPPoiHarvest")
CLPPoiCollectionResponse = _Class("CLPPoiCollectionResponse")
CLPPipelineDiagnosticReport = _Class("CLPPipelineDiagnosticReport")
CLPPassLocation = _Class("CLPPassLocation")
CLPPassCollectionResponse = _Class("CLPPassCollectionResponse")
CLPNRCellTowerLocation = _Class("CLPNRCellTowerLocation")
CLPNRCellNeighbor = _Class("CLPNRCellNeighbor")
CLPMotionActivity = _Class("CLPMotionActivity")
CLPMeta = _Class("CLPMeta")
CLPLteCellTowerLocation = _Class("CLPLteCellTowerLocation")
CLPLteCellNeighbor = _Class("CLPLteCellNeighbor")
CLPLocationConsumptionScoreInfo = _Class("CLPLocationConsumptionScoreInfo")
CLPLocationCollectionResponse = _Class("CLPLocationCollectionResponse")
CLPLocation = _Class("CLPLocation")
CLPIonosphereData = _Class("CLPIonosphereData")
CLPIndoorWifiScan = _Class("CLPIndoorWifiScan")
CLPIndoorPressure = _Class("CLPIndoorPressure")
CLPIndoorMotionActivity = _Class("CLPIndoorMotionActivity")
CLPIndoorEvent = _Class("CLPIndoorEvent")
CLPIndoorCollectionResponse = _Class("CLPIndoorCollectionResponse")
CLPIndoorCMPedometer = _Class("CLPIndoorCMPedometer")
CLPIndoorCMAttitude = _Class("CLPIndoorCMAttitude")
CLPContext = _Class("CLPContext")
CLPCellWifiCollectionResponse = _Class("CLPCellWifiCollectionResponse")
CLPCellTowerLocation = _Class("CLPCellTowerLocation")
CLPCellOutOfServiceInfo = _Class("CLPCellOutOfServiceInfo")
CLPCellNeighborsGroup = _Class("CLPCellNeighborsGroup")
CLPCellNeighbor = _Class("CLPCellNeighbor")
CLPCdmaCellTowerLocation = _Class("CLPCdmaCellTowerLocation")
CLPCdmaCellNeighbor = _Class("CLPCdmaCellNeighbor")
CLPBundleId = _Class("CLPBundleId")
CLPBaroCalibrationIndication = _Class("CLPBaroCalibrationIndication")
CLPAppLocation = _Class("CLPAppLocation")
CLPAppCollectionResponse = _Class("CLPAppCollectionResponse")
CLPAccessoryMeta = _Class("CLPAccessoryMeta")
CLPWtwCollectionRequest = _Class("CLPWtwCollectionRequest")
CLPTraceCollectionRequest = _Class("CLPTraceCollectionRequest")
CLPPressureCollectionRequest = _Class("CLPPressureCollectionRequest")
CLPPoiCollectionRequest = _Class("CLPPoiCollectionRequest")
CLPPassCollectionRequest = _Class("CLPPassCollectionRequest")
CLPLocationConsumptionScoreInfoRequest = _Class(
    "CLPLocationConsumptionScoreInfoRequest"
)
CLPLocationCollectionRequest = _Class("CLPLocationCollectionRequest")
CLPIonosphereCollectionRequest = _Class("CLPIonosphereCollectionRequest")
CLPIndoorCollectionRequest = _Class("CLPIndoorCollectionRequest")
CLPCellWifiCollectionRequest = _Class("CLPCellWifiCollectionRequest")
CLPAppCollectionRequest = _Class("CLPAppCollectionRequest")
CLPAltimeterCollectionRequest = _Class("CLPAltimeterCollectionRequest")
