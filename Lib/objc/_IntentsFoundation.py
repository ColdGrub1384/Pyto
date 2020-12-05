"""
Classes from the 'IntentsFoundation' framework.
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


INFSentenceContext = _Class("INFSentenceContext")
INFGrammarCollection = _Class("INFGrammarCollection")
INFSentence = _Class("INFSentence")
IFObjectHasher = _Class("IFObjectHasher")
INFSentenceToken = _Class("INFSentenceToken")
INFPartOfSpeech = _Class("INFPartOfSpeech")
INFNumber = _Class("INFNumber")
INFVariantsDescriptor = _Class("INFVariantsDescriptor")
INFSentenceTokenWithContext = _Class("INFSentenceTokenWithContext")
_IFValueTransformer = _Class("_IFValueTransformer")
