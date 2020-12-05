"""
Classes from the 'ResponseKit' framework.
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


RKPaymentIdentifier = _Class("RKPaymentIdentifier")
RKCurrencyAmount = _Class("RKCurrencyAmount")
RKUtilities = _Class("RKUtilities")
RKMessageClassifier = _Class("RKMessageClassifier")
RKConversation = _Class("RKConversation")
RKBundleDataProvider = _Class("RKBundleDataProvider")
RKRankingDataManager = _Class("RKRankingDataManager")
RKProactiveGrammar = _Class("RKProactiveGrammar")
RKEventIdentification = _Class("RKEventIdentification")
RKEventIdentifier = _Class("RKEventIdentifier")
RKMontrealModel = _Class("RKMontrealModel")
RKAssets = _Class("RKAssets")
RKMessageIntentRecognizer = _Class("RKMessageIntentRecognizer")
RKMessageResponseManager = _Class("RKMessageResponseManager")
RKConversationTurn = _Class("RKConversationTurn")
RKResponse = _Class("RKResponse")
RKResponseCandidate = _Class("RKResponseCandidate")
RKText = _Class("RKText")
RKMessage = _Class("RKMessage")
RKTextAnnotation = _Class("RKTextAnnotation")
RKCoreAnalytics = _Class("RKCoreAnalytics")
RKPersistentPersonalizer = _Class("RKPersistentPersonalizer")
RKLinguisticDataProvider = _Class("RKLinguisticDataProvider")
RKAggdStatistics = _Class("RKAggdStatistics")
RKRankLearner = _Class("RKRankLearner")
RKRankedResponse = _Class("RKRankedResponse")
RKResponseCountTimestampRecipient = _Class("RKResponseCountTimestampRecipient")
RKResponseFeatures = _Class("RKResponseFeatures")
RKLexicalEntity = _Class("RKLexicalEntity")
RKClassification = _Class("RKClassification")
RKNLEventTokenizer = _Class("RKNLEventTokenizer")
RKNLEventToken = _Class("RKNLEventToken")
RKResponseCollection = _Class("RKResponseCollection")
_RKResponse = _Class("_RKResponse")
RKSentenceClassifier = _Class("RKSentenceClassifier")
RKSentenceClassifier_hu_HU = _Class("RKSentenceClassifier_hu_HU")
RKSentenceClassifier_id_ID = _Class("RKSentenceClassifier_id_ID")
RKSentenceClassifier_de_DE = _Class("RKSentenceClassifier_de_DE")
RKSentenceClassifier_sv_SE = _Class("RKSentenceClassifier_sv_SE")
RKSentenceClassifier_it_IT = _Class("RKSentenceClassifier_it_IT")
RKSentenceClassifier_hr_HR = _Class("RKSentenceClassifier_hr_HR")
RKSentenceClassifier_ja_JP = _Class("RKSentenceClassifier_ja_JP")
RKSentenceClassifier_ca_ES = _Class("RKSentenceClassifier_ca_ES")
RKSentenceClassifier_da_DK = _Class("RKSentenceClassifier_da_DK")
RKSentenceClassifier_ro_RO = _Class("RKSentenceClassifier_ro_RO")
RKSentenceClassifier_fr_BE = _Class("RKSentenceClassifier_fr_BE")
RKSentenceClassifier_sk_SK = _Class("RKSentenceClassifier_sk_SK")
RKSentenceClassifier_cs_CZ = _Class("RKSentenceClassifier_cs_CZ")
RKSentenceClassifier_ru_RU = _Class("RKSentenceClassifier_ru_RU")
RKSentenceClassifier_nl_BE = _Class("RKSentenceClassifier_nl_BE")
RKSentenceClassifier_pl_PL = _Class("RKSentenceClassifier_pl_PL")
RKSentenceClassifier_ms_MY = _Class("RKSentenceClassifier_ms_MY")
RKSentenceClassifier_pt_BR = _Class("RKSentenceClassifier_pt_BR")
RKSentenceClassifier_zh_Hant_CN = _Class("RKSentenceClassifier_zh_Hant_CN")
RKSentenceClassifier_zh_Hans_CN = _Class("RKSentenceClassifier_zh_Hans_CN")
RKSentenceClassifier_nl_NL = _Class("RKSentenceClassifier_nl_NL")
RKSentenceClassifier_vi_VN = _Class("RKSentenceClassifier_vi_VN")
RKSentenceClassifier_en_US = _Class("RKSentenceClassifier_en_US")
RKSentenceClassifier_he_IL = _Class("RKSentenceClassifier_he_IL")
RKSentenceClassifier_fi_FI = _Class("RKSentenceClassifier_fi_FI")
RKSentenceClassifier_hi_IN = _Class("RKSentenceClassifier_hi_IN")
RKSentenceClassifier_es_ES = _Class("RKSentenceClassifier_es_ES")
RKSentenceClassifier_uk_UA = _Class("RKSentenceClassifier_uk_UA")
RKSentenceClassifier_nb_NO = _Class("RKSentenceClassifier_nb_NO")
RKSentenceClassifier_th_TH = _Class("RKSentenceClassifier_th_TH")
RKSentenceClassifier_ar_AE = _Class("RKSentenceClassifier_ar_AE")
RKSentenceClassifier_el_GR = _Class("RKSentenceClassifier_el_GR")
RKSentenceClassifier_tr_TR = _Class("RKSentenceClassifier_tr_TR")
RKSentenceClassifier_fr_FR = _Class("RKSentenceClassifier_fr_FR")
RKSentenceClassifier_ko_KO = _Class("RKSentenceClassifier_ko_KO")
RankingInfo = _Class("RankingInfo")
RKRankingInfo = _Class("RKRankingInfo")
