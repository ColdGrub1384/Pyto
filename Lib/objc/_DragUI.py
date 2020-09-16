'''
Classes from the 'DragUI' framework.
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

    
DRPasteAnnouncement = _Class('DRPasteAnnouncement')
DRPasteAnnouncementEndpoint = _Class('DRPasteAnnouncementEndpoint')
DRPasteAnnouncementContinuityEndpoint = _Class('DRPasteAnnouncementContinuityEndpoint')
DRPasteAnnouncementApplicationEndpoint = _Class('DRPasteAnnouncementApplicationEndpoint')
