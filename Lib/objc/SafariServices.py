"""
Classes from the 'SafariServices' framework.
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


SFQueueingServiceViewControllerProxy = _Class("SFQueueingServiceViewControllerProxy")
_SFSafariSharingExtensionController = _Class("_SFSafariSharingExtensionController")
SFCustomActivityProxy = _Class("SFCustomActivityProxy")
_SFBarManager = _Class("_SFBarManager")
_SFBarItemConfiguration = _Class("_SFBarItemConfiguration")
_SFDownload = _Class("_SFDownload")
_SFKeyboardGeometry = _Class("_SFKeyboardGeometry")
_SFWebProcessSharingLinkExtractor = _Class("_SFWebProcessSharingLinkExtractor")
SFContentBlockerState = _Class("SFContentBlockerState")
SFHighPriorityRecommendationData = _Class("SFHighPriorityRecommendationData")
_SFDropSession = _Class("_SFDropSession")
_SFClipLink = _Class("_SFClipLink")
SFSafariViewControllerConfiguration = _Class("SFSafariViewControllerConfiguration")
_SFMicrodataExtractor = _Class("_SFMicrodataExtractor")
_SFPopoverPresentationDelegate = _Class("_SFPopoverPresentationDelegate")
SFNavigationBarMetrics = _Class("SFNavigationBarMetrics")
_SFSearchEngineController = _Class("_SFSearchEngineController")
_SFNavigationResult = _Class("_SFNavigationResult")
_SFQuickLookDocumentWriter = _Class("_SFQuickLookDocumentWriter")
_SFRequestDesktopSiteQuirksManager = _Class("_SFRequestDesktopSiteQuirksManager")
_SFDownloadDispatcher = _Class("_SFDownloadDispatcher")
_SFSafariDataSharingController = _Class("_SFSafariDataSharingController")
_SFSharingLinkExtractor = _Class("_SFSharingLinkExtractor")
_SFDownloadManager = _Class("_SFDownloadManager")
_SFDownloadIconCache = _Class("_SFDownloadIconCache")
SFTelephonyURLHandler = _Class("SFTelephonyURLHandler")
SFTelephonyURLRequest = _Class("SFTelephonyURLRequest")
SFDownloadFile = _Class("SFDownloadFile")
_SFSaveToFilesOperation = _Class("_SFSaveToFilesOperation")
_SFPerSitePreferencesUtilities = _Class("_SFPerSitePreferencesUtilities")
_SFPasswordPickerTableConfiguration = _Class("_SFPasswordPickerTableConfiguration")
_SFSecIdentityPreferencesController = _Class("_SFSecIdentityPreferencesController")
_SFDialogController = _Class("_SFDialogController")
_SFSectionModel = _Class("_SFSectionModel")
_SFBannerModel = _Class("_SFBannerModel")
_SFSectionAction = _Class("_SFSectionAction")
SFFormAutoFillFrame = _Class("SFFormAutoFillFrame")
_SFOpenInOtherAppActivityItemsSource = _Class("_SFOpenInOtherAppActivityItemsSource")
_SFClass = _Class("_SFClass")
_SFQuickLookDocument = _Class("_SFQuickLookDocument")
_SFInjectedJavaScriptController = _Class("_SFInjectedJavaScriptController")
_SFBrowserSavedState = _Class("_SFBrowserSavedState")
_SFReloadOptionsController = _Class("_SFReloadOptionsController")
_SFWebClipMetadataFetcher = _Class("_SFWebClipMetadataFetcher")
_SFUnresponsiveWebProcessController = _Class("_SFUnresponsiveWebProcessController")
SFFolderPickerList = _Class("SFFolderPickerList")
_SFFolderPickerItem = _Class("_SFFolderPickerItem")
_SFSettingsAuthentication = _Class("_SFSettingsAuthentication")
_SFMailContentProvider = _Class("_SFMailContentProvider")
_SFSiteIcon = _Class("_SFSiteIcon")
SFAutoFillAuthenticationUtilities = _Class("SFAutoFillAuthenticationUtilities")
_SFQRCodeDetectionController = _Class("_SFQRCodeDetectionController")
_SFAuthenticationContext = _Class("_SFAuthenticationContext")
_SFUIViewPopoverSourceInfo = _Class("_SFUIViewPopoverSourceInfo")
_SFBrowserWindowStateData = _Class("_SFBrowserWindowStateData")
SFBrowserStateSQLiteStore = _Class("SFBrowserStateSQLiteStore")
_SFNavigationUtilitiesManager = _Class("_SFNavigationUtilitiesManager")
SFProcessDictionary = _Class("SFProcessDictionary")
_SFRequestDesktopSiteQuirksSnapshot = _Class("_SFRequestDesktopSiteQuirksSnapshot")
_SFNavigationIntentBuilder = _Class("_SFNavigationIntentBuilder")
SFCertificateWarningJSController = _Class("SFCertificateWarningJSController")
SFWebProcessPlugInCertificateWarningController = _Class(
    "SFWebProcessPlugInCertificateWarningController"
)
_SFApplicationManifestFetcher = _Class("_SFApplicationManifestFetcher")
_SFSharablePasswordReceiver = _Class("_SFSharablePasswordReceiver")
_SFNavigationIntent = _Class("_SFNavigationIntent")
_SFReaderExtractor = _Class("_SFReaderExtractor")
_SFActivityItemCustomizationController = _Class(
    "_SFActivityItemCustomizationController"
)
_SFNavigationBarItem = _Class("_SFNavigationBarItem")
_SFReaderTextSizeStepperController = _Class("_SFReaderTextSizeStepperController")
_SFPageZoomStepperController = _Class("_SFPageZoomStepperController")
_SFPageFormatMenuController = _Class("_SFPageFormatMenuController")
_SFLinkRedirectionResolver = _Class("_SFLinkRedirectionResolver")
_SFBrowserConfiguration = _Class("_SFBrowserConfiguration")
_SFSettingsAlertItem = _Class("_SFSettingsAlertItem")
_SFDynamicBarAnimator = _Class("_SFDynamicBarAnimator")
SFCredentialDisplayData = _Class("SFCredentialDisplayData")
SFDialogAction = _Class("SFDialogAction")
_SFPerSitePreferencesSection = _Class("_SFPerSitePreferencesSection")
_SFAutomaticTabClosingUtilities = _Class("_SFAutomaticTabClosingUtilities")
_SFBarHoverAssistant = _Class("_SFBarHoverAssistant")
_SFReaderCustomProtocols = _Class("_SFReaderCustomProtocols")
SFWebProcessPlugInPageExtensionController = _Class(
    "SFWebProcessPlugInPageExtensionController"
)
SFBlockBasedCAAnimationDelegate = _Class("SFBlockBasedCAAnimationDelegate")
SFUIBarButtonItemPopoverSourceInfo = _Class("SFUIBarButtonItemPopoverSourceInfo")
SFWatchMetrics = _Class("SFWatchMetrics")
_SFPerSitePreferencePopoverDisplayInformation = _Class(
    "_SFPerSitePreferencePopoverDisplayInformation"
)
SFFormAutocompleteState = _Class("SFFormAutocompleteState")
_SFCalendarEventDetector = _Class("_SFCalendarEventDetector")
_SFWebViewUsageMonitor = _Class("_SFWebViewUsageMonitor")
_SFLinkPresentationIconCache = _Class("_SFLinkPresentationIconCache")
_SFURLLabelAccessoryItem = _Class("_SFURLLabelAccessoryItem")
SFContactAutoFillValue = _Class("SFContactAutoFillValue")
_SFBrowserWindowSettings = _Class("_SFBrowserWindowSettings")
_SFQuickLookDocumentController = _Class("_SFQuickLookDocumentController")
_SFAutomationController = _Class("_SFAutomationController")
_SFReaderFontOptionsGroupController = _Class("_SFReaderFontOptionsGroupController")
_SFPasswordIconController = _Class("_SFPasswordIconController")
_SFPerSitePreferenceDisplayInformation = _Class(
    "_SFPerSitePreferenceDisplayInformation"
)
SFSystemAlert = _Class("SFSystemAlert")
_SFManagedFeatureObserver = _Class("_SFManagedFeatureObserver")
_SFLinkPreviewHelper = _Class("_SFLinkPreviewHelper")
SFPrivacyReportGridRowLayoutInfo = _Class("SFPrivacyReportGridRowLayoutInfo")
_SFDialog = _Class("_SFDialog")
SFWebUIDialog = _Class("SFWebUIDialog")
SFBasicDialog = _Class("SFBasicDialog")
SFAuthenticatorDialog = _Class("SFAuthenticatorDialog")
_SFOpenURLOperationDelegate = _Class("_SFOpenURLOperationDelegate")
SFBrowserPersonaAnalyticsHelper = _Class("SFBrowserPersonaAnalyticsHelper")
SFContactAutoFillPropertyValues = _Class("SFContactAutoFillPropertyValues")
_SFReaderExtractedData = _Class("_SFReaderExtractedData")
_SFFormAutoFillController = _Class("_SFFormAutoFillController")
SFStartPageBookmarkFolderDataSource = _Class("SFStartPageBookmarkFolderDataSource")
_SFReaderController = _Class("_SFReaderController")
_SFBarTheme = _Class("_SFBarTheme")
_SFNavigationBarTheme = _Class("_SFNavigationBarTheme")
SFLocationManager = _Class("SFLocationManager")
_SFPerSitePreferencesVendor = _Class("_SFPerSitePreferencesVendor")
_SFStoreBannerTracker = _Class("_SFStoreBannerTracker")
SFBrowserDocumentTrackerInfo = _Class("SFBrowserDocumentTrackerInfo")
_SFBrowserKeyCommands = _Class("_SFBrowserKeyCommands")
_SFMediaCaptureStatusBarManager = _Class("_SFMediaCaptureStatusBarManager")
_SFWebAppMediaCaptureStatusBarManager = _Class("_SFWebAppMediaCaptureStatusBarManager")
SFPrintQueueItem = _Class("SFPrintQueueItem")
_SFPrintController = _Class("_SFPrintController")
SFFormAutoFillFrameHandle = _Class("SFFormAutoFillFrameHandle")
_SFPasswordManagerAppearanceValues = _Class("_SFPasswordManagerAppearanceValues")
SFNavigationBarAccessoryButtonArrangement = _Class(
    "SFNavigationBarAccessoryButtonArrangement"
)
_SFWebArchiveProvider = _Class("_SFWebArchiveProvider")
_SFUserActivityController = _Class("_SFUserActivityController")
SFContentBlockerManager = _Class("SFContentBlockerManager")
_SFActivityItemProviderCollection = _Class("_SFActivityItemProviderCollection")
SFFormAutoFillNode = _Class("SFFormAutoFillNode")
_SFDownloadStorageUsageMonitor = _Class("_SFDownloadStorageUsageMonitor")
SFDownloadStorageUsageMonitorEntry = _Class("SFDownloadStorageUsageMonitorEntry")
_SFTabStateData = _Class("_SFTabStateData")
SFAuthenticationSession = _Class("SFAuthenticationSession")
_SFPageLoadErrorController = _Class("_SFPageLoadErrorController")
_SFPageFormatMenuPrivacyReportController = _Class(
    "_SFPageFormatMenuPrivacyReportController"
)
SFFormsMetadataProvider = _Class("SFFormsMetadataProvider")
_SFBookmarksLockCoordinator = _Class("_SFBookmarksLockCoordinator")
SFPrivacyReportItem = _Class("SFPrivacyReportItem")
_SFFormAutoFillInputSession = _Class("_SFFormAutoFillInputSession")
SSReadingList = _Class("SSReadingList")
SFHighPriorityRecommendationCellID = _Class("SFHighPriorityRecommendationCellID")
_SFSyntheticClickContext = _Class("_SFSyntheticClickContext")
_SFTelephonyNavigationMitigationPolicy = _Class(
    "_SFTelephonyNavigationMitigationPolicy"
)
SFPasswordCellData = _Class("SFPasswordCellData")
_SFPasswordTableConfiguration = _Class("_SFPasswordTableConfiguration")
_SFSearchEngineInfo = _Class("_SFSearchEngineInfo")
_SFWebProcessPlugIn = _Class("_SFWebProcessPlugIn")
_SFTouchIconCache = _Class("_SFTouchIconCache")
_SFPasswordTouchIconCache = _Class("_SFPasswordTouchIconCache")
_SFWebProcessPlugInPageController = _Class("_SFWebProcessPlugInPageController")
_SFWebProcessPlugInAutoFillPageController = _Class(
    "_SFWebProcessPlugInAutoFillPageController"
)
_SFWebProcessPlugInReaderEnabledPageController = _Class(
    "_SFWebProcessPlugInReaderEnabledPageController"
)
_SFReaderWebProcessPlugInPageController = _Class(
    "_SFReaderWebProcessPlugInPageController"
)
_SFSiteMetadataManager = _Class("_SFSiteMetadataManager")
_SFFaviconProvider = _Class("_SFFaviconProvider")
_SFPasswordTouchIconRequest = _Class("_SFPasswordTouchIconRequest")
SFBookmarkTouchIconRequest = _Class("SFBookmarkTouchIconRequest")
_SFBookmarkFolderTouchIconProvider = _Class("_SFBookmarkFolderTouchIconProvider")
SFFeatureManager = _Class("SFFeatureManager")
_SFFeatureAvailability = _Class("_SFFeatureAvailability")
_SSURLCompletionSession = _Class("_SSURLCompletionSession")
_SFRecentWebSearchesController = _Class("_SFRecentWebSearchesController")
SFSingleCreditCardData = _Class("SFSingleCreditCardData")
_SSHistoryAccessSession = _Class("_SSHistoryAccessSession")
_SFFormMetadataController = _Class("_SFFormMetadataController")
_SFFormDataController = _Class("_SFFormDataController")
_SFRequestDesktopSitePreferenceManager = _Class(
    "_SFRequestDesktopSitePreferenceManager"
)
_SFUserMediaPermissionController = _Class("_SFUserMediaPermissionController")
_SFPageZoomPreferenceManager = _Class("_SFPageZoomPreferenceManager")
_SFContentBlockersPreferenceManager = _Class("_SFContentBlockersPreferenceManager")
_SFGeolocationPermissionManager = _Class("_SFGeolocationPermissionManager")
_SFRequestDesktopSiteQuirksSnapshotTransformer = _Class(
    "_SFRequestDesktopSiteQuirksSnapshotTransformer"
)
_SFTextSuggestion = _Class("_SFTextSuggestion")
_SFTableViewDiffableDataSource = _Class("_SFTableViewDiffableDataSource")
_SFFolderPickerTableViewCellLayoutManager = _Class(
    "_SFFolderPickerTableViewCellLayoutManager"
)
SFPrintPageRenderer = _Class("SFPrintPageRenderer")
SFMultipleLineAlertAction = _Class("SFMultipleLineAlertAction")
_SFOpenWithAppUIActivity = _Class("_SFOpenWithAppUIActivity")
_SFActivity = _Class("_SFActivity")
SFKillSafariViewServiceActivity = _Class("SFKillSafariViewServiceActivity")
_SFAddBookmarkActivity = _Class("_SFAddBookmarkActivity")
_SFFindOnPageUIActivity = _Class("_SFFindOnPageUIActivity")
SFSaveToFilesActivity = _Class("SFSaveToFilesActivity")
SFHostApplicationCustomActivity = _Class("SFHostApplicationCustomActivity")
_SFKillWebContentProcessUIActivity = _Class("_SFKillWebContentProcessUIActivity")
_SFDownloadCurrentPageActivity = _Class("_SFDownloadCurrentPageActivity")
SFInteractiveDismissController = _Class("SFInteractiveDismissController")
SFKBScreenTraits = _Class("SFKBScreenTraits")
SFDownloadsBarButtonItem = _Class("SFDownloadsBarButtonItem")
SFBarButtonItemLongPressGestureRecognizer = _Class(
    "SFBarButtonItemLongPressGestureRecognizer"
)
SFToggleBackgroundLayer = _Class("SFToggleBackgroundLayer")
_SFTouchIconFetchOperation = _Class("_SFTouchIconFetchOperation")
_SFActivityItemProvider = _Class("_SFActivityItemProvider")
_SFImageActivityItemProvider = _Class("_SFImageActivityItemProvider")
_SFPrintActivityItemProvider = _Class("_SFPrintActivityItemProvider")
_SFDownloadActivityItemProvider = _Class("_SFDownloadActivityItemProvider")
_SFLinkWithPreviewActivityItemProvider = _Class(
    "_SFLinkWithPreviewActivityItemProvider"
)
_SFActivityExtensionItemProvider = _Class("_SFActivityExtensionItemProvider")
_SFWebArchiveActivityItemProvider = _Class("_SFWebArchiveActivityItemProvider")
SFBarRegistration = _Class("SFBarRegistration")
SFAutomaticPasswordExplanationView = _Class("SFAutomaticPasswordExplanationView")
SFAutomaticPasswordScrollViewContentView = _Class(
    "SFAutomaticPasswordScrollViewContentView"
)
SFQRImageContentView = _Class("SFQRImageContentView")
SFQRImageHeaderView = _Class("SFQRImageHeaderView")
_SFQuickLookDocumentInfoView = _Class("_SFQuickLookDocumentInfoView")
SFDialogTextView = _Class("SFDialogTextView")
_SFDialogView = _Class("_SFDialogView")
SFPrivacyReportExplanationDetailItemView = _Class(
    "SFPrivacyReportExplanationDetailItemView"
)
SFPrivacyReportMeterBar = _Class("SFPrivacyReportMeterBar")
SFSafariLaunchPlaceholderView = _Class("SFSafariLaunchPlaceholderView")
SFNanoDomainContainerView = _Class("SFNanoDomainContainerView")
SFSafariView = _Class("SFSafariView")
_SFSettingsAlertCustomViewContainer = _Class("_SFSettingsAlertCustomViewContainer")
_SFSettingsAlertItemBackgroundView = _Class("_SFSettingsAlertItemBackgroundView")
_SFHairlineBorderView = _Class("_SFHairlineBorderView")
_SFSiteIconView = _Class("_SFSiteIconView")
SFReaderAppearanceThemeSelector = _Class("SFReaderAppearanceThemeSelector")
SFDomainLabel = _Class("SFDomainLabel")
SFPrivacyReportOverviewCellContentView = _Class(
    "SFPrivacyReportOverviewCellContentView"
)
_SFLinkPreviewHeader = _Class("_SFLinkPreviewHeader")
SFSiteCardSourceView = _Class("SFSiteCardSourceView")
SFToggleBackgroundView = _Class("SFToggleBackgroundView")
_SFPasswordManagerLockedView = _Class("_SFPasswordManagerLockedView")
_SFReaderFontDownloadAccessory = _Class("_SFReaderFontDownloadAccessory")
SFPrivacyReportIconView = _Class("SFPrivacyReportIconView")
_SFFindOnPageView = _Class("_SFFindOnPageView")
SFPrivacyReportGridView = _Class("SFPrivacyReportGridView")
SFPrivacyReportExplanationDetailView = _Class("SFPrivacyReportExplanationDetailView")
SFPrivacyReportOverviewView = _Class("SFPrivacyReportOverviewView")
_SFTranslationTargetLocaleAlertActionContentView = _Class(
    "_SFTranslationTargetLocaleAlertActionContentView"
)
SFDialogContentView = _Class("SFDialogContentView")
SFToolbarContainer = _Class("SFToolbarContainer")
_SFCrashBanner = _Class("_SFCrashBanner")
_SFNavigationBar = _Class("_SFNavigationBar")
_SFBrowserNavigationBar = _Class("_SFBrowserNavigationBar")
_SFNavigationBarLabelsContainer = _Class("_SFNavigationBarLabelsContainer")
_SFURLTextPreviewView = _Class("_SFURLTextPreviewView")
_SFPinnableBanner = _Class("_SFPinnableBanner")
_SFStoreBanner = _Class("_SFStoreBanner")
_SFLinkBanner = _Class("_SFLinkBanner")
_SFAppLinkBanner = _Class("_SFAppLinkBanner")
_SFClipLinkBanner = _Class("_SFClipLinkBanner")
_SFBrowserView = _Class("_SFBrowserView")
_SFKeyboardLayoutAlignmentView = _Class("_SFKeyboardLayoutAlignmentView")
_SFMultipleLineAlertActionView = _Class("_SFMultipleLineAlertActionView")
_SFFluidProgressView = _Class("_SFFluidProgressView")
SFAutomaticPasswordInputView = _Class("SFAutomaticPasswordInputView")
_SFFindOnPageToolbar = _Class("_SFFindOnPageToolbar")
_SFAutoFillInputView = _Class("_SFAutoFillInputView")
_SFQuickLookDocumentView = _Class("_SFQuickLookDocumentView")
_SFSecurityRecommendationsDrillInTableViewCell = _Class(
    "_SFSecurityRecommendationsDrillInTableViewCell"
)
SFContactAutoFillTableViewCell = _Class("SFContactAutoFillTableViewCell")
SFSecurityRecommendationInfoCell = _Class("SFSecurityRecommendationInfoCell")
SFPrivacyReportTrackingTableViewCell = _Class("SFPrivacyReportTrackingTableViewCell")
SFPrivacyReportWebsiteTableViewCell = _Class("SFPrivacyReportWebsiteTableViewCell")
SFPrivacyReportTrackerTableViewCell = _Class("SFPrivacyReportTrackerTableViewCell")
SFPasswordTableViewCell = _Class("SFPasswordTableViewCell")
SFPrivacyReportExplanationTableViewCell = _Class(
    "SFPrivacyReportExplanationTableViewCell"
)
SFSwitchTableViewCell = _Class("SFSwitchTableViewCell")
SFPrivacyReportGridTableViewCell = _Class("SFPrivacyReportGridTableViewCell")
SFPrivacyReportSubheaderTableViewCell = _Class("SFPrivacyReportSubheaderTableViewCell")
SFPasswordBreachToggleCell = _Class("SFPasswordBreachToggleCell")
SFEditableTableViewCell = _Class("SFEditableTableViewCell")
SFPrivacyReportDetailToggleTableViewCell = _Class(
    "SFPrivacyReportDetailToggleTableViewCell"
)
_SFBookmarkTextEntryTableViewCell = _Class("_SFBookmarkTextEntryTableViewCell")
SFStartPageSectionHeader = _Class("SFStartPageSectionHeader")
SFBannerCell = _Class("SFBannerCell")
SFSiteIconCell = _Class("SFSiteIconCell")
SFSiteCardCell = _Class("SFSiteCardCell")
SFPrivacyReportGridItemCell = _Class("SFPrivacyReportGridItemCell")
_SFToolbar = _Class("_SFToolbar")
_SFOptionsGroupDetailLabel = _Class("_SFOptionsGroupDetailLabel")
_SFFindOnPageInputBar = _Class("_SFFindOnPageInputBar")
_SFNavigationBarURLButtonBackgroundView = _Class(
    "_SFNavigationBarURLButtonBackgroundView"
)
_SFVibrantSeparatorView = _Class("_SFVibrantSeparatorView")
SFVibrantCellSelectionBackgroundView = _Class("SFVibrantCellSelectionBackgroundView")
_SFSettingsAlertControl = _Class("_SFSettingsAlertControl")
_SFSettingsAlertStepper = _Class("_SFSettingsAlertStepper")
_SFSettingsAlertButton = _Class("_SFSettingsAlertButton")
SFDialogTextField = _Class("SFDialogTextField")
SFDismissButton = _Class("SFDismissButton")
SFDownloadsBarButtonItemView = _Class("SFDownloadsBarButtonItemView")
SFNavigationBarToggleButton = _Class("SFNavigationBarToggleButton")
_SFAutoFillInputViewButton = _Class("_SFAutoFillInputViewButton")
_SFDimmingButton = _Class("_SFDimmingButton")
SFLinkPreviewHeaderContentView = _Class("SFLinkPreviewHeaderContentView")
_SFNavigationBarURLButton = _Class("_SFNavigationBarURLButton")
_SFCompressedBarButton = _Class("_SFCompressedBarButton")
_SFWebsiteButton = _Class("_SFWebsiteButton")
_SFWebView = _Class("_SFWebView")
_SFQRImagePreviewViewController = _Class("_SFQRImagePreviewViewController")
_SFStartPageViewController = _Class("_SFStartPageViewController")
_SFSettingsAlertContentController = _Class("_SFSettingsAlertContentController")
_SFSettingsAlertController = _Class("_SFSettingsAlertController")
SFStartPageCollectionViewController = _Class("SFStartPageCollectionViewController")
SFWebViewController = _Class("SFWebViewController")
SFReaderEnabledWebViewController = _Class("SFReaderEnabledWebViewController")
SFPasswordServiceViewController = _Class("SFPasswordServiceViewController")
SFExternalPasswordCredentialServiceViewController = _Class(
    "SFExternalPasswordCredentialServiceViewController"
)
SFPasswordSavingServiceViewController = _Class("SFPasswordSavingServiceViewController")
SFPasswordPickerServiceViewController = _Class("SFPasswordPickerServiceViewController")
_SFBrowserContentViewController = _Class("_SFBrowserContentViewController")
SFBrowserServiceViewController = _Class("SFBrowserServiceViewController")
_SFWebAppServiceViewController = _Class("_SFWebAppServiceViewController")
_SFTranslationTargetLocaleAlertActionContentViewController = _Class(
    "_SFTranslationTargetLocaleAlertActionContentViewController"
)
_SFAdaptivePreviewViewController = _Class("_SFAdaptivePreviewViewController")
_SFPasswordViewController = _Class("_SFPasswordViewController")
_SFAppAutoFillPasswordViewController = _Class("_SFAppAutoFillPasswordViewController")
_SFAppPasswordSavingViewController = _Class("_SFAppPasswordSavingViewController")
_SFExternalPasswordCredentialViewController = _Class(
    "_SFExternalPasswordCredentialViewController"
)
_SFMultipleLineAlertActionViewController = _Class(
    "_SFMultipleLineAlertActionViewController"
)
SFReaderViewController = _Class("SFReaderViewController")
_SFDigitalHealthViewController = _Class("_SFDigitalHealthViewController")
SFPrivacyReportViewController = _Class("SFPrivacyReportViewController")
SFSafariViewController = _Class("SFSafariViewController")
SFAuthenticationViewController = _Class("SFAuthenticationViewController")
SFLinkRedirectionViewController = _Class("SFLinkRedirectionViewController")
_SFURLTextPreviewViewController = _Class("_SFURLTextPreviewViewController")
_SFPerSitePreferenceNotifyingListController = _Class(
    "_SFPerSitePreferenceNotifyingListController"
)
_SFActivityViewController = _Class("_SFActivityViewController")
_SFOpenInOtherAppActivityViewController = _Class(
    "_SFOpenInOtherAppActivityViewController"
)
SFBrowserRemoteViewController = _Class("SFBrowserRemoteViewController")
_SFWebAppViewController = _Class("_SFWebAppViewController")
SFPasswordRemoteViewController = _Class("SFPasswordRemoteViewController")
SFExternalPasswordCredentialRemoteViewController = _Class(
    "SFExternalPasswordCredentialRemoteViewController"
)
SFPasswordSavingRemoteViewController = _Class("SFPasswordSavingRemoteViewController")
SFPasswordPickerRemoteViewController = _Class("SFPasswordPickerRemoteViewController")
_SFAutomaticPasswordInputViewController = _Class(
    "_SFAutomaticPasswordInputViewController"
)
_SFBookmarkTextEntryTableViewController = _Class(
    "_SFBookmarkTextEntryTableViewController"
)
SFAddPasswordViewController = _Class("SFAddPasswordViewController")
_SFPerSitePreferencesPopoverViewController = _Class(
    "_SFPerSitePreferencesPopoverViewController"
)
SFContactAutoFillViewController = _Class("SFContactAutoFillViewController")
SFPrivacyReportWebsiteDetailViewController = _Class(
    "SFPrivacyReportWebsiteDetailViewController"
)
_SFPopoverSizingTableViewController = _Class("_SFPopoverSizingTableViewController")
_SFBookmarkInfoViewController = _Class("_SFBookmarkInfoViewController")
SFPrivacyReportTrackerDetailViewController = _Class(
    "SFPrivacyReportTrackerDetailViewController"
)
SFContactAutoFillDetailViewController = _Class("SFContactAutoFillDetailViewController")
SFPasswordDetailViewController = _Class("SFPasswordDetailViewController")
_SFPasswordTableViewController = _Class("_SFPasswordTableViewController")
_SFPasswordPickerTableViewController = _Class("_SFPasswordPickerTableViewController")
_SFPasswordAuditingViewController = _Class("_SFPasswordAuditingViewController")
_SFEditablePasswordTableViewController = _Class(
    "_SFEditablePasswordTableViewController"
)
SFPasswordPickerViewController = _Class("SFPasswordPickerViewController")
_SFICSPreviewViewController = _Class("_SFICSPreviewViewController")
_SFContactPreviewViewController = _Class("_SFContactPreviewViewController")
_SFSingleBookmarkNavigationController = _Class("_SFSingleBookmarkNavigationController")
_SFCreditCardCaptureViewController = _Class("_SFCreditCardCaptureViewController")
SFPasswordAlertController = _Class("SFPasswordAlertController")
SFFormAutoFillMultipleLoginsAlertController = _Class(
    "SFFormAutoFillMultipleLoginsAlertController"
)
_SFTranslationTargetLocaleAlertController = _Class(
    "_SFTranslationTargetLocaleAlertController"
)
