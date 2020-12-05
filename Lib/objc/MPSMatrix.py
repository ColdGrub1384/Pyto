"""
Classes from the 'MPSMatrix' framework.
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


MPSMatrixRandomDistributionDescriptor = _Class("MPSMatrixRandomDistributionDescriptor")
MPSMatrixCopyDescriptor = _Class("MPSMatrixCopyDescriptor")
MPSMatrixRandom = _Class("MPSMatrixRandom")
MPSMatrixRandomPhilox = _Class("MPSMatrixRandomPhilox")
MPSMatrixRandomMTGP32 = _Class("MPSMatrixRandomMTGP32")
MPSMatrixCopy = _Class("MPSMatrixCopy")
MPSMatrixUnaryKernel = _Class("MPSMatrixUnaryKernel")
MPSMatrixDecompositionLU = _Class("MPSMatrixDecompositionLU")
MPSMatrixSoftMax = _Class("MPSMatrixSoftMax")
MPSMatrixLogSoftMax = _Class("MPSMatrixLogSoftMax")
MPSMatrixFindTopK = _Class("MPSMatrixFindTopK")
MPSMatrixDecompositionCholesky = _Class("MPSMatrixDecompositionCholesky")
MPSMatrixBinaryKernel = _Class("MPSMatrixBinaryKernel")
MPSMatrixVectorMultiplication = _Class("MPSMatrixVectorMultiplication")
MPSMatrixSolveCholesky = _Class("MPSMatrixSolveCholesky")
MPSMatrixSolveLU = _Class("MPSMatrixSolveLU")
MPSMatrixSolveTriangular = _Class("MPSMatrixSolveTriangular")
MPSMatrixSoftMaxGradient = _Class("MPSMatrixSoftMaxGradient")
MPSMatrixLogSoftMaxGradient = _Class("MPSMatrixLogSoftMaxGradient")
MPSMatrixMultiplication = _Class("MPSMatrixMultiplication")
