"""
Classes from the 'IntentsCore' framework.
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


INCAppLaunchRequest = _Class("INCAppLaunchRequest")
INCExtensionProxy = _Class("INCExtensionProxy")
INCIntentDefaultValueProvider = _Class("INCIntentDefaultValueProvider")
INCAppProxy = _Class("INCAppProxy")
INCExtensionError = _Class("INCExtensionError")
INCExtensionConnection = _Class("INCExtensionConnection")
INCExtensionTransactionState = _Class("INCExtensionTransactionState")
INCWidgetIntentProvider = _Class("INCWidgetIntentProvider")
INCChronoIntentProvider = _Class("INCChronoIntentProvider")
INCWidgetOptions = _Class("INCWidgetOptions")
INCChronoOptions = _Class("INCChronoOptions")
INCDisplayLayoutMonitorObserver = _Class("INCDisplayLayoutMonitorObserver")
INCExtensionPlugInBundleManager = _Class("INCExtensionPlugInBundleManager")
INCExtensionManager = _Class("INCExtensionManager")
_INCOptionalLocalExtension = _Class("_INCOptionalLocalExtension")
INCExtensionTransaction = _Class("INCExtensionTransaction")
INCExtensionPlugInBundle = _Class("INCExtensionPlugInBundle")
INCLocalExtensionRegistry = _Class("INCLocalExtensionRegistry")
INCExtensionRequest = _Class("INCExtensionRequest")
INCExecutionInfoResolver = _Class("INCExecutionInfoResolver")
INCIntentExecutionInfoResolver = _Class("INCIntentExecutionInfoResolver")
INCExecutionInfo = _Class("INCExecutionInfo")
INCIntentExecutionInfo = _Class("INCIntentExecutionInfo")
INCUserActivityExecutionInfo = _Class("INCUserActivityExecutionInfo")
