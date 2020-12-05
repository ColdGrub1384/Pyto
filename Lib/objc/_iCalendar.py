"""
Classes from the 'iCalendar' framework.
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


ICSTokenizer = _Class("ICSTokenizer")
ICSRecurrenceRule = _Class("ICSRecurrenceRule")
ICSByDayValue = _Class("ICSByDayValue")
ICSPeriod = _Class("ICSPeriod")
ICSDateValue = _Class("ICSDateValue")
ICSDateTimeValue = _Class("ICSDateTimeValue")
ICSDateTimeUTCValue = _Class("ICSDateTimeUTCValue")
ICSCompressedInputStream = _Class("ICSCompressedInputStream")
ICSTimeZoneChange = _Class("ICSTimeZoneChange")
ICSTimeZoneTranslator = _Class("ICSTimeZoneTranslator")
ICSLogger = _Class("ICSLogger")
ICSParser = _Class("ICSParser")
ICSDocument = _Class("ICSDocument")
ICSColor = _Class("ICSColor")
ICSZStringWriter = _Class("ICSZStringWriter")
ICSStringWriter = _Class("ICSStringWriter")
ICSProperty = _Class("ICSProperty")
ICSTravelDuration = _Class("ICSTravelDuration")
ICSConference = _Class("ICSConference")
ICSMultiValueProperty = _Class("ICSMultiValueProperty")
ICSStructuredLocation = _Class("ICSStructuredLocation")
ICSTravelAdvisoryBehavior = _Class("ICSTravelAdvisoryBehavior")
ICSDate = _Class("ICSDate")
ICSAlternateTimeProposal = _Class("ICSAlternateTimeProposal")
ICSFreeBusyTime = _Class("ICSFreeBusyTime")
ICSTrigger = _Class("ICSTrigger")
ICSAttendeeComment = _Class("ICSAttendeeComment")
ICSUserAddress = _Class("ICSUserAddress")
ICSAttachment = _Class("ICSAttachment")
ICSPushbackStream = _Class("ICSPushbackStream")
ICSDuration = _Class("ICSDuration")
ICSInputData = _Class("ICSInputData")
ICSComponent = _Class("ICSComponent")
ICSTimeZoneBlock = _Class("ICSTimeZoneBlock")
ICSTimeZoneStandardBlock = _Class("ICSTimeZoneStandardBlock")
ICSTimeZoneDaylightBlock = _Class("ICSTimeZoneDaylightBlock")
ICSAlarm = _Class("ICSAlarm")
ICSAvailable = _Class("ICSAvailable")
ICSFreeBusy = _Class("ICSFreeBusy")
ICSAvailability = _Class("ICSAvailability")
ICSJournal = _Class("ICSJournal")
ICSCalendarItem = _Class("ICSCalendarItem")
ICSEvent = _Class("ICSEvent")
ICSTodo = _Class("ICSTodo")
ICSCalendar = _Class("ICSCalendar")
ICSTimeZone = _Class("ICSTimeZone")
ICSUnfoldingStream = _Class("ICSUnfoldingStream")
ICSPredefinedValue = _Class("ICSPredefinedValue")
ICSClassificationValue = _Class("ICSClassificationValue")
ICSCalendarServerAccessValue = _Class("ICSCalendarServerAccessValue")
ICSActionValue = _Class("ICSActionValue")
ICSMethodValue = _Class("ICSMethodValue")
ICSBusyStatusValue = _Class("ICSBusyStatusValue")
ICSTransparencyValue = _Class("ICSTransparencyValue")
ICSStatusValue = _Class("ICSStatusValue")
ICSRelationshipTypeParameter = _Class("ICSRelationshipTypeParameter")
ICSFreeBusyTypeParameter = _Class("ICSFreeBusyTypeParameter")
ICSScheduleForceSendParameter = _Class("ICSScheduleForceSendParameter")
ICSScheduleStatusParameter = _Class("ICSScheduleStatusParameter")
ICSScheduleAgentParameter = _Class("ICSScheduleAgentParameter")
ICSAlternateTimeProposalStatusParameter = _Class(
    "ICSAlternateTimeProposalStatusParameter"
)
ICSParticipationStatusParameter = _Class("ICSParticipationStatusParameter")
ICSCalendarUserParameter = _Class("ICSCalendarUserParameter")
ICSRoleParameter = _Class("ICSRoleParameter")
