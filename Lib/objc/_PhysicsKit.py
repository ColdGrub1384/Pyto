"""
Classes from the 'PhysicsKit' framework.
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


PKQuadTree = _Class("PKQuadTree")
PKRegion = _Class("PKRegion")
PKPhysicsGrid = _Class("PKPhysicsGrid")
PKPhysicsWorld = _Class("PKPhysicsWorld")
PKPhysicsField = _Class("PKPhysicsField")
PKPhysicsFieldElectric = _Class("PKPhysicsFieldElectric")
PKPhysicsFieldMagnetic = _Class("PKPhysicsFieldMagnetic")
PKPhysicsFieldSpring = _Class("PKPhysicsFieldSpring")
PKPhysicsFieldNoise = _Class("PKPhysicsFieldNoise")
PKPhysicsFieldTurbulence = _Class("PKPhysicsFieldTurbulence")
PKPhysicsFieldVelocity = _Class("PKPhysicsFieldVelocity")
PKPhysicsFieldCustomBlock = _Class("PKPhysicsFieldCustomBlock")
PKPhysicsFieldRadialGravity = _Class("PKPhysicsFieldRadialGravity")
PKPhysicsFieldLinearGravity = _Class("PKPhysicsFieldLinearGravity")
PKPhysicsFieldVortex = _Class("PKPhysicsFieldVortex")
PKPhysicsFieldDrag = _Class("PKPhysicsFieldDrag")
PKPhysicsJoint = _Class("PKPhysicsJoint")
PKPhysicsJointRope = _Class("PKPhysicsJointRope")
PKPhysicsJointPrismatic = _Class("PKPhysicsJointPrismatic")
PKPhysicsJointWeld = _Class("PKPhysicsJointWeld")
PKPhysicsJointDistance = _Class("PKPhysicsJointDistance")
PKPhysicsJointRevolute = _Class("PKPhysicsJointRevolute")
PKPhysicsContact = _Class("PKPhysicsContact")
PKPhysicsBody = _Class("PKPhysicsBody")
BoxedPhysicsShape = _Class("BoxedPhysicsShape")
