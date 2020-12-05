"""
Classes from the 'DocumentManagerCore' framework.
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


DOCDownloadSettings = _Class("DOCDownloadSettings")
DOCFPItemCollectionManager = _Class("DOCFPItemCollectionManager")
DOCItemCollectionSubscriber = _Class("DOCItemCollectionSubscriber")
DOCEnumerationProperties = _Class("DOCEnumerationProperties")
DOCDownloadImportManager = _Class("DOCDownloadImportManager")
DOCTag = _Class("DOCTag")
DOCAXIdentifier = _Class("DOCAXIdentifier")
_DOCViewStyleSelectorAXIdentifier = _Class("_DOCViewStyleSelectorAXIdentifier")
_DOCSidebarAXIdentifier = _Class("_DOCSidebarAXIdentifier")
_DOCItemInfoViewAXIdentifier = _Class("_DOCItemInfoViewAXIdentifier")
DOCUserInterfaceState = _Class("DOCUserInterfaceState")
DOCFeatureState = _Class("DOCFeatureState")
DOCFeatureStateFFSetting = _Class("DOCFeatureStateFFSetting")
DOCFeature = _Class("DOCFeature")
DOCItemCollectionObserver = _Class("DOCItemCollectionObserver")
DOCFavoritesManager = _Class("DOCFavoritesManager")
DOCTagRegistryICloudDataSource = _Class("DOCTagRegistryICloudDataSource")
DOCTagLocalStorage = _Class("DOCTagLocalStorage")
DOCTagRegistry = _Class("DOCTagRegistry")
DOCManagedPermission = _Class("DOCManagedPermission")
DOCConfiguration = _Class("DOCConfiguration")
