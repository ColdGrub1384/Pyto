"""
Classes from the 'MetalTools' framework.
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


MTLDebugResource = _Class("MTLDebugResource")
MTLDebugRenderTargetAttachmentInfo = _Class("MTLDebugRenderTargetAttachmentInfo")
MTLDebugBufferMarker = _Class("MTLDebugBufferMarker")
MTLBufferErrorLog = _Class("MTLBufferErrorLog")
MTLTextureErrorLog = _Class("MTLTextureErrorLog")
MTLCountersTraceCommandBuffer = _Class("MTLCountersTraceCommandBuffer")
MTLCountersTraceCommandEncoder = _Class("MTLCountersTraceCommandEncoder")
MTLCountersTraceResourceStateCommandEncoder = _Class(
    "MTLCountersTraceResourceStateCommandEncoder"
)
MTLCountersTraceRenderCommandEncoder = _Class("MTLCountersTraceRenderCommandEncoder")
MTLCountersTraceComputeCommandEncoder = _Class("MTLCountersTraceComputeCommandEncoder")
MTLCountersTraceBlitCommandEncoder = _Class("MTLCountersTraceBlitCommandEncoder")
MTLToolsPerfCounterMailbox = _Class("MTLToolsPerfCounterMailbox")
MTLToolsObject = _Class("MTLToolsObject")
MTLToolsFunctionHandle = _Class("MTLToolsFunctionHandle")
MTLDebugFunctionHandle = _Class("MTLDebugFunctionHandle")
MTLToolsArgumentEncoder = _Class("MTLToolsArgumentEncoder")
MTLDebugArgumentEncoder = _Class("MTLDebugArgumentEncoder")
MTLGPUDebugArgumentEncoder = _Class("MTLGPUDebugArgumentEncoder")
MTLToolsTextureLayout = _Class("MTLToolsTextureLayout")
MTLDebugTextureLayout = _Class("MTLDebugTextureLayout")
MTLToolsIndirectRenderCommand = _Class("MTLToolsIndirectRenderCommand")
MTLDebugIndirectRenderCommand = _Class("MTLDebugIndirectRenderCommand")
MTLGPUDebugIndirectRenderCommand = _Class("MTLGPUDebugIndirectRenderCommand")
MTLToolsResourceGroupSPI = _Class("MTLToolsResourceGroupSPI")
MTLToolsRasterizationRateMap = _Class("MTLToolsRasterizationRateMap")
MTLToolsRenderPipelineState = _Class("MTLToolsRenderPipelineState")
MTLDebugRenderPipelineState = _Class("MTLDebugRenderPipelineState")
MTLTelemetryRenderPipelineState = _Class("MTLTelemetryRenderPipelineState")
MTLGPUDebugRenderPipelineState = _Class("MTLGPUDebugRenderPipelineState")
MTLToolsPipelineLibrary = _Class("MTLToolsPipelineLibrary")
MTLDebugPipelineLibrary = _Class("MTLDebugPipelineLibrary")
MTLToolsFunction = _Class("MTLToolsFunction")
MTLGPUDebugFunction = _Class("MTLGPUDebugFunction")
MTLDebugFunction = _Class("MTLDebugFunction")
MTLToolsEvent = _Class("MTLToolsEvent")
MTLDebugEvent = _Class("MTLDebugEvent")
MTLToolsSharedEvent = _Class("MTLToolsSharedEvent")
MTLDebugSharedEvent = _Class("MTLDebugSharedEvent")
MTLToolsDepthStencilState = _Class("MTLToolsDepthStencilState")
MTLDebugDepthStencilState = _Class("MTLDebugDepthStencilState")
MTLTelemetryDepthStencilState = _Class("MTLTelemetryDepthStencilState")
MTLToolsComputePipelineState = _Class("MTLToolsComputePipelineState")
MTLDebugComputePipelineState = _Class("MTLDebugComputePipelineState")
MTLTelemetryComputePipelineState = _Class("MTLTelemetryComputePipelineState")
MTLGPUDebugComputePipelineState = _Class("MTLGPUDebugComputePipelineState")
MTLToolsBinaryArchive = _Class("MTLToolsBinaryArchive")
MTLDebugBinaryArchive = _Class("MTLDebugBinaryArchive")
MTLGPUDebugBinaryArchive = _Class("MTLGPUDebugBinaryArchive")
MTLToolsDynamicLibrary = _Class("MTLToolsDynamicLibrary")
MTLDebugDynamicLibrary = _Class("MTLDebugDynamicLibrary")
MTLToolsCommandQueue = _Class("MTLToolsCommandQueue")
MTLTelemetryCommandQueue = _Class("MTLTelemetryCommandQueue")
MTLCountersCommandQueue = _Class("MTLCountersCommandQueue")
MTLDebugCommandQueue = _Class("MTLDebugCommandQueue")
MTLGPUDebugCommandQueue = _Class("MTLGPUDebugCommandQueue")
MTLToolsCommandBuffer = _Class("MTLToolsCommandBuffer")
MTLTelemetryCommandBuffer = _Class("MTLTelemetryCommandBuffer")
MTLCountersCommandBuffer = _Class("MTLCountersCommandBuffer")
MTLDebugCommandBuffer = _Class("MTLDebugCommandBuffer")
MTLGPUDebugCommandBuffer = _Class("MTLGPUDebugCommandBuffer")
MTLToolsSamplerState = _Class("MTLToolsSamplerState")
MTLDebugSamplerState = _Class("MTLDebugSamplerState")
MTLTelemetrySamplerState = _Class("MTLTelemetrySamplerState")
MTLToolsLibrary = _Class("MTLToolsLibrary")
MTLDebugLibrary = _Class("MTLDebugLibrary")
MTLGPUDebugLibrary = _Class("MTLGPUDebugLibrary")
MTLToolsCounterSampleBuffer = _Class("MTLToolsCounterSampleBuffer")
MTLDebugCounterSampleBuffer = _Class("MTLDebugCounterSampleBuffer")
MTLToolsFence = _Class("MTLToolsFence")
MTLToolsResource = _Class("MTLToolsResource")
MTLToolsAccelerationStructure = _Class("MTLToolsAccelerationStructure")
MTLDebugAccelerationStructure = _Class("MTLDebugAccelerationStructure")
MTLToolsTexture = _Class("MTLToolsTexture")
MTLDebugTexture = _Class("MTLDebugTexture")
MTLTelemetryTexture = _Class("MTLTelemetryTexture")
MTLToolsIntersectionFunctionTable = _Class("MTLToolsIntersectionFunctionTable")
MTLDebugIntersectionFunctionTable = _Class("MTLDebugIntersectionFunctionTable")
MTLToolsVisibleFunctionTable = _Class("MTLToolsVisibleFunctionTable")
MTLDebugVisibleFunctionTable = _Class("MTLDebugVisibleFunctionTable")
MTLToolsBuffer = _Class("MTLToolsBuffer")
MTLTelemetryBuffer = _Class("MTLTelemetryBuffer")
MTLDebugBuffer = _Class("MTLDebugBuffer")
MTLGPUDebugBuffer = _Class("MTLGPUDebugBuffer")
MTLToolsHeap = _Class("MTLToolsHeap")
MTLDebugHeap = _Class("MTLDebugHeap")
MTLGPUDebugHeap = _Class("MTLGPUDebugHeap")
MTLTelemetryHeap = _Class("MTLTelemetryHeap")
MTLToolsIndirectCommandBuffer = _Class("MTLToolsIndirectCommandBuffer")
MTLGPUDebugIndirectCommandBuffer = _Class("MTLGPUDebugIndirectCommandBuffer")
MTLDebugIndirectCommandBuffer = _Class("MTLDebugIndirectCommandBuffer")
MTLToolsCommandEncoder = _Class("MTLToolsCommandEncoder")
MTLToolsResourceStateCommandEncoder = _Class("MTLToolsResourceStateCommandEncoder")
MTLCountersResourceStateCommandEncoder = _Class(
    "MTLCountersResourceStateCommandEncoder"
)
MTLDebugResourceStateCommandEncoder = _Class("MTLDebugResourceStateCommandEncoder")
MTLToolsParallelRenderCommandEncoder = _Class("MTLToolsParallelRenderCommandEncoder")
MTLDebugParallelRenderCommandEncoder = _Class("MTLDebugParallelRenderCommandEncoder")
MTLGPUDebugParallelRenderCommandEncoder = _Class(
    "MTLGPUDebugParallelRenderCommandEncoder"
)
MTLTelemetryParallelRenderCommandEncoder = _Class(
    "MTLTelemetryParallelRenderCommandEncoder"
)
MTLCountersParallelRenderCommandEncoder = _Class(
    "MTLCountersParallelRenderCommandEncoder"
)
MTLToolsAccelerationStructureCommandEncoder = _Class(
    "MTLToolsAccelerationStructureCommandEncoder"
)
MTLDebugAccelerationStructureCommandEncoder = _Class(
    "MTLDebugAccelerationStructureCommandEncoder"
)
MTLToolsComputeCommandEncoder = _Class("MTLToolsComputeCommandEncoder")
MTLGPUDebugComputeCommandEncoder = _Class("MTLGPUDebugComputeCommandEncoder")
MTLTelemetryComputeCommandEncoder = _Class("MTLTelemetryComputeCommandEncoder")
MTLDebugComputeCommandEncoder = _Class("MTLDebugComputeCommandEncoder")
MTLCountersComputeCommandEncoder = _Class("MTLCountersComputeCommandEncoder")
MTLToolsBlitCommandEncoder = _Class("MTLToolsBlitCommandEncoder")
MTLCountersBlitCommandEncoder = _Class("MTLCountersBlitCommandEncoder")
MTLTelemetryBlitCommandEncoder = _Class("MTLTelemetryBlitCommandEncoder")
MTLGPUDebugBlitCommandEncoder = _Class("MTLGPUDebugBlitCommandEncoder")
MTLDebugBlitCommandEncoder = _Class("MTLDebugBlitCommandEncoder")
MTLToolsRenderCommandEncoder = _Class("MTLToolsRenderCommandEncoder")
MTLTelemetryRenderCommandEncoder = _Class("MTLTelemetryRenderCommandEncoder")
MTLDebugRenderCommandEncoder = _Class("MTLDebugRenderCommandEncoder")
MTLCountersRenderCommandEncoder = _Class("MTLCountersRenderCommandEncoder")
MTLGPUDebugRenderCommandEncoder = _Class("MTLGPUDebugRenderCommandEncoder")
MTLToolsIndirectComputeCommand = _Class("MTLToolsIndirectComputeCommand")
MTLGPUDebugIndirectComputeCommand = _Class("MTLGPUDebugIndirectComputeCommand")
MTLDebugIndirectComputeCommand = _Class("MTLDebugIndirectComputeCommand")
MTLToolsDevice = _Class("MTLToolsDevice")
MTLTelemetryDevice = _Class("MTLTelemetryDevice")
MTLCountersDevice = _Class("MTLCountersDevice")
MTLGPUDebugDevice = _Class("MTLGPUDebugDevice")
MTLDebugDevice = _Class("MTLDebugDevice")
