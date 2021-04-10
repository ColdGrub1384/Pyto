""" Download a file from a url.
"""
from __future__ import print_function

import sys
import argparse

from time import monotonic

from six.moves.urllib.request import urlopen

try:
    import pasteboard as clipboard
    import console
except:
    console = None


def main(args):

    from progress.bar import ChargingBar as Bar

    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output-file", nargs="?", help="save content as file")
    ap.add_argument(
        "url", nargs="?", help="the url to read from (default to clipboard)"
    )

    ns = ap.parse_args(args)
    url = ns.url or clipboard.string()
    output_file = ns.output_file or url.split("/")[-1]

    try:

        # print('Opening: %s\n' % url)
        u = urlopen(url)

        meta = u.info()
        try:
            file_size = int(meta["Content-Length"])
        except (IndexError, ValueError, TypeError):
            file_size = 0

        # print("Save as: {} ".format(output_file), end="")
        # print("({} bytes)".format(file_size if file_size else "???"))

        with open(output_file, "wb") as f:

            file_size_dl = 0
            block_sz = 8192

            if file_size != 0 and file_size is not None:
                bar = Bar("Downloading", max=100)
            else:
                bar = None

            _n = 0

            while True:
                buf = u.read(block_sz)
                if not buf:
                    break
                file_size_dl += len(buf)
                f.write(buf)

                if bar is not None:
                    n = int(file_size_dl * 100.0 / file_size)

                    if n == _n:
                        continue

                    _n = n

                    now = monotonic()
                    dt = now - bar._ts
                    bar.update_avg(n, dt)
                    bar._ts = now
                    bar.index = n
                    bar.update()

            if bar is not None:
                bar.finish()

    except Exception as e:
        print(e)
        print("Unable to download file: %s" % url)
        return 1

    return 0


if __name__ == "__main__":
    main(sys.argv[1:])
