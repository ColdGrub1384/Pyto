import docutils.nodes
import docutils.parsers.rst
import docutils.utils
import docutils.frontend
import sys

def parse_rst(text: str) -> docutils.nodes.document:
    parser = docutils.parsers.rst.Parser()
    components = (docutils.parsers.rst.Parser,)
    settings = docutils.frontend.OptionParser(components=components).get_default_values()
    document = docutils.utils.new_document('<rst-doc>', settings=settings)
    parser.parse(text, document)
    return document

if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        print(parse_rst(f.read()))