import pandas as pd
import bookmarks as bm

# Pick a csv file for the first time.
# Then, the previously picked file will be reused.
csv_file = bm.FileBookmark("my_csv_file")
dt = pd.read_csv(csv_file.path)
