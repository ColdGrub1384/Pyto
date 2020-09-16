'''
Classes from the 'DataMigration' framework.
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

    
DMUserDataDispositionManager = _Class('DMUserDataDispositionManager')
DMMigrationPluginWrapperWatchdog = _Class('DMMigrationPluginWrapperWatchdog')
DMXPCConnection = _Class('DMXPCConnection')
DMConnection = _Class('DMConnection')
DMEnvironment = _Class('DMEnvironment')
DMTimer = _Class('DMTimer')
DMClientAPIController = _Class('DMClientAPIController')
DMPluginParameters = _Class('DMPluginParameters')
DMMigrationPluginWrapperConnection = _Class('DMMigrationPluginWrapperConnection')
DMMigrationDeferredExitManager = _Class('DMMigrationDeferredExitManager')
DataClassMigrator = _Class('DataClassMigrator')
DMPluginFaulter = _Class('DMPluginFaulter')
DMPluginFileSystemRep = _Class('DMPluginFileSystemRep')
