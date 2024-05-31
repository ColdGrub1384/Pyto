"""
Generate HTML code with lxml and show it in a Web View.
"""

import pyto_ui as ui
from lxml import etree

web_view = ui.WebView()

# html
root_elem = etree.Element("html", lang="en_US")

#   head
head = etree.SubElement(root_elem, "head")

#     meta
etree.SubElement(head, "meta", name="viewport", content="width=device-width, initial-scale=1.0")

#     title
etree.SubElement(root_elem, "title").text = "Web Page"

#   body
body = etree.SubElement(root_elem, "body")

#     h1   
etree.SubElement(body, "h1").text = "Hello World!"

html = etree.tostring(root_elem, pretty_print=True).decode("utf-8")
web_view.load_html(html)

ui.show_view(web_view, mode=ui.PRESENTATION_MODE_SHEET)