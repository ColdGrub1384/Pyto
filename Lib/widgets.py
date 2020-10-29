"""
Home Screen Widgets

Since iOS / iPadOS 14, multiple widgets from the same app can be displayed in the home screen. That changed the way widgets work.
Before iOS 14, widgets were dynamic which means that a script's output could be displayed at real time and views were interactive. 
However, that changed. Now widgets are not really interactive. The UI cannot be changed after being presented. That means a widget now provides a static UI multiple times a day.

Individual UI elements can open the script in foreground except on the small layout, where only the whole widget can be pressed.

Scripts can determine when a widget will be reloaded, for example each hour.
While the UI is not interactive, UI elements can open the script in foreground to do a certain task. So coding some kind of launcher is possible.

.. warning::
   This library requires iOS 14+
"""

from __future__ import annotations
from typing import Union, List
from urllib.request import urlopen
from time import sleep
from __check_type__ import check
import os
import datetime
import ui_constants
import sys
import __image__
import threading
from pyto import Python


try:
    if "sphinx" in sys.modules:
        raise ValueError

    from rubicon.objc import ObjCClass, CGFloat
except ValueError:
    def ObjCClass(class_name):
        return None


try:
    from PIL import Image as PIL_Image
except ModuleNotFoundError:
    PIL_Image = None
except ImportError:
    PIL_Image = None


def __Class__(name):
    try:
        return ObjCClass("Pyto."+name)
    except NameError:
        return ObjCClass("WidgetExtension."+name)


UIDevice = ObjCClass("UIDevice")
__UIFont__ = ObjCClass("UIFont")


def wait_for_internet_connection():
    while not __Class__("InternetConnection").isReachable:
        sleep(0.2)


if (
    UIDevice is not None
    and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 14
):
    raise ImportError("Home Screen Widgets were introduced on iPadOS / iOS 14.")


class PytoUIView: # Travis CI doesn't let me mark a parameter as 'ui.View' without importing PytoUI
    pass


try:
    if Python.shared.widgetLink is not None:
        _link = str(Python.shared.widgetLink)
    else:
        _link = None
except AttributeError:
    _link = None


link: str = _link
"""
When an UI element with a ``link`` attribute in a medium or large widget is pressed, the widget script will be opened in foreground and the ``link`` attribute will be passed to this variable.
At the beginning of a widget script, you can check if this variable is ``None``. If it's not, that means an UI element with a ``link`` attribute was pressed.

See :data:`~widgets.WidgetComponent.link`, :meth:`~widgets.WidgetLayout.add_row` and :meth:`~widgets.WidgetLayout.set_link`

:rtype: str
"""


if "console" in sys.modules:
    __widget_id__ = sys.modules["console"].__widget_id__
else:
    __widget_id__ = None


__PyWidget__ = __Class__("PyWidget")
__shown_view__ = False
__PyColor__ = __Class__("PyColor")
try:
    __widget__ = __PyWidget__.alloc().init()
except AttributeError:
    pass

if __PyWidget__ is None and not "sphinx" in sys.modules:
    raise NotImplementedError("Home Screen Widgets are coming on Pyto 13.")


def schedule_next_reload(time: Union[datetime.timedelta, float]):
    """
    Schedules the next reload of the widget.
    The widget may not be reloaded exactly at the provided time, the system will choose when it's appropiate but never before the provided time.

    :param time: The time passed before the widget should reload. A ``datetime.timedelta`` object or the number of seconds.
    """

    check(time, "time", [datetime.timedelta, float, int])

    seconds = 0

    if isinstance(time, datetime.timedelta):
        seconds = time.total_seconds()
    else:
        seconds = time

    __widget__.updateInterval = seconds


def __show_view__(view: PytoUIView, key: str = None):

    widget = __widget__

    widget.view = view.__py_view__

    small = __PyWidget__.sizeForFamily(0)
    medium = __PyWidget__.sizeForFamily(1)
    large = __PyWidget__.sizeForFamily(2)

    for size in [(0, small), (1, medium), (2, large)]:
        view.size = (size[1].width, size[1].height)

        func = view.layout
        if func is not None:
            if func.__code__.co_argcount >= 1:
                func(view)
            else:
                func()

        widget.setSnapshot(size[0])

    if key is None:
        __PyWidget__.updateTimeline(__widget_id__, widget=widget)
    else:
        __PyWidget__.addWidget(widget, key=key)


def show_view(view: PytoUIView):
    """
    Shows the given view on a widget. A snapshot for each widget size will be taken.

    :param view: A view to show in the widget.
    """

    try:
        view.__py_view__
    except AttributeError:
        msg = "The 'view' parameter must be a PytoUI View instance."
        raise TypeError(msg)

    global __shown_view__
    __shown_view__ = True

    __show_view__(view)


def save_snapshot(view: PytoUIView, key: str):
    """
    Saves the snapshot of the given view. The snapshot will be selectable to show in a widget and can be updated in app.

    :param view: A view to show in the widget.
    :param key: The name of the snapshot. When a new snapshot is saved with an existing key, the widget will be updated.
    """

    try:
        view.__py_view__
    except AttributeError:
        msg = "The 'view' parameter must be a PytoUI View instance."
        raise TypeError(msg)

    __show_view__(view, key)


def reload_widgets(names: Union[str, List[str]]):
    """
    Reloads the widgets corresponding to the given scripts names.
    It works only for "Run Script" widgets.

    The names can and can also not contain the ".py" suffix.

    :param names: A string or a list of strings corresponding to the scripts to reload as widgets.
    """

    check(names, "names", [str, list])

    if isinstance(names, str):
        names = [names]
    
    _names = []
    for name in _names:
        if not name.endswith(".py"):
            _names.append(name+".py")
        else:
            _names.append(name)

    __PyWidget__.reloadWidgets(_names)


###############
# MARK: - UI #
##############


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

        :rtype: widgets.Color
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

        :rtype: widgets.Color
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

        :param light: :class:`~widgets.Color` object to be displayed in light mode.
        :param dark: :class:`~widgets.Color` object to be displayed in dark mode.

        :rtype: widgets.Color
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


if "pyto_ui" in sys.modules and "sphinx" not in sys.modules:
    try:
        Color = sys.modules["pyto_ui"].Color
    except AttributeError:
        pass


def __pyto_ui_color__():
    if "pyto_ui" in sys.modules:
        try:
            return sys.modules["pyto_ui"].Color
        except AttributeError:
            return None
    else:
        return None


# Font Size

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

# Font Text Style

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

# Color

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

# Date Style

DATE_STYLE = "DATE_STYLE"

DATE_STYLE_DATE = 0
"""
A style displaying a date.
"""

DATE_STYLE_OFFSET = 1
"""
A style displaying a date as offset from now.
"""

DATE_STYLE_RELATIVE = 2
"""
A style displaying a date as relative to now.
"""

DATE_STYLE_TIME = 3
"""
A style displaying only the time component for a date.
"""

DATE_STYLE_TIMER = 4
"""
A style displaying a date as timer counting from now.
"""

# Padding

PADDING = "PADDING"

PADDING_NONE = 0
"""
No padding around an UI element.
"""

PADDING_ALL = 1
"""
Padding everywhere around an UI element.
"""

PADDING_VERTICAL = 2
"""
Vertical padding around an UI element.
"""

PADDING_HORIZONTAL = 3
"""
Horizontal padding around an UI element.
"""


class Padding:
    """
    Padding with custom values. Use `constants <constants.html#padding>`_ for using the system defined padding.
    """

    top: float = None
    """ Top padding """

    bottom: float = None
    """ Bottom padding """

    left: float = None
    """ Left padding """

    right: float = None
    """ Right padding """

    def __init__(self, top: float = None, bottom: float = None, left: float = None, right: float = None):
        self.top = top
        self.bottom = bottom
        self.left = left
        self.right = right


def __set_padding__(padding, component):
    if isinstance(padding, Padding):
        component.padding = 4
        component.customPadding.top = padding.top
        component.customPadding.bottom = padding.bottom
        component.customPadding.left = padding.left
        component.customPadding.right = padding.right
    else:
        component.padding = padding


class WidgetComponent:
    """
    An abstract class that represents an UI element displayed in a widget.

    :class:`~widgets.WidgetComponent` attributes can be modified after initialisation, but they can all be set from the initialiser.
    However, changes made to an :class:`~widgets.WidgetComponent` object after being displayed won't take effect.
    """

    background_color: Color = COLOR_CLEAR
    """
    The background color of the element.

    :rtype: widgets.Color
    """

    corner_radius: float = 0
    """
    The radius to use when drawing rounded corners for the view’s background.

    :rtype: float
    """

    padding: Union[PADDING, Padding] = PADDING_NONE
    """
    If set to ``True``, additional blank space around the view will be added.

    See :class:`~widgets.Padding`.

    :rtype: bool
    """

    link: str = None
    """
    A string that will be passed to the widget script when the element is tapped.
    Set this attribute to make the element tappable.

    When an element is tapped, the widget is executed in app and the ``link`` attribute is passed to :data:`~widgets.WidgetComponent.link`.
    The element isn't tappable if this attribute is set to ``None``.

    This attribute doesn't take effect on small widgets.

    :rtype: str
    """

    def __init__(
        self,
        background_color: Color = None,
        corner_radius: float = 0,
        padding: Union[PADDING, Padding] = None,
        link: str = None,
    ):

        check(background_color, "background_color", [Color, __pyto_ui_color__(), None])
        check(corner_radius, "corner_radius", [float, int])
        check(padding, "padding", [int, Padding, None])
        check(link, "link", [str, None])

        if background_color is None:
            self.background_color = COLOR_CLEAR
        else:
            self.background_color = background_color

        self.corner_radius = corner_radius

        if padding is None:
            self.padding = PADDING_NONE
        else:
            self.padding = padding

        self.link = link

    def __make_objc_view__(self):
        return __Class__("WidgetComponent").alloc().init()


class Text(WidgetComponent):
    """
    A widget UI element displaying plain text.
    """

    text: str = None
    """
    The text displayed on screen.

    :rtype: str
    """

    font: Font = None
    """
    The font of the text.

    :rtype: widgets.Font
    """

    color: Color = None
    """
    The foreground color of the text.

    :rtype: widgets.Color
    """

    def __init__(
        self,
        text: str,
        color: Color = None,
        font: Font = None,
        background_color: Color = None,
        corner_radius: float = 0,
        padding: Union[PADDING, Padding] = None,
        link: str = None,
    ):
        super().__init__(background_color, corner_radius, padding, link)

        check(text, "text", [str])
        check(corner_radius, "corner_radius", [float, int])

        self.text = text
        self.color = color

        if font is None:
            self.font = Font.system_font_of_size(FONT_SYSTEM_SIZE)
        else:
            self.font = font

    def __make_objc_view__(self):
        obj = __Class__("WidgetText").alloc().init()
        obj.text = self.text
        
        try:
            obj.color = self.color.__py_color__.managed
        except AttributeError:
            pass

        try:
            obj.backgroundColor = self.background_color.__py_color__.managed
        except AttributeError:
            pass

        obj.font = self.font.__ui_font__
        obj.cornerRadius = self.corner_radius
        __set_padding__(self.padding, obj)
        obj.identifier = self.link
        return obj


class DynamicDate(WidgetComponent):
    """
    A text displaying a date with the correct format.

    As widgets are not dynamic and UI elements aren't modifiable after being displayed, this class can also serve to display timers with a provided date.

    Example:

    .. highlight:: python
    .. code-block:: python

        import widgets as wd
        from datetime import datetime, timedelta

        # A 1 hour timer
        one_hour = datetime.now() + timedelta(hours=1)
        timer = wd.DynamicDate(one_hour, style=wd.DATE_STYLE_TIMER)

        # Formatted date
        today = datetime.today()
        date_text = wd.DynamicDate(today)
    """

    date: Union[datetime.datetime, datetime.date, datetime.time] = None
    """
    The date used to create the text.

    Valid value types:

    - ``datetime.datetime``: A specific date and time.
    - ``datetime.date``: A date without specifying time. The current time will be used.
    - ``datetime.time``: A time without specifying date. The current date will be used.

    :rtype: Union[datetime.datetime, datetime.date, datetime.time]
    """

    style: DATE_STYLE = DATE_STYLE_DATE
    """
    The date style determines how the date should be used to create text.

    See `Date Style <constants.html#date-style>`_

    :rtype: DATE_STYLE_DATE
    """

    font: Font = None
    """
    The font of the text.

    :rtype: widgets.Font
    """

    color: Color = None
    """
    The foreground color of the text.

    :rtype: widgets.Color
    """

    def __init__(
        self,
        date: Union[datetime.datetime, datetime.date, datetime.time],
        style: DATE_STYLE = DATE_STYLE_DATE,
        color: Color = None,
        font=None,
        background_color: Color = None,
        corner_radius: float = 0,
        padding: Union[PADDING, Padding] = None,
        link: str = None,
    ):
        super().__init__(background_color, corner_radius, padding, link)

        check(date, "date", [datetime.datetime, datetime.date, datetime.time])
        check(style, "style", [int])
        check(color, "color", [Color, __pyto_ui_color__(), None])

        self.date = date
        self.style = style
        self.color = color

        if font is None:
            self.font = Font.system_font_of_size(FONT_SYSTEM_SIZE)
        else:
            self.font = font

    def __make_objc_view__(self):

        date = None

        if isinstance(self.date, datetime.datetime):
            date = self.date
        elif isinstance(self.date, datetime.date):
            date = datetime.datetime.combine(
                self.date, datetime.datetime.today().time()
            )
        elif isinstance(self.date, datetime.time):
            date = datetime.datetime.combine(datetime.date.today(), self.date)

        obj = __Class__("WidgetDate").alloc().init()
        obj.setDateWithYear(
            date.year,
            month=date.month,
            day=date.day,
            hour=date.hour,
            minute=date.minute,
            second=date.second,
        )
        obj.style = self.style
        
        try:
            obj.color = self.color.__py_color__.managed
        except AttributeError:
            pass

        try:
            obj.backgroundColor = self.background_color.__py_color__.managed
        except AttributeError:
            pass

        obj.font = self.font.__ui_font__
        obj.cornerRadius = self.corner_radius
        __set_padding__(self.padding, obj)
        obj.identifier = self.link
        return obj


class SystemSymbol(WidgetComponent):
    """
    An UI element displaying a system symbol (SF Symbol).

    Valid symbol names are declared in the `sf_symbols <sf_symbols.html>`_ module.
    """

    symbol_name: str = None
    """
    The SF Symbol name.

    :rtype: str
    """

    color: Color = None
    """
    The foreground color of the symbol.

    :rtype: widgets.Color
    """

    font_size: float = None
    """
    The size in pixels of the symbol.

    :rtype: float
    """

    def __init__(
        self,
        symbol_name: str,
        color: Color = None,
        font_size: float = None,
        background_color: Color = None,
        corner_radius: float = 0,
        padding: Union[PADDING, Padding] = None,
        link: str = None,
    ):
        super().__init__(background_color, corner_radius, padding, link)

        check(symbol_name, "symbol_name", [str])
        check(color, "color", [Color, __pyto_ui_color__(), None])
        check(font_size, "font_size", [float, int, None])

        self.symbol_name = symbol_name
        self.color = color

        self.font_size = font_size

    def __make_objc_view__(self):
        obj = __Class__("WidgetSymbol").alloc().init()
        obj.symbolName = self.symbol_name
        
        try:
            obj.color = self.color.__py_color__.managed
        except AttributeError:
            pass

        try:
            obj.backgroundColor = self.background_color.__py_color__.managed
        except AttributeError:
            pass

        obj.cornerRadius = self.corner_radius

        if self.font_size is not None:
            obj.fontSize = self.font_size

        __set_padding__(self.padding, obj)
        obj.identifier = self.link
        return obj


class Image(WidgetComponent):
    """
    An UI element displaying an image.
    """

    image: PIL_Image.Image = None
    """
    A Pillow image to be displayed.

    :rtype: PIL.Image
    """

    fill: bool = False
    """
    If set to ``True``, the image will fill its container. Otherwise, the image will conserve its own aspect ratio.

    :rtype: bool
    """

    def __init__(
        self,
        image: PIL_Image.Image = None,
        url: str = None,
        fill: bool = False,
        background_color: Color = None,
        corner_radius: float = 0,
        padding: Union[PADDING, Padding] = None,
        link: str = None,
    ):
        super().__init__(background_color, corner_radius, padding, link)

        check(image, "image", [PIL_Image.Image, None])
        check(url, "url", [str, None])

        if url is not None:
            self.image = PIL_Image.open(urlopen(url))
        else:
            self.image = image

    def __make_objc_view__(self):
        obj = __Class__("WidgetImage").alloc().init()
        obj.image = __image__.__ui_image_from_pil_image__(self.image)
        try:
            obj.backgroundColor = self.background_color.__py_color__.managed
        except AttributeError:
            pass
        obj.cornerRadius = self.corner_radius
        __set_padding__(self.padding, obj)
        obj.identifier = self.link
        obj.fill = self.fill
        return obj


class Spacer(WidgetComponent):
    """
    An invisible UI element taking as much as horizontal space as it can.

    Label -- < Spacer> -- Label
    """

    def __init__(self):
        pass


class WidgetLayout:
    """
    The layout of a widget with all its UI elements. A Widget contains 3 layouts: small, medium and large.
    A widget layout is composed of rows, each row containing a list of UI elements.
    """

    def __init__(self):
        try:
            self.__widget_view__ = __Class__("WidgetView").alloc().init()
        except AttributeError:  # Documentation
            pass

    def set_link(self, link: str):
        """
        When a widget is tapped, the widget is executed in app and the ``link`` attribute is passed to data:`~widgets.WidgetComponent.link`.

        Links on entire widgets take effect on small widgets unlike links on UI elements.
        
        :param link: A string that will be passed to the widget script when the widget is tapped.
        """

        check(link, "link", [str, None])

        self.__widget_view__.link = link

    def set_background_color(self, color: Color):
        """
        Sets the background color of the widget layout.

        :param color: A :class:`~widgets.Color` object.
        """

        check(color, "color", [Color, __pyto_ui_color__(), None])

        try:
            self.__widget_view__.backgroundColor = color.__py_color__.managed
        except AttributeError:
            self.__widget_view__.backgroundColor = COLOR_CLEAR

    def set_background_gradient(self, colors: List[Color]):
        """
        Sets the background color of the widget layout to a gradient.
        The gradient is linear and goes from top to bottom and uses the colors passed as a list.

        :param colors: A list of :class:`~widgets.Color` objects for the gradient.
        """

        check(colors, "colors", [list, None])

        if colors is None:
            self.__widget_view__.backgroundGradient = None
        else:
            ui_colors = []
            for color in colors:
                ui_colors.append(color.__py_color__.managed)
            self.__widget_view__.backgroundGradient = ui_colors

    def set_background_image(self, image: Image):
        """
        Sets the background image of the widget layout.

        :param image: An :class:`~widgets.Image` object.
        """

        check(image, "image", [Image, None])

        try:
            image_obj = image.__make_objc_view__()
            image_obj.fill = True
            self.__widget_view__.backgroundImage = image_obj
        except AttributeError:
            self.__widget_view__.backgroundImage = None

    def add_row(
        self,
        row: List[WidgetComponent],
        background_color: Color = None,
        corner_radius: float = 0,
        link: str = None,
    ):
        """
        Adds a row to the widget layout. A row is a list of UI elements on the same horizontal line.

        :param row: A list of UI elements.
        :param background_color: The background color of the row.
        :param corner_radius: The radius to use when drawing rounded corners for the row's background.
        :link: A string that will be passed to the widget script when the row is tapped. This parameter doesn't take effect on small widgets.
        """

        check(row, "row", [list])
        check(background_color, "background_color", [Color, __pyto_ui_color__(), None])
        check(corner_radius, "corner_radius", [float, int])
        check(link, "link", [str, None])

        if background_color is None:
            background_color = COLOR_CLEAR

        objc_row = []

        for element in row:
            obj = element.__make_objc_view__()
            objc_row.append(obj)

        self.__widget_view__.addRow(
            objc_row,
            backgroundColor=background_color.__py_color__.managed,
            cornerRadius=corner_radius,
            identifier=link,
        )

    def add_vertical_spacer(self):
        """
        Adds a row that takes as much as vertical space as possible.
        """

        self.__widget_view__.addSpacer()

    def add_vertical_divider(self, color: Color = None):
        """
        Adds a visual vertical separator.

        :param color: The color of the line.
        """

        check(color, "color", [Color, __pyto_ui_color__(), None])

        _color = None
        try:
            _color = color.__py_color__.managed
        except AttributeError:
            pass

        self.__widget_view__.addDividerWithColor(_color)


class Widget:
    """
    The configuration of a widget, which is a set of different layouts.
    """

    small_layout: WidgetLayout = WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for small sized widgets.
    """

    medium_layout: WidgetLayout = WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for medium sized widgets.
    """

    large_layout: WidgetLayout = WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for large sized widgets.
    """

    def __init__(self):
        self.small_layout = WidgetLayout()
        self.medium_layout = WidgetLayout()
        self.large_layout = WidgetLayout()


def __show_widget__(widget: Widget, key: str):
    _widget = __widget__

    try:
        _widget.scriptPath = threading.current_thread().script_path
    except AttributeError:
        _widget.scriptPath = None

    _widget.addView(widget.small_layout.__widget_view__, family=0)
    _widget.addView(widget.medium_layout.__widget_view__, family=1)
    _widget.addView(widget.large_layout.__widget_view__, family=2)

    if key is None:
        __PyWidget__.updateTimeline(__widget_id__, widget=_widget)
    else:
        __PyWidget__.addWidget(_widget, key=key)


class TimelineProvider:
    """
    A timeline providers allows a script to provide content to a widget for the future.
    
    Pass a subclass of :class:`~widgets.TimelineProvider` to :func:`~widgets.provide_timeline` to provide a timeline of widgets.
    Calling this function in app will just preview the widget and will not have any effect.
    """

    def __reload_time__(self):
        time = self.reload_time()

        seconds = 0

        if isinstance(time, datetime.timedelta):
            seconds = time.total_seconds()
        else:
            seconds = time
        
        return seconds

    def reload_time(self) -> Union[datetime.timedelta, float]:
        """
        Returns the delay after which the widget should reload and run the script again. 
        The return value is the delay between the last timeline entry and the next reload. The system doesn't guarantees the widget to be reloaded at an exact time.

        Supported return types are ``float``s representing seconds or a ``datetime.timedelta`` object.

        :rtype: Union[datetime.timedelta, float]
        """

        return 0

    def widget(self, date: datetime.datetime) -> Widget:
        """
        Returns a widget for the given timestamp.

        :rtype: Widget
        """

        raise NotImplementedError("Implement 'WidgetTimelineProvider' to support timelines.")

    def timeline(self) -> List[datetime.datetime]:
        """
        Returns a list of timestamps for which the script has data.
        Make sure to not provide an exaggerated ammount of dates because the widget can crash due to memory issues.

        :rtype: List[datetime.datetime]
        """

        raise NotImplementedError("Implement 'WidgetTimelineProvider' to support timelines.")


def provide_timeline(provider: TimelineProvider):
    """
    Provides a timeline of widgets for the future.

    :param provider: A :class:`~widgets.TimelineProvider` subclass.
    """

    widgets = []

    dates = provider.timeline()
    for date in dates:
        widget = provider.widget(date)
        py_widget = __PyWidget__.alloc().init()
        py_widget.timelineDateTimestamp = date.timestamp()
        try:
            py_widget.scriptPath = threading.current_thread().script_path
        except AttributeError:
            py_widget.scriptPath = None
        py_widget.addView(widget.small_layout.__widget_view__, family=0)
        py_widget.addView(widget.medium_layout.__widget_view__, family=1)
        py_widget.addView(widget.large_layout.__widget_view__, family=2)
        widgets.append(py_widget)

    __PyWidget__.updateTimeline(__widget_id__, widgets=widgets, reloadAfter=provider.__reload_time__())


def show_widget(widget: Widget):
    """
    Shows a widget with the given configuration

    :param widget: The widget's configuration.
    """

    check(widget, "widget", [Widget])

    __show_widget__(widget, None)


def save_widget(widget: Widget, key: str):
    """
    Saves a widget that will be selectable to show in a widget and can be updated in app.

    :param widget: The widget's configuration.
    :param key: The name of the widget. When a new widget is saved with an existing key, it will be updated.
    """

    check(widget, "widget", [Widget])
    check(key, "key", [str])

    __show_widget__(widget, key)

def delete_in_app_widget(key: str):
    """
    Deletes a widget saved with :func:`~widgets.save_widget` or :func:`~widgets.save_snapshot`.

    :param key: The name of the widget.
    """

    __PyWidget__.removeWidget(key)
