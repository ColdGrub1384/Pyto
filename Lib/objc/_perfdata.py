"""
Classes from the 'perfdata' framework.
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


PDBucket = _Class("PDBucket")
PDMeasurement = _Class("PDMeasurement")
PDContainer = _Class("PDContainer")
PDAggregateMeasurement = _Class("PDAggregateMeasurement")
