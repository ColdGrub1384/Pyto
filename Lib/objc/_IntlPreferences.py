"""
Classes from the 'IntlPreferences' framework.
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


IPLanguageListGenerator = _Class("IPLanguageListGenerator")
IntlUtility = _Class("IntlUtility")
NSPersonNameComponentsFormatterPreferences = _Class(
    "NSPersonNameComponentsFormatterPreferences"
)
IPFoundationNamePreferenceInfoProvider = _Class(
    "IPFoundationNamePreferenceInfoProvider"
)
IPOSXABNamePreferenceInfoProvider = _Class("IPOSXABNamePreferenceInfoProvider")
IPiOSABNamePreferenceInfoProvider = _Class("IPiOSABNamePreferenceInfoProvider")
IPLanguage = _Class("IPLanguage")
IPInternationalAnalytics = _Class("IPInternationalAnalytics")
ISMigrator = _Class("ISMigrator")
IP_unsupportedVariantsAddedByKeyboards_migrator = _Class(
    "IP_unsupportedVariantsAddedByKeyboards_migrator"
)
IP_Zawgyi_migrator = _Class("IP_Zawgyi_migrator")
IP_HK_MO_yue_Hant_migrator = _Class("IP_HK_MO_yue_Hant_migrator")
IP_pa_Arab_to_pa_Aran_migrator = _Class("IP_pa_Arab_to_pa_Aran_migrator")
ISRootMigrator = _Class("ISRootMigrator")
IPWatchLocaleController = _Class("IPWatchLocaleController")
