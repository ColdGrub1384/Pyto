"""
Classes from the 'VirtualGarage' framework.
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


VGVirtualGarageService = _Class("VGVirtualGarageService")
VGVirtualGarageServer = _Class("VGVirtualGarageServer")
VGExternalAccessoryAdapter = _Class("VGExternalAccessoryAdapter")
VGOEMApplication = _Class("VGOEMApplication")
VGOEMApplicationFinder = _Class("VGOEMApplicationFinder")
VGVirtualGarage = _Class("VGVirtualGarage")
VGVehicleState = _Class("VGVehicleState")
VGExternalAccessory = _Class("VGExternalAccessory")
VGExternalAccessoryState = _Class("VGExternalAccessoryState")
VGDataCoordinator = _Class("VGDataCoordinator")
VGVehicle = _Class("VGVehicle")
VGVehicleDeduper = _Class("VGVehicleDeduper")
VGVehicleStateStorage = _Class("VGVehicleStateStorage")
