'''
Classes from the 'Montreal' framework.
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

    
MLPInferenceResult = _Class('MLPInferenceResult')
MLPModelConvolutionDataSource = _Class('MLPModelConvolutionDataSource')
MontrealNNGenerateModel = _Class('MontrealNNGenerateModel')
MontrealNNGenerateNode = _Class('MontrealNNGenerateNode')
MLPNDArrayLossLabels = _Class('MLPNDArrayLossLabels')
MLPDeviceHandler = _Class('MLPDeviceHandler')
MLPLearningRateDecayHandler = _Class('MLPLearningRateDecayHandler')
MLPOptimizer = _Class('MLPOptimizer')
MLPOptimizerSGD = _Class('MLPOptimizerSGD')
MLPOptimizerAdam = _Class('MLPOptimizerAdam')
MLPModelLSTMDataSource = _Class('MLPModelLSTMDataSource')
MontrealModelJSONParser = _Class('MontrealModelJSONParser')
MLPDataBatch = _Class('MLPDataBatch')
MLPImageDataBatch = _Class('MLPImageDataBatch')
MLPSeqDataBatch = _Class('MLPSeqDataBatch')
MLPData = _Class('MLPData')
MLPNetwork = _Class('MLPNetwork')
MLPCNNNetwork = _Class('MLPCNNNetwork')
MLPSeqNetwork = _Class('MLPSeqNetwork')
MontrealLogIndent = _Class('MontrealLogIndent')
MLPLayer = _Class('MLPLayer')
MLPLSTMLayer = _Class('MLPLSTMLayer')
MLPEmbeddingLayer = _Class('MLPEmbeddingLayer')
MLPMatrixLayer = _Class('MLPMatrixLayer')
MLPDenseLayer = _Class('MLPDenseLayer')
MLPImageLayer = _Class('MLPImageLayer')
MLPLossLayer = _Class('MLPLossLayer')
MLPDropoutLayer = _Class('MLPDropoutLayer')
MLPConvolutionBase = _Class('MLPConvolutionBase')
MLPConvolutionLayer = _Class('MLPConvolutionLayer')
MLPPoolingLayer = _Class('MLPPoolingLayer')
MontrealNNDescription = _Class('MontrealNNDescription')
MontrealNNModelWeight = _Class('MontrealNNModelWeight')
MontrealNNModelNetwork = _Class('MontrealNNModelNetwork')
MontrealNNModelOptimizerParam = _Class('MontrealNNModelOptimizerParam')
MontrealNNModelTensor = _Class('MontrealNNModelTensor')
MontrealNNModelNode = _Class('MontrealNNModelNode')
MontrealNNModelQuantization = _Class('MontrealNNModelQuantization')
