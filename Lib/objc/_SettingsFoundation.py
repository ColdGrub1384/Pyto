"""
Classes from the 'SettingsFoundation' framework.
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


SFRestrictionsPasscodeController = _Class("SFRestrictionsPasscodeController")
SFRestrictionsController = _Class("SFRestrictionsController")
SFEyesightWarningView = _Class("SFEyesightWarningView")
SFMonthAndYearOfManufactureView = _Class("SFMonthAndYearOfManufactureView")
SFAlertMarkView = _Class("SFAlertMarkView")
SFIndiaBISView = _Class("SFIndiaBISView")
SFYearOfManufactureView = _Class("SFYearOfManufactureView")
SFRegulatoryCertificationsView = _Class("SFRegulatoryCertificationsView")
