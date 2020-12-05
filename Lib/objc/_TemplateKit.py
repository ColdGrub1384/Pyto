"""
Classes from the 'TemplateKit' framework.
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


TLKTableViewScrollTester = _Class("TLKTableViewScrollTester")
TLKFontUtilities = _Class("TLKFontUtilities")
TLKGridLayoutManager = _Class("TLKGridLayoutManager")
TLKManyTrailingGridLayoutManager = _Class("TLKManyTrailingGridLayoutManager")
TLKLabelItem = _Class("TLKLabelItem")
TLKArrangementItem = _Class("TLKArrangementItem")
TLKGridImageItem = _Class("TLKGridImageItem")
TLKObject = _Class("TLKObject")
TLKTableColumnAlignment = _Class("TLKTableColumnAlignment")
TLKTableRow = _Class("TLKTableRow")
TLKTableHeaderRow = _Class("TLKTableHeaderRow")
TLKKeyValueTuple = _Class("TLKKeyValueTuple")
TLKFormattedTextItem = _Class("TLKFormattedTextItem")
TLKIcon = _Class("TLKIcon")
TLKInlineRoundedText = _Class("TLKInlineRoundedText")
TLKStars = _Class("TLKStars")
TLKInlineImage = _Class("TLKInlineImage")
TLKFormattedText = _Class("TLKFormattedText")
TLKMultilineText = _Class("TLKMultilineText")
TLKRichText = _Class("TLKRichText")
TLKSelectableGridTuple = _Class("TLKSelectableGridTuple")
TLKDetailsSection = _Class("TLKDetailsSection")
TLKImage = _Class("TLKImage")
TLKUtilities = _Class("TLKUtilities")
TLKAppearance = _Class("TLKAppearance")
TLKLightAppearance = _Class("TLKLightAppearance")
TLKVibrantLightAppearance = _Class("TLKVibrantLightAppearance")
TLKDarkAppearance = _Class("TLKDarkAppearance")
TLKVibrantDarkAppearance = _Class("TLKVibrantDarkAppearance")
TLKLayoutUtilities = _Class("TLKLayoutUtilities")
TLKImageAttachment = _Class("TLKImageAttachment")
TLKButton = _Class("TLKButton")
TLKProminenceView = _Class("TLKProminenceView")
TLKView = _Class("TLKView")
TLKSectionHeaderView = _Class("TLKSectionHeaderView")
TLKButtonView = _Class("TLKButtonView")
TLKKeyValueView = _Class("TLKKeyValueView")
TLKDescriptionView = _Class("TLKDescriptionView")
TLKSelectableGridView = _Class("TLKSelectableGridView")
TLKMediaInfoView = _Class("TLKMediaInfoView")
TLKHeaderView = _Class("TLKHeaderView")
TLKGridRowView = _Class("TLKGridRowView")
TLKEmbossedLabel = _Class("TLKEmbossedLabel")
TLKRoundedCornerLabel = _Class("TLKRoundedCornerLabel")
TLKImagesView = _Class("TLKImagesView")
TLKSplitHeaderView = _Class("TLKSplitHeaderView")
TLKTextAreaView = _Class("TLKTextAreaView")
TLKActivityIndicatorView = _Class("TLKActivityIndicatorView")
TLKSimpleRowView = _Class("TLKSimpleRowView")
TLKDetailsView = _Class("TLKDetailsView")
TLKEnlargedTitleView = _Class("TLKEnlargedTitleView")
TLKImageView = _Class("TLKImageView")
TLKAuxilliaryTextView = _Class("TLKAuxilliaryTextView")
TLKDescriptionContainerBoxView = _Class("TLKDescriptionContainerBoxView")
TLKStackView = _Class("TLKStackView")
TLKRichTextField = _Class("TLKRichTextField")
TLKRoundedCornerLabels = _Class("TLKRoundedCornerLabels")
TLKIconsView = _Class("TLKIconsView")
TLKStarsView = _Class("TLKStarsView")
TLKTitleContainerView = _Class("TLKTitleContainerView")
TLKContentsView = _Class("TLKContentsView")
TLKContentsContainerView = _Class("TLKContentsContainerView")
TLKKeyValueGridView = _Class("TLKKeyValueGridView")
TLKPassThroughScrollView = _Class("TLKPassThroughScrollView")
TLKTextView = _Class("TLKTextView")
TLKLabel = _Class("TLKLabel")
TLKTextButton = _Class("TLKTextButton")
TLKTapContainerButton = _Class("TLKTapContainerButton")
TLKSelectableGridButton = _Class("TLKSelectableGridButton")
TLKStoreButton = _Class("TLKStoreButton")
