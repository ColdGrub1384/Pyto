from hashlib import new
from typing import List, Tuple
from EventKit import EKEvent, EKAlarm, EKStructuredLocation, EKRecurrenceRule, EKRecurrenceEnd
from pyto import PyEventHelper
from datetime import datetime, timezone, timedelta, date
from Foundation import NSDate, NSTimeZone, NSURL
from CoreLocation import CLLocation
from __check_type__ import check
from location import Location
from enum import Enum


def _foundation_date(date: datetime) -> NSDate:
    timestamp = datetime.timestamp(date)
    return NSDate.alloc().initWithTimeIntervalSince1970(timestamp)


def _datetime(date: NSDate) -> datetime:
    return datetime.fromtimestamp(date.timeIntervalSince1970())


def _foundation_timezone(tz: timezone) -> NSTimeZone:
    now = datetime.now(tz)
    return NSTimeZone.timeZoneForSecondsFromGMT(timezone.utcoffset(now).seconds)


def _timezone(tz: NSTimeZone) -> timezone:
    return timezone(timedelta(seconds=tz.secondsFromGMT()))


class StructuredLocation:

    def __init__(self, title: str):
        check(title, "title", [str])
        self.__location__ = EKStructuredLocation.locationWithTitle(title)


    @property
    def title(self) -> str:
        title = self.__location__.title
        if title is None:
            return title
        else:
            return str(title)

    @title.setter
    def title(self, new_value: str):
        self.__location__.title = new_value
    

    @property
    def geo_location(self) -> Location:
        location = self.__location__.geoLocation
        if location is None:
            return location
        else:
            return Location(longitude=location.coordinate.longitude, latitude=location.coordinate.latitude)

    @geo_location.setter
    def geo_location(self, new_value: Location):
        self.__location__.geoLocation = CLLocation.alloc().initWithLatitude(new_value.latitude, longitude=new_value.longitude)


    @property
    def radius(self) -> float:
        return self.__location__.radius

    @radius.setter
    def radius(self, new_value: float):
        self.__location__.radius = new_value


class AlarmProximity(Enum):

    NONE = 0
    ENTER = 1 
    LEAVE = 2


class AlarmType(Enum):

    DISPLAY = 0
    AUDIO = 1
    PROCEDURE = 2
    EMAIL = 3


class Alarm:

    def __init__(self, date: datetime = None, offset: timedelta = None):
        if date is not None and offset is not None:
            msg = "Cannot initialize 'Alarm' with both 'absolute_date' and 'offset'."
            raise ValueError(msg)

        check(date, "date", [datetime, None])
        check(offset, "offset", [timedelta, None])

        if date is not None:
            self.__alarm__ = EKAlarm.alarmWithAbsoluteDate(_foundation_date(date))
        elif offset is not None:
            self.__alarm__ = EKAlarm.alarmWithRelativeOffset(offset.seconds)
        else:
            msg = "Cannot initialize 'Alarm' any parameter."
            raise ValueError(msg)


    @property
    def absolute_date(self) -> datetime:
        date = self.__alarm__.absoluteDate
        if date is None:
            return date
        else:
            return _datetime(date)

    @absolute_date.setter
    def absolute_date(self, new_value: datetime):
        if new_value is None:
            self.__alarm__.absoluteDate = new_value
        else:
            self.__alarm__.absoluteDate = _foundation_date(new_value)
    

    @property
    def relative_offset(self) -> timedelta:
        offset = self.__alarm__.relativeOffset
        if offset is None:
            return offset
        else:
            return timedelta(seconds=offset)

    @relative_offset.setter
    def relative_offset(self, new_value: timedelta):
        if new_value is None:
            self.__alarm__.relativeOffset = new_value
        else:
            self.__alarm__.relativeOffset = new_value.seconds


    @property
    def structured_location(self) -> StructuredLocation:
        location = self.__alarm__.structuredLocation
        if location is None:
            return None
        else:
            py_location = StructuredLocation.__new__(StructuredLocation)
            py_location.__location__ = location
            return py_location

    @structured_location.setter
    def structured_location(self, new_value: StructuredLocation):
        if new_value is None:
            self.__alarm__.structuredLocation = new_value
        else:
            self.__alarm__.structuredLocation = new_value.__location__
    

    @property
    def proximity(self) -> AlarmProximity:
        proximity = self.__alarm__.proximity
        return AlarmProximity(int(proximity))

    @proximity.setter
    def proximity(self, new_value: AlarmProximity):
        self.__alarm__.proximity = new_value.value


    @property
    def type(self) -> AlarmType:
        type = self.__alarm__.type
        return AlarmType(int(type))

    @type.setter
    def type(self, new_value: AlarmType):
        self.__alarm__.type = new_value.value


    @property
    def email_address(self) -> str:
        email = self.__alarm__.emailAddress
        if email is None:
            return email
        else:
            return str(email)

    @email_address.setter
    def email_address(self, new_value: str):
        self.__alarm__.emailAddress = new_value

    
    @property
    def sound_name(self) -> str:
        sound = self.__alarm__.soundName
        if sound is None:
            return sound
        else:
            return str(sound)

    @sound_name.setter
    def sound_name(self, new_value: str):
        self.__alarm__.soundName = new_value


class RecurrenceEnd:

    def __init__(self, end_date: datetime = None, occurrence_count: int = None):
        if end_date is not None and occurrence_count is not None:
            msg = "Cannot initialize 'RecurrenceEnd' with both 'end_date' and 'occurrence_count'."
            raise ValueError(msg)

        check(end_date, "end_date", [datetime, None])
        check(occurrence_count, "occurrence_count", [int, float, None])

        if end_date is not None:
            self.__end__ = EKRecurrenceEnd.recurrenceEndWithEndDate(_foundation_date(end_date))
        elif occurrence_count is not None:
            self.__end__ = EKRecurrenceEnd.recurrenceEndWithOccurrenceCount(occurrence_count)
        else:
            msg = "Cannot initialize 'RecurrenceEnd' any parameter."
            raise ValueError(msg)


    @property
    def end_date(self) -> datetime:
        date = self.__end__.endDate
        if date is None:
            return date
        else:
            return _datetime(date)

    @end_date.setter
    def end_date(self, new_value: datetime):
        if new_value is None:
            self.__end__.endDate = new_value
        else:
            self.__end__.endDate = _foundation_date(new_value)
    

    @property
    def occurrence_count(self) -> int:
        count = self.__end__.occurrenceCount
        return count

    @occurrence_count.setter
    def occurrence_count(self, new_value: int):
        self.__end__.occurrenceCount = new_value



class RecurrenceFrequency(Enum):

    DAILY = 0
    WEEKLY = 1
    MONTHLY = 2
    YEARLY = 3


class RecurrenceRule:

    def __init__(self, frequency: RecurrenceFrequency, interval: int, end: RecurrenceEnd):

        check(frequency, "frequency", [RecurrenceFrequency])
        check(interval, "interval", [int, float])
        check(end, "end", [RecurrenceEnd, None])

        self.__rule__ = EKRecurrenceRule.alloc().initRecurrenceWithFrequency(frequency.value, interval=interval, end=end.__end__)


    @property
    def frequency(self) -> RecurrenceFrequency:
        freq = self.__rule__.frequency
        return RecurrenceFrequency(freq)
    

    @property
    def interval(self) -> int:
        return self.__rule__.interval


    @property
    def end(self) -> RecurrenceEnd:
        end = self.__rule__.recurrenceEnd
        if end is None:
            return end
        else:
            py_end = RecurrenceEnd.__new__(RecurrenceEnd)
            py_end.__end__ = end
            return py_end
    
    @end.setter
    def end(self, new_value: RecurrenceEnd):
        if new_value is None:
            self.__rule__.recurrenceEnd = new_value
        else:
            self.__rule__.recurrenceEnd = new_value.__end__


class Event:

    def __init__(self):
        self.__event__ = PyEventHelper.makeEvent()


    @property
    def title(self) -> str:
        title = self.__event__.title
        if title is None:
            return title
        else:
            return str(title)

    @title.setter
    def title(self, new_value: str):
        self.__event__.title = new_value


    @property
    def location(self) -> str:
        location = self.__event__.location
        if location is None:
            return location
        else:
            return str(location)

    @location.setter
    def location(self, new_value: str):
        self.__event__.location = new_value


    @property
    def creation_date(self) -> datetime:
        creation_date = self.__event__.creationDate
        if creation_date is None:
            return creation_date
        else:
            return _datetime(creation_date)

    
    @property
    def last_modified_date(self) -> datetime:
        modification_date = self.__event__.lastModifiedDate
        if modification_date is None:
            return modification_date
        else:
            return _datetime(modification_date)

    
    @property
    def time_zone(self) -> timezone:
        tz = self.__event__.timeZone
        if tz is None:
            return tz
        else:
            return _timezone(tz)

    @time_zone.setter
    def time_zone(self, new_value: timezone):

        if new_value is None:
            self.__event__.timeZone = new_value
        else:
            self.__event__.timeZone = _foundation_timezone(new_value)
    
    
    @property
    def url(self) -> str:
        url = self.__event__.URL
        if url is None:
            return url
        else:
            return str(url.absoluteString)

    @url.setter
    def url(self, new_value: str):
        if new_value is None:
            self.__event__.URL = new_value
        else:
            self.__event__.URL = NSURL.URLWithString(new_value)


    @property
    def notes(self) -> str:
        notes = self.__event__.notes
        if notes is None:
            return notes
        else:
            return str(notes)

    @notes.setter
    def notes(self, new_value: str):
        self.__event__.notes = new_value

    
    @property
    def alarms(self) -> Tuple[Alarm]:
        alarms = []
        objc_alarms = self.__event__.alarms
        if objc_alarms is None:
            return alarms
        
        for alarm in objc_alarms:
            py_alarm = Alarm.__new__(Alarm)
            py_alarm.__alarm__ = alarm
            alarms.append(py_alarm)
        
        return alarms
    
    @alarms.setter
    def alarms(self, new_value: Tuple[Alarm]):
        objc_alarms = []
        if new_value is None:
            self.__event__.alarms = new_value
        else:
            for alarm in new_value:
                objc_alarms.append(alarm.__alarm__)
            
            self.__event__.alarms = objc_alarms
    

    def add_alarm(self, alarm: Alarm):
        self.__event__.addAlarm(alarm.__alarm__)
    

    def remove_alarm(self, alarm: Alarm):
        self.__event__.removeAlarm(alarm.__alarm__)
    

    @property
    def recurrence_rule(self) -> RecurrenceRule:
        rules = []
        objc_rules = self.__event__.recurrenceRules
        if objc_rules is None:
            return None
        
        for rule in objc_rules:
            py_rule = RecurrenceRule.__new__(RecurrenceRule)
            py_rule.__rule__ = rule
            rules.append(py_rule)
        
        try:
            return rules[0]
        except IndexError:
            return None

    @recurrence_rule.setter
    def recurrence_rule(self, new_value: RecurrenceRule):
        if new_value is None:
            self.__event__.recurrenceRules = new_value
        else:
            self.__event__.recurrenceRules = [new_value]

    
    @property
    def start_date(self) -> datetime:
        date = self.__event__.startDate
        if date is None:
            return date
        else:
            return _datetime(date)

    @start_date.setter
    def start_date(self, new_value: datetime):
        if new_value is None:
            self.__event__.startDate = new_value
        else:
            self.__event__.startDate = _foundation_date(new_value)


    @property
    def end_date(self) -> datetime:
        date = self.__event__.endDate
        if date is None:
            return date
        else:
            return _datetime(date)

    @end_date.setter
    def end_date(self, new_value: datetime):
        if new_value is None:
            self.__event__.endDate = new_value
        else:
            self.__event__.endDate = _foundation_date(new_value)
    

    @property
    def all_day(self) -> bool:
        return self.__event__.isAllDay
    
    @all_day.setter
    def all_day(self, new_value: bool):
        self.__event__.setAllDay(new_value)
    

    @property
    def occurrence_date(self) -> datetime:
        date = self.__event__.occurrenceDate
        if date is None:
            return date
        else:
            return _datetime(date)
    

    @property
    def structured_location(self) -> StructuredLocation:
        location = self.__event__.structuredLocation
        if location is None:
            return None
        else:
            py_location = StructuredLocation.__new__(StructuredLocation)
            py_location.__location__ = location
            return py_location

    @structured_location.setter
    def structured_location(self, new_value: StructuredLocation):
        if new_value is None:
            self.__event__.structuredLocation = new_value
        else:
            self.__event__.structuredLocation = new_value.__location__
    

    def refresh(self) -> bool:
        return self.__event_


def save_event(event: Event):

    check(event, "event", [Event])

    error = PyEventHelper.saveEvent(event.__event__)
    if error is not None:
        msg = str(error)
        raise RuntimeError(msg)


def remove_event(event: Event):

    check(event, "event", [Event])

    error = PyEventHelper.removeEvent(event.__event__)
    if error is not None:
        msg = str(error)
        raise RuntimeError(msg)


def get_events(start_date: datetime, end_date: datetime) -> List[Event]:

    check(start_date, "start_date", [datetime])
    check(end_date, "end_date", [datetime])

    result = PyEventHelper.getEventsWithStartDate(_foundation_date(start_date), endDate=_foundation_date(end_date))
    if result.error is not None:
        msg = str(result.error)
        raise RuntimeError(msg)
    else:
        events = []
        for event in list(result.events):
            py_event = Event.__new__(Event)
            py_event.__event__ = event
            events.append(py_event)
        
        return events
    