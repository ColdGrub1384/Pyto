"""
Classes from the 'ContactsUI' framework.
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


CNUIVCardUtilities = _Class("CNUIVCardUtilities")
CNActionMenuHelper = _Class("CNActionMenuHelper")
CNAvatarCardTransitionController = _Class("CNAvatarCardTransitionController")
CNAvatarCardTransition = _Class("CNAvatarCardTransition")
CNPhotoPickerConfiguration = _Class("CNPhotoPickerConfiguration")
CNPhotoPickerActionsViewControllerLayout = _Class(
    "CNPhotoPickerActionsViewControllerLayout"
)
CNPhotoPickerActionButtonBlockHandler = _Class("CNPhotoPickerActionButtonBlockHandler")
CNMeCardSharingAudienceDataSource = _Class("CNMeCardSharingAudienceDataSource")
CNPhotoPickerImageWithEffectGenerator = _Class("CNPhotoPickerImageWithEffectGenerator")
CNUIDataCollectorAggDLogger = _Class("CNUIDataCollectorAggDLogger")
CNOnboardingBoldButtonProvider = _Class("CNOnboardingBoldButtonProvider")
CNPhotoPickerAddItemsProvider = _Class("CNPhotoPickerAddItemsProvider")
CNUISchedulerProvider = _Class("CNUISchedulerProvider")
CNAvatarViewControllerSettings = _Class("CNAvatarViewControllerSettings")
CNContactHeaderViewSizeAttributes = _Class("CNContactHeaderViewSizeAttributes")
CNUIFamilyMemberContactsController = _Class("CNUIFamilyMemberContactsController")
CNContactAsyncDataSource = _Class("CNContactAsyncDataSource")
CNContactDataSourceSafeDelegate = _Class("CNContactDataSourceSafeDelegate")
CNUICoreApplicationAuthorizationItem = _Class("CNUICoreApplicationAuthorizationItem")
CNUINavigationListViewCellHeightEstimator = _Class(
    "CNUINavigationListViewCellHeightEstimator"
)
CNUIPropertyGroupItemIDSHandle = _Class("CNUIPropertyGroupItemIDSHandle")
CNContactSuggestionViewControllerLabeledValueDataSource = _Class(
    "CNContactSuggestionViewControllerLabeledValueDataSource"
)
CNSharingProfileOnboardingPhotoSelectionResult = _Class(
    "CNSharingProfileOnboardingPhotoSelectionResult"
)
CNQuickActionsUsageManager = _Class("CNQuickActionsUsageManager")
CNUINavigationListStyleProviderImpl = _Class("CNUINavigationListStyleProviderImpl")
CNUICarPlayNavigationListStyleProvider = _Class(
    "CNUICarPlayNavigationListStyleProvider"
)
CNUIPhoneNavigationListStyleProvider = _Class("CNUIPhoneNavigationListStyleProvider")
CNUINavigationListStyleProvider = _Class("CNUINavigationListStyleProvider")
CNToneKitPickerStyleProvider = _Class("CNToneKitPickerStyleProvider")
CNAvatarCardController = _Class("CNAvatarCardController")
CNAvatarPosePickerController = _Class("CNAvatarPosePickerController")
CNContactStoreDataSource = _Class("CNContactStoreDataSource")
CNContactStoreSnapshot = _Class("CNContactStoreSnapshot")
CNUIContactSaveResult = _Class("CNUIContactSaveResult")
CNUINavigationListItem = _Class("CNUINavigationListItem")
CNUIContactStoreExecutor = _Class("CNUIContactStoreExecutor")
CNUIFamilyMemberControllerShared = _Class("CNUIFamilyMemberControllerShared")
CNAccountsAndGroupsDataSource = _Class("CNAccountsAndGroupsDataSource")
CNAccountsAndGroupsItem = _Class("CNAccountsAndGroupsItem")
CNAccountsAndGroupsSection = _Class("CNAccountsAndGroupsSection")
CNContactTargetActionWrapper = _Class("CNContactTargetActionWrapper")
CNContactListStyleProvider = _Class("CNContactListStyleProvider")
CNContactListStyleDefautProvider = _Class("CNContactListStyleDefautProvider")
CNContactListStyleWrapperProvider = _Class("CNContactListStyleWrapperProvider")
CNSharingProfileLogger = _Class("CNSharingProfileLogger")
CNUIAccountsFacadeRequestRunner = _Class("CNUIAccountsFacadeRequestRunner")
CNUIAccountsFacade = _Class("CNUIAccountsFacade")
CNGroupIdentity = _Class("CNGroupIdentity")
CNUICoreRemoteApplicationIconLoader = _Class("CNUICoreRemoteApplicationIconLoader")
CNUIContactsEnvironmentServicesProvider = _Class(
    "CNUIContactsEnvironmentServicesProvider"
)
CNUIContactsEnvironment = _Class("CNUIContactsEnvironment")
CNUIDataCollectionSearchSession = _Class("CNUIDataCollectionSearchSession")
CNUINavigationListStyleApplier = _Class("CNUINavigationListStyleApplier")
CNSiriContactContextProvider = _Class("CNSiriContactContextProvider")
CNMeCardSharingContactNameProvider = _Class("CNMeCardSharingContactNameProvider")
CNBadgingAvatarViewController = _Class("CNBadgingAvatarViewController")
CNSharingProfileOnboardingFlowManager = _Class("CNSharingProfileOnboardingFlowManager")
CNPhotoPickerPhotoFacesProvider = _Class("CNPhotoPickerPhotoFacesProvider")
CNUIContactsAuthorizationController = _Class("CNUIContactsAuthorizationController")
CNShareContactActivityItem = _Class("CNShareContactActivityItem")
CNUIGeminiDataSource = _Class("CNUIGeminiDataSource")
CNUIColorRepository = _Class("CNUIColorRepository")
CNPropertyBestIDSValueQuery = _Class("CNPropertyBestIDSValueQuery")
CNPhotoPickerProviderGroupsBuilder = _Class("CNPhotoPickerProviderGroupsBuilder")
CNContactViewCache = _Class("CNContactViewCache")
CNShareLocationController = _Class("CNShareLocationController")
_CNAvatarImageProvider = _Class("_CNAvatarImageProvider")
CNVisualIdentityContactAvatarProvider = _Class("CNVisualIdentityContactAvatarProvider")
CNSharingProfilePhotoPickerItem = _Class("CNSharingProfilePhotoPickerItem")
CNMeCardSharingRowItem = _Class("CNMeCardSharingRowItem")
CNContactActionProvider = _Class("CNContactActionProvider")
CNMeCardSharingResult = _Class("CNMeCardSharingResult")
CNFeatureDefaults = _Class("CNFeatureDefaults")
CNPhotoPickerMonogramProvider = _Class("CNPhotoPickerMonogramProvider")
CNPhotoPickerCapabilities = _Class("CNPhotoPickerCapabilities")
CNContactActionsContext = _Class("CNContactActionsContext")
CNPhotoPickerEmojiProvider = _Class("CNPhotoPickerEmojiProvider")
CNUIFavoritesEntryPicker = _Class("CNUIFavoritesEntryPicker")
CNUIDataCollector = _Class("CNUIDataCollector")
CNUIEditAuthorizationController = _Class("CNUIEditAuthorizationController")
CNUnknownContactsController = _Class("CNUnknownContactsController")
CNContactSuggestionViewControllerSGOriginDataSource = _Class(
    "CNContactSuggestionViewControllerSGOriginDataSource"
)
CNContactCustomDataSource = _Class("CNContactCustomDataSource")
CNUIContactStoreLinkedContactSaveExecutor = _Class(
    "CNUIContactStoreLinkedContactSaveExecutor"
)
CNVCardImportController = _Class("CNVCardImportController")
CNMonogrammer = _Class("CNMonogrammer")
CNContactRecentsReference = _Class("CNContactRecentsReference")
CNSharingProfileAvatarItemProviderConfiguration = _Class(
    "CNSharingProfileAvatarItemProviderConfiguration"
)
CNPhotoPickerAccountPhotoProvider = _Class("CNPhotoPickerAccountPhotoProvider")
CNUIAfterCACommitScheduler = _Class("CNUIAfterCACommitScheduler")
TestCNUIUserActionContext = _Class("TestCNUIUserActionContext")
TestCNUIUserActionListDataSource = _Class("TestCNUIUserActionListDataSource")
CNTestQuickActionViewContainer = _Class("CNTestQuickActionViewContainer")
CNAvatarEditingManager = _Class("CNAvatarEditingManager")
CNVisualIdentityAvatarLayoutManager = _Class("CNVisualIdentityAvatarLayoutManager")
CNContactQuickActionsController = _Class("CNContactQuickActionsController")
CNSharingProfileAvatarItemProvider = _Class("CNSharingProfileAvatarItemProvider")
CNUIEditingSessionSaveExecutor = _Class("CNUIEditingSessionSaveExecutor")
CNHealthStoreManager = _Class("CNHealthStoreManager")
CNVisualIdentity = _Class("CNVisualIdentity")
CNAvatarStickerGeneratorProvider = _Class("CNAvatarStickerGeneratorProvider")
CNUIDraggingContacts = _Class("CNUIDraggingContacts")
CNContactFilter = _Class("CNContactFilter")
CNContactStoreFilter = _Class("CNContactStoreFilter")
CNMeCardSharingSettingsNameDataSource = _Class("CNMeCardSharingSettingsNameDataSource")
CNMeCardSharingDataSource = _Class("CNMeCardSharingDataSource")
CNUIFamilyMemberContactItem = _Class("CNUIFamilyMemberContactItem")
CNContactStyle = _Class("CNContactStyle")
CNPhotoPickerRecentsProvider = _Class("CNPhotoPickerRecentsProvider")
CNPhotoPickerProviderItem = _Class("CNPhotoPickerProviderItem")
CNPhotoPickerGlyphProviderItem = _Class("CNPhotoPickerGlyphProviderItem")
CNPhotoPickerMonogramProviderItem = _Class("CNPhotoPickerMonogramProviderItem")
CNPhotoPickerPhotoFacesProviderItem = _Class("CNPhotoPickerPhotoFacesProviderItem")
CNPhotoPickerEmojiProviderItem = _Class("CNPhotoPickerEmojiProviderItem")
CNPhotoPickerRecentsProviderItem = _Class("CNPhotoPickerRecentsProviderItem")
CNPhotoPickerAnimojiProviderItem = _Class("CNPhotoPickerAnimojiProviderItem")
CNPhotoPickerRecentAnimojiProviderItem = _Class(
    "CNPhotoPickerRecentAnimojiProviderItem"
)
CNNumberFormatting = _Class("CNNumberFormatting")
CNPropertyIDSRequest = _Class("CNPropertyIDSRequest")
CNPrivacyAdditions = _Class("CNPrivacyAdditions")
CNCustomCardAction = _Class("CNCustomCardAction")
CNSharingProfileAvatarItem = _Class("CNSharingProfileAvatarItem")
CNAvatarImageRenderer = _Class("CNAvatarImageRenderer")
CNUIFMFFacade = _Class("CNUIFMFFacade")
CNContactQuickActionsDisambiguationMenuPresentation = _Class(
    "CNContactQuickActionsDisambiguationMenuPresentation"
)
_CNContactQuickActionsAlertSheetDisambiguationMenuPresentation = _Class(
    "_CNContactQuickActionsAlertSheetDisambiguationMenuPresentation"
)
_CNContactQuickActionsModalDisambiguationMenuPresentation = _Class(
    "_CNContactQuickActionsModalDisambiguationMenuPresentation"
)
_CNUINavigationListViewPermissiveGestureRecognizerDelegate = _Class(
    "_CNUINavigationListViewPermissiveGestureRecognizerDelegate"
)
CNAvatarImageRendererSettings = _Class("CNAvatarImageRendererSettings")
CNAvatarCardControllerOrbTransition = _Class("CNAvatarCardControllerOrbTransition")
CNMeCardSharingContactAvatarProvider = _Class("CNMeCardSharingContactAvatarProvider")
CNUIFamilyMemberWhitelistedContactsController = _Class(
    "CNUIFamilyMemberWhitelistedContactsController"
)
CNSharingProfileOnboardingFlowResult = _Class("CNSharingProfileOnboardingFlowResult")
CNUIExternalComponentsFactory = _Class("CNUIExternalComponentsFactory")
CNAccountsAndGroupsStyle = _Class("CNAccountsAndGroupsStyle")
CNInsetGroupsAndAccountsStyle = _Class("CNInsetGroupsAndAccountsStyle")
CNOutlineGroupsAndAccountsStyle = _Class("CNOutlineGroupsAndAccountsStyle")
_CNCustomActionSheetPresentation = _Class("_CNCustomActionSheetPresentation")
CNCustomActionSheetPresentation = _Class("CNCustomActionSheetPresentation")
CNContactDataSourceLIFOScheduler = _Class("CNContactDataSourceLIFOScheduler")
CNPhotoPickerAnimojiProvider = _Class("CNPhotoPickerAnimojiProvider")
CNMeCardSharingPickerLayoutAttributes = _Class("CNMeCardSharingPickerLayoutAttributes")
CNKeyboardSettings = _Class("CNKeyboardSettings")
ABCountry = _Class("ABCountry")
CNPhotoPickerColorVariant = _Class("CNPhotoPickerColorVariant")
CNUIAAfamilyMember = _Class("CNUIAAfamilyMember")
CNMeCardSharingNameFormatter = _Class("CNMeCardSharingNameFormatter")
CNPhotoPickerDataSource = _Class("CNPhotoPickerDataSource")
CNMeCardSharingEnabledDataSource = _Class("CNMeCardSharingEnabledDataSource")
CNGroupIdentityInlineActionsViewConfiguration = _Class(
    "CNGroupIdentityInlineActionsViewConfiguration"
)
CNGroupIdentityActionItem = _Class("CNGroupIdentityActionItem")
CNUIContactSaveConfiguration = _Class("CNUIContactSaveConfiguration")
CNContactPhotoPreviewItem = _Class("CNContactPhotoPreviewItem")
CNSharingProfileAudienceDataSource = _Class("CNSharingProfileAudienceDataSource")
CNContactActionsController = _Class("CNContactActionsController")
CNUIStringUtilities = _Class("CNUIStringUtilities")
CNSharingProfileRowItem = _Class("CNSharingProfileRowItem")
CNAvatarImageRenderingScope = _Class("CNAvatarImageRenderingScope")
CNMeCardSharingOnboardingAvatarCarouselItem = _Class(
    "CNMeCardSharingOnboardingAvatarCarouselItem"
)
CNUIDataCollectorSGLogger = _Class("CNUIDataCollectorSGLogger")
CNUIToolbarItem = _Class("CNUIToolbarItem")
CNActionItem = _Class("CNActionItem")
CNContactListStyleApplier = _Class("CNContactListStyleApplier")
CNQuickAction = _Class("CNQuickAction")
CNQuickContactAction = _Class("CNQuickContactAction")
CNQuickPropertyAction = _Class("CNQuickPropertyAction")
CNQuickDisambiguateAction = _Class("CNQuickDisambiguateAction")
CNQuickFaceTimeAction = _Class("CNQuickFaceTimeAction")
CNPhotoPickerDefaultEmoji = _Class("CNPhotoPickerDefaultEmoji")
CNPhotoPickerVariantsManager = _Class("CNPhotoPickerVariantsManager")
CNSharingProfileMeCardUpdater = _Class("CNSharingProfileMeCardUpdater")
CNUINullSaveExecutor = _Class("CNUINullSaveExecutor")
CNDonatedMeCardPersistenceHelper = _Class("CNDonatedMeCardPersistenceHelper")
CNUIDate = _Class("CNUIDate")
CNPhotoPickerActionsModel = _Class("CNPhotoPickerActionsModel")
CNContactSection = _Class("CNContactSection")
CNUIFamilyMemberDowntimeContactDataSource = _Class(
    "CNUIFamilyMemberDowntimeContactDataSource"
)
CNUIFamilyMemberDowntimeContactSection = _Class(
    "CNUIFamilyMemberDowntimeContactSection"
)
CNUIFamilyMemberDowntimeContactItem = _Class("CNUIFamilyMemberDowntimeContactItem")
CNAvatarImageUtilities = _Class("CNAvatarImageUtilities")
CNTestFuture = _Class("CNTestFuture")
CNUIMapTileGenerator = _Class("CNUIMapTileGenerator")
CNUIContactsAuthorizationStore = _Class("CNUIContactsAuthorizationStore")
CNQuickActionsManager = _Class("CNQuickActionsManager")
CNUIFontRepository = _Class("CNUIFontRepository")
CNPhotoPickerProviderGroup = _Class("CNPhotoPickerProviderGroup")
CNPhotoPickerProviderSuggestionsGroup = _Class("CNPhotoPickerProviderSuggestionsGroup")
CNPhotoPickerProviderAddItemsGroup = _Class("CNPhotoPickerProviderAddItemsGroup")
CNPhotoPickerProviderEmojiGroup = _Class("CNPhotoPickerProviderEmojiGroup")
CNPhotoPickerProviderAnimojiGroup = _Class("CNPhotoPickerProviderAnimojiGroup")
CNPhotoPickerProviderInjectedItemsGroup = _Class(
    "CNPhotoPickerProviderInjectedItemsGroup"
)
CNUICoreContactsAuthorizationModel = _Class("CNUICoreContactsAuthorizationModel")
CNUIFamilyMemberContactsEditingStrategy = _Class(
    "CNUIFamilyMemberContactsEditingStrategy"
)
CNCardGroupItem = _Class("CNCardGroupItem")
CNPropertyPlaceholderItem = _Class("CNPropertyPlaceholderItem")
ABPostalNameGroupItem = _Class("ABPostalNameGroupItem")
CNCardLinkedCardsPlaceholderGroupItem = _Class("CNCardLinkedCardsPlaceholderGroupItem")
CNCardLinkedCardsGroupItem = _Class("CNCardLinkedCardsGroupItem")
CNCardFaceTimeGroupItem = _Class("CNCardFaceTimeGroupItem")
CNCardActionGroupItem = _Class("CNCardActionGroupItem")
CNPropertyGroupItem = _Class("CNPropertyGroupItem")
CNPropertyGroupGeminiItem = _Class("CNPropertyGroupGeminiItem")
CNCardDowntimeWhitelistGroupItem = _Class("CNCardDowntimeWhitelistGroupItem")
CNPropertyGroupURLAddressItem = _Class("CNPropertyGroupURLAddressItem")
CNPropertyGroupSocialProfileItem = _Class("CNPropertyGroupSocialProfileItem")
CNPropertyGroupContactRelationItem = _Class("CNPropertyGroupContactRelationItem")
CNPropertyGroupPostalAddressItem = _Class("CNPropertyGroupPostalAddressItem")
CNPropertyGroupPhoneItem = _Class("CNPropertyGroupPhoneItem")
CNPropertyGroupNoteItem = _Class("CNPropertyGroupNoteItem")
CNPropertyGroupInstantMessageItem = _Class("CNPropertyGroupInstantMessageItem")
CNPropertyGroupEmailAddressItem = _Class("CNPropertyGroupEmailAddressItem")
CNPropertyGroupAlertItem = _Class("CNPropertyGroupAlertItem")
CNPropertyGroupDateItem = _Class("CNPropertyGroupDateItem")
CNPropertyGroupBirthdayItem = _Class("CNPropertyGroupBirthdayItem")
CNPropertyGroupNameItem = _Class("CNPropertyGroupNameItem")
CNCardGroup = _Class("CNCardGroup")
CNCardLinkedCardsGroup = _Class("CNCardLinkedCardsGroup")
CNCardFaceTimeGroup = _Class("CNCardFaceTimeGroup")
CNCardPropertyGroup = _Class("CNCardPropertyGroup")
CNCardDowntimeWhitelistGroup = _Class("CNCardDowntimeWhitelistGroup")
CNCardPropertyAlertGroup = _Class("CNCardPropertyAlertGroup")
CNCardiMessageEmailGroup = _Class("CNCardiMessageEmailGroup")
CNCardPropertyGeminiGroup = _Class("CNCardPropertyGeminiGroup")
CNCardPropertyNameGroup = _Class("CNCardPropertyNameGroup")
CNContactAction = _Class("CNContactAction")
CNContactUpdateExistingContactAction = _Class("CNContactUpdateExistingContactAction")
CNContactEnableGuardianRestrictionsAction = _Class(
    "CNContactEnableGuardianRestrictionsAction"
)
CNContactShareWithFamilyAction = _Class("CNContactShareWithFamilyAction")
CNContactDisableGuardianRestrictionsAction = _Class(
    "CNContactDisableGuardianRestrictionsAction"
)
CNEditInAppAction = _Class("CNEditInAppAction")
CNContactIgnoreDonatedInformationAction = _Class(
    "CNContactIgnoreDonatedInformationAction"
)
CNContactSuggestionAction = _Class("CNContactSuggestionAction")
CNContactToggleBlockCallerAction = _Class("CNContactToggleBlockCallerAction")
CNContactShareContactAction = _Class("CNContactShareContactAction")
CNContactDeleteContactAction = _Class("CNContactDeleteContactAction")
CNContactCreateNewContactAction = _Class("CNContactCreateNewContactAction")
CNContactAddToExistingContactAction = _Class("CNContactAddToExistingContactAction")
CNContactAddNewFieldAction = _Class("CNContactAddNewFieldAction")
CNContactAddLinkedCardAction = _Class("CNContactAddLinkedCardAction")
CNContactClearRecentsDataAction = _Class("CNContactClearRecentsDataAction")
CNPropertyAction = _Class("CNPropertyAction")
CNPropertySendMessageAction = _Class("CNPropertySendMessageAction")
CNEmergencyContactAction = _Class("CNEmergencyContactAction")
CNPropertyLinkedCardsAction = _Class("CNPropertyLinkedCardsAction")
CNPropertySuggestionAction = _Class("CNPropertySuggestionAction")
CNPropertyFaceTimeAction = _Class("CNPropertyFaceTimeAction")
CNMedicalIDAction = _Class("CNMedicalIDAction")
CNContactAddFavoriteAction = _Class("CNContactAddFavoriteAction")
CNPropertyTTYRelayAction = _Class("CNPropertyTTYRelayAction")
CNPropertyTTYAction = _Class("CNPropertyTTYAction")
CNContactStopSharingWithFamily = _Class("CNContactStopSharingWithFamily")
CNCapabilitiesManager = _Class("CNCapabilitiesManager")
CNReadonlyPolicy = _Class("CNReadonlyPolicy")
CNContactGridViewLayout = _Class("CNContactGridViewLayout")
CNMeCardSharingOnboardingAvatarCarouselLayout = _Class(
    "CNMeCardSharingOnboardingAvatarCarouselLayout"
)
CNContactPickerExtensionHostContext = _Class("CNContactPickerExtensionHostContext")
CNContactPickerExtensionContext = _Class("CNContactPickerExtensionContext")
CNContactViewExtensionHostContext = _Class("CNContactViewExtensionHostContext")
CNContactViewExtensionContext = _Class("CNContactViewExtensionContext")
CNUICancelBarButtonItem = _Class("CNUICancelBarButtonItem")
CNAvatarCardPresentationController = _Class("CNAvatarCardPresentationController")
CNActionsView = _Class("CNActionsView")
CNPhotoPickerHeaderView = _Class("CNPhotoPickerHeaderView")
CNAvatarCardActionsView = _Class("CNAvatarCardActionsView")
CNStarkNoContentBannerView = _Class("CNStarkNoContentBannerView")
CNDatePickerContainerView = _Class("CNDatePickerContainerView")
CNStarkContactNameView = _Class("CNStarkContactNameView")
CNContactDowntimeView = _Class("CNContactDowntimeView")
CNStarkHeaderPlatterView = _Class("CNStarkHeaderPlatterView")
CNContactGridClippingView = _Class("CNContactGridClippingView")
CNRepeatingGradientSeparatorView = _Class("CNRepeatingGradientSeparatorView")
CNQuickActionButton = _Class("CNQuickActionButton")
CNQuickActionsView = _Class("CNQuickActionsView")
CNLabeledBadge = _Class("CNLabeledBadge")
CNContactGeminiView = _Class("CNContactGeminiView")
CNVibrantBackdropView = _Class("CNVibrantBackdropView")
CNTestQuickActionView = _Class("CNTestQuickActionView")
CNCaptureButtonView = _Class("CNCaptureButtonView")
CNStarkActionView = _Class("CNStarkActionView")
CNContactListBannerView = _Class("CNContactListBannerView")
_CNAvatarView = _Class("_CNAvatarView")
CNAvatarCardHighlightView = _Class("CNAvatarCardHighlightView")
CNPhotoPickerTrapView = _Class("CNPhotoPickerTrapView")
CNPhotoPickerPreviewView = _Class("CNPhotoPickerPreviewView")
CNPhotoPickerAnimojiPosePreviewView = _Class("CNPhotoPickerAnimojiPosePreviewView")
CNContactHeaderView = _Class("CNContactHeaderView")
CNContactHeaderEditView = _Class("CNContactHeaderEditView")
CNContactHeaderDisplayView = _Class("CNContactHeaderDisplayView")
CNUIToolbar = _Class("CNUIToolbar")
CNGeminiBadge = _Class("CNGeminiBadge")
CNAvatarView = _Class("CNAvatarView")
CNContactOrbHeaderView = _Class("CNContactOrbHeaderView")
CNAvatarCardHeaderView = _Class("CNAvatarCardHeaderView")
CNContactActionsContainerView = _Class("CNContactActionsContainerView")
CNContactTableViewHeaderFooterView = _Class("CNContactTableViewHeaderFooterView")
CNWarningHeaderFooterView = _Class("CNWarningHeaderFooterView")
CNContactListHeaderFooterView = _Class("CNContactListHeaderFooterView")
CNVisualIdentityEditablePrimaryAvatarTextField = _Class(
    "CNVisualIdentityEditablePrimaryAvatarTextField"
)
CNAvatarCardActionsTableView = _Class("CNAvatarCardActionsTableView")
CNContactListTableView = _Class("CNContactListTableView")
CNPostalAddressEditorTableView = _Class("CNPostalAddressEditorTableView")
CNUINavigationListView = _Class("CNUINavigationListView")
CNMaskingTableView = _Class("CNMaskingTableView")
CNContactView = _Class("CNContactView")
CNMeCardSharingSettingsNameCell = _Class("CNMeCardSharingSettingsNameCell")
CNPickerItemCell = _Class("CNPickerItemCell")
CNAvatarCardActionCell = _Class("CNAvatarCardActionCell")
CNAvatarCardContactCell = _Class("CNAvatarCardContactCell")
CNContactListTableViewCell = _Class("CNContactListTableViewCell")
CNUINavigationListViewCell = _Class("CNUINavigationListViewCell")
CNUINavigationListViewDetailCell = _Class("CNUINavigationListViewDetailCell")
CNSharingProfileOnboardingNameCell = _Class("CNSharingProfileOnboardingNameCell")
CNContactCell = _Class("CNContactCell")
CNContactDowntimeWhitelistCell = _Class("CNContactDowntimeWhitelistCell")
CNPropertyNameCell = _Class("CNPropertyNameCell")
ABPostalNameContactEditingCell = _Class("ABPostalNameContactEditingCell")
CNStarkFaceTimeCell = _Class("CNStarkFaceTimeCell")
CNLabeledCell = _Class("CNLabeledCell")
CNPropertyCell = _Class("CNPropertyCell")
CNPropertyNoteCell = _Class("CNPropertyNoteCell")
CNPropertyEditingCell = _Class("CNPropertyEditingCell")
CNPropertyPostalAddressEditingCell = _Class("CNPropertyPostalAddressEditingCell")
CNPropertySimpleEditingCell = _Class("CNPropertySimpleEditingCell")
CNPropertyURLAddressEditingCell = _Class("CNPropertyURLAddressEditingCell")
CNPropertySocialProfileEditingCell = _Class("CNPropertySocialProfileEditingCell")
CNPropertyRelatedNameEditingCell = _Class("CNPropertyRelatedNameEditingCell")
CNPropertyPhoneNumberEditingCell = _Class("CNPropertyPhoneNumberEditingCell")
CNPropertyInstantMessageEditingCell = _Class("CNPropertyInstantMessageEditingCell")
CNPropertyDateEditingCell = _Class("CNPropertyDateEditingCell")
CNPropertySimpleCell = _Class("CNPropertySimpleCell")
CNPropertyRelatedNameCell = _Class("CNPropertyRelatedNameCell")
CNPropertyGeminiEditingCell = _Class("CNPropertyGeminiEditingCell")
CNPropertySimpleTransportCell = _Class("CNPropertySimpleTransportCell")
CNPropertyPostalAddressCell = _Class("CNPropertyPostalAddressCell")
CNStarkContactAddressPropertyCell = _Class("CNStarkContactAddressPropertyCell")
CNPropertyPhoneNumberCell = _Class("CNPropertyPhoneNumberCell")
CNStarkContactPropertyCell = _Class("CNStarkContactPropertyCell")
CNPropertyEmailAddressCell = _Class("CNPropertyEmailAddressCell")
CNPropertyIntentActionableCell = _Class("CNPropertyIntentActionableCell")
CNPropertyAlertCell = _Class("CNPropertyAlertCell")
CNPropertyAlertEditingCell = _Class("CNPropertyAlertEditingCell")
CNPropertyPlaceholderCell = _Class("CNPropertyPlaceholderCell")
CNLinkedCardsPlaceholderCell = _Class("CNLinkedCardsPlaceholderCell")
CNLinkedCardsCell = _Class("CNLinkedCardsCell")
CNLinkedCardsEditingCell = _Class("CNLinkedCardsEditingCell")
CNFaceTimeCell = _Class("CNFaceTimeCell")
CNContactActionSplitCell = _Class("CNContactActionSplitCell")
CNContactActionCell = _Class("CNContactActionCell")
CNGeminiPickerCell = _Class("CNGeminiPickerCell")
CNMeCardSharingTextFieldTableViewCell = _Class("CNMeCardSharingTextFieldTableViewCell")
CNUIFamilyDowntimeContactPickerCell = _Class("CNUIFamilyDowntimeContactPickerCell")
CNAddressComponentTextFieldCell = _Class("CNAddressComponentTextFieldCell")
CNAddressComponentSplitTextFieldCell = _Class("CNAddressComponentSplitTextFieldCell")
CNSharingProfileOnboardingHeaderView = _Class("CNSharingProfileOnboardingHeaderView")
CNPhotoPickerSectionHeader = _Class("CNPhotoPickerSectionHeader")
CNMeCardSharingOnboardingAvatarCarouselCell = _Class(
    "CNMeCardSharingOnboardingAvatarCarouselCell"
)
CNContactGridCell = _Class("CNContactGridCell")
CNQuickActionCell = _Class("CNQuickActionCell")
CNSharingProfilePhotoPickerItemCell = _Class("CNSharingProfilePhotoPickerItemCell")
CNPhotoPickerCollectionViewCell = _Class("CNPhotoPickerCollectionViewCell")
CNPostalAddressEditorView = _Class("CNPostalAddressEditorView")
CNActionView = _Class("CNActionView")
CNContactPhotoView = _Class("CNContactPhotoView")
CNVisualIdentityItemEditorSegmentedControl = _Class(
    "CNVisualIdentityItemEditorSegmentedControl"
)
CNPhotoPickerHeaderViewTextField = _Class("CNPhotoPickerHeaderViewTextField")
CNTextField = _Class("CNTextField")
CNPhotoPickerActionButton = _Class("CNPhotoPickerActionButton")
CNPhotoPickerHeaderButton = _Class("CNPhotoPickerHeaderButton")
CNTransportButton = _Class("CNTransportButton")
CNPropertyLabelButton = _Class("CNPropertyLabelButton")
CNContactInlineActionsViewController = _Class("CNContactInlineActionsViewController")
CNContactViewController = _Class("CNContactViewController")
CNMeCardSharingOnboardingHeaderViewController = _Class(
    "CNMeCardSharingOnboardingHeaderViewController"
)
CNMeCardSharingPickerViewController = _Class("CNMeCardSharingPickerViewController")
CNMeCardSharingAvatarViewController = _Class("CNMeCardSharingAvatarViewController")
CNStarkActionsController = _Class("CNStarkActionsController")
CNPhotoPickerActionsViewController = _Class("CNPhotoPickerActionsViewController")
CNVisualIdentityEditablePrimaryAvatarViewController = _Class(
    "CNVisualIdentityEditablePrimaryAvatarViewController"
)
CNGroupAvatarViewController = _Class("CNGroupAvatarViewController")
CNGroupIdentityInlineActionsViewController = _Class(
    "CNGroupIdentityInlineActionsViewController"
)
CNContactOrbHeaderViewController = _Class("CNContactOrbHeaderViewController")
CNAvatarViewController = _Class("CNAvatarViewController")
CNAvatarViewController_NewAvatarView = _Class("CNAvatarViewController_NewAvatarView")
CNAvatarViewController_LegacyAvatarView = _Class(
    "CNAvatarViewController_LegacyAvatarView"
)
CNPhotoPickerVariantListController = _Class("CNPhotoPickerVariantListController")
CNVisualIdentityPickerViewController = _Class("CNVisualIdentityPickerViewController")
CNPhotoPickerViewController = _Class("CNPhotoPickerViewController")
CNErrorViewController = _Class("CNErrorViewController")
CNContactPickerServiceErrorViewController = _Class(
    "CNContactPickerServiceErrorViewController"
)
CNContactViewServiceErrorViewController = _Class(
    "CNContactViewServiceErrorViewController"
)
CNStarkContactInfoViewController = _Class("CNStarkContactInfoViewController")
CNMeCardSharingSettingsHeaderViewController = _Class(
    "CNMeCardSharingSettingsHeaderViewController"
)
CNVCardViewController = _Class("CNVCardViewController")
CNContactPickerContentViewController = _Class("CNContactPickerContentViewController")
CNContactPickerServiceViewController = _Class("CNContactPickerServiceViewController")
CNAvatarCardViewController = _Class("CNAvatarCardViewController")
CNMeCardSharingOnboardingAvatarCarouselViewController = _Class(
    "CNMeCardSharingOnboardingAvatarCarouselViewController"
)
CNVisualIdentityItemEditorViewController = _Class(
    "CNVisualIdentityItemEditorViewController"
)
CNVisualIdentityAvatarViewController = _Class("CNVisualIdentityAvatarViewController")
CNAccountsAndGroupsViewController = _Class("CNAccountsAndGroupsViewController")
CNSharingProfilePhotoPickerViewController = _Class(
    "CNSharingProfilePhotoPickerViewController"
)
CNContactGroupPickerViewController = _Class("CNContactGroupPickerViewController")
CNMeCardSharingSettingsViewController = _Class("CNMeCardSharingSettingsViewController")
CNGroupIdentityHeaderViewController = _Class("CNGroupIdentityHeaderViewController")
CNAvatarCaptureViewController = _Class("CNAvatarCaptureViewController")
CNSyndicationViewController = _Class("CNSyndicationViewController")
CNContactPickerViewController = _Class("CNContactPickerViewController")
CNContactPicker = _Class("CNContactPicker")
CNStarkCardViewController = _Class("CNStarkCardViewController")
CNUINavigationListViewController = _Class("CNUINavigationListViewController")
CNMeCardSharingHeaderViewController = _Class("CNMeCardSharingHeaderViewController")
CNUIFamilyMemberDowntimeContactPickerController = _Class(
    "CNUIFamilyMemberDowntimeContactPickerController"
)
CNContactContentViewController = _Class("CNContactContentViewController")
CNStarkContactViewController = _Class("CNStarkContactViewController")
CNContactViewServiceViewController = _Class("CNContactViewServiceViewController")
CNSharingProfileOnboardingPhotoSelectionViewController = _Class(
    "CNSharingProfileOnboardingPhotoSelectionViewController"
)
CNSharingProfileOnboardingVariantViewController = _Class(
    "CNSharingProfileOnboardingVariantViewController"
)
CNSharingProfileOnboardingPosePickerController = _Class(
    "CNSharingProfileOnboardingPosePickerController"
)
CNSharingProfileOnboardingAudienceCatalystViewController = _Class(
    "CNSharingProfileOnboardingAudienceCatalystViewController"
)
CNSharingProfileOnboardingAudienceViewController = _Class(
    "CNSharingProfileOnboardingAudienceViewController"
)
CNMeCardSharingOnboardingViewController = _Class(
    "CNMeCardSharingOnboardingViewController"
)
CNMeCardSharingOnboardingEditViewController = _Class(
    "CNMeCardSharingOnboardingEditViewController"
)
CNMeCardSharingOnboardingAudienceViewController = _Class(
    "CNMeCardSharingOnboardingAudienceViewController"
)
CNContactPickerHostViewController = _Class("CNContactPickerHostViewController")
CNContactViewHostViewController = _Class("CNContactViewHostViewController")
CNContactSuggestionViewController = _Class("CNContactSuggestionViewController")
CNPostalAddressEditorViewController = _Class("CNPostalAddressEditorViewController")
CNContactListViewController = _Class("CNContactListViewController")
CNStarkContactsListViewController = _Class("CNStarkContactsListViewController")
CNPickerController = _Class("CNPickerController")
CNSocialProfileServicePickerController = _Class(
    "CNSocialProfileServicePickerController"
)
CNLabelPickerController = _Class("CNLabelPickerController")
CNInstantMessagePickerController = _Class("CNInstantMessagePickerController")
CNMultipleUnknownContactsViewController = _Class(
    "CNMultipleUnknownContactsViewController"
)
CNContactGridViewController = _Class("CNContactGridViewController")
CNTonePickerController = _Class("CNTonePickerController")
CNPostalAddressEditorNavigationController = _Class(
    "CNPostalAddressEditorNavigationController"
)
CNContactNavigationController = _Class("CNContactNavigationController")
CNCountryPickerController = _Class("CNCountryPickerController")
CNGeminiPickerController = _Class("CNGeminiPickerController")
CNStarkContactsBrowserViewController = _Class("CNStarkContactsBrowserViewController")
CNPortraitOnlyNavigationController = _Class("CNPortraitOnlyNavigationController")
CNPhotoPickerNavigationViewController = _Class("CNPhotoPickerNavigationViewController")
