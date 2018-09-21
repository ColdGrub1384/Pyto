"""
Opens Google with given query.
"""

import sharing
from urllib.parse import quote

query = quote(input("Search with Google: "), safe="")

sharing.openURL("https://www.google.com/search?q="+query)

