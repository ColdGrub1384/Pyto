"""
Classes from the 'ContactsAutocompleteUI' framework.
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


CNComposeDropTarget = _Class("CNComposeDropTarget")
CNComposeRecipients = _Class("CNComposeRecipients")
CNAutocompleteSearchManager = _Class("CNAutocompleteSearchManager")
CNAutocompleteContactsSearchTaskContext = _Class(
    "CNAutocompleteContactsSearchTaskContext"
)
CNAutocompleteSupplementalGroup = _Class("CNAutocompleteSupplementalGroup")
CNAutocompleteSupplementalGroupMember = _Class("CNAutocompleteSupplementalGroupMember")
CNComposeAddressConcatenator = _Class("CNComposeAddressConcatenator")
CNAutocompleteFontMetricCache = _Class("CNAutocompleteFontMetricCache")
_CNAUICRRecentContactCNContext = _Class("_CNAUICRRecentContactCNContext")
CNAutocompleteUIPreferences = _Class("CNAutocompleteUIPreferences")
CNComposeRecipient = _Class("CNComposeRecipient")
CNRecentComposeRecipient = _Class("CNRecentComposeRecipient")
CNComposeRecipientGroup = _Class("CNComposeRecipientGroup")
CNRecentComposeRecipientGroup = _Class("CNRecentComposeRecipientGroup")
CNUnifiedComposeRecipient = _Class("CNUnifiedComposeRecipient")
CNComposeRecipientOriginContext = _Class("CNComposeRecipientOriginContext")
_CNCountableMatchesContext = _Class("_CNCountableMatchesContext")
_CNAutocompleteResultsTableViewModel = _Class("_CNAutocompleteResultsTableViewModel")
_CNAutocompleteTableViewModelDiff = _Class("_CNAutocompleteTableViewModelDiff")
CNComposeDragSource = _Class("CNComposeDragSource")
_CNAtomTextAttachment = _Class("_CNAtomTextAttachment")
CNAtomCenteredTextAttachment = _Class("CNAtomCenteredTextAttachment")
_CNAtomAttachment = _Class("_CNAtomAttachment")
_CNAtomTextSelectionRect = _Class("_CNAtomTextSelectionRect")
_CNAtomViewTextSelectionRect = _Class("_CNAtomViewTextSelectionRect")
CNAtomIcon = _Class("CNAtomIcon")
CNAutocompleteSearchOperation = _Class("CNAutocompleteSearchOperation")
CNContactsAutocompleteSearchOperation = _Class("CNContactsAutocompleteSearchOperation")
CNComposeHeaderView = _Class("CNComposeHeaderView")
CNComposeRecipientTextView = _Class("CNComposeRecipientTextView")
CNModernAtomBackgroundView = _Class("CNModernAtomBackgroundView")
CNModernAtomIconView = _Class("CNModernAtomIconView")
_CNAtomLayoutView = _Class("_CNAtomLayoutView")
CNAtomView = _Class("CNAtomView")
CNComposeRecipientAtom = _Class("CNComposeRecipientAtom")
_CNAtomTextView = _Class("_CNAtomTextView")
_CNAtomFieldEditor = _Class("_CNAtomFieldEditor")
CNAutocompleteResultsTableView = _Class("CNAutocompleteResultsTableView")
CNComposeTableViewCell = _Class("CNComposeTableViewCell")
CNComposeRecipientTableViewCell = _Class("CNComposeRecipientTableViewCell")
CNAutocompleteDisambiguatingTableViewCell = _Class(
    "CNAutocompleteDisambiguatingTableViewCell"
)
CNComposeHeaderLabelView = _Class("CNComposeHeaderLabelView")
_CNAtomTextViewBaselineLayoutStrut = _Class("_CNAtomTextViewBaselineLayoutStrut")
CNAtomTextView = _Class("CNAtomTextView")
CNChevronButton = _Class("CNChevronButton")
CNComposeRecipientActionButton = _Class("CNComposeRecipientActionButton")
CNAutocompleteResultsTableViewController = _Class(
    "CNAutocompleteResultsTableViewController"
)
CNAutocompleteGroupDetailViewController = _Class(
    "CNAutocompleteGroupDetailViewController"
)
