"""
UI for scripts

The ``pyto_ui`` module contains classes for building and presenting a native UI, in app or in the Today Widget.
This library's API is very similar to UIKit.

This library may have a lot of similarities with ``UIKit``, but subclassing isn't supported very well. Instead of overriding methods, you will often need to set properties to a function. For properties, setters are what makes the passed value take effect, so instead of override the getter, you should just set properties. If you really want to subclass a :class:`View`, you can set properties from the initializer.

(Many docstrings are quoted from the Apple Documentation)
"""

from __future__ import annotations
from UIKit import UIFont as __UIFont__, UIImage, UIView, UIViewController
from Foundation import NSThread
from typing import List, Callable, Tuple
from pyto import __Class__, ConsoleViewController, PyAlert as __PyAlert__
from __check_type__ import check
from __image__ import __ui_image_from_pil_image__, __pil_image_from_ui_image__
from time import sleep
from io import BytesIO
from threading import Thread
from mainthread import mainthread
import __pyto_ui_garbage_collector__ as _gc
import os
import sys
import base64
import threading
import _values
import ui_constants
import builtins
from timeit import default_timer as timer

try:
    from rubicon.objc import ObjCClass, CGFloat
    from rubicon.objc.api import NSString
except ValueError:

    def ObjCClass(class_name):
        return None


if "widget" not in os.environ:
    from urllib.request import urlopen

    try:
        from PIL import Image
    except ImportError:
        pass


class __v__:
    def __init__(self, string):
        self.s = string

    def __eq__(self, other):
        return other == self.s

    def __repr__(self):
        return self.s


#############################
# MARK: - Objective-C Classes
#############################

__PyView__ = __Class__("PyView")
__PyControl__ = __Class__("PyControl")
__PySlider__ = __Class__("PySlider")
__PySegmentedControl__ = __Class__("PySegmentedControl")
__PySwitch__ = __Class__("PySwitch")
__PyButton__ = __Class__("PyButton")
__PyLabel__ = __Class__("PyLabel")
__UIImageView__ = __Class__("PyImageView")
__PyTextView__ = __Class__("PyTextView")
__PyTextField__ = __Class__("PyTextField")
__PyTableView__ = __Class__("PyTableView")
__PyTableViewCell__ = __Class__("PyTableViewCell")
__PyTableViewSection__ = __Class__("PyTableViewSection")
__PyWebView__ = __Class__("PyWebView")
__PyGestureRecognizer__ = __Class__("PyGestureRecognizer")
__PyUIKitView__ = __Class__("PyUIKitView")

__PyColor__ = __Class__("PyColor")
__PyButtonItem__ = __Class__("PyButtonItem")
__PyTextInputTraitsConstants__ = __Class__("PyTextInputTraitsConstants")

try:
    __NSData__ = ObjCClass("NSData")
except NameError:
    pass

###################
# MARK: - Constants
###################

# MARK: - Gesture Recognizer Type

GESTURE_TYPE = ui_constants.GESTURE_TYPE

GESTURE_TYPE_LONG_PRESS = ui_constants.GESTURE_TYPE_LONG_PRESS
"""
A long press gesture.
"""

GESTURE_TYPE_PAN = ui_constants.GESTURE_TYPE_PAN
"""
A dragging gesture.
"""

GESTURE_TYPE_TAP = ui_constants.GESTURE_TYPE_TAP
"""
A tap gesture.
"""

# MARK: - Keyboard Appearance

KEYBOARD_APPEARANCE = ui_constants.KEYBOARD_APPEARANCE

KEYBOARD_APPEARANCE_DEFAULT = ui_constants.KEYBOARD_APPEARANCE_DEFAULT
"""
Specifies the default keyboard appearance for the current input method.
"""

KEYBOARD_APPEARANCE_LIGHT = ui_constants.KEYBOARD_APPEARANCE_LIGHT
"""
Specifies a keyboard appearance suitable for a light UI look.
"""

KEYBOARD_APPEARANCE_DARK = ui_constants.KEYBOARD_APPEARANCE_DARK
"""
Specifies a keyboard appearance suitable for a dark UI look.
"""

# MARK: - Keyboard Type

KEYBOARD_TYPE = ui_constants.KEYBOARD_TYPE

KEYBOARD_TYPE_DEFAULT = ui_constants.KEYBOARD_TYPE_DEFAULT
"""
Specifies the default keyboard for the current input method.
"""

KEYBOARD_TYPE_ASCII_CAPABLE = ui_constants.KEYBOARD_TYPE_ASCII_CAPABLE
"""
Specifies a keyboard that displays standard ASCII characters.
"""

KEYBOARD_TYPE_ASCII_CAPABLE_NUMBER_PAD = (
    ui_constants.KEYBOARD_TYPE_ASCII_CAPABLE_NUMBER_PAD
)
"""
Specifies a number pad that outputs only ASCII digits.
"""

KEYBOARD_TYPE_DECIMAL_PAD = ui_constants.KEYBOARD_TYPE_DECIMAL_PAD
"""
Specifies a keyboard with numbers and a decimal point.
"""

KEYBOARD_TYPE_EMAIL_ADDRESS = ui_constants.KEYBOARD_TYPE_EMAIL_ADDRESS
"""
Specifies a keyboard optimized for entering email addresses. This keyboard type prominently features the at (“@”), period (“.”) and space characters.
"""

KEYBOARD_TYPE_NAME_PHONE_PAD = ui_constants.KEYBOARD_TYPE_NAME_PHONE_PAD
"""
Specifies a keypad designed for entering a person’s name or phone number. This keyboard type does not support auto-capitalization.
"""

KEYBOARD_TYPE_NUMBER_PAD = ui_constants.KEYBOARD_TYPE_NUMBER_PAD
"""
Specifies a numeric keypad designed for PIN entry. This keyboard type prominently features the numbers 0 through 9. This keyboard type does not support auto-capitalization.
"""

KEYBOARD_TYPE_NUMBERS_AND_PUNCTUATION = (
    ui_constants.KEYBOARD_TYPE_NUMBERS_AND_PUNCTUATION
)
"""
Specifies the numbers and punctuation keyboard.
"""

KEYBOARD_TYPE_PHONE_PAD = ui_constants.KEYBOARD_TYPE_PHONE_PAD
"""
Specifies a keypad designed for entering telephone numbers. This keyboard type prominently features the numbers 0 through 9 and the “*” and “#” characters. This keyboard type does not support auto-capitalization.
"""

KEYBOARD_TYPE_TWITTER = ui_constants.KEYBOARD_TYPE_TWITTER
"""
Specifies a keyboard optimized for Twitter text entry, with easy access to the at (“@”) and hash (“#”) characters.
"""

KEYBOARD_TYPE_URL = ui_constants.KEYBOARD_TYPE_URL
"""
Specifies a keyboard optimized for URL entry. This keyboard type prominently features the period (“.”) and slash (“/”) characters and the “.com” string.
"""

KEYBOARD_TYPE_WEB_SEARCH = ui_constants.KEYBOARD_TYPE_WEB_SEARCH
"""
Specifies a keyboard optimized for web search terms and URL entry. This keyboard type prominently features the space and period (“.”) characters.
"""

# MARK: - Return Key Type

RETURN_KEY_TYPE = ui_constants.RETURN_KEY_TYPE

RETURN_KEY_TYPE_DEFAULT = ui_constants.RETURN_KEY_TYPE_DEFAULT
"""
Specifies that the visible title of the Return key is “return”.
"""

RETURN_KEY_TYPE_CONTINUE = ui_constants.RETURN_KEY_TYPE_CONTINUE
"""
Specifies that the visible title of the Return key is “Continue”.
"""

RETURN_KEY_TYPE_DONE = ui_constants.RETURN_KEY_TYPE_DONE
"""
Specifies that the visible title of the Return key is “Done”.
"""

RETURN_KEY_TYPE_EMERGENCY_CALL = ui_constants.RETURN_KEY_TYPE_EMERGENCY_CALL
"""
Specifies that the visible title of the Return key is “Emergency Call”.
"""

RETURN_KEY_TYPE_GO = ui_constants.RETURN_KEY_TYPE_GO
"""
Specifies that the visible title of the Return key is “Go”.
"""

RETURN_KEY_TYPE_GOOGLE = ui_constants.RETURN_KEY_TYPE_GOOGLE
"""
Specifies that the visible title of the Return key is “Google”.
"""

RETURN_KEY_TYPE_JOIN = ui_constants.RETURN_KEY_TYPE_JOIN
"""
Specifies that the visible title of the Return key is “Join”.
"""

RETURN_KEY_TYPE_NEXT = ui_constants.RETURN_KEY_TYPE_NEXT
"""
Specifies that the visible title of the Return key is “Next”.
"""

RETURN_KEY_TYPE_ROUTE = ui_constants.RETURN_KEY_TYPE_ROUTE
"""
Specifies that the visible title of the Return key is “Route”.
"""

RETURN_KEY_TYPE_SEARCH = ui_constants.RETURN_KEY_TYPE_SEARCH
"""
Specifies that the visible title of the Return key is “Search”.
"""

RETURN_KEY_TYPE_SEND = ui_constants.RETURN_KEY_TYPE_SEND
"""
Specifies that the visible title of the Return key is “Send”.
"""

RETURN_KEY_TYPE_YAHOO = ui_constants.RETURN_KEY_TYPE_YAHOO
"""
Specifies that the visible title of the Return key is “Yahoo”.
"""

# MARK: - Autocapitalization Type

AUTO_CAPITALIZE = ui_constants.AUTO_CAPITALIZE

AUTO_CAPITALIZE_NONE = ui_constants.AUTO_CAPITALIZE_NONE
"""
Specifies that there is no automatic text capitalization.
"""

AUTO_CAPITALIZE_ALL = ui_constants.AUTO_CAPITALIZE_ALL
"""
Specifies automatic capitalization of all characters, such as for entry of two-character state abbreviations for the United States.
"""

AUTO_CAPITALIZE_SENTENCES = ui_constants.AUTO_CAPITALIZE_SENTENCES
"""
Specifies automatic capitalization of the first letter of each sentence.
"""

AUTO_CAPITALIZE_WORDS = ui_constants.AUTO_CAPITALIZE_WORDS
"""
Specifies automatic capitalization of the first letter of each word.
"""

# MARK: - Font Text Style

FONT_TEXT_STYLE = ui_constants.FONT_TEXT_STYLE

FONT_TEXT_STYLE_BODY = ui_constants.FONT_TEXT_STYLE_BODY
"""
The font used for body text.
"""

FONT_TEXT_STYLE_CALLOUT = ui_constants.FONT_TEXT_STYLE_CALLOUT
"""
The font used for callouts.
"""

FONT_TEXT_STYLE_CAPTION_1 = ui_constants.FONT_TEXT_STYLE_CAPTION_1
"""
The font used for standard captions.
"""

FONT_TEXT_STYLE_CAPTION_2 = ui_constants.FONT_TEXT_STYLE_CAPTION_2
"""
The font used for alternate captions.
"""

FONT_TEXT_STYLE_FOOTNOTE = ui_constants.FONT_TEXT_STYLE_FOOTNOTE
"""
The font used in footnotes.
"""

FONT_TEXT_STYLE_HEADLINE = ui_constants.FONT_TEXT_STYLE_HEADLINE
"""
The font used for headings.
"""

FONT_TEXT_STYLE_SUBHEADLINE = ui_constants.FONT_TEXT_STYLE_SUBHEADLINE
"""
The font used for subheadings.
"""

FONT_TEXT_STYLE_LARGE_TITLE = ui_constants.FONT_TEXT_STYLE_LARGE_TITLE
"""
The font style for large titles.
"""

FONT_TEXT_STYLE_TITLE_1 = ui_constants.FONT_TEXT_STYLE_TITLE_1
"""
The font used for first level hierarchical headings.
"""

FONT_TEXT_STYLE_TITLE_2 = ui_constants.FONT_TEXT_STYLE_TITLE_2
"""
The font used for second level hierarchical headings.
"""

FONT_TEXT_STYLE_TITLE_3 = ui_constants.FONT_TEXT_STYLE_TITLE_3
"""
The font used for third level hierarchical headings.
"""

# MARK: - Font Size

FONT_SIZE = ui_constants.FONT_SIZE

FONT_LABEL_SIZE = ui_constants.FONT_LABEL_SIZE
"""
Returns the standard font size used for labels.
"""

FONT_BUTTON_SIZE = ui_constants.FONT_BUTTON_SIZE
"""
Returns the standard font size used for buttons.
"""

FONT_SMALL_SYSTEM_SIZE = ui_constants.FONT_SMALL_SYSTEM_SIZE
"""
Returns the size of the standard small system font.
"""

FONT_SYSTEM_SIZE = ui_constants.FONT_SYSTEM_SIZE
"""
Returns the size of the standard system font.
"""

# MARK: - Presentation Mode

PRESENTATION_MODE = ui_constants.PRESENTATION_MODE

PRESENTATION_MODE_SHEET = ui_constants.PRESENTATION_MODE_SHEET
"""
A presentation style that displays the content centered in the screen.
"""

PRESENTATION_MODE_FULLSCREEN = ui_constants.PRESENTATION_MODE_FULLSCREEN
"""
A presentation style in which the presented view covers the screen.
"""

PRESENTATION_MODE_WIDGET = ui_constants.PRESENTATION_MODE_WIDGET
"""
A presentation mode style which simulates a Today Widget. Should be used in app to preview how a widget will look.
"""

# MARK: - Appearance

APPEARANCE = ui_constants.APPEARANCE

APPEARANCE_UNSPECIFIED = ui_constants.APPEARANCE_UNSPECIFIED
"""
An unspecified interface style.
"""

APPEARANCE_LIGHT = ui_constants.APPEARANCE_LIGHT
"""
The light interface style.
"""

APPEARANCE_DARK = ui_constants.APPEARANCE_DARK
"""
The dark interface style.
"""

# MARK: - Auto Resizing

AUTO_RESIZING = ui_constants.AUTO_RESIZING

FLEXIBLE_WIDTH = ui_constants.FLEXIBLE_WIDTH
"""
Resizing performed by expanding or shrinking a view’s width.
"""

FLEXIBLE_HEIGHT = ui_constants.FLEXIBLE_HEIGHT
"""
Resizing performed by expanding or shrinking a view's height.
"""

FLEXIBLE_TOP_MARGIN = ui_constants.FLEXIBLE_TOP_MARGIN
"""
Resizing performed by expanding or shrinking a view in the direction of the top margin.
"""

FLEXIBLE_BOTTOM_MARGIN = ui_constants.FLEXIBLE_BOTTOM_MARGIN
"""
Resizing performed by expanding or shrinking a view in the direction of the bottom margin.
"""

FLEXIBLE_LEFT_MARGIN = ui_constants.FLEXIBLE_LEFT_MARGIN
"""
Resizing performed by expanding or shrinking a view in the direction of the left margin.
"""

FLEXIBLE_RIGHT_MARGIN = ui_constants.FLEXIBLE_RIGHT_MARGIN
"""
Resizing performed by expanding or shrinking a view in the direction of the right margin.
"""

# MARK: - Content Mode

CONTENT_MODE = ui_constants.CONTENT_MODE

CONTENT_MODE_SCALE_TO_FILL = ui_constants.CONTENT_MODE_SCALE_TO_FILL
"""
The option to scale the content to fit the size of itself by changing the aspect ratio of the content if necessary.
"""

CONTENT_MODE_SCALE_ASPECT_FIT = ui_constants.CONTENT_MODE_SCALE_ASPECT_FIT
"""
The option to scale the content to fit the size of the view by maintaining the aspect ratio. Any remaining area of the view’s bounds is transparent.
"""

CONTENT_MODE_SCALE_ASPECT_FILL = ui_constants.CONTENT_MODE_SCALE_ASPECT_FILL
"""
The option to scale the content to fill the size of the view. Some portion of the content may be clipped to fill the view’s bounds.
"""

CONTENT_MODE_REDRAW = ui_constants.CONTENT_MODE_REDRAW
"""
The option to redisplay the view when the bounds change by invoking the ``setNeedsDisplay()`` method.
"""

CONTENT_MODE_CENTER = ui_constants.CONTENT_MODE_CENTER
"""
The option to center the content in the view’s bounds, keeping the proportions the same.
"""

CONTENT_MODE_TOP = ui_constants.CONTENT_MODE_TOP
"""
The option to center the content aligned at the top in the view’s bounds.
"""

CONTENT_MODE_BOTTOM = ui_constants.CONTENT_MODE_BOTTOM
"""
The option to center the content aligned at the bottom in the view’s bounds.
"""

CONTENT_MODE_LEFT = ui_constants.CONTENT_MODE_LEFT
"""
The option to align the content on the left of the view.
"""

CONTENT_MODE_RIGHT = ui_constants.CONTENT_MODE_RIGHT
"""
The option to align the content on the right of the view.
"""

CONTENT_MODE_TOP_LEFT = ui_constants.CONTENT_MODE_TOP_LEFT
"""
The option to align the content in the top-left corner of the view.
"""

CONTENT_MODE_TOP_RIGHT = ui_constants.CONTENT_MODE_TOP_RIGHT
"""
The option to align the content in the top-right corner of the view.
"""

CONTENT_MODE_BOTTOM_LEFT = ui_constants.CONTENT_MODE_BOTTOM_LEFT
"""
The option to align the content in the bottom-left corner of the view.
"""

CONTENT_MODE_BOTTOM_RIGHT = ui_constants.CONTENT_MODE_BOTTOM_RIGHT
"""
The option to align the content in the bottom-right corner of the view.
"""

# MARK: - Horizontal Alignment

HORZONTAL_ALIGNMENT = ui_constants.HORZONTAL_ALIGNMENT

HORZONTAL_ALIGNMENT_CENTER = ui_constants.HORZONTAL_ALIGNMENT_CENTER
"""
Aligns the content horizontally in the center of the control.
"""

HORZONTAL_ALIGNMENT_FILL = ui_constants.HORZONTAL_ALIGNMENT_FILL
"""
Aligns the content horizontally to fill the content rectangles; text may wrap and images may be stretched.
"""

HORZONTAL_ALIGNMENT_LEADING = ui_constants.HORZONTAL_ALIGNMENT_LEADING
"""
Aligns the content horizontally from the leading edge of the control.
"""

HORZONTAL_ALIGNMENT_LEFT = ui_constants.HORZONTAL_ALIGNMENT_LEFT
"""
Aligns the content horizontally from the left of the control (the default).
"""

HORZONTAL_ALIGNMENT_RIGHT = ui_constants.HORZONTAL_ALIGNMENT_RIGHT
"""
Aligns the content horizontally from the right of the control.
"""

HORZONTAL_ALIGNMENT_TRAILING = ui_constants.HORZONTAL_ALIGNMENT_TRAILING
"""
Aligns the content horizontally from the trailing edge of the control.
"""

# MARK: - Vertical Alignment

VERTICAL_ALIGNMENT = ui_constants.VERTICAL_ALIGNMENT

VERTICAL_ALIGNMENT_BOTTOM = ui_constants.VERTICAL_ALIGNMENT_BOTTOM
"""
Aligns the content vertically at the bottom in the control.
"""

VERTICAL_ALIGNMENT_CENTER = ui_constants.VERTICAL_ALIGNMENT_CENTER
"""
Aligns the content vertically in the center of the control.
"""

VERTICAL_ALIGNMENT_FILL = ui_constants.VERTICAL_ALIGNMENT_FILL
"""
Aligns the content vertically to fill the content rectangle; images may be stretched.
"""

VERTICAL_ALIGNMENT_TOP = ui_constants.VERTICAL_ALIGNMENT_TOP
"""
Aligns the content vertically at the top in the control (the default).
"""

# MARK: - Button Type

BUTTON_TYPE = ui_constants.BUTTON_TYPE

BUTTON_TYPE_SYSTEM = ui_constants.BUTTON_TYPE_SYSTEM
"""
A system style button, such as those shown in navigation bars and toolbars.
"""

BUTTON_TYPE_CONTACT_ADD = ui_constants.BUTTON_TYPE_CONTACT_ADD
"""
A contact add button.
"""

BUTTON_TYPE_CUSTOM = ui_constants.BUTTON_TYPE_CUSTOM
"""
No button style.
"""

BUTTON_TYPE_DETAIL_DISCLOSURE = ui_constants.BUTTON_TYPE_DETAIL_DISCLOSURE
"""
A detail disclosure button.
"""

BUTTON_TYPE_INFO_DARK = ui_constants.BUTTON_TYPE_INFO_DARK
"""
An information button that has a dark background.
"""

BUTTON_TYPE_INFO_LIGHT = ui_constants.BUTTON_TYPE_INFO_LIGHT
"""
An information button that has a light background.
"""

# MARK: - Text Alignment

TEXT_ALIGNMENT = ui_constants.TEXT_ALIGNMENT

TEXT_ALIGNMENT_LEFT = ui_constants.TEXT_ALIGNMENT_LEFT
"""
Text is visually left aligned.
"""

TEXT_ALIGNMENT_RIGHT = ui_constants.TEXT_ALIGNMENT_RIGHT
"""
Text is visually right aligned.
"""

TEXT_ALIGNMENT_CENTER = ui_constants.TEXT_ALIGNMENT_CENTER
"""
Text is visually center aligned.
"""

TEXT_ALIGNMENT_JUSTIFIED = ui_constants.TEXT_ALIGNMENT_JUSTIFIED
"""
Text is justified.
"""

TEXT_ALIGNMENT_NATURAL = ui_constants.TEXT_ALIGNMENT_NATURAL
"""
Use the default alignment associated with the current localization of the app. The default alignment for left-to-right scripts is left, and the default alignment for right-to-left scripts is right.
"""

# MARK: - Line Break Mode

LINE_BREAK_MODE = ui_constants.LINE_BREAK_MODE

LINE_BREAK_MODE_BY_WORD_WRAPPING = ui_constants.LINE_BREAK_MODE_BY_WORD_WRAPPING
"""
Wrapping occurs at word boundaries, unless the word itself doesn’t fit on a single line.
"""

LINE_BREAK_MODE_BY_CHAR_WRAPPING = ui_constants.LINE_BREAK_MODE_BY_CHAR_WRAPPING
"""
Wrapping occurs before the first character that doesn’t fit.
"""

LINE_BREAK_MODE_BY_CLIPPING = ui_constants.LINE_BREAK_MODE_BY_CLIPPING
"""
Lines are simply not drawn past the edge of the text container.
"""

LINE_BREAK_MODE_BY_TRUNCATING_HEAD = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_HEAD
"""
The line is displayed so that the end fits in the container and the missing text at the beginning of the line is indicated by an ellipsis glyph. Although this mode works for multiline text, it is more often used for single line text.
"""

LINE_BREAK_MODE_BY_TRUNCATING_TAIL = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_TAIL
"""
The line is displayed so that the beginning fits in the container and the missing text at the end of the line is indicated by an ellipsis glyph. Although this mode works for multiline text, it is more often used for single line text.
"""

LINE_BREAK_MODE_BY_TRUNCATING_MIDDLE = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_MIDDLE
"""
The line is displayed so that the beginning and end fit in the container and the missing text in the middle is indicated by an ellipsis glyph. This mode is used for single-line layout; using it with multiline text truncates the text into a single line.
"""

# MARK: - Touch Type

TOUCH_TYPE = ui_constants.TOUCH_TYPE

TOUCH_TYPE_DIRECT = ui_constants.TOUCH_TYPE_DIRECT
"""
A touch resulting from direct contact with the screen.
"""

TOUCH_TYPE_INDIRECT = ui_constants.TOUCH_TYPE_INDIRECT
"""
A touch that did not result from contact with the screen.
"""

TOUCH_TYPE_PENCIL = ui_constants.TOUCH_TYPE_PENCIL
"""
A touch from Apple Pencil.
"""

# MARK: - Gesture State

GESTURE_STATE = ui_constants.GESTURE_STATE

GESTURE_STATE_POSSIBLE = ui_constants.GESTURE_STATE_POSSIBLE
"""
The gesture recognizer has not yet recognized its gesture, but may be evaluating touch events. This is the default state.
"""

GESTURE_STATE_BEGAN = ui_constants.GESTURE_STATE_BEGAN
"""
The gesture recognizer has received touch objects recognized as a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop.
"""

GESTURE_STATE_CHANGED = ui_constants.GESTURE_STATE_CHANGED
"""
The gesture recognizer has received touches recognized as a change to a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop.
"""

GESTURE_STATE_ENDED = ui_constants.GESTURE_STATE_ENDED
"""
The gesture recognizer has received touches recognized as the end of a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
"""

GESTURE_STATE_CANCELLED = ui_constants.GESTURE_STATE_CANCELLED
"""
The gesture recognizer has received touches resulting in the cancellation of a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
"""

GESTURE_STATE_RECOGNIZED = ui_constants.GESTURE_STATE_RECOGNIZED
"""
The gesture recognizer has received a multi-touch sequence that it recognizes as its gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
"""

# MARK: - Table View Cell Style

TABLE_VIEW_CELL_STYLE = ui_constants.TABLE_VIEW_CELL_STYLE

TABLE_VIEW_CELL_STYLE_DEFAULT = ui_constants.TABLE_VIEW_CELL_STYLE_DEFAULT
"""
A simple style for a cell with a text label (black and left-aligned) and an optional image view.
"""

TABLE_VIEW_CELL_STYLE_SUBTITLE = ui_constants.TABLE_VIEW_CELL_STYLE_SUBTITLE
"""
A style for a cell with a left-aligned label across the top and a left-aligned label below it in smaller gray text.
"""

TABLE_VIEW_CELL_STYLE_VALUE1 = ui_constants.TABLE_VIEW_CELL_STYLE_VALUE1
"""
A style for a cell with a label on the left side of the cell with left-aligned and black text; on the right side is a label that has smaller blue text and is right-aligned. The Settings application uses cells in this style.
"""

TABLE_VIEW_CELL_STYLE_VALUE2 = ui_constants.TABLE_VIEW_CELL_STYLE_VALUE2
"""
A style for a cell with a label on the left side of the cell with text that is right-aligned and blue; on the right side of the cell is another label with smaller text that is left-aligned and black. The Phone/Contacts application uses cells in this style.
"""


# MARK: - Table View Cell Accessory Type

ACCESSORY_TYPE = ui_constants.ACCESSORY_TYPE

ACCESSORY_TYPE_NONE = ui_constants.ACCESSORY_TYPE_NONE
"""
No accessory view.
"""

ACCESSORY_TYPE_CHECKMARK = ui_constants.ACCESSORY_TYPE_CHECKMARK
"""
A checkmark image.
"""

ACCESSORY_TYPE_DETAIL_BUTTON = ui_constants.ACCESSORY_TYPE_DETAIL_BUTTON
"""
An information button.
"""

ACCESSORY_TYPE_DETAIL_DISCLOSURE_BUTTON = (
    ui_constants.ACCESSORY_TYPE_DETAIL_DISCLOSURE_BUTTON
)
"""
An information button and a disclosure (chevron) control.
"""

ACCESSORY_TYPE_DISCLOSURE_INDICATOR = ui_constants.ACCESSORY_TYPE_DISCLOSURE_INDICATOR
"""
A chevron-shaped control for presenting new content.
"""

# MARK: - Table View Style

TABLE_VIEW_STYLE = ui_constants.TABLE_VIEW_STYLE

TABLE_VIEW_STYLE_PLAIN = ui_constants.TABLE_VIEW_STYLE_PLAIN
"""
A plain table view.
"""

TABLE_VIEW_STYLE_GROUPED = ui_constants.TABLE_VIEW_STYLE_GROUPED
"""
A table view whose sections present distinct groups of rows.
"""

# MARK: - Text Field Border Style

TEXT_FIELD_BORDER_STYLE = ui_constants.TEXT_FIELD_BORDER_STYLE

TEXT_FIELD_BORDER_STYLE_NONE = ui_constants.TEXT_FIELD_BORDER_STYLE_NONE
"""
The text field does not display a border.
"""

TEXT_FIELD_BORDER_STYLE_BEZEL = ui_constants.TEXT_FIELD_BORDER_STYLE_BEZEL
"""
Displays a bezel-style border for the text field. This style is typically used for standard data-entry fields.
"""

TEXT_FIELD_BORDER_STYLE_LINE = ui_constants.TEXT_FIELD_BORDER_STYLE_LINE
"""
Displays a thin rectangle around the text field.
"""

TEXT_FIELD_BORDER_STYLE_ROUNDED_RECT = ui_constants.TEXT_FIELD_BORDER_STYLE_ROUNDED_RECT
"""
Displays a rounded-style border for the text field.
"""

# MARK: - Button Item Style

BUTTON_ITEM_STYLE = ui_constants.BUTTON_ITEM_STYLE

BUTTON_ITEM_STYLE_PLAIN = ui_constants.BUTTON_ITEM_STYLE_PLAIN
"""
Glows when tapped. The default item style.
"""

BUTTON_ITEM_STYLE_DONE = ui_constants.BUTTON_ITEM_STYLE_DONE
"""
The style for a done button—for example, a button that completes some task and returns to the previous view.
"""

# MARK: - Button Item System Item

SYSTEM_ITEM = ui_constants.SYSTEM_ITEM

SYSTEM_ITEM_ACTION = ui_constants.SYSTEM_ITEM_ACTION
"""
The system action button.
"""

SYSTEM_ITEM_ADD = ui_constants.SYSTEM_ITEM_ADD
"""
The system plus button containing an icon of a plus sign.
"""

SYSTEM_ITEM_BOOKMARKS = ui_constants.SYSTEM_ITEM_BOOKMARKS
"""
The system bookmarks button.
"""

SYSTEM_ITEM_CAMERA = ui_constants.SYSTEM_ITEM_CAMERA
"""
The system camera button.
"""

SYSTEM_ITEM_CANCEL = ui_constants.SYSTEM_ITEM_CANCEL
"""
The system Cancel button, localized.
"""

SYSTEM_ITEM_COMPOSE = ui_constants.SYSTEM_ITEM_COMPOSE
"""
The system compose button.
"""

SYSTEM_ITEM_DONE = ui_constants.SYSTEM_ITEM_DONE
"""
The system Done button, localized.
"""

SYSTEM_ITEM_EDIT = ui_constants.SYSTEM_ITEM_EDIT
"""
The system Edit button, localized.
"""

SYSTEM_ITEM_FAST_FORWARD = ui_constants.SYSTEM_ITEM_FAST_FORWARD
"""
The system fast forward button.
"""

SYSTEM_ITEM_FLEXIBLE_SPACE = ui_constants.SYSTEM_ITEM_FLEXIBLE_SPACE
"""
Blank space to add between other items. The space is distributed equally between the other items. Other item properties are ignored when this value is set.
"""

SYSTEM_ITEM_ORGANIZE = ui_constants.SYSTEM_ITEM_ORGANIZE
"""
The system organize button.
"""

SYSTEM_ITEM_PAUSE = ui_constants.SYSTEM_ITEM_PAUSE
"""
The system pause button.
"""

SYSTEM_ITEM_PLAY = ui_constants.SYSTEM_ITEM_PLAY
"""
The system play button.
"""

SYSTEM_ITEM_REDO = ui_constants.SYSTEM_ITEM_REDO
"""
The system redo button.
"""

SYSTEM_ITEM_REFRESH = ui_constants.SYSTEM_ITEM_REFRESH
"""
The system refresh button.
"""

SYSTEM_ITEM_REPLY = ui_constants.SYSTEM_ITEM_REPLY
"""
The system reply button.
"""

SYSTEM_ITEM_REWIND = ui_constants.SYSTEM_ITEM_REWIND
"""
The system rewind button.
"""

SYSTEM_ITEM_SAVE = ui_constants.SYSTEM_ITEM_SAVE
"""
The system Save button, localized.
"""

SYSTEM_ITEM_SEARCH = ui_constants.SYSTEM_ITEM_SEARCH
"""
The system search button.
"""

SYSTEM_ITEM_STOP = ui_constants.SYSTEM_ITEM_STOP
"""
The system stop button.
"""

SYSTEM_ITEM_TRASH = ui_constants.SYSTEM_ITEM_TRASH
"""
The system trash button.
"""

SYSTEM_ITEM_UNDO = ui_constants.SYSTEM_ITEM_UNDO
"""
The system undo button.
"""

###############
# MARK: - Other Classes
###############

# MARK: - Color


class Color:
    """
    A ``Color`` object represents a color to be displayed on screen.

    Example:

    .. highlight:: python
    .. code-block:: python

        import pyto_ui as ui

        # RGB
        black = ui.Color.rgb(0, 0, 0, 1)

        # White
        white = ui.Color.white(1, 1)

        # Dynamic
        background = ui.Color.dynamic(light=white, dark=black)

    For pre-defined colors, see `Color <constants.html#ui-elements-colors>`_ constants.
    """

    __py_color__ = None

    def red(self) -> float:
        """
        Returns the red value of the color.

        :rtype: float
        """

        return float(self.__py_color__.red)

    def green(self) -> float:
        """
        Returns the green value of the color.

        :rtype: float
        """

        return float(self.__py_color__.green)

    def blue(self) -> float:
        """
        Returns the blue value of the color.

        :rtype: float
        """

        return float(self.__py_color__.blue)

    def alpha(self) -> float:
        """
        Returns the alpha value of the color.

        :rtype: float
        """

        return float(self.__py_color__.alpha)

    def __init__(self, py_color):
        self.__py_color__ = py_color

    # def __del__(self):
    #    self.__py_color__.release()

    def __repr__(self):
        return str(self.__py_color__.managed.description)

    @classmethod
    def rgb(cls, red: float, green: float, blue, alpha: float = 1) -> Color:
        """
        Initializes a color from RGB values.

        All values should be located between 0 and 1, not between 0 and 255.

        :param red: The red value.
        :param green: The geen value.
        :param blue: The blue value.
        :param alpha: The opacity value.

        :rtype: pyto_ui.Color
        """

        check(red, "red", [float, int])
        check(green, "green", [float, int])
        check(blue, "blue", [float, int])
        check(alpha, "alpha", [float, int])

        if red > 1 or green > 1 or blue > 1 or alpha > 1:
            raise ValueError("Values must be located between 0 and 1.")

        return cls(__PyColor__.colorWithRed(red, green=green, blue=blue, alpha=alpha))

    @classmethod
    def white(cls, white: float, alpha: float) -> Color:
        """
        Initializes and returns a color from white value.

        All values should be located between 0 and 1, not between 0 and 255.

        :param white: The grayscale value.
        :param alpha: The opacity value.

        :rtype: pyto_ui.Color
        """

        check(white, "white", [float, int])
        check(alpha, "alpha", [float, int])

        if white > 1 or alpha > 1:
            raise ValueError("Values must be located between 0 and 1.")

        return cls(__PyColor__.colorWithWhite(white, alpha=alpha))

    @classmethod
    def dynamic(cls, light: Color, dark: Color) -> Color:
        """
        Initializes and returns a color that dynamically changes in dark or light mode.

        :param light: :class:`~pyto_ui.Color` object to be displayed in light mode.
        :param dark: :class:`~pyto_ui.Color` object to be displayed in dark mode.

        :rtype: pyto_ui.Color
        """

        check(light, "light", Color)
        check(dark, "dark", Color)

        return cls(
            __PyColor__.colorWithLight(light.__py_color__, dark=dark.__py_color__)
        )

    def __eq__(self, other):
        try:
            return (
                self.red() == other.red()
                and self.green() == other.green()
                and self.blue() == other.blue()
                and self.alpha() == other.alpha()
            )
        except AttributeError:
            return False


COLOR_LABEL = Color(ui_constants.COLOR_LABEL)
""" The color for text labels containing primary content. """

COLOR_SECONDARY_LABEL = Color(ui_constants.COLOR_SECONDARY_LABEL)
""" The color for text labels containing secondary content. """

COLOR_TERTIARY_LABEL = Color(ui_constants.COLOR_TERTIARY_LABEL)
""" The color for text labels containing tertiary content. """

COLOR_QUATERNARY_LABEL = Color(ui_constants.COLOR_QUATERNARY_LABEL)
""" The color for text labels containing quaternary content. """

COLOR_SYSTEM_FILL = Color(ui_constants.COLOR_SYSTEM_FILL)
""" An overlay fill color for thin and small shapes. """

COLOR_SECONDARY_SYSTEM_FILL = Color(ui_constants.COLOR_SECONDARY_SYSTEM_FILL)
""" An overlay fill color for medium-size shapes. """

COLOR_TERTIARY_SYSTEM_FILL = Color(ui_constants.COLOR_TERTIARY_SYSTEM_FILL)
""" An overlay fill color for large shapes. """

COLOR_QUATERNARY_SYSTEM_FILL = Color(ui_constants.COLOR_QUATERNARY_SYSTEM_FILL)
""" An overlay fill color for large areas containing complex content. """

COLOR_PLACEHOLDER_TEXT = Color(ui_constants.COLOR_PLACEHOLDER_TEXT)
""" The color for placeholder text in controls or text views. """

COLOR_SYSTEM_BACKGROUND = Color(ui_constants.COLOR_SYSTEM_BACKGROUND)
""" The color for the main background of your interface. """

COLOR_SECONDARY_SYSTEM_BACKGROUND = Color(
    ui_constants.COLOR_SECONDARY_SYSTEM_BACKGROUND
)
""" The color for content layered on top of the main background. """

COLOR_TERTIARY_SYSTEM_BACKGROUND = Color(ui_constants.COLOR_TERTIARY_SYSTEM_BACKGROUND)
""" The color for content layered on top of secondary backgrounds. """

COLOR_SYSTEM_GROUPED_BACKGROUND = Color(ui_constants.COLOR_SYSTEM_GROUPED_BACKGROUND)
""" The color for the main background of your grouped interface. """

COLOR_SECONDARY_GROUPED_BACKGROUND = Color(
    ui_constants.COLOR_SECONDARY_GROUPED_BACKGROUND
)
""" The color for content layered on top of the main background of your grouped interface. """

COLOR_TERTIARY_GROUPED_BACKGROUND = Color(
    ui_constants.COLOR_TERTIARY_GROUPED_BACKGROUND
)
""" The color for content layered on top of secondary backgrounds of your grouped interface. """

COLOR_SEPARATOR = Color(ui_constants.COLOR_SEPARATOR)
""" The color for thin borders or divider lines that allows some underlying content to be visible. """

COLOR_OPAQUE_SEPARATOR = Color(ui_constants.COLOR_OPAQUE_SEPARATOR)
""" The color for borders or divider lines that hide any underlying content. """

COLOR_LINK = Color(ui_constants.COLOR_LINK)
""" The color for links. """

COLOR_DARK_TEXT = Color(ui_constants.COLOR_DARK_TEXT)
""" The nonadaptable system color for text on a light background. """

COLOR_LIGHT_TEXT = Color(ui_constants.COLOR_LIGHT_TEXT)
""" The nonadaptable system color for text on a dark background. """

COLOR_SYSTEM_BLUE = Color(ui_constants.COLOR_SYSTEM_BLUE)
""" A blue color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_GREEN = Color(ui_constants.COLOR_SYSTEM_GREEN)
""" A green color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_INDIGO = Color(ui_constants.COLOR_SYSTEM_INDIGO)
""" An indigo color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_ORANGE = Color(ui_constants.COLOR_SYSTEM_ORANGE)
""" An orange color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_PINK = Color(ui_constants.COLOR_SYSTEM_PINK)
""" A pink color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_PURPLE = Color(ui_constants.COLOR_SYSTEM_PURPLE)
""" A purple color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_RED = Color(ui_constants.COLOR_SYSTEM_RED)
""" A red color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_TEAL = Color(ui_constants.COLOR_SYSTEM_TEAL)
""" A teal color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_YELLOW = Color(ui_constants.COLOR_SYSTEM_YELLOW)
""" A yellow color that automatically adapts to the current trait environment. """

COLOR_SYSTEM_GRAY = Color(ui_constants.COLOR_SYSTEM_GRAY)
""" The base gray color. """

COLOR_SYSTEM_GRAY2 = Color(ui_constants.COLOR_SYSTEM_GRAY2)
""" A second-level shade of grey. """

COLOR_SYSTEM_GRAY3 = Color(ui_constants.COLOR_SYSTEM_GRAY3)
""" A third-level shade of grey. """

COLOR_SYSTEM_GRAY4 = Color(ui_constants.COLOR_SYSTEM_GRAY4)
""" A fourth-level shade of grey. """

COLOR_SYSTEM_GRAY5 = Color(ui_constants.COLOR_SYSTEM_GRAY5)
""" A fifth-level shade of grey. """

COLOR_SYSTEM_GRAY6 = Color(ui_constants.COLOR_SYSTEM_GRAY6)
""" A sixth-level shade of grey. """

COLOR_CLEAR = Color(ui_constants.COLOR_CLEAR)
""" A color object with grayscale and alpha values that are both 0.0. """

COLOR_BLACK = Color(ui_constants.COLOR_BLACK)
""" A color object in the sRGB color space with a grayscale value of 0.0 and an alpha value of 1.0. """

COLOR_BLUE = Color(ui_constants.COLOR_BLUE)
""" A color object with RGB values of 0.0, 0.0, and 1.0 and an alpha value of 1.0. """

COLOR_BROWN = Color(ui_constants.COLOR_BROWN)
""" A color object with RGB values of 0.6, 0.4, and 0.2 and an alpha value of 1.0. """

COLOR_CYAN = Color(ui_constants.COLOR_CYAN)
""" A color object with RGB values of 0.0, 1.0, and 1.0 and an alpha value of 1.0. """

COLOR_DARK_GRAY = Color(ui_constants.COLOR_DARK_GRAY)
""" A color object with a grayscale value of 1/3 and an alpha value of 1.0. """

COLOR_GRAY = Color(ui_constants.COLOR_GRAY)
""" A color object with a grayscale value of 0.5 and an alpha value of 1.0. """

COLOR_GREEN = Color(ui_constants.COLOR_GREEN)
""" A color object with RGB values of 0.0, 1.0, and 0.0 and an alpha value of 1.0. """

COLOR_LIGHT_GRAY = Color(ui_constants.COLOR_LIGHT_GRAY)
""" A color object with a grayscale value of 2/3 and an alpha value of 1.0. """

COLOR_MAGENTA = Color(ui_constants.COLOR_MAGENTA)
""" A color object with RGB values of 1.0, 0.0, and 1.0 and an alpha value of 1.0. """

COLOR_ORANGE = Color(ui_constants.COLOR_ORANGE)
""" A color object with RGB values of 1.0, 0.5, and 0.0 and an alpha value of 1.0. """

COLOR_PURPLE = Color(ui_constants.COLOR_PURPLE)
""" A color object with RGB values of 0.5, 0.0, and 0.5 and an alpha value of 1.0. """

COLOR_RED = Color(ui_constants.COLOR_RED)
""" A color object with RGB values of 1.0, 0.0, and 0.0 and an alpha value of 1.0. """

COLOR_WHITE = Color(ui_constants.COLOR_WHITE)
""" A color object with a grayscale value of 1.0 and an alpha value of 1.0. """

COLOR_YELLOW = Color(ui_constants.COLOR_YELLOW)
""" A color object with RGB values of 1.0, 1.0, and 0.0 and an alpha value of 1.0. """


# MARK: - Font


class Font:
    """
    A ``Font`` object represents a font (with name and size) to be used on labels, buttons, text views etc.
    """

    __ui_font__ = None

    def __init__(self, name: str, size: float):
        """
        Initializes a font with given name and size.

        :pram name: The fully specified name of the font. This name incorporates both the font family name and the specific style information for the font.
        :param size: The size (in points) to which the font is scaled. This value must be greater than 0.0.
        """

        check(name, "name", [str, None])
        check(size, "size", [float, int, None])

        if name is None and size is None:
            return

        self.__ui_font__ = __UIFont__.fontWithName(name, size=CGFloat(size))

    def __repr__(self):
        return str(self.__ui_font__.description)

    def with_size(self, size: float) -> Font:
        """
        Returns a font object that is the same as the receiver but which has the specified size instead.

        :param size: The desired size (in points) of the new font object. This value must be greater than 0.0.

        :rtype: pyto_ui.Font
        """

        check(size, "size", [float, int])

        font = self.__class__(None, None)
        font.__ui_font__ = self.__ui_font__.fontWithSize(CGFloat(size))
        return font

    @classmethod
    def font_names_for_family_name(cls, name: str) -> List[str]:
        """
        Returns an array of font names available in a particular font family.

        :param name: The name of the font family. Use the :func:`~pyto_ui.font_family_names` function to get an array of the available font family names on the system.

        :rtype: List[str]
        """

        check(name, "name", [str])

        names = __UIFont__.fontNamesForFamilyName(name)

        py_names = []

        for name in names:
            py_names.append(str(name))

        return py_names

    @classmethod
    def system_font_of_size(cls, size: float) -> Font:
        """
        Returns the font object used for standard interface items in the specified size.

        :param size: The size (in points) to which the font is scaled. This value must be greater than 0.0.

        :rtype: pyto_ui.Font
        """

        check(size, "size", [float, int])

        font = cls(None, None)
        font.__ui_font__ = __UIFont__.systemFontOfSize(CGFloat(size))
        return font

    @classmethod
    def italic_system_font_of_size(cls, size: float) -> Font:
        """
        Returns the font object used for standard interface items that are rendered in italic type in the specified size.

        :param size: The size (in points) for the font. This value must be greater than 0.0.

        :rtype: pyto_ui.Font
        """

        check(size, "size", [float, int])

        font = cls(None, None)
        font.__ui_font__ = __UIFont__.italicSystemFontOfSize(CGFloat(size))
        return font

    @classmethod
    def bold_system_font_of_size(cls, size: float) -> Font:
        """
        Returns the font object used for standard interface items that are rendered in boldface type in the specified size

        :param size: The size (in points) for the font. This value must be greater than 0.0.

        :rtype: pyto_ui.Font
        """

        check(size, "size", [float, int])

        font = cls(None, None)
        font.__ui_font__ = __UIFont__.boldSystemFontOfSize(CGFloat(size))
        return font

    @classmethod
    def font_with_style(cls, style: FONT_TEXT_STYLE) -> Font:
        """
        Returns an instance of the system font for the specified text style and scaled appropriately for the user's selected content size category.

        :param style: The text style for which to return a font. See `Font Text Style <constants.html#font-text-style>`_ constants for possible values.

        :rtype: pyto_ui.Font
        """

        check(style, "style", [str])

        font = cls(None, None)
        font.__ui_font__ = __UIFont__.preferredFontForTextStyle(style)
        return font


# MARK: - Gesture Recognizer


class GestureRecognizer:
    """
    A gesture-recognizer object—or, simply, a gesture recognizer—decouples the logic for recognizing a sequence of touches (or other input) and acting on that recognition. When one of these objects recognizes a common gesture or, in some cases, a change in the gesture, it sends an action message to each designated target object.

    This class represents the type of gesture passed to the ``type`` initializer parameter. See `Gesture Type <constants.html#gesture-type>`_ constants for possible values.
    When the gesture is starting, cancelling or changig, ``action`` is called with the gesture recognizer as parameter. You can then access the location and the state from it.

    Example:

    .. highlight:: python
    .. code-block:: python

        '''
        Move a circle with finger.
        '''

        import pyto_ui as ui

        view = ui.View()
        view.background_color = ui.COLOR_SYSTEM_BACKGROUND

        circle = ui.View()
        circle.size = (50, 50)
        circle.center = (view.width/2, view.height/2)
        circle.flexible_margins = True
        circle.corner_radius = 25
        circle.background_color = ui.COLOR_LABEL
        view.add_subview(circle)

        def move(sender: ui.GestureRecognizer):
            if sender.state == ui.GESTURE_STATE_CHANGED:
                circle.center = sender.location

        gesture = ui.GestureRecognizer(ui.GESTURE_TYPE_PAN)
        gesture.action = move
        view.add_gesture_recognizer(gesture)

        ui.show_view(view)

    """

    __py_gesture__ = None

    def __init__(
        self, type: GESTURE_TYPE, action: Callable[[GestureRecognizer], None] = None
    ):

        if type.objc_class == __PyGestureRecognizer__:
            self.__py_gesture__ = type
        else:
            self.__py_gesture__ = __PyGestureRecognizer__.newRecognizerWithType(type)

        self.__py_gesture__.managedValue = _values.value(self)
        if action is not None:
            self.action = action

    def __repr__(self):
        return str(self.__py_gesture__.managed.description)

    __x__ = []
    __y__ = []

    @property
    def x(self) -> float:
        """
        (Read Only) Returns the X position of the gesture in its container view.

        :rtype: float
        """

        try:
            return self.__x__[0]
        except IndexError:
            return None

    @property
    def y(self) -> float:
        """
        (Read Only) Returns the Y position of the gesture in its container view.
        """

        try:
            return self.__y__[0]
        except IndexError:
            return None

    @property
    def location(self) -> Tuple[float, float]:
        """
        (Read Only) Returns a tuple with the X and the Y position of the gesture in its container view.

        :rtype: Tuple[float, float]
        """

        tup = (self.x, self.y)
        if tup == (None, None):
            return None
        else:
            return tup

    @property
    def view(self) -> "View":
        """
        (Read Only) Returns the view associated with the gesture.

        :rtype: View
        """

        view = self.__py_gesture__.view
        if view is None:
            return None
        else:
            _view = View()
            _view.__py_view__ = view
            return _view

    @property
    def enabled(self) -> bool:
        """
        A boolean indicating whether the gesture recognizer is enabled.

        :rtype: bool
        """

        return self.__py_gesture__.enabled

    @enabled.setter
    def enabled(self, new_value: bool):
        self.__py_gesture__.enabled = new_value

    __number_of_touches__ = None

    @property
    def number_of_touches(self) -> int:
        """
        (Read Only) Returns the number of touches involved in the gesture represented by the receiver.

        :rtype: int
        """

        if self.__number_of_touches__ is not None:
            return self.__number_of_touches__
        else:
            return self.__py_gesture__.numberOfTouches

    __state__ = None

    @property
    def state(self) -> GESTURE_STATE:
        """
        (Read Only) The current state of the gesture recognizer.

        :rtype: `Gesture State <constants.html#gesture-state>`_
        """

        if self.__state__ is not None:
            return self.__state__
        else:
            return self.__py_gesture__.state

    @property
    def requires_exclusive_touch_type(self) -> bool:
        """
        A Boolean indicating whether the gesture recognizer considers touches of different types simultaneously.

        :rtype: bool
        """
        return self.__py_gesture__.requiresExclusiveTouchType

    @requires_exclusive_touch_type.setter
    def requires_exclusive_touch_type(self, new_value: bool):
        self.__py_gesture__.requiresExclusiveTouchType = new_value

    @property
    def delays_touches_ended(self) -> bool:
        """
        A Boolean value determining whether the receiver delays sending touches in a end phase to its view.

        :rtype: bool
        """
        return self.__py_gesture__.delaysTouchesEnded

    @delays_touches_ended.setter
    def delays_touches_ended(self, new_value: bool):
        self.__py_gesture__.delaysTouchesEnded = new_value

    @property
    def delays_touches_began(self) -> bool:
        """
        A Boolean value determining whether the receiver delays sending touches in a begin phase to its view.

        :rtype: bool
        """
        return self.__py_gesture__.delaysTouchesBegan

    @delays_touches_began.setter
    def delays_touches_began(self, new_value: bool):
        self.__py_gesture__.delaysTouchesBegan = new_value

    @property
    def cancels_touches_in_view(self) -> bool:
        """
        A Boolean value affecting whether touches are delivered to a view when a gesture is recognized.

        :rtype: bool
        """
        return self.__py_gesture__.cancelsTouchesInView

    @cancels_touches_in_view.setter
    def cancels_touches_in_view(self, new_value: bool):
        self.__py_gesture__.cancelsTouchesInView = new_value

    @property
    def allowed_touch_types(self) -> List[TOUCH_TYPE]:
        """
        An array of touch types used to distinguish type of touches. For possible values, see ``Touch Type`` constants.

        :rtype: List[`Touch Type <constants.html#touch-type>`_]
        """
        return self.__py_gesture__.allowedTouchTypes

    @allowed_touch_types.setter
    def allowedTouchTypes(self, new_value: List[TOUCH_TYPE]):
        self.__py_gesture__.allowedTouchTypes = new_value

    @property
    def action(self) -> Callable[[GestureRecognizer], None]:
        """
        A function called to handle the gesture. Takes the sender gesture recognizer as parameter.

        :rtype: Callable[[GestureRecognizer], None]
        """

        action = self.__py_gesture__.action
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @action.setter
    def action(self, new_value: Callable[[GestureRecognizer], None]):
        if new_value is None:
            self.__py_gesture__.action = None
        else:
            self.__py_gesture__.action = _values.value(new_value)

    @property
    def minimum_press_duration(self) -> float:
        """
        The minimum time that the user must press on the view for the gesture to be recognized.

        (Only works for long press gestures)

        :rtype: float
        """

        return self.__py_gesture__.minimumDuration

    @minimum_press_duration.setter
    def minimum_press_duration(self, new_value) -> float:
        self.__py_gesture__.minimumDuration = new_value


# MARK: - Table View Section


class TableViewSection:
    """
    An object representing a section in a Table View.
    A section has a title and a list of cells contained in.
    """

    __py_section__ = None

    def __init__(self, title: str, cells: List["TableViewCell"]):
        self.__py_section__ = __PyTableViewSection__.new()
        self.__py_section__.managedValue = _values.value(self)
        self.title = title
        self.cells = cells

    @property
    def table_view(self) -> "TableView":
        """
        (Read Only) Returns the Table view associated with the section.

        :rtype: TableView
        """

        table_view = self.__py_section__.tableView
        if table_view is None:
            return None
        else:
            py_table_view = TableView()
            py_table_view.__py_view__ = table_view
            return py_table_view

    @property
    def title(self) -> str:
        """
        The title of the section displayed on screen.

        :rtype: str
        """

        return str(self.__py_section__.title)

    @title.setter
    def title(self, new_value: str):
        self.__py_section__.title = new_value

    @property
    def cells(self) -> "TableViewCell":
        """
        Cells contained in the section. After setting a value, the section will be reloaded automatically.

        :rtype: TableViewCell
        """

        cells = self.__py_section__.cells
        py_cells = []
        for cell in cells:
            py_cell = TableViewCell()
            py_cell.__py_view__ = cell
            py_cells.append(py_cell)
        return py_cells

    @cells.setter
    def cells(self, new_value: "TableViewCell"):
        cells = []
        for cell in new_value:
            cells.append(cell.__py_view__)
        self.__py_section__.cells = cells

    @property
    def did_select_cell(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when a cell contained in the section is selected. Takes the sender section and the selected cell's index as parameters.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_section__.didSelectCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_select_cell.setter
    def did_select_cell(self, new_value: Callable[[TableViewSection, int], None]):
        if new_value is None:
            self.__py_section__.didSelectCell = None
        else:
            self.__py_section__.didSelectCell = _values.value(new_value)

    @property
    def did_tap_cell_accessory_button(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when the accessory button of a cell contained in the section is pressed. Takes the sender section and the cell's index as parameters.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_section__.accessoryButtonTapped
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_tap_cell_accessory_button.setter
    def did_tap_cell_accessory_button(
        self, new_value: Callable[[TableViewSection, int], None]
    ):
        if new_value is None:
            self.__py_section__.accessoryButtonTapped = None
        else:
            self.__py_section__.accessoryButtonTapped = _values.value(new_value)

    @property
    def did_delete_cell(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when a cell contained in the section is deleted. Takes the sender section and the selected deleted cell's index as parameters.
        This function should be used to remove the data corresponding to the cell from the database.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_section__.didDeleteCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_delete_cell.setter
    def did_delete_cell(self, new_value: Callable[[TableViewSection, int], None]):
        if new_value is None:
            self.__py_section__.didDeleteCell = None
        else:
            self.__py_section__.didDeleteCell = _values.value(new_value)

    @property
    def did_move_cell(self) -> Callable[[TableViewSection, int, int], None]:
        """
        A function called when a cell contained in the section is moved. Takes the sender section, the moved deleted cell's index and the destination index as parameters.
        This function should be used to move the data corresponding to the cell from the database.

        :rtype: Callable[[TableViewSection, int, int], None]
        """

        action = self.__py_section__.didMoveCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_move_cell.setter
    def did_move_cell(self, new_value: Callable[[TableViewSection, int, int], None]):
        if new_value is None:
            self.__py_section__.didMoveCell = None
        else:
            self.__py_section__.didMoveCell = _values.value(new_value)


# MARK: - Button Item


class ButtonItem:
    """
    A special kind of button that can be placed on the view's navigation bar. Can have a title, and image or a system type.
    """

    __py_item__ = None

    def __init__(
        self,
        title: str = None,
        image: "Image" = None,
        system_item: SYSTEM_ITEM = None,
        style: BUTTON_ITEM_STYLE = __v__("BUTTON_ITEM_STYLE_PLAIN"),
    ):

        if style == "BUTTON_ITEM_STYLE_PLAIN":
            style = BUTTON_ITEM_STYLE_PLAIN

        if system_item is not None:
            self.__py_item__ = __PyButtonItem__.alloc().initWithSystemItem(system_item)
        else:
            self.__py_item__ = __PyButtonItem__.alloc().initWithStyle(style)

        self.__py_item__.managedValue = _values.value(self)
        self.title = title
        self.image = image

    def __repr__(self):
        return str(self.__py_item__.managed.description)

    @property
    def title(self) -> str:
        """
        The title of the button displayed on screen.

        :rtype: str
        """

        title = self.__py_item__.title
        if title is not None:
            return str(title)
        else:
            return None

    @title.setter
    def title(self, new_value: str):
        self.__py_item__.title = new_value

    @property
    def image(self) -> "Image.Image":
        """
        A ``PIL`` image object displayed on screen. May also be an ``UIKit`` ``UIImage`` symbol. See :func:`~pyto_ui.image_with_system_name`.

        :rtype: PIL.Image.Image
        """

        ui_image = self.__py_item__.image
        if ui_image is None:
            return None
        elif ui_image.symbolImage:
            return ui_image
        else:
            return __pil_image_from_ui_image__(ui_image)

    @image.setter
    def image(self, new_value: "Image"):
        if new_value is None:
            self.__py_item__.image = None
        elif "objc_class" in dir(new_value) and new_value.objc_class == UIImage:
            self.__py_item__.image = new_value
        else:
            self.__py_item__.image = __ui_image_from_pil_image__(new_value)

    @property
    def enabled(self) -> bool:
        """
        A boolean indicating whether the button is enabled.

        :rtype: bool
        """
        return self.__py_item__.enabled

    @enabled.setter
    def enabled(self, new_value: bool):
        self.__py_item__.enabled = new_value

    @property
    def style(self) -> BUTTON_ITEM_STYLE:
        """
        The button item style. See `Button Item Style <constants.html#button-item-style>`_ constants for possible values.

        :rtype: `Button Item Style <constants.html#button-item-style>`_
        """
        return self.__py_item__.style

    @style.setter
    def style(self, new_value: BUTTON_ITEM_STYLE):
        self.__py_item__.style = new_value

    @property
    def action(self) -> Callable[[ButtonItem], None]:
        """
        A function called when the button item is pressed. Takes the button item as parameter.

        :rtype: Callable[[ButtonItem], None]
        """

        action = self.__py_item__.action
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @action.setter
    def action(self, new_value: Callable[[ButtonItem], None]):
        if new_value is None:
            self.__py_item__.action = None
        else:
            self.__py_item__.action = _values.value(new_value)


if "widget" not in os.environ:

    # MARK: - Alert

    class Alert:
        """
        A class representing an alert.

        Example:

        .. highlight:: python
        .. code-block:: python

            from pyto_ui import Alert

            alert = Alert("Hello", "Hello World!")
            alert.add_action("Ok")
            alert.add_cancel_action("Cancel")
            if (alert.show() == "Ok"):
                print("Good Bye!")
        """

        __pyAlert__ = None

        def __init__(self, title: str, message: str):
            """
            Creates an alert.

            :param title: The title of the alert.
            :param message: The message of the alert.
            """

            self.__pyAlert__ = __PyAlert__.alloc().init()
            self.__pyAlert__.title = title
            self.__pyAlert__.message = message

        __actions__ = []

        def add_action(self, title: str):
            """
            Adds an action with given title.

            :param title: The title of the action.
            """

            self.__pyAlert__.addAction(title)

        def add_destructive_action(self, title: str):
            """
            Adds a destructive action with given title.

            :param title: The title of the action.
            """

            self.__pyAlert__.addDestructiveAction(title)

        def add_cancel_action(self, title: str):
            """
            Adds a cancel action with given title. Can only be added once.

            :param title: The title of the action.
            """

            if not self.__pyAlert__.addCancelAction(title):
                raise ValueError("There is already a cancel action.")

        def show(self) -> str:
            """
            Shows alert.

            Returns the title of the selected action.

            :rtype: str
            """

            script_path = None
            try:
                script_path = threading.current_thread().script_path
            except AttributeError:
                pass

            return self.__pyAlert__._show(script_path)


######################
# MARK: - View Classes
######################


class View:
    """
    An object that manages the content for a rectangular area on the screen.
    """

    __py_view__ = None

    def __init__(self):
        self.__py_view__ = __PyView__.newView()

    def __repr__(self):
        return str(self.__py_view__.managed.description)

    def __getitem__(self, item):
        return self.subview_with_name(item)

    def __del__(self):
        if self.__py_view__.references == 1:
            _gc.collected.append(self.__py_view__)
        else:
            self.__py_view__.releaseReference()
            self.__py_view__.release()

    def __setattr__(self, name, value):
        if name == "__py_view__":
            previous = self.__py_view__
            if previous is not None and previous.references != 1:
                previous.releaseReference()
                previous.release()
            elif previous is not None:
                _gc.collected.append(previous)

            if value is not None:
                value.retainReference()
                value.retain()

        super().__setattr__(name, value)

    @property
    def title(self) -> str:
        """
        If this view is directly presented, the top bar will show this view's title.

        :rtype: str
        """

        title = self.__py_view__.title
        if title is None:
            return title
        else:
            return str(title)

    @title.setter
    def title(self, new_value: str):
        self.__py_view__.title = new_value

    @property
    def name(self) -> str:
        """
        The name identifying the view. To access a subview with its name, you can use the :func:`~pyto_ui.View.subview_with_name` function. :class:`~pyto_ui.View` is also subscriptable, so you can do something like that:

        .. highlight:: python
        .. code-block:: python

            import pyto_ui as ui

            button = ui.Button()
            button.name = "Button"

            view = ui.View()
            view.add_subview(button)
            view["Button"] # -> Button object

        :rtype: str
        """

        name = self.__py_view__.name
        if name is None:
            return name
        else:
            return str(name)

    @name.setter
    def name(self, new_value: str):
        self.__py_view__.name = new_value

    def close(self):
        """
        Closes the view, if the receiver object is the root view presented to the user.
        """

        self.__py_view__.close()

    def push(self, view: View):
        """
        Presents the given additional view on top of the receiver.

        :param view: The view to present.
        """

        self.__py_view__.pushView(view.__py_view__)

    def pop(self):
        """
        Pops the visible view controller from the navigation controller.
        """

        self.__py_view__.pop()

    @property
    def navigation_bar_hidden(self) -> bool:
        """
        A boolean indicating whether the Navigation Bar of the View should be hidden.

        :rtype: bool
        """

        return self.__py_view__.navigationBarHidden

    @navigation_bar_hidden.setter
    def navigation_bar_hidden(self, new_value: bool):
        self.__py_view__.navigationBarHidden = new_value

    @property
    def x(self) -> float:
        """
        The x-coordinate of the view.

        :rtype: float
        """

        return self.__py_view__.x

    @x.setter
    def x(self, new_value: float):
        self.__py_view__.x = new_value

    @property
    def y(self) -> float:
        """
        The y-coordinate of the point.

        :rtype: float
        """
        return self.__py_view__.y

    @y.setter
    def y(self, new_value: float):
        self.__py_view__.y = new_value

    @property
    def width(self) -> float:
        """
        The width of the view.

        :rtype: float
        """

        return self.__py_view__.width

    @width.setter
    def width(self, new_value: float):
        self.__py_view__.width = new_value

    @property
    def height(self) -> float:
        """
        The height of the view.

        :rtype: float
        """

        return self.__py_view__.height

    @height.setter
    def height(self, new_value: float):
        self.__py_view__.height = new_value

    @property
    def center_x(self) -> float:
        """
        The center x-coordinate of the view's frame rectangle. Setting this value updates ``frame`` property appropiately.

        :rtype: float
        """

        return self.__py_view__.centerX

    @center_x.setter
    def center_x(self, new_value: float):
        self.__py_view__.centerX = new_value

    @property
    def center_y(self) -> float:
        """
        The center y-coordinate of the view's frame rectangle. Setting this value updates ``frame`` property appropiately.

        :rtype: float
        """

        return self.__py_view__.centerY

    @center_y.setter
    def center_y(self, new_value: float):
        self.__py_view__.centerY = new_value

    @property
    def center(self) -> Tuple[float, float]:
        """
        The center point of the view's frame rectangle. Setting this value updates ``frame`` property appropiately.
        This value is a tuple with X and Y coordinates.

        :rtype: Tuple[float, float]
        """

        return (self.center_x, self.center_y)

    @center.setter
    def center(self, new_value: Tuple[float, float]):
        self.center_x, self.center_y = new_value

    @property
    def size(self) -> Tuple[float, float]:
        """
        A size that specifies the height and width of the rectangle.
        This value is a tuple with height and width values.

        :rtype: Tuple[float, float]
        """

        return (self.width, self.height)

    @size.setter
    def size(self, new_value: Tuple[float, float]):
        self.width, self.height = new_value

    @property
    def origin(self) -> Tuple[float, float]:
        """
        A point that specifies the coordinates of the view's rectangle’s origin.
        This value is a tuple with X and Y coordinates.

        :rtype: Tuple[float, float]
        """

        return (self.x, self.y)

    @origin.setter
    def origin(self, new_value: Tuple[float, float]):
        self.x, self.y = new_value

    @property
    def frame(self) -> Tuple[float, float, float, float]:
        """
        The frame rectangle, which describes the view’s location and size in its superview’s coordinate system.
        This value is a tuple with X, Y, Width and Height values.

        :rtype: Tuple[float, float, float, float]
        """

        return (self.x, self.y, self.width, self.height)

    @frame.setter
    def frame(self, new_value: Tuple[float, float, float, float]):
        self.x, self.y, self.width, self.height = new_value

    @property
    def __flexible_width__(self) -> bool:
        return self.__py_view__.flexibleWidth

    @__flexible_width__.setter
    def __flexible_width__(self, new_value: bool):
        self.__py_view__.flexibleWidth = new_value

    @property
    def __flexible_height__(self) -> bool:
        return self.__py_view__.flexibleHeight

    @__flexible_height__.setter
    def __flexible_height__(self, new_value: bool):
        self.__py_view__.flexibleHeight = new_value

    @property
    def __flexible_left_margin__(self) -> bool:
        return self.__py_view__.flexibleLeftMargin

    @__flexible_left_margin__.setter
    def __flexible_left_margin__(self, new_value: bool):
        self.__py_view__.flexibleLeftMargin = new_value

    @property
    def __flexible_right_margin__(self) -> bool:
        return self.__py_view__.flexibleRightMargin

    @__flexible_right_margin__.setter
    def __flexible_right_margin__(self, new_value: bool):
        self.__py_view__.flexibleRightMargin = new_value

    @property
    def __flexible_top_margin__(self) -> bool:
        return self.__py_view__.flexibleTopMargin

    @__flexible_top_margin__.setter
    def __flexible_top_margin__(self, new_value: bool):
        self.__py_view__.flexibleTopMargin = new_value

    @property
    def __flexible_bottom_margin__(self) -> bool:
        return self.__py_view__.flexibleBottomMargin

    @__flexible_bottom_margin__.setter
    def __flexible_bottom_margin__(self, new_value: bool):
        self.__py_view__.flexibleBottomMargin = new_value

    @property
    def flex(self) -> List[AUTO_RESIZING]:
        """
        A list that determines how the receiver resizes itself when its superview’s bounds change. See `Auto Resizing <constants.html#auto-resizing>`_ constants for possible values.

        :rtype: List[`Auto Resizing <constants.html#auto-resizing>`_]
        """

        a = []

        if self.__flexible_width__:
            a.append(FLEXIBLE_WIDTH)

        if self.__flexible_height__:
            a.append(FLEXIBLE_HEIGHT)

        if self.__flexible_bottom_margin__:
            a.append(FLEXIBLE_BOTTOM_MARGIN)

        if self.__flexible_top_margin__:
            a.append(FLEXIBLE_TOP_MARGIN)

        if self.__flexible_left_margin__:
            a.append(FLEXIBLE_LEFT_MARGIN)

        if self.__flexible_right_margin__:
            a.append(FLEXIBLE_RIGHT_MARGIN)

        return a

    @flex.setter
    def flex(self, new_value: List[AUTO_RESIZING]):
        (
            self.__flexible_width__,
            self.__flexible_height__,
            self.__flexible_top_margin__,
            self.__flexible_bottom_margin__,
            self.__flexible_left_margin__,
            self.__flexible_right_margin__,
        ) = (
            (FLEXIBLE_WIDTH in new_value),
            (FLEXIBLE_HEIGHT in new_value),
            (FLEXIBLE_TOP_MARGIN in new_value),
            (FLEXIBLE_BOTTOM_MARGIN in new_value),
            (FLEXIBLE_LEFT_MARGIN in new_value),
            (FLEXIBLE_RIGHT_MARGIN in new_value),
        )

    def subview_with_name(self, name) -> View:
        """
        Returns the subview with the given name.

        Raises ``NameError`` if no view is found.

        :rtype: View
        """

        for view in self.subviews:
            if view.name == name:
                return view

        raise NameError(f"No subview named '{name}'")

    @property
    def subviews(self) -> List[View]:
        """
        (Read Only) A list of the view's children.

        See also :func:`~pyto_ui.View.add_subview`.

        :rtype: List[View]
        """

        views = self.__py_view__.subviews
        if views is None or len(views) == 0:
            return []
        else:
            _views = []
            for view in views:
                ui = sys.modules["pyto_ui"]
                _class = getattr(ui, str(view.objc_class.pythonName))
                _view = _class()
                _view.__py_view__ = view
                _views.append(_view)
            return _views

    @property
    def superview(self) -> View:
        """
        (Read Only) The parent view containg the receiver view.

        :rtype: View
        """

        superview = self.__py_view__.superView
        if superview is None:
            return None
        else:
            ui = sys.modules["pyto_ui"]
            _class = getattr(ui, str(superview.objc_class.pythonName))
            view = _class()
            view.__py_view__ = superview
            return view

    @property
    def background_color(self) -> Color:
        """
        The background color of the view.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.backgroundColor
        if c is None:
            return None
        else:
            return Color(c)

    @background_color.setter
    def background_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.backgroundColor = None
        else:
            self.__py_view__.backgroundColor = new_value.__py_color__

    @property
    def hidden(self) -> bool:
        """
        A boolean indicating whether the view is visible or not.

        :rtype: bool
        """

        return self.__py_view__.hidden

    @hidden.setter
    def hidden(self, new_value: bool):
        self.__py_view__.hidden = new_value

    @property
    def alpha(self) -> float:
        """
        The opacity of the view.

        :rtype: float
        """

        return self.__py_view__.alpha

    @alpha.setter
    def alpha(self, new_value: float):
        self.__py_view__.alpha = new_value

    @property
    def opaque(self) -> bool:
        """
        A boolean indicating whether the view is opaque or not. Setting to ``True`` should prevent the view from having a transparent background.

        :rtype: bool
        """

        return self.__py_view__.opaque

    @opaque.setter
    def opaque(self, new_value: bool):
        self.__py_view__.opaque = new_value

    @property
    def tint_color(self) -> Color:
        """
        The tint color of the view. If set to ``None``, the tint color will be inherited from the superview. The tint color affects some views like ``Button`` for title color, ``TextView`` for cursor color, etc.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.tintColor
        if c is None:
            return None
        else:
            return Color(c)

    @tint_color.setter
    def tint_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.tintColor = None
        else:
            self.__py_view__.tintColor = new_value.__py_color__

    @property
    def user_interaction_enabled(self) -> bool:
        """
        A boolean indicating whether the view responds to touches.

        :rtype: bool
        """

        return self.__py_view__.userInteractionEnabled

    @user_interaction_enabled.setter
    def user_interaction_enabled(self, new_value: bool):
        self.__py_view__.userInteractionEnabled = new_value

    @property
    def clips_to_bounds(self) -> bool:
        """
        A boolean value that determines whether subviews are confined to the bounds of the view.

        :rtype: bool
        """

        return self.__py_view__.clipsToBounds

    @clips_to_bounds.setter
    def clips_to_bounds(self, new_value: bool):
        self.__py_view__.clipsToBounds = new_value

    @property
    def corner_radius(self) -> float:
        """
        The radius to use when drawing rounded corners for the view’s background.

        :rtype: float
        """

        return self.__py_view__.cornerRadius

    @corner_radius.setter
    def corner_radius(self, new_value: float):
        self.__py_view__.cornerRadius = new_value

    @property
    def border_width(self) -> float:
        """
        The width of the view's border.

        :rtype: float
        """

        return self.__py_view__.borderWidth

    @border_width.setter
    def border_width(self, new_value: float):
        self.__py_view__.borderWidth = new_value

    @property
    def border_color(self) -> Color:
        """
        The color of the view's border

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.borderColor
        if c is None:
            return None
        else:
            return Color(c)

    @border_color.setter
    def border_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.borderColor = None
        else:
            self.__py_view__.borderColor = new_value.__py_color__

    @property
    def content_mode(self) -> CONTENT_MODE:
        """
        A flag used to determine how a view lays out its content when its bounds change.
        See `Content Mode` <constants.html#content-mode>`_ constants for possible values.

        :rtype: `Content Mode` <constants.html#content-mode>`_
        """

        return self.__py_view__.contentMode

    @content_mode.setter
    def content_mode(self, new_value: CONTENT_MODE):
        self.__py_view__.contentMode = new_value

    @property
    def appearance(self) -> APPEARANCE:
        """
        The appearance of the view.
        See `Appearance <constants.html#appearance>`_ constants for possible values.

        :rtype: `Appearance <constants.html#appearance>`_
        """

        return self.__py_view__.appearance

    @appearance.setter
    def appearance(self, new_value: APPEARANCE):
        self.__py_view__.appearance = new_value

    @property
    def first_responder(self) -> bool:
        """
        (Read Only) A boolean indicating the view is first responder.
        ``UIKit`` dispatches some types of events, such as motion events, to the first responder initially.

        :rtype: bool
        """

        return self.__py_view__.firstResponder

    def add_subview(self, view: View):
        """
        Adds the given view to the receiver's hierarchy.

        :param view: The view to add.
        """

        self.__py_view__.addSubview(view.__py_view__)

    def insert_subview(self, view: View, index: int):
        """
        Inserts the given view to the receiver's hierarchy at the given index.

        :param view: The view to insert.
        :param index: The index where the view should be inserted.
        """

        self.__py_view__.insertSubview(view.__py_view__, at=index)

    def insert_subview_bellow(self, view: View, bellow_view: View):
        """
        Inserts the given view to the receiver's hierarchy bellow another given view.

        :param view: The view to insert.
        :param bellow_view: The view above the inserted view.
        """

        self.__py_view__.insertSubview(view.__py_view__, bellow=bellow_view.__py_view__)

    def insert_subview_above(self, view: View, above_view: View):
        """
        Inserts the given view to the receiver's hierarchy above another given view.

        :param view: The view to insert.
        :param above_view: The view bellow the inserted view.
        """

        self.__py_view__.insertSubview(view.__py_view__, above=above_view.__py_view__)

    def remove_from_superview(self):
        """
        Removes the view from the parent's hierarchy.
        """

        self.__py_view__.removeFromSuperview()

    def add_gesture_recognizer(self, gesture_recognizer: GestureRecognizer):
        """
        Adds a gesture recognizer.

        :param gesture_recognizer: The gesture recognizer to be added.
        """

        self.__py_view__.addGestureRecognizer(gesture_recognizer.__py_gesture__)

    def remove_gesture_recognizer(self, gesture_recognizer: GestureRecognizer):
        """
        Removes a gesture recognizer.

        :param gesture_recognizer: The gesture recognizer to be removed.
        """

        self.__py_view__.removeGestureRecognizer(gesture_recognizer.__py_gesture__)

    @property
    def gesture_recognizers(self) -> List[GestureRecognizer]:
        """
        (Read Only) Returns all gesture recognizers.

        See :meth:`~pyto_ui.View.add_gesture_recognizer`.

        :rtype: List[GestureRecognizer]
        """

        recognizers = self.__py_view__.gestureRecognizers
        if recognizers is None or len(recognizers) == 0:
            return []
        else:
            _recognizers = []
            for recognizer in recognizers:
                _recognizer = GestureRecognizer(GESTURE_TYPE_TAP)
                _recognizer.__py_gesture__ = recognizer
                _recognizers.append(_recognizer)
            return _recognizers

    def size_to_fit(self):
        """
        Sizes the view to fit its content.
        """

        self.__py_view__.sizeToFit()

    def become_first_responder(self) -> bool:
        """
        Becomes the first responder. On :class:`~pyto_ui.TextView` and :class:`~pyto_ui.TextField` objects, the keyboard will be shown.
        Returns a boolean indicating the success.

        :rtype: bool
        """

        return self.__py_view__.becomeFirstResponder()

    def resign_first_responder(self) -> bool:
        """
        Stops being the first responder. On :class:`~pyto_ui.TextView` and :class:`~pyto_ui.TextField` objects, the keyboard will be hidden.
        Returns a boolean indicating the success.

        :rtype: bool
        """

        return self.__py_view__.resignFirstResponder()

    @property
    def layout(self) -> Callable[[View], None]:
        """
        A function called when the view is resized. Takes the view as parameter.

        :rtype: Callable[[View], None]
        """

        action = self.__py_view__.layoutAction
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @layout.setter
    def layout(self, new_value: Callable[[View], None]):
        self.__py_view__.pyValue = _values.value(self)
        if new_value is None:
            self.__py_view__.layoutAction = None
        else:
            self.__py_view__.layoutAction = _values.value(new_value)

    @property
    def did_appear(self) -> Callable[[View], None]:
        """
        A function called when the view appears on screen. This function is called only if for the presented view and not its subviews.

        :rtype: Callable[[View], None]
        """

        action = self.__py_view__.appearAction
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_appear.setter
    def did_appear(self, new_value: Callable[[View], None]):
        self.__py_view__.pyValue = _values.value(self)
        if new_value is None:
            self.__py_view__.appearAction = None
        else:
            self.__py_view__.appearAction = _values.value(new_value)

    @property
    def did_disappear(self) -> Callable[[View], None]:
        """
        A function called when the view stops being visible on screen. This function is called only if for the presented view and not its subviews.

        :rtype: Callable[[View], None]
        """

        action = self.__py_view__.disappearAction
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_disappear.setter
    def did_disappear(self, new_value: Callable[[View], None]):
        self.__py_view__.pyValue = _values.value(self)
        if new_value is None:
            self.__py_view__.disappearAction = None
        else:
            self.__py_view__.disappearAction = _values.value(new_value)

    @property
    def button_items(self) -> List[ButtonItem]:
        """
        A list of :class:`~pyto_ui.ButtonItem` objects to be displayed on the top bar. Works only if the view is the root view presented with :func:`~pyto_ui.show_view` or :meth:`~pyto_ui.View.push`.

        :rtype: List[ButtonItem]
        """

        items = self.__py_view__.buttonItems
        if items is None or len(items) == 0:
            return []
        else:
            _items = []
            for item in items:
                _item = ButtonItem()
                _item.managed = item
                _items.append(_item)
            return _items

    @button_items.setter
    def button_items(self, new_value: List[ButtonItem]):
        items = []
        if new_value is not None and len(new_value) > 0:
            for item in new_value:
                items.append(item.__py_item__)
        self.__py_view__.buttonItems = items


class UIKitView(View):
    """
    This class is used to create a PytoUI view from an UIKit view. This class must be subclassed and implement :meth:`~pyto_ui.UIKitView.make_view`.
    """

    def __init__(self):

        if type(self) is UIKitView:
            msg = "'UIKitView' must be subclassed and implement 'make_view()'."
            raise NotImplementedError(msg)

        self._made_view = False
        self._make_view()
        while self.__py_view__ is None:
            continue

    def make_view(self) -> "UIView":
        """
        Implement this method to return an UIKit View. This method is automatically called on the main thread.

        :rtype: UIView
        """

        return None

    @mainthread
    def _make_view(self):
        view = self.make_view()
        py_view = __PyUIKitView__.alloc().initWithManaged(view)
        self.__py_view__ = py_view


class ImageView(View):
    """
    A view displaying an image. The displayed image can be a ``PIL`` image, an ``UIKit`` ``UIImage`` (see :func:`~pyto_ui.image_with_system_name`) or can be directly downloaded from an URL.
    """

    def __init__(self, image: "Image" = None, symbol_name: str = None, url: str = None):
        self.__py_view__ = __UIImageView__.newView()
        self.image = image
        if url is not None:
            self.load_from_url(url)
        elif symbol_name is not None:
            self.image = image_with_system_name(symbol_name)

    @property
    def image(self) -> "Image":
        """
        The image displayed on screen. Can be a ``PIL`` image or an ``UIKit`` ``UIImage``. See :func:`~pyto_ui.image_with_system_name` for more information about how to get a symbol image.

        :rtype: Image.Image
        """

        ui_image = self.__py_view__.image
        if ui_image is None:
            return None
        elif ui_image.symbolImage:
            return ui_image
        else:
            return __pil_image_from_ui_image__(ui_image)

    @image.setter
    def image(self, new_value: "Image"):

        if self.__py_view__.image is not None:
            self.__py_view__.image.release()

        if new_value is None:
            self.__py_view__.image = None
        elif "objc_class" in dir(new_value) and new_value.objc_class == UIImage:
            self.__py_view__.image = new_value
        else:
            self.__py_view__.image = __ui_image_from_pil_image__(new_value)

    def load_from_url(self, url):
        """
        Loads and display the image at given url.

        :param url: The URL of the image.
        """

        def _set_image(self, url):
            from PIL import Image

            self.image = Image.open(urlopen(url))

        Thread(target=_set_image, args=(self, url)).start()


class Label(View):
    """
    A view displaying not editable and not selectable text.
    """

    def __init__(self, text: str = ""):
        self.__py_view__ = __PyLabel__.newView()
        self.text = text

    def load_html(self, html):
        """
        Loads HTML in the Label.

        :param html: The HTML code to load.
        """

        self.__py_view__.loadHTML(html)

    @property
    def text(self) -> str:
        """
        The text to be displayed on the view.

        :rtype: str
        """

        return str(self.__py_view__.text)

    @text.setter
    def text(self, new_value: str):
        self.__py_view__.text = new_value

    @property
    def text_color(self) -> Color:
        """
        The color of the text.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.textColor
        if c is None:
            return None
        else:
            return Color(c)

    @text_color.setter
    def text_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.textColor = None
        else:
            self.__py_view__.textColor = new_value.__py_color__

    @property
    def font(self) -> Font:
        """
        The font of the text.

        :rtype: pyto_ui.Font
        """

        py_font = self.__py_view__.font
        if py_font is None:
            return None

        font = Font(None, None)
        font.__ui_font__ = py_font
        return font

    @font.setter
    def font(self, new_value: Font):
        if new_value is None:
            self.__py_view__.font = None
        else:
            self.__py_view__.font = new_value.__ui_font__

    @property
    def text_alignment(self) -> TEXT_ALIGNMENT:
        """
        The text's alignment. For possible values, see `Text Alignment <constants.html#text-alignment>`_ constants.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return self.__py_view__.textAlignment

    @text_alignment.setter
    def text_alignment(self, new_value: TEXT_ALIGNMENT):
        self.__py_view__.textAlignment = new_value

    @property
    def line_break_mode(self) -> LINE_BREAK_MODE:
        """
        The line break mode.

        :rtype: `Line Break Mode <constants.html#line-break-mode>`_
        """

        return self.__py_view__.lineBreakMode

    @line_break_mode.setter
    def line_break_mode(self, new_value: LINE_BREAK_MODE):
        self.__py_view__.lineBreakMode = new_value

    @property
    def adjusts_font_size_to_fit_width(self) -> bool:
        """
        A boolean indicating whether the label adjusts its font size to fit its size.

        :rtype: bool
        """

        return self.__py_view__.adjustsFontSizeToFitWidth

    @adjusts_font_size_to_fit_width.setter
    def adjusts_font_size_to_fit_width(self, new_value: bool):
        self.__py_view__.adjustsFontSizeToFitWidth = new_value

    @property
    def allows_default_tightening_for_truncation(self) -> bool:
        return self.__py_view__.allowsDefaultTighteningForTruncation

    @allows_default_tightening_for_truncation.setter
    def allows_default_tightening_for_truncation(self, new_value: bool):
        self.__py_view__.allowsDefaultTighteningForTruncation = new_value

    @property
    def number_of_lines(self) -> int:
        """
        The numbers of lines displayed in the label. Set to ``0`` to show all the text.

        :rtype: int
        """

        return self.__py_view__.numberOfLines

    @number_of_lines.setter
    def number_of_lines(self, new_value: int):
        self.__py_view__.numberOfLines = new_value


class TableViewCell(View):
    """
    A cell contained in a :class:`~pyto_ui.TableView`.
    Can have a title, a subtitle, an image and an accessory view.

    For a list of supported style, see `Table View Cell Style <constants.html#table-view-cell-style>`_ constants.
    """

    def __init__(
        self, style: TABLE_VIEW_STYLE = __v__("TABLE_VIEW_CELL_STYLE_DEFAULT")
    ):
        if style == "TABLE_VIEW_CELL_STYLE_DEFAULT":
            self.__py_view__ = __PyTableViewCell__.newViewWithStyle(
                TABLE_VIEW_CELL_STYLE_DEFAULT
            )
        else:
            self.__py_view__ = __PyTableViewCell__.newViewWithStyle(style)
        self.__py_view__.managedValue = _values.value(self)

    @property
    def movable(self) -> bool:
        """
        A boolean indicating whether the cell is movable. If set to ``True``, the container :class:`TableViewSection` object should handle the move.

        :rtype: bool
        """

        return self.__py_view__.movable

    @movable.setter
    def movable(self, new_value: bool):
        self.__py_view__.movable = new_value

    @property
    def removable(self) -> bool:
        """
        A boolean indicating the cell is removable. If set to ``True``, the container :class:`TableViewSection` object should handle the removal.

        :rtype: bool
        """

        return self.__py_view__.removable

    @removable.setter
    def removable(self, new_value: bool):
        self.__py_view__.removable = new_value

    @property
    def content_view(self) -> View:
        """
        (Read Only) The view contained in the cell. Custom views should be added inside it.

        :rtype: View
        """

        _view = View()
        _view.__py_view__ = self.__py_view__.contentView
        return _view

    @property
    def image_view(self) -> ImageView:
        """
        (Read Only) The view containing an image. May return ``None`` for some `Table View Cell Style <constants.html#table-view-cell-style>`_ values.

        :rtype: Image View
        """

        view = self.__py_view__.imageView
        if view is None:
            return None
        else:
            _view = ImageView()
            _view.__py_view__ = view
            return _view

    @property
    def text_label(self) -> Label:
        """
        (Read Only) The label containing the main text of the cell.

        :rtype: Label
        """

        view = self.__py_view__.textLabel
        if view is None:
            return None
        else:
            _view = Label()
            _view.__py_view__ = view
            return _view

    @property
    def detail_text_label(self) -> Label:
        """
        (Read Only) The label containing secondary text. May return ``None`` for some `Table View Cell Style <constants.html#table-view-cell-style>`_ values.

        :rtype: Label
        """

        view = self.__py_view__.detailLabel
        if view is None:
            return None
        else:
            _view = Label()
            _view.__py_view__ = view
            return _view

    @property
    def accessory_type(self) -> ACCESSORY_TYPE:
        """
        The type of accessory view placed to the right of the cell. See `Accessory Type <constants.html#accessory_type>`_ constants for possible values.

        :rtype: `Accessory Type <constants.html#accessory_type>`_.
        """

        return self.__py_view__.accessoryType

    @accessory_type.setter
    def accessory_type(self, new_value: ACCESSORY_TYPE):
        self.__py_view__.accessoryType = new_value


class TableView(View):
    """
    A view containing a list of cells.

    A Table View has a list of :class:`TableViewSection` objects that represent groups of cells. A Table View has two possible styles. See `Table View Style <constants.html#table-view-style>`_.
    """

    def __init__(
        self,
        style: TABLE_VIEW_STYLE = __v__("TABLE_VIEW_STYLE_PLAIN"),
        sections: List[TableViewSection] = [],
    ):
        if style == "TABLE_VIEW_STYLE_PLAIN":
            self.__py_view__ = __PyTableView__.newViewWithStyle(TABLE_VIEW_STYLE_PLAIN)
        else:
            self.__py_view__ = __PyTableView__.newViewWithStyle(style)
        self.__py_view__.managedValue = _values.value(self)
        self.sections = sections

    @property
    def reload_action(self) -> Callable[TableView, None]:
        """
        A function called when the button item is pressed. Takes the button item as parameter.

        :rtype: Callable[[TableView], None]
        """

        action = self.__py_view__.reloadAction
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @reload_action.setter
    def reload_action(self, new_value: Callable[[TableView], None]):
        if new_value is None:
            self.__py_view__.action = None
        else:
            self.__py_view__.reloadAction = _values.value(new_value)

    @property
    def edit_button_item(self) -> ButtonItem:
        """
        Returns a bar button item that toggles its title and associated state between Edit and Done.
        The button item is setup to edit the Table View.

        :rtype: ButtonItem
        """

        item = ButtonItem()
        item.__py_item__ = self.__py_view__.editButtonItem
        return item

    @property
    def sections(self) -> List[TableViewSection]:
        """
        A list of :class:`TableViewSection` containg cells to be displayed on the Table View.
        Setting a new value will reload automatically the contents of the Table View.

        :rtype: List[TableViewSection]
        """

        sections = self.__py_view__.sections
        py_sections = []
        for section in sections:
            py_section = TableViewSection("", [])
            py_section.__py_section__ = section
            py_sections.append(py_section)
        return py_sections

    @sections.setter
    def sections(self, new_value: List[TableViewSection]):
        sections = []
        for section in new_value:
            section.__py_section__.tableView = self.__py_view__
            sections.append(section.__py_section__)
        self.__py_view__.sections = sections

    def deselect_row(self):
        """
        Deselects the current selected row.
        """

        self.__py_view__.deselectRowAnimated(True)


class TextView(View):
    """
    An editable, multiline and scrollable view containing text.
    """

    def __init__(self, text=""):
        self.__py_view__ = __PyTextView__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.text = text

    @property
    def selected_range(self) -> Tuple[int, int]:
        """
        Returns the selected text range. A tuple of two integers (start, end).

        :rtype: Tuple[int, int]
        """

        return (int(self.__py_view__.range[0]), int(self.__py_view__.range[1]))

    @property
    def did_begin_editing(self) -> Callable[[TextView], None]:
        """
        A function called when the Text View begins editing. Takes the sender Text View as parameter.

        :rtype: Callable[[TextView], None]
        """

        action = self.__py_view__.didBeginEditing
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_begin_editing.setter
    def did_begin_editing(self, new_value: Callable[[TextView], None]):
        if new_value is None:
            self.__py_view__.didBeginEditing = None
        else:
            self.__py_view__.didBeginEditing = _values.value(new_value)

    @property
    def did_end_editing(self) -> Callable[[TextView], None]:
        """
        A function called when the Text View ends editing. Takes the sender Text View as parameter.

        :rtype: Callable[[TextView], None]
        """

        action = self.__py_view__.didEndEditing
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_end_editing.setter
    def did_end_editing(self, new_value: Callable[[TextView], None]):
        if new_value is None:
            self.__py_view__.didEndEditing = None
        else:
            self.__py_view__.didEndEditing = _values.value(new_value)

    @property
    def did_change(self) -> Callable[[TextView], None]:
        """
        A function called when the Text View's text changes. Takes the sender Text View as parameter.

        :rtype: Callable[[TextView], None]
        """

        action = self.__py_view__.didChangeText
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_change.setter
    def did_change(self, new_value: Callable[[TextView], None]):
        if new_value is None:
            self.__py_view__.didChangeText = None
        else:
            self.__py_view__.didChangeText = _values.value(new_value)

    def load_html(self, html):
        """
        Loads HTML in the Text View.

        :param html: The HTML code to load.
        """

        self.__py_view__.loadHTML(html)

    @property
    def text(self) -> str:
        """
        The text contained in the view.

        :rtype: str
        """

        return str(self.__py_view__.text)

    @text.setter
    def text(self, new_value: str):
        self.__py_view__.text = new_value

    @property
    def editable(self) -> bool:
        """
        A boolean indicating whether the text is editable.

        :rtype: bool
        """

        return self.__py_view__.editable

    @editable.setter
    def editable(self, new_value: bool):
        self.__py_view__.editable = new_value

    @property
    def selectable(self) -> bool:
        """
        A boolean indicating whether the text is selectable.

        :rtype: bool
        """

        return self.__py_view__.selectable

    @selectable.setter
    def selectable(self, new_value: bool):
        self.__py_view__.selectable = new_value

    @property
    def text_color(self) -> Color:
        """
        The color of the text displayed on screen.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.textColor
        if c is None:
            return None
        else:
            return Color(c)

    @text_color.setter
    def text_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.textColor = None
        else:
            self.__py_view__.textColor = new_value.__py_color__

    @property
    def font(self) -> Font:
        """
        The font of the text displayed on screen.

        :rtype: pyto_ui.Font
        """

        py_font = self.__py_view__.font
        if py_font is None:
            return None

        font = Font(None, None)
        font.__ui_font__ = py_font
        return font

    @font.setter
    def font(self, new_value: Font):
        if new_value is None:
            self.__py_view__.font = None
        else:
            self.__py_view__.font = new_value.__ui_font__

    @property
    def text_alignment(self) -> TEXT_ALIGNMENT:
        """
        The alignment of the text displayed on screen. See `Text Alignment <constants.html#text-alignment>`_ constants for possible values.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return self.__py_view__.textAlignment

    @text_alignment.setter
    def text_alignment(self, new_value: TEXT_ALIGNMENT):
        self.__py_view__.textAlignment = new_value

    @property
    def smart_dashes(self) -> bool:
        """
        A boolean indicating whether smart dashes are enabled.

        :rtype: bool
        """

        return self.__py_view__.smartDashes

    @smart_dashes.setter
    def smart_dashes(self, new_value: bool):
        self.__py_view__.smartDashes = new_value

    @property
    def smart_quotes(self) -> bool:
        """
        A boolean indicating whether smart quotes are enabled.

        :rtype: bool
        """

        return self.__py_view__.smartQuotes

    @smart_quotes.setter
    def smart_quotes(self, new_value: bool):
        self.__py_view__.smartQuotes = new_value

    @property
    def keyboard_type(self) -> KEYBOARD_TYPE:
        """
        The type of keyboard to use while editing the text. See `Keyboard Type <constants.html#keyboard-type>`_ constants for possible values.

        :rtype: `Keyboard Type <constants.html#keyboard-type>`_
        """

        return self.__py_view__.keyboardType

    @keyboard_type.setter
    def keyboard_type(self, new_value: KEYBOARD_TYPE):
        self.__py_view__.keyboardType = new_value

    @property
    def autocapitalization_type(self) -> AUTO_CAPITALIZE:
        """
        The type of autocapitalization to use while editing th text. See `Auto Capitalization <constants.html#auto-capitalization>`_ constants for possible values.

        :rtype: `Auto Capitalization <constants.html#auto-capitalization>`_
        """

        return self.__py_view__.autocapitalizationType

    @autocapitalization_type.setter
    def autocapitalization_type(self, new_value: AUTO_CAPITALIZE):
        self.__py_view__.autocapitalizationType = new_value

    @property
    def autocorrection(self) -> bool:
        """
        A boolean indicating whether autocorrection is enabled.

        :rtype: bool
        """

        return self.__py_view__.autocorrection

    @autocorrection.setter
    def autocorrection(self, new_value: bool):
        self.__py_view__.autocorrection = new_value

    @property
    def keyboard_appearance(self) -> KEYBOARD_APPEARANCE:
        """
        The appearance of the keyboard used while editing the text. See `Keyboard Appearance <constants.html#keyboard-appearance>`_ constants for possible values.

        :rtype: `Keyboard Appearance <constants.html#keyboard-appearance>`_
        """

        return self.__py_view__.keyboardAppearance

    @keyboard_appearance.setter
    def keyboard_appearance(self, new_value: KEYBOARD_APPEARANCE):
        self.__py_view__.keyboardAppearance = new_value

    @property
    def return_key_type(self) -> RETURN_KEY_TYPE:
        """
        The type of return key to show on the keyboard used to edit the text. See `Return Key Type <constants.html#return-key-type>`_ constants for possible values.

        :rtype: `Return Key Type <constants.html#return-key-type>`_
        """

        return self.__py_view__.returnKeyType

    @return_key_type.setter
    def return_key_type(self, new_value: RETURN_KEY_TYPE):
        self.__py_view__.returnKeyType = new_value

    @property
    def secure(self) -> bool:
        """
        A boolean indicating whether the keyboard should be configured to enter sensitive data.

        :rtype: bool
        """

        return self.__py_view__.isSecureTextEntry

    @secure.setter
    def secure(self, new_value: bool):
        self.__py_view__.isSecureTextEntry = new_value


if "widget" not in os.environ:

    class WebView(View):
        """
        A View that displays web content.
        """

        class JavaScriptException(Exception):
            """
            An excpetion while running JavaScript code. Raised by :meth:`~pyto_ui.WebView.evaluate_js`.
            """

            pass

        def __init__(self, url: str = None):
            self.__py_view__ = __PyWebView__.newView()
            self.__py_view__.managedValue = _values.value(self)
            if url is not None:
                self.load_url(url)

        def evaluate_js(self, code) -> str:
            """
            Runs JavaScript code and returns a String representation of the evaluation result. Raises a :class:`~pyto_ui.WebView.JavaScriptException`.

            :param code: JavaScript code to run.
            :rtype: str
            """

            code = NSString.alloc().initWithUTF8String(code.encode("utf-8"))

            result = self.__py_view__.evaluateJavaScript(code)
            code.release()
            if result is None:
                return None
            else:
                _result = str(result)
                result = _result
                if result.startswith("_VALUE_:"):
                    return result.replace("_VALUE_:", "", 1)
                elif result.startswith("_ERROR_:"):
                    raise self.__class__.JavaScriptException(
                        result.replace("_ERROR_:", "", 1)
                    )

        def load_url(self, url: str):
            """
            Loads an URL.

            :param url: The URL to laod. Can be 'http://', 'https://' or 'file://'.
            """

            self.__py_view__.loadURL(url)

        def load_html(self, html: str, base_url: str = None):
            """
            Loads an HTML string.

            :param html: The HTML code to load.
            :param base_url: An optional URL used to resolve relative paths.
            """

            baseURL = base_url
            if baseURL is not None:
                baseURL = str(base_url)

            self.__py_view__.loadHTML(html, baseURL=baseURL)

        def reload(self):
            """
            Reloads the Web View.
            """

            self.__py_view__.reload()

        def stop(self):
            """
            Stops loading content.
            """

            self.__py_view__.stop()

        def go_back(self):
            """
            Goes back.
            """

            self.__py_view__.goBack()

        def go_forward(self):
            """
            Goes forward.
            """

            self.__py_view__.goForward()

        @property
        def can_go_back(self) -> bool:
            """
            (Read Only) A boolean indicating whether :meth:`~pyto_ui.WebView.go_back` can be performed.

            :rtype: bool
            """

            return self.__py_view__.canGoBack

        @property
        def can_go_forward(self) -> bool:
            """
            (Read Only) A boolean indicating whether :meth:`~pyto_ui.WebView.go_forward` can be performed.

            :rtype: bool
            """
            return self.__py_view__.canGoForward

        @property
        def is_loading(self) -> bool:
            """
            (Read Only) A boolean indicating whether the Web View is loading content.

            :rtype: bool
            """

            return self.__py_view__.isLoading

        @property
        def url(self) -> str:
            """
            (Read Only) The current URL loaded into the Web View.

            :rtype: str
            """

            url = self.__py_view__.url
            if url is None:
                return None
            else:
                return str(url)

        @property
        def did_start_loading(self) -> Callable[[WebView], None]:
            """
            A function called when the Web View starts loading contents. Takes the sender Web View as parameter.

            :rtype: Callable[[WebView], None]
            """

            action = self.__py_view__.didStartLoading
            if action is None:
                return None
            else:
                return getattr(_values, str(action.identifier))

        @did_start_loading.setter
        def did_start_loading(self, new_value: Callable[[WebView], None]):
            if new_value is None:
                self.__py_view__.didStartLoading = None
            else:
                self.__py_view__.didStartLoading = _values.value(new_value)

        @property
        def did_finish_loading(self) -> Callable[[WebView], None]:
            """
            A function called when the Web View finished loading contents. Takes the sender Web View as parameter.

            :rtype: Callable[[WebView], None]
            """

            action = self.__py_view__.didFinishLoading
            if action is None:
                return None
            else:
                return getattr(_values, str(action.identifier))

        @did_finish_loading.setter
        def did_finish_loading(self, new_value: Callable[[WebView], None]):
            if new_value is None:
                self.__py_view__.didFinishLoading = None
            else:
                self.__py_view__.didFinishLoading = _values.value(new_value)

        @property
        def did_fail_loading(self) -> Callable[[WebView, str], None]:
            """
            A function called when the Web View failed to load contents. Takes the sender Web View and a string describing the error as parameters.

            :rtype: Callable[[WebView, str], None]
            """

            action = self.__py_view__.didFailLoading
            if action is None:
                return None
            else:
                return getattr(_values, str(action.identifier))

        @did_fail_loading.setter
        def did_fail_loading(self, new_value: Callable[[WebView, str], None]):
            if new_value is None:
                self.__py_view__.didFailLoading = None
            else:
                self.__py_view__.didFailLoading = _values.value(new_value)


##################
# MARK: - Control Classes
##################


class Control(View):
    """
    The base class for controls, which are visual elements that convey a specific action or intention in response to user interactions.

    Inherited by :class:`Button`, :class:`SegmentedControl`, :class:`Slider`, :class:`Switch` and :class:`TextField`
    """

    def __init__(self):
        self.__py_view__ = __PyControl__.newView()
        self.__py_view__.managedValue = _values.value(self)

    @property
    def enabled(self) -> bool:
        """
        A boolean indicating whether the control is enabled.

        :rtype: bool
        """

        return self.__py_view__.enabled

    @enabled.setter
    def enabled(self, new_value: bool):
        self.__py_view__.enabled = new_value

    @property
    def horizontal_alignment(self) -> HORZONTAL_ALIGNMENT:
        """
        The horizontal alignment of the view's contents. See `Horizontal Alignment <constants.html#horizontal-alignment>`_ constants for possible values.

        :rtype: `Horizontal Alignment <constants.html#horizontal-alignment>`_
        """

        return self.__py_view__.contentHorizontalAlignment

    @horizontal_alignment.setter
    def horizontal_alignment(self, new_value: HORZONTAL_ALIGNMENT):
        self.__py_view__.contentHorizontalAlignment = new_value

    @property
    def vertical_alignment(self) -> VERTICAL_ALIGNMENT:
        """
        The vertical alignment of the view's contents. See `Vertical Alignemnt <constants.html#vertical-alignment>`_ constants for possible values.

        :rtype: `Vertical Alignment <constants.html#vertical-alignment>`_
        """

        return self.__py_view__.contentVerticalAlignment

    @vertical_alignment.setter
    def vertical_alignment(self, new_value: VERTICAL_ALIGNMENT):
        self.__py_view__.contentVerticalAlignment = new_value

    @property
    def action(self) -> Callable[[Control], None]:
        """
        A function called when the control triggers its action.
        For example, a :class:`Button` object calls this function when it's pressed.

        Takes the :class:`Control` object as parameter.

        :rtype: Callable[[Control], None]
        """

        action = self.__py_view__.action
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @action.setter
    def action(self, new_value: Callable[[Control], None]):
        if new_value is None:
            self.__py_view__.action = None
        else:
            self.__py_view__.action = _values.value(new_value)


class SegmentedControl(Control):
    """
    A horizontal control made of multiple segments, each segment functioning as a discrete button.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the segmented control changes its selection.
    """

    def __init__(self, segments: List[str] = []):
        self.__py_view__ = __PySegmentedControl__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.segments = segments

    @property
    def segments(self) -> List[str]:
        """
        A list of strings representing segments titles.

        :rtype: List[str]
        """

        return list(map(str, self.__py_view__.segments))

    @segments.setter
    def segments(self, new_value: List[str]):
        self.__py_view__.segments = new_value

    @property
    def selected_segment(self) -> int:
        """
        The index of selected segment.

        :rtype: int
        """

        return self.__py_view__.selectedSegmentIndex

    @selected_segment.setter
    def selected_segment(self, new_value: int):
        self.__py_view__.selectedSegmentIndex = new_value


class Slider(Control):
    """
    A control used to select a single value from a continuous range of values. The default range is located between ``0`` and ``1``.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the slider changes its value.
    """

    def __init__(self, value: float = 0.5):
        self.__py_view__ = __PySlider__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.value = value

    def set_value_with_animation(self, value: float):
        """
        Sets the value of the slider with an animation.

        :param value: The value of the slider.
        """

        self.__py_view__.setValue(value, animated=True)

    @property
    def value(self) -> float:
        """
        The value of the slider between its range.

        :rtype: float
        """

        return self.__py_view__.value

    @value.setter
    def value(self, new_value: float):
        self.__py_view__.value = new_value

    @property
    def minimum_value(self) -> float:
        """
        The minimum value of the slider.

        :rtype: float
        """

        return self.__py_view__.minimumValue

    @minimum_value.setter
    def minimum_value(self, new_value: float):
        self.__py_view__.minimumValue = new_value

    @property
    def maximum_value(self) -> float:
        """
        The maximum value of the slider.

        :rtype: float
        """

        return self.__py_view__.maximumValue

    @maximum_value.setter
    def maximum_value(self, new_value: float):
        self.__py_view__.maximumValue = new_value

    @property
    def minimum_track_color(self) -> Color:
        """
        The color used to tint the default minimum track.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.minimumTrackColor
        if c is None:
            return None
        else:
            return Color(c)

    @minimum_track_color.setter
    def minimum_track_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.minimumTrackColor = None
        else:
            self.__py_view__.minimumTrackColor = new_value.__py_color__

    @property
    def maximum_track_color(self) -> Color:
        """
        The color used to tint the default maximum track.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.maximumTrackColor
        if c is None:
            return None
        else:
            return Color(c)

    @maximum_track_color.setter
    def maximum_track_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.maximumTrackColor = None
        else:
            self.__py_view__.maximumTrackColor = new_value.__py_color__

    @property
    def thumb_color(self) -> Color:
        """
        The color used to tint the default thumb.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.thumbColor
        if c is None:
            return None
        else:
            return Color(c)

    @thumb_color.setter
    def thumb_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.thumbColor = None
        else:
            self.__py_view__.thumbColor = new_value.__py_color__


class Switch(Control):
    """
    A control that offers a binary choice, such as On/Off.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the switch changes its value.
    """

    def __init__(self, on=False):
        self.__py_view__ = __PySwitch__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.on = on

    def set_on_with_animation(self, on: bool):
        """
        Sets the state of the switch to On or Off with an animation.

        :param on: A boolean indicating whether the switch should be On.
        """

        self.__py_view__.setOn(on, animated=True)

    @property
    def on(self) -> bool:
        """
        A boolean indicating whether the switch is On.

        :rtype: bool
        """

        return self.__py_view__.isOn

    @on.setter
    def on(self, new_value: bool):
        self.__py_view__.isOn = new_value

    @property
    def on_color(self) -> Color:
        """
        The color used to tint the appearance of the switch when it is turned on.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.onColor
        if c is None:
            return None
        else:
            return Color(c)

    @on_color.setter
    def on_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.onColor = None
        else:
            self.__py_view__.onColor = new_value.__py_color__

    @property
    def thumb_color(self) -> Color:
        """
        The color used to tint the appearance of the thumb.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.thumbColor
        if c is None:
            return None
        else:
            return Color(c)

    @thumb_color.setter
    def thumb_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.thumbColor = None
        else:
            self.__py_view__.thumbColor = new_value.__py_color__


class Button(Control):
    """
    A control that executes your custom code in response to user interactions.
    To add an action, set :data:`~pyto_ui.Control.action`.

    For types of buttons, see `Button Type <constants.html#button-type>`_ constants.
    """

    def __init__(
        self,
        type: BUTTON_TYPE = __v__("BUTTON_TYPE_SYSTEM"),
        title: str = "",
        image: "Image" = None,
    ):
        if type == "BUTTON_TYPE_SYSTEM":
            self.__py_view__ = __PyButton__.newButtonWithType(BUTTON_TYPE_SYSTEM)
        else:
            self.__py_view__ = __PyButton__.newButtonWithType(type)
        self.__py_view__.managedValue = _values.value(self)
        self.title = title
        self.image = image

    @property
    def title(self) -> str:
        """
        The title of the button

        :rtype: str
        """

        title = self.__py_view__.title
        if title is not None:
            return str(title)
        else:
            return None

    @title.setter
    def title(self, new_value: str):
        self.__py_view__.title = new_value

    @property
    def title_color(self) -> Color:
        """
        The color of the title.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.titleColor
        if c is None:
            return None
        else:
            return Color(c)

    @title_color.setter
    def title_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.titleColor = None
        else:
            self.__py_view__.titleColor = new_value.__py_color__

    @property
    def image(self) -> "Image.Image":
        """
        The image displayed on the button. Can be a ``PIL`` image or an ``UIKit`` symbol image. For more information about symbols, see :func:`~pyto_ui.image_with_system_name`.

        :rtype: PIL.Image.Image
        """

        ui_image = self.__py_view__.image
        if ui_image is None:
            return None
        elif ui_image.symbolImage:
            return ui_image
        else:
            return __pil_image_from_ui_image__(ui_image)

    @image.setter
    def image(self, new_value: "Image"):
        if new_value is None:
            self.__py_view__.image = None
        elif "objc_class" in dir(new_value) and new_value.objc_class == UIImage:
            self.__py_view__.image = new_value
        else:
            self.__py_view__.image = __ui_image_from_pil_image__(new_value)

    @property
    def font(self) -> Font:
        """
        The font to be applied to the text.

        :rtype: pyto_ui.Font
        """

        py_font = self.__py_view__.font
        if py_font is None:
            return None
        font = Font(None, None)
        font.__ui_font__ = py_font
        return font

    @font.setter
    def font(self, new_value: Font):
        if new_value is None:
            self.__py_view__.font = None
        else:
            self.__py_view__.font = new_value.__ui_font__


class TextField(Control):
    """
    A field to type single line text.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the text field changes its text.
    """

    def __init__(self, text: str = "", placeholder: str = None):
        self.__py_view__ = __PyTextField__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.text = text
        self.placeholder = placeholder

    @property
    def border_style(self) -> TEXT_FIELD_BORDER_STYLE:
        return self.__py_view__.borderStyle

    @border_style.setter
    def border_style(self, new_value: TEXT_FIELD_BORDER_STYLE):
        self.__py_view__.borderStyle = new_value

    @property
    def did_begin_editing(self) -> Callable[[TextField], None]:
        """
        A function called when the Text Field begins editing. Takes the sender Text Field as parameter.

        :rtype: Callable[[TextField], None]
        """

        action = self.__py_view__.didBeginEditing
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_begin_editing.setter
    def did_begin_editing(self, new_value: Callable[[TextField], None]):
        if new_value is None:
            self.__py_view__.didBeginEditing = None
        else:
            self.__py_view__.didBeginEditing = _values.value(new_value)

    @property
    def did_end_editing(self) -> Callable[[TextField], None]:
        """
        A function called when the Text Field ends editing. Takes the sender Text Field as parameter.

        :rtype: Callable[[TextField], None]
        """

        action = self.__py_view__.didEndEditing
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_end_editing.setter
    def did_end_editing(self, new_value: Callable[[TextField], None]):
        if new_value is None:
            self.__py_view__.didEndEditing = None
        else:
            self.__py_view__.didEndEditing = _values.value(new_value)

    @property
    def text(self) -> str:
        """
        The text contained in the Text Field.

        :rtype: str
        """

        return str(self.__py_view__.text)

    @text.setter
    def text(self, new_value: str):
        self.__py_view__.text = new_value

    @property
    def placeholder(self) -> str:
        """
        A gray text shown when there is no text.

        :rtype: str
        """

        return str(self.__py_view__.placeholder)

    @placeholder.setter
    def placeholder(self, new_value: str):
        self.__py_view__.placeholder = new_value

    @property
    def text_color(self) -> Color:
        """
        The color of the text displayed on screen.

        :rtype: pyto_ui.Color
        """

        c = self.__py_view__.textColor
        if c is None:
            return None
        else:
            return Color(c)

    @text_color.setter
    def text_color(self, new_value: Color):
        if new_value is None:
            self.__py_view__.textColor = None
        else:
            self.__py_view__.textColor = new_value.__py_color__

    @property
    def font(self) -> Font:
        """
        The font of the text displayed on screen.

        :rtype: pyto_ui.Font
        """

        py_font = self.__py_view__.font
        if py_font is None:
            return None

        font = Font(None, None)
        font.__ui_font__ = py_font
        return font

    @font.setter
    def font(self, new_value: Font):
        if new_value is None:
            self.__py_view__.font = None
        else:
            self.__py_view__.font = new_value.__ui_font__

    @property
    def text_alignment(self) -> TEXT_ALIGNMENT:
        """
        The alignment of the text displayed on screen. See `Text Alignment <constants.html#text-alignment>`_ constants for possible values.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return self.__py_view__.textAlignment

    @text_alignment.setter
    def text_alignment(self, new_value: TEXT_ALIGNMENT):
        self.__py_view__.textAlignment = new_value

    @property
    def smart_dashes(self) -> bool:
        """
        A boolean indicating whether smart dashes are enabled.

        :rtype: bool
        """

        return self.__py_view__.smartDashes

    @smart_dashes.setter
    def smart_dashes(self, new_value: bool):
        self.__py_view__.smartDashes = new_value

    @property
    def smart_quotes(self) -> bool:
        """
        A boolean indicating whether smart quotes are enabled.

        :rtype: bool
        """

        return self.__py_view__.smartQuotes

    @smart_quotes.setter
    def smart_quotes(self, new_value: bool):
        self.__py_view__.smartQuotes = new_value

    @property
    def keyboard_type(self) -> KEYBOARD_TYPE:
        """
        The type of keyboard to use while editing the text. See `Keyboard Type <constants.html#keyboard-type>`_ constants for possible values.

        :rtype: `Keyboard Type <constants.html#keyboard-type>`_
        """

        return self.__py_view__.keyboardType

    @keyboard_type.setter
    def keyboard_type(self, new_value: KEYBOARD_TYPE):
        self.__py_view__.keyboardType = new_value

    @property
    def autocapitalization_type(self) -> AUTO_CAPITALIZE:
        """
        The type of autocapitalization to use while editing th text. See `Auto Capitalization <constants.html#auto-capitalization>`_ constants for possible values.

        :rtype: `Auto Capitalization <constants.html#auto-capitalization>`_
        """

        return self.__py_view__.autocapitalizationType

    @autocapitalization_type.setter
    def autocapitalization_type(self, new_value: AUTO_CAPITALIZE):
        self.__py_view__.autocapitalizationType = new_value

    @property
    def autocorrection(self) -> bool:
        """
        A boolean indicating whether autocorrection is enabled.

        :rtype: bool
        """

        return self.__py_view__.autocorrection

    @autocorrection.setter
    def autocorrection(self, new_value: bool):
        self.__py_view__.autocorrection = new_value

    @property
    def keyboard_appearance(self) -> KEYBOARD_APPEARANCE:
        """
        The appearance of the keyboard used while editing the text. See `Keyboard Appearance <constants.html#keyboard-appearance>`_ constants for possible values.

        :rtype: `Keyboard Appearance <constants.html#keyboard-appearance>`_
        """

        return self.__py_view__.keyboardAppearance

    @keyboard_appearance.setter
    def keyboard_appearance(self, new_value: KEYBOARD_APPEARANCE):
        self.__py_view__.keyboardAppearance = new_value

    @property
    def return_key_type(self) -> RETURN_KEY_TYPE:
        """
        The type of return key to show on the keyboard used to edit the text. See `Return Key Type <constants.html#return-key-type>`_ constants for possible values.

        :rtype: `Return Key Type <constants.html#return-key-type>`_
        """

        return self.__py_view__.returnKeyType

    @return_key_type.setter
    def return_key_type(self, new_value: RETURN_KEY_TYPE):
        self.__py_view__.returnKeyType = new_value

    @property
    def secure(self) -> bool:
        """
        A boolean indicating whether the keyboard should be configured to enter sensitive data. The text entered by the user will be hidden.

        :rtype: bool
        """

        return self.__py_view__.isSecureTextEntry

    @secure.setter
    def secure(self, new_value: bool):
        self.__py_view__.isSecureTextEntry = new_value


###################
# MARK: - Functions
###################


def font_family_names() -> List[str]:
    """
    Returns all font family names that can be used to initialize a font.

    :rtype: List[str]
    """

    names = __UIFont__.familyNames

    py_names = []

    for name in names:
        py_names.append(str(name))

    return py_names


def image_with_system_name(name: str) -> UIImage:
    """
    Returns a system symbol image from given name. The return value is an UIKit ``UIImage`` object, so it can only be used on the ``pyto_ui`` library.
    More info about symbols on `Apple's Web Site <https://developer.apple.com/design/resources/>`_ .

    :param name: The name of the SF Symbol.

    :rtype: UIImage
    """

    check(name, "name", [str])

    image = UIImage.systemImageNamed(name, withConfiguration=None)
    if image is None:
        raise ValueError("The given symbol name is not valid.")
    return image


def show_view(view: View, mode: PRESENTATION_MODE):
    """
    Presents the given view.

    This function doesn't return until the view is closed. You can use another thread to perform background tasks and modify the UI after it's presented.

    On iPad, if the view has a custom size, it will be used for the presentation.

    :param view: The :class:`~pyto_ui.View` object to present.
    :param mode: The presentation mode to use. The value will be ignored on a widget. See `Presentation Mode <constants.html#presentation-mode>`_ constants for possible values.
    """

    check(view, "view", [View])
    check(mode, "mode", [int])

    def show(view, mode):
        view.__py_view__.presentationMode = mode
        try:
            ConsoleViewController.showView(
                view.__py_view__,
                onConsoleForPath=threading.current_thread().script_path,
            )
        except AttributeError:
            ConsoleViewController.showView(view.__py_view__, onConsoleForPath=None)

        while view.__py_view__.isPresented:
            sleep(0.2)

    if (
        "__editor_delegate__" in dir(builtins)
        and builtins.__editor_delegate__ is not None
    ):
        global show_view
        _show_view = show_view
        show_view = show
        try:
            builtins.__editor_delegate__.show_ui(view, mode)
            return
        except NotImplementedError:
            pass
        finally:
            show_view = _show_view

    show(view, mode)


def show_view_controller(view_controller: "UIViewController"):
    """
    Shows an UIKit View Controller. This function must be called from the main thread.

    See `Objective-C <Objective-C.html>`_ and `mainthread <mainthread.html>`_.

    :param view_controller: UIViewController.
    """

    if not NSThread.currentThread.isMainThread:
        raise RuntimeError(
            "'show_view_controller' must be called from the app's main thread. See the 'mainthread' module."
        )

    try:
        ConsoleViewController.showVC(
            view_controller, onConsoleForPath=threading.current_thread().script_path
        )
    except AttributeError:
        ConsoleViewController.showVC(view_controller, onConsoleForPath=None)


def pick_color() -> Color:
    """
    Picks a color with the system color picker and returns it.

    Requires iOS 14.

    :rtype: pyto_ui.Color
    """

    UIDevice = ObjCClass("UIDevice")
    if (
        UIDevice is not None
        and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 14
    ):
        raise NotImplementedError("The color picker requires iOS 14.")

    script_path = None
    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        pass

    color = ConsoleViewController.pickColorWithScriptPath(script_path)
    if color is None:
        return None
    else:
        return Color(color)


def pick_font(size: float = None) -> Font:
    """
    Picks a font with the system font picker and returns it.

    :rtype: pyto_ui.Font
    """

    check(size, "size", [float, int, None])

    script_path = None
    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        pass

    font = ConsoleViewController.pickFontWithScriptPath(script_path)
    if font is None:
        return None
    else:
        pyFont = Font("", 0)
        pyFont.__ui_font__ = font
        if size is not None:
            pyFont = pyFont.with_size(size)
        return pyFont
