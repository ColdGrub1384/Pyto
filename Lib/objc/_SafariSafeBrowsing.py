'''
Classes from the 'SafariSafeBrowsing' framework.
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

    
RemoteConfigurationController = _Class('RemoteConfigurationController')
ProviderConfiguration = _Class('ProviderConfiguration')
SSBDatabaseUpdateSupport = _Class('SSBDatabaseUpdateSupport')
SSBDatabaseUpdaterStatus = _Class('SSBDatabaseUpdaterStatus')
SSBManagedConfigurationManager = _Class('SSBManagedConfigurationManager')
_SSBServiceStatus = _Class('_SSBServiceStatus')
SSBAvailability = _Class('SSBAvailability')
_SSBDatabaseStatus = _Class('_SSBDatabaseStatus')
SSBLookupResult = _Class('SSBLookupResult')
SSBServiceLookupResult = _Class('SSBServiceLookupResult')
SSBLookupContext = _Class('SSBLookupContext')
