"""
Text to speech

Speak text with system voices.
"""

from pyto import PySpeech
from typing import List


def is_speaking() -> bool:
    """
    Returns a boolean indicating if the device is currently speaking.

    :rtype: bool
    """

    return PySpeech.isSpeaking()


def wait():
    """
    Waits until the script finishes speaking.
    """

    PySpeech.wait()


def say(text: str, language: str = None, rate: float = None):
    """
    Says the given text.

    :param text: The text to speak.
    :param language: Format: ``en-US``. If is nothing provided, the system language is used. Use the :func:`~pyto_ui.get_available_languages` function to get all available languages.
    :param rate: The speed of the voice. From 0 (really slow) to 1 (really fast). If nothing is provided, 0.5 is used.
    """

    r = rate
    if r is None:
        r = 0.5

    PySpeech.say(text, language=language, rate=r)


def get_available_languages() -> List[str]:
    """
    Returns all available languages.

    :rtype: List[str]
    """

    voices = []

    for voice in PySpeech.availableVoices():
        voices.append(str(voice))

    return voices
