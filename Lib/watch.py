"""
Apple Watch

The 'watch' module provides APIs for building complications and showing UIs on the Apple Watch.
"""

import widgets as wd
import datetime
import userkeys as uk
import __watch_script_store__ as store
from __check_type__ import check
from typing import Union, List
from threading import current_thread
from pyto import Python


__PyComplication__ = wd.__Class__("PyComplication")
__PyWatchUI__ = wd.__Class__("PyWatchUI")


__cached_ui__ = None


def _schedule_next_reload(time: Union[datetime.timedelta, float]):
    check(time, "time", [datetime.timedelta, float, int])

    seconds = 0

    if isinstance(time, datetime.timedelta):
        seconds = time.total_seconds()
    else:
        seconds = time

    __PyComplication__.updateInterval = seconds


class Progress(wd.WidgetComponent):
    """
    A view indicating a progress.
    """

    value: float = 0
    """
    The value of the progress (between 0 and 1).
    """

    circular: bool = False
    """
    If set to ``False`` (default value), the progress view will be linear.
    If set to ``True``, the progress view will be a circular ring.
    """

    label: wd.WidgetComponent = None
    """
    A widget component describing the progress.
    Can be a symbol or a text for example.
    """

    color: wd.Color = None
    """
    The tint color of the progress.
    """

    def __init__(
        self,
        value: int = 0,
        circular: bool = False,
        label: wd.WidgetComponent = None,
        color: wd.Color = None,
        background_color: wd.Color = None,
        corner_radius: float = 0,
        padding: Union[wd.PADDING, wd.Padding] = None,
        link: str = None,
    ):
        super().__init__(background_color, corner_radius, padding, link)

        check(value, "value", [float])
        check(circular, "circular", [bool])
        check(label, "label", [wd.WidgetComponent, None])
        check(color, "color", [wd.Color, wd.__pyto_ui_color__(), None])

        if value < 0 or value > 1:
            raise ValueError("The value of a progress bar must be between 0 and 1.")

        self.value = value
        self.circular = circular
        self.label = label
        self.color = color

    def __make_objc_view__(self):
        obj = wd.__Class__("WidgetProgress").alloc().init()
        obj.progress = self.value
        obj.isCircular = self.circular

        if self.label is not None:
            obj.label = self.label.__make_objc_view__()

        try:
            obj.color = self.color.__py_color__.managed
        except AttributeError:
            pass

        obj.backgroundColor = self.background_color.__py_color__.managed
        obj.cornerRadius = self.corner_radius
        wd.__set_padding__(self.padding, obj)
        obj.identifier = self.link
        return obj


class Complication:
    """
    The configuration of a Watch Complication, which is a set of different layouts.

    Use the `widgets <widgets.html>`_ APIs to build a complication UI.
    """

    rectangular: wd.WidgetLayout = wd.WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for rectangular complications.
    """

    circular: wd.WidgetLayout = wd.WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for circular complications.
    """

    circular_extra_large: wd.WidgetLayout = wd.WidgetLayout()
    """
    A :class:`~widgets.WidgetLayout` object which UI's will be used for extra large circular complications.
    """

    def __init__(self):
        self.rectangular = wd.WidgetLayout()
        self.circular = wd.WidgetLayout()
        self.circular_extra_large = wd.WidgetLayout()

    def add_row(
        self,
        row: List[wd.WidgetComponent],
        background_color: wd.Color = None,
        corner_radius: float = 0,
        link: str = None,
    ):

        for component in row:
            if "color" not in dir(component):
                continue

            if component.color.__py_color__ == wd.COLOR_LABEL.__py_color__.managed:
                component.color = wd.COLOR_WHITE

        super.add_row(row, background_color, corner_radius, link)


def __objc__(complication: Complication):
    objc = __PyComplication__.alloc().init()

    objc.addView(complication.circular.__widget_view__, family=0)
    objc.addView(complication.circular_extra_large.__widget_view__, family=1)
    objc.addView(complication.rectangular.__widget_view__, family=2)
    objc.updateInterval = __PyComplication__.updateInterval

    return objc


def reload_complications():
    """
    Reloads complications currently displayed on the paired Apple Watch.
    """

    __PyComplication__.reload()


def __reload_descriptors__():
    names = list(store.providers.keys())
    try:
        cached = uk.get("__watch_descriptors__")
    except KeyError:
        cached = []

    if names != cached:
        uk.set(names, "__watch_descriptors__")
        __PyComplication__.reloadDescriptors()


class ComplicationsProvider:
    """
    An abstract class for implementing Apple Watch complications.
    """

    def name(self) -> str:
        """
        Return the name of the complication.
        This name is used in the Watch Face setup.

        :rtype: str
        """

        raise NotImplementedError("Implement 'name()' to provide complications.")

    def complication(self, date: datetime.datetime) -> Complication:
        """
        Return a complication to be displayed in the Watch Face at the given moment.

        :param date: The timestamp at which the returned complication will be displayed.

        :rtype: Complication
        """

        raise NotImplementedError(
            "Implement 'complication(date)' to provide complications."
        )

    def timeline(
        self, after_date: datetime.datetime, limit: int
    ) -> List[datetime.datetime]:
        """
        Return a list of timestamps. The Apple Watch will display a complication on each of the returned dates.
        The Apple Watch will call this function to request data for the future.


        You should fetch your data from this function and return the ``datetime`` objects for which you have data.
        Then the :meth:`~watch.Complication.complication` method will be called for each timestamp to configure the content.

        :param after_date: The moment when the timeline begins.
        :param limit: A limit of dates that can be returned (usually 100).

        :rtype: List[datetime.datetime]
        """

        raise NotImplementedError(
            "Implement 'timelines(after_date, limit)' to provide complications."
        )

    def __complications__(self, after_date, limit):
        complications = []
        for date in self.timeline(after_date, limit):
            complications.append((date, self.complication(date)))
        return complications


def add_complications_provider(provider: ComplicationsProvider):
    """
    Adds a complication to the Apple Watch. After adding the :class:`~watch.ComplicationsProvider` object, you will be able to add the complication to your Watch Face.
    This function must be called from the script configured for the Apple Watch so the passed object can provide the data to the Watch Face.

    :param provider: The object that will provide data to the complication.
    """

    store.providers[provider.name()] = provider
    __reload_descriptors__()

    try:
        path = current_thread().script_path
        if path != str(Python.watchScriptURL.path):
            reload_complications()
    except AttributeError:
        pass


def delete_interface():
    """
    Deletes the previous user interface sent to the Watch.
    """

    __PyWatchUI__.deleteUI()


def make_interface() -> wd.WidgetLayout:
    """
    Creates and returns a :class:`~widget.WidgetLayout` instance.
    When the script finishes running, the content of the returned object will be passed and displayed in the Apple Watch.
    This function must be called from the script configured in the Apple Watch.

    :rtype: wd.WidgetLayout
    """

    global __cached_ui__

    view = wd.WidgetLayout()
    __cached_ui__ = view.__widget_view__
    return view


def __show_ui_if_needed__():
    global __cached_ui__

    if __cached_ui__ is not None:
        __PyWatchUI__.sendUI(__cached_ui__)
    __cached_ui__ = None
