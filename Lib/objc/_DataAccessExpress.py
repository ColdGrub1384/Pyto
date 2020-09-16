'''
Classes from the 'DataAccessExpress' framework.
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

    
DABehaviorOptions = _Class('DABehaviorOptions')
DAEUpdateGrantedDelegatePermissionContext = _Class('DAEUpdateGrantedDelegatePermissionContext')
DAFolderChange = _Class('DAFolderChange')
DAECalendarDirectorySearchResult = _Class('DAECalendarDirectorySearchResult')
DAECalendarAvailabilitySpan = _Class('DAECalendarAvailabilitySpan')
DADisableableObject = _Class('DADisableableObject')
DAStatusReport = _Class('DAStatusReport')
DAContactSearchResultElement = _Class('DAContactSearchResultElement')
DASharedAccountProperties = _Class('DASharedAccountProperties')
DASearchQuery = _Class('DASearchQuery')
DAMailboxSearchQuery = _Class('DAMailboxSearchQuery')
DAContactsSearchQuery = _Class('DAContactsSearchQuery')
DAESubscriptionCalendarDownloadContext = _Class('DAESubscriptionCalendarDownloadContext')
DAAccountChangeInfo = _Class('DAAccountChangeInfo')
DACPLogShared = _Class('DACPLogShared')
DACPLogDFile = _Class('DACPLogDFile')
DAEGrantedDelegate = _Class('DAEGrantedDelegate')
DAAccountExternalIdentificationInfo = _Class('DAAccountExternalIdentificationInfo')
DAECalendarDirectorySearchContext = _Class('DAECalendarDirectorySearchContext')
DAOofParams = _Class('DAOofParams')
DAOofSettingsInfo = _Class('DAOofSettingsInfo')
DAECalendarAvailabilityContext = _Class('DAECalendarAvailabilityContext')
DAESubscribedCalendarSummary = _Class('DAESubscribedCalendarSummary')
DADConnection = _Class('DADConnection')
DAOfficeHoursContext = _Class('DAOfficeHoursContext')
DASharedCalendarContext = _Class('DASharedCalendarContext')
DADownloadContext = _Class('DADownloadContext')
DADAMContainerIDCacheKey = _Class('DADAMContainerIDCacheKey')
DATrafficLogFilename = _Class('DATrafficLogFilename')
DAEGrantedDelegatesListContext = _Class('DAEGrantedDelegatesListContext')
