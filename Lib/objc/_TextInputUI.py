"""
Classes from the 'TextInputUI' framework.
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


TUIEmojiSearchSource = _Class("TUIEmojiSearchSource")
TUIPreferencesController = _Class("TUIPreferencesController")
TUISuggestedInputMode = _Class("TUISuggestedInputMode")
FieldSpecTuple = _Class("FieldSpecTuple")
TUIAnalyticsSession = _Class("TUIAnalyticsSession")
TUIEmojiSearchAnalyticsSession = _Class("TUIEmojiSearchAnalyticsSession")
TUICandidateLayoutAttributes = _Class("TUICandidateLayoutAttributes")
TUIKeyboardBackendController = _Class("TUIKeyboardBackendController")
TUIKBGraphSerialization = _Class("TUIKBGraphSerialization")
TUIKeyboardLayoutFactory = _Class("TUIKeyboardLayoutFactory")
TUIButtonBarGroupSet = _Class("TUIButtonBarGroupSet")
TUISystemInputAssistantLayoutViewSet = _Class("TUISystemInputAssistantLayoutViewSet")
TUISystemInputAssistantLayout = _Class("TUISystemInputAssistantLayout")
TUISystemInputAssistantLayoutSplit = _Class("TUISystemInputAssistantLayoutSplit")
TUISystemInputAssistantLayoutStandard = _Class("TUISystemInputAssistantLayoutStandard")
TUITypedStringCandidate = _Class("TUITypedStringCandidate")
TUIPlaceholderCandidate = _Class("TUIPlaceholderCandidate")
TUIKeyboardInputManagerMux = _Class("TUIKeyboardInputManagerMux")
TUICandidateLayout = _Class("TUICandidateLayout")
_InvertibleFlowLayout = _Class("_InvertibleFlowLayout")
TUIButtonBarItemView = _Class("TUIButtonBarItemView")
TouchExclusionView = _Class("TouchExclusionView")
ShapeView = _Class("ShapeView")
TUIEmojiVariantCell = _Class("TUIEmojiVariantCell")
TUICandidateGrid = _Class("TUICandidateGrid")
TUICandidateBackdropView = _Class("TUICandidateBackdropView")
TUICandidateInlineTextView = _Class("TUICandidateInlineTextView")
TUIEmojiSearchTextFieldBackgroundView = _Class("TUIEmojiSearchTextFieldBackgroundView")
TUIAssistantButtonBarGroupView = _Class("TUIAssistantButtonBarGroupView")
TUIEmojiSearchView = _Class("TUIEmojiSearchView")
TUICandidateView = _Class("TUICandidateView")
TUICandidateLabel = _Class("TUICandidateLabel")
TUIEmojiSearchTextFieldPortalView = _Class("TUIEmojiSearchTextFieldPortalView")
TUIAssistantButtonBarView = _Class("TUIAssistantButtonBarView")
TUIPredictionViewCell = _Class("TUIPredictionViewCell")
TUIPredictionViewStackContentView = _Class("TUIPredictionViewStackContentView")
TUIPredictionViewStackView = _Class("TUIPredictionViewStackView")
TUIPredictionView = _Class("TUIPredictionView")
TUISystemInputAssistantPageView = _Class("TUISystemInputAssistantPageView")
TUISystemInputAssistantView = _Class("TUISystemInputAssistantView")
TUIEmojiSearchInputView = _Class("TUIEmojiSearchInputView")
TUICandidateCollectionView = _Class("TUICandidateCollectionView")
TUICandidateLine = _Class("TUICandidateLine")
TUICandidateSlottedSeparator = _Class("TUICandidateSlottedSeparator")
TUICandidateGroupHeader = _Class("TUICandidateGroupHeader")
TUIEmojiSearchResultCollectionViewCell = _Class(
    "TUIEmojiSearchResultCollectionViewCell"
)
TUICandidateBaseCell = _Class("TUICandidateBaseCell")
TUIAutofillExtraCandidateCell = _Class("TUIAutofillExtraCandidateCell")
TUISuggestionCandidateCell = _Class("TUISuggestionCandidateCell")
TUICandidateCell = _Class("TUICandidateCell")
TUIProactiveCandidateCell = _Class("TUIProactiveCandidateCell")
TUICandidateSortControl = _Class("TUICandidateSortControl")
TUIEmojiVariantSelectorView = _Class("TUIEmojiVariantSelectorView")
TUIEmojiSearchTextField = _Class("TUIEmojiSearchTextField")
TUICandidateArrowButton = _Class("TUICandidateArrowButton")
TUIPredictionCellButton = _Class("TUIPredictionCellButton")
TUIEmojiSearchInputViewController = _Class("TUIEmojiSearchInputViewController")
TUIEmojiSearchResultsCollectionViewController = _Class(
    "TUIEmojiSearchResultsCollectionViewController"
)
