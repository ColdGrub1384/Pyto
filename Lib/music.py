"""
Access to the media library

Use the ``music`` module to access the Music library of the user and to play items.

Example:

.. highlight:: python
.. code-block:: python

    import music
    music.set_queue_with_items(music.pick_music())
    music.play()
"""

from pyto_ui import __pil_image_from_ui_image__
from typing import List
from pyto import PyMusicHelper
from ctypes import cdll
import PIL
import threading


try:
    from rubicon.objc import ObjCClass

    MPMusicPlayerController = ObjCClass("MPMusicPlayerController")
    """ The 'MPMusicPlayerController' class from the 'MediaPlayer' framework. """

    MPMediaItem = ObjCClass("MPMediaItem")
    """ The 'MPMediaItem' class from the 'MediaPlayer' framework. """

    MPMediaItemCollection = ObjCClass("MPMediaItemCollection")
    """ The 'MPMediaItemCollection' class from the 'MediaPlayer' framework. """

    MPMediaQuery = ObjCClass("MPMediaQuery")
    """ The 'MPMusicMPMediaQueryPlayerController' class from the 'MediaPlayer' framework. """

    MediaPlayer = cdll.LoadLibrary("/System/Library/Frameworks/MediaPlayer.framework/MediaPlayer")
except NameError:
    MPMusicPlayerController = "MPMusicPlayerController"
    """ The 'MPMusicPlayerController' class from the 'MediaPlayer' framework. """

    MPMediaItem = "MPMediaItem"
    """ The 'MPMediaItem' class from the 'MediaPlayer' framework. """

    MPMediaItemCollection = "MPMediaItemCollection"
    """ The 'MPMediaItemCollection' class from the 'MediaPlayer' framework. """

    MPMediaQuery = "MPMediaQuery"
    """ The 'MPMusicMPMediaQueryPlayerController' class from the 'MediaPlayer' framework. """

    MediaPlayer = "MediaPlayer"


class NamedInt(int):

    name = ""

    def __repr__(self):
        if type(MPMusicPlayerController) is str:
            return str(int(self))
        else:
            return self.name


REPEAT_MODE_DEFAULT = 0
"""
The user’s preferred repeat mode.
"""

REPEAT_MODE_NONE = 1
"""
The music player will not repeat the current song or playlist.
"""

REPEAT_MODE_ONE = 2
"""
The music player will repeat the current song.
"""

REPEAT_MODE_ALL = 3
"""
The music player will repeat the current playlist.
"""


SHUFFLE_MODE_DEFAULT = 0
"""
The user’s preferred shuffle mode.
"""

SHUFFLE_MODE_OFF = 1
"""
The playlist is not shuffled.
"""

SHUFFLE_MODE_SONGS = 2
"""
The playlist is shuffled by song.
"""

SHUFFLE_MODE_ALBUMS = 3
"""
The playlist is shuffled by album.
"""


PLAYBACK_STATE_STOPPED = NamedInt(0)
"""
The music player is stopped.
"""

PLAYBACK_STATE_PLAYING = NamedInt(1)
"""
The music player is playing.
"""

PLAYBACK_STATE_PAUSED = NamedInt(2)
"""
The music player is paused.
"""

PLAYBACK_STATE_INTERRUPTED = NamedInt(3)
"""
The music player has been interrupted, such as by an incoming phone call.
"""

PLAYBACK_STATE_SEEKING_FORWARD = NamedInt(4)
"""
The music player is seeking forward.
"""

PLAYBACK_STATE_SEEKING_BACKWARD = NamedInt(5)
"""
The music player is seeking backward.
"""

PLAYBACK_STATE_STOPPED.name = "PLAYBACK_STATE_STOPPED"
PLAYBACK_STATE_PLAYING.name = "PLAYBACK_STATE_PLAYING"
PLAYBACK_STATE_PAUSED.name = "PLAYBACK_STATE_PAUSED"
PLAYBACK_STATE_INTERRUPTED.name = "PLAYBACK_STATE_INTERRUPTED"
PLAYBACK_STATE_SEEKING_FORWARD.name = "PLAYBACK_STATE_SEEKING_FORWARD"
PLAYBACK_STATE_SEEKING_BACKWARD.name = "PLAYBACK_STATE_SEEKING_BACKWARD"


class MediaItem:
    """
    A collection of properties that represents a single item contained in the media library.
    """

    __item__ = None

    def __init__(self, item: MPMediaItem):
        self.__item__ = item

    @property
    def album_artist(self) -> str:
        """
        The primary performing artist for an album as a whole.

        :rtype: str
        """

        val = self.__item__.albumArtist
        if val is not None:
            val = str(val)
        return val

    @property
    def album_artist_persistent_id(self) -> str:
        """
        The persistent identifier for the primary performing artist for an album as a whole.

        :rtype: str
        """

        val = self.__item__.albumArtistPersistentID
        if val is not None:
            val = str(val)
        return val
    
    @property
    def album_persistent_id(self) -> str:
        """
        The persistent identifier for an album.

        :rtype: str
        """

        val = self.__item__.albumPersistentID
        if val is not None:
            val = str(val)
        return val

    @property
    def album_title(self) -> str:
        """
        The title of an album, such as “Live On Mars”, as opposed to the title of an individual song on the album, such as “Crater Dance (radio edit)”.

        :rtype: str
        """

        val = self.__item__.albumTitle
        if val is not None:
            val = str(val)
        return val

    @property
    def album_track_count(self) -> int:
        """
        The number of tracks in the album that contains the media item.

        :rtype: int
        """

        val = self.__item__.albumTrackCount
        if val is not None:
            val = int(val)
        return val

    @property
    def artist(self) -> str:
        """
        The performing artist(s) for a media item—which may vary from the primary artist for the album that a media item belongs to.

        :rtype: str
        """

        val = self.__item__.artist
        if val is not None:
            val = str(val)
        return val

    @property
    def artist_persistent_id(self) -> int:
        """
        The persistent identifier for an artist.

        :rtype: int
        """

        val = self.__item__.artistPersistentID
        if val is not None:
            val = str(val)
        return val
    
    @property
    def artwork(self) -> PIL.Image:
        """
        The artwork image for the media item.

        :rtype: PIL.Image
        """

        val = self.__item__.artwork
        if val is not None:
            val = __pil_image_from_ui_image__(val.imageWithSize(val.bounds.size))
        return val

    @property
    def beats_per_minute(self) -> int:
        """
        The number of musical beats per minute for the media item.

        :rtype: int
        """

        val = self.__item__.beatsPerMinute
        if val is not None:
            val = int(val)
        return val

    @property
    def bookmark_time(self) -> float:
        """
        The user’s place in the media item the most recent time it was played.

        :rtype: float
        """

        val = self.__item__.bookmarkTime
        if val is not None:
            val = float(val)
        return val

    @property
    def is_cloud_item(self) -> bool:
        """
        A Boolean value indicating whether the media item is an iCloud Music Library item.

        :rtype: bool
        """

        val = self.__item__.isCloudItem
        if val is not None:
            val = bool(val)
        return val

    @property
    def comments(self) -> str:
        """
        Textual information about the media item.

        :rtype: str
        """

        val = self.__item__.comments
        if val is not None:
            val = str(val)
        return val

    @property
    def is_compilation(self) -> bool:
        """
        A Boolean value indicating whether the media item is part of a compilation.

        :rtype: bool
        """

        val = self.__item__.isCompilation
        if val is not None:
            val = bool(val)
        return val

    @property
    def composer(self) -> str:
        """
        The musical composer for the media item.

        :rtype: str
        """

        val = self.__item__.composer
        if val is not None:
            val = str(val)
        return val

    @property
    def composer_persistent_id(self) -> str:
        """
        The persistent identifier for a composer.

        :rtype: str
        """

        val = self.__item__.composerPersistentID
        if val is not None:
            val = str(val)
        return val

    @property
    def date_added(self) -> str:
        """
        The date the item was added to the library.

        :rtype: str
        """

        val = self.__item__.dateAdded
        if val is not None:
            val = str(val)
        return val

    @property
    def disc_count(self) -> int:
        """
        The number of discs in the album that contains the media item.

        :rtype: int
        """

        val = self.__item__.discCount
        if val is not None:
            val = int(val)
        return val
    
    @property
    def disc_number(self) -> int:
        """
        The disc number of the media item, for a media item that is part of a multi-disc album.

        :rtype: int
        """

        val = self.__item__.discNumber
        if val is not None:
            val = int(val)
        return val

    @property
    def is_explicit_item(self) -> bool:
        """
        A Boolean value that indicates whether the item has explicit (adult) lyrics or language.

        :rtype: bool
        """

        val = self.__item__.isExplicitItem
        if val is not None:
            val = bool(val)
        return val

    @property
    def genre(self) -> str:
        """
        The musical or film genre of the media item.

        :rtype: str
        """

        val = self.__item__.genre
        if val is not None:
            val = str(val)
        return val

    @property
    def genre_persistent_id(self) -> str:
        """
        The persistent identifier for a genre.

        :rtype: str
        """

        val = self.__item__.genrePersistentID
        if val is not None:
            val = str(val)
        return val

    @property
    def last_played_date(self) -> str:
        """
        The date a media item was last played.

        :rtype: str
        """

        val = self.__item__.lastPlayedDate
        if val is not None:
            val = str(val)
        return val

    @property
    def lyrics(self) -> str:
        """
        The lyrics for the media item.

        :rtype: str
        """

        val = self.__item__.lyrics
        if val is not None:
            val = str(val)
        return val

    @property
    def persistent_id(self) -> str:
        """
        The persistent identifier for the media item.

        :rtype: str
        """

        val = self.__item__.persistentID
        if val is not None:
            val = str(val)
        return val

    @property
    def play_count(self) -> int:
        """
        The number of times the user has played the media item.

        :rtype: int
        """

        val = self.__item__.playCount
        if val is not None:
            val = int(val)
        return val
    
    @property
    def playback_duration(self) -> float:
        """
        The playback duration of the media item.

        :rtype: float
        """

        val = self.__item__.playbackDuration
        if val is not None:
            val = float(val)
        return val

    @property
    def playback_store_id(self) -> str:
        """
        The non-library identifier for a media item.

        :rtype: str
        """

        val = self.__item__.playbackStoreID
        if val is not None:
            val = str(val)
        return val

    @property 
    def podcast_persistent_id(self) -> str:
        """
        The persistent identifier for an audio podcast.

        :rtype: str
        """

        val = self.__item__.podcastPersistentID
        if val is not None:
            val = str(val)
        return val

    @property
    def podcast_title(self) -> str:
        """
        The title of a podcast, such as “This Martian Drudgery”, as opposed to the title of an individual episode of a podcast such as “Episode 12: Another Cold Day At The Pole”.

        :rtype: str
        """

        val = self.__item__.podcastTitle
        if val is not None:
            val = str(val)
        return val

    @property
    def has_protected_asset(self) -> bool:
        """
        A Boolean indicating whether the media item has a protected asset.

        :rtype: bool
        """

        val = self.__item__.hasProtectedAsset
        if val is not None:
            val = bool(val)
        return val

    @property
    def rating(self) -> int:
        """
        The user-specified rating of the object in the range [0...5], where a value of 5 indicates the most favorable rating.

        :rtype: int
        """

        val = self.__item__.rating
        if val is not None:
            val = int(val)
        return val

    @property
    def release_date(self) -> str:
        """
        The date on which the media item was first publicly released.

        :rtype: str
        """

        val = self.__item__.releaseDate
        if val is not None:
            val = str(val)
        return val
    
    @property
    def skip_count(self) -> int:
        """
        The number of times the user has skipped playing the item.

        :rtype: int
        """

        val = self.__item__.skipCount
        if val is not None:
            val = int(val)
        return val

    @property
    def title(self) -> str:
        """
        The title (or name) of the media item.

        :rtype: str
        """

        val = self.__item__.title
        if val is not None:
            val = str(val)
        return val

    @property
    def user_grouping(self) -> str:
        """
        Grouping information for the media item.

        :rtype: str
        """

        val = self.__item__.userGrouping
        if val is not None:
            val = str(val)
        return val


class MediaQuery:
    """
    A query that specifies a set of media items from the device’s media library by way of a filter and a grouping type.
    """

    __query__ = None

    def __init__(self, query: MPMediaQuery):
        self.__query__ = query

    @property
    def items(self) -> List[MediaItem]:
        """
        An array of media items that match the media query’s predicate.

        :rtype: List[MediaItem]
        """

        items = self.__query__.items
        py_items = []
        for item in items:
            py_items.append(MediaItem(item))
        return py_items

    @classmethod
    def albums(cls) -> "MediaQuery":
        """
        Creates a media query that matches music items and that groups and sorts collections by album name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.albumsQuery())

    @classmethod
    def artists(cls) -> "MediaQuery":
        """
        Creates a media query that matches music items and that groups and sorts collections by artist name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.artistsQuery())

    @classmethod
    def songs(cls) -> "MediaQuery":
        """
        Creates a media query that matches music items and that groups and sorts collections by song name.

        :rtype: MediaQuery
        """
        
        return cls(MPMediaQuery.songsQuery())

    @classmethod
    def playlists(cls) -> "MediaQuery":
        """
        Creates a media query that matches the entire library and that groups and sorts collections by playlist name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.playlistsQuery())

    @classmethod
    def podcasts(cls) -> "MediaQuery":
        """
        Creates a media query that matches podcast items and that groups and sorts collections by podcast name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.podcastsQuery())

    @classmethod
    def audiobook(cls) -> "MediaQuery":
        """
        Creates a media query that matches audio book items and that groups and sorts collections by audio book name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.audiobookQuery())

    @classmethod
    def compilations(cls) -> "MediaQuery":
        """
        Creates a media query that matches compilation items and that groups and sorts collections by album name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.compilationsQuery())

    @classmethod
    def composers(cls) -> "MediaQuery":
        """
        Creates a media query that matches all media items and that groups and sorts collections by composer name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.composersQuery())

    @classmethod
    def genres(cls) -> "MediaQuery":
        """
        Creates a media query that matches all media items and that groups and sorts collections by genre name.

        :rtype: MediaQuery
        """

        return cls(MPMediaQuery.genresQuery())


try:
    player = MPMusicPlayerController.systemMusicPlayer
except AttributeError:
    player = None


def set_queue_with_items(items: List[MediaItem]):
    """
    Sets a music player’s playback queue using a media item collection.

    :param items: An array of ``MediaItem`` that you want as the playback queue.
    """

    objc_items = []
    for item in items:
        objc_items.append(item.__item__)
    collection = MPMediaItemCollection.collectionWithItems(objc_items)
    player.setQueueWithItemCollection(collection)


def set_queue_with_store_ids(ids: List[str]):
    """
    Sets a music player's playback queue using with media items identified by the store identifiers.

    :param ids: An array of store identifiers associated with the media items to be added to the queue. 
    """

    player.setQueueWithStoreIDs(ids)


def playback_state() -> int:
    """
    The current playback state of the music player.

    :rtype: `Playback State <music.html#id3>`_
    """

    state = int(player.playbackState)
    if state == PLAYBACK_STATE_STOPPED:
        return PLAYBACK_STATE_STOPPED
    elif state == PLAYBACK_STATE_PLAYING:
        return PLAYBACK_STATE_PLAYING
    elif state == PLAYBACK_STATE_PAUSED:
        return PLAYBACK_STATE_PAUSED
    elif state == PLAYBACK_STATE_INTERRUPTED:
        return PLAYBACK_STATE_INTERRUPTED
    elif state == PLAYBACK_STATE_SEEKING_FORWARD:
        return PLAYBACK_STATE_SEEKING_FORWARD
    elif state == PLAYBACK_STATE_SEEKING_BACKWARD:
        return PLAYBACK_STATE_SEEKING_BACKWARD


def index_of_now_playing_item() -> int:
    """
    The index of the now playing item in the current playback queue.

    :rtype: int
    """

    return int(player.indexOfNowPlayingItem)


def now_playing_item() -> MediaItem:
    """
    The currently-playing media item, or the media item, within a queue, that you have designated to begin playback with.

    :rtype: MediaItem
    """

    val = player.nowPlayingItem
    if val is not None:
        val = MediaItem(val)
    return val


def set_repeat_mode(mode: int):
    """
    Sets the repeat mode of the music player.

    :param mode: The repeat mode to set. See `Repeat Mode <music.html#id1>`_ for possible values.
    """

    play.repeatMode = mode


def set_shuffle_mode(mode: int):
    """
    Sets the shuffle mode of the music player.

    :param mode: The shuffle mode to set. See `Shuffle Mode <music.html#id2>`_ for possible values.
    """

    player.shuffleMode = mode


def next():
    """
    Starts playback of the next media item in the playback queue; or, the music player is not playing, designates the next media item as the next to be played.
    """

    player.skipToNextItem()


def previous():
    """
    Starts playback of the previous media item in the playback queue; or, the music player is not playing, designates the previous media item as the next to be played.
    """

    player.skipToPreviousItem()


def restart():
    """
    Restarts playback at the beginning of the currently playing media item.
    """

    player.skipToBeginning()


def stop():
    """
    Ends playback of the current item.
    """

    player.stop()


def play():
    """
    Initiates playback of the current item.
    """

    player.play()


def pick_music() -> List[MediaItem]:
    """
    Picks music with a UI.

    Returns a list of selected items.

    :rtype: List[MediaItem]
    """

    try:
        res = PyMusicHelper.pickMusicWithScriptPath(threading.current_thread().script_path)
    except AttributeError:
        res = PyMusicHelper.pickMusicWithScriptPath(None)
    
    items = []
    for item in res:
        items.append(MediaItem(item))
    
    return items
