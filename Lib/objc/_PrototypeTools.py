'''
Classes from the 'PrototypeTools' framework.
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

    
PTDomainServer = _Class('PTDomainServer')
PTRowAction = _Class('PTRowAction')
PTSRowAction = _Class('PTSRowAction')
PTRestoreDefaultSettingsRowAction = _Class('PTRestoreDefaultSettingsRowAction')
PTSRestoreDefaultSettingsRowAction = _Class('PTSRestoreDefaultSettingsRowAction')
PTModule = _Class('PTModule')
PTSModule = _Class('PTSModule')
PTTestRecipeInfo = _Class('PTTestRecipeInfo')
PTTestRecipe = _Class('PTTestRecipe')
PTDoubleTestRecipe = _Class('PTDoubleTestRecipe')
PTToggleTestRecipe = _Class('PTToggleTestRecipe')
PTSingleTestRecipe = _Class('PTSingleTestRecipe')
PTSection = _Class('PTSection')
PTSSection = _Class('PTSSection')
PTRow = _Class('PTRow')
PTSRow = _Class('PTSRow')
PTButtonRow = _Class('PTButtonRow')
PTSButtonRow = _Class('PTSButtonRow')
PTDrillDownRow = _Class('PTDrillDownRow')
PTSDrillDownRow = _Class('PTSDrillDownRow')
PTEditStringRow = _Class('PTEditStringRow')
PTSEditStringRow = _Class('PTSEditStringRow')
PTEditFloatRow = _Class('PTEditFloatRow')
PTSEditFloatRow = _Class('PTSEditFloatRow')
PTChoiceRow = _Class('PTChoiceRow')
PTSChoiceRow = _Class('PTSChoiceRow')
PTSliderRow = _Class('PTSliderRow')
PTSSliderRow = _Class('PTSSliderRow')
PTSwitchRow = _Class('PTSwitchRow')
PTSSwitchRow = _Class('PTSSwitchRow')
PTProxySettingsDefinition = _Class('PTProxySettingsDefinition')
PTDefaults = _Class('PTDefaults')
PTOutlet = _Class('PTOutlet')
PTSettingsClassStructure = _Class('PTSettingsClassStructure')
PTSettings = _Class('PTSettings')
PTSizeSettings = _Class('PTSizeSettings')
PTPointSettings = _Class('PTPointSettings')
PTProxySettings = _Class('PTProxySettings')
PTDomainInfo = _Class('PTDomainInfo')
PTDomain = _Class('PTDomain')
