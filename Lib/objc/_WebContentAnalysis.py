"""
Classes from the 'WebContentAnalysis' framework.
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


WFSystemContentWhitelist = _Class("WFSystemContentWhitelist")
WFSystemContentWhitelistItem = _Class("WFSystemContentWhitelistItem")
WFBlockPage = _Class("WFBlockPage")
WFJudge = _Class("WFJudge")
WFWhitelistUserPreferences = _Class("WFWhitelistUserPreferences")
WFWhitelistSiteBuffer = _Class("WFWhitelistSiteBuffer")
WFWebPageDecorator = _Class("WFWebPageDecorator")
WFWebPageToTrainingText = _Class("WFWebPageToTrainingText")
WFWebPageToFilterText = _Class("WFWebPageToFilterText")
WFVerdict = _Class("WFVerdict")
WFNodeWrapper = _Class("WFNodeWrapper")
WFTreeXMLDocumentStripper = _Class("WFTreeXMLDocumentStripper")
WFTreeHTMLStripper = _Class("WFTreeHTMLStripper")
WFTagFactory = _Class("WFTagFactory")
WFPostprocessor = _Class("WFPostprocessor")
WFLSMResult = _Class("WFLSMResult")
WFCategoryJudgement = _Class("WFCategoryJudgement")
WFLSMMap = _Class("WFLSMMap")
WFLSMScoreNormalizedMap = _Class("WFLSMScoreNormalizedMap")
WFJavascriptStripper = _Class("WFJavascriptStripper")
WFImgArrayCache = _Class("WFImgArrayCache")
XMLNode = _Class("XMLNode")
WFLink = _Class("WFLink")
WFImg = _Class("WFImg")
WFTagFlyweight = _Class("WFTagFlyweight")
WFJapanDatingTag = _Class("WFJapanDatingTag")
WFUSC2257Tag = _Class("WFUSC2257Tag")
WFSlangTag = _Class("WFSlangTag")
WFDocumentStructureTag = _Class("WFDocumentStructureTag")
WFContentSniffer = _Class("WFContentSniffer")
WFUserSettings = _Class("WFUserSettings")
WebFilterEvaluator = _Class("WebFilterEvaluator")
WFPINEntryViewController = _Class("WFPINEntryViewController")
WFRemotePINEntryViewController = _Class("WFRemotePINEntryViewController")
