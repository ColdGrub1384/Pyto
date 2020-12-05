"""
Classes from the 'Color_Picker_for_iOS' framework.
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


PodsDummy_Color_Picker_for_iOS = _Class("PodsDummy_Color_Picker_for_iOS")
HRColorInfoView = _Class("HRColorInfoView")
HRColorCursor = _Class("HRColorCursor")
HRBrightnessCursor = _Class("HRBrightnessCursor")
HRColorPickerView = _Class("HRColorPickerView")
HRColorMapView = _Class("HRColorMapView")
HRBrightnessSlider = _Class("HRBrightnessSlider")
