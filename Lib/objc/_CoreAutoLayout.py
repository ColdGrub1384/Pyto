"""
Classes from the 'CoreAutoLayout' framework.
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


NSLayoutRect = _Class("NSLayoutRect")
NSLayoutRectangle = _Class("NSLayoutRectangle")
NSLayoutPoint = _Class("NSLayoutPoint")
NSISPlaybackOperation = _Class("NSISPlaybackOperation")
NSISPlaybackOperationVariableDelegate = _Class("NSISPlaybackOperationVariableDelegate")
_NSLayoutRuleNode = _Class("_NSLayoutRuleNode")
_NSCompositeLayoutRuleNode = _Class("_NSCompositeLayoutRuleNode")
_NSConstraintDescriptionLayoutRuleNode = _Class(
    "_NSConstraintDescriptionLayoutRuleNode"
)
NSLayoutConstraintExplainer = _Class("NSLayoutConstraintExplainer")
NSVisualFormatLayoutRule = _Class("NSVisualFormatLayoutRule")
NSStackInContainerRule = _Class("NSStackInContainerRule")
NSStackLayoutRule = _Class("NSStackLayoutRule")
NSAlignmentLayoutRule = _Class("NSAlignmentLayoutRule")
NSLayoutRectRule = _Class("NSLayoutRectRule")
NSLayoutPointRule = _Class("NSLayoutPointRule")
NSLayoutAnchorRule = _Class("NSLayoutAnchorRule")
NSLayoutConstraintParser = _Class("NSLayoutConstraintParser")
_NSLayoutRectObservable = _Class("_NSLayoutRectObservable")
_NSISVariableObservable = _Class("_NSISVariableObservable")
_NSISLinearExpressionObservable = _Class("_NSISLinearExpressionObservable")
NSISVariableObservation = _Class("NSISVariableObservation")
NSISLinearExpression = _Class("NSISLinearExpression")
NSISObjectiveLinearExpression = _Class("NSISObjectiveLinearExpression")
NSISVariable = _Class("NSISVariable")
NSISRestrictedToNonNegativeVariableToBeMinimized = _Class(
    "NSISRestrictedToNonNegativeVariableToBeMinimized"
)
NSISRestrictedToNonNegativeMarkerVariableToBeMinimized = _Class(
    "NSISRestrictedToNonNegativeMarkerVariableToBeMinimized"
)
NSISRestrictedToNonNegativeMarkerVariable = _Class(
    "NSISRestrictedToNonNegativeMarkerVariable"
)
NSISUnrestrictedVariable = _Class("NSISUnrestrictedVariable")
NSISRestrictedToNonNegativeVariable = _Class("NSISRestrictedToNonNegativeVariable")
NSISRestrictedToZeroMarkerVariable = _Class("NSISRestrictedToZeroMarkerVariable")
NSISInlineStorageVariable = _Class("NSISInlineStorageVariable")
NSISEngine = _Class("NSISEngine")
NSLayoutAnchor = _Class("NSLayoutAnchor")
NSLayoutDimension = _Class("NSLayoutDimension")
_NSDistanceLayoutDimension = _Class("_NSDistanceLayoutDimension")
_NSCompositeLayoutDimension = _Class("_NSCompositeLayoutDimension")
_NSArithmeticLayoutDimension = _Class("_NSArithmeticLayoutDimension")
NSLayoutYAxisAnchor = _Class("NSLayoutYAxisAnchor")
_NSCompositeLayoutYAxisAnchor = _Class("_NSCompositeLayoutYAxisAnchor")
_NSAutoresizingMaskYAxisAnchor = _Class("_NSAutoresizingMaskYAxisAnchor")
NSLayoutXAxisAnchor = _Class("NSLayoutXAxisAnchor")
_NSCompositeLayoutXAxisAnchor = _Class("_NSCompositeLayoutXAxisAnchor")
_NSAutoresizingMaskXAxisAnchor = _Class("_NSAutoresizingMaskXAxisAnchor")
NSLayoutConstraint = _Class("NSLayoutConstraint")
NSIBPrototypingLayoutConstraint = _Class("NSIBPrototypingLayoutConstraint")
NSErrorVariableConstraint = _Class("NSErrorVariableConstraint")
NSAutoresizingMaskLayoutConstraint = _Class("NSAutoresizingMaskLayoutConstraint")
NSContentSizeLayoutConstraint = _Class("NSContentSizeLayoutConstraint")
