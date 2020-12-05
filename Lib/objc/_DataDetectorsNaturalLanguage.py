"""
Classes from the 'DataDetectorsNaturalLanguage' framework.
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


IPEventClassificationType = _Class("IPEventClassificationType")
IPFeatureSentenceFragment = _Class("IPFeatureSentenceFragment")
IPTextMessageConversation = _Class("IPTextMessageConversation")
IPPerson = _Class("IPPerson")
IPRegexToolbox = _Class("IPRegexToolbox")
IPCircularBufferArray = _Class("IPCircularBufferArray")
IPFeature = _Class("IPFeature")
IPFeatureKeyword = _Class("IPFeatureKeyword")
IPFeatureSentence = _Class("IPFeatureSentence")
IPFeatureData = _Class("IPFeatureData")
IPTenseDetector = _Class("IPTenseDetector")
IPFeatureManager = _Class("IPFeatureManager")
IPFeatureExtractor = _Class("IPFeatureExtractor")
IPSentenceFeatureExtractor = _Class("IPSentenceFeatureExtractor")
IPDataDetectorsFeatureExtractor = _Class("IPDataDetectorsFeatureExtractor")
IPKeywordFeatureExtractor = _Class("IPKeywordFeatureExtractor")
IPMessage = _Class("IPMessage")
IPQuoteParser = _Class("IPQuoteParser")
IPFeatureScanner = _Class("IPFeatureScanner")
IPFeatureTextMessageScanner = _Class("IPFeatureTextMessageScanner")
IPFeatureMailScanner = _Class("IPFeatureMailScanner")
IPMessageUnit = _Class("IPMessageUnit")
IPMessageThread = _Class("IPMessageThread")
