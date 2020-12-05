"""
Classes from the 'DebugHierarchyFoundation' framework.
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


DebugHierarchyFormatSpecifier = _Class("DebugHierarchyFormatSpecifier")
DebugHierarchyTargetHub = _Class("DebugHierarchyTargetHub")
DBGTargetHub = _Class("DBGTargetHub")
DebugHierarchyLogEntry = _Class("DebugHierarchyLogEntry")
DebugHierarchyRequestActionExecutor = _Class("DebugHierarchyRequestActionExecutor")
DebugHierarchyRuntimeType = _Class("DebugHierarchyRuntimeType")
DebugHierarchyObjectInterface = _Class("DebugHierarchyObjectInterface")
DebugHierarchyRequestExecutor = _Class("DebugHierarchyRequestExecutor")
DebugHierarchyCrawler = _Class("DebugHierarchyCrawler")
DebugHierarchyRequestExecutionContext = _Class("DebugHierarchyRequestExecutionContext")
DebugHierarchyRuntimeInfo = _Class("DebugHierarchyRuntimeInfo")
DebugHierarchyCrawlerOptions = _Class("DebugHierarchyCrawlerOptions")
DebugHierarchyRequest = _Class("DebugHierarchyRequest")
DebugHierarchyAbstractRequestAction = _Class("DebugHierarchyAbstractRequestAction")
DebugHierarchyResetAction = _Class("DebugHierarchyResetAction")
DebugHierarchyRunLoopAction = _Class("DebugHierarchyRunLoopAction")
DebugHierarchyPropertyAction = _Class("DebugHierarchyPropertyAction")
DebugHierarchyPropertyActionLegacyV1 = _Class("DebugHierarchyPropertyActionLegacyV1")
DebugHierarchyMetaDataAction = _Class("DebugHierarchyMetaDataAction")
DebugHierarchyMetaDataProviderProtocolHelper = _Class(
    "DebugHierarchyMetaDataProviderProtocolHelper"
)
DebugHierarchyValueProtocolHelper = _Class("DebugHierarchyValueProtocolHelper")
DebugHierarchyObjectProtocolHelper = _Class("DebugHierarchyObjectProtocolHelper")
DebugHierarchyEntryPointProtocolHelper = _Class(
    "DebugHierarchyEntryPointProtocolHelper"
)
DebugHierarchyProperty = _Class("DebugHierarchyProperty")
