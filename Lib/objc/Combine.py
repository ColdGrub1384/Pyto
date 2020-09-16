'''
Classes from the 'Combine' framework.
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

    
DebugHook = _Class('Combine.DebugHook')
_TtCC7Combine25ObservableObjectPublisherP33_40FA7804DFFDD9097A0F4AE4A57029327Conduit = _Class('_TtCC7Combine25ObservableObjectPublisherP33_40FA7804DFFDD9097A0F4AE4A57029327Conduit')
AnyCancellable = _Class('Combine.AnyCancellable')
_TtGC7Combine16PublishedSubjectSb_ = _Class('_TtGC7Combine16PublishedSubjectSb_')
_TtGC7Combine16PublishedSubjectSS_ = _Class('_TtGC7Combine16PublishedSubjectSS_')
_TtGC7Combine16PublishedSubjectGSaSS__ = _Class('_TtGC7Combine16PublishedSubjectGSaSS__')
ObservableObjectPublisher = _Class('Combine.ObservableObjectPublisher')
