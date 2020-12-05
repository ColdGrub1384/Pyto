"""
Classes from the 'AuthKitUI' framework.
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


AKAppleIDServerUIDataHarvester = _Class("AKAppleIDServerUIDataHarvester")
AKURLRequestApprover = _Class("AKURLRequestApprover")
AKInAppAuthenticationRemoteUIDelegate = _Class("AKInAppAuthenticationRemoteUIDelegate")
AKIDPHandler = _Class("AKIDPHandler")
AKInAppAuthenticationRemoteUIProvider = _Class("AKInAppAuthenticationRemoteUIProvider")
AKBasicLoginSecondFactorActions = _Class("AKBasicLoginSecondFactorActions")
AKBasicLoginActions = _Class("AKBasicLoginActions")
AKAuthorizationPaneContext = _Class("AKAuthorizationPaneContext")
AKAppleIDObjectModelFieldExtractor = _Class("AKAppleIDObjectModelFieldExtractor")
AKAuthorizationScopeChoices = _Class("AKAuthorizationScopeChoices")
AKAuthorizationSubPane = _Class("AKAuthorizationSubPane")
AKAuthorizationSubPanePrivacyLink = _Class("AKAuthorizationSubPanePrivacyLink")
AKAuthorizationSubPaneConfirmButton = _Class("AKAuthorizationSubPaneConfirmButton")
AKAuthorizationSubPaneInfoLabel = _Class("AKAuthorizationSubPaneInfoLabel")
AKAuthorizationSubPaneImage = _Class("AKAuthorizationSubPaneImage")
AKAuthorizationBulletPointSubPane = _Class("AKAuthorizationBulletPointSubPane")
AKAuthorizationContainerViewControllerAnimator = _Class(
    "AKAuthorizationContainerViewControllerAnimator"
)
AKSizing = _Class("AKSizing")
AKAppleIDServerUIContextController = _Class("AKAppleIDServerUIContextController")
AKIcon = _Class("AKIcon")
AKCAReporter = _Class("AKCAReporter")
AKCATiburonRequestReporter = _Class("AKCATiburonRequestReporter")
AKCATiburonAuthorizationUIReporter = _Class("AKCATiburonAuthorizationUIReporter")
AKCASatoriReporter = _Class("AKCASatoriReporter")
AKCATiburonPasswordUIReporter = _Class("AKCATiburonPasswordUIReporter")
AKCAPiggybackReporter = _Class("AKCAPiggybackReporter")
AKCATiburonInputUIReporter = _Class("AKCATiburonInputUIReporter")
AKCATiburonRequestAttemptReporter = _Class("AKCATiburonRequestAttemptReporter")
AKRoundedPath = _Class("AKRoundedPath")
AKCurvePoint = _Class("AKCurvePoint")
AKAppleIDAuthenticationInAppContext = _Class("AKAppleIDAuthenticationInAppContext")
AKAppleIDAuthenticationPurpleBuddyContext = _Class(
    "AKAppleIDAuthenticationPurpleBuddyContext"
)
AKAppleIDAuthenticationInAppExtensionContext = _Class(
    "AKAppleIDAuthenticationInAppExtensionContext"
)
AKAppleIDAuthenticationWatchBuddyContext = _Class(
    "AKAppleIDAuthenticationWatchBuddyContext"
)
AKAppleIDAuthenticationUISurrogateContext = _Class(
    "AKAppleIDAuthenticationUISurrogateContext"
)
AKAuthHandlerUIImpl = _Class("AKAuthHandlerUIImpl")
AKAuthorizationBiometricImage = _Class("AKAuthorizationBiometricImage")
AKAuthorizationNameFormatter = _Class("AKAuthorizationNameFormatter")
AKTextField = _Class("AKTextField")
AKBasicLoginContentViewControllerContainerView = _Class(
    "AKBasicLoginContentViewControllerContainerView"
)
AKCodeEntryView = _Class("AKCodeEntryView")
AKAuthorizationPasswordRequestViewCell = _Class(
    "AKAuthorizationPasswordRequestViewCell"
)
AKAuthorizationScopeDetailTableViewCell = _Class(
    "AKAuthorizationScopeDetailTableViewCell"
)
AKBasicLoginTableViewCell = _Class("AKBasicLoginTableViewCell")
AKAuthorizationLoginChoiceCell = _Class("AKAuthorizationLoginChoiceCell")
AKAuthorizationTwoLineTableViewCell = _Class("AKAuthorizationTwoLineTableViewCell")
AKAuthorizationScopeEditTableViewCell = _Class("AKAuthorizationScopeEditTableViewCell")
AKAuthorizationButton = _Class("AKAuthorizationButton")
AKAuthorizationAppleIDButton = _Class("AKAuthorizationAppleIDButton")
AKAuthorizationContinueButton = _Class("AKAuthorizationContinueButton")
_AKInsetTextField = _Class("_AKInsetTextField")
AKRoundedButton = _Class("AKRoundedButton")
AKTextualLinkButton = _Class("AKTextualLinkButton")
AKBaseSignInViewController = _Class("AKBaseSignInViewController")
AKModalSignInViewController = _Class("AKModalSignInViewController")
AKInlineSignInViewController = _Class("AKInlineSignInViewController")
AKTapToSignInViewController = _Class("AKTapToSignInViewController")
AKBasicLoginOptionsViewController = _Class("AKBasicLoginOptionsViewController")
AKBasicLoginContentViewController = _Class("AKBasicLoginContentViewController")
AKAuthorizationViewController = _Class("AKAuthorizationViewController")
AKSecondFactorCodeEntryContentViewController = _Class(
    "AKSecondFactorCodeEntryContentViewController"
)
AKAuthorizationContainerViewController = _Class(
    "AKAuthorizationContainerViewController"
)
AKAuthorizationContaineriPhoneViewController = _Class(
    "AKAuthorizationContaineriPhoneViewController"
)
AKAuthorizationContaineriPadViewController = _Class(
    "AKAuthorizationContaineriPadViewController"
)
AKIDPProvidedSignInViewController = _Class("AKIDPProvidedSignInViewController")
AKAuthorizationPaneViewController = _Class("AKAuthorizationPaneViewController")
AKAuthorizationInputPaneViewController = _Class(
    "AKAuthorizationInputPaneViewController"
)
AKAuthorizationFirstTimePaneViewController = _Class(
    "AKAuthorizationFirstTimePaneViewController"
)
AKAuthorizationPasswordAuthenticationViewController = _Class(
    "AKAuthorizationPasswordAuthenticationViewController"
)
AKAuthorizationEmailEditPaneViewController = _Class(
    "AKAuthorizationEmailEditPaneViewController"
)
AKBasicLoginViewController = _Class("AKBasicLoginViewController")
AKAuthorizationNavigationController = _Class("AKAuthorizationNavigationController")
AKBasicLoginAlertController = _Class("AKBasicLoginAlertController")
