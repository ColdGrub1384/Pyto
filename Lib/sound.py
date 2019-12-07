"""
A module for playing sounds. Wraps the AudioToolbox and AVFoundation system framework.
"""

from os.path import abspath, expanduser
from rubicon.objc import ObjCClass
from ctypes import *

AudioToolbox = cdll.LoadLibrary("/System/Library/Frameworks/AudioToolbox.framework/AudioToolbox")
"""
The AudioToolbox system framework.
"""

AVFoundation = cdll.LoadLibrary("/System/Library/Frameworks/AVFoundation.framework/AVFoundation")
"""
The AVFoundation system framework.
"""

AVAudioPlayer = ObjCClass("AVAudioPlayer")
"""
The AVAudioPlayer class from AVFoundation framework.
"""

NSURL = ObjCClass("NSURL")

class AudioPlayer:
    """
    A wrapper of the ``AVAudioPlayer`` class of the AVFoundation framework. Use this class for playing long sounds with the ability to pause, to stop and to set the time.
    """

    def __init__(self, path: str):
        """
        Initializes a player from the given audio path.

        :param path: The path of the audio.
        """

        abs_path = abspath(path)
        url = NSURL.fileURLWithPath(abs_path)
        self.__player__ = AVAudioPlayer.alloc().initWithContentsOfURL(url, error=None)

    def play(self):
        """
        Plays the audio asynchronously.
        """

        self.__player__.play()

    def pause(self):
        """
        Pauses the audio.
        """

        self.__player__.pause()

    def stop(self):
        """
        Stops the audio.
        """

        self.__player__.stop()

    @property
    def playing(self) -> bool:
        """
        A boolean indicating whether the sound is playing. (read only)

        :rtype: bool
        """

        return self.__player__.isPlaying()

    @property
    def volume(self) -> float:
        """
        The volume of the sound. (From 0 to 1)

        :rtype: float
        """

        return float(self.__player__.volume)
 
    @volume.setter
    def volume(self, new_value: float):
        self.__player__.volume = new_value

    @property
    def current_time(self) -> float:
        """
        The current time of the sound in seconds.

        :rtype: float
        """

        return float(self.__player__.currentTime)

    @current_time.setter
    def current_time(self, new_value: float):
        self.__player__.currentTime = new_value

def play_file(path: str):
    """
    Plays a file at given path.

    .. warning::
       Only use this function for sounds under 30 seconds. Use :class:`AudioPlayer` for longer sounds.

    :param path: The relative path of the file to play.
    """

    path = abspath(path)
    url = NSURL.fileURLWithPath(path).ptr
    s = c_int(0)
    s = byref(s)

    AudioToolbox.AudioServicesCreateSystemSoundID(url, s)
    AudioToolbox.AudioServicesPlaySystemSound(s._obj)

def play_beep():
    """
    Plays a beep sound.
    """

    AudioToolbox.AudioServicesPlaySystemSound(1052)

def play_system_sound(id: int):
    """
    Plays a system sound with given ID.

    For a list of sounds: `github.com/TUNER88/iOSSystemSoundsLibrary <https://github.com/TUNER88/iOSSystemSoundsLibrary>`_.

    :param id: The ID of the system sound to play.
    """

    AudioToolbox.AudioServicesPlaySystemSound(id)
