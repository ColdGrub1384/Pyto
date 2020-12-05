"""
Classes from the 'MediaExperience' framework.
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


CMSM_IDSConnection = _Class("CMSM_IDSConnection")
FigRoutePredictionFetchOneShotCompletion = _Class(
    "FigRoutePredictionFetchOneShotCompletion"
)
FigRoutingSessionUpdateState = _Class("FigRoutingSessionUpdateState")
MXSession = _Class("MXSession")
CMSM_IDSClient = _Class("CMSM_IDSClient")
DisplayModeRefreshRateObserver = _Class("DisplayModeRefreshRateObserver")
FigResilientRemoteRoutingContextFactory = _Class(
    "FigResilientRemoteRoutingContextFactory"
)
CMSM_IDSServer = _Class("CMSM_IDSServer")
FigRemoteRoutingContextFactory = _Class("FigRemoteRoutingContextFactory")
MXTestSessionFactory = _Class("MXTestSessionFactory")
MXTestCore = _Class("MXTestCore")
MXTestSessionProperty = _Class("MXTestSessionProperty")
MX_DeviceManagementPolicyDidChangeObserver = _Class(
    "MX_DeviceManagementPolicyDidChangeObserver"
)
MXSystemController = _Class("MXSystemController")
