"""
Classes from the 'LocalAuthenticationPrivateUI' framework.
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


LAUIPearlGlyphViewStaticResources = _Class("LAUIPearlGlyphViewStaticResources")
LAUICubicBSplineRenderer = _Class("LAUICubicBSplineRenderer")
LAUIAuthenticationCore = _Class("LAUIAuthenticationCore")
LAUIDisplayLinkTargetProxy = _Class("LAUIDisplayLinkTargetProxy")
LAUIRenderLoop = _Class("LAUIRenderLoop")
LAUIMetalRenderLoop = _Class("LAUIMetalRenderLoop")
LAUIAnimationDelegate = _Class("LAUIAnimationDelegate")
LAUIPhysicalButtonViewAnimation = _Class("LAUIPhysicalButtonViewAnimation")
LAUIPhysicalButtonViewShimmerAnimation = _Class(
    "LAUIPhysicalButtonViewShimmerAnimation"
)
LAUIPhysicalButtonViewBounceAnimation = _Class("LAUIPhysicalButtonViewBounceAnimation")
LAPKGlyphWrapper = _Class("LAPKGlyphWrapper")
LAUICheckmarkLayer = _Class("LAUICheckmarkLayer")
LAUIPearlGlyphViewAutoLayoutWrapper = _Class("LAUIPearlGlyphViewAutoLayoutWrapper")
LAUIPearlGlyphView = _Class("LAUIPearlGlyphView")
LAUIRadialPingView = _Class("LAUIRadialPingView")
LAUIHorizontalArrowView = _Class("LAUIHorizontalArrowView")
LAUIPearlGlyphLabel = _Class("LAUIPearlGlyphLabel")
LAUIAuthenticationView = _Class("LAUIAuthenticationView")
LAUIPhysicalButtonView = _Class("LAUIPhysicalButtonView")
