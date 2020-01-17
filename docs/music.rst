music
=====

.. currentmodule:: music

.. automodule:: music

Playing music
-------------

.. autofunction:: set_queue_with_items

.. autofunction:: set_queue_with_store_ids

.. autofunction:: play

.. autofunction:: stop

.. autofunction:: restart

.. autofunction:: next

.. autofunction:: previous

.. autofunction:: set_shuffle_mode

.. autofunction:: set_repeat_mode

.. autofunction:: playback_state

Now playing item
----------------

.. autofunction:: now_playing_item

.. autofunction:: index_of_now_playing_item

Picking music
-------------

.. autofunction:: pick_music

Classes
-------

.. autoclass:: MediaItem
   :members:

.. autoclass:: MediaQuery
   :members:

Objective-C classes
-------------------

.. autodata:: MPMusicPlayerController

.. autodata:: MPMediaItem

.. autodata:: MPMediaItemCollection

.. autodata:: MPMediaQuery

Constants
---------

Repeat mode
***********

.. autodata:: REPEAT_MODE_DEFAULT

.. autodata:: REPEAT_MODE_NONE

.. autodata:: REPEAT_MODE_ONE

.. autodata:: REPEAT_MODE_ALL

Shuffle mode
************

.. autodata:: SHUFFLE_MODE_DEFAULT

.. autodata:: SHUFFLE_MODE_OFF

.. autodata:: SHUFFLE_MODE_SONGS

.. autodata:: SHUFFLE_MODE_ALBUMS

Playback state
**************

.. autodata:: PLAYBACK_STATE_STOPPED

.. autodata:: PLAYBACK_STATE_PLAYING

.. autodata:: PLAYBACK_STATE_PAUSED

.. autodata:: PLAYBACK_STATE_INTERRUPTED

.. autodata:: PLAYBACK_STATE_SEEKING_FORWARD

.. autodata:: PLAYBACK_STATE_SEEKING_BACKWARD
