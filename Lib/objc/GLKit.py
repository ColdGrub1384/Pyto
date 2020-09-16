'''
Classes from the 'GLKit' framework.
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

    
GLKDisplayLinkMessenger = _Class('GLKDisplayLinkMessenger')
GLKShadingHash = _Class('GLKShadingHash')
GLKHashableBigInt = _Class('GLKHashableBigInt')
GLKShaderBlockNode = _Class('GLKShaderBlockNode')
GLKSkyboxEffect = _Class('GLKSkyboxEffect')
GLKTextureLoader = _Class('GLKTextureLoader')
GLKTextureInfo = _Class('GLKTextureInfo')
GLKTexture = _Class('GLKTexture')
GLKTextureTXR = _Class('GLKTextureTXR')
GLKEffectProperty = _Class('GLKEffectProperty')
GLKEffectPropertyTransform = _Class('GLKEffectPropertyTransform')
GLKEffectPropertyTexture = _Class('GLKEffectPropertyTexture')
GLKEffectPropertyTexGen = _Class('GLKEffectPropertyTexGen')
GLKEffectPropertyMaterial = _Class('GLKEffectPropertyMaterial')
GLKEffectPropertyLight = _Class('GLKEffectPropertyLight')
GLKEffectPropertyFog = _Class('GLKEffectPropertyFog')
GLKEffectPropertyConstantColor = _Class('GLKEffectPropertyConstantColor')
GLKMesh = _Class('GLKMesh')
GLKSubmesh = _Class('GLKSubmesh')
GLKMeshBufferAllocator = _Class('GLKMeshBufferAllocator')
GLKMeshBuffer = _Class('GLKMeshBuffer')
GLKMeshBufferZone = _Class('GLKMeshBufferZone')
GLKMeshBufferHolder = _Class('GLKMeshBufferHolder')
GLKEffect = _Class('GLKEffect')
GLKBaseEffect = _Class('GLKBaseEffect')
GLKReflectionMapEffect = _Class('GLKReflectionMapEffect')
GLKView = _Class('GLKView')
GLKViewController = _Class('GLKViewController')
