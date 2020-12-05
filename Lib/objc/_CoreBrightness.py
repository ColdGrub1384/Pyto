"""
Classes from the 'CoreBrightness' framework.
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


CBPreferencesHandler = _Class("CBPreferencesHandler")
CBColorSample = _Class("CBColorSample")
CBHIDService = _Class("CBHIDService")
CBALSService = _Class("CBALSService")
SunriseSunsetProvider = _Class("SunriseSunsetProvider")
CBABRamp = _Class("CBABRamp")
BrightnessSystem = _Class("BrightnessSystem")
__Hotspot = _Class("__Hotspot")
KeyboardBrightnessClient = _Class("KeyboardBrightnessClient")
BLControl = _Class("BLControl")
CBStatusInfoHelper = _Class("CBStatusInfoHelper")
NightShiftDisplayWrapper = _Class("NightShiftDisplayWrapper")
CBAdaptationClient = _Class("CBAdaptationClient")
CBHIDEvent = _Class("CBHIDEvent")
CBALSEvent = _Class("CBALSEvent")
CBFilter = _Class("CBFilter")
CBDigitizerFilter = _Class("CBDigitizerFilter")
CBBrightestALSFilter = _Class("CBBrightestALSFilter")
CBSensorOverrideFilter = _Class("CBSensorOverrideFilter")
CBProxFilter = _Class("CBProxFilter")
CBCAManager = _Class("CBCAManager")
CBAnalyticsManager = _Class("CBAnalyticsManager")
CBKeyboardPreferencesManager = _Class("CBKeyboardPreferencesManager")
CBContainer = _Class("CBContainer")
CBDisplayContaineriOS = _Class("CBDisplayContaineriOS")
CBColorModuleiOS = _Class("CBColorModuleiOS")
CBKeyboardBacklightContainer = _Class("CBKeyboardBacklightContainer")
BacklightdExportedObj = _Class("BacklightdExportedObj")
BrightnessSystemClient = _Class("BrightnessSystemClient")
CBABCurve = _Class("CBABCurve")
CBALSNodeiOS = _Class("CBALSNodeiOS")
BrightnessSystemInternal = _Class("BrightnessSystemInternal")
BrightnessSystemClientExportedObj = _Class("BrightnessSystemClientExportedObj")
CBBlueLightClient = _Class("CBBlueLightClient")
CBClient = _Class("CBClient")
NightModeControl = _Class("NightModeControl")
BrightnessSystemClientInternal = _Class("BrightnessSystemClientInternal")
CBAPEndpoint = _Class("CBAPEndpoint")
CBModule = _Class("CBModule")
CBColorFilter = _Class("CBColorFilter")
CBABModuleiOS = _Class("CBABModuleiOS")
CBEDRModule = _Class("CBEDRModule")
CBABModuleExternal = _Class("CBABModuleExternal")
KeyboardBacklight = _Class("KeyboardBacklight")
KeyboardBacklightHIDCurve = _Class("KeyboardBacklightHIDCurve")
KeyboardBacklightHIDCurveNits = _Class("KeyboardBacklightHIDCurveNits")
CBDisplayModule = _Class("CBDisplayModule")
CBDisplayModuleHIDiOS = _Class("CBDisplayModuleHIDiOS")
CBDisplayModuleiOS = _Class("CBDisplayModuleiOS")
