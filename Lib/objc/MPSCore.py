"""
Classes from the 'MPSCore' framework.
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


MPSWorkloadStatistics = _Class("MPSWorkloadStatistics")
MPSCommandBuffer = _Class("MPSCommandBuffer")
MPSPredicatedCommandEncoder = _Class("MPSPredicatedCommandEncoder")
MPSPredicate = _Class("MPSPredicate")
MPSParallelRandomMTGP32State = _Class("MPSParallelRandomMTGP32State")
MPSParallelRandomDistributionDescriptor = _Class(
    "MPSParallelRandomDistributionDescriptor"
)
MPSImage = _Class("MPSImage")
MPSVirtualImage = _Class("MPSVirtualImage")
MPSTemporaryImage = _Class("MPSTemporaryImage")
MPSImageDescriptor = _Class("MPSImageDescriptor")
MPSImageDefaultAllocator = _Class("MPSImageDefaultAllocator")
MPSTemporaryImageDefaultAllocator = _Class("MPSTemporaryImageDefaultAllocator")
MPSCommandBufferImageCache = _Class("MPSCommandBufferImageCache")
MPSState = _Class("MPSState")
MPSStateResourceList = _Class("MPSStateResourceList")
MPSVector = _Class("MPSVector")
MPSTemporaryVector = _Class("MPSTemporaryVector")
MPSMatrix = _Class("MPSMatrix")
MPSTemporaryMatrix = _Class("MPSTemporaryMatrix")
MPSVectorDescriptor = _Class("MPSVectorDescriptor")
MPSMatrixDescriptor = _Class("MPSMatrixDescriptor")
MPSKernel = _Class("MPSKernel")
MPSParallelReduce = _Class("MPSParallelReduce")
MPSParallelReduceArgMax = _Class("MPSParallelReduceArgMax")
MPSParallelReduceArgMin = _Class("MPSParallelReduceArgMin")
MPSParallelReduceMax = _Class("MPSParallelReduceMax")
MPSParallelReduceMin = _Class("MPSParallelReduceMin")
MPSParallelReduceSum = _Class("MPSParallelReduceSum")
MPSParallelRandom = _Class("MPSParallelRandom")
MPSParallelRandomPhilox = _Class("MPSParallelRandomPhilox")
MPSParallelRandomMTGP32 = _Class("MPSParallelRandomMTGP32")
MPSParallelSort = _Class("MPSParallelSort")
MPSParallelRadixSort = _Class("MPSParallelRadixSort")
MPSParallelScan = _Class("MPSParallelScan")
MPSParallelInclusiveScan = _Class("MPSParallelInclusiveScan")
MPSParallelExclusiveScan = _Class("MPSParallelExclusiveScan")
MPSNDArray = _Class("MPSNDArray")
MPSTemporaryNDArray = _Class("MPSTemporaryNDArray")
MPSNDArrayDefaultAllocator = _Class("MPSNDArrayDefaultAllocator")
MPSTemporaryNDArrayDefaultAllocator = _Class("MPSTemporaryNDArrayDefaultAllocator")
MPSNDArrayDescriptor = _Class("MPSNDArrayDescriptor")
MPSExternalPluginBase = _Class("MPSExternalPluginBase")
MPSKernelDAGObject = _Class("MPSKernelDAGObject")
MPSComputeEncoder = _Class("MPSComputeEncoder")
MPSKeyedUnarchiver = _Class("MPSKeyedUnarchiver")
