'''
Classes from the 'CalendarDatabase' framework.
'''

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

    
CDBDataProtectionObserver = _Class('CDBDataProtectionObserver')
EKPersistentChangeStoreRowInfo = _Class('EKPersistentChangeStoreRowInfo')
EKPersistentChangeStoreInfo = _Class('EKPersistentChangeStoreInfo')
CADObjectChangeID = _Class('CADObjectChangeID')
CDBSpotlightUtilities = _Class('CDBSpotlightUtilities')
CDBABCReporter = _Class('CDBABCReporter')
CDBCommonEntityFunctionalityHandler = _Class('CDBCommonEntityFunctionalityHandler')
CDBBundle = _Class('CDBBundle')
EKCalendarFilter = _Class('EKCalendarFilter')
CalItemMetadata = _Class('CalItemMetadata')
CADObjectID = _Class('CADObjectID')
CalAlarmMetadata = _Class('CalAlarmMetadata')
CalStoreSetupAndTeardownUtils = _Class('CalStoreSetupAndTeardownUtils')
CDBPreferences = _Class('CDBPreferences')
CalSearch = _Class('CalSearch')
CDBAttachmentMigrator = _Class('CDBAttachmentMigrator')
CDBAttachmentInfo = _Class('CDBAttachmentInfo')
CADObjectChangeIDHelper = _Class('CADObjectChangeIDHelper')
CalDAVOfficeHour = _Class('CalDAVOfficeHour')
CalScheduledTaskCache_TimeZoneFetchContext = _Class('CalScheduledTaskCache_TimeZoneFetchContext')
CDBRecurrenceGenerator = _Class('CDBRecurrenceGenerator')
