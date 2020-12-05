"""
Classes from the 'NanoPreferencesSync' framework.
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


NPSDomainAccessorInternal = _Class("NPSDomainAccessorInternal")
NPSManager = _Class("NPSManager")
NPSDomainAccessorFilePresenter = _Class("NPSDomainAccessorFilePresenter")
NPSDomainAccessor = _Class("NPSDomainAccessor")
NPSDomainAccessorUtils = _Class("NPSDomainAccessorUtils")
NPSPrefPlistProtectedUtil = _Class("NPSPrefPlistProtectedUtil")
NPSPrefPlistSizeUtil = _Class("NPSPrefPlistSizeUtil")
