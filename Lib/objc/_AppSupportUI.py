'''
Classes from the 'AppSupportUI' framework.
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

    
NUIGridArrangement = _Class('NUIGridArrangement')
NUISizeCache = _Class('NUISizeCache')
NUIBoxArrangement = _Class('NUIBoxArrangement')
NUIGridDimension = _Class('NUIGridDimension')
_NUIViewContainerViewInfo = _Class('_NUIViewContainerViewInfo')
NUIWidgetGridView = _Class('NUIWidgetGridView')
NUIWidgetGridViewEmptyCell = _Class('NUIWidgetGridViewEmptyCell')
NUIContainerView = _Class('NUIContainerView')
NUIContainerBoxView = _Class('NUIContainerBoxView')
NUIContainerFlowView = _Class('NUIContainerFlowView')
NUIContainerStackView = _Class('NUIContainerStackView')
NUIWidgetGridViewCell = _Class('NUIWidgetGridViewCell')
NUIContainerGridView = _Class('NUIContainerGridView')
NUIContentScrollView = _Class('NUIContentScrollView')
NUITableViewContainerCell = _Class('NUITableViewContainerCell')
NUICollectionViewContainerCell = _Class('NUICollectionViewContainerCell')
