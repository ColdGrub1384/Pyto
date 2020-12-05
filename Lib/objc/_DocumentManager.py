"""
Classes from the 'DocumentManager' framework.
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


DOCConcreteLocation = _Class("DOCConcreteLocation")
DOCUserInterfaceStateStore = _Class("DOCUserInterfaceStateStore")
DOCSmartFolderDatabase = _Class("DOCSmartFolderDatabase")
DOCFrecencyBasedEvent = _Class("DOCFrecencyBasedEvent")
DOCHotFolderEvent = _Class("DOCHotFolderEvent")
DOCSmartFolderHit = _Class("DOCSmartFolderHit")
DOCTransitionUtils = _Class("DOCTransitionUtils")
UIDocumentBrowserActionDescriptor = _Class("UIDocumentBrowserActionDescriptor")
UIDocumentBrowserTransitionController = _Class("UIDocumentBrowserTransitionController")
DOCDocumentSource = _Class("DOCDocumentSource")
DOCSearchingDocumentSource = _Class("DOCSearchingDocumentSource")
DOCSourceSearchingContext = _Class("DOCSourceSearchingContext")
DOCErrorStore = _Class("DOCErrorStore")
DOCActivity = _Class("DOCActivity")
DOCDestructiveActivity = _Class("DOCDestructiveActivity")
DOCWeakProxy = _Class("DOCWeakProxy")
DOCItem = _Class("DOCItem")
DOCPromisedItem = _Class("DOCPromisedItem")
DOCExtensionInterface = _Class("DOCExtensionInterface")
DOCRemoteContext = _Class("DOCRemoteContext")
DOCKeyCommandRegistry = _Class("DOCKeyCommandRegistry")
DOCKeyboardFocusManager = _Class("DOCKeyboardFocusManager")
UIDocumentBrowserAction = _Class("UIDocumentBrowserAction")
DOCRemoteBarButton = _Class("DOCRemoteBarButton")
DOCRemoteUIBarButtonItem = _Class("DOCRemoteUIBarButtonItem")
DOCAppearance = _Class("DOCAppearance")
DOCSymbolicLocationURLWrapper = _Class("DOCSymbolicLocationURLWrapper")
DOCViewServiceErrorView = _Class("DOCViewServiceErrorView")
DOCRemoteBarButtonTrackingView = _Class("DOCRemoteBarButtonTrackingView")
DOCViewServiceErrorViewController = _Class("DOCViewServiceErrorViewController")
DOCDocBrowserVC_UIActivityViewController = _Class(
    "DOCDocBrowserVC_UIActivityViewController"
)
UIDocumentBrowserViewController = _Class("UIDocumentBrowserViewController")
DOCExportModeViewController = _Class("DOCExportModeViewController")
DOCRemoteViewController = _Class("DOCRemoteViewController")
DOCTargetSelectionBrowserViewController = _Class(
    "DOCTargetSelectionBrowserViewController"
)
