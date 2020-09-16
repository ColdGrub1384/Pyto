'''
Classes from the 'RemoteUI' framework.
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

    
RUINavBarSpinnerManager = _Class('RUINavBarSpinnerManager')
RUISpinnerRecord = _Class('RUISpinnerRecord')
RUISelectOption = _Class('RUISelectOption')
RUIParser = _Class('RUIParser')
RemoteUIController = _Class('RemoteUIController')
RUIObjectModel = _Class('RUIObjectModel')
_RUILoaderSessionDelegateAdapter = _Class('_RUILoaderSessionDelegateAdapter')
RUIHTTPRequest = _Class('RUIHTTPRequest')
RUILoader = _Class('RUILoader')
RUIImageLoader = _Class('RUIImageLoader')
RUIImageLoad = _Class('RUIImageLoad')
RUIActionSignal = _Class('RUIActionSignal')
RUIStyle = _Class('RUIStyle')
RUIFrontRowStyle = _Class('RUIFrontRowStyle')
RUISetupAssistantStyle = _Class('RUISetupAssistantStyle')
RUISetupAssistantModalStyle = _Class('RUISetupAssistantModalStyle')
RUIElement = _Class('RUIElement')
RUIHTMLFooterElement = _Class('RUIHTMLFooterElement')
RUIHeaderElement = _Class('RUIHeaderElement')
RUIBarButtonItem = _Class('RUIBarButtonItem')
RUITableViewRow = _Class('RUITableViewRow')
RUISubHeaderElement = _Class('RUISubHeaderElement')
RUITableViewSection = _Class('RUITableViewSection')
RUIWebView = _Class('RUIWebView')
RUITableView = _Class('RUITableView')
RUIDetailHeaderElement = _Class('RUIDetailHeaderElement')
RUISpinnerView = _Class('RUISpinnerView')
RUIChoice = _Class('RUIChoice')
RUIAlertView = _Class('RUIAlertView')
RUIPasscodeView = _Class('RUIPasscodeView')
RUIPageElement = _Class('RUIPageElement')
RUIDetailButtonElement = _Class('RUIDetailButtonElement')
RUIAlertButton = _Class('RUIAlertButton')
RUIHTMLHeaderElement = _Class('RUIHTMLHeaderElement')
RUIMultiChoiceElement = _Class('RUIMultiChoiceElement')
RUIChoiceViewElement = _Class('RUIChoiceViewElement')
RUIFooterElement = _Class('RUIFooterElement')
RUIScriptingStaticFunction = _Class('RUIScriptingStaticFunction')
RUIScriptingStaticValue = _Class('RUIScriptingStaticValue')
RUIPlatform = _Class('RUIPlatform')
RUIBarButtonSpinnerView = _Class('RUIBarButtonSpinnerView')
RUIHalfSheetDetent = _Class('RUIHalfSheetDetent')
RUIModalPresentationController = _Class('RUIModalPresentationController')
RUIMultiChoiceView = _Class('RUIMultiChoiceView')
RUIHTMLHeaderView = _Class('RUIHTMLHeaderView')
RUILinkLabel = _Class('RUILinkLabel')
RUIPrivacyLinkContainerView = _Class('RUIPrivacyLinkContainerView')
RUIWebContainerView = _Class('RUIWebContainerView')
RUIReadableContentContainer = _Class('RUIReadableContentContainer')
RUIHTMLFooterView = _Class('RUIHTMLFooterView')
RemoteUISectionFooter = _Class('RemoteUISectionFooter')
RemoteUILinkFooter = _Class('RemoteUILinkFooter')
RUIChoiceView = _Class('RUIChoiceView')
RUIHeaderView = _Class('RUIHeaderView')
RUIModernHeaderView = _Class('RUIModernHeaderView')
RUITableViewHeaderFooterView = _Class('RUITableViewHeaderFooterView')
RemoteUITableViewCell = _Class('RemoteUITableViewCell')
RemoteUITableViewSubtitleAndValueCell = _Class('RemoteUITableViewSubtitleAndValueCell')
RUIVariableHeightCell = _Class('RUIVariableHeightCell')
RemoteUIWebViewController = _Class('RemoteUIWebViewController')
RUIPage = _Class('RUIPage')
RUINavigationController = _Class('RUINavigationController')
