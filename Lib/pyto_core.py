"""
Extend the editor

.. warning::
   This library requires iOS / iPadOS 13.

Run a script at the app's startup and extend the code editor.
"""

from pyto import __Class__
from typing import List, Callable, Union
from UIKit import UIDevice, UIImage
from pyto import EditorViewController, Python
from PIL import Image
from __check_type__ import check
import builtins
import base64
import threading
import traceback
import sys
import pyto_ui as ui


if (
    UIDevice is not None
    and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 13
):
    raise ImportError("PytoCore requires iPadOS / iOS 13")


try:
    del sys.modules["pyto_ui"]
    del sys.modules["ui_constants"]
except KeyError:
    pass


__py_core__ = __Class__("PyCore")


def startup_script():
    """
    Sets the current running script as startup script, so each time Pyto will be launched, this script will be executed in background.
    This function cannot be executed on a subthread.

    Setting the startup script will replace the old one. Only one plugin is supported at time because only one object can be receive editor's events. But nothing stops you from importing other modules.
    """

    script_path = None
    plugin_path = None
    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        pass

    try:
        plugin_path = threading.current_thread().plugin_path
    except AttributeError:
        pass

    if script_path is None:
        __py_core__.startupScript = plugin_path
        return

    def doit():

        alert = ui.Alert(
            "This script wants to be executed at startup",
            "Doing so will replace the previous script.",
        )
        alert.add_destructive_action("Allow")
        alert.add_cancel_action("Cancel")
        if alert.show() == "Cancel":
            return

        __py_core__.startupScript = script_path

    threading.Thread(target=doit).start()


def show_view(view: ui.View, mode: ui.PRESENTATION_MODE):
    """
    Shows a PytoUI :class:`~pyto_ui.View`.

    Use this function to show a view on a plugin running in background. That will show the view on any screen of the app on the key window.
    Also, this function returns before the view is closed, so that's also useful for running code after showing the view.

    :param view: The :class:`~pyto_ui.View` object to present.
    :param mode: The presentation mode to use. The value will be ignored on a widget. See `Presentation Mode <constants.html#presentation-mode>`_ constants for possible values.
    """

    def showview():
        ui.show_view(view, mode)

    threading.Thread(target=showview).start()


# MARK: - Editor


class EditorDelegate:
    """
    An object that receives events from the code editor.
    Override it to implement your plugin.
    """

    def run_script(self, script_path: str, run: Callable[[], None]):
        """
        Called when a script will be executed.

        If the ``run()`` function isn't called, the script will not be executed.

        :param script_path: The path of the script to be executed.
        :param run: Call this function to run the script.
        """

        raise NotImplementedError("Not implemented")

    def did_run_script(self, script_path: str, local: dict, exception: Exception):
        """
        Called when a script finished running.

        :param script_path: The path of the script.
        :param local: The ``__dict__`` attribute of the executed script.
        :param exception: The exception raised by the script. Can be ``None``.
        """

        raise NotImplementedError("Not implemented")

    def editor_button_icon(self, script_path: str) -> Union[Image.Image, UIImage, str]:
        """
        By overriding this method, a new button will be added the the code editor's toolbar.

        From this function, return the icon of this button.

        There are three possible return types:

            - A PIL Image
            - An Objective-C ``UIImage`` object
            - A string with the name of an SF Symbol. `List of SF Symbols <https://sfsymbols.com>`_

        This method receives the path of the script being edited as parameter. If you want to not display a button for specific scripts, raise ``NotImplementedError``.

        :param script_path: The path of the script being edited.

        :rtype: Union[Image.Image, UIImage, str]
        """

        raise NotImplementedError("Not implemented")

    def editor_button_pressed(self, script_path: str):
        """
        If the :func:`~pyto_core.EditorDelegate.editor_button_icon` function is implemented, this method will be called when the button in the toolbar is pressed.

        :param script_path: The path of the script being edited.
        """

        raise NotImplementedError("Not implemented")

    def show_ui(self, view: ui.View, mode: ui.PRESENTATION_MODE):
        """
        This function is called when a :class:`~pyto_ui.View` will be presented.

        If you override this method, views will not be presented automatically. Use the :func:`~pyto_ui.show_view`  or the :func:`~pyto_core.show_view` function to show the passed view.

        :param view: The :class:`~pyto_ui.View` to be presented.
        :param mode: The presentation mode.
        """

        raise NotImplementedError("Not implemented")


def set_editor_delegate(delegate: EditorDelegate):
    """
    Sets a :class:`~pyto_core.EditorDelegate` object as the object that will respond to events.
    """

    builtins.__editor_delegate__ = delegate
    EditorViewController.setupEditorButton(None)


__actions__ = []


class __ScriptThread__(threading.Thread):

    __pyto_core_thread__ = None

    script_path = None


def __set_button_icon__(icon, editor):
    image = icon
    if isinstance(image, str):
        image = ui.image_with_system_name(image)
    elif "objc_class" not in dir(image):
        image = ui.__ui_image_from_pil_image__(image)

    editor.editorIcon = image


def __setup_button__(delegate, editor):
    script_path = str(editor.document.fileURL.path)

    image = delegate.editor_button_icon(script_path)

    def action():
        def _action():
            try:
                delegate.editor_button_pressed(script_path)
            except SystemExit:
                pass
            except KeyboardInterrupt:
                pass
            except Exception:
                traceback.print_exc()

            try:
                Python.shared.removeScriptFromList(
                    threading.current_thread().script_path
                )
            except AttributeError:
                pass

        thread = __ScriptThread__(target=_action)
        thread.script_path = script_path
        thread.start()

    __actions__.append(action)
    index = len(__actions__) - 1

    editor.actionIndex = index
    __set_button_icon__(image, editor)


def __setup_editor_button__(i):
    try:
        delegate = builtins.__editor_delegate__
        if delegate is None:
            return

        editor = __py_core__.editorViewControllers.objectAt(i)
        if editor is None:
            return

        __setup_button__(delegate, editor)
    except NotImplementedError:
        pass


# MARK: - Theme


class Theme:
    """
    An editor theme.
    There's no way to create a theme programatically but it can be returned by :func:`~pyto_core.editor_themes` and be shared to other devices.
    """

    data: str = ""
    """
    A base 64 encoded string containing the theme's data.
    """

    name: str = ""
    """
    The theme's name.
    """

    def __init__(self, name: str, data: str):
        check(name, "name", [str])
        check(data, "data", [str])

        self.name = name
        self.data = data

    def __repr__(self):
        return "Theme(" + self.name + ")"

    def __str__(self):
        return self.name

    def __eq__(self, b):
        if type(b) is self.__class__:
            return b.data == self.data
        else:
            return False


def set_theme(theme: Theme):
    """
    Sets the current editor's theme.
    This will not install the theme, so if it was created by another device, the theme will disappear after choosing another one.
    To install it just go to the settings and create a new theme, that will copy the current one.

    :param theme: The theme to be set.
    """

    check(theme, "theme", [Theme])

    if not __py_core__.setTheme(theme.data):
        raise ValueError("Invalid theme!")


def current_editor_theme() -> Theme:
    """
    Returns the current editor theme.

    :rtype: Theme
    """

    themes = [__py_core__.currentTheme]
    themes = list(themes)

    decoded_themes = []

    for theme in themes:
        data = base64.b64decode(str(theme.base64EncodedStringWithOptions(0))).decode()
        decoded_themes.append(Theme(data.split("\n")[0], data))

    return decoded_themes[0]


def editor_themes() -> List[Theme]:
    """
    Returns a list of installed themes. Includes the default ones.

    :rtype: List[Theme]
    """

    themes = __py_core__.themes
    themes = list(themes)

    decoded_themes = []

    for theme in themes:
        data = base64.b64decode(str(theme.base64EncodedStringWithOptions(0))).decode()
        decoded_themes.append(Theme(data.split("\n")[0], data))

    return decoded_themes
