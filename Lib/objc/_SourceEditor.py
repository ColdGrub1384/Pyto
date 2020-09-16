'''
Classes from the 'SourceEditor' framework.
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

    
SwiftLexer = _Class('SourceEditor.SwiftLexer')
Python3Lexer = _Class('SourceEditor.Python3Lexer')
PodsDummy_SourceEditor = _Class('PodsDummy_SourceEditor')
