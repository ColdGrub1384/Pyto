"""
Shows the 10 artist with more songs in the music library and then plays a random song from the selected artist.
"""

import music
from random import shuffle
from collections import Counter
from os import environ
from colorama import Style
from shutil import get_terminal_size

##################
# Top 10 artists #
##################

artist_counter = Counter()
songs = []

query = music.MediaQuery.songs()
for item in query.items:
    artist_counter[item.artist] += 1
    songs.append(item)

most_common = artist_counter.most_common(10)

if len(artist_counter) == 0:
	raise RuntimeError("You don't seem to have any music in your library.")
else:
	print("Most common artists in your music library:")
	print("=" * get_terminal_size().columns)
	for i, (artist, count) in enumerate(most_common):
		print(f"{Style.BRIGHT}%i{Style.RESET_ALL}. %s (%i songs)" % (i+1, artist, count))

########################
# Play songs by artist #
########################

print()
i = int(input("Type the index of an artist to play a random song by it: "))-1

artist = most_common[i][0]
songs_by_artist = []
for song in songs:
    if song.artist == artist:
        songs_by_artist.append(song)

shuffle(songs_by_artist)

music.set_queue_with_items(songs_by_artist)
music.play()
