"""
Classes from the 'Metal' framework.
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


MTLCommandQueueSPIStats = _Class("MTLCommandQueueSPIStats")
MTLCommandQueueDescriptor = _Class("MTLCommandQueueDescriptor")
MTLCommandQueueDescriptorInternal = _Class("MTLCommandQueueDescriptorInternal")
MTLVertexDescriptor = _Class("MTLVertexDescriptor")
MTLVertexDescriptorInternal = _Class("MTLVertexDescriptorInternal")
MTLVertexAttributeDescriptorArray = _Class("MTLVertexAttributeDescriptorArray")
MTLVertexAttributeDescriptorArrayInternal = _Class(
    "MTLVertexAttributeDescriptorArrayInternal"
)
MTLVertexAttributeDescriptor = _Class("MTLVertexAttributeDescriptor")
MTLVertexAttributeDescriptorInternal = _Class("MTLVertexAttributeDescriptorInternal")
MTLVertexBufferLayoutDescriptorArray = _Class("MTLVertexBufferLayoutDescriptorArray")
MTLVertexBufferLayoutDescriptorArrayInternal = _Class(
    "MTLVertexBufferLayoutDescriptorArrayInternal"
)
MTLVertexBufferLayoutDescriptor = _Class("MTLVertexBufferLayoutDescriptor")
MTLVertexBufferLayoutDescriptorInternal = _Class(
    "MTLVertexBufferLayoutDescriptorInternal"
)
MTLCommandBufferDescriptor = _Class("MTLCommandBufferDescriptor")
_MTLCommandBufferEncoderInfo = _Class("_MTLCommandBufferEncoderInfo")
_MTLDepthStencilState = _Class("_MTLDepthStencilState")
MTLDepthStencilDescriptor = _Class("MTLDepthStencilDescriptor")
MTLDepthStencilDescriptorInternal = _Class("MTLDepthStencilDescriptorInternal")
MTLStencilDescriptor = _Class("MTLStencilDescriptor")
MTLStencilDescriptorInternal = _Class("MTLStencilDescriptorInternal")
MTLFunctionDescriptor = _Class("MTLFunctionDescriptor")
MTLIntersectionFunctionDescriptor = _Class("MTLIntersectionFunctionDescriptor")
MTLSharedEventListener = _Class("MTLSharedEventListener")
MTLSharedEventListenerInternal = _Class("MTLSharedEventListenerInternal")
MTLSharedEventHandle = _Class("MTLSharedEventHandle")
MTLBlitPassDescriptor = _Class("MTLBlitPassDescriptor")
MTLBlitPassDescriptorInternal = _Class("MTLBlitPassDescriptorInternal")
MTLBlitPassSampleBufferAttachmentDescriptorArray = _Class(
    "MTLBlitPassSampleBufferAttachmentDescriptorArray"
)
MTLBlitPassSampleBufferAttachmentDescriptorArrayInternal = _Class(
    "MTLBlitPassSampleBufferAttachmentDescriptorArrayInternal"
)
MTLBlitPassSampleBufferAttachmentDescriptor = _Class(
    "MTLBlitPassSampleBufferAttachmentDescriptor"
)
MTLBlitPassSampleBufferAttachmentDescriptorInternal = _Class(
    "MTLBlitPassSampleBufferAttachmentDescriptorInternal"
)
MTLResourceAllocationInfo = _Class("MTLResourceAllocationInfo")
MTLResourceList = _Class("MTLResourceList")
MTLIOAccelDeviceShmemPool = _Class("MTLIOAccelDeviceShmemPool")
MTLLinkedFunctions = _Class("MTLLinkedFunctions")
MTLLinkedFunctionsInternal = _Class("MTLLinkedFunctionsInternal")
_MTLRenderPipelineState = _Class("_MTLRenderPipelineState")
MTLRenderPipelineDescriptor = _Class("MTLRenderPipelineDescriptor")
MTLRenderPipelineDescriptorInternal = _Class("MTLRenderPipelineDescriptorInternal")
MTLRenderPipelineColorAttachmentDescriptorArray = _Class(
    "MTLRenderPipelineColorAttachmentDescriptorArray"
)
MTLRenderPipelineColorAttachmentDescriptorArrayInternal = _Class(
    "MTLRenderPipelineColorAttachmentDescriptorArrayInternal"
)
MTLRenderPipelineReflection = _Class("MTLRenderPipelineReflection")
MTLRenderPipelineReflectionInternal = _Class("MTLRenderPipelineReflectionInternal")
MTLRenderPipelineColorAttachmentDescriptor = _Class(
    "MTLRenderPipelineColorAttachmentDescriptor"
)
MTLRenderPipelineColorAttachmentDescriptorInternal = _Class(
    "MTLRenderPipelineColorAttachmentDescriptorInternal"
)
_MTLMessageNotifier = _Class("_MTLMessageNotifier")
MTLMessage = _Class("MTLMessage")
MTLMessageFilter = _Class("MTLMessageFilter")
MTLInferredInput = _Class("MTLInferredInput")
MTLPostVertexDumpOutput = _Class("MTLPostVertexDumpOutput")
MTLStructMember = _Class("MTLStructMember")
MTLStructMemberInternal = _Class("MTLStructMemberInternal")
MTLType = _Class("MTLType")
MTLArrayType = _Class("MTLArrayType")
MTLArrayTypeInternal = _Class("MTLArrayTypeInternal")
MTLTextureReferenceType = _Class("MTLTextureReferenceType")
MTLTextureReferenceTypeInternal = _Class("MTLTextureReferenceTypeInternal")
MTLPointerType = _Class("MTLPointerType")
MTLPointerTypeInternal = _Class("MTLPointerTypeInternal")
MTLTypeInternal = _Class("MTLTypeInternal")
MTLStructType = _Class("MTLStructType")
MTLStructTypeInternal = _Class("MTLStructTypeInternal")
MTLResourceStatePassDescriptor = _Class("MTLResourceStatePassDescriptor")
MTLResourceStatePassDescriptorInternal = _Class(
    "MTLResourceStatePassDescriptorInternal"
)
MTLResourceStatePassSampleBufferAttachmentDescriptorArray = _Class(
    "MTLResourceStatePassSampleBufferAttachmentDescriptorArray"
)
MTLResourceStatePassSampleBufferAttachmentDescriptorArrayInternal = _Class(
    "MTLResourceStatePassSampleBufferAttachmentDescriptorArrayInternal"
)
MTLResourceStatePassSampleBufferAttachmentDescriptor = _Class(
    "MTLResourceStatePassSampleBufferAttachmentDescriptor"
)
MTLResourceStatePassSampleBufferAttachmentDescriptorInternal = _Class(
    "MTLResourceStatePassSampleBufferAttachmentDescriptorInternal"
)
_MTLComputePipelineState = _Class("_MTLComputePipelineState")
MTLComputePipelineDescriptor = _Class("MTLComputePipelineDescriptor")
MTLComputePipelineDescriptorInternal = _Class("MTLComputePipelineDescriptorInternal")
MTLComputePipelineReflection = _Class("MTLComputePipelineReflection")
MTLComputePipelineReflectionInternal = _Class("MTLComputePipelineReflectionInternal")
MTLRenderPassDescriptor = _Class("MTLRenderPassDescriptor")
MTLRenderPassDescriptorInternal = _Class("MTLRenderPassDescriptorInternal")
MTLRenderPassSampleBufferAttachmentDescriptorArray = _Class(
    "MTLRenderPassSampleBufferAttachmentDescriptorArray"
)
MTLRenderPassSampleBufferAttachmentDescriptorArrayInternal = _Class(
    "MTLRenderPassSampleBufferAttachmentDescriptorArrayInternal"
)
MTLRenderPassSampleBufferAttachmentDescriptor = _Class(
    "MTLRenderPassSampleBufferAttachmentDescriptor"
)
MTLRenderPassSampleBufferAttachmentDescriptorInternal = _Class(
    "MTLRenderPassSampleBufferAttachmentDescriptorInternal"
)
MTLRenderPassColorAttachmentDescriptorArray = _Class(
    "MTLRenderPassColorAttachmentDescriptorArray"
)
MTLRenderPassColorAttachmentDescriptorArrayInternal = _Class(
    "MTLRenderPassColorAttachmentDescriptorArrayInternal"
)
MTLRenderPassAttachmentDescriptor = _Class("MTLRenderPassAttachmentDescriptor")
MTLRenderPassStencilAttachmentDescriptor = _Class(
    "MTLRenderPassStencilAttachmentDescriptor"
)
MTLRenderPassStencilAttachmentDescriptorInternal = _Class(
    "MTLRenderPassStencilAttachmentDescriptorInternal"
)
MTLRenderPassDepthAttachmentDescriptor = _Class(
    "MTLRenderPassDepthAttachmentDescriptor"
)
MTLRenderPassDepthAttachmentDescriptorInternal = _Class(
    "MTLRenderPassDepthAttachmentDescriptorInternal"
)
MTLRenderPassColorAttachmentDescriptor = _Class(
    "MTLRenderPassColorAttachmentDescriptor"
)
MTLRenderPassColorAttachmentDescriptorInternal = _Class(
    "MTLRenderPassColorAttachmentDescriptorInternal"
)
MTLFunctionVariant = _Class("MTLFunctionVariant")
MTLFunctionReflection = _Class("MTLFunctionReflection")
MTLFunctionReflectionInternal = _Class("MTLFunctionReflectionInternal")
MTLFunctionConstant = _Class("MTLFunctionConstant")
MTLFunctionConstantInternal = _Class("MTLFunctionConstantInternal")
MTLAttribute = _Class("MTLAttribute")
MTLAttributeInternal = _Class("MTLAttributeInternal")
MTLVertexAttribute = _Class("MTLVertexAttribute")
MTLVertexAttributeInternal = _Class("MTLVertexAttributeInternal")
MTLCompileFunctionRequestData = _Class("MTLCompileFunctionRequestData")
MTLCompileOptions = _Class("MTLCompileOptions")
MTLCompileOptionsInternal = _Class("MTLCompileOptionsInternal")
MTLVisibleFunctionTableDescriptor = _Class("MTLVisibleFunctionTableDescriptor")
MTLVisibleFunctionTableDescriptorInternal = _Class(
    "MTLVisibleFunctionTableDescriptorInternal"
)
MTLHeapDescriptor = _Class("MTLHeapDescriptor")
MTLHeapDescriptorInternal = _Class("MTLHeapDescriptorInternal")
MTLTargetDeviceArchitecture = _Class("MTLTargetDeviceArchitecture")
MTLLoadedFile = _Class("MTLLoadedFile")
_MTLSamplerState = _Class("_MTLSamplerState")
MTLSamplerDescriptor = _Class("MTLSamplerDescriptor")
MTLSamplerDescriptorInternal = _Class("MTLSamplerDescriptorInternal")
MTLCaptureManager = _Class("MTLCaptureManager")
MTLCaptureDescriptor = _Class("MTLCaptureDescriptor")
MTLIOAccelTextureLayout = _Class("MTLIOAccelTextureLayout")
_MTLIndirectRenderCommand = _Class("_MTLIndirectRenderCommand")
MTLIOAccelIndirectRenderCommand = _Class("MTLIOAccelIndirectRenderCommand")
MTLIndirectCommandBufferDescriptor = _Class("MTLIndirectCommandBufferDescriptor")
MTLIndirectCommandBufferDescriptorInternal = _Class(
    "MTLIndirectCommandBufferDescriptorInternal"
)
MTLTextureDescriptor = _Class("MTLTextureDescriptor")
MTLTextureDescriptorInternal = _Class("MTLTextureDescriptorInternal")
MTLSharedTextureHandle = _Class("MTLSharedTextureHandle")
MTLCounterSampleBufferDescriptor = _Class("MTLCounterSampleBufferDescriptor")
MTLCounterSampleBufferDescriptorInternal = _Class(
    "MTLCounterSampleBufferDescriptorInternal"
)
MTLCounterSetInternal = _Class("MTLCounterSetInternal")
MTLCounterInternal = _Class("MTLCounterInternal")
MTLComputePassDescriptor = _Class("MTLComputePassDescriptor")
MTLComputePassDescriptorInternal = _Class("MTLComputePassDescriptorInternal")
MTLComputePassSampleBufferAttachmentDescriptorArray = _Class(
    "MTLComputePassSampleBufferAttachmentDescriptorArray"
)
MTLComputePassSampleBufferAttachmentDescriptorArrayInternal = _Class(
    "MTLComputePassSampleBufferAttachmentDescriptorArrayInternal"
)
MTLComputePassSampleBufferAttachmentDescriptor = _Class(
    "MTLComputePassSampleBufferAttachmentDescriptor"
)
MTLComputePassSampleBufferAttachmentDescriptorInternal = _Class(
    "MTLComputePassSampleBufferAttachmentDescriptorInternal"
)
MTLIntersectionFunctionTableDescriptor = _Class(
    "MTLIntersectionFunctionTableDescriptor"
)
MTLIntersectionFunctionTableDescriptorInternal = _Class(
    "MTLIntersectionFunctionTableDescriptorInternal"
)
MTLArgumentDescriptor = _Class("MTLArgumentDescriptor")
MTLArgumentDescriptorInternal = _Class("MTLArgumentDescriptorInternal")
MTLIndirectArgumentDescriptor = _Class("MTLIndirectArgumentDescriptor")
MTLIndirectArgumentDescriptorInternal = _Class("MTLIndirectArgumentDescriptorInternal")
MTLDebugInstrumentationData = _Class("MTLDebugInstrumentationData")
MTLDebugSubProgram = _Class("MTLDebugSubProgram")
MTLDebugLocation = _Class("MTLDebugLocation")
MTLPipelineBufferDescriptorArray = _Class("MTLPipelineBufferDescriptorArray")
MTLPipelineBufferDescriptorArrayInternal = _Class(
    "MTLPipelineBufferDescriptorArrayInternal"
)
MTLPipelineBufferDescriptor = _Class("MTLPipelineBufferDescriptor")
MTLPipelineBufferDescriptorInternal = _Class("MTLPipelineBufferDescriptorInternal")
MTLArgument = _Class("MTLArgument")
MTLArgumentInternal = _Class("MTLArgumentInternal")
MTLIndirectConstantArgument = _Class("MTLIndirectConstantArgument")
MTLImageBlockArgument = _Class("MTLImageBlockArgument")
MTLImageBlockDataArgument = _Class("MTLImageBlockDataArgument")
MTLBuiltInArgument = _Class("MTLBuiltInArgument")
MTLTextureArgument = _Class("MTLTextureArgument")
MTLThreadgroupMemoryArgument = _Class("MTLThreadgroupMemoryArgument")
MTLBufferArgument = _Class("MTLBufferArgument")
MTLIOAccelResourcePool = _Class("MTLIOAccelResourcePool")
MTLDynamicLibraryContainer = _Class("MTLDynamicLibraryContainer")
MTLFunctionConstantValues = _Class("MTLFunctionConstantValues")
MTLFunctionConstantValuesInternal = _Class("MTLFunctionConstantValuesInternal")
MTLIndexedConstantValue = _Class("MTLIndexedConstantValue")
MTLNamedConstantValue = _Class("MTLNamedConstantValue")
MTLAccelerationStructureGeometryDescriptor = _Class(
    "MTLAccelerationStructureGeometryDescriptor"
)
MTLAccelerationStructureBoundingBoxGeometryDescriptor = _Class(
    "MTLAccelerationStructureBoundingBoxGeometryDescriptor"
)
MTLAccelerationStructureTriangleGeometryDescriptor = _Class(
    "MTLAccelerationStructureTriangleGeometryDescriptor"
)
MTLAccelerationStructureDescriptor = _Class("MTLAccelerationStructureDescriptor")
MTLInstanceAccelerationStructureDescriptor = _Class(
    "MTLInstanceAccelerationStructureDescriptor"
)
MTLPrimitiveAccelerationStructureDescriptor = _Class(
    "MTLPrimitiveAccelerationStructureDescriptor"
)
_MTLFunctionHandle = _Class("_MTLFunctionHandle")
_MTLIndirectDispatchThreadsArguments = _Class("_MTLIndirectDispatchThreadsArguments")
_MTLImageBlockArguments = _Class("_MTLImageBlockArguments")
_MTLIndirectDispatchThreadgroupsArguments = _Class(
    "_MTLIndirectDispatchThreadgroupsArguments"
)
_MTLIndirectTessellationFactorArguments = _Class(
    "_MTLIndirectTessellationFactorArguments"
)
_MTLIndirectDrawIndexedPatchesArguments = _Class(
    "_MTLIndirectDrawIndexedPatchesArguments"
)
_MTLIndirectDrawPatchesArguments = _Class("_MTLIndirectDrawPatchesArguments")
_MTLIndirectDrawIndexedArguments = _Class("_MTLIndirectDrawIndexedArguments")
_MTLIndirectDrawArguments = _Class("_MTLIndirectDrawArguments")
_MTLRasterizationRateMap = _Class("_MTLRasterizationRateMap")
MTLRasterizationRateMapDescriptor = _Class("MTLRasterizationRateMapDescriptor")
MTLRasterizationRateMapDescriptorInternal = _Class(
    "MTLRasterizationRateMapDescriptorInternal"
)
MTLRasterizationRateLayerArray = _Class("MTLRasterizationRateLayerArray")
MTLRasterizationRateLayerArrayInternal = _Class(
    "MTLRasterizationRateLayerArrayInternal"
)
MTLRasterizationRateLayerDescriptor = _Class("MTLRasterizationRateLayerDescriptor")
MTLRasterizationRateLayerDescriptorInternal = _Class(
    "MTLRasterizationRateLayerDescriptorInternal"
)
MTLRasterizationRateSampleArray = _Class("MTLRasterizationRateSampleArray")
MTLRasterizationRateSampleArrayInternal = _Class(
    "MTLRasterizationRateSampleArrayInternal"
)
MTLBinaryEntry = _Class("MTLBinaryEntry")
MTLBinaryKey = _Class("MTLBinaryKey")
MTLBinaryArchiveDescriptor = _Class("MTLBinaryArchiveDescriptor")
MTLIndirectArgumentBufferEmulationData = _Class(
    "MTLIndirectArgumentBufferEmulationData"
)
_MTLIndirectArgumentBufferLayout = _Class("_MTLIndirectArgumentBufferLayout")
MTLEmulationIndirectArgumentBufferLayout = _Class(
    "MTLEmulationIndirectArgumentBufferLayout"
)
MTLBVHBuilder = _Class("MTLBVHBuilder")
MTLGPUBVHBuilder = _Class("MTLGPUBVHBuilder")
MTLBVHDescriptor = _Class("MTLBVHDescriptor")
MTLBVHGeometryDescriptor = _Class("MTLBVHGeometryDescriptor")
MTLBVHBoundingBoxGeometryDescriptor = _Class("MTLBVHBoundingBoxGeometryDescriptor")
MTLBVHPolygonGeometryDescriptor = _Class("MTLBVHPolygonGeometryDescriptor")
MTLIOAccelDeviceShmem = _Class("MTLIOAccelDeviceShmem")
MTLStageInputOutputDescriptor = _Class("MTLStageInputOutputDescriptor")
MTLStageInputOutputDescriptorInternal = _Class("MTLStageInputOutputDescriptorInternal")
MTLAttributeDescriptorArray = _Class("MTLAttributeDescriptorArray")
MTLAttributeDescriptorArrayInternal = _Class("MTLAttributeDescriptorArrayInternal")
MTLAttributeDescriptor = _Class("MTLAttributeDescriptor")
MTLAttributeDescriptorInternal = _Class("MTLAttributeDescriptorInternal")
MTLBufferLayoutDescriptorArray = _Class("MTLBufferLayoutDescriptorArray")
MTLBufferLayoutDescriptorArrayInternal = _Class(
    "MTLBufferLayoutDescriptorArrayInternal"
)
MTLBufferLayoutDescriptor = _Class("MTLBufferLayoutDescriptor")
MTLBufferLayoutDescriptorInternal = _Class("MTLBufferLayoutDescriptorInternal")
_MTLFunctionLogDebugLocation = _Class("_MTLFunctionLogDebugLocation")
MTLTileRenderPipelineDescriptor = _Class("MTLTileRenderPipelineDescriptor")
MTLTileRenderPipelineDescriptorInternal = _Class(
    "MTLTileRenderPipelineDescriptorInternal"
)
MTLTileRenderPipelineColorAttachmentDescriptorArray = _Class(
    "MTLTileRenderPipelineColorAttachmentDescriptorArray"
)
MTLTileRenderPipelineColorAttachmentDescriptorArrayInternal = _Class(
    "MTLTileRenderPipelineColorAttachmentDescriptorArrayInternal"
)
MTLTileRenderPipelineColorAttachmentDescriptor = _Class(
    "MTLTileRenderPipelineColorAttachmentDescriptor"
)
MTLTileRenderPipelineColorAttachmentDescriptorInternal = _Class(
    "MTLTileRenderPipelineColorAttachmentDescriptorInternal"
)
_MTLIndirectComputeCommand = _Class("_MTLIndirectComputeCommand")
MTLIOAccelIndirectComputeCommand = _Class("MTLIOAccelIndirectComputeCommand")
_PipelineLibrarySerializer = _Class("_PipelineLibrarySerializer")
_MTLIOAccelMTLEvent = _Class("_MTLIOAccelMTLEvent")
_MTLSharedEvent = _Class("_MTLSharedEvent")
MTLDeviceFeatureQueries = _Class("MTLDeviceFeatureQueries")
_MTLDeviceFeatureQueries = _Class("_MTLDeviceFeatureQueries")
MTLCompiler = _Class("MTLCompiler")
_MTLPipelineCache = _Class("_MTLPipelineCache")
MTLResourceListPool = _Class("MTLResourceListPool")
MTLLoader = _Class("MTLLoader")
_MTLObjectWithLabel = _Class("_MTLObjectWithLabel")
_MTLFunction = _Class("_MTLFunction")
_MTLFunctionInternal = _Class("_MTLFunctionInternal")
_MTLLibrary = _Class("_MTLLibrary")
_MTLHeap = _Class("_MTLHeap")
MTLIOAccelHeap = _Class("MTLIOAccelHeap")
_MTLCommandQueue = _Class("_MTLCommandQueue")
MTLIOAccelCommandQueue = _Class("MTLIOAccelCommandQueue")
_MTLSWRaytracingAccelerationStructureCommandEncoder = _Class(
    "_MTLSWRaytracingAccelerationStructureCommandEncoder"
)
_MTLParallelRenderCommandEncoder = _Class("_MTLParallelRenderCommandEncoder")
MTLIOAccelParallelRenderCommandEncoder = _Class(
    "MTLIOAccelParallelRenderCommandEncoder"
)
_MTLPipelineLibrary = _Class("_MTLPipelineLibrary")
_MTLFence = _Class("_MTLFence")
MTLIOAccelFence = _Class("MTLIOAccelFence")
_MTLDynamicLibrary = _Class("_MTLDynamicLibrary")
_MTLBinaryArchive = _Class("_MTLBinaryArchive")
_MTLIndirectArgumentEncoder = _Class("_MTLIndirectArgumentEncoder")
MTLIOAccelIndirectArgumentEncoder = _Class("MTLIOAccelIndirectArgumentEncoder")
MTLEmulationIndirectArgumentEncoder = _Class("MTLEmulationIndirectArgumentEncoder")
_MTLCommandBuffer = _Class("_MTLCommandBuffer")
MTLIOAccelCommandBuffer = _Class("MTLIOAccelCommandBuffer")
_MTLCommandEncoder = _Class("_MTLCommandEncoder")
_MTLDebugCommandEncoder = _Class("_MTLDebugCommandEncoder")
MTLIOAccelDebugCommandEncoder = _Class("MTLIOAccelDebugCommandEncoder")
_MTLAccelerationStructureCommandEncoder = _Class(
    "_MTLAccelerationStructureCommandEncoder"
)
MTLIOAccelCommandEncoder = _Class("MTLIOAccelCommandEncoder")
MTLIOAccelResourceStateCommandEncoder = _Class("MTLIOAccelResourceStateCommandEncoder")
MTLIOAccelRenderCommandEncoder = _Class("MTLIOAccelRenderCommandEncoder")
MTLIOAccelComputeCommandEncoder = _Class("MTLIOAccelComputeCommandEncoder")
MTLIOAccelBlitCommandEncoder = _Class("MTLIOAccelBlitCommandEncoder")
MTLCaptureScope = _Class("MTLCaptureScope")
_MTLResource = _Class("_MTLResource")
MTLIOAccelResource = _Class("MTLIOAccelResource")
MTLIOAccelIntersectionFunctionTable = _Class("MTLIOAccelIntersectionFunctionTable")
MTLIOAccelBuffer = _Class("MTLIOAccelBuffer")
MTLIOAccelTexture = _Class("MTLIOAccelTexture")
MTLIOAccelPooledResource = _Class("MTLIOAccelPooledResource")
MTLIOAccelAccelerationStructure = _Class("MTLIOAccelAccelerationStructure")
MTLIOAccelVisibleFunctionTable = _Class("MTLIOAccelVisibleFunctionTable")
MTLIOAccelIndirectCommandBuffer = _Class("MTLIOAccelIndirectCommandBuffer")
MTLIOMemoryInfo = _Class("MTLIOMemoryInfo")
_MTLDevice = _Class("_MTLDevice")
MTLIOAccelDevice = _Class("MTLIOAccelDevice")
