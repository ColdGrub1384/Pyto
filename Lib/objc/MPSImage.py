"""
Classes from the 'MPSImage' framework.
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


MPSImageSpatioTemporalGuidedFilterDescriptor = _Class(
    "MPSImageSpatioTemporalGuidedFilterDescriptor"
)
MPSImageFindKeypoints = _Class("MPSImageFindKeypoints")
MPSMatrixCopyToImage = _Class("MPSMatrixCopyToImage")
MPSImageCopyToMatrix = _Class("MPSImageCopyToMatrix")
MPSImageNormalizedHistogram = _Class("MPSImageNormalizedHistogram")
MPSImageGuidedFilter = _Class("MPSImageGuidedFilter")
MPSImageHistogram = _Class("MPSImageHistogram")
MPSBinaryImageKernel = _Class("MPSBinaryImageKernel")
MPSImageArithmetic = _Class("MPSImageArithmetic")
MPSImageDivide = _Class("MPSImageDivide")
MPSImageMultiply = _Class("MPSImageMultiply")
MPSImageSubtract = _Class("MPSImageSubtract")
MPSImageAdd = _Class("MPSImageAdd")
MPSImageEDLines = _Class("MPSImageEDLines")
MPSUnaryImageKernel = _Class("MPSUnaryImageKernel")
MPSImageHistogramSpecification = _Class("MPSImageHistogramSpecification")
MPSImageStatisticsMean = _Class("MPSImageStatisticsMean")
MPSImageStatisticsMeanAndVariance = _Class("MPSImageStatisticsMeanAndVariance")
MPSImageStatisticsMinAndMax = _Class("MPSImageStatisticsMinAndMax")
MPSImageScreenTelemetry = _Class("MPSImageScreenTelemetry")
MPSImageThresholdToZeroInverse = _Class("MPSImageThresholdToZeroInverse")
MPSImageThresholdToZero = _Class("MPSImageThresholdToZero")
MPSImageThresholdTruncate = _Class("MPSImageThresholdTruncate")
MPSImageThresholdBinaryInverse = _Class("MPSImageThresholdBinaryInverse")
MPSImageThresholdBinary = _Class("MPSImageThresholdBinary")
MPSImageGaussianBlur = _Class("MPSImageGaussianBlur")
MPSImageIntegral = _Class("MPSImageIntegral")
MPSImageBox3D = _Class("MPSImageBox3D")
MPSImageMedian = _Class("MPSImageMedian")
MPSImageConversion = _Class("MPSImageConversion")
MPSImageHistogramEqualization = _Class("MPSImageHistogramEqualization")
MPSImageEuclideanDistanceTransform = _Class("MPSImageEuclideanDistanceTransform")
MPSImageTranspose = _Class("MPSImageTranspose")
MPSImageBox = _Class("MPSImageBox")
MPSImageTent = _Class("MPSImageTent")
MPSImageSobel = _Class("MPSImageSobel")
MPSImageDilate = _Class("MPSImageDilate")
MPSImageErode = _Class("MPSImageErode")
MPSImageAreaMax = _Class("MPSImageAreaMax")
MPSImageAreaMin = _Class("MPSImageAreaMin")
MPSImageScale = _Class("MPSImageScale")
MPSImageLanczosScale = _Class("MPSImageLanczosScale")
MPSImageBilinearScale = _Class("MPSImageBilinearScale")
MPSImageCanny = _Class("MPSImageCanny")
MPSImageReduceUnary = _Class("MPSImageReduceUnary")
MPSImageReduceColumnSum = _Class("MPSImageReduceColumnSum")
MPSImageReduceRowSum = _Class("MPSImageReduceRowSum")
MPSImageReduceColumnMean = _Class("MPSImageReduceColumnMean")
MPSImageReduceRowMean = _Class("MPSImageReduceRowMean")
MPSImageReduceColumnMax = _Class("MPSImageReduceColumnMax")
MPSImageReduceRowMax = _Class("MPSImageReduceRowMax")
MPSImageReduceColumnMin = _Class("MPSImageReduceColumnMin")
MPSImageReduceRowMin = _Class("MPSImageReduceRowMin")
MPSImageConvolution = _Class("MPSImageConvolution")
MPSImageLaplacian = _Class("MPSImageLaplacian")
MPSImageIntegralOfSquares = _Class("MPSImageIntegralOfSquares")
MPSImagePyramid = _Class("MPSImagePyramid")
MPSImageGaussianPyramid = _Class("MPSImageGaussianPyramid")
MPSImageLaplacianPyramid = _Class("MPSImageLaplacianPyramid")
MPSImageLaplacianPyramidSubtract = _Class("MPSImageLaplacianPyramidSubtract")
MPSImageLaplacianPyramidAdd = _Class("MPSImageLaplacianPyramidAdd")
MPSImageSpatioTemporalGuidedFilter = _Class("MPSImageSpatioTemporalGuidedFilter")
