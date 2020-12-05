"""
Classes from the 'MPSRayIntersector' framework.
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


MPSAccelerationStructureGroup = _Class("MPSAccelerationStructureGroup")
MPSPolygonBuffer = _Class("MPSPolygonBuffer")
MPSSVGFDenoiser = _Class("MPSSVGFDenoiser")
MPSSVGFDefaultTextureAllocator = _Class("MPSSVGFDefaultTextureAllocator")
MPSRayIntersector = _Class("MPSRayIntersector")
MPSTemporalAA = _Class("MPSTemporalAA")
MPSSVGF = _Class("MPSSVGF")
MPSAccelerationStructure = _Class("MPSAccelerationStructure")
MPSInstanceAccelerationStructure = _Class("MPSInstanceAccelerationStructure")
MPSPolygonAccelerationStructure = _Class("MPSPolygonAccelerationStructure")
MPSTriangleAccelerationStructure = _Class("MPSTriangleAccelerationStructure")
MPSQuadrilateralAccelerationStructure = _Class("MPSQuadrilateralAccelerationStructure")
