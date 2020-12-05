"""
Classes from the 'ModelIO' framework.
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


MDLTexture = _Class("MDLTexture")
MDLNormalMapTexture = _Class("MDLNormalMapTexture")
MDLSkyCubeTexture = _Class("MDLSkyCubeTexture")
MDLColorSwatchTexture = _Class("MDLColorSwatchTexture")
MDLCheckerboardTexture = _Class("MDLCheckerboardTexture")
MDLURLTexture = _Class("MDLURLTexture")
MDLNoiseTexture = _Class("MDLNoiseTexture")
MDLObjectContainer = _Class("MDLObjectContainer")
MDLMeshBufferAllocatorDefault = _Class("MDLMeshBufferAllocatorDefault")
MDLMeshBufferDataAllocator = _Class("MDLMeshBufferDataAllocator")
MDLMeshBufferData = _Class("MDLMeshBufferData")
MDLMeshBufferZoneDefault = _Class("MDLMeshBufferZoneDefault")
MDLMeshBufferMap = _Class("MDLMeshBufferMap")
_MDL_DarwinHelper__internal = _Class("_MDL_DarwinHelper__internal")
MDLTransform = _Class("MDLTransform")
MDLScene = _Class("MDLScene")
MDLMemoryMappedData = _Class("MDLMemoryMappedData")
MDLAnimationBindComponent = _Class("MDLAnimationBindComponent")
MDLVertexAttributeData = _Class("MDLVertexAttributeData")
MDLAnimatedValue = _Class("MDLAnimatedValue")
MDLAnimatedMatrix4x4 = _Class("MDLAnimatedMatrix4x4")
MDLAnimatedQuaternion = _Class("MDLAnimatedQuaternion")
MDLAnimatedVector4 = _Class("MDLAnimatedVector4")
MDLAnimatedVector3 = _Class("MDLAnimatedVector3")
MDLAnimatedVector2 = _Class("MDLAnimatedVector2")
MDLAnimatedScalar = _Class("MDLAnimatedScalar")
MDLAnimatedQuaternionArray = _Class("MDLAnimatedQuaternionArray")
MDLAnimatedVector3Array = _Class("MDLAnimatedVector3Array")
MDLAnimatedScalarArray = _Class("MDLAnimatedScalarArray")
MDLMatrix4x4Array = _Class("MDLMatrix4x4Array")
MDLVertexDescriptor = _Class("MDLVertexDescriptor")
MDLVertexAttribute = _Class("MDLVertexAttribute")
MDLVertexBufferLayout = _Class("MDLVertexBufferLayout")
MDLInteractiveCameraController = _Class("MDLInteractiveCameraController")
MDLSubmesh = _Class("MDLSubmesh")
MDLSubmeshTopology = _Class("MDLSubmeshTopology")
MDLVolumeGrid = _Class("MDLVolumeGrid")
MDLTransformStack = _Class("MDLTransformStack")
MDLTransformMatrixOp = _Class("MDLTransformMatrixOp")
MDLTransformOrientOp = _Class("MDLTransformOrientOp")
MDLTransformScaleOp = _Class("MDLTransformScaleOp")
MDLTransformRotateOp = _Class("MDLTransformRotateOp")
MDLTransformTranslateOp = _Class("MDLTransformTranslateOp")
MDLTransformRotateZOp = _Class("MDLTransformRotateZOp")
MDLTransformRotateYOp = _Class("MDLTransformRotateYOp")
MDLTransformRotateXOp = _Class("MDLTransformRotateXOp")
MDLObject = _Class("MDLObject")
MDLPackedJointAnimation = _Class("MDLPackedJointAnimation")
MDLSkeleton = _Class("MDLSkeleton")
MDLMesh = _Class("MDLMesh")
MDLVoxelArray = _Class("MDLVoxelArray")
MDLCamera = _Class("MDLCamera")
MDLStereoscopicCamera = _Class("MDLStereoscopicCamera")
MDLLight = _Class("MDLLight")
MDLLightProbe = _Class("MDLLightProbe")
MDLPhysicallyPlausibleLight = _Class("MDLPhysicallyPlausibleLight")
MDLPhotometricLight = _Class("MDLPhotometricLight")
MDLAreaLight = _Class("MDLAreaLight")
MDLAsset = _Class("MDLAsset")
_MDLProbeCluster = _Class("_MDLProbeCluster")
MDLArchiveAssetResolver = _Class("MDLArchiveAssetResolver")
MDLBundleAssetResolver = _Class("MDLBundleAssetResolver")
MDLPathAssetResolver = _Class("MDLPathAssetResolver")
MDLRelativeAssetResolver = _Class("MDLRelativeAssetResolver")
MDLAssetLoader = _Class("MDLAssetLoader")
MDLMorphDeformer = _Class("MDLMorphDeformer")
MDLMaterialPropertyNode = _Class("MDLMaterialPropertyNode")
MDLMaterialPropertyGraph = _Class("MDLMaterialPropertyGraph")
MDLMaterialPropertyConnection = _Class("MDLMaterialPropertyConnection")
MDLMaterial = _Class("MDLMaterial")
MDLScatteringFunction = _Class("MDLScatteringFunction")
MDLPhysicallyPlausibleScatteringFunction = _Class(
    "MDLPhysicallyPlausibleScatteringFunction"
)
MDLMaterialProperty = _Class("MDLMaterialProperty")
MDLTextureSampler = _Class("MDLTextureSampler")
MDLTextureFilter = _Class("MDLTextureFilter")
MDLSkinDeformer = _Class("MDLSkinDeformer")
