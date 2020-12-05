"""
Classes from the 'MaterialKit' framework.
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


MTVisualStyling = _Class("MTVisualStyling")
MTVisualStylingProvider = _Class("MTVisualStylingProvider")
MTMappedImageCache = _Class("MTMappedImageCache")
MTLumaDodgePillSettings = _Class("MTLumaDodgePillSettings")
MTLumaDodgePillStyleSettings = _Class("MTLumaDodgePillStyleSettings")
MTLumaDodgePillDomain = _Class("MTLumaDodgePillDomain")
_MTVisualStylingVibrancyEffect = _Class("_MTVisualStylingVibrancyEffect")
MTMaterialShadowView = _Class("MTMaterialShadowView")
MTMaterialView = _Class("MTMaterialView")
_MTStaticVibrantColorMaterialView = _Class("_MTStaticVibrantColorMaterialView")
MTStylingProvidingSolidColorView = _Class("MTStylingProvidingSolidColorView")
_MTLumaDodgePillLowQualityEffectView = _Class("_MTLumaDodgePillLowQualityEffectView")
MTPillView = _Class("MTPillView")
MTStaticColorPillView = _Class("MTStaticColorPillView")
MTLumaDodgePillView = _Class("MTLumaDodgePillView")
MTShadowView = _Class("MTShadowView")
