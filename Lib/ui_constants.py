"""
A module containing constants for ``pyto_ui``.
"""

from pyto import __Class__
from UIKit import (
    UITapGestureRecognizer,
    UILongPressGestureRecognizer,
    UIPanGestureRecognizer,
    UIGestureRecognizer,
)
from UIKit import UIFont as __UIFont__, UIDevice
import os
import sys

if (
    UIDevice is not None
    and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 13
):
    raise ImportError("PytoUI requires iPadOS / iOS 13")

__PyView__ = __Class__("PyView")
__PyColor__ = __Class__("PyColor")
__PyControl__ = __Class__("PyControl")
__PyButton__ = __Class__("PyButton")
__PyLabel__ = __Class__("PyLabel")
__PyTableView__ = __Class__("PyTableView")
__PyTableViewCell__ = __Class__("PyTableViewCell")
__PyTextField__ = __Class__("PyTextField")
__PyGestureRecognizer__ = __Class__("PyGestureRecognizer")
__PyButtonItem__ = __Class__("PyButtonItem")
__PyTextInputTraitsConstants__ = __Class__("PyTextInputTraitsConstants")


class Value:
    def __repr__(self):
        return None


class AUTO_RESIZING:
    pass


class GESTURE_TYPE:
    pass


class KEYBOARD_APPEARANCE:
    pass


class KEYBOARD_TYPE:
    pass


class RETURN_KEY_TYPE:
    pass


class AUTO_CAPITALIZE:
    pass


class FONT_TEXT_STYLE:
    pass


class FONT_SIZE:
    pass


class PRESENTATION_MODE:
    pass


class APPEARANCE:
    pass


class CONTENT_MODE:
    pass


class HORZONTAL_ALIGNMENT:
    pass


class VERTICAL_ALIGNMENT:
    pass


class BUTTON_TYPE:
    pass


class TEXT_ALIGNMENT:
    pass


class LINE_BREAK_MODE:
    pass


class TOUCH_TYPE:
    pass


class GESTURE_STATE:
    pass


class TABLE_VIEW_CELL_STYLE:
    pass


class ACCESSORY_TYPE:
    pass


class TABLE_VIEW_STYLE:
    pass


class TEXT_FIELD_BORDER_STYLE:
    pass


class BUTTON_ITEM_STYLE:
    pass


class SYSTEM_ITEM:
    pass


try:

    COLOR_LABEL = __PyColor__.label
    COLOR_SECONDARY_LABEL = __PyColor__.secondaryLabel
    COLOR_TERTIARY_LABEL = __PyColor__.tertiaryLabel
    COLOR_QUATERNARY_LABEL = __PyColor__.quaternaryLabel
    COLOR_SYSTEM_FILL = __PyColor__.systemFill
    COLOR_SECONDARY_SYSTEM_FILL = __PyColor__.secondarySystemFill
    COLOR_TERTIARY_SYSTEM_FILL = __PyColor__.tertiarySystemFill
    COLOR_QUATERNARY_SYSTEM_FILL = __PyColor__.quaternarySystemFill
    COLOR_PLACEHOLDER_TEXT = __PyColor__.placeholderText
    COLOR_SYSTEM_BACKGROUND = __PyColor__.systemBackground
    COLOR_SECONDARY_SYSTEM_BACKGROUND = __PyColor__.secondarySystemBackground
    COLOR_TERTIARY_SYSTEM_BACKGROUND = __PyColor__.tertiarySystemBackground
    COLOR_SYSTEM_GROUPED_BACKGROUND = __PyColor__.systemGroupedBackground
    COLOR_SECONDARY_GROUPED_BACKGROUND = __PyColor__.secondarySystemGroupedBackground
    COLOR_TERTIARY_GROUPED_BACKGROUND = __PyColor__.tertiarySystemGroupedBackground
    COLOR_SEPARATOR = __PyColor__.separator
    COLOR_OPAQUE_SEPARATOR = __PyColor__.opaqueSeparator
    COLOR_LINK = __PyColor__.link
    COLOR_DARK_TEXT = __PyColor__.darkText
    COLOR_LIGHT_TEXT = __PyColor__.lightText
    COLOR_SYSTEM_BLUE = __PyColor__.systemBlue
    COLOR_SYSTEM_GREEN = __PyColor__.systemGreen
    COLOR_SYSTEM_INDIGO = __PyColor__.systemIndigo
    COLOR_SYSTEM_ORANGE = __PyColor__.systemOrange
    COLOR_SYSTEM_PINK = __PyColor__.systemPink
    COLOR_SYSTEM_PURPLE = __PyColor__.systemPurple
    COLOR_SYSTEM_RED = __PyColor__.systemRed
    COLOR_SYSTEM_TEAL = __PyColor__.systemTeal
    COLOR_SYSTEM_YELLOW = __PyColor__.systemYellow
    COLOR_SYSTEM_GRAY = __PyColor__.systemGray
    COLOR_SYSTEM_GRAY2 = __PyColor__.systemGray2
    COLOR_SYSTEM_GRAY3 = __PyColor__.systemGray3
    COLOR_SYSTEM_GRAY4 = __PyColor__.systemGray4
    COLOR_SYSTEM_GRAY5 = __PyColor__.systemGray5
    COLOR_SYSTEM_GRAY6 = __PyColor__.systemGray6
    COLOR_CLEAR = __PyColor__.clear
    COLOR_BLACK = __PyColor__.black
    COLOR_BLUE = __PyColor__.blue
    COLOR_BROWN = __PyColor__.brown
    COLOR_CYAN = __PyColor__.cyan
    COLOR_DARK_GRAY = __PyColor__.darkGray
    COLOR_GRAY = __PyColor__.gray
    COLOR_GREEN = __PyColor__.green
    COLOR_LIGHT_GRAY = __PyColor__.lightGray
    COLOR_MAGENTA = __PyColor__.magenta
    COLOR_ORANGE = __PyColor__.orange
    COLOR_PURPLE = __PyColor__.purple
    COLOR_RED = __PyColor__.red
    COLOR_WHITE = __PyColor__.white
    COLOR_YELLOW = __PyColor__.yellow

    GESTURE_TYPE_NONE = UIGestureRecognizer
    GESTURE_TYPE_LONG_PRESS = UILongPressGestureRecognizer
    GESTURE_TYPE_PAN = UIPanGestureRecognizer
    GESTURE_TYPE_TAP = UITapGestureRecognizer

    KEYBOARD_APPEARANCE_DEFAULT = (
        __PyTextInputTraitsConstants__.KeyboardAppearanceDefault
    )
    KEYBOARD_APPEARANCE_LIGHT = __PyTextInputTraitsConstants__.KeyboardAppearanceLight
    KEYBOARD_APPEARANCE_DARK = __PyTextInputTraitsConstants__.KeyboardAppearanceDark

    KEYBOARD_TYPE_DEFAULT = __PyTextInputTraitsConstants__.KeyboardTypeDefault
    KEYBOARD_TYPE_ALPHABET = __PyTextInputTraitsConstants__.KeyboardTypeAlphabet
    KEYBOARD_TYPE_ASCII_CAPABLE = (
        __PyTextInputTraitsConstants__.KeyboardTypeAsciiCapable
    )
    KEYBOARD_TYPE_ASCII_CAPABLE_NUMBER_PAD = (
        __PyTextInputTraitsConstants__.KeyboardTypeAsciiCapableNumberPad
    )
    KEYBOARD_TYPE_DECIMAL_PAD = __PyTextInputTraitsConstants__.KeyboardTypeDecimalPad
    KEYBOARD_TYPE_EMAIL_ADDRESS = (
        __PyTextInputTraitsConstants__.KeyboardTypeEmailAddress
    )
    KEYBOARD_TYPE_NAME_PHONE_PAD = (
        __PyTextInputTraitsConstants__.KeyboardTypeNamePhonePad
    )
    KEYBOARD_TYPE_NUMBER_PAD = __PyTextInputTraitsConstants__.KeyboardTypeNumberPad
    KEYBOARD_TYPE_NUMBERS_AND_PUNCTUATION = (
        __PyTextInputTraitsConstants__.KeyboardTypeNumbersAndPunctuation
    )
    KEYBOARD_TYPE_PHONE_PAD = __PyTextInputTraitsConstants__.KeyboardTypePhonePad
    KEYBOARD_TYPE_TWITTER = __PyTextInputTraitsConstants__.KeyboardTypeTwitter
    KEYBOARD_TYPE_URL = __PyTextInputTraitsConstants__.KeyboardTypeURL
    KEYBOARD_TYPE_WEB_SEARCH = __PyTextInputTraitsConstants__.KeyboardTypeWebSearch

    RETURN_KEY_TYPE_DEFAULT = __PyTextInputTraitsConstants__.ReturnKeyTypeDefault
    RETURN_KEY_TYPE_CONTINUE = __PyTextInputTraitsConstants__.ReturnKeyTypeContinue
    RETURN_KEY_TYPE_DONE = __PyTextInputTraitsConstants__.ReturnKeyTypeDone
    RETURN_KEY_TYPE_EMERGENCY_CALL = (
        __PyTextInputTraitsConstants__.ReturnKeyTypeEmergencyCall
    )
    RETURN_KEY_TYPE_GO = __PyTextInputTraitsConstants__.ReturnKeyTypeGo
    RETURN_KEY_TYPE_GOOGLE = __PyTextInputTraitsConstants__.ReturnKeyTypeGoogle
    RETURN_KEY_TYPE_JOIN = __PyTextInputTraitsConstants__.ReturnKeyTypeJoin
    RETURN_KEY_TYPE_NEXT = __PyTextInputTraitsConstants__.ReturnKeyTypeNext
    RETURN_KEY_TYPE_ROUTE = __PyTextInputTraitsConstants__.ReturnKeyTypeRoute
    RETURN_KEY_TYPE_SEARCH = __PyTextInputTraitsConstants__.ReturnKeyTypeSearch
    RETURN_KEY_TYPE_SEND = __PyTextInputTraitsConstants__.ReturnKeyTypeSend
    RETURN_KEY_TYPE_YAHOO = __PyTextInputTraitsConstants__.ReturnKeyTypeYahoo

    AUTO_CAPITALIZE_NONE = __PyTextInputTraitsConstants__.AutocapitalizationTypeNone
    AUTO_CAPITALIZE_ALL = (
        __PyTextInputTraitsConstants__.AutocapitalizationTypeAllCharacters
    )
    AUTO_CAPITALIZE_SENTENCES = (
        __PyTextInputTraitsConstants__.AutocapitalizationTypeSentences
    )
    AUTO_CAPITALIZE_WORDS = __PyTextInputTraitsConstants__.AutocapitalizationTypeWords

    FONT_TEXT_STYLE_BODY = "UICTFontTextStyleBody"
    FONT_TEXT_STYLE_CALLOUT = "UICTFontTextStyleCallout"
    FONT_TEXT_STYLE_CAPTION_1 = "UICTFontTextStyleCaption1"
    FONT_TEXT_STYLE_CAPTION_2 = "UICTFontTextStyleCaption2"
    FONT_TEXT_STYLE_FOOTNOTE = "UICTFontTextStyleFootnote"
    FONT_TEXT_STYLE_HEADLINE = "UICTFontTextStyleHeadline"
    FONT_TEXT_STYLE_SUBHEADLINE = "UICTFontTextStyleSubhead"
    FONT_TEXT_STYLE_LARGE_TITLE = "UICTFontTextStyleTitle0"
    FONT_TEXT_STYLE_TITLE_1 = "UICTFontTextStyleTitle1"
    FONT_TEXT_STYLE_TITLE_2 = "UICTFontTextStyleTitle2"
    FONT_TEXT_STYLE_TITLE_3 = "UICTFontTextStyleTitle3"

    try:
        FONT_LABEL_SIZE = __UIFont__.labelFontSize()
        FONT_BUTTON_SIZE = __UIFont__.buttonFontSize()
        FONT_SMALL_SYSTEM_SIZE = __UIFont__.smallSystemFontSize()
        FONT_SYSTEM_SIZE = __UIFont__.systemFontSize()
    except TypeError:  # iOS / iPadOS 14
        FONT_LABEL_SIZE = __UIFont__.labelFontSize
        FONT_BUTTON_SIZE = __UIFont__.buttonFontSize
        FONT_SMALL_SYSTEM_SIZE = __UIFont__.smallSystemFontSize
        FONT_SYSTEM_SIZE = __UIFont__.systemFontSize

    PRESENTATION_MODE_SHEET = __PyView__.PresentationModeSheet
    PRESENTATION_MODE_FULLSCREEN = __PyView__.PresentationModeFullScreen
    PRESENTATION_MODE_WIDGET = __PyView__.PresentationModeWidget

    APPEARANCE_UNSPECIFIED = __PyView__.AppearanceUnspecified
    APPEARANCE_LIGHT = __PyView__.AppearanceLight
    APPEARANCE_DARK = __PyView__.AppearanceDark

    CONTENT_MODE_SCALE_TO_FILL = __PyView__.ContentModeScaleToFill
    CONTENT_MODE_SCALE_ASPECT_FIT = __PyView__.ContentModeScaleAspectFit
    CONTENT_MODE_SCALE_ASPECT_FILL = __PyView__.ContentModeScaleAspectFill
    CONTENT_MODE_REDRAW = __PyView__.ContentModeRedraw
    CONTENT_MODE_CENTER = __PyView__.ContentModeCenter
    CONTENT_MODE_TOP = __PyView__.ContentModeTop
    CONTENT_MODE_BOTTOM = __PyView__.ContentModeBottom
    CONTENT_MODE_LEFT = __PyView__.ContentModeLeft
    CONTENT_MODE_RIGHT = __PyView__.ContentModeRight
    CONTENT_MODE_TOP_LEFT = __PyView__.ContentModeTopLeft
    CONTENT_MODE_TOP_RIGHT = __PyView__.ContentModeTopRight
    CONTENT_MODE_BOTTOM_LEFT = __PyView__.ContentModeBottomLeft
    CONTENT_MODE_BOTTOM_RIGHT = __PyView__.ContentModeBottomRight

    FLEXIBLE_WIDTH = 0
    FLEXIBLE_HEIGHT = 1
    FLEXIBLE_TOP_MARGIN = 2
    FLEXIBLE_BOTTOM_MARGIN = 3
    FLEXIBLE_LEFT_MARGIN = 4
    FLEXIBLE_RIGHT_MARGIN = 5

    HORZONTAL_ALIGNMENT_CENTER = __PyControl__.ContentHorizontalAlignmentCenter
    HORZONTAL_ALIGNMENT_FILL = __PyControl__.ContentHorizontalAlignmentFill
    HORZONTAL_ALIGNMENT_LEADING = __PyControl__.ContentHorizontalAlignmentLeading
    HORZONTAL_ALIGNMENT_LEFT = __PyControl__.ContentHorizontalAlignmentLeft
    HORZONTAL_ALIGNMENT_RIGHT = __PyControl__.ContentHorizontalAlignmentRight
    HORZONTAL_ALIGNMENT_TRAILING = __PyControl__.ContentHorizontalAlignmentTrailing

    VERTICAL_ALIGNMENT_BOTTOM = __PyControl__.ContentVerticalAlignmentBottom
    VERTICAL_ALIGNMENT_CENTER = __PyControl__.ContentVerticalAlignmentCenter
    VERTICAL_ALIGNMENT_FILL = __PyControl__.ContentVerticalAlignmentFill
    VERTICAL_ALIGNMENT_TOP = __PyControl__.ContentVerticalAlignmentTop

    BUTTON_TYPE_SYSTEM = __PyButton__.TypeSystem
    BUTTON_TYPE_CONTACT_ADD = __PyButton__.TypeContactAdd
    BUTTON_TYPE_CUSTOM = __PyButton__.TypeCustom
    BUTTON_TYPE_DETAIL_DISCLOSURE = __PyButton__.TypeDetailDisclosure
    BUTTON_TYPE_INFO_DARK = __PyButton__.TypeInfoDark
    BUTTON_TYPE_INFO_LIGHT = __PyButton__.TypeInfoLight

    TEXT_ALIGNMENT_LEFT = __PyLabel__.TextAlignmentLeft
    TEXT_ALIGNMENT_RIGHT = __PyLabel__.TextAlignmentRight
    TEXT_ALIGNMENT_CENTER = __PyLabel__.TextAlignmentCenter
    TEXT_ALIGNMENT_JUSTIFIED = __PyLabel__.TextAlignmentJustified
    TEXT_ALIGNMENT_NATURAL = __PyLabel__.TextAlignmentNatural

    LINE_BREAK_MODE_BY_WORD_WRAPPING = __PyLabel__.LineBreakModeByWordWrapping
    LINE_BREAK_MODE_BY_CHAR_WRAPPING = __PyLabel__.LineBreakModeByCharWrapping
    LINE_BREAK_MODE_BY_CLIPPING = __PyLabel__.LineBreakModeByClipping
    LINE_BREAK_MODE_BY_TRUNCATING_HEAD = __PyLabel__.LineBreakModeByTruncatingHead
    LINE_BREAK_MODE_BY_TRUNCATING_TAIL = __PyLabel__.LineBreakModeByTruncatingTail
    LINE_BREAK_MODE_BY_TRUNCATING_MIDDLE = __PyLabel__.LineBreakModeByTruncatingMiddle

    TOUCH_TYPE_DIRECT = __PyGestureRecognizer__.TouchTypeDirect
    TOUCH_TYPE_INDIRECT = __PyGestureRecognizer__.TouchTypeIndirect
    TOUCH_TYPE_PENCIL = __PyGestureRecognizer__.TouchTypePencil

    GESTURE_STATE_POSSIBLE = __PyGestureRecognizer__.GestureStatePossible
    GESTURE_STATE_BEGAN = __PyGestureRecognizer__.GestureStateBegan
    GESTURE_STATE_CHANGED = __PyGestureRecognizer__.GestureStateChanged
    GESTURE_STATE_ENDED = __PyGestureRecognizer__.GestureStateEnded
    GESTURE_STATE_CANCELLED = __PyGestureRecognizer__.GestureStateCancelled
    GESTURE_STATE_RECOGNIZED = __PyGestureRecognizer__.GestureStateRecognized

    TABLE_VIEW_CELL_STYLE_DEFAULT = __PyTableViewCell__.StyleDefault
    TABLE_VIEW_CELL_STYLE_SUBTITLE = __PyTableViewCell__.StyleSubtitle
    TABLE_VIEW_CELL_STYLE_VALUE1 = __PyTableViewCell__.StyleValue1
    TABLE_VIEW_CELL_STYLE_VALUE2 = __PyTableViewCell__.StyleValue2

    ACCESSORY_TYPE_NONE = __PyTableViewCell__.AccessoryTypeNone
    ACCESSORY_TYPE_CHECKMARK = __PyTableViewCell__.AccessoryTypeCheckmark
    ACCESSORY_TYPE_DETAIL_BUTTON = __PyTableViewCell__.AccessoryTypeDetailButton
    ACCESSORY_TYPE_DETAIL_DISCLOSURE_BUTTON = (
        __PyTableViewCell__.AccessoryTypeDetailDisclosureButton
    )
    ACCESSORY_TYPE_DISCLOSURE_INDICATOR = (
        __PyTableViewCell__.AccessoryTypeDisclosureIndicator
    )

    TABLE_VIEW_STYLE_PLAIN = __PyTableView__.StylePlain
    TABLE_VIEW_STYLE_GROUPED = __PyTableView__.StyleGrouped

    TEXT_FIELD_BORDER_STYLE_NONE = __PyTextField__.BorderStyleNone
    TEXT_FIELD_BORDER_STYLE_BEZEL = __PyTextField__.BorderStyleBezel
    TEXT_FIELD_BORDER_STYLE_LINE = __PyTextField__.BorderStyleLine
    TEXT_FIELD_BORDER_STYLE_ROUNDED_RECT = __PyTextField__.BorderStyleRoundedRect

    BUTTON_ITEM_STYLE_PLAIN = __PyButtonItem__.StylePlain
    BUTTON_ITEM_STYLE_DONE = __PyButtonItem__.StyleDone

    SYSTEM_ITEM_ACTION = __PyButtonItem__.SystemItemAction
    SYSTEM_ITEM_ADD = __PyButtonItem__.SystemItemAdd
    SYSTEM_ITEM_BOOKMARKS = __PyButtonItem__.SystemItemBookmarks
    SYSTEM_ITEM_CAMERA = __PyButtonItem__.SystemItemCamera
    SYSTEM_ITEM_CANCEL = __PyButtonItem__.SystemItemCancel
    SYSTEM_ITEM_COMPOSE = __PyButtonItem__.SystemItemCompose
    SYSTEM_ITEM_DONE = __PyButtonItem__.SystemItemDone
    SYSTEM_ITEM_EDIT = __PyButtonItem__.SystemItemEdit
    SYSTEM_ITEM_FAST_FORWARD = __PyButtonItem__.SystemItemFastForward
    SYSTEM_ITEM_FIXED_SPACE = __PyButtonItem__.SystemItemFixedSpace
    SYSTEM_ITEM_FLEXIBLE_SPACE = __PyButtonItem__.SystemItemFlexibleSpace
    SYSTEM_ITEM_ORGANIZE = __PyButtonItem__.SystemItemOrganize
    SYSTEM_ITEM_PAUSE = __PyButtonItem__.SystemItemPause
    SYSTEM_ITEM_PLAY = __PyButtonItem__.SystemItemPlay
    SYSTEM_ITEM_REDO = __PyButtonItem__.SystemItemRedo
    SYSTEM_ITEM_REFRESH = __PyButtonItem__.SystemItemRefresh
    SYSTEM_ITEM_REPLY = __PyButtonItem__.SystemItemReply
    SYSTEM_ITEM_REWIND = __PyButtonItem__.SystemItemRewind
    SYSTEM_ITEM_SAVE = __PyButtonItem__.SystemItemSave
    SYSTEM_ITEM_SEARCH = __PyButtonItem__.SystemItemSearch
    SYSTEM_ITEM_STOP = __PyButtonItem__.SystemItemStop
    SYSTEM_ITEM_TRASH = __PyButtonItem__.SystemItemTrash
    SYSTEM_ITEM_UNDO = __PyButtonItem__.SystemItemUndo

except AttributeError:

    COLOR_LABEL = Value()
    COLOR_SECONDARY_LABEL = Value()
    COLOR_TERTIARY_LABEL = Value()
    COLOR_QUATERNARY_LABEL = Value()
    COLOR_SYSTEM_FILL = Value()
    COLOR_SECONDARY_SYSTEM_FILL = Value()
    COLOR_TERTIARY_SYSTEM_FILL = Value()
    COLOR_QUATERNARY_SYSTEM_FILL = Value()
    COLOR_PLACEHOLDER_TEXT = Value()
    COLOR_SYSTEM_BACKGROUND = Value()
    COLOR_SECONDARY_SYSTEM_BACKGROUND = Value()
    COLOR_TERTIARY_SYSTEM_BACKGROUND = Value()
    COLOR_SYSTEM_GROUPED_BACKGROUND = Value()
    COLOR_SECONDARY_GROUPED_BACKGROUND = Value()
    COLOR_TERTIARY_GROUPED_BACKGROUND = Value()
    COLOR_SEPARATOR = Value()
    COLOR_OPAQUE_SEPARATOR = Value()
    COLOR_LINK = Value()
    COLOR_DARK_TEXT = Value()
    COLOR_LIGHT_TEXT = Value()
    COLOR_SYSTEM_BLUE = Value()
    COLOR_SYSTEM_GREEN = Value()
    COLOR_SYSTEM_INDIGO = Value()
    COLOR_SYSTEM_ORANGE = Value()
    COLOR_SYSTEM_PINK = Value()
    COLOR_SYSTEM_PURPLE = Value()
    COLOR_SYSTEM_RED = Value()
    COLOR_SYSTEM_TEAL = Value()
    COLOR_SYSTEM_YELLOW = Value()
    COLOR_SYSTEM_GRAY = Value()
    COLOR_SYSTEM_GRAY2 = Value()
    COLOR_SYSTEM_GRAY3 = Value()
    COLOR_SYSTEM_GRAY4 = Value()
    COLOR_SYSTEM_GRAY5 = Value()
    COLOR_SYSTEM_GRAY6 = Value()
    COLOR_CLEAR = Value()
    COLOR_BLACK = Value()
    COLOR_BLUE = Value()
    COLOR_BROWN = Value()
    COLOR_CYAN = Value()
    COLOR_DARK_GRAY = Value()
    COLOR_GRAY = Value()
    COLOR_GREEN = Value()
    COLOR_LIGHT_GRAY = Value()
    COLOR_MAGENTA = Value()
    COLOR_ORANGE = Value()
    COLOR_PURPLE = Value()
    COLOR_RED = Value()
    COLOR_WHITE = Value()
    COLOR_YELLOW = Value()

    GESTURE_TYPE_NONE = Value()
    GESTURE_TYPE_LONG_PRESS = Value()
    GESTURE_TYPE_PAN = Value()
    GESTURE_TYPE_TAP = Value()

    KEYBOARD_APPEARANCE_DEFAULT = Value()
    KEYBOARD_APPEARANCE_LIGHT = Value()
    KEYBOARD_APPEARANCE_DARK = Value()
    KEYBOARD_TYPE_DEFAULT = Value()
    KEYBOARD_TYPE_ALPHABET = Value()
    KEYBOARD_TYPE_ASCII_CAPABLE = Value()
    KEYBOARD_TYPE_ASCII_CAPABLE_NUMBER_PAD = Value()
    KEYBOARD_TYPE_DECIMAL_PAD = Value()
    KEYBOARD_TYPE_EMAIL_ADDRESS = Value()
    KEYBOARD_TYPE_NAME_PHONE_PAD = Value()
    KEYBOARD_TYPE_NUMBER_PAD = Value()
    KEYBOARD_TYPE_NUMBERS_AND_PUNCTUATION = Value()
    KEYBOARD_TYPE_PHONE_PAD = Value()
    KEYBOARD_TYPE_TWITTER = Value()
    KEYBOARD_TYPE_URL = Value()
    KEYBOARD_TYPE_WEB_SEARCH = Value()

    RETURN_KEY_TYPE_DEFAULT = Value()
    RETURN_KEY_TYPE_CONTINUE = Value()
    RETURN_KEY_TYPE_DONE = Value()
    RETURN_KEY_TYPE_EMERGENCY_CALL = Value()
    RETURN_KEY_TYPE_GO = Value()
    RETURN_KEY_TYPE_GOOGLE = Value()
    RETURN_KEY_TYPE_JOIN = Value()
    RETURN_KEY_TYPE_NEXT = Value()
    RETURN_KEY_TYPE_ROUTE = Value()
    RETURN_KEY_TYPE_SEARCH = Value()
    RETURN_KEY_TYPE_SEND = Value()
    RETURN_KEY_TYPE_YAHOO = Value()

    AUTO_CAPITALIZE_NONE = Value()
    AUTO_CAPITALIZE_ALL = Value()
    AUTO_CAPITALIZE_SENTENCES = Value()
    AUTO_CAPITALIZE_WORDS = Value()

    FONT_TEXT_STYLE_BODY = Value()
    FONT_TEXT_STYLE_CALLOUT = Value()
    FONT_TEXT_STYLE_CAPTION_1 = Value()
    FONT_TEXT_STYLE_CAPTION_2 = Value()
    FONT_TEXT_STYLE_FOOTNOTE = Value()
    FONT_TEXT_STYLE_HEADLINE = Value()
    FONT_TEXT_STYLE_SUBHEADLINE = Value()
    FONT_TEXT_STYLE_LARGE_TITLE = Value()
    FONT_TEXT_STYLE_TITLE_1 = Value()
    FONT_TEXT_STYLE_TITLE_2 = Value()
    FONT_TEXT_STYLE_TITLE_3 = Value()
    FONT_LABEL_SIZE = Value()
    FONT_BUTTON_SIZE = Value()
    FONT_SMALL_SYSTEM_SIZE = Value()
    FONT_SYSTEM_SIZE = Value()

    PRESENTATION_MODE_SHEET = Value()
    PRESENTATION_MODE_FULLSCREEN = Value()
    PRESENTATION_MODE_WIDGET = Value()

    APPEARANCE_UNSPECIFIED = Value()
    APPEARANCE_LIGHT = Value()
    APPEARANCE_DARK = Value()

    FLEXIBLE_WIDTH = Value()
    FLEXIBLE_HEIGHT = Value()
    FLEXIBLE_TOP_MARGIN = Value()
    FLEXIBLE_BOTTOM_MARGIN = Value()
    FLEXIBLE_LEFT_MARGIN = Value()
    FLEXIBLE_RIGHT_MARGIN = Value()

    CONTENT_MODE_SCALE_TO_FILL = Value()
    CONTENT_MODE_SCALE_ASPECT_FIT = Value()
    CONTENT_MODE_SCALE_ASPECT_FILL = Value()
    CONTENT_MODE_REDRAW = Value()
    CONTENT_MODE_CENTER = Value()
    CONTENT_MODE_TOP = Value()
    CONTENT_MODE_BOTTOM = Value()
    CONTENT_MODE_LEFT = Value()
    CONTENT_MODE_RIGHT = Value()
    CONTENT_MODE_TOP_LEFT = Value()
    CONTENT_MODE_TOP_RIGHT = Value()
    CONTENT_MODE_BOTTOM_LEFT = Value()
    CONTENT_MODE_BOTTOM_RIGHT = Value()

    HORZONTAL_ALIGNMENT_CENTER = Value()
    HORZONTAL_ALIGNMENT_FILL = Value()
    HORZONTAL_ALIGNMENT_LEADING = Value()
    HORZONTAL_ALIGNMENT_LEFT = Value()
    HORZONTAL_ALIGNMENT_RIGHT = Value()
    HORZONTAL_ALIGNMENT_TRAILING = Value()

    VERTICAL_ALIGNMENT_BOTTOM = Value()
    VERTICAL_ALIGNMENT_CENTER = Value()
    VERTICAL_ALIGNMENT_FILL = Value()
    VERTICAL_ALIGNMENT_TOP = Value()

    BUTTON_TYPE_SYSTEM = Value()
    BUTTON_TYPE_CONTACT_ADD = Value()
    BUTTON_TYPE_CUSTOM = Value()
    BUTTON_TYPE_DETAIL_DISCLOSURE = Value()
    BUTTON_TYPE_INFO_DARK = Value()
    BUTTON_TYPE_INFO_LIGHT = Value()

    TEXT_ALIGNMENT_LEFT = Value()
    TEXT_ALIGNMENT_RIGHT = Value()
    TEXT_ALIGNMENT_CENTER = Value()
    TEXT_ALIGNMENT_JUSTIFIED = Value()
    TEXT_ALIGNMENT_NATURAL = Value()

    LINE_BREAK_MODE_BY_WORD_WRAPPING = Value()
    LINE_BREAK_MODE_BY_CHAR_WRAPPING = Value()
    LINE_BREAK_MODE_BY_CLIPPING = Value()
    LINE_BREAK_MODE_BY_TRUNCATING_HEAD = Value()
    LINE_BREAK_MODE_BY_TRUNCATING_TAIL = Value()
    LINE_BREAK_MODE_BY_TRUNCATING_MIDDLE = Value()

    TOUCH_TYPE_DIRECT = Value()
    TOUCH_TYPE_INDIRECT = Value()
    TOUCH_TYPE_PENCIL = Value()

    GESTURE_STATE_POSSIBLE = Value()
    GESTURE_STATE_BEGAN = Value()
    GESTURE_STATE_CHANGED = Value()
    GESTURE_STATE_ENDED = Value()
    GESTURE_STATE_CANCELLED = Value()
    GESTURE_STATE_RECOGNIZED = Value()

    TABLE_VIEW_CELL_STYLE_DEFAULT = Value()
    TABLE_VIEW_CELL_STYLE_SUBTITLE = Value()
    TABLE_VIEW_CELL_STYLE_VALUE1 = Value()
    TABLE_VIEW_CELL_STYLE_VALUE2 = Value()

    ACCESSORY_TYPE_NONE = Value()
    ACCESSORY_TYPE_CHECKMARK = Value()
    ACCESSORY_TYPE_DETAIL_BUTTON = Value()
    ACCESSORY_TYPE_DETAIL_DISCLOSURE_BUTTON = Value()
    ACCESSORY_TYPE_DISCLOSURE_INDICATOR = Value()

    TABLE_VIEW_STYLE_PLAIN = Value()
    TABLE_VIEW_STYLE_GROUPED = Value()
    TEXT_FIELD_BORDER_STYLE_NONE = Value()
    TEXT_FIELD_BORDER_STYLE_BEZEL = Value()
    TEXT_FIELD_BORDER_STYLE_LINE = Value()
    TEXT_FIELD_BORDER_STYLE_ROUNDED_RECT = Value()

    BUTTON_ITEM_STYLE_PLAIN = Value()
    BUTTON_ITEM_STYLE_DONE = Value()

    SYSTEM_ITEM_ACTION = Value()
    SYSTEM_ITEM_ADD = Value()
    SYSTEM_ITEM_BOOKMARKS = Value()
    SYSTEM_ITEM_CAMERA = Value()
    SYSTEM_ITEM_CANCEL = Value()
    SYSTEM_ITEM_COMPOSE = Value()
    SYSTEM_ITEM_DONE = Value()
    SYSTEM_ITEM_EDIT = Value()
    SYSTEM_ITEM_FAST_FORWARD = Value()
    SYSTEM_ITEM_FIXED_SPACE = Value()
    SYSTEM_ITEM_FLEXIBLE_SPACE = Value()
    SYSTEM_ITEM_ORGANIZE = Value()
    SYSTEM_ITEM_PAUSE = Value()
    SYSTEM_ITEM_PLAY = Value()
    SYSTEM_ITEM_REDO = Value()
    SYSTEM_ITEM_REFRESH = Value()
    SYSTEM_ITEM_REPLY = Value()
    SYSTEM_ITEM_REWIND = Value()
    SYSTEM_ITEM_SAVE = Value()
    SYSTEM_ITEM_SEARCH = Value()
    SYSTEM_ITEM_STOP = Value()
    SYSTEM_ITEM_TRASH = Value()
    SYSTEM_ITEM_UNDO = Value()
