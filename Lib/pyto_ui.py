"""
UI for scripts

The ``pyto_ui`` module contains classes for building and presenting a native UI, in app or in the Today Widget.
This library's API is very similar to UIKit.

This library may have a lot of similarities with ``UIKit``, but subclassing isn't supported very well. Instead of overriding methods, you will often need to set properties to a function. For properties, setters are what makes the passed value take effect, so instead of override the getter, you should just set properties. If you really want to subclass a :class:`View`, you can set properties from the initializer.

(Many docstrings are quoted from the Apple Documentation)
"""

from __future__ import annotations
from unicodedata import name
from xml.dom.minidom import Attr
from xmlrpc.client import Boolean
from UIKit import UIFont as __UIFont__, UIImage, UIView, UIViewController, UIMenuElement
from Foundation import NSThread, NSURL
from typing import List, Callable, Tuple, Type, TypeVar
from types import ModuleType
from pyto import __Class__, ConsoleViewController, PyAlert as __PyAlert__
from __check_type__ import check
from timeit import default_timer as timer
from __image__ import __ui_image_from_pil_image__, __pil_image_from_ui_image__
from time import sleep
from io import BytesIO
from threading import Thread
from mainthread import mainthread
from inspect import signature
import __pyto_ui_garbage_collector__ as _gc
import os
import sys
import base64
import threading
import _values
import ui_constants
import builtins
import json
import warnings
import re
from timeit import default_timer as timer
from _docsupport import is_sphinx
from dataclasses import dataclass
from enum import Enum, IntFlag
from collections import namedtuple
import inspect
import dis
import weakref
import functools

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


if not is_sphinx:
    from toga_iOS.widgets.box import Box as iOSBox
    from toga_iOS.colors import native_color
    import toga


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
__PyScrollView__ = __Class__("PyScrollView")
__PyControl__ = __Class__("PyControl")
__PyStackView__ = __Class__("PyStackView")
__PyStackSpacerView__ = __Class__("PyStackSpacerView")
__PySlider__ = __Class__("PySlider")
__PyStepper__ = __Class__("PyStepper")
__PySegmentedControl__ = __Class__("PySegmentedControl")
__PySwitch__ = __Class__("PySwitch")
__PyButton__ = __Class__("PyButton")
__PyLabel__ = __Class__("PyLabel")
__PyImageView__ = __Class__("PyImageView")
__PyTextView__ = __Class__("PyTextView")
__PyTextField__ = __Class__("PyTextField")
__PyTableView__ = __Class__("PyTableView")
__PyTableViewCell__ = __Class__("PyTableViewCell")
__PyTableViewSection__ = __Class__("PyTableViewSection")
__PyWebView__ = __Class__("PyWebView")
__PyCollectionView__ = __Class__("PyCollectionView")
__PyGestureRecognizer__ = __Class__("PyGestureRecognizer")
__PyUIKitView__ = __Class__("PyUIKitView")
__PyNavigationView__ = __Class__("PyNavigationView")
__PyIBStackView__ = __Class__("PyIBStackView")

__PyMenuElement__ = __Class__("PyMenuElement")
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

# MARK: - Sheet size

class SheetSize:

    IPHONE_SMALL = (320, 568)

    IPHONE_MEDIUM = (375, 667)

    IPHONE_LARGE = (428, 926)

    IPAD_SMALL = (744, 1133)

    FORM = (1, 1)

    PAGE = (2, 2)

# MARK: - Key

class KeyCode(Enum):

    A = 0x04
    """ The raw HID hexadecimal usage code 04. """

    B = 0x05
    """ The raw HID hexadecimal usage code 05. """

    C = 0x06
    """ The raw HID hexadecimal usage code 06. """

    D = 0x07
    """ The raw HID hexadecimal usage code 07. """

    E = 0x08
    """ The raw HID hexadecimal usage code 08. """

    F = 0x09
    """ The raw HID hexadecimal usage code 09. """

    G = 0x0A
    """ The raw HID hexadecimal usage code 0A. """

    H = 0x0B
    """ The raw HID hexadecimal usage code 0B. """

    I = 0x0C
    """ The raw HID hexadecimal usage code 0C. """

    J = 0x0D
    """ The raw HID hexadecimal usage code 0D. """

    K = 0x0E
    """ The raw HID hexadecimal usage code 0E. """

    L = 0x0F
    """ The raw HID hexadecimal usage code 0F. """

    M = 0x10
    """ The raw HID hexadecimal usage code 10. """

    N = 0x11
    """ The raw HID hexadecimal usage code 11. """

    O = 0x12
    """ The raw HID hexadecimal usage code 12. """

    P = 0x13
    """ The raw HID hexadecimal usage code 13. """

    Q = 0x14
    """ The raw HID hexadecimal usage code 14. """

    R = 0x15
    """ The raw HID hexadecimal usage code 15. """

    S = 0x16
    """ The raw HID hexadecimal usage code 16. """

    T = 0x17
    """ The raw HID hexadecimal usage code 17. """

    U = 0x18
    """ The raw HID hexadecimal usage code 18. """

    V = 0x19
    """ The raw HID hexadecimal usage code 19. """

    W = 0x1A
    """ The raw HID hexadecimal usage code 1A. """

    X = 0x1B
    """ The raw HID hexadecimal usage code 1B. """

    Y = 0x1C
    """ The raw HID hexadecimal usage code 1C. """

    Z = 0x1D
    """ The raw HID hexadecimal usage code 1D. """

    _0 = 0x27
    """ The raw HID hexadecimal usage code 27. """

    _1 = 0x1E
    """ The raw HID hexadecimal usage code 1E. """

    _2 = 0x1F
    """ The raw HID hexadecimal usage code 1F. """

    _3 = 0x20
    """ The raw HID hexadecimal usage code 20. """

    _4 = 0x21
    """ The raw HID hexadecimal usage code 21. """

    _5 = 0x22
    """ The raw HID hexadecimal usage code 22. """

    _6 = 0x23
    """ The raw HID hexadecimal usage code 23. """

    _7 = 0x24
    """ The raw HID hexadecimal usage code 24. """

    _8 = 0x25
    """ The raw HID hexadecimal usage code 25. """

    _9 = 0x26
    """ The raw HID hexadecimal usage code 26. """

    BACKSLASH = 0x31
    """ The raw HID hexadecimal usage code 31. """

    CLOSE_BRACKET = 0x30
    """ The raw HID hexadecimal usage code 30. """

    COMMA = 0x36
    """ The raw HID hexadecimal usage code 36. """

    EQUAL_SIGN = 0x2E
    """ The raw HID hexadecimal usage code 2E. """

    HYPHEN = 0x2D
    """ The raw HID hexadecimal usage code 2D. """

    NON_U_S_BACKSLASH = 0x64
    """ The raw HID hexadecimal usage code 64. """

    NON_U_S_POUND = 0x32
    """ The raw HID hexadecimal usage code 32. """

    OPEN_BRACKET = 0x2F
    """ The raw HID hexadecimal usage code 2F. """

    PERIOD = 0x37
    """ The raw HID hexadecimal usage code 37. """

    QUOTE = 0x34
    """ The raw HID hexadecimal usage code 34. """

    SEMICOLON = 0x33
    """ The raw HID hexadecimal usage code 33. """

    SEPARATOR = 0x9F
    """ The raw HID hexadecimal usage code 9F. """

    SLASH = 0x38
    """ The raw HID hexadecimal usage code 38. """

    SPACEBAR = 0x2C
    """ The raw HID hexadecimal usage code 2C. """

    CAPS_LOCK = 0x39
    """ The raw HID hexadecimal usage code 39. """

    LEFT_ALT = 0xE2
    """ The raw HID hexadecimal usage code E2. """

    LEFT_CONTROL = 0xE0
    """ The raw HID hexadecimal usage code E0. """

    LEFT_SHIFT = 0xE1
    """ The raw HID hexadecimal usage code E1. """

    LOCKING_CAPS_LOCK = 0x82
    """ The raw HID hexadecimal usage code 82. """

    LOCKING_NUM_LOCK = 0x83
    """ The raw HID hexadecimal usage code 83. """

    LOCKING_SCROLL_LOCK = 0x84
    """ The raw HID hexadecimal usage code 84. """

    RIGHT_ALT = 0xE6
    """ The raw HID hexadecimal usage code E6. """

    RIGHT_CONTROL = 0xE4
    """ The raw HID hexadecimal usage code E4. """

    RIGHT_SHIFT = 0xE5
    """ The raw HID hexadecimal usage code E5. """

    SCROLL_LOCK = 0x47
    """ The raw HID hexadecimal usage code 47. """

    LEFT_ARROW = 0x50
    """ The raw HID hexadecimal usage code 50. """

    RIGHT_ARROW = 0x4F
    """ The raw HID hexadecimal usage code 4F. """

    UP_ARROW = 0x52
    """ The raw HID hexadecimal usage code 52. """

    DOWN_ARROW = 0x51
    """ The raw HID hexadecimal usage code 51. """

    PAGE_UP = 0x4B
    """ The raw HID hexadecimal usage code 4B. """

    PAGE_DOWN = 0x4E
    """ The raw HID hexadecimal usage code 4E. """

    HOME = 0x4A
    """ The raw HID hexadecimal usage code 4A. """

    END = 0x4D
    """ The raw HID hexadecimal usage code 4D. """

    DELETE_FORWARD = 0x4C
    """ The raw HID hexadecimal usage code 4C. """

    DELETE_OR_BACKSPACE = 0x2A
    """ The raw HID hexadecimal usage code 2A. """

    ESCAPE = 0x29
    """ The raw HID hexadecimal usage code 29. """

    INSERT = 0x49
    """ The raw HID hexadecimal usage code 49. """

    RETURN = 0x9E
    """ The raw HID hexadecimal usage code 9E. """

    TAB = 0x2B
    """ The raw HID hexadecimal usage code 2B. """

    F_1 = 0x3A
    """ The raw HID hexadecimal usage code 3A. """

    F_2 = 0x3B
    """ The raw HID hexadecimal usage code 3B. """

    F_3 = 0x3C
    """ The raw HID hexadecimal usage code 3C. """

    F_4 = 0x3D
    """ The raw HID hexadecimal usage code 3D. """

    F_5 = 0x3E
    """ The raw HID hexadecimal usage code 3E. """

    F_6 = 0x3F
    """ The raw HID hexadecimal usage code 3F. """

    F_7 = 0x40
    """ The raw HID hexadecimal usage code 40. """

    F_8 = 0x41
    """ The raw HID hexadecimal usage code 41. """

    F_9 = 0x42
    """ The raw HID hexadecimal usage code 42. """

    F_1_0 = 0x43
    """ The raw HID hexadecimal usage code 43. """

    F_1_1 = 0x44
    """ The raw HID hexadecimal usage code 44. """

    F_1_2 = 0x45
    """ The raw HID hexadecimal usage code 45. """

    F_1_3 = 0x68
    """ The raw HID hexadecimal usage code 68. """

    F_1_4 = 0x69
    """ The raw HID hexadecimal usage code 69. """

    F_1_5 = 0x6A
    """ The raw HID hexadecimal usage code 6A. """

    F_1_6 = 0x6B
    """ The raw HID hexadecimal usage code 6B. """

    F_1_7 = 0x6C
    """ The raw HID hexadecimal usage code 6C. """

    F_1_8 = 0x6D
    """ The raw HID hexadecimal usage code 6D. """

    F_1_9 = 0x6E
    """ The raw HID hexadecimal usage code 6E. """

    F_2_0 = 0x6F
    """ The raw HID hexadecimal usage code 6F. """

    F_2_1 = 0x70
    """ The raw HID hexadecimal usage code 70. """

    F_2_2 = 0x71
    """ The raw HID hexadecimal usage code 71. """

    F_2_3 = 0x72
    """ The raw HID hexadecimal usage code 72. """

    F_2_4 = 0x73
    """ The raw HID hexadecimal usage code 73. """

    PAUSE = 0x48
    """ The raw HID hexadecimal usage code 48. """

    STOP = 0x78
    """ The raw HID hexadecimal usage code 78. """

    MUTE = 0x7F
    """ The raw HID hexadecimal usage code 7F. """

    VOLUME_UP = 0x80
    """ The raw HID hexadecimal usage code 80. """

    VOLUME_DOWN = 0x81
    """ The raw HID hexadecimal usage code 81. """

    L_A_N_G_1 = 0x90
    """ The raw HID hexadecimal usage code 90. """

    L_A_N_G_2 = 0x91
    """ The raw HID hexadecimal usage code 91. """

    L_A_N_G_3 = 0x92
    """ The raw HID hexadecimal usage code 92. """

    L_A_N_G_4 = 0x93
    """ The raw HID hexadecimal usage code 93. """

    L_A_N_G_5 = 0x94
    """ The raw HID hexadecimal usage code 94. """

    L_A_N_G_6 = 0x95
    """ The raw HID hexadecimal usage code 95. """

    L_A_N_G_7 = 0x96
    """ The raw HID hexadecimal usage code 96. """

    L_A_N_G_8 = 0x97
    """ The raw HID hexadecimal usage code 97. """

    L_A_N_G_9 = 0x98
    """ The raw HID hexadecimal usage code 98. """

    INTERNATIONAL_1 = 0x87
    """ The raw HID hexadecimal usage code 87. """

    INTERNATIONAL_2 = 0x88
    """ The raw HID hexadecimal usage code 88. """

    INTERNATIONAL_3 = 0x89
    """ The raw HID hexadecimal usage code 89. """

    INTERNATIONAL_4 = 0x8A
    """ The raw HID hexadecimal usage code 8A. """

    INTERNATIONAL_5 = 0x8B
    """ The raw HID hexadecimal usage code 8B. """

    INTERNATIONAL_6 = 0x8C
    """ The raw HID hexadecimal usage code 8C. """

    INTERNATIONAL_7 = 0x8D
    """ The raw HID hexadecimal usage code 8D. """

    INTERNATIONAL_8 = 0x8E
    """ The raw HID hexadecimal usage code 8E. """

    INTERNATIONAL_9 = 0x8F
    """ The raw HID hexadecimal usage code 8F. """

    ERROR_ROLL_OVER = 0x01
    """ The raw HID hexadecimal usage code 01. """

    ERROR_UNDEFINED = 0x03
    """ The raw HID hexadecimal usage code 03. """

    AGAIN = 0x79
    """ The raw HID hexadecimal usage code 79. """

    ALTERNATE_ERASE = 0x99
    """ The raw HID hexadecimal usage code 99. """

    APPLICATION = 0x65
    """ The raw HID hexadecimal usage code 65. """

    CANCEL = 0x9B
    """ The raw HID hexadecimal usage code 9B. """

    CLEAR = 0x9C
    """ The raw HID hexadecimal usage code 9C. """

    CLEAR_OR_AGAIN = 0xA2
    """ The raw HID hexadecimal usage code A2. """

    COPY = 0x7C
    """ The raw HID hexadecimal usage code 7C. """

    CR_SEL_OR_PROPS = 0xA3
    """ The raw HID hexadecimal usage code A3. """

    CUT = 0x7B
    """ The raw HID hexadecimal usage code 7B. """

    EX_SEL = 0xA4
    """ The raw HID hexadecimal usage code A4. """

    EXECUTE = 0x74
    """ The raw HID hexadecimal usage code 74. """

    FIND = 0x7E
    """ The raw HID hexadecimal usage code 7E. """

    GRAVE_ACCENT_AND_TILDE = 0x35
    """ The raw HID hexadecimal usage code 35. """

    HELP = 0x75
    """ The raw HID hexadecimal usage code 75. """

    LEFT_G_U_I = 0xE3
    """ The raw HID hexadecimal usage code E3. """

    MENU = 0x76
    """ The raw HID hexadecimal usage code 76. """

    OPER = 0xA1
    """ The raw HID hexadecimal usage code A1. """

    OUT = 0xA0
    """ The raw HID hexadecimal usage code A0. """

    P_O_S_T_FAIL = 0x02
    """ The raw HID hexadecimal usage code 02. """

    PASTE = 0x7D
    """ The raw HID hexadecimal usage code 7D. """

    POWER = 0x66
    """ The raw HID hexadecimal usage code 66. """

    PRINT_SCREEN = 0x46
    """ The raw HID hexadecimal usage code 46. """

    PRIOR = 0x9D
    """ The raw HID hexadecimal usage code 9D. """

    RETURN_OR_ENTER = 0x28
    """ The raw HID hexadecimal usage code 28. """

    RIGHT_G_U_I = 0xE7
    """ The raw HID hexadecimal usage code E7. """

    SELECT = 0x77
    """ The raw HID hexadecimal usage code 77. """

    SYS_REQ_OR_ATTENTION = 0x9A
    """ The raw HID hexadecimal usage code 9A. """

    UNDO = 0x7A
    """ The raw HID hexadecimal usage code 7A. """

    _RESERVED = 0xFFFF
    """ The raw HID hexadecimal usage code FFFF. """

class KeyModifier(IntFlag):

    ALPHA_SHIFT = 65536
    """ A modifier flag that indicates the user pressed the Caps Lock key. """

    SHIFT = 131072
    """ A modifier flag that indicates the user pressed the Shift key. """

    CONTROL = 262144
    """ A modifier flag that indicates the user pressed the Control key. """    
    
    ALTERNATE = 524288
    """ A modifier flag that indicates the user pressed the Option key. """

    COMMAND = 1048576
    """ A modifier flag that indicates the user pressed the Command key. """

    NUMERIC_PAD = 2097152
    """ A modifier flag that indicates the user pressed a key located on the numeric keypad. """

class Key:

    def __init__(self, key_code: KeyCode, modifier_flags: KeyModifier, characters: str):
        self.key_code = key_code
        self.modifier_flags = modifier_flags
        self.characters = characters

# MARK: - Gesture Recognizer Type

class GestureType(Enum):
    """
    Types of gestures handled by a gesture recognizer.
    """

    LONG_PRESS = ui_constants.GESTURE_TYPE_LONG_PRESS
    """
    A long press gesture.
    """


    PAN = ui_constants.GESTURE_TYPE_PAN
    """
    A dragging gesture.
    """

    TAP = ui_constants.GESTURE_TYPE_TAP
    """
    A tap gesture.
    """

# MARK: - Keyboard Appearance

class KeyboardAppearance(Enum):
    """
    Appearances of the OS keyboard.
    """

    DEFAULT = ui_constants.KEYBOARD_APPEARANCE_DEFAULT
    """
    Specifies the default keyboard appearance for the current input method.
    """

    LIGHT = ui_constants.KEYBOARD_APPEARANCE_LIGHT
    """
    Specifies a keyboard appearance suitable for a light UI look.
    """

    DARK = ui_constants.KEYBOARD_APPEARANCE_DARK
    """
    Specifies a keyboard appearance suitable for a dark UI look.
    """

# MARK: - Keyboard Type

class KeyboardType(Enum):
    """
    Keyboard layouts.
    """

    DEFAULT = ui_constants.KEYBOARD_TYPE_DEFAULT
    """
    Specifies the default keyboard for the current input method.
    """

    ASCII_CAPABLE = ui_constants.KEYBOARD_TYPE_ASCII_CAPABLE
    """
    Specifies a keyboard that displays standard ASCII characters.
    """

    ASCII_CAPABLE_NUMBER_PAD = (
        ui_constants.KEYBOARD_TYPE_ASCII_CAPABLE_NUMBER_PAD
    )
    """
    Specifies a number pad that outputs only ASCII digits.
    """

    DECIMAL_PAD = ui_constants.KEYBOARD_TYPE_DECIMAL_PAD
    """
    Specifies a keyboard with numbers and a decimal point.
    """

    EMAIL_ADDRESS = ui_constants.KEYBOARD_TYPE_EMAIL_ADDRESS
    """
    Specifies a keyboard optimized for entering email addresses. This keyboard type prominently features the at (“@”), period (“.”) and space characters.
    """

    NAME_PHONE_PAD = ui_constants.KEYBOARD_TYPE_NAME_PHONE_PAD
    """
    Specifies a keypad designed for entering a person’s name or phone number. This keyboard type does not support auto-capitalization.
    """

    NUMBER_PAD = ui_constants.KEYBOARD_TYPE_NUMBER_PAD
    """
    Specifies a numeric keypad designed for PIN entry. This keyboard type prominently features the numbers 0 through 9. This keyboard type does not support auto-capitalization.
    """

    NUMBERS_AND_PUNCTUATION = ui_constants.KEYBOARD_TYPE_NUMBERS_AND_PUNCTUATION
    """
    Specifies the numbers and punctuation keyboard.
    """

    PHONE_PAD = ui_constants.KEYBOARD_TYPE_PHONE_PAD
    """
    Specifies a keypad designed for entering telephone numbers. This keyboard type prominently features the numbers 0 through 9 and the “*” and “#” characters. This keyboard type does not support auto-capitalization.
    """

    TWITTER = ui_constants.KEYBOARD_TYPE_TWITTER
    """
    Specifies a keyboard optimized for Twitter text entry, with easy access to the at (“@”) and hash (“#”) characters.
    """

    URL = ui_constants.KEYBOARD_TYPE_URL
    """
    Specifies a keyboard optimized for URL entry. This keyboard type prominently features the period (“.”) and slash (“/”) characters and the “.com” string.
    """

    WEB_SEARCH = ui_constants.KEYBOARD_TYPE_WEB_SEARCH
    """
    Specifies a keyboard optimized for web search terms and URL entry. This keyboard type prominently features the space and period (“.”) characters.
    """

# MARK: - Return Key Type

class ReturnKeyType(Enum):
    """
    Return key types.
    """

    DEFAULT = ui_constants.RETURN_KEY_TYPE_DEFAULT
    """
    Specifies that the visible title of the Return key is “return”.
    """

    CONTINUE = ui_constants.RETURN_KEY_TYPE_CONTINUE
    """
    Specifies that the visible title of the Return key is “Continue”.
    """

    DONE = ui_constants.RETURN_KEY_TYPE_DONE
    """
    Specifies that the visible title of the Return key is “Done”.
    """

    EMERGENCY_CALL = ui_constants.RETURN_KEY_TYPE_EMERGENCY_CALL
    """
    Specifies that the visible title of the Return key is “Emergency Call”.
    """

    GO = ui_constants.RETURN_KEY_TYPE_GO
    """
    Specifies that the visible title of the Return key is “Go”.
    """

    GOOGLE = ui_constants.RETURN_KEY_TYPE_GOOGLE
    """
    Specifies that the visible title of the Return key is “Google”.
    """

    JOIN = ui_constants.RETURN_KEY_TYPE_JOIN
    """
    Specifies that the visible title of the Return key is “Join”.
    """

    NEXT = ui_constants.RETURN_KEY_TYPE_NEXT
    """
    Specifies that the visible title of the Return key is “Next”.
    """

    ROUTE = ui_constants.RETURN_KEY_TYPE_ROUTE
    """
    Specifies that the visible title of the Return key is “Route”.
    """

    SEARCH = ui_constants.RETURN_KEY_TYPE_SEARCH
    """
    Specifies that the visible title of the Return key is “Search”.
    """

    SEND = ui_constants.RETURN_KEY_TYPE_SEND
    """
    Specifies that the visible title of the Return key is “Send”.
    """

    YAHOO = ui_constants.RETURN_KEY_TYPE_YAHOO
    """
    Specifies that the visible title of the Return key is “Yahoo”.
    """

# MARK: - Autocapitalization Type

class AutoCapitalization(Enum):
    """
    Configure auto capitalization on text entries.
    """

    NONE = ui_constants.AUTO_CAPITALIZE_NONE
    """
    Specifies that there is no automatic text capitalization.
    """

    ALL = ui_constants.AUTO_CAPITALIZE_ALL
    """
    Specifies automatic capitalization of all characters, such as for entry of two-character state abbreviations for the United States.
    """

    SENTENCES = ui_constants.AUTO_CAPITALIZE_SENTENCES
    """
    Specifies automatic capitalization of the first letter of each sentence.
    """

    WORDS = ui_constants.AUTO_CAPITALIZE_WORDS
    """
    Specifies automatic capitalization of the first letter of each word.
    """

# MARK: - Font Text Style

class FontTextStyle(Enum):
    """
    Pre-defined system font styles.
    """

    BODY = ui_constants.FONT_TEXT_STYLE_BODY
    """
    The font used for body text.
    """

    CALLOUT = ui_constants.FONT_TEXT_STYLE_CALLOUT
    """
    The font used for callouts.
    """

    CAPTION_1 = ui_constants.FONT_TEXT_STYLE_CAPTION_1
    """
    The font used for standard captions.
    """

    CAPTION_2 = ui_constants.FONT_TEXT_STYLE_CAPTION_2
    """
    The font used for alternate captions.
    """

    FOOTNOTE = ui_constants.FONT_TEXT_STYLE_FOOTNOTE
    """
    The font used in footnotes.
    """

    HEADLINE = ui_constants.FONT_TEXT_STYLE_HEADLINE
    """
    The font used for headings.
    """

    SUBHEADLINE = ui_constants.FONT_TEXT_STYLE_SUBHEADLINE
    """
    The font used for subheadings.
    """

    LARGE_TITLE = ui_constants.FONT_TEXT_STYLE_LARGE_TITLE
    """
    The font style for large titles.
    """

    TITLE_1 = ui_constants.FONT_TEXT_STYLE_TITLE_1
    """
    The font used for first level hierarchical headings.
    """

    TITLE_2 = ui_constants.FONT_TEXT_STYLE_TITLE_2
    """
    The font used for second level hierarchical headings.
    """

    TITLE_3 = ui_constants.FONT_TEXT_STYLE_TITLE_3
    """
    The font used for third level hierarchical headings.
    """

# MARK: - Font Size

class FontSize(Enum):
    """
    Pre-defined system font sizes.
    """

    LABEL_SIZE = ui_constants.FONT_LABEL_SIZE
    """
    Returns the standard font size used for labels.
    """

    BUTTON_SIZE = ui_constants.FONT_BUTTON_SIZE
    """
    Returns the standard font size used for buttons.
    """

    SMALL_SYSTEM_SIZE = ui_constants.FONT_SMALL_SYSTEM_SIZE
    """
    Returns the size of the standard small system font.
    """

    SYSTEM_SIZE = ui_constants.FONT_SYSTEM_SIZE
    """
    Returns the size of the standard system font.
    """

# MARK: - Presentation Mode

class PresentationMode(Enum):
    """
    Customize the presentation of a view.
    """

    SHEET = ui_constants.PRESENTATION_MODE_SHEET
    """
    A presentation style that displays the content centered in the screen.
    """

    FULLSCREEN = ui_constants.PRESENTATION_MODE_FULLSCREEN
    """
    A presentation style in which the presented view covers the screen.
    """

    NEW_SCENE = ui_constants.PRESENTATION_MODE_NEW_SCENE
    """
    A presentation style in which the presented view is opened on a new window scene if the script is running on an iPad.
    On iPhone, the view presents full screen.
    """

    WIDGET = ui_constants.PRESENTATION_MODE_WIDGET

# MARK: - Appearance

class Appearance(Enum):
    """
    UI appearance.
    """

    UNSPECIFIED = ui_constants.APPEARANCE_UNSPECIFIED
    """
    An unspecified interface style.
    """

    LIGHT = ui_constants.APPEARANCE_LIGHT
    """
    The light interface style.
    """

    DARK = ui_constants.APPEARANCE_DARK
    """
    The dark interface style.
    """

# MARK: - Auto Resizing

class AutoResizing(IntFlag):
    """
    Configure a view for auto resizing.
    """

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

class ContentMode(Enum):
    """
    Options to specify how a view adjusts its content when its size changes.
    """

    SCALE_TO_FILL = ui_constants.CONTENT_MODE_SCALE_TO_FILL
    """
    The option to scale the content to fit the size of itself by changing the aspect ratio of the content if necessary.
    """

    SCALE_ASPECT_FIT = ui_constants.CONTENT_MODE_SCALE_ASPECT_FIT
    """
    The option to scale the content to fit the size of the view by maintaining the aspect ratio. Any remaining area of the view’s bounds is transparent.
    """

    SCALE_ASPECT_FILL = ui_constants.CONTENT_MODE_SCALE_ASPECT_FILL
    """
    The option to scale the content to fill the size of the view. Some portion of the content may be clipped to fill the view’s bounds.
    """

    REDRAW = ui_constants.CONTENT_MODE_REDRAW
    """
    The option to redisplay the view when the bounds change by invoking the ``setNeedsDisplay()`` method.
    """

    CENTER = ui_constants.CONTENT_MODE_CENTER
    """
    The option to center the content in the view’s bounds, keeping the proportions the same.
    """

    TOP = ui_constants.CONTENT_MODE_TOP
    """
    The option to center the content aligned at the top in the view’s bounds.
    """

    BOTTOM = ui_constants.CONTENT_MODE_BOTTOM
    """
    The option to center the content aligned at the bottom in the view’s bounds.
    """

    LEFT = ui_constants.CONTENT_MODE_LEFT
    """
    The option to align the content on the left of the view.
    """

    RIGHT = ui_constants.CONTENT_MODE_RIGHT
    """
    The option to align the content on the right of the view.
    """

    TOP_LEFT = ui_constants.CONTENT_MODE_TOP_LEFT
    """
    The option to align the content in the top-left corner of the view.
    """

    TOP_RIGHT = ui_constants.CONTENT_MODE_TOP_RIGHT
    """
    The option to align the content in the top-right corner of the view.
    """

    BOTTOM_LEFT = ui_constants.CONTENT_MODE_BOTTOM_LEFT
    """
    The option to align the content in the bottom-left corner of the view.
    """

    BOTTOM_RIGHT = ui_constants.CONTENT_MODE_BOTTOM_RIGHT
    """
    The option to align the content in the bottom-right corner of the view.
    """

# MARK: - Horizontal Alignment

class HorizontalAlignment(Enum):
    """
    Horizontal alignment.
    """

    CENTER = ui_constants.HORIZONTAL_ALIGNMENT_CENTER
    """
    Aligns the content horizontally in the center of the control.
    """

    FILL = ui_constants.HORIZONTAL_ALIGNMENT_FILL
    """
    Aligns the content horizontally to fill the content rectangles; text may wrap and images may be stretched.
    """

    LEADING = ui_constants.HORIZONTAL_ALIGNMENT_LEADING
    """
    Aligns the content horizontally from the leading edge of the control.
    """

    LEFT = ui_constants.HORIZONTAL_ALIGNMENT_LEFT
    """
    Aligns the content horizontally from the left of the control (the default).
    """

    RIGHT = ui_constants.HORIZONTAL_ALIGNMENT_RIGHT
    """
    Aligns the content horizontally from the right of the control.
    """

    TRAILING = ui_constants.HORIZONTAL_ALIGNMENT_TRAILING
    """
    Aligns the content horizontally from the trailing edge of the control.
    """

# MARK: - Vertical Alignment

class VerticalAlignment(Enum):
    """
    Vertical alignment.
    """

    BOTTOM = ui_constants.VERTICAL_ALIGNMENT_BOTTOM
    """
    Aligns the content vertically at the bottom in the control.
    """

    CENTER = ui_constants.VERTICAL_ALIGNMENT_CENTER
    """
    Aligns the content vertically in the center of the control.
    """

    FILL = ui_constants.VERTICAL_ALIGNMENT_FILL
    """
    Aligns the content vertically to fill the content rectangle; images may be stretched.
    """

    TOP = ui_constants.VERTICAL_ALIGNMENT_TOP
    """
    Aligns the content vertically at the top in the control (the default).
    """

# MARK: - Button Type

class ButtonType(Enum):
    """
    Pre-defined system buttons.
    """

    SYSTEM = ui_constants.BUTTON_TYPE_SYSTEM
    """
    A system style button, such as those shown in navigation bars and toolbars.
    """

    CONTACT_ADD = ui_constants.BUTTON_TYPE_CONTACT_ADD
    """
    A contact add button.
    """

    CUSTOM = ui_constants.BUTTON_TYPE_CUSTOM
    """
    No button style.
    """

    DETAIL_DISCLOSURE = ui_constants.BUTTON_TYPE_DETAIL_DISCLOSURE
    """
    A detail disclosure button.
    """

    INFO_DARK = ui_constants.BUTTON_TYPE_INFO_DARK
    """
    An information button that has a dark background.
    """

    INFO_LIGHT = ui_constants.BUTTON_TYPE_INFO_LIGHT
    """
    An information button that has a light background.
    """

# MARK: - Text Alignment

class TextAlignment(Enum):
    """
    Configure the text alignment of a view.
    """

    LEFT = ui_constants.TEXT_ALIGNMENT_LEFT
    """
    Text is visually left aligned.
    """

    RIGHT = ui_constants.TEXT_ALIGNMENT_RIGHT
    """
    Text is visually right aligned.
    """

    CENTER = ui_constants.TEXT_ALIGNMENT_CENTER
    """
    Text is visually center aligned.
    """

    JUSTIFIED = ui_constants.TEXT_ALIGNMENT_JUSTIFIED
    """
    Text is justified.
    """

    NATURAL = ui_constants.TEXT_ALIGNMENT_NATURAL
    """
    Use the default alignment associated with the current localization of the app. The default alignment for left-to-right scripts is left, and the default alignment for right-to-left scripts is right.
    """

# MARK: - Line Break Mode

class LineBreakMode(Enum):
    """
    Constants that specify what happens when a line is too long for a container.
    """


    BY_WORD_WRAPPING = ui_constants.LINE_BREAK_MODE_BY_WORD_WRAPPING
    """
    Wrapping occurs at word boundaries, unless the word itself doesn’t fit on a single line.
    """

    BY_CHAR_WRAPPING = ui_constants.LINE_BREAK_MODE_BY_CHAR_WRAPPING
    """
    Wrapping occurs before the first character that doesn’t fit.
    """

    BY_CLIPPING = ui_constants.LINE_BREAK_MODE_BY_CLIPPING
    """
    Lines are simply not drawn past the edge of the text container.
    """

    BY_TRUNCATING_HEAD = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_HEAD
    """
    The line is displayed so that the end fits in the container and the missing text at the beginning of the line is indicated by an ellipsis glyph. Although this mode works for multiline text, it is more often used for single line text.
    """

    BY_TRUNCATING_TAIL = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_TAIL
    """
    The line is displayed so that the beginning fits in the container and the missing text at the end of the line is indicated by an ellipsis glyph. Although this mode works for multiline text, it is more often used for single line text.
    """

    BY_TRUNCATING_MIDDLE = ui_constants.LINE_BREAK_MODE_BY_TRUNCATING_MIDDLE
    """
    The line is displayed so that the beginning and end fit in the container and the missing text in the middle is indicated by an ellipsis glyph. This mode is used for single-line layout; using it with multiline text truncates the text into a single line.
    """

# MARK: - Touch Type

class TouchType(Enum):
    """
    Type of touch.
    """

    DIRECT = ui_constants.TOUCH_TYPE_DIRECT
    """
    A touch resulting from direct contact with the screen.
    """

    INDIRECT = ui_constants.TOUCH_TYPE_INDIRECT
    """
    A touch that did not result from contact with the screen.
    """

    PENCIL = ui_constants.TOUCH_TYPE_PENCIL
    """
    A touch from Apple Pencil.
    """

    INDIRECT_POINTER = ui_constants.TOUCH_TYPE_PENCIL
    """
    A click from a pointer.
    """

# MARK: - Gesture State

class GestureState(Enum):
    """
    The state of a gesture recognizer.
    """

    POSSIBLE = ui_constants.GESTURE_STATE_POSSIBLE
    """
    The gesture recognizer has not yet recognized its gesture, but may be evaluating touch events. This is the default state.
    """

    BEGAN = ui_constants.GESTURE_STATE_BEGAN
    """
    The gesture recognizer has received touch objects recognized as a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop.
    """

    CHANGED = ui_constants.GESTURE_STATE_CHANGED
    """
    The gesture recognizer has received touches recognized as a change to a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop.
    """

    ENDED = ui_constants.GESTURE_STATE_ENDED
    """
    The gesture recognizer has received touches recognized as the end of a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
    """

    CANCELLED = ui_constants.GESTURE_STATE_CANCELLED
    """
    The gesture recognizer has received touches resulting in the cancellation of a continuous gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
    """

    RECOGNIZED = ui_constants.GESTURE_STATE_RECOGNIZED
    """
    The gesture recognizer has received a multi-touch sequence that it recognizes as its gesture. It sends its action message (or messages) at the next cycle of the run loop and resets its state to possible.
    """

# MARK: - Table View Cell Style

class TableViewCellStyle(Enum):
    """
    Styles of table view cells.
    """

    DEFAULT = ui_constants.TABLE_VIEW_CELL_STYLE_DEFAULT
    """
    A simple style for a cell with a text label (black and left-aligned) and an optional image view.
    """

    SUBTITLE = ui_constants.TABLE_VIEW_CELL_STYLE_SUBTITLE
    """
    A style for a cell with a left-aligned label across the top and a left-aligned label below it in smaller gray text.
    """

    VALUE1 = ui_constants.TABLE_VIEW_CELL_STYLE_VALUE1
    """
    A style for a cell with a label on the left side of the cell with left-aligned and black text; on the right side is a label that has smaller blue text and is right-aligned. The Settings application uses cells in this style.
    """

    VALUE2 = ui_constants.TABLE_VIEW_CELL_STYLE_VALUE2
    """
    A style for a cell with a label on the left side of the cell with text that is right-aligned and blue; on the right side of the cell is another label with smaller text that is left-aligned and black. The Phone/Contacts application uses cells in this style.
    """


# MARK: - Table View Cell Accessory Type

class AccessoryType(Enum):
    """
    Table view cell accessory types.
    """

    NONE = ui_constants.ACCESSORY_TYPE_NONE
    """
    No accessory view.
    """

    CHECKMARK = ui_constants.ACCESSORY_TYPE_CHECKMARK
    """
    A checkmark image.
    """

    DETAIL_BUTTON = ui_constants.ACCESSORY_TYPE_DETAIL_BUTTON
    """
    An information button.
    """

    DETAIL_DISCLOSURE_BUTTON = ui_constants.ACCESSORY_TYPE_DETAIL_DISCLOSURE_BUTTON
    """
    An information button and a disclosure (chevron) control.
    """

    DISCLOSURE_INDICATOR = ui_constants.ACCESSORY_TYPE_DISCLOSURE_INDICATOR
    """
    A chevron-shaped control for presenting new content.
    """

# MARK: - Table View Style

class TableViewStyle(Enum):
    """
    Styles of a table view.
    """


    PLAIN = ui_constants.TABLE_VIEW_STYLE_PLAIN
    """
    A plain table view.
    """

    GROUPED = ui_constants.TABLE_VIEW_STYLE_GROUPED
    """
    A table view whose sections present distinct groups of rows.
    """

    INSET_GROUPED = ui_constants.TABLE_VIEW_STYLE_INSET_GROUPED
    """
    A table view where the grouped sections are inset with rounded corners.
    """

# MARK: - Text Field Border Style

class TextFieldBorderStyle(Enum):
    """
    Text field border style.
    """

    NONE = ui_constants.TEXT_FIELD_BORDER_STYLE_NONE
    """
    The text field does not display a border.
    """

    BEZEL = ui_constants.TEXT_FIELD_BORDER_STYLE_BEZEL
    """
    Displays a bezel-style border for the text field. This style is typically used for standard data-entry fields.
    """

    LINE = ui_constants.TEXT_FIELD_BORDER_STYLE_LINE
    """
    Displays a thin rectangle around the text field.
    """

    ROUNDED_RECT = ui_constants.TEXT_FIELD_BORDER_STYLE_ROUNDED_RECT
    """
    Displays a rounded-style border for the text field.
    """

# MARK: - Button Item Style

class ButtonItemStyle(Enum):
    """
    Styles of a bar button item.
    """

    PLAIN = ui_constants.BUTTON_ITEM_STYLE_PLAIN
    """
    Glows when tapped. The default item style.
    """

    DONE = ui_constants.BUTTON_ITEM_STYLE_DONE
    """
    The style for a done button—for example, a button that completes some task and returns to the previous view.
    """

# MARK: - Button Item System Item

class SystemItem(Enum):
    """
    System bar button items.
    """

    ACTION = ui_constants.SYSTEM_ITEM_ACTION
    """
    The system action button.
    """

    ADD = ui_constants.SYSTEM_ITEM_ADD
    """
    The system plus button containing an icon of a plus sign.
    """

    BOOKMARKS = ui_constants.SYSTEM_ITEM_BOOKMARKS
    """
    The system bookmarks button.
    """

    CAMERA = ui_constants.SYSTEM_ITEM_CAMERA
    """
    The system camera button.
    """

    CANCEL = ui_constants.SYSTEM_ITEM_CANCEL
    """
    The system Cancel button, localized.
    """

    COMPOSE = ui_constants.SYSTEM_ITEM_COMPOSE
    """
    The system compose button.
    """

    DONE = ui_constants.SYSTEM_ITEM_DONE
    """
    The system Done button, localized.
    """

    EDIT = ui_constants.SYSTEM_ITEM_EDIT
    """
    The system Edit button, localized.
    """

    FAST_FORWARD = ui_constants.SYSTEM_ITEM_FAST_FORWARD
    """
    The system fast forward button.
    """

    FLEXIBLE_SPACE = ui_constants.SYSTEM_ITEM_FLEXIBLE_SPACE
    """
    Blank space to add between other items. The space is distributed equally between the other items. Other item properties are ignored when this value is set.
    """

    ORGANIZE = ui_constants.SYSTEM_ITEM_ORGANIZE
    """
    The system organize button.
    """

    PAUSE = ui_constants.SYSTEM_ITEM_PAUSE
    """
    The system pause button.
    """

    PLAY = ui_constants.SYSTEM_ITEM_PLAY
    """
    The system play button.
    """

    REDO = ui_constants.SYSTEM_ITEM_REDO
    """
    The system redo button.
    """

    REFRESH = ui_constants.SYSTEM_ITEM_REFRESH
    """
    The system refresh button.
    """

    REPLY = ui_constants.SYSTEM_ITEM_REPLY
    """
    The system reply button.
    """

    REWIND = ui_constants.SYSTEM_ITEM_REWIND
    """
    The system rewind button.
    """

    SAVE = ui_constants.SYSTEM_ITEM_SAVE
    """
    The system Save button, localized.
    """

    SEARCH = ui_constants.SYSTEM_ITEM_SEARCH
    """
    The system search button.
    """

    STOP = ui_constants.SYSTEM_ITEM_STOP
    """
    The system stop button.
    """

    TRASH = ui_constants.SYSTEM_ITEM_TRASH
    """
    The system trash button.
    """

    UNDO = ui_constants.SYSTEM_ITEM_UNDO
    """
    The system undo button.
    """

###############
# MARK: - Other Classes
###############


# MARK: - Menu


class MenuElementState(Enum):
    """
    The state of a menu element.
    """

    OFF = 0
    """
    Off.
    """

    ON = 1
    """
    On.
    """

    MIXED = 2
    """
    Mixed.
    """


class MenuElementAttributes(IntFlag):
    """
    Attributes of a menu element.
    """

    DESTRUCTIVE = 2
    """
    Destructive.
    """

    DISABLED = 1
    """
    Selection disabled.
    """

    HIDDEN = 4
    """
    Hidden.
    """

    KEEPS_MENU_PRESENTED = 8
    """
    Keep menu presented after selecting an element.
    """


class MenuOptions(IntFlag):
    """
    Menu options.
    """

    DISPLAY_INLINE = 1
    """
    Display the children elements inline without the need to expand the menu.
    """

    DESTRUCTIVE = 2
    """
    Destructive.
    """

    SINGLE_SELECTION = 32
    """
    Only allow the selection of one element.
    """


class MenuElementSize(Enum):
    """
    The size of the children elements of a menu.
    """

    SMALL = 0
    """
    Small.
    """

    MEDIUM = 1
    """
    Medium.
    """

    LARGE = 2
    """
    Large.
    """


class MenuElement:
    """
    A menu element. 
    Do not initialize. Use either :class:`~pyto_ui.MenuAction` or :class:`~pyto_ui.Menu`."
    """
    
    def __init__(self):
        try:
            self.__py_element__.value = _values.value(self)
            self.__py_element__.update = _values.value(self.update)
        except AttributeError:
            msg = "Cannot initialize 'MenuElement' directly. Use either 'MenuAction' or 'Menu'."
            raise NotImplementedError(msg)

    @property
    def symbol_name(self) -> str:
        """
        An image representation of the menu element.
        See `sf_symbols <sf_symbols.html>` for possible values.
        """

        name = self.__py_element__.symbolName
        if name is not None:
            return str(name)


    @symbol_name.setter
    def symbol_name(self, new_value: str):
        self.__py_element__.symbolName = new_value


    @property
    def title(self) -> str:
        """
        The title of the menu element.
        """

        return str(self.__py_element__.title)

    @title.setter
    def title(self, new_value: str):
        self.__py_element__.title = new_value


    @property
    def subtitle(self) -> str:
        """
        The subtitle of the menu element.
        """
        
        subtitle = self.__py_element__.subtitle
        if subtitle is not None:
            return str(subtitle)

    @subtitle.setter
    def subtitle(self, new_value: str):
        self.__py_element__.subtitle = new_value


    def update(self):
        if callable(self.symbol_name):
            self.__py_element__.symbolName = self.symbol_name()
        
        if callable(self.title):
            self.__py_element__.title = self.title()

        if callable(self.subtitle):
            self.__py_element__.subtitle = self.subtitle()

    def make_element(self) -> UIMenuElement:
        raise NotImplementedError()


class MenuAction(MenuElement):
    """
    A tappable element in a menu.

    :param title: The title.
    :param subtitle: The subtitle.
    :param symbol_name: An image representation of the menu element. See `sf_symbols <sf_symbols.html>`_.
    :attributes: Attributes of the menu element. See :class:`~pyto_ui.MenuElementAttributes`_.
    :state: The state of the menu element. See :class:`~pyto_ui.MenuElementState`_.
    :action: A function that takes the instance of the caller menu element when tapped.
    """

    def __init__(
                    self,
                    title: str = "",
                    subtitle: str = None,
                    symbol_name: str = None,
                    attributes: MenuElementAttributes = MenuElementAttributes(0),
                    state: MenuElementState = MenuElementState.OFF,
                    action: Callable[[MenuAction], None] = None
                ):
        
        self.__py_element__ = __PyMenuElement__.alloc().init()

        
        if not callable(self.title):
            self.title = title

        if not callable(self.subtitle):
            self.subtitle = subtitle
        
        if not callable(self.symbol_name):
            self.symbol_name = symbol_name

        if not callable(self.attributes):
            self.attributes = attributes

        if not callable(self.state):
            self.state = state
        
        if not callable(self.action):
            self.action = action

        super().__init__()
        

    @property
    def action(self) -> Callable[[MenuAction], None]:
        """
        A function that takes the instance of the caller menu element when tapped.
        """

        action = self.__py_element__.action
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @action.setter
    def action(self, new_value: Callable[[MenuAction], None]):
        if new_value is None:
            self.__py_element__.action = None
        else:
            self.__py_element__.action = _values.value(new_value)


    @property
    def state(self) -> MenuElementState:
        """
        The state of the menu element. See :class:`~pyto_ui.MenuElementState`_.
        """

        return MenuElementState(self.__py_element__.state)

    @state.setter
    def state(self, new_value: MenuElementState):
        self.__py_element__.state = new_value

    
    @property
    def attributes(self) -> MenuElementAttributes:
        """
        Attributes of the menu element. See :class:`~pyto_ui.MenuElementAttributes`_.
        """

        return MenuElementState(self.__py_element__.attributes)

    @attributes.setter
    def attributes(self, new_value: MenuElementAttributes):
        self.__py_element__.attributes = new_value


    def update(self):
        super().update()

        if callable(self.state):
            self.__py_element__.state = self.state()

        if callable(self.attributes):
            self.__py_element__.attributes = self.attributes()

        if callable(self.action):
            self.__py_element__.action = _values.value(self.action)
            
    def make_element(self):
        return self.__py_element__.makeAction()


class Menu(MenuElement):
    """
    A whole menu. Can be assigned to a button: see :meth:`~pyto_ui.Button.menu`_.

    :param title: The title.
    :param subtitle: The subtitle.
    :param symbol_name: An image representation of the menu. See `sf_symbols <sf_symbols.html>`_.
    :options: Additional options. See :class:`~pyto_ui.MenuOptions`_.
    :preferred_element_size: The size of the children elements. See :class:`~pyto_ui.MenuElementSize`_.
    :children: A tuple of children menu elements.
    """

    def __init__(
                    self, 
                    title: str = "",
                    subtitle: str = None,
                    symbol_name: str = None,
                    options: MenuOptions = MenuOptions(0),
                    preferred_element_size: MenuElementSize = MenuElementSize.LARGE,
                    children: Tuple[MenuElement] = ()
                ):

        self.__py_element__ = __PyMenuElement__.alloc().init()
        self.__py_element__.isMenu = True
        
        self._children = ()

        if not callable(self.title):
            self.title = title

        if not callable(self.subtitle):
            self.subtitle = subtitle
        
        if not callable(self.symbol_name):
            self.symbol_name = symbol_name
        
        if not callable(self.options):
            self.options = options

        if not callable(self.preferred_element_size):
            self.preferred_element_size = preferred_element_size

        if not callable(self.children):
            self.children = children
    
        super().__init__()


    @property
    def preferred_element_size(self) -> MenuElementSize:
        """
        The size of the children elements. See :class:`~pyto_ui.MenuElementSize`_.
        """

        return MenuElementSize(self.__py_element__.preferredElementSize)
    
    @preferred_element_size.setter
    def preferred_element_size(self, new_value: MenuElementSize):
        self.__py_element__.preferredElementSize = new_value


    @property
    def options(self) -> MenuOptions:
        """
        Additional options. See :class:`~pyto_ui.MenuOptions`_.
        """

        return MenuOptions(self.__py_element__.options)
    
    @options.setter
    def options(self, new_value: MenuOptions):
        self.__py_element__.options = new_value


    @property
    def children(self) -> Tuple[MenuElement]:
        """
        A tuple of children menu elements.
        """

        return self._children

    @children.setter
    def children(self, new_value: Tuple[MenuElement]):
        self._children = new_value


    def update(self):
        super().update()

        if callable(self.options):
            self.__py_element__.options = self.options()

        if callable(self.preferred_element_size):
            self.__py_element__.preferredElementSize = self.preferred_element_size()

        if callable(self.children):
            children = self.children()
        else:
            children = self.children
        
        objc_children = []
        for child in children:
            objc_children.append(child.__py_element__)
        
        self.__py_element__.children = objc_children

    def make_element(self):
        return self.__py_element__.makeMenu()


# MARK: Rect

Rect = namedtuple("Rect", ["x", "y", "width", "height"])
"""
A tuple that contains the location and dimensions of a rectangle.
"""

Point = namedtuple("Point", ["x", "y"])
"""
A tuple that contains a point in a two-dimensional coordinate system.
"""

Size = namedtuple("Size", ["width", "height"])
"""
A tuple that contains width and height values.
"""

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

    For pre-defined colors, see :class:`~pyto_ui.SystemColors`.
    """

    __py_color__ = None

    def _hex_to_rgb(self, hx, hsl=False):
        if re.compile(r'#[a-fA-F0-9]{3}(?:[a-fA-F0-9]{3})?$').match(hx):
            div = 255.0 if hsl else 0
            if len(hx) <= 4:
                return tuple(int(hx[i]*2, 16) / div if div else
                            int(hx[i]*2, 16) for i in (1, 2, 3))
            return tuple(int(hx[i:i+2], 16) / div if div else
                        int(hx[i:i+2], 16) for i in (1, 3, 5))
        raise ValueError(f'"{hx}" is not a valid HEX code.')

    def configure_from_dictionary(self, obj):
        cls = Color
        if isinstance(obj, str):
            if obj.startswith("#"):
                color = self._hex_to_rgb(obj)
                self.__py_color__ = cls.rgb(color[0]/255, color[1]/255, color[2]/255).__py_color__
            else:
                self.__py_color__ = getattr(type(self), obj).__py_color__
        elif isinstance(obj, dict):
            if "dark" in obj and "light" in obj:
                light = cls.__new__(cls)
                light.configure_from_dictionary(obj["light"])

                dark = cls.__new__(cls)
                dark.configure_from_dictionary(obj["dark"])

                self.__py_color__ = cls.dynamic(light, dark).__py_color__
            else:
                try:
                    alpha = obj["alpha"]
                except KeyError:
                    alpha = 1
                
                self.__py_color__ = cls.rgb(obj["red"], obj["green"], obj["blue"], alpha).__py_color__
        else:
            return None

    def dictionary_representation(self):
        if self._dark is not None and self._light is not None:
            return {
                "dark": self._dark.dictionary_representation(),
                "light": self._light.dictionary_representation()
            }
        else:

            for attr in dir(type(self)):
                if attr.upper() != attr:
                    continue

                value = getattr(type(self), attr)
                if "__py_color__" in dir(value) and value.__py_color__.isEqual(self.__py_color__):
                    return attr

        return {
            "red": self.red(),
            "green": self.green(),
            "blue": self.blue(),
            "alpha": self.alpha()
        }

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

        self._light = None
        self._dark = None

    # def __del__(self):
    #    self.__py_color__.release()

    def __repr__(self):
        return "<"+self.__class__.__module__+"."+self.__class__.__name__+" "+str(self.__py_color__.managed.description)+">"

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

        object = cls(
            __PyColor__.colorWithLight(light.__py_color__, dark=dark.__py_color__)
        )

        object._light = light
        object._dark = dark

        return object

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

class SystemColors:
    """
    System defined colors.
    """

    LABEL = Color(ui_constants.COLOR_LABEL)
    """ The color for text labels containing primary content. """

    SECONDARY_LABEL = Color(ui_constants.COLOR_SECONDARY_LABEL)
    """ The color for text labels containing secondary content. """

    TERTIARY_LABEL = Color(ui_constants.COLOR_TERTIARY_LABEL)
    """ The color for text labels containing tertiary content. """

    QUATERNARY_LABEL = Color(ui_constants.COLOR_QUATERNARY_LABEL)
    """ The color for text labels containing quaternary content. """

    SYSTEM_FILL = Color(ui_constants.COLOR_SYSTEM_FILL)
    """ An overlay fill color for thin and small shapes. """

    SECONDARY_SYSTEM_FILL = Color(ui_constants.COLOR_SECONDARY_SYSTEM_FILL)
    """ An overlay fill color for medium-size shapes. """

    TERTIARY_SYSTEM_FILL = Color(ui_constants.COLOR_TERTIARY_SYSTEM_FILL)
    """ An overlay fill color for large shapes. """

    QUATERNARY_SYSTEM_FILL = Color(ui_constants.COLOR_QUATERNARY_SYSTEM_FILL)
    """ An overlay fill color for large areas containing complex content. """

    PLACEHOLDER_TEXT = Color(ui_constants.COLOR_PLACEHOLDER_TEXT)
    """ The color for placeholder text in controls or text views. """

    SYSTEM_BACKGROUND = Color(ui_constants.COLOR_SYSTEM_BACKGROUND)
    """ The color for the main background of your interface. """

    SECONDARY_SYSTEM_BACKGROUND = Color(
        ui_constants.COLOR_SECONDARY_SYSTEM_BACKGROUND
    )
    """ The color for content layered on top of the main background. """

    TERTIARY_SYSTEM_BACKGROUND = Color(ui_constants.COLOR_TERTIARY_SYSTEM_BACKGROUND)
    """ The color for content layered on top of secondary backgrounds. """

    SYSTEM_GROUPED_BACKGROUND = Color(ui_constants.COLOR_SYSTEM_GROUPED_BACKGROUND)
    """ The color for the main background of your grouped interface. """

    SECONDARY_GROUPED_BACKGROUND = Color(
        ui_constants.COLOR_SECONDARY_GROUPED_BACKGROUND
    )
    """ The color for content layered on top of the main background of your grouped interface. """

    TERTIARY_GROUPED_BACKGROUND = Color(
        ui_constants.COLOR_TERTIARY_GROUPED_BACKGROUND
    )
    """ The color for content layered on top of secondary backgrounds of your grouped interface. """

    SEPARATOR = Color(ui_constants.COLOR_SEPARATOR)
    """ The color for thin borders or divider lines that allows some underlying content to be visible. """

    OPAQUE_SEPARATOR = Color(ui_constants.COLOR_OPAQUE_SEPARATOR)
    """ The color for borders or divider lines that hide any underlying content. """

    LINK = Color(ui_constants.COLOR_LINK)
    """ The color for links. """

    DARK_TEXT = Color(ui_constants.COLOR_DARK_TEXT)
    """ The nonadaptable system color for text on a light background. """

    LIGHT_TEXT = Color(ui_constants.COLOR_LIGHT_TEXT)
    """ The nonadaptable system color for text on a dark background. """

    SYSTEM_BLUE = Color(ui_constants.COLOR_SYSTEM_BLUE)
    """ A blue color that automatically adapts to the current trait environment. """

    SYSTEM_GREEN = Color(ui_constants.COLOR_SYSTEM_GREEN)
    """ A green color that automatically adapts to the current trait environment. """

    SYSTEM_INDIGO = Color(ui_constants.COLOR_SYSTEM_INDIGO)
    """ An indigo color that automatically adapts to the current trait environment. """

    SYSTEM_ORANGE = Color(ui_constants.COLOR_SYSTEM_ORANGE)
    """ An orange color that automatically adapts to the current trait environment. """

    SYSTEM_PINK = Color(ui_constants.COLOR_SYSTEM_PINK)
    """ A pink color that automatically adapts to the current trait environment. """

    SYSTEM_PURPLE = Color(ui_constants.COLOR_SYSTEM_PURPLE)
    """ A purple color that automatically adapts to the current trait environment. """

    SYSTEM_RED = Color(ui_constants.COLOR_SYSTEM_RED)
    """ A red color that automatically adapts to the current trait environment. """

    SYSTEM_TEAL = Color(ui_constants.COLOR_SYSTEM_TEAL)
    """ A teal color that automatically adapts to the current trait environment. """

    SYSTEM_YELLOW = Color(ui_constants.COLOR_SYSTEM_YELLOW)
    """ A yellow color that automatically adapts to the current trait environment. """

    SYSTEM_GRAY = Color(ui_constants.COLOR_SYSTEM_GRAY)
    """ The base gray color. """

    SYSTEM_GRAY2 = Color(ui_constants.COLOR_SYSTEM_GRAY2)
    """ A second-level shade of grey. """

    SYSTEM_GRAY3 = Color(ui_constants.COLOR_SYSTEM_GRAY3)
    """ A third-level shade of grey. """

    SYSTEM_GRAY4 = Color(ui_constants.COLOR_SYSTEM_GRAY4)
    """ A fourth-level shade of grey. """

    SYSTEM_GRAY5 = Color(ui_constants.COLOR_SYSTEM_GRAY5)
    """ A fifth-level shade of grey. """

    SYSTEM_GRAY6 = Color(ui_constants.COLOR_SYSTEM_GRAY6)
    """ A sixth-level shade of grey. """

    CLEAR = Color(ui_constants.COLOR_CLEAR)
    """ A color object with grayscale and alpha values that are both 0.0. """

    BLACK = Color(ui_constants.COLOR_BLACK)
    """ A color object in the sRGB color space with a grayscale value of 0.0 and an alpha value of 1.0. """

    BLUE = Color(ui_constants.COLOR_BLUE)
    """ A color object with RGB values of 0.0, 0.0, and 1.0 and an alpha value of 1.0. """

    BROWN = Color(ui_constants.COLOR_BROWN)
    """ A color object with RGB values of 0.6, 0.4, and 0.2 and an alpha value of 1.0. """

    CYAN = Color(ui_constants.COLOR_CYAN)
    """ A color object with RGB values of 0.0, 1.0, and 1.0 and an alpha value of 1.0. """

    DARK_GRAY = Color(ui_constants.COLOR_DARK_GRAY)
    """ A color object with a grayscale value of 1/3 and an alpha value of 1.0. """

    GRAY = Color(ui_constants.COLOR_GRAY)
    """ A color object with a grayscale value of 0.5 and an alpha value of 1.0. """

    GREEN = Color(ui_constants.COLOR_GREEN)
    """ A color object with RGB values of 0.0, 1.0, and 0.0 and an alpha value of 1.0. """

    LIGHT_GRAY = Color(ui_constants.COLOR_LIGHT_GRAY)
    """ A color object with a grayscale value of 2/3 and an alpha value of 1.0. """

    MAGENTA = Color(ui_constants.COLOR_MAGENTA)
    """ A color object with RGB values of 1.0, 0.0, and 1.0 and an alpha value of 1.0. """

    ORANGE = Color(ui_constants.COLOR_ORANGE)
    """ A color object with RGB values of 1.0, 0.5, and 0.0 and an alpha value of 1.0. """

    PURPLE = Color(ui_constants.COLOR_PURPLE)
    """ A color object with RGB values of 0.5, 0.0, and 0.5 and an alpha value of 1.0. """

    RED = Color(ui_constants.COLOR_RED)
    """ A color object with RGB values of 1.0, 0.0, and 0.0 and an alpha value of 1.0. """

    WHITE = Color(ui_constants.COLOR_WHITE)
    """ A color object with a grayscale value of 1.0 and an alpha value of 1.0. """

    YELLOW = Color(ui_constants.COLOR_YELLOW)
    """ A color object with RGB values of 1.0, 1.0, and 0.0 and an alpha value of 1.0. """

try:
    if not SystemColors.CLEAR.__py_color__.objc_class.name.endswith("PyColor"): # Something went wrong, retry
        del sys.modules["ui_constants"]
        del sys.modules["pyto_ui"]

        import pyto_ui as _ui
        globals().update(_ui.__dict__)
except AttributeError:
    pass

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

    def configure_from_dictionary(self, obj):
        try:
            size = float(obj)
            self.__ui_font__ = __UIFont__.systemFontOfSize(CGFloat(size))
        except ValueError:
            try:
                parts = obj.split("-")
                name_parts = parts.copy()
                del name_parts[-1]
                name = "-".join(name_parts)
                self.__init__(name, float(parts[-1]))
            except ValueError:
                self.__init__(obj, FontSize.SYSTEM_SIZE)

    def dictionary_representation(self):
        return f"{str(self.__ui_font__.fontName)}-{float(self.__ui_font__.pointSize)}"

    def __repr__(self):
        return "<"+self.__class__.__module__+"."+self.__class__.__name__+" "+str(self.__ui_font__.description)+">"

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
    def font_with_style(cls, style: FontTextStyle) -> Font:
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
        self, type: GestureType, action: Callable[[GestureRecognizer], None] = None
    ):

        if "objc_class" in dir(type) and type.objc_class == __PyGestureRecognizer__:
            self.__py_gesture__ = type
        else:
            self.__py_gesture__ = __PyGestureRecognizer__.newRecognizerWithType(type)

        self.__py_gesture__.managedValue = _values.value(self)
        if action is not None:
            self.action = action

    def __repr__(self):
        return "<"+self.__class__.__module__+"."+self.__class__.__name__+" "+str(self.__py_gesture__.managed.description)+">"

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
            _view = _wrap_view(view)
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
    def state(self) -> GestureState:
        """
        (Read Only) The current state of the gesture recognizer.

        :rtype: `Gesture State <constants.html#gesture-state>`_
        """

        if self.__state__ is not None:
            return GestureState(self.__state__)
        else:
            return GestureState(self.__py_gesture__.state)

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
    def allowed_touch_types(self) -> Tuple[TouchType]:
        """
        An array of touch types used to distinguish type of touches. For possible values, see ``Touch Type`` constants.

        :rtype: List[`Touch Type <constants.html#touch-type>`_]
        """

        touch_types = []
        for touch_type in self.__py_gesture__.allowedTouchTypes:
            touch_types.append(TouchType(touch_type))
        return touch_types 

    @allowed_touch_types.setter
    def allowedTouchTypes(self, new_value: Tuple[TouchType]):
        self.__py_gesture__.allowedTouchTypes = list(new_value)

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

    _parent = None

    def configure_from_dictionary(self, dictionary):
        if "title" in dictionary and dictionary["title"] is not None:
            self.title = dictionary["title"]
        
        if "cells" in dictionary and dictionary["cells"] is not None:
            cells = []
            for cell in dictionary["cells"]:

                if isinstance(cell, View):
                    cell = cell.dictionary_representation()

                _cell = TableViewCell()
                _cell._parent = self._parent
                _cell.configure_from_dictionary(cell)
                cells.append(_cell)
            
            self.cells = cells

    def dictionary_representation(self):
        cells = []
        for cell in self.cells:
            cells.append(cell.dictionary_representation())

        d = {
            "title": self.title,
            "cells": cells
        }

        return d

    def __init__(self, title: str = "", cells: List["TableViewCell"] = []):
        self.__py_section__ = __PyTableViewSection__.new()
        self.__py_section__.managedValue = _values.value(self)
        self.title = title
        self.cells = cells

    def __del__(self):
        self.__py_section__.releaseReference()
        self.__py_section__.release()

    def __setattr__(self, name, value):
        if name == "__py_section__":
            previous = self.__py_section__
            if previous is not None and previous.references == 1:
                previous.releaseReference()
                previous.release()
            elif previous is not None:
                if previous not in _gc.collected:
                    _gc.collected.append(previous)

            if value is not None:
                value.retainReference()
                #value.retain()

        super().__setattr__(name, value)

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
            py_table_view = _wrap_view(table_view)
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
    def cells(self) -> Tuple["TableViewCell"]:
        """
        Cells contained in the section. After setting a value, the section will be reloaded automatically.
        The returned value of this property will always be a tuple, so mutating a list of cells won't trigger a reload.

        :rtype: Tuple[TableViewCell]
        """

        cells = self.__py_section__.cells
        py_cells = []
        for cell in cells:
            py_cell = _wrap_view(cell)
            py_cells.append(py_cell)
        return tuple(py_cells)

    @cells.setter
    def cells(self, new_value: "TableViewCell"):
        cells = []
        for cell in new_value:
            cells.append(cell.__py_view__)
        self.__py_section__.cells = list(cells)

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

    _system_item = None

    _style = None

    _get_function = None

    _parent = None

    def __del__(self):
        self.__py_item__.releaseReference()
        self.__py_item__.release()

    def __setattr__(self, name, value):
        if name == "__py_item__":
            previous = self.__py_item__
            if previous is not None and previous.references == 1:
                previous.releaseReference()
                previous.release()
            elif previous is not None:
                if previous not in _gc.collected:
                    _gc.collected.append(previous)

            if value is not None:
                value.retainReference()
                value.retain()
        
        super().__setattr__(name, value)

    def dictionary_representation(self):
        dict = {}
        if self.title is not None:
            dict["title"] = self.title
        
        if self.image is not None and isinstance(self.image, Image.Image):
            dict["image"] = self.image.filename
        
        if self._system_item is not None:
            dict["system_item"] = self._system_item.name

        dict["enabled"] = self.enabled

        for name in dir(self):
            try:
                func = getattr(self.__class__, name)
                if not isinstance(func, property):
                    continue
                func = func.fget

                sig = signature(func)
                if sig.return_annotation.startswith("Callable["):
                    value = getattr(self, name)
                    if callable(value) and "__self__" in dir(value) and value.__self__ == self:
                        dict[name] = "self."+value.__name__

            except AttributeError:
                continue

        return dict

    def configure_from_dictionary(self, dictionary):
        def get(key, _dict=dictionary, default=None):
            try:
                return _dict[key]
            except KeyError:
                return default
        
        if "connections" in dictionary:
            def _get_connections(key, default=None):
                return get(key, _dict=dictionary["connections"], default=default)
            
            self._get_function = _get_connections

        system_item = get("system_item")
        if system_item is not None:
            self._system_item = getattr(SystemItem, system_item)
            self.__py_item__ = __PyButtonItem__.alloc().initWithSystemItem(self._system_item)

        self.title = get("title")
        
        if get("image") is not None:
            if os.path.isfile(get("image")):
                self.image = Image.open(get("image"))
            else:
                self.image = image_with_system_name(get("image"))

        self.enabled = get("enabled", default=True)
        
        View._decode_functions(self)

    def _get_custom_view(self) -> View:
        view = self.__py_item__._customView
        if view is None:
            return
        
        return _wrap_view(view)

    def __init__(
        self,
        title: str = None,
        image: "Image" = None,
        system_item: SystemItem = None,
        style: ButtonItemStyle = __v__("PLAIN"),
    ):

        if style == "PLAIN":
            style = ButtonItemStyle.PLAIN

        if system_item is not None:
            self.__py_item__ = __PyButtonItem__.alloc().initWithSystemItem(system_item)
            self._system_item = system_item
        else:
            self.__py_item__ = __PyButtonItem__.alloc().initWithStyle(style)
            self._style = style

        self.__py_item__.managedValue = _values.value(self)
        self.title = title
        self.image = image

    def __repr__(self):
        return "<"+self.__class__.__module__+"."+self.__class__.__name__+" "+str(self.__py_item__.managed.description)+">"

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
    def style(self) -> ButtonItemStyle:
        """
        The button item style. See `Button Item Style <constants.html#button-item-style>`_ constants for possible values.

        :rtype: `Button Item Style <constants.html#button-item-style>`_
        """
        return ButtonItemStyle(self.__py_item__.style)

    @style.setter
    def style(self, new_value: ButtonItemStyle):
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


# MARK: - Padding

class Padding:
    """
    Padding with custom values.
    """

    top: float = None
    """ Top padding """

    bottom: float = None
    """ Bottom padding """

    left: float = None
    """ Left padding """

    right: float = None
    """ Right padding """

    def __init__(
        self, top: float = 0, bottom: float = 0, left: float = 0, right: float = 0
    ):
        self.top = top
        self.bottom = bottom
        self.left = left
        self.right = right


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

_views = {}
_cls = {}

class View:
    """
    An object that manages the content for a rectangular area on the screen.
    """

    __py_view__ = None

    _parent = None

    def _get(self, key, _dict, default=None):
        try:
            return _dict[key]
        except KeyError:
            return default

    def configure_from_dictionary(self, dictionary):
        if self.__py_view__ is None:
            self.__init__()

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)

        if "connections" in dictionary:
            def _get_connections(key, default=None):
                return get(key, _dict=dictionary["connections"], default=default)

            self._get_function = _get_connections

        self.name = get("name")

        if get("frame") is not None:
            self.frame = tuple(get("frame"))

        if get("size") is not None:
            self.size = tuple(get("size"))

        topbar = get("topbar")
        if topbar is not None:
            hidden = get("hidden", topbar, False)
            title = get("title", topbar)

            self.navigation_bar_hidden = hidden            
            self.title = title
        
        self.flex = get("flex", default=[])

        subviews = get("children", default=[])
        for view in subviews:
            if view == "Spacer":
                if not isinstance(self, StackView):
                    raise NotImplementedError("Spacers can only have a 'StackView' instance as their super view.")

                self.add_subview(_StackSpacerView())
            elif isinstance(view, View):
                view._parent = self
                view._decode_functions()
                self.add_subview(view)
            else:
                view = _from_json(view)
                view._parent = self
                view._decode_functions()
                self.add_subview(view)

        self.hidden = get("hidden", default=False)
        self.alpha = get("alpha", default=1)
        self.opaque = get("opaque", default=False)

        if get("background_color") is not None:
            bg_color = Color.__new__(Color)
            bg_color.configure_from_dictionary(get("background_color"))
            self.background_color = bg_color

        if get("tint_color") is not None:
            tint_color = Color.__new__(Color)
            tint_color.configure_from_dictionary(get("tint_color"))
            self.tint_color = tint_color
        
        self.user_interaction_enabled = get("user_interaction", default=True)
        self.clips_to_bounds = get("clips_to_bounds", default=False)
        self.corner_radius = get("corner_radius", default=0)
        self.border_width = get("border_width", default=0)

        if get("border_color") is not None:
            border_color = Color.__new__(Color)
            border_color.configure_from_dictionary(get("border_color"))
            self.border_color = border_color
        
        if get("content_mode") is not None:
            self.content_mode = getattr(ContentMode, get("content_mode"))

        if get("appearance") is not None:
            self.appearance = getattr(Appearance, get("appearance"))

        button_items = []
        if get("button_items") is not None:
            for item in get("button_items"):
                b_item = ButtonItem()
                b_item._parent = self
                b_item.configure_from_dictionary(item)
                button_items.append(b_item)

        self.button_items = button_items

        self._decode_functions()

    _get_function = None

    def _decode_functions(self):

        get = self._get_function

        if get is None:
            return

        for name in dir(self):
            try:
                func = getattr(self.__class__, name)
                if not isinstance(func, property):
                    continue
                func = func.fget

                sig = signature(func)
                if sig.return_annotation.startswith("Callable[") and get(name) is not None:
                    try:
                        setattr(self, name, eval(get(name), sys.modules["__main__"].__dict__, locals()))
                    except NameError:
                        def try_with_parent(parent):
                            if get(name) in dir(parent):
                                return getattr(parent, get(name))
                            elif parent._parent is not None:
                                return try_with_parent(parent._parent)
                            else:
                                return None
                        
                        setattr(self, name, try_with_parent(self))

            except AttributeError:
                continue

    def dictionary_representation(self) -> dict:
        subviews = []
        for view in self.subviews:
            if isinstance(view, _StackSpacerView):
                subviews.append("Spacer")
            else:
                subviews.append(view.dictionary_representation())

        bg_color = self.background_color
        if bg_color is not None:
            bg_color = bg_color.dictionary_representation()

        tint_color = self.tint_color
        if tint_color is not None and self._set_tint_color:
            tint_color = tint_color.dictionary_representation()

        border_color = self.border_color
        if border_color is not None:
            border_color = border_color.dictionary_representation()

        content_mode = self.content_mode.name

        if self.appearance == Appearance.DARK and self._set_appearance:
            appearance = "dark"
        elif self.appearance == Appearance.LIGHT and self._set_appearance:
            appearance = "light"
        else:
            appearance = None

        button_items = []
        for item in self.button_items:
            button_items.append(item.dictionary_representation())

        d = {
            "class": ".".join([self.__class__.__module__, self.__class__.__name__]),
            "name": self.name,

            "frame": self.frame,

            "topbar": {
                "hidden": self.navigation_bar_hidden,
                "title": self.title
            },

            "flex": self.flex,

            "children": subviews,

            "hidden": self.hidden,
            "alpha": self.alpha,
            "opaque": self.opaque,

            "background_color": bg_color,
            "tint_color": tint_color,

            "user_interaction": self.user_interaction_enabled,

            "clips_to_bounds": self.clips_to_bounds,
            "corner_radius": self.corner_radius,
            "border_width": self.border_width,
            "border_color": border_color,

            "content_mode": content_mode,
            "appearance": appearance,

            "button_items": button_items
        }

        for name in dir(self):
            try:
                func = getattr(self.__class__, name)
                if not isinstance(func, property):
                    continue
                func = func.fget

                sig = signature(func)
                if sig.return_annotation.startswith("Callable["):
                    value = getattr(self, name)
                    if callable(value) and "__self__" in dir(value) and value.__self__ == self:
                        d[name] = "self."+value.__name__

            except AttributeError:
                continue
    
        return d

    def _setup_subclass(self):
        _views[self.__py_view__] = weakref.ref(self)

        if callable(self.layout):
            self.__py_view__.layoutAction = _values.value(self.layout)
        
        if callable(self.did_appear):
            self.__py_view__.appearAction = _values.value(self.did_appear)
        
        if callable(self.did_disappear):
            self.__py_view__.disappearAction = _values.value(self.did_disappear)

        if callable(self.key_press_began):
            self.__py_view__.keyPressBegan = _values.value(self.key_press_began)

        if callable(self.key_press_ended):
            self.__py_view__.keyPressEnded = _values.value(self.key_press_ended)

    def __init__(self):
        self.__py_view__ = __PyView__.newView()
        self._setup_subclass()

    def ib_init(self):
        """
        This method is called when the view was initialized from the interface builder.
        PytoUI doesn't call '__init__' when a view is created from the interface builder.
        """
        
        pass

    def _setup_connections(self, connections):
        for connection in connections:
            connection = list(connection)
            
            for view_connection in list(connection[1]):
                attr_name = str(list(view_connection)[0])
                view = __PyView__.view(connection[0])
                if view is None:
                    continue

                if self.__py_view__.managed.containsOrIs(view.managed):
                    func_name = str(list(view_connection)[1])
                    try:
                        func = getattr(self, func_name)
                        if isinstance(func, _IBAction):
                            _view = _wrap_view(view)
                            func._self = self
                            setattr(_view, attr_name, func)
                    except AttributeError:
                        continue
                    
    def __repr__(self):
        return "<"+self.__class__.__module__+"."+self.__class__.__name__+" "+str(self.__py_view__.managed.description)+">"

    def __getitem__(self, item):
        return self.subview_with_name(item)

    def __getattr__(self, name):
        if NSThread.isMainThread:
            return self.__getattribute__(name)

        try:
            return self[name]
        except NameError:
            return self.__getattribute__(name)

    def __del__(self):
        if self.__py_view__ in _views:
            del _views[self.__py_view__]

        try:
            if self.__py_view__.references == 1:
                value = self.__py_view__.managedValue
                identifier = str(value.identifier)
                if identifier in dir(_values):
                    delattr(_values, identifier)
                
                _gc.collected.append(self.__py_view__)
                del self.__py_view__
            elif self.__py_view__ not in _gc.collected:
                self.__py_view__.releaseReference()
                self.__py_view__.release()
        except (AttributeError, ValueError):
            pass

    def __setattr__(self, name, value):
        if name == "__py_view__":
            previous = self.__py_view__
            if previous is not None and previous.references == 1:
                previous.releaseReference()
                previous.release()
            elif previous is not None:
                if previous not in _gc.collected:
                    _gc.collected.append(previous)

            if value is not None:
                value.retainReference()
                if isinstance(self, TableView) or isinstance(self, StackView):
                    value.retain()

        super().__setattr__(name, value)

    @property
    def navigation_view(self) -> NavigationView:
        """
        Returns the :class:`~pyto_ui.NavigationView` containing the receiver view if it exists.

        :rtype: NavigationView
        """
        
        view = self.__py_view__.navigationView
        if view is None:
            return None
        else:
            return _wrap_view(view)

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
        if self.navigation_view:
            self.navigation_view.close()

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
    def center(self) -> Point:
        """
        The center point of the view's frame rectangle. Setting this value updates ``frame`` property appropiately.
        This value is a tuple with X and Y coordinates.

        :rtype: Point
        """

        return Point(self.center_x, self.center_y)

    @center.setter
    def center(self, new_value: Point):
        self.center_x, self.center_y = new_value

    @property
    def size(self) -> Size:
        """
        A size that specifies the height and width of the rectangle.
        This value is a tuple with height and width values.

        :rtype: Size
        """

        return Size(self.width, self.height)

    @size.setter
    def size(self, new_value: Size):
        self.width, self.height = new_value

    @property
    def origin(self) -> Point:
        """
        A point that specifies the coordinates of the view's rectangle’s origin.
        This value is a tuple with X and Y coordinates.

        :rtype: Point
        """

        return Point(self.x, self.y)

    @origin.setter
    def origin(self, new_value: Point):
        self.x, self.y = new_value

    @property
    def frame(self) -> Rect:
        """
        The frame rectangle, which describes the view’s location and size in its superview’s coordinate system.
        This value is a tuple with X, Y, Width and Height values.

        :rtype: Rect
        """

        return Rect(self.x, self.y, self.width, self.height)

    @frame.setter
    def frame(self, new_value: Rect):
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
    def flex(self) -> AutoResizing:
        """
        A list that determines how the receiver resizes itself when its superview’s bounds change. See `Auto Resizing <constants.html#auto-resizing>`_ constants for possible values.

        :rtype: List[`Auto Resizing <constants.html#auto-resizing>`_]
        """

        a = AutoResizing(0)

        if self.__flexible_width__:
            a = a | AutoResizing.FLEXIBLE_WIDTH

        if self.__flexible_height__:
            a = a | AutoResizing.FLEXIBLE_HEIGHT

        if self.__flexible_bottom_margin__:
            a = a | AutoResizing.FLEXIBLE_BOTTOM_MARGIN

        if self.__flexible_top_margin__:
            a = a | AutoResizing.FLEXIBLE_TOP_MARGIN

        if self.__flexible_left_margin__:
            a = a | AutoResizing.FLEXIBLE_LEFT_MARGIN

        if self.__flexible_right_margin__:
            a = a | AutoResizing.FLEXIBLE_RIGHT_MARGIN

        return a

    @flex.setter
    def flex(self, new_value: AutoResizing):
        if isinstance(new_value, list) or isinstance(new_value, tuple):
            flags = new_value
        else:
            flags = [flag for flag in AutoResizing if flag in new_value]

        (
            self.__flexible_width__,
            self.__flexible_height__,
            self.__flexible_top_margin__,
            self.__flexible_bottom_margin__,
            self.__flexible_left_margin__,
            self.__flexible_right_margin__,
        ) = (
            (AutoResizing.FLEXIBLE_WIDTH in flags),
            (AutoResizing.FLEXIBLE_HEIGHT in flags),
            (AutoResizing.FLEXIBLE_TOP_MARGIN in flags),
            (AutoResizing.FLEXIBLE_BOTTOM_MARGIN in flags),
            (AutoResizing.FLEXIBLE_LEFT_MARGIN in flags),
            (AutoResizing.FLEXIBLE_RIGHT_MARGIN in flags),
        )

    _subviews = None

    def subview_with_name(self, name) -> View:
        """
        Returns the subview with the given name. This function search through all of the subviews recursively.

        Raises ``NameError`` if no view is found.

        :rtype: View
        """

        if name == "left_button_items" or name == "right_button_items":
            raise NameError

        if self._subviews is None:
            self._subviews = {}

        try:
            view = self._subviews[name]
            return view
        except KeyError:
            pass

        def search_in_view(subview: View):

            items = subview.left_button_items + subview.right_button_items
            for item in items:
                view = item._get_custom_view()
                if view is None:
                    continue
                if view.name == name:
                    return view

            for view in subview.subviews:
                if str(view.name) == name:
                    return view

            for view in subview.subviews:
                result = search_in_view(view)
                if result is not None:
                    return result
        
        view = search_in_view(self)

        if view is not None:
            self._subviews[name] = view
            return view

        raise NameError(f"No subview named '{name}'")

    @property
    def subviews(self) -> Tuple[View]:
        """
        (Read Only) A tuple of the view's children.

        See also :func:`~pyto_ui.View.add_subview`.

        :rtype: Tuple[View]
        """

        views = self.__py_view__.subviews
        if views is None or len(views) == 0:
            return ()
        else:
            _views = []
            for view in views:
                _view = _wrap_view(view)
                _views.append(_view)
            return tuple(_views)

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
            view = _wrap_view(superview)
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

    _set_tint_color = False

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
            self._set_tint_color = False
        else:
            self.__py_view__.tintColor = new_value.__py_color__
            self._set_tint_color = True

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
    def content_mode(self) -> ContentMode:
        """
        A flag used to determine how a view lays out its content when its bounds change.
        See `Content Mode` <constants.html#content-mode>`_ constants for possible values.

        :rtype: `Content Mode` <constants.html#content-mode>`_
        """

        return self.__py_view__.contentMode

    @content_mode.setter
    def content_mode(self, new_value: ContentMode):
        self.__py_view__.contentMode = new_value

    @property
    def appearance(self) -> Appearance:
        """
        The appearance of the view.
        See `Appearance <constants.html#appearance>`_ constants for possible values.

        :rtype: `Appearance <constants.html#appearance>`_
        """

        return Appearance(self.__py_view__.appearance)

    _set_appearance = False

    @appearance.setter
    def appearance(self, new_value: Appearance):
        
        self._set_appearance = (new_value != Appearance.UNSPECIFIED)

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

    def insert_subview_below(self, view: View, below_view: View):
        """
        Inserts the given view to the receiver's hierarchy bellow another given view.

        :param view: The view to insert.
        :param below_view: The view above the inserted view.
        """

        self.__py_view__.insertSubview(view.__py_view__, below=below_view.__py_view__)

    def insert_subview_above(self, view: View, above_view: View):
        """
        Inserts the given view to the receiver's hierarchy above another given view.

        :param view: The view to insert.
        :param above_view: The view below the inserted view.
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
                _recognizer = GestureRecognizer(GestureType.TAP)
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
    def key_press_began(self) -> Callable[[View, Key], None]:
        """
        Called when a physical keyboard key is pressed.
        The view needs to be the first responder to listen to this event.
        Call :meth:`~pyto_ui.View.become_first_responder` if needed.

        :rtype: Callable[[View, Key], None]
        """

        action = self.__py_view__.keyPressBegan
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @key_press_began.setter
    def key_press_began(self, new_value: Callable[[View, Key], None]):
        self.__py_view__.keyPressBegan = _values.value(self)
        if new_value is None:
            self.__py_view__.keyPressBegan = None
        else:
            self.__py_view__.keyPressBegan = _values.value(new_value)

    @property
    def key_press_ended(self) -> Callable[[View, Key], None]:
        """
        Called after a physical keyboard key is pressed.
        The view needs to be the first responder to listen to this event.
        Call :meth:`~pyto_ui.View.become_first_responder` if needed.
        
        :rtype: Callable[[View, Key], None]
        """

        action = self.__py_view__.keyPressBegan
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @key_press_ended.setter
    def key_press_ended(self, new_value: Callable[[View, Key], None]):
        self.__py_view__.keyPressEnded = _values.value(self)
        if new_value is None:
            self.__py_view__.keyPressEnded = None
        else:
            self.__py_view__.keyPressEnded = _values.value(new_value)

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
    def left_button_items(self) -> Tuple[ButtonItem]:
        """
        A tuple of :class:`~pyto_ui.ButtonItem` objects to be displayed on the left of the top bar if the view is in a navigation view.

        :rtype: List[ButtonItem]
        """

        items = self.__py_view__.leftButtonItems
        if items is None or len(items) == 0:
            return ()
        else:
            _items = []
            for item in items:
                _item = ButtonItem()
                _item.__py_item__ = item
                _items.append(_item)
            return tuple(_items)

    @left_button_items.setter
    def left_button_items(self, new_value: Tuple[ButtonItem]):
        items = []
        if new_value is not None and len(new_value) > 0:
            for item in new_value:
                items.append(item.__py_item__)
        self.__py_view__.leftButtonItems = item
    
    @property
    def right_button_items(self) -> Tuple[ButtonItem]:
        """
        A tuple of :class:`~pyto_ui.ButtonItem` objects to be displayed on the right of the top bar if the view is in a navigation view.

        :rtype: List[ButtonItem]
        """

        items = self.__py_view__.rightButtonItems
        if items is None or len(items) == 0:
            return ()
        else:
            _items = []
            for item in items:
                _item = ButtonItem()
                _item.__py_item__ = item
                _items.append(_item)
            return tuple(_items)

    @right_button_items.setter
    def right_button_items(self, new_value: Tuple[ButtonItem]):
        items = []
        if new_value is not None and len(new_value) > 0:
            for item in new_value:
                items.append(item.__py_item__)
        self.__py_view__.rightButtonItems = items
    

    @property
    def menu(self) -> Menu:
        """
        A context menu to be displayed when long pressing the view.

        :rtype: Menu
        """

        menu = self.__py_view__.menuValue
        if menu is None:
            return None
        else:
            return getattr(_values, str(menu.identifier))
    
    @menu.setter
    def menu(self, new_value: Menu):
        if new_value is None:
            self.__py_view__.menuValue = None
            self.__py_view__.setMenu(None)
        else:
            self.__py_view__.menuValue = _values.value(new_value)
            self.__py_view__.setMenu(new_value.__py_element__)


class NavigationView(View):
    """
    A container view that defines a stack-based scheme for navigating hierarchical content.
    """

    def __init__(self, root_view: View = None):
        if root_view is None:
            view = None
        else:
            view = root_view.__py_view__
        
        self.__py_view__ = __PyNavigationView__.newViewWithRootView(view)

    def push(self, view: View):
        """
        Adds a view to the stack.
        """
        
        if isinstance(view, _InterfaceBuilderNavigationView) and view.root_view is not None:
            if view.root_view.title is None or view.root_view.title == "":
                view.root_view.title = view.title
            view = view.root_view

        self.__py_view__.pushView(view.__py_view__)
    
    def pop(self):
        """
        Removes the last view from the stack.
        """
        
        self.__py_view__.pop()

    def pop_to_root(self):
        """
        Removes all views from the stack after the first one.
        """

        self.__py_view__.popToRootViewController()
    
    @property
    def views(self) -> Tuple[View]:
        """
        Returns the view currently in the stack by order.

        :rtype: Tuple[View]
        """
        
        _views = []
        for view in list(self.__py_view__.views):
            _view = _wrap_view(view)
            _views.append(_view)

        return tuple(_views)

    
    @property
    def root_view(self) -> View:
        """
        Returns the first view or None.

        :rtype: Tuple[View]
        """
        
        try:
            return self.views[0]
        except IndexError:
            return None

    @property
    def navigation_bar_hidden(self) -> bool:
        """
        Property indicating wether the navigation bar is hidden.

        :rtype: bool
        """
        
        return self.__py_view__.navigationBarHidden
    
    @navigation_bar_hidden.setter
    def navigation_bar_hidden(self, new_value: bool):
        self.__py_view__.navigationBarHidden = new_value


class _InterfaceBuilderNavigationView(NavigationView):

    @mainthread
    def _save_root_view(self, vc):
        self._root_view = vc.view

    def __init__(self, root_view_controller: "UIViewController"):
        self.__py_view__ = __PyNavigationView__.newViewWithRootViewController(root_view_controller)
        self._save_root_view(root_view_controller)
        self._setup_subclass()

    def subview_with_name(self, name) -> View:
        try:
            return super().subview_with_name(name)
        except NameError:
            return self.views[-1].subview_with_name(name)


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
        self._setup_subclass()


class ScrollView(View):
    """
    A view that allows the scrolling of its contained views.
    """

    _content_view = None

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)

        try:
            dictionary = dictionary["ScrollView"]
        except KeyError:
            return
        
        content = get("content")

        if content is not None:
            self.content_width = get("width", content)
            self.content_height = get("height", content)

            view = get("view", content)
            if view is not None:
                if isinstance(view, View):
                    view = view.dictionary_representation()
                self.content_view._parent = self
                self.content_view.configure_from_dictionary(view)
        
        self.horizontal = get("horizontal", default=False)
        self.vertical = get("vertical", default=False)

    def dictionary_representation(self):
        d = super().dictionary_representation()

        scroll_view = {
            "content": {
                "width": self.content_width,
                "height": self.content_height,
                "view": self.content_view.dictionary_representation()
            },

            "vertical": self.vertical,
            "horizontal": self.horizontal
        }

        d["ScrollView"] = scroll_view

        return d

    @property
    def content_width(self) -> float:
        """
        The horizontal size of the content. The value is used to calculate when the scroll view should stop scrolling horizontally.

        The default value is ``None``, which means the content width will be equal to the width size of the Scroll View.

        :rtype: float
        """

        return self.__py_view__.contentWidth

    @content_width.setter
    def content_width(self, new_value: float):
        self.__py_view__.contentWidth = new_value

    @property
    def content_height(self) -> float:
        """
        The vertical size of the content. The value is used to calculate when the scroll view should stop scrolling vertically.

        The default value is ``None``, which means the content height will be equal to the height size of the Scroll View.

        :rtype: float
        """

        return self.__py_view__.contentHeight

    @content_height.setter
    def content_height(self, new_value: float):
        self.__py_view__.contentHeight = new_value

    @property
    def vertical(self) -> bool:
        """
        A boolean indicating whether the user can scroll vertically.

        The default value is ``False``.

        :rtype: bool
        """

        return self.__py_view__.vertical

    @vertical.setter
    def vertical(self, new_value: bool):
        self.__py_view__.vertical = new_value

    @property
    def horizontal(self) -> bool:
        """
        A boolean indicating whether the user can scroll horizontally.

        The default value is ``True``.

        :rtype: bool
        """

        return self.__py_view__.horizontal

    @horizontal.setter
    def horizontal(self, new_value: bool):
        self.__py_view__.horizontal = new_value

    @property
    def content_view(self) -> View:
        """
        (Read Only) This view is the content of the Scroll View.

        You should add subviewss there instead of adding them directy to the Scroll View.
        """

        if self._content_view is not None:
            return self._content_view
        else:
            view = View.__new__(View)
            view.__py_view__ = self.__py_view__.content
            view._setup_subclass()
            self._content_view = view
            return view

    def __init__(self):
        self.__py_view__ = __PyScrollView__.newView()
        self._setup_subclass()

    def add_subview(self, view):
        super().add_subview(view)

        msg = "Adding a subview to a ScrollView doesn't add it to the scrollable area. See 'ScrollView.content_view'."
        warnings.warn(msg, UserWarning)


class _StackSpacerView(View):

    def __init__(self):
        self.__py_view__ = __PyStackSpacerView__.newView()
        self._setup_subclass()


class _StackIBSpacerView(View):
    pass


class _StackIBDividerView(View):
    pass


class StackView(View):
    """
    A view that arranges its children in a horizontal or vertical line.

    This is a base class for :class:`~pyto_ui.HorizontalStackView` and :class:`~pyto_ui.VerticalStackView`. You should use one of them instead of :class:`~pyto_ui.StackView`.
    """

    def __init__(self):
        raise NotImplementedError("Cannot initialize a 'StackView'. Use 'HorizontalStackView' or 'VerticalStackView'.")

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["StackView"]
        except KeyError:
            return

        if "padding" in dictionary and dictionary["padding"] is not None:
            padding = dictionary["padding"]
            self.padding = Padding(padding[0], padding[1], padding[2], padding[3])

    def dictionary_representation(self):
        d = super().dictionary_representation()

        stack_view = {
            "padding": [self.padding.top, self.padding.bottom, self.padding.left, self.padding.right]
        }

        d["StackView"] = stack_view
        return d

    def add_spacer(self):
        """
        Adds a flexible space.
        """

        self.add_subview(_StackSpacerView())
    
    def insert_spacer(self, index: int):
        """
        Inserts a flexible space at the given index.

        :param index: The index where the view should be inserted.
        """

        self.insert_subview(_StackSpacerView(), index)
    
    def insert_spacer_before(self, before_view):
        """
        Inserts a flexible space at the given index.

        :param before_view: The view placed after the spacer.
        """

        self.insert_subview_below(_StackSpacerView(), before_view)

    def insert_spacer_after(self, after_view):
        """
        Inserts a flexible space at the given index.

        :param after_view: The view placed before the spacer.
        """

        self.insert_subview_below(_StackSpacerView(), after_view)


class HorizontalStackView(StackView):
    """
    A view that arranges its children in a horizontal line.
    """

    def __init__(self):
        self.__py_view__ = __PyStackView__.horizontal()
        self._setup_subclass()


class VerticalStackView(StackView):
    """
    A view that arranges its children in a vertical line.
    """

    def __init__(self):
        self.__py_view__ = __PyStackView__.vertical()
        self._setup_subclass()


class ImageView(View):
    """
    A view displaying an image.

    :param image: A PIL image.
    :param symbol_name: An SF symbol name. See `sf_symbols <sf_symbols.html>`_
    :param url: The URL of an image to load it remotely.
    """

    def __init__(self, image: "Image" = None, symbol_name: str = None, url: str = None):
        self.__py_view__ = __PyImageView__.newView()
        self._setup_subclass()
        self.image = image
        self._symbol_name = None
        self._url = None
        if url is not None:
            self.load_from_url(url)
            self._url = url
        elif symbol_name is not None:
            self.image = image_with_system_name(symbol_name)
            self._symbol_name = symbol_name

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["ImageView"]
        except KeyError:
            return

        if "url" in dictionary and isinstance(dictionary["url"], str):
            self.load_from_url(dictionary["url"])
        elif "symbol" in dictionary and isinstance(dictionary["symbol"], str):
            self.image = image_with_system_name(dictionary["symbol"])
        elif "path" in dictionary and isinstance(dictionary["path"], str):
            self.image = Image.open(dictionary["path"])

    def dictionary_representation(self):
        r = super().dictionary_representation()
        image_view = {}

        if self._url is not None:
            image_view["url"] = self._url
        elif self._symbol_name is not None:
            image_view["symbol"] = self._symbol_name
        elif self.image is not None and self.image.filename is not None:
            image_view["path"] = self.image.filename

        r["ImageView"] = image_view

        return r

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
        self._setup_subclass()
        self.text = text
        self._html = None

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)
        
        try:
            dictionary = dictionary["Label"]
        except KeyError:
            return

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)

        self.text = get("text", default="")
        html = get("html")

        if html is not None:
            self.load_html(html)

        font = get("font")
        if font is not None:
            font_obj = Font.__new__(Font)
            font_obj.configure_from_dictionary(font)
            self.font = font_obj
        
        alignment = get("alignment")
        if alignment is not None:
            self.text_alignment = getattr(TextAlignment, alignment)

        line_break_mode = get("line_break_mode")
        if line_break_mode is not None:
            self.line_break_mode = getattr(LineBreakMode, line_break_mode)

        self.number_of_lines = get("number_of_lines", default=1)
        self.adjusts_font_size_to_fit_width = get("adjusts_font_size_to_fit_width", default=False)

    def dictionary_representation(self):
        r = super().dictionary_representation()
        label = {}

        label["text"] = self.text

        if self._html is not None:
            label["html"] = self._html
        
        if self.text_color is not None:
            label["color"] = self.text_color.dictionary_representation()
        
        if self.font is not None:
            label["font"] = self.font.dictionary_representation()
        
        label["alignment"] = self.text_alignment.name
        label["line_break_mode"] = self.line_break_mode.name

        label["adjusts_font_size_to_fit_width"] = self.adjusts_font_size_to_fit_width
        label["number_of_lines"] = self.number_of_lines

        r["Label"] = label
        return r

    def load_html(self, html):
        """
        Loads HTML in the Label.

        :param html: The HTML code to load.
        """

        self._html = html
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
    def text_alignment(self) -> TextAlignment:
        """
        The text's alignment. For possible values, see `Text Alignment <constants.html#text-alignment>`_ constants.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return TextAlignment(self.__py_view__.textAlignment)

    @text_alignment.setter
    def text_alignment(self, new_value: TextAlignment):
        self.__py_view__.textAlignment = new_value

    @property
    def line_break_mode(self) -> LineBreakMode:
        """
        The line break mode.

        :rtype: `Line Break Mode <constants.html#line-break-mode>`_
        """

        return LineBreakMode(self.__py_view__.lineBreakMode)

    @line_break_mode.setter
    def line_break_mode(self, new_value: LineBreakMode):
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

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["TableViewCell"]
        except KeyError:
            return

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)

        self.movable, self.removable = get("movable", default=False), get("removable", default=False)

        if get("content") is not None:
            content = get("content")
            if isinstance(content, View):
                content = content.dictionary_representation()
            self.content_view.configure_from_dictionary(content)

        if get("image") is not None and self.image_view is not None:
            image = get("image")
            if isinstance(image, View):
                image = image.dictionary_representation()
            self.image_view.configure_from_dictionary(image)

        if get("label") is not None and self.text_label is not None:
            label = get("label")
            if isinstance(label, View):
                label = label.dictionary_representation()
            self.text_label.configure_from_dictionary(label)

        if get("detail_label") is not None and self.detail_text_label is not None:
            detºail_label = get("detail_label")
            if isinstance(detail_label, View):
                detail_label = label.dictionary_representation()
            self.detail_text_label.configure_from_dictionary(detail_label)

        accessory_type = get("accessory_type")
        if accessory_type is not None:
            self.accessory_type = getattr(AccessoryType, accessory_type)

    def dictionary_representation(self):
        r = super().dictionary_representation()

        table_view_cell = {
            "movable": self.movable,
            "removable": self.removable,
            "content": self.content_view.dictionary_representation(),
        }

        if self.image_view is not None:
            table_view_cell["image"] = self.image_view.dictionary_representation()

        if self.text_label is not None:
            table_view_cell["label"] = self.text_label.dictionary_representation()

        if self.detail_text_label is not None:
            table_view_cell["detail_label"] = self.detail_text_label.dictionary_representation()

        table_view_cell["accessory_type"] = self.accessory_type.name

        r["TableViewCell"] = table_view_cell
        return r

    def __init__(
        self, style: TableViewCellStyle = TableViewCellStyle.SUBTITLE, text: str = None, detail: str = None, image: "Image" = None
    ):
        self.__py_view__ = __PyTableViewCell__.newViewWithStyle(style)
        self.__py_view__.managedValue = _values.value(self)
        self._setup_subclass()

        if text is not None:
            self.text_label.text = text
        
        if detail is not None:
            self.detail_text_label.text = detail

        if image is not None:
            self.image_view.image = image

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

    _content_view = None

    @property
    def content_view(self) -> View:
        """
        (Read Only) The view contained in the cell. Custom views should be added inside it.

        :rtype: View
        """
        
        if self._content_view is not None:
            return self._content_view
        
        _view = View()
        _view.__py_view__ = self.__py_view__.contentView
        self._content_view = _view
        _view.__py_view__.retainReference()
        _view.__py_view__.retain()
        return _view

    _image_view = None

    @property
    def image_view(self) -> ImageView:
        """
        (Read Only) The view containing an image. May return ``None`` for some `Table View Cell Style <constants.html#table-view-cell-style>`_ values.

        :rtype: Image View
        """

        if self._image_view is not None:
            return self._image_view

        view = self.__py_view__.imageView
        if view is None:
            return None
        else:
            _view = _wrap_view(view)
            self._image_view = _view
            view.retainReference()
            return _view

    _text_label = None

    @property
    def text_label(self) -> Label:
        """
        (Read Only) The label containing the main text of the cell.

        :rtype: Label
        """

        if self._text_label is not None:
            return self._text_label

        view = self.__py_view__.textLabel
        if view is None:
            return None
        else:
            _view = _wrap_view(view)
            self._text_label = _view
            view.retainReference()
            view.retain()
            return _view

    _detail_text_label = None

    @property
    def detail_text_label(self) -> Label:
        """
        (Read Only) The label containing secondary text. May return ``None`` for some `Table View Cell Style <constants.html#table-view-cell-style>`_ values.

        :rtype: Label
        """

        if self._detail_text_label is not None:
            return self._detail_text_label

        view = self.__py_view__.detailLabel
        if view is None:
            return None
        else:
            _view = _wrap_view(view)
            self._detail_text_label = _view
            view.retainReference()
            view.retain()
            return _view

    @property
    def accessory_type(self) -> AccessoryType:
        """
        The type of accessory view placed to the right of the cell. See `Accessory Type <constants.html#accessory_type>`_ constants for possible values.

        :rtype: `Accessory Type <constants.html#accessory_type>`_.
        """

        return AccessoryType(self.__py_view__.accessoryType)

    @accessory_type.setter
    def accessory_type(self, new_value: AccessoryType):
        self.__py_view__.accessoryType = new_value


class TableView(View):
    """
    A view containing a list of cells.

    A Table View has a list of :class:`TableViewSection` objects that represent groups of cells. A Table View has two possible styles. See `Table View Style <constants.html#table-view-style>`_.
    """

    def dictionary_representation(self):
        d = super().dictionary_representation()

        sections = []

        for section in self.sections:
            sections.append(section.dictionary_representation())

        d["TableView"] = {
            "sections": sections
        }
        return d

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["TableView"]
        except KeyError:
            return
        
        if "sections" in dictionary and dictionary["sections"] is not None:
            sections = []
            for section in dictionary["sections"]:
                _section = TableViewSection()
                _section._parent = self._parent
                _section.configure_from_dictionary(section)
                sections.append(_section)

            self.sections = sections

    def _setup_subclass(self):
        super()._setup_subclass()

        if callable(self.did_select_cell):
            self.__py_view__.didSelectCell = _values.value(self.layout)
        
        if callable(self.did_tap_cell_accessory_button):
            self.__py_view__.accessoryButtonTapped = _values.value(self.did_tap_cell_accessory_button)
        
        if callable(self.did_delete_cell):
            self.__py_view__.didDeleteCell = _values.value(self.did_delete_cell)

        if callable(self.did_move_cell):
            self.__py_view__.didMoveCell = _values.value(self.did_move_cell)

    def __init__(
        self,
        style: TableViewStyle = TableViewStyle.INSET_GROUPED,
        sections: List[TableViewSection] = [],
    ):
        self.__py_view__ = __PyTableView__.newViewWithStyle(style)
        self.__py_view__.managedValue = _values.value(self)
        self.sections = sections
        self._setup_subclass()

    def set_cells(self, cells: List[TableViewCell] | Tuple[TableViewCell] | TableViewCell):
        """
        Fills the Table View with the given cells.

        :param cells: The cells to display.
        """
        
        if isinstance(cells, TableViewCell):
            cells = (cells,)
        
        self.sections = [TableViewSection(cells=cells)]

    @property
    def reload_action(self) -> Callable[[TableView], None]:
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

    @property
    def did_select_cell(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when a cell contained in the table view is selected. Takes the section and the selected cell's index as parameters.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_view__.didSelectCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_select_cell.setter
    def did_select_cell(self, new_value: Callable[[TableViewSection, int], None]):
        if new_value is None:
            self.__py_view__.didSelectCell = None
        else:
            self.__py_view__.didSelectCell = _values.value(new_value)

    @property
    def did_tap_cell_accessory_button(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when the accessory button of a cell contained in the table view is pressed. Takes the section and the cell's index as parameters.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_view__.accessoryButtonTapped
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_tap_cell_accessory_button.setter
    def did_tap_cell_accessory_button(
        self, new_value: Callable[[TableViewSection, int], None]
    ):
        if new_value is None:
            self.__py_view__.accessoryButtonTapped = None
        else:
            self.__py_view__.accessoryButtonTapped = _values.value(new_value)

    @property
    def did_delete_cell(self) -> Callable[[TableViewSection, int], None]:
        """
        A function called when a cell contained in the table view is deleted. Takes the section and the selected deleted cell's index as parameters.
        This function should be used to remove the data corresponding to the cell from the database.

        :rtype: Callable[[TableViewSection, int], None]
        """

        action = self.__py_view__.didDeleteCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_delete_cell.setter
    def did_delete_cell(self, new_value: Callable[[TableViewSection, int], None]):
        if new_value is None:
            self.__py_view__.didDeleteCell = None
        else:
            self.__py_view__.didDeleteCell = _values.value(new_value)

    @property
    def did_move_cell(self) -> Callable[[TableViewSection, int, int], None]:
        """
        A function called when a cell contained in the table view is moved. Takes the section, the moved deleted cell's index and the destination index as parameters.
        This function should be used to move the data corresponding to the cell from the database.

        :rtype: Callable[[TableViewSection, int, int], None]
        """

        action = self.__py_view__.didMoveCell
        if action is None:
            return None
        else:
            return getattr(_values, str(action.identifier))

    @did_move_cell.setter
    def did_move_cell(self, new_value: Callable[[TableViewSection, int, int], None]):
        if new_value is None:
            self.__py_view__.didMoveCell = None
        else:
            self.__py_view__.didMoveCell = _values.value(new_value)


class TextView(View):
    """
    An editable, multiline and scrollable view containing text.
    """

    def __init__(self, text=""):
        self.__py_view__ = __PyTextView__.newView()
        self.__py_view__.managedValue = _values.value(self)
        self.text = text
        self._setup_subclass()

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["TextView"]
        except KeyError:
            return
        
        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)
        
        self.selected_range = tuple(get("selected_range", default=[]))
        self.text = get("text", default="")
        self.editable = get("editable", default=True)
        self.selectable = get("selectable", default=True)
        self.smart_quotes = get("smart_quotes", default=True)
        self.smart_dashes = get("smart_dashes", default=True)
        self.autocorrection = get("autocorrection", default=True)
        self.secure = get("secure", default=False)

        if get("html") is not None:
            self.load_html(get("html"))
        
        if get("color") is not None:
            color = Color.__new__(Color)
            color.configure_from_dictionary(get("color"))
            self.text_color = color

        if get("font") is not None:
            font = Font.__new__(Font)
            font.configure_from_dictionary(get("font"))
            self.font = font

        text_alignment = get("text_alignment")
        if text_alignment is not None:
            self.text_alignment = getattr(TextAlignment, text_alignment)
        
        keyboard_type = get("keyboard_type")
        if keyboard_type is not None:
            self.keyboard_type = getattr(KeyboardType, keyboard_type)
        
        keyboard_appearance = get("keyboard_appearance")
        if keyboard_appearance is not None:
            self.keyboard_appearance = getattr(KeyboardAppearance, keyboard_appearance)

        autocapitalization_type = get("autocapitalization_type")
        if autocapitalization_type is not None:
            self.autocapitalization_type = getattr(AutoCapitalization, autocapitalization_type)
        
        return_key_type = get("return_key_type")
        if return_key_type is not None:
            self.return_key_type = getattr(ReturnKeyType, return_key_type)

    def dictionary_representation(self):
        r = super().dictionary_representation()

        text_view = {
            "selected_range": self.selected_range,
            "text": self.text,
            "editable": self.editable,
            "selectable": self.selectable,
            "smart_quotes": self.smart_quotes,
            "smart_dashes": self.smart_dashes,
            "autocorrection": self.autocorrection,
            "secure": self.secure
        }

        if self._html is not None:
            text_view["html"] = self._html
        
        if self.text_color is not None:
            text_view["color"] = self.text_color.dictionary_representation()
        
        if self.font is not None:
            text_view["font"] = self.font.dictionary_representation()
        
        text_view["alignment"] = self.text_alignment.name        
        text_view["keyboard_type"] = self.keyboard_type.name
        text_view["keyboard_appearance"] = self.keyboard_appearance.name
        text_view["autocapitalization_type"] = self.autocapitalization_type.name
        text_view["return_key_type"] = self.return_key_type.name

        r["TextView"] = text_view
        return r

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

    _html = None

    def load_html(self, html):
        """
        Loads HTML in the Text View.

        :param html: The HTML code to load.
        """

        self._html = html
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
    def text_alignment(self) -> TextAlignment:
        """
        The alignment of the text displayed on screen. See `Text Alignment <constants.html#text-alignment>`_ constants for possible values.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return TextAlignment(self.__py_view__.textAlignment)

    @text_alignment.setter
    def text_alignment(self, new_value: TextAlignment):
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
    def keyboard_type(self) -> KeyboardType:
        """
        The type of keyboard to use while editing the text. See `Keyboard Type <constants.html#keyboard-type>`_ constants for possible values.

        :rtype: `Keyboard Type <constants.html#keyboard-type>`_
        """

        return KeyboardType(self.__py_view__.keyboardType)

    @keyboard_type.setter
    def keyboard_type(self, new_value: KeyboardType):
        self.__py_view__.keyboardType = new_value

    @property
    def autocapitalization_type(self) -> AutoCapitalization:
        """
        The type of autocapitalization to use while editing th text. See `Auto Capitalization <constants.html#auto-capitalization>`_ constants for possible values.

        :rtype: `Auto Capitalization <constants.html#auto-capitalization>`_
        """

        return AutoCapitalization(self.__py_view__.autocapitalizationType)

    @autocapitalization_type.setter
    def autocapitalization_type(self, new_value: AutoCapitalization):
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
    def keyboard_appearance(self) -> KeyboardAppearance:
        """
        The appearance of the keyboard used while editing the text. See `Keyboard Appearance <constants.html#keyboard-appearance>`_ constants for possible values.

        :rtype: `Keyboard Appearance <constants.html#keyboard-appearance>`_
        """

        return KeyboardAppearance(self.__py_view__.keyboardAppearance)

    @keyboard_appearance.setter
    def keyboard_appearance(self, new_value: KeyboardAppearance):
        self.__py_view__.keyboardAppearance = new_value

    @property
    def return_key_type(self) -> ReturnKeyType:
        """
        The type of return key to show on the keyboard used to edit the text. See `Return Key Type <constants.html#return-key-type>`_ constants for possible values.

        :rtype: `Return Key Type <constants.html#return-key-type>`_
        """

        return ReturnKeyType(self.__py_view__.returnKeyType)

    @return_key_type.setter
    def return_key_type(self, new_value: ReturnKeyType):
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


# MARK: - Web view

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

        def configure_from_dictionary(self, dictionary):
            super().configure_from_dictionary(dictionary)

            try:
                dictionary = dictionary["WebView"]
            except KeyError:
                return

            if "html" in dictionary and dictionary["html"] is not None:

                try:
                    base_url = dictionary["base_url"]
                except KeyError:
                    base_url = None

                self.load_html(dictionary["html"], base_url=base_url)
            elif "url" in dictionary and dictionary["url"] is not None:
                self.load_url(dictionary["url"])

        def dictionary_representation(self):
            r = super().dictionary_representation()

            web_view = {}

            if self._url is not None:
                web_view["url"] = self._url
            elif self._html is not None:
                web_view["html"] = self._html
                web_view["base_url"] = self._base_url

            r["WebView"] = web_view
            return r

        def __init__(self, url: str = None):
            self.__py_view__ = __PyWebView__.newView()
            self._setup_subclass()
            self.__py_view__.managedValue = _values.value(self)

            if url is not None:
                self.load_url(url)

        def _setup_subclass(self):
            super()._setup_subclass()

            if callable(self.did_finish_loading):
                self.__py_view__.didFinishLoading = _values.value(self.did_finish_loading)
        
            if callable(self.did_fail_loading):
                self.__py_view__.didFailLoading = _values.value(self.did_fail_loading)
        
            if callable(self.did_start_loading):
                self.__py_view__.didStartLoading = _values.value(self.did_start_loading)

            if callable(self.did_receive_message):
                self.__py_view__.didReceiveMessage = _values.value(self.did_receive_message)

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

        _url = None

        def load_url(self, url: str):
            """
            Loads an URL.

            :param url: The URL to laod. Can be 'http://', 'https://' or 'file://'.
            """

            self._url = url
            self.__py_view__.loadURL(url)

        def load_file_path(self, path: str):
            """
            Loads a file.

            :param path: The path of the file to load.
            """

            url = str(NSURL.alloc().initFileURLWithPath(os.path.abspath(path)).absoluteString)
            self._url = url
            self.__py_view__.loadURL(url)

        _html = None

        _base_url = None

        def load_html(self, html: str, base_url: str = None):
            """
            Loads an HTML string.

            :param html: The HTML code to load.
            :param base_url: An optional URL used to resolve relative paths.
            """

            baseURL = base_url
            if baseURL is not None:
                baseURL = str(base_url)

            self._html = html
            self._base_url = base_url
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

        def register_message_handler(self, name: str):
            """
            Adds a script message handler.

            Adding a script message handler with name name causes the JavaScript function ``window.webkit.messageHandlers.name.postMessage(messageBody)`` to be defined in all frames in all web views that use the user content controller.

            :param name: The name of the message handler.
            """

            self.__py_view__.registerMessageHandler(name)

        @property
        def did_receive_message(self) -> Callable[[WebView, str, object], None]:
            """
            A function called when a script message is received from a webpage.
            Takes the sender Web View, the name of the message and the content of the message as parameters.

            The following example script shows how to send a message from a JavaScript page and how to receive it from the Web View.

            .. highlight:: python
            .. code-block:: python

                import pyto_ui as ui

                def did_receive_message(web_view, name, message):
                    print(name, message)

                web_view = ui.WebView()
                web_view.did_receive_message = did_receive_message
                web_view.register_message_handler("webView")

                web_view.load_html('''

                <h1> Hello World </h1>

                <script>
                    window.webkit.messageHandlers.webView.postMessage({foo:"bar"})
                </script>

                ''')

                ui.show_view(web_view, ui.PRESENTATION_MODE_SHEET)

            :rtype: Callable[[WebView, str, object], None]
            """

            action = self.__py_view__.didReceiveMessage
            if action is None:
                return None
            else:
                return getattr(_values, str(action.identifier))

        @did_receive_message.setter
        def did_receive_message(self, new_value: Callable[[WebView, str, object], None]):
            if new_value is None:
                self.__py_view__.didReceiveMessage = None
            else:
                self.__py_view__.didReceiveMessage = _values.value(new_value)

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
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)

        try:
            dictionary = dictionary["Control"]
        except KeyError:
            return
        
        if "enabled" in dictionary and dictionary["enabled"] is not None:
            self.enabled = dictionary["enabled"]
        
        horizontal_alignment = get("horizontal_alignment")
        if horizontal_alignment is not None:
            self.horizontal_alignment = getattr(HorizontalAlignment, horizontal_alignment)

        vertical_alignment = get("vertical_alignment")
        if vertical_alignment is not None:
            self.vertical_alignment = getattr(VerticalAlignment, vertical_alignment)

    def dictionary_representation(self):
        r = super().dictionary_representation()
        
        control = {
            "enabled": self.enabled
        }

        control["horizontal_alignment"] = self.horizontal_alignment.name
        control["vertical_alignment"] = self.vertical_alignment.name
        
        r["Control"] = control
        return r

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
    def horizontal_alignment(self) -> HorizontalAlignment:
        """
        The horizontal alignment of the view's contents. See `Horizontal Alignment <constants.html#horizontal-alignment>`_ constants for possible values.

        :rtype: `Horizontal Alignment <constants.html#horizontal-alignment>`_
        """

        return HorizontalAlignment(self.__py_view__.contentHorizontalAlignment)

    @horizontal_alignment.setter
    def horizontal_alignment(self, new_value: HorizontalAlignment):
        self.__py_view__.contentHorizontalAlignment = new_value

    @property
    def vertical_alignment(self) -> VerticalAlignment:
        """
        The vertical alignment of the view's contents. See `Vertical Alignemnt <constants.html#vertical-alignment>`_ constants for possible values.

        :rtype: `Vertical Alignment <constants.html#vertical-alignment>`_
        """

        return VerticalAlignment(self.__py_view__.contentVerticalAlignment)

    @vertical_alignment.setter
    def vertical_alignment(self, new_value: VerticalAlignment):
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
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)
        self.segments = segments

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["SegmentedControl"]
        except KeyError:
            return

        if "segments" in dictionary and dictionary["segments"] is not None:
            self.segments = dictionary["segments"]

        if "selection" in dictionary and dictionary["selection"] is not None:
            self.selected_segment = dictionary["selection"]

    def dictionary_representation(self):
        r = super().dictionary_representation()

        segmented_control = {
            "segments": self.segments,
            "selection": self.selected_segment
        }

        r["SegmentedControl"] = segmented_control
        return r

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
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)
        self.value = value

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary()

        try:
            dictionary = dictionary["Slider"]
        except KeyError:
            return
        
        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)
        
        self.value = get("value", default=0)
        self.minimum_value = get("min", default=0)
        self.maximum_value = get("max", default=1)

        if get("thumb_color") is not None:
            thumb_color = Color.__new__(Color)
            thumb_color.configure_from_dictionary(get("thumb_color"))
            self.thumb_color = thumb_color
        
        if get("maximum_track_color") is not None:
            maximum_track_color = Color.__new__(Color)
            maximum_track_color.configure_from_dictionary(get("maximum_track_color"))
            self.maximum_track_color = maximum_track_color

        if get("minimum_track_color") is not None:
            minimum_track_color = Color.__new__(Color)
            minimum_track_color.configure_from_dictionary(get("minimum_track_color"))
            self.minimum_track_color = minimum_track_color

    def dictionary_representation(self):
        r = super().dictionary_representation()

        slider = {
            "value": self.value,
            "min": self.minimum_value,
            "max": self.maximum_value
        }

        if self.thumb_color is not None:
            slider["thumb_color"] = self.thumb_color.dictionary_representation()
        
        if self.maximum_track_color is not None:
            slider["maximum_track_color"] = self.maximum_track_color.dictionary_representation()

        if self.minimum_track_color is not None:
            slider["minimum_track_color"] = self.minimum_track_color.dictionary_representation()

        r["Slider"] = slider
        return r

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


class Stepper(Control):
    """
    A control for incrementing or decrementing a value.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the switch changes its value.
    """

    def __init__(self, minimum_value: float = 0, maximum_value: float = 100):
        self.__py_view__ = __PyStepper__.newView()
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)
        self.minimum_value = minimum_value
        self.maximum_value = maximum_value
    
    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["Stepper"]
        except KeyError:
            return
        
        if "minimum_value" in dictionary and dictionary["minimum_value"] is not None:
            self.minimum_value = dictionary["minimum_value"]

        if "maximum_value" in dictionary and dictionary["maximum_value"] is not None:
            self.maximum_value = dictionary["maximum_value"]

        if "step_value" in dictionary and dictionary["step_value"] is not None:
            self.step_value = dictionary["step_value"]

        if "value" in dictionary and dictionary["value"] is not None:
            self.value = dictionary["value"]

    def dictionary_representation(self):
        r = super().dictionary_representation()

        stepper = {}

        stepper["minimum_value"] = self.minimum_value
        stepper["maximum_value"] = self.maximum_value
        stepper["step_value"] = self.step_value
        stepper["value"] = self.value

        r["Stepper"] = stepper

        return r

    @property
    def value(self) -> float:
        """
        The numeric value of the stepper.

        :rtype: float
        """

        return float(self.__py_view__.value)

    @value.setter
    def value(self, new_value: float):
        self.__py_view__.value = new_value

    @property
    def minimum_value(self) -> float:
        """
        The lowest possible numeric value for the stepper.

        :rtype: float
        """

        return float(self.__py_view__.minimumValue)

    @minimum_value.setter
    def minimum_value(self, new_value: float):
        self.__py_view__.minimumValue = new_value

    @property
    def maximum_value(self) -> float:
        """
        The highest possible numeric value for the stepper.

        :rtype: float
        """

        return float(self.__py_view__.maximumValue)

    @maximum_value.setter
    def maximum_value(self, new_value: float):
        self.__py_view__.maximumValue = new_value

    @property
    def step_value(self) -> float:
        """
        The step, or increment, value for the stepper.

        :rtype: float
        """

        return float(self.__py_view__.stepValue)

    @step_value.setter
    def step_value(self, new_value: float):
        self.__py_view__.stepValue = new_value


class Switch(Control):
    """
    A control that offers a binary choice, such as On/Off.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the switch changes its value.
    """

    def __init__(self, on=False):
        self.__py_view__ = __PySwitch__.newView()
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)
        self.on = on

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["Switch"]
        except KeyError:
            return
        
        if "on" in dictionary and dictionary["on"] is not None:
            self.on = dictionary["on"]
        
        if "on_color" in dictionary and dictionary["on_color"] is not None:
            on_color = Color.__new__(Color)
            on_color.configure_from_dictionary(dictionary["on_color"])
            self.on_color = on_color
        
        if "thumb_color" in dictionary and dictionary["thumb_color"] is not None:
            thumb_color = Color.__new__(Color)
            thumb_color.configure_from_dictionary(dictionary["thumb_color"])
            self.thumb_color = thumb_color

    def dictionary_representation(self):
        r = super().dictionary_representation()

        switch = {}

        switch["on"] = self.on

        if self.on_color is not None:
            switch["on_color"] = self.on_color.dictionary_representation()
        
        if self.thumb_color is not None:
            switch["thumb_color"] = self.thumb_color.dictionary_representation()

        r["Switch"] = switch

        return r

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

    _button_type = None

    def __init__(
        self,
        type: ButtonType = __v__("SYSTEM"),
        title: str = "",
        image: "Image" = None,
    ):
        if type == "SYSTEM":
            self.__py_view__ = __PyButton__.newButtonWithType(ButtonType.SYSTEM)
            self._button_type = type
        else:
            self.__py_view__ = __PyButton__.newButtonWithType(type)
        self.__py_view__.managedValue = _values.value(self)
        self.title = title
        self.image = image
        self._setup_subclass()

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["Button"]
        except KeyError:
            return

        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)
        
        button_type = get("type")
        if button_type is not None:
            self._button_type = getattr(ButtonType, button_type)
            self.__py_view__ = __PyButton__.newButtonWithType(self._button_type)
            self._setup_subclass()

        self.title = get("title")

        if get("color") is not None:
            title_color = Color.__new__(Color)
            title_color.configure_from_dictionary(get("color"))
            self.title_color = title_color
        
        if get("font") is not None:
            font = Font.__new__(Font)
            font.configure_from_dictionary(get("font"))
            self.font = font
        
        if get("image") is not None:
            if os.path.isfile(get("image")):
                self.image = Image.open(get("image"))
            else:
                self.image = image_with_system_name(get("image"))

    def dictionary_representation(self):
        r = super().dictionary_representation()

        button = {
            "title": self.title
        }

        if self.title_color is not None:
            button["color"] = self.title_color.dictionary_representation()
        
        if self.font is not None:
            button["font"] = self.font.dictionary_representation()

        if self.image is not None and isinstance(self.image, Image.Image):
            button["image"] = self.image.filename

        button["type"] = self._button_type.name

        r["Button"] = button
        return r

    def _setup_subclass(self):
        super()._setup_subclass()

        if callable(self.action):
            self.__py_view__.action = _values.value(self.action)

    @property
    def title(self) -> str:
        """
        The title of the button.

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
    def subtitle(self) -> str:
        """
        The subtitle of the button.

        :rtype: str
        """

        subtitle = self.__py_view__.subtitle
        if subtitle is not None:
            return str(subtitle)
        else:
            return None

    @title.setter
    def subtitle(self, new_value: str):
        self.__py_view__.subtitle = new_value

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

    _image = None

    @image.setter
    def image(self, new_value: "Image"):
        if new_value is None:
            self.__py_view__.image = None
            self._image = None
        elif "objc_class" in dir(new_value) and new_value.objc_class == UIImage:
            self.__py_view__.image = new_value
        else:
            self._image = new_value
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

    @property
    def menu_primary_action(self) -> bool:
        """
        Show the context menu attached to the button as the primary action.
        Default is False. See :meth:`~pyto_ui.View.menu`.

        :rtype: bool
        """
        return self.__py_view__.showsMenuAsPrimaryAction
    
    @menu_primary_action.setter
    def menu_primary_action(self, new_value: bool):
        self.__py_view__.showsMenuAsPrimaryAction = new_value


class TextField(Control):
    """
    A field to type single line text.
    The function passed to :data:`~pyto_ui.Control.action` will be called when the text field changes its text.
    """

    def __init__(self, text: str = "", placeholder: str = None):
        self.__py_view__ = __PyTextField__.newView()
        self._setup_subclass()
        self.__py_view__.managedValue = _values.value(self)
        self.text = text
        self.placeholder = placeholder
        
    def _setup_subclass(self):
        super()._setup_subclass()

        if callable(self.did_begin_editing):
            self.__py_view__.didBeginEditing = _values.value(self.did_begin_editing)
            
        if callable(self.did_end_editing):
            self.__py_view__.didEndEditing = _values.value(self.did_end_editing)

    def configure_from_dictionary(self, dictionary):
        super().configure_from_dictionary(dictionary)

        try:
            dictionary = dictionary["TextView"]
        except KeyError:
            return
        
        def get(key, _dict=dictionary, default=None):
            return self._get(key, _dict, default)
        
        self.placeholder = tuple(get("placeholder", default=""))
        self.text = get("text", default="")
        self.smart_quotes = get("smart_quotes", default=True)
        self.smart_dashes = get("smart_dashes", default=True)
        self.autocorrection = get("autocorrection", default=True)
        self.secure = get("secure", default=False)

        if get("color") is not None:
            color = Color.__new__(Color)
            color.configure_from_dictionary(get("color"))
            self.text_color = color

        if get("font") is not None:
            font = Font.__new__(Font)
            font.configure_from_dictionary(get("font"))
            self.font = font

        text_alignment = get("text_alignment")
        if text_alignment is not None:
            self.text_alignment = getattr(TextAlignment, text_alignment)
        
        keyboard_type = get("keyboard_type")
        if keyboard_type is not None:
            self.keyboard_type = getattr(KeyboardType, keyboard_type)
        
        keyboard_appearance = get("keyboard_appearance")
        if keyboard_appearance is not None:
            self.keyboard_appearance = getattr(KeyboardAppearance, keyboard_appearance)

        autocapitalization_type = get("autocapitalization_type")
        if autocapitalization_type is not None:
            self.autocapitalization_type = getattr(AutoCapitalization, autocapitalization_type)
        
        return_key_type = get("return_key_type")
        if return_key_type is not None:
            self.return_key_type = getattr(ReturnKeyType, return_key_type)
        
        border_style = get("border_style")
        if border_style is not None:
            self.border_style = getattr(TextFieldBorderStyle, border_style)

    def dictionary_representation(self):
        r = super().dictionary_representation()

        text_field = {
            "text": self.text,
            "placeholder": self.placeholder,
            "smart_quotes": self.smart_quotes,
            "smart_dashes": self.smart_dashes,
            "autocorrection": self.autocorrection,
            "secure": self.secure
        }

        text_field["keyboard_type"] = self.keyboard_type.name
        text_field["keyboard_appearance"] = self.keyboard_appearance.name
        text_field["autocapitalization_type"] = self.autocapitalization_type.name
        text_field["return_key_type"] = self.return_key_type.name
        text_field["border_style"] = self.border_style.name
        text_field["alignment"] = self.text_alignment.name

        if self.text_color is not None:
            text_field["color"] = self.text_color.dictionary_representation()
        
        if self.font is not None:
            text_field["font"] = self.font.dictionary_representation()

        r["TextField"] = text_field
        return r

    @property
    def border_style(self) -> TextFieldBorderStyle:
        """
        The border style of the Text Field.

        :rtype: TEXT_FIELD_BORDER_STYLE
        """

        return TextFieldBorderStyle(self.__py_view__.borderStyle)

    @border_style.setter
    def border_style(self, new_value: TextFieldBorderStyle):
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
    def text_alignment(self) -> TextAlignment:
        """
        The alignment of the text displayed on screen. See `Text Alignment <constants.html#text-alignment>`_ constants for possible values.

        :rtype: `Text Alignment <constants.html#text-alignment>`_
        """

        return TextAlignment(self.__py_view__.textAlignment)

    @text_alignment.setter
    def text_alignment(self, new_value: TextAlignment):
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
    def keyboard_type(self) -> KeyboardType:
        """
        The type of keyboard to use while editing the text. See `Keyboard Type <constants.html#keyboard-type>`_ constants for possible values.

        :rtype: `Keyboard Type <constants.html#keyboard-type>`_
        """

        return KeyboardType(self.__py_view__.keyboardType)

    @keyboard_type.setter
    def keyboard_type(self, new_value: KeyboardType):
        self.__py_view__.keyboardType = new_value

    @property
    def autocapitalization_type(self) -> AutoCapitalization:
        """
        The type of autocapitalization to use while editing th text. See `Auto Capitalization <constants.html#auto-capitalization>`_ constants for possible values.

        :rtype: `Auto Capitalization <constants.html#auto-capitalization>`_
        """

        return AutoCapitalization(self.__py_view__.autocapitalizationType)

    @autocapitalization_type.setter
    def autocapitalization_type(self, new_value: AutoCapitalization):
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
    def keyboard_appearance(self) -> KeyboardAppearance:
        """
        The appearance of the keyboard used while editing the text. See `Keyboard Appearance <constants.html#keyboard-appearance>`_ constants for possible values.

        :rtype: `Keyboard Appearance <constants.html#keyboard-appearance>`_
        """

        return KeyboardAppearance(self.__py_view__.keyboardAppearance)

    @keyboard_appearance.setter
    def keyboard_appearance(self, new_value: KeyboardAppearance):
        self.__py_view__.keyboardAppearance = new_value

    @property
    def return_key_type(self) -> ReturnKeyType:
        """
        The type of return key to show on the keyboard used to edit the text. See `Return Key Type <constants.html#return-key-type>`_ constants for possible values.

        :rtype: `Return Key Type <constants.html#return-key-type>`_
        """

        return ReturnKeyType(self.__py_view__.returnKeyType)

    @return_key_type.setter
    def return_key_type(self, new_value: ReturnKeyType):
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


##################
# MARK: - Serialization
##################

def _from_json(obj):
    if "class" in obj and isinstance(obj["class"], str):
        full_class_name = obj["class"]
        if "." in full_class_name:
            parts = full_class_name.split(".")
            class_name = parts[-1]
            del parts[-1]
            module = ".".join(parts)
                
            klass = getattr(sys.modules[module], class_name)
        else:
            try:
                klass = getattr(sys.modules["__main__"], full_class_name)
            except AttributeError:
                klass = globals()[full_class_name]
        
        if klass is None:
            klass = eval(full_class_name)

        view = klass.__new__(klass)
        view.configure_from_dictionary(obj)
        return view
    else:
        return obj

class Encoder(json.JSONEncoder):

    def default(self, o):
        return o.dictionary_representation()

class Decoder(json.JSONDecoder):

    def __init__(self):
        super().__init__(object_hook=_from_json)

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


def _wrap_view(view: __PyView__) -> View:

    if view in _views:
        _view = _views[view]()
        if _view is not None:
            return _view
    
    view.retain()
    view.retainReference()

    if view in _cls:
        instance = _cls[view].__new__(_cls[view])
        instance.__py_view__ = view
        instance._setup_subclass()
        return instance

    try:
        ui = sys.modules["pyto_ui"]
    except KeyError:
        import pyto_ui as ui

    try:
        _class = getattr(ui, str(view.objc_class.pythonName))
    except AttributeError:
        _class = View
                
    _view = _class.__new__(_class)
    _view.__py_view__ = view

    return _view


_ib_types_map = {
    "UIView": (View, __PyView__),
    "InterfaceBuilderButton": (Button, __PyButton__),
    "UILabel": (Label, __PyLabel__),
    "UISlider": (Slider, __PySlider__),
    "UISwitch": (Switch, __PySwitch__),
    "UIStepper": (Stepper, __PyStepper__),
    "UITextField": (TextField, __PyTextField__),
    "StackViewContainer": (StackView, __PyIBStackView__),
    "StackViewSpacer": (_StackIBSpacerView, __PyView__),
    "StackViewDivider": (_StackIBDividerView, __PyView__),
    "InterfaceBuilderImageView": (ImageView, __PyImageView__),
    "InterfaceBuilderSegmentedControl": (SegmentedControl, __PySegmentedControl__),
    "UITextView": (TextView, __PyTextView__),
    "UITableView": (TableView, __PyTableView__),
    "UILayoutContainerView": (NavigationView, _InterfaceBuilderNavigationView),
}

def _create_subviews(view, _globals):

    cls_name = view.objc_class.name.split(".")[-1]
    try:
        cls = _ib_types_map[cls_name]
        py_cls = cls[0]
        objc_cls = cls[1]

        objc_view = objc_cls.alloc().initWithManaged(view)
        objc_view.retain()
        objc_view.retainReference()

        if objc_view.customClassName is not None:
            cls_name = str(objc_view.customClassName)

            err_msg = f"No class named '{cls_name}'. Use either just the name of the class if it's in the global namespace, or '<module name>.<class name>' (the module has to be imported and in sys.modules)."

            try:
                py_cls = eval(cls_name, _globals)
            except (NameError, AttributeError):
                comp = cls_name.split(".")
                if len(comp) < 2:
                    raise NameError(err_msg)

                cls_name = comp.pop(-1)
                mod_name = ".".join(comp)

                try:
                    mod = __import__(mod_name, _globals).__dict__
                except ModuleNotFoundError:
                    raise NameError(err_msg)

                py_cls = eval(cls_name, mod)

        py_view = py_cls.__new__(py_cls)
        py_view.__py_view__ = objc_view
        py_view._setup_subclass()
    except KeyError:
        py_view = View.__new__(View)
        py_view.__py_view__ = __PyView__.alloc().initWithManaged(view)
        py_view._setup_subclass()
    
    try:
        py_view.__py_view__.managedValue
        py_view.__py_view__.managedValue = _values.value(py_view)
    except AttributeError:
        pass

    _cls[py_view.__py_view__] = type(py_view)

    if view.objc_class.name.split(".")[-1] == "StackViewContainer":
        objc_subviews = view.getSubviews()
    else:
        objc_subviews = view.subviews()
    
    for subview in list(objc_subviews):
        _create_subviews(subview, _globals)

    py_view._setup_connections(_globals["_pytoui_interfacebuilder_connections"])
    threading.Thread(target=py_view.ib_init, args=()).start()
    

def _get_uikit_view(view):
    if isinstance(view, _InterfaceBuilderNavigationView):
        view = getattr(view, "_root_view")
    else:
        view = view.__py_view_.managed
    
    return view


class ib_ref(View):
    """
    A reference to a view from the interface builder. When :func:`~pyto_ui.read` is called, every instance of this class found in globals will be replaced by the view named like the variable referencing the instance.

    For example:

    .. highlight:: python
    .. code-block:: python
    
       continue_btn = ui.ib_ref()
       view = ui.read("my_view.pytoui", globals())
       
       (continue_btn is view["continue_btn"]) == True
    """
    
    def __new__(cls):
        _locals = inspect.stack()[1][0].f_locals
        try:
            root = _locals["_pytoui_interfacebuilder_view"]
            frame = inspect.stack()[1][0]
            code = frame.f_code
            offset = 0
            for (_offset, lineno) in dis.findlinestarts(code):
                if lineno == frame.f_lineno:
                    offset = _offset
                    break
            
            bytecode = dis.Bytecode(code)
            view = None
            for instr in bytecode:
                if instr.opname == "STORE_NAME" and instr.offset >= offset:
                    view = root[instr.argval]
                    break

            if view is None:
                raise NameError("No view was found")
            return view
        except KeyError:
            return super().__new__(cls)


class _IBAction:

    def __init__(self, action, _self=None):
        self.action = action
        self._self = _self

    def __getattr__(self, name):
        return getattr(self.action, name)

    def __call__(self, *args, **kwargs):
        if self._self is not None:
            return self.action(self._self, *args, **kwargs)
        else:
            return self.action(*args, **kwargs)
    
    def __get__(self, instance, instancetype):
        return _IBAction(self.action, instance)
   

def ib_action(action):
    _locals = inspect.stack()[1][0].f_locals
    try:
        connections = _locals["_pytoui_interfacebuilder_connections"]

        frame = inspect.stack()[1][0]
        code = frame.f_code
        offset = 0
        for (_offset, lineno) in dis.findlinestarts(code):
            if lineno == frame.f_lineno:
                offset = _offset
                break
            
        bytecode = dis.Bytecode(code)
        connection_name = None
        found_code = False
        for instr in bytecode:

            if instr.offset < offset:
                continue

            if not found_code: # The first argvals are the arguments, after that there's the code, and then the function's name
                if isinstance(instr.argval, type(ib_action.__code__)):
                    found_code = True
                continue

            if instr.opname == "LOAD_CONST" and isinstance(instr.argval, str):
                connection_name = instr.argval
                break

        for connection in connections:
            connection = list(connection)
            
            for view_connection in list(connection[1]):
                attr_name = str(list(view_connection)[0])
                if str(list(view_connection)[1]) == connection_name:

                    view = __PyView__.view(connection[0])
                    _view = _wrap_view(view)

                    setattr(_view, attr_name, action)

        return action
    except KeyError:
        return _IBAction(action)


def read(path: str, _globals: dict = None) -> NavigationView:
    """
    Creates a view from the given ".pytoui" file path.

    :param path: The path of the file.
    :_globals: A globals object to resolve the Interface Builder connections. If no value is provided, the locals from the caller will be used.

    :rtype: View
    """

    if _globals is None:
        _globals = inspect.stack()[1][0].f_globals

    ret = __PyView__.readFromPath(os.path.abspath(path))
    if ret is None:

        errorType = str(__PyView__.lastErrorType)
        msg = str(__PyView__.lastError)
        
        if errorType == "fileNotFound":
            raise FileNotFoundError(msg)
        else:
            raise IOError(msg)
    
    vc = list(ret)[0]
    original_nav_vc = list(ret)[1]
    connections = list(ret)[2]
    button_items = list(list(ret)[3])

    nav_vc = _InterfaceBuilderNavigationView(vc)
    __PyView__.copyAttributesWithSourceNavVC(original_nav_vc, destNavVC=nav_vc.__py_view__)

    _globals["_pytoui_interfacebuilder_view"] = nav_vc
    _globals["_pytoui_interfacebuilder_connections"] = connections

    for item in button_items:
        mainthread(_create_subviews)(item, _globals)
    
    mainthread(_create_subviews)(_get_uikit_view(nav_vc), _globals)

    for var in dict(_globals):
        if var == "":
            continue

        if isinstance(_globals[var], ib_ref):
            _globals[var] = nav_vc[var]

    for connection in connections:
        connection = list(connection)
        view = __PyView__.view(connection[0])
        _view = _wrap_view(view)

        for view_connection in list(connection[1]):
            try:
                setattr(_view, str(list(view_connection)[0]), _globals[str(list(view_connection)[1])])
            except KeyError:
                pass

    return nav_vc


def show_view_without_waiting(view: View, mode: PresentationMode):
    """
    Shows a PytoUI :class:`~pyto_ui.View`.

    Use this function to show a view on a plugin running in background. That will show the view on any screen of the app on the key window.
    Also, this function returns before the view is closed, so that's also useful for running code after showing the view.

    :param view: The :class:`~pyto_ui.View` object to present.
    :param mode: The presentation mode to use. The value will be ignored on a widget. See `Presentation Mode <constants.html#presentation-mode>`_ constants for possible values.
    """

    def showview():
        show_view(view, mode)

    threading.Thread(target=showview).start()


def cast(view: View, cls: Type[TypeVar("View", bound=View)]) -> View:
    """
    Returns a view casted to the given type. It is unsafe to use the return value unless you are sure about the casted view type.

    Using this should genreally not be necessary, as PytoUI casts views automatically.
    But sometimes, PytoUI may fail to automatically cast UIKit views to their corresponding Python class. If that's the case, you should use this function to cast it yourself.
    
    A cast to a type that doesn't correspond to the view's type won't result in an exception or a crash unless you use properties or functions exclusive to that type.
    For example, you may write a function that can take both Labels and TextViews. They both have similar properties, like 'text´ or 'text_color'.
    Sure it would be simplier to just use 'setattr' or 'getattr' to use these properties, but you could also technically cast a TextView into a Label and successfully access its 'text' attribute.
    That works because Python is a weak typed language so it will just look for the 'text' `property of the Objective-C object.

    :param view: The PytoUI view to cast.
    :param cls: The new class.

    :rtype: View
    """
    
    new_view = cls.__new__(cls)
    pyto_ui_view_type = __PyView__

    for obj in globals().items():
        if hasattr(obj, "pythonName"):
            name = str(obj.pythonName)
            if name == cls.name:
                pyto_ui_view_type = obj
                break
    
    new_view.__py_view__ = pyto_ui_view_type.alloc().initWithManaged(view.__py_view__.managed)
    return new_view
    


def show_view(view: View, mode: PresentationMode = None):
    """
    Presents the given view.

    This function doesn't return until the view is closed. You can use another thread to perform background tasks and modify the UI after it's presented.

    On iPad, if the view has a custom size, it will be used for the presentation.

    :param view: The :class:`~pyto_ui.View` object to present.
    :param mode: The presentation mode to use. The default value is 'SHEET'. See `Presentation Mode <constants.html#presentation-mode>`_ constants for possible values.
    """

    if mode is None:
        mode = PresentationMode.SHEET

    check(view, "view", [View])
    check(mode, "mode", [PresentationMode])

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


# MARK: - Toga

if is_sphinx:

    iOSBox = object

    class toga:

        class Box:
            pass


class _PytoBox(iOSBox):
    
    def __init__(self, view, interface):
        self.pyto_view = view
        super().__init__(interface=interface)
    
    def create(self):
        self.native = self.pyto_view.__py_view__.managed
        
        # Add the layout constraints
        self.add_constraints()


class TogaWidget(toga.Box):
    """
    A Toga Widget created from a PytoUI view.
    Pass a :class:`~pyto_ui.View` as the first parameter of the initializer.
    """
    
    def __init__(self, view: View, id=None, style=None, children=None, factory=None):
        super().__init__(id=id, style=style, factory=factory)

        self._children = []
        if children:
            self.add(*children)

        # Create a platform specific implementation of a Box
        self._impl = _PytoBox(view=view, interface=self)


# MARK: - Deprecated constants

_deprecated_constants_path = os.path.join(os.path.abspath(os.path.dirname(__file__)), "pyto_ui_deprecated_constants.json")

with open(_deprecated_constants_path) as f:
    _deprecated_constants = json.load(f)

_pyto_ui = sys.modules[__name__]

class PytoUI(ModuleType):

    def __getattribute__(self, name):

        if name in _deprecated_constants:
            msg = f"'{name}' was renamed to '{_deprecated_constants[name]}'."
            warnings.warn(
                msg, DeprecationWarning
            )
            return eval(_deprecated_constants[name], _pyto_ui.__dict__)

        try:
            return getattr(_pyto_ui, name)
        except (KeyError, AttributeError):
            return super().__getattribute__(name)
    
    def __setattr__(self, name, value):
        setattr(_pyto_ui, name, value)

sys.modules[__name__] = PytoUI(__name__)
