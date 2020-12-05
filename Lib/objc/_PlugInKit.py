"""
Classes from the 'PlugInKit' framework.
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


PKManager = _Class("PKManager")
PKXPCObject = _Class("PKXPCObject")
PKBundle = _Class("PKBundle")
PKService = _Class("PKService")
PKCapabilities = _Class("PKCapabilities")
PKDiscoveryLSWatcher = _Class("PKDiscoveryLSWatcher")
PKDiscoveryDriver = _Class("PKDiscoveryDriver")
PKSandboxExtension = _Class("PKSandboxExtension")
PKPlugInCore = _Class("PKPlugInCore")
PKServicePersonality = _Class("PKServicePersonality")
PKHostPlugIn = _Class("PKHostPlugIn")
PKDaemonClient = _Class("PKDaemonClient")
PKHost = _Class("PKHost")
PKServiceDefaults = _Class("PKServiceDefaults")
PKHostDefaults = _Class("PKHostDefaults")
