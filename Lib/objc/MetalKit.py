'''
Classes from the 'MetalKit' framework.
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

    
MTKViewDisplayLinkTarget = _Class('MTKViewDisplayLinkTarget')
MTKMeshBuffer = _Class('MTKMeshBuffer')
MTKTextureLoaderASTCHelper = _Class('MTKTextureLoaderASTCHelper')
MTKMeshBufferZone = _Class('MTKMeshBufferZone')
MTKMeshBufferHolder = _Class('MTKMeshBufferHolder')
MTKMesh = _Class('MTKMesh')
MTKSubmesh = _Class('MTKSubmesh')
MTKMeshBufferAllocator = _Class('MTKMeshBufferAllocator')
MTKOffscreenDrawable = _Class('MTKOffscreenDrawable')
MTKTextureLoader = _Class('MTKTextureLoader')
MTKTextureIOBufferAllocator = _Class('MTKTextureIOBufferAllocator')
MTKTextureIOBuffer = _Class('MTKTextureIOBuffer')
MTKTextureIOBufferMap = _Class('MTKTextureIOBufferMap')
MTKTextureUploader = _Class('MTKTextureUploader')
MTKTextureLoaderData = _Class('MTKTextureLoaderData')
MTKTextureLoaderPVR = _Class('MTKTextureLoaderPVR')
MTKTextureLoaderKTX = _Class('MTKTextureLoaderKTX')
MTKTextureLoaderImageIO = _Class('MTKTextureLoaderImageIO')
MTKTextureLoaderMDL = _Class('MTKTextureLoaderMDL')
MTKTextureLoaderPVR3 = _Class('MTKTextureLoaderPVR3')
MTKView = _Class('MTKView')
