"""
Classes from the 'ImageCaptureCore' framework.
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


ICMasterDeviceBrowser = _Class("ICMasterDeviceBrowser")
ICDeviceBrowser = _Class("ICDeviceBrowser")
ICDeviceBrowserPrivateData = _Class("ICDeviceBrowserPrivateData")
ICClient = _Class("ICClient")
ICClientManager = _Class("ICClientManager")
ICDeviceAccessManager = _Class("ICDeviceAccessManager")
ICCameraItem = _Class("ICCameraItem")
ICCameraFolder = _Class("ICCameraFolder")
ICCameraFile = _Class("ICCameraFile")
ICDevice = _Class("ICDevice")
ICCameraDevice = _Class("ICCameraDevice")
ICDeviceManager = _Class("ICDeviceManager")
PTPCameraDeviceManager = _Class("PTPCameraDeviceManager")
MSCameraDeviceManager = _Class("MSCameraDeviceManager")
ICAccessManager = _Class("ICAccessManager")
ICPrefManager = _Class("ICPrefManager")
PTPObjectInfoDataset = _Class("PTPObjectInfoDataset")
MSObjectInfoDataset = _Class("MSObjectInfoDataset")
ICDeviceManagerThread = _Class("ICDeviceManagerThread")
