'''
Classes from the 'SavannaKit' framework.
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

    
PodsDummy_SavannaKit = _Class('PodsDummy_SavannaKit')
LineNumberLayoutManager = _Class('SavannaKit.LineNumberLayoutManager')
SyntaxTextViewLayoutManager = _Class('SavannaKit.SyntaxTextViewLayoutManager')
SyntaxTextView = _Class('SavannaKit.SyntaxTextView')
InnerTextView = _Class('SavannaKit.InnerTextView')
