'''
Classes from the 'CoreLocation' framework.
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

    
_CLVIOEstimation = _Class('_CLVIOEstimation')
_CLLSLHeadingEstimation = _Class('_CLLSLHeadingEstimation')
_CLLSLHeading = _Class('_CLLSLHeading')
_CLLSLHeadingSupplInfo = _Class('_CLLSLHeadingSupplInfo')
_CLLSLMapRoadSegment = _Class('_CLLSLMapRoadSegment')
_CLLSLLocation = _Class('_CLLSLLocation')
_CLLSLLocationCoordinate = _Class('_CLLSLLocationCoordinate')
_CLRangingPeerDistance = _Class('_CLRangingPeerDistance')
_CLRangingPeer = _Class('_CLRangingPeer')
_CLRangingPeerDistanceInternal = _Class('_CLRangingPeerDistanceInternal')
_CLRangingPeerInternal = _Class('_CLRangingPeerInternal')
CLFloor = _Class('CLFloor')
CLLocationInternal = _Class('CLLocationInternal')
CLHarvester = _Class('CLHarvester')
_CLVertex = _Class('_CLVertex')
CLReductiveFilterOptions = _Class('CLReductiveFilterOptions')
CLPlacemark = _Class('CLPlacemark')
CLPlacemarkInternal = _Class('CLPlacemarkInternal')
CLLocationInternalClient = _Class('CLLocationInternalClient')
CLGeocoder = _Class('CLGeocoder')
CLGeocoderInternal = _Class('CLGeocoderInternal')
CLVisit = _Class('CLVisit')
CLVehicleSpeed = _Class('CLVehicleSpeed')
CLVehicleSpeedInternal = _Class('CLVehicleSpeedInternal')
CLVehicleHeading = _Class('CLVehicleHeading')
CLVehicleHeadingInternal = _Class('CLVehicleHeadingInternal')
CLBeaconIdentityConstraint = _Class('CLBeaconIdentityConstraint')
CLSimulationManager = _Class('CLSimulationManager')
_CLVLLocalizationResult = _Class('_CLVLLocalizationResult')
CLBeacon = _Class('CLBeacon')
CLBeaconInternal = _Class('CLBeaconInternal')
CLRegion = _Class('CLRegion')
_CLPolygonalRegion = _Class('_CLPolygonalRegion')
CLBeaconRegion = _Class('CLBeaconRegion')
CLCircularRegion = _Class('CLCircularRegion')
CLRegionInternal = _Class('CLRegionInternal')
_CLLocationFusionInfo = _Class('_CLLocationFusionInfo')
CLHeading = _Class('CLHeading')
CLHeadingInternal = _Class('CLHeadingInternal')
CLLocationMatchInfo = _Class('CLLocationMatchInfo')
CLLocationMatchInfoInternal = _Class('CLLocationMatchInfoInternal')
CLLocationSmoother = _Class('CLLocationSmoother')
_CLLocationSmootherProxy = _Class('_CLLocationSmootherProxy')
_CLLocationGroundAltitude = _Class('_CLLocationGroundAltitude')
CLAssertion = _Class('CLAssertion')
CLLocationIndependenceAssertion = _Class('CLLocationIndependenceAssertion')
CLInUseAssertion = _Class('CLInUseAssertion')
CLEmergencyEnablementAssertion = _Class('CLEmergencyEnablementAssertion')
CLLocationManagerRoutine = _Class('CLLocationManagerRoutine')
_CLLocationManagerRoutineProxy = _Class('_CLLocationManagerRoutineProxy')
_CLPlaceInference = _Class('_CLPlaceInference')
CLLocation = _Class('CLLocation')
CLStateTracker = _Class('CLStateTracker')
CLLocationManagerStateTracker = _Class('CLLocationManagerStateTracker')
CLLocationManagerInternal = _Class('CLLocationManagerInternal')
CLLocationManager = _Class('CLLocationManager')
