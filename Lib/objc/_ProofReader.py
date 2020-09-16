'''
Classes from the 'ProofReader' framework.
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

    
PRAutocorrectionContext = _Class('PRAutocorrectionContext')
PRPinyinContext = _Class('PRPinyinContext')
PRZhuyinContext = _Class('PRZhuyinContext')
PRModification = _Class('PRModification')
PRPinyinModification = _Class('PRPinyinModification')
PRZhuyinModification = _Class('PRZhuyinModification')
PRTurkishSuffix = _Class('PRTurkishSuffix')
PRLexiconCompletion = _Class('PRLexiconCompletion')
PRLexiconCorrection = _Class('PRLexiconCorrection')
PRLexiconCorrectionCursor = _Class('PRLexiconCorrectionCursor')
PRCandidateList = _Class('PRCandidateList')
PRCandidate = _Class('PRCandidate')
PRErrorModel = _Class('PRErrorModel')
PRRecordedCorrection = _Class('PRRecordedCorrection')
PRTypologyRecord = _Class('PRTypologyRecord')
PRTypologyCandidate = _Class('PRTypologyCandidate')
PRTypologyCorrection = _Class('PRTypologyCorrection')
PRLanguageModel = _Class('PRLanguageModel')
PRLexiconCursor = _Class('PRLexiconCursor')
PRLexicon = _Class('PRLexicon')
PRDictionary = _Class('PRDictionary')
PRLanguage = _Class('PRLanguage')
AppleSpell = _Class('AppleSpell')
PRPinyinString = _Class('PRPinyinString')
