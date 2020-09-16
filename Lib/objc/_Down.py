'''
Classes from the 'Down' framework.
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

    
DebugVisitor = _Class('Down.DebugVisitor')
BaseNode = _Class('Down.BaseNode')
ThematicBreak = _Class('Down.ThematicBreak')
Text = _Class('Down.Text')
Strong = _Class('Down.Strong')
SoftBreak = _Class('Down.SoftBreak')
Paragraph = _Class('Down.Paragraph')
List = _Class('Down.List')
Link = _Class('Down.Link')
LineBreak = _Class('Down.LineBreak')
Item = _Class('Down.Item')
Image = _Class('Down.Image')
HtmlInline = _Class('Down.HtmlInline')
HtmlBlock = _Class('Down.HtmlBlock')
Heading = _Class('Down.Heading')
Emphasis = _Class('Down.Emphasis')
Document = _Class('Down.Document')
CustomInline = _Class('Down.CustomInline')
CustomBlock = _Class('Down.CustomBlock')
CodeBlock = _Class('Down.CodeBlock')
Code = _Class('Down.Code')
BlockQuote = _Class('Down.BlockQuote')
AttributedStringVisitor = _Class('Down.AttributedStringVisitor')
PodsDummy_Down = _Class('PodsDummy_Down')
DownView = _Class('Down.DownView')
