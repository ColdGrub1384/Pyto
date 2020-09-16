'''
Classes from the 'CoreMaterial' framework.
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

    
MTCoreMaterialVisualStylingProvider = _Class('MTCoreMaterialVisualStylingProvider')
MTMaterialSettingsInterpolator = _Class('MTMaterialSettingsInterpolator')
MTPrunePromise = _Class('MTPrunePromise')
MTCoreMaterialVisualStyling = _Class('MTCoreMaterialVisualStyling')
MTVisualStyleSet = _Class('MTVisualStyleSet')
MTColor = _Class('MTColor')
MTRGBColor = _Class('MTRGBColor')
MTWhiteColor = _Class('MTWhiteColor')
MTTintingMaterialSettings = _Class('MTTintingMaterialSettings')
MTTintingFilteringMaterialSettings = _Class('MTTintingFilteringMaterialSettings')
MTRecipeMaterialSettings = _Class('MTRecipeMaterialSettings')
MTStylingProvidingSolidColorLayer = _Class('MTStylingProvidingSolidColorLayer')
MTMaterialLayer = _Class('MTMaterialLayer')
