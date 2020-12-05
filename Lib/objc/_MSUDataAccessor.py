"""
Classes from the 'MSUDataAccessor' framework.
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


LPMedia = _Class("LPMedia")
LPPartitionMedia = _Class("LPPartitionMedia")
LPAPFSVolume = _Class("LPAPFSVolume")
LPAPFSPhysicalStore = _Class("LPAPFSPhysicalStore")
LPAPFSContainer = _Class("LPAPFSContainer")
MSUDataAccessorSymbolicPathResolver = _Class("MSUDataAccessorSymbolicPathResolver")
MSUDataAccessor = _Class("MSUDataAccessor")
MSUDataAccessorRestore = _Class("MSUDataAccessorRestore")
