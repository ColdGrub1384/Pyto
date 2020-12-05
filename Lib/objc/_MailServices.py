"""
Classes from the 'MailServices' framework.
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


_MSXPCRemoteProxy = _Class("_MSXPCRemoteProxy")
MSCriterion = _Class("MSCriterion")
MSIdleAutosaveItem = _Class("MSIdleAutosaveItem")
MSEmailModel = _Class("MSEmailModel")
MSAutosaveSession = _Class("MSAutosaveSession")
MSXPCService = _Class("MSXPCService")
MSSearch = _Class("MSSearch")
MSAutosave = _Class("MSAutosave")
MSService = _Class("MSService")
MSMailDefaultService = _Class("MSMailDefaultService")
MSXPCEndpoint = _Class("MSXPCEndpoint")
MSSendEmail = _Class("MSSendEmail")
MSSaveEmail = _Class("MSSaveEmail")
MSPushRegistration = _Class("MSPushRegistration")
MSKeyValueStore = _Class("MSKeyValueStore")
MSAccounts = _Class("MSAccounts")
MSXPCConnection = _Class("MSXPCConnection")
