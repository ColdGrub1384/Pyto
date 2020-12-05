"""
Classes from the 'OnBoardingKit' framework.
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


OBScrollViewWeakLayoutObserver = _Class("OBScrollViewWeakLayoutObserver")
OBNavigationBarDisplayState = _Class("OBNavigationBarDisplayState")
OBSplashButton = _Class("OBSplashButton")
OBAnalyticsManager = _Class("OBAnalyticsManager")
OBPrivacyPresenter = _Class("OBPrivacyPresenter")
OBAnimationState = _Class("OBAnimationState")
OBBundle = _Class("OBBundle")
OBUtilities = _Class("OBUtilities")
OBViewUtilities = _Class("OBViewUtilities")
OBStyle = _Class("OBStyle")
OBFlow = _Class("OBFlow")
OBPrivacyFlow = _Class("OBPrivacyFlow")
OBCapabilities = _Class("OBCapabilities")
OBDevice = _Class("OBDevice")
OBBundleManager = _Class("OBBundleManager")
OBBuddyStyle = _Class("OBBuddyStyle")
OBAnimationController = _Class("OBAnimationController")
OBSplashContent = _Class("OBSplashContent")
OBSplashBullet = _Class("OBSplashBullet")
OBAnalyticsEvent = _Class("OBAnalyticsEvent")
OBOnBoardingKitPrivacySplashPresentation = _Class(
    "OBOnBoardingKitPrivacySplashPresentation"
)
OBOnBoardingKitPrivacyLinkPresentation = _Class(
    "OBOnBoardingKitPrivacyLinkPresentation"
)
OBOnBoardingKitPrivacyUnifiedAboutPresentation = _Class(
    "OBOnBoardingKitPrivacyUnifiedAboutPresentation"
)
OBOnBoardingKitPrivacyLinkInteraction = _Class("OBOnBoardingKitPrivacyLinkInteraction")
OBButtonTrayLayoutGuide = _Class("OBButtonTrayLayoutGuide")
TapOffGestureRecognizer = _Class("TapOffGestureRecognizer")
OBImage = _Class("OBImage")
OBBulletedList = _Class("OBBulletedList")
OBTextBulletedList = _Class("OBTextBulletedList")
OBContentView = _Class("OBContentView")
OBIconTextView = _Class("OBIconTextView")
OBHeaderView = _Class("OBHeaderView")
OBAnimationView = _Class("OBAnimationView")
OBTableHeaderFooterView = _Class("OBTableHeaderFooterView")
OBBuddyPaneHeaderView = _Class("OBBuddyPaneHeaderView")
OBBulletedListItem = _Class("OBBulletedListItem")
OBTextBulletedListItem = _Class("OBTextBulletedListItem")
OBButtonTray = _Class("OBButtonTray")
OBStackedIconTextList = _Class("OBStackedIconTextList")
OBTextSectionView = _Class("OBTextSectionView")
OBPrivacySplashListView = _Class("OBPrivacySplashListView")
OBTemplateLabel = _Class("OBTemplateLabel")
OBTemplateHeaderDetailLabel = _Class("OBTemplateHeaderDetailLabel")
OBImageView = _Class("OBImageView")
OBTintInheritingImageView = _Class("OBTintInheritingImageView")
OBPrivacyLinkButton = _Class("OBPrivacyLinkButton")
OBHeaderAccessoryButton = _Class("OBHeaderAccessoryButton")
OBPrivacyButton = _Class("OBPrivacyButton")
OBTrayButton = _Class("OBTrayButton")
OBBoldTrayButton = _Class("OBBoldTrayButton")
OBLinkTrayButton = _Class("OBLinkTrayButton")
OBHollowButton = _Class("OBHollowButton")
OBBuddyContinueButton = _Class("OBBuddyContinueButton")
OBTextAccessoryButton = _Class("OBTextAccessoryButton")
OBTextSectionAccessoryButton = _Class("OBTextSectionAccessoryButton")
OBTextBulletedListAccessoryButton = _Class("OBTextBulletedListAccessoryButton")
OBPrivacyLinkController = _Class("OBPrivacyLinkController")
OBPrivacyLinkController_iOS = _Class("OBPrivacyLinkController_iOS")
OBSplashController = _Class("OBSplashController")
OBSetupAssistantDynamicLayoutController = _Class(
    "OBSetupAssistantDynamicLayoutController"
)
OBBaseWelcomeController = _Class("OBBaseWelcomeController")
OBSetupAssistantSpinnerController = _Class("OBSetupAssistantSpinnerController")
OBSetupAssistantFinishedController = _Class("OBSetupAssistantFinishedController")
OBWelcomeController = _Class("OBWelcomeController")
OBSetupAssistantHollowController = _Class("OBSetupAssistantHollowController")
OBSetupAssistantPasscodeViewController = _Class(
    "OBSetupAssistantPasscodeViewController"
)
OBTouchIDEnrollmentWelcomeController = _Class("OBTouchIDEnrollmentWelcomeController")
OBSetupAssistantBulletedListController = _Class(
    "OBSetupAssistantBulletedListController"
)
OBPrivacySplashController = _Class("OBPrivacySplashController")
OBSetupAssistantProgressController = _Class("OBSetupAssistantProgressController")
OBWelcomeFullCenterContentController = _Class("OBWelcomeFullCenterContentController")
OBTextWelcomeController = _Class("OBTextWelcomeController")
OBTableWelcomeController = _Class("OBTableWelcomeController")
OBSetupAssistantLanguageLocaleController = _Class(
    "OBSetupAssistantLanguageLocaleController"
)
OBPrivacyCombinedController = _Class("OBPrivacyCombinedController")
OBPrivacyCombinedController_iOS = _Class("OBPrivacyCombinedController_iOS")
OBNavigationController = _Class("OBNavigationController")
OBPrivacyModalNavigationController = _Class("OBPrivacyModalNavigationController")
