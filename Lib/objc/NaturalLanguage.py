"""
Classes from the 'NaturalLanguage' framework.
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


NLEmbedding = _Class("NLEmbedding")
NLXPCSpellServerClient = _Class("NLXPCSpellServerClient")
NLDataEnumerator = _Class("NLDataEnumerator")
NLDataInstanceLocator = _Class("NLDataInstanceLocator")
NLDataInstance = _Class("NLDataInstance")
NLClassifierModelDataInstance = _Class("NLClassifierModelDataInstance")
NLSequenceModelDataInstance = _Class("NLSequenceModelDataInstance")
NLModelConfiguration = _Class("NLModelConfiguration")
NLTokenizer = _Class("NLTokenizer")
NLLogCategory = _Class("NLLogCategory")
NLModelTrainer = _Class("NLModelTrainer")
NLLanguageRecognizer = _Class("NLLanguageRecognizer")
NLCFROLanguageRecognizer = _Class("NLCFROLanguageRecognizer")
NLPModelTrainingDelegate = _Class("NLPModelTrainingDelegate")
NLDataSet = _Class("NLDataSet")
NLModelTrainingDataSet = _Class("NLModelTrainingDataSet")
NLDataProvider = _Class("NLDataProvider")
NLSplitDataProvider = _Class("NLSplitDataProvider")
NLConcatenatedDataProvider = _Class("NLConcatenatedDataProvider")
NLConstrainedDataProvider = _Class("NLConstrainedDataProvider")
NLPModelTrainingDataProvider = _Class("NLPModelTrainingDataProvider")
NLLanguageModel = _Class("NLLanguageModel")
NLTaggerAssetRequest = _Class("NLTaggerAssetRequest")
NLLexicon = _Class("NLLexicon")
NLLexiconCursor = _Class("NLLexiconCursor")
NLLexiconCompletion = _Class("NLLexiconCompletion")
NLLexiconEntry = _Class("NLLexiconEntry")
NLModel = _Class("NLModel")
NLPMLClassifierModel = _Class("NLPMLClassifierModel")
NLPMLSequenceModel = _Class("NLPMLSequenceModel")
NLClassifierModel = _Class("NLClassifierModel")
NLSequenceModel = _Class("NLSequenceModel")
NLGazetteer = _Class("NLGazetteer")
NLModelImpl = _Class("NLModelImpl")
NLModelImplE = _Class("NLModelImplE")
NLModelImplX = _Class("NLModelImplX")
NLModelImplM = _Class("NLModelImplM")
NLModelImplNX = _Class("NLModelImplNX")
NLModelImplN = _Class("NLModelImplN")
NLModelImplLC = _Class("NLModelImplLC")
NLModelImplL = _Class("NLModelImplL")
NLModelImplG = _Class("NLModelImplG")
NLModelImplML = _Class("NLModelImplML")
NLNumberGenerator = _Class("NLNumberGenerator")
NLTagger = _Class("NLTagger")
