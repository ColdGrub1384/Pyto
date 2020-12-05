"""
Classes from the 'AudioSession' framework.
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


AVAudioSessionRouteDescription = _Class("AVAudioSessionRouteDescription")
AVAudioSessionChannelDescription = _Class("AVAudioSessionChannelDescription")
AVAudioSessionDataSourceDescription = _Class("AVAudioSessionDataSourceDescription")
AVAudioSessionPortDescription = _Class("AVAudioSessionPortDescription")
AVAudioSession = _Class("AVAudioSession")
