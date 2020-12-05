"""
Classes from the 'AGXMetalA10' framework.
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


AGXA10FamilyIndirectRenderCommandEncoder = _Class(
    "AGXA10FamilyIndirectRenderCommandEncoder"
)
AGXA10FamilyComputeOrFragmentOrTileProgram = _Class(
    "AGXA10FamilyComputeOrFragmentOrTileProgram"
)
AGXA10FamilyComputeProgram = _Class("AGXA10FamilyComputeProgram")
AGXA10FamilyFragmentProgram = _Class("AGXA10FamilyFragmentProgram")
AGXA10FamilyVertexProgram = _Class("AGXA10FamilyVertexProgram")
AGXA10FamilyWarpFunction = _Class("AGXA10FamilyWarpFunction")
AGXA10FamilyResourceGroup = _Class("AGXA10FamilyResourceGroup")
AGXMTLCounterSampleBuffer = _Class("AGXMTLCounterSampleBuffer")
AGXA10FamilyIndirectComputeCommandEncoder = _Class(
    "AGXA10FamilyIndirectComputeCommandEncoder"
)
AGXTextureLayout = _Class("AGXTextureLayout")
AGXA10FamilyDepthStencilState = _Class("AGXA10FamilyDepthStencilState")
AGXA10FamilyRenderPipeline = _Class("AGXA10FamilyRenderPipeline")
AGXA10FamilyComputePipeline = _Class("AGXA10FamilyComputePipeline")
AGXA10FamilySampler = _Class("AGXA10FamilySampler")
AGXA10FamilyIndirectRenderCommand = _Class("AGXA10FamilyIndirectRenderCommand")
AGXA10FamilyFunctionHandle = _Class("AGXA10FamilyFunctionHandle")
AGXA10FamilyRasterizationRateMap = _Class("AGXA10FamilyRasterizationRateMap")
AGXA10FamilyIndirectArgumentBufferLayout = _Class(
    "AGXA10FamilyIndirectArgumentBufferLayout"
)
AGXA10FamilyIndirectComputeCommand = _Class("AGXA10FamilyIndirectComputeCommand")
AGXPrincipalDevice = _Class("AGXPrincipalDevice")
AGXA10FamilySparseHeap = _Class("AGXA10FamilySparseHeap")
AGXA10FamilyHeap = _Class("AGXA10FamilyHeap")
AGXA10FamilyCommandQueue = _Class("AGXA10FamilyCommandQueue")
AGXA10FamilyThreadedRenderPass = _Class("AGXA10FamilyThreadedRenderPass")
AGXA10FamilyDynamicLibrary = _Class("AGXA10FamilyDynamicLibrary")
AGXA10FamilyBinaryArchive = _Class("AGXA10FamilyBinaryArchive")
AGXA10FamilyIndirectArgumentEncoder = _Class("AGXA10FamilyIndirectArgumentEncoder")
AGXA10FamilyCommandBuffer = _Class("AGXA10FamilyCommandBuffer")
AGXA10FamilyResourceStateContext = _Class("AGXA10FamilyResourceStateContext")
AGXA10FamilyRenderContext = _Class("AGXA10FamilyRenderContext")
AGXA10FamilySampledRenderContext = _Class("AGXA10FamilySampledRenderContext")
AGXA10FamilyComputeContext = _Class("AGXA10FamilyComputeContext")
AGXA10FamilySampledComputeContext = _Class("AGXA10FamilySampledComputeContext")
AGXA10FamilyBlitContext = _Class("AGXA10FamilyBlitContext")
AGXA10FamilyDebugContext = _Class("AGXA10FamilyDebugContext")
AGXTexture = _Class("AGXTexture")
AGXA10FamilyTexture = _Class("AGXA10FamilyTexture")
AGXA10FamilyIndirectCommandBuffer = _Class("AGXA10FamilyIndirectCommandBuffer")
AGXBuffer = _Class("AGXBuffer")
AGXA10FamilyVisibleFunctionTable = _Class("AGXA10FamilyVisibleFunctionTable")
AGXA10FamilyBuffer = _Class("AGXA10FamilyBuffer")
AGXA10FamilyDevice = _Class("AGXA10FamilyDevice")
AGXA10XDevice = _Class("AGXA10XDevice")
AGXA10Device = _Class("AGXA10Device")
