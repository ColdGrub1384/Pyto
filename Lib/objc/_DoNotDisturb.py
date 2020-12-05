"""
Classes from the 'DoNotDisturb' framework.
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


DNDSettingsService = _Class("DNDSettingsService")
DNDRemoteServiceConnection = _Class("DNDRemoteServiceConnection")
DNDStateModeAssertionMetadata = _Class("DNDStateModeAssertionMetadata")
DNDModeAssertionService = _Class("DNDModeAssertionService")
DNDClientEventSource = _Class("DNDClientEventSource")
DNDModeAssertionDetails = _Class("DNDModeAssertionDetails")
DNDMutableModeAssertionDetails = _Class("DNDMutableModeAssertionDetails")
DNDScheduleSettings = _Class("DNDScheduleSettings")
DNDMutableScheduleSettings = _Class("DNDMutableScheduleSettings")
DNDModeAssertionSource = _Class("DNDModeAssertionSource")
DNDClientEventDetails = _Class("DNDClientEventDetails")
DNDMutableClientEventDetails = _Class("DNDMutableClientEventDetails")
DNDStateService = _Class("DNDStateService")
DNDModeAssertionInvalidationDetails = _Class("DNDModeAssertionInvalidationDetails")
DNDMutableModeAssertionInvalidationDetails = _Class(
    "DNDMutableModeAssertionInvalidationDetails"
)
DNDBypassSettings = _Class("DNDBypassSettings")
DNDMutableBypassSettings = _Class("DNDMutableBypassSettings")
DNDState = _Class("DNDState")
DNDClientEventBehavior = _Class("DNDClientEventBehavior")
DNDEventBehaviorResolutionService = _Class("DNDEventBehaviorResolutionService")
DNDRequestDetails = _Class("DNDRequestDetails")
DNDDevice = _Class("DNDDevice")
DNDStateUpdate = _Class("DNDStateUpdate")
DNDModeAssertionInvalidation = _Class("DNDModeAssertionInvalidation")
DNDScheduleTimePeriod = _Class("DNDScheduleTimePeriod")
DNDMutableScheduleTimePeriod = _Class("DNDMutableScheduleTimePeriod")
DNDModeAssertionLifetime = _Class("DNDModeAssertionLifetime")
DNDModeAssertionScheduleLifetime = _Class("DNDModeAssertionScheduleLifetime")
DNDModeAssertionUserRequestedLifetime = _Class("DNDModeAssertionUserRequestedLifetime")
DNDModeAssertionLocationLifetime = _Class("DNDModeAssertionLocationLifetime")
DNDModeAssertionCalendarEventLifetime = _Class("DNDModeAssertionCalendarEventLifetime")
DNDModeAssertionDateIntervalLifetime = _Class("DNDModeAssertionDateIntervalLifetime")
DNDBehaviorSettings = _Class("DNDBehaviorSettings")
DNDMutableBehaviorSettings = _Class("DNDMutableBehaviorSettings")
DNDModeAssertion = _Class("DNDModeAssertion")
DNDScheduleTime = _Class("DNDScheduleTime")
DNDMutableScheduleTime = _Class("DNDMutableScheduleTime")
