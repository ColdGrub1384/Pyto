"""
Classes from the 'PersistentConnection' framework.
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


PCDispatchTimer = _Class("PCDispatchTimer")
PCSimpleTimer = _Class("PCSimpleTimer")
PCLogging = _Class("PCLogging")
PCLog = _Class("PCLog")
PCCarrierBundleHelper = _Class("PCCarrierBundleHelper")
PCInterfaceMonitor = _Class("PCInterfaceMonitor")
PCWWANUsabilityMonitor = _Class("PCWWANUsabilityMonitor")
PCNonCellularUsabilityMonitor = _Class("PCNonCellularUsabilityMonitor")
PCInterfaceUsabilityMonitor = _Class("PCInterfaceUsabilityMonitor")
PCDistributedLock = _Class("PCDistributedLock")
PCPersistentIdentifiers = _Class("PCPersistentIdentifiers")
PCSystemWakeManager = _Class("PCSystemWakeManager")
PCConnectionManager = _Class("PCConnectionManager")
PCKeepAliveState = _Class("PCKeepAliveState")
PCPersistentTimer = _Class("PCPersistentTimer")
PCMultiStageGrowthAlgorithm = _Class("PCMultiStageGrowthAlgorithm")
PCPersistentInterfaceManager = _Class("PCPersistentInterfaceManager")
PCDelegateInfo = _Class("PCDelegateInfo")
PCCancelAllProcessWakesOperation = _Class("PCCancelAllProcessWakesOperation")
PCScheduleSystemWakeOperation = _Class("PCScheduleSystemWakeOperation")
