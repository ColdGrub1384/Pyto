'''
Classes from the 'CVNLP' framework.
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

    
CVNLPTextDecodingContext = _Class('CVNLPTextDecodingContext')
CVNLPDecodingLexicon = _Class('CVNLPDecodingLexicon')
CVNLPCaptionRuntimeReplacements = _Class('CVNLPCaptionRuntimeReplacements')
CVNLPCaptionRuntimeExcludeGenderTrigger = _Class('CVNLPCaptionRuntimeExcludeGenderTrigger')
CVNLPCTCBeamState = _Class('CVNLPCTCBeamState')
CVNLPTextDecodingPath = _Class('CVNLPTextDecodingPath')
CVNLPCTCTextDecodingPath = _Class('CVNLPCTCTextDecodingPath')
CVNLPCaptionPerformance = _Class('CVNLPCaptionPerformance')
CVNLPCaptionPerformanceResult = _Class('CVNLPCaptionPerformanceResult')
CVNLPTokenIDConverter = _Class('CVNLPTokenIDConverter')
CVNLPTextDecoderUtilities = _Class('CVNLPTextDecoderUtilities')
CVNLPTextDecodingResult = _Class('CVNLPTextDecodingResult')
CVNLPTextDecodingResultCandidate = _Class('CVNLPTextDecodingResultCandidate')
CVNLPCaptionRuntimeParameters = _Class('CVNLPCaptionRuntimeParameters')
CVNLPTextDecoder = _Class('CVNLPTextDecoder')
CVNLPCTCTextDecoder = _Class('CVNLPCTCTextDecoder')
CVNLPTextDecodingConfiguration = _Class('CVNLPTextDecodingConfiguration')
CVNLPTextDecodingBeamSearchConfiguration = _Class('CVNLPTextDecodingBeamSearchConfiguration')
BundleHelper = _Class('BundleHelper')
CVNLPCaptionPostProcessingHandler = _Class('CVNLPCaptionPostProcessingHandler')
CVNLPLexiconCursors = _Class('CVNLPLexiconCursors')
CVNLPLexiconCursor = _Class('CVNLPLexiconCursor')
CVNLPActivationMatrix = _Class('CVNLPActivationMatrix')
CVNLPCaptionModelBase = _Class('CVNLPCaptionModelBase')
CVNLPVisionRequestHandler = _Class('CVNLPVisionRequestHandler')
CVNLPCaptionDecoderBlock = _Class('CVNLPCaptionDecoderBlock')
CVNLPCaptionDecoder = _Class('CVNLPCaptionDecoder')
CVNLPCaptionDecoderLSTM = _Class('CVNLPCaptionDecoderLSTM')
CVNLPCaptionDecoderTransformer = _Class('CVNLPCaptionDecoderTransformer')
CVNLPCaptionEncoder = _Class('CVNLPCaptionEncoder')
CVNLPCaptionEncoderTransformer = _Class('CVNLPCaptionEncoderTransformer')
CVNLPCaptionEncoderLSTM = _Class('CVNLPCaptionEncoderLSTM')
CVNLPLanguageResourceBundle = _Class('CVNLPLanguageResourceBundle')
CVNLPInformationStream = _Class('CVNLPInformationStream')
CVNLPDecodingLexicons = _Class('CVNLPDecodingLexicons')
CVNLPDecodingLanguageModel = _Class('CVNLPDecodingLanguageModel')
CVNLPCaptionSensitiveImageParameters = _Class('CVNLPCaptionSensitiveImageParameters')
CVNLPTextDecodingToken = _Class('CVNLPTextDecodingToken')
