import widgets as wd
import datetime
import userkeys as uk
import __watch_script_store__ as store
from __check_type__ import check
from typing import Union, List


__PyComplication__ = wd.__Class__("PyComplication")


def schedule_next_reload(time: Union[datetime.timedelta, float]):
    """
    Schedules the next reload of the complication.
    The complication may not be reloaded more than 4 times in 1 hour so be careful and reload only when needed (every 15-20 minutes should be good).

    :param time: The time passed before the complication should reload. A ``datetime.timedelta`` object or the number of seconds.
    """

    check(time, "time", [datetime.timedelta, float, int])

    seconds = 0

    if isinstance(time, datetime.timedelta):
        seconds = time.total_seconds()
    else:
        seconds = time

    __PyComplication__.updateInterval = seconds


class Progess(wd.WidgetComponent):
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
            raise ValueError("The value of a progess bar must be between 0 and 1.")

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


def __objc__(complication: Complication):
    """
    Sends the complication to the Watch.
    """

    objc = __PyComplication__.alloc().init()

    objc.addView(complication.circular.__widget_view__, family=0)
    objc.addView(complication.circular_extra_large.__widget_view__, family=1)
    objc.addView(complication.rectangular.__widget_view__, family=2)
    objc.updateInterval = __PyComplication__.updateInterval

    return objc


def reload_complications():
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

    def name(self) -> str:
        raise NotImplementedError("Implement 'name()' to provide complications.")

    def complication(self, date: datetime.datetime) -> Complication:
        raise NotImplementedError("Implement 'complication(date)' to provide complications.")

    def timeline(self, after_date: datetime.datetime, limit: int) -> List[datetime.datetime]:
        raise NotImplementedError("Implement 'timelines(after_date, limit)' to provide complications.")

    def __complications__(self, after_date, limit):
        complications = []
        for date in self.timeline(after_date, limit):
            complications.append((date, self.complication(date)))
        return complications


def add_complications_provider(provider: ComplicationsProvider):
    store.providers[provider.name()] = provider
    __reload_descriptors__()
