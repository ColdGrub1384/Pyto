"""
Classes from the 'RemoteTextInput' framework.
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


RTIDocumentTraits = _Class("RTIDocumentTraits")
RTITextOperations = _Class("RTITextOperations")
RTIInputSystemService = _Class("RTIInputSystemService")
RTIUtilities = _Class("RTIUtilities")
RTIInputSystemClient = _Class("RTIInputSystemClient")
RTIInputSystemClientSession = _Class("RTIInputSystemClientSession")
RTIDocumentState = _Class("RTIDocumentState")
RTIStyledIntermediateText = _Class("RTIStyledIntermediateText")
RTIDataPayload = _Class("RTIDataPayload")
RTIInputSystemDataPayload = _Class("RTIInputSystemDataPayload")
RTIInputSystemSession = _Class("RTIInputSystemSession")
RTIInputSystemServiceSession = _Class("RTIInputSystemServiceSession")
RTIInputSystemSourceSession = _Class("RTIInputSystemSourceSession")
