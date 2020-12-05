"""
Classes from the 'NLP' framework.
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


NLPOIEntry = _Class("NLPOIEntry")
QuickTypePFLTrainer = _Class("QuickTypePFLTrainer")
NLSearchParserManager = _Class("NLSearchParserManager")
NLParsecDataManager = _Class("NLParsecDataManager")
QuickTypePFLData = _Class("QuickTypePFLData")
NLPOIEntryImpl = _Class("NLPOIEntryImpl")
