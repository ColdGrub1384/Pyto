"""
Classes from the 'CertUI' framework.
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


CertUIPrompt = _Class("CertUIPrompt")
CertUITrustManager = _Class("CertUITrustManager")
CertUIConnectionDelegate = _Class("CertUIConnectionDelegate")
CertUIUtilities = _Class("CertUIUtilities")
