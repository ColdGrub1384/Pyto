"""
Classes from the 'IOGPU' framework.
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


IOGPUMTLFence = _Class("IOGPUMTLFence")
IOGPUMetalTextureLayout = _Class("IOGPUMetalTextureLayout")
IOGPUMTLEvent = _Class("IOGPUMTLEvent")
_IOGPUMetalMTLEvent = _Class("_IOGPUMetalMTLEvent")
IOGPUMetalIndirectRenderCommand = _Class("IOGPUMetalIndirectRenderCommand")
IOGPUMetalIndirectComputeCommand = _Class("IOGPUMetalIndirectComputeCommand")
IOGPUMetalResourcePool = _Class("IOGPUMetalResourcePool")
IOGPUMetalDeviceShmem = _Class("IOGPUMetalDeviceShmem")
IOGPUMetalDeviceShmemPool = _Class("IOGPUMetalDeviceShmemPool")
IOGPUMemoryInfo = _Class("IOGPUMemoryInfo")
IOGPUMetalHeap = _Class("IOGPUMetalHeap")
IOGPUMetalCommandQueue = _Class("IOGPUMetalCommandQueue")
IOGPUMetalParallelRenderCommandEncoder = _Class(
    "IOGPUMetalParallelRenderCommandEncoder"
)
IOGPUMetalFence = _Class("IOGPUMetalFence")
IOGPUMetalIndirectArgumentEncoder = _Class("IOGPUMetalIndirectArgumentEncoder")
IOGPUMetalCommandBuffer = _Class("IOGPUMetalCommandBuffer")
IOGPUMetalCommandEncoder = _Class("IOGPUMetalCommandEncoder")
IOGPUMetalResourceStateCommandEncoder = _Class("IOGPUMetalResourceStateCommandEncoder")
IOGPUMetalRenderCommandEncoder = _Class("IOGPUMetalRenderCommandEncoder")
IOGPUMetalComputeCommandEncoder = _Class("IOGPUMetalComputeCommandEncoder")
IOGPUMetalBlitCommandEncoder = _Class("IOGPUMetalBlitCommandEncoder")
IOGPUMetalDebugCommandEncoder = _Class("IOGPUMetalDebugCommandEncoder")
IOGPUMetalResource = _Class("IOGPUMetalResource")
IOGPUMetalAccelerationStructure = _Class("IOGPUMetalAccelerationStructure")
IOGPUMetalTexture = _Class("IOGPUMetalTexture")
IOGPUMetalIndirectCommandBuffer = _Class("IOGPUMetalIndirectCommandBuffer")
IOGPUMetalIntersectionFunctionTable = _Class("IOGPUMetalIntersectionFunctionTable")
IOGPUMetalVisibleFunctionTable = _Class("IOGPUMetalVisibleFunctionTable")
IOGPUMetalBuffer = _Class("IOGPUMetalBuffer")
IOGPUMetalPooledResource = _Class("IOGPUMetalPooledResource")
IOGPUMetalDevice = _Class("IOGPUMetalDevice")
