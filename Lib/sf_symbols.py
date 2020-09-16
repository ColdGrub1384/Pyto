"""
SF Symbols

SF Symbols were introduced in iOS 13. They are system images that can be used in any app.
This library contains the name of every SF Symbol.

.. warning::
   This library requires iOS 14+

Usage
-----

*pyto_ui*

.. highlight:: python
.. code-block:: python

    import pyto_ui as ui
    import sy_symbols as sf

    image = ui.ImageView(symbol_name=sf.PERSON_CIRCLE)

*widgets*

.. highlight:: python
.. code-block:: python

    import widgets as wg
    import sy_symbols as sf

    image = wg.SystemSymbol(sf.PERSON_CIRCLE)

"""

from UIKit import UIDevice
import sys

if UIDevice is not None and float(str(UIDevice.currentDevice.systemVersion).split(".")[0]) < 14:
    raise ImportError("Home Screen Widgets were introduced on iPadOS / iOS 14.")


class Symbol(str):

    def __repr__(self):
        if "sphinx" in sys.modules:
            return ""
        else:
            return "Symbol '"+self+"'"


SQUARE_AND_ARROW_UP = Symbol("square.and.arrow.up")
""" 'square.and.arrow.up' symbol """

SQUARE_AND_ARROW_UP_FILL = Symbol("square.and.arrow.up.fill")
""" 'square.and.arrow.up.fill' symbol """

SQUARE_AND_ARROW_DOWN = Symbol("square.and.arrow.down")
""" 'square.and.arrow.down' symbol """

SQUARE_AND_ARROW_DOWN_FILL = Symbol("square.and.arrow.down.fill")
""" 'square.and.arrow.down.fill' symbol """

SQUARE_AND_ARROW_UP_ON_SQUARE = Symbol("square.and.arrow.up.on.square")
""" 'square.and.arrow.up.on.square' symbol """

SQUARE_AND_ARROW_UP_ON_SQUARE_FILL = Symbol("square.and.arrow.up.on.square.fill")
""" 'square.and.arrow.up.on.square.fill' symbol """

SQUARE_AND_ARROW_DOWN_ON_SQUARE = Symbol("square.and.arrow.down.on.square")
""" 'square.and.arrow.down.on.square' symbol """

SQUARE_AND_ARROW_DOWN_ON_SQUARE_FILL = Symbol("square.and.arrow.down.on.square.fill")
""" 'square.and.arrow.down.on.square.fill' symbol """

PENCIL = Symbol("pencil")
""" 'pencil' symbol """

PENCIL_CIRCLE = Symbol("pencil.circle")
""" 'pencil.circle' symbol """

PENCIL_CIRCLE_FILL = Symbol("pencil.circle.fill")
""" 'pencil.circle.fill' symbol """

PENCIL_SLASH = Symbol("pencil.slash")
""" 'pencil.slash' symbol """

SQUARE_AND_PENCIL = Symbol("square.and.pencil")
""" 'square.and.pencil' symbol """

RECTANGLE_AND_PENCIL_AND_ELLIPSIS = Symbol("rectangle.and.pencil.and.ellipsis")
""" 'rectangle.and.pencil.and.ellipsis' symbol """

SCRIBBLE = Symbol("scribble")
""" 'scribble' symbol """

SCRIBBLE_VARIABLE = Symbol("scribble.variable")
""" 'scribble.variable' symbol """

HIGHLIGHTER = Symbol("highlighter")
""" 'highlighter' symbol """

PENCIL_AND_OUTLINE = Symbol("pencil.and.outline")
""" 'pencil.and.outline' symbol """

PENCIL_TIP = Symbol("pencil.tip")
""" 'pencil.tip' symbol """

PENCIL_TIP_CROP_CIRCLE = Symbol("pencil.tip.crop.circle")
""" 'pencil.tip.crop.circle' symbol """

PENCIL_TIP_CROP_CIRCLE_BADGE_PLUS = Symbol("pencil.tip.crop.circle.badge.plus")
""" 'pencil.tip.crop.circle.badge.plus' symbol """

PENCIL_TIP_CROP_CIRCLE_BADGE_MINUS = Symbol("pencil.tip.crop.circle.badge.minus")
""" 'pencil.tip.crop.circle.badge.minus' symbol """

PENCIL_TIP_CROP_CIRCLE_BADGE_ARROW_RIGHT = Symbol("pencil.tip.crop.circle.badge.arrow.right")
""" 'pencil.tip.crop.circle.badge.arrow.right' symbol """

LASSO = Symbol("lasso")
""" 'lasso' symbol """

LASSO_SPARKLES = Symbol("lasso.sparkles")
""" 'lasso.sparkles' symbol """

TRASH = Symbol("trash")
""" 'trash' symbol """

TRASH_FILL = Symbol("trash.fill")
""" 'trash.fill' symbol """

TRASH_CIRCLE = Symbol("trash.circle")
""" 'trash.circle' symbol """

TRASH_CIRCLE_FILL = Symbol("trash.circle.fill")
""" 'trash.circle.fill' symbol """

TRASH_SLASH = Symbol("trash.slash")
""" 'trash.slash' symbol """

TRASH_SLASH_FILL = Symbol("trash.slash.fill")
""" 'trash.slash.fill' symbol """

FOLDER = Symbol("folder")
""" 'folder' symbol """

FOLDER_FILL = Symbol("folder.fill")
""" 'folder.fill' symbol """

FOLDER_CIRCLE = Symbol("folder.circle")
""" 'folder.circle' symbol """

FOLDER_CIRCLE_FILL = Symbol("folder.circle.fill")
""" 'folder.circle.fill' symbol """

FOLDER_BADGE_PLUS = Symbol("folder.badge.plus")
""" 'folder.badge.plus' symbol """

FOLDER_FILL_BADGE_PLUS = Symbol("folder.fill.badge.plus")
""" 'folder.fill.badge.plus' symbol """

FOLDER_BADGE_MINUS = Symbol("folder.badge.minus")
""" 'folder.badge.minus' symbol """

FOLDER_FILL_BADGE_MINUS = Symbol("folder.fill.badge.minus")
""" 'folder.fill.badge.minus' symbol """

FOLDER_BADGE_QUESTIONMARK = Symbol("folder.badge.questionmark")
""" 'folder.badge.questionmark' symbol """

FOLDER_FILL_BADGE_QUESTIONMARK = Symbol("folder.fill.badge.questionmark")
""" 'folder.fill.badge.questionmark' symbol """

FOLDER_BADGE_PERSON_CROP = Symbol("folder.badge.person.crop")
""" 'folder.badge.person.crop' symbol """

FOLDER_FILL_BADGE_PERSON_CROP = Symbol("folder.fill.badge.person.crop")
""" 'folder.fill.badge.person.crop' symbol """

SQUARE_GRID_3X1_FOLDER_BADGE_PLUS = Symbol("square.grid.3x1.folder.badge.plus")
""" 'square.grid.3x1.folder.badge.plus' symbol """

SQUARE_GRID_3X1_FOLDER_FILL_BADGE_PLUS = Symbol("square.grid.3x1.folder.fill.badge.plus")
""" 'square.grid.3x1.folder.fill.badge.plus' symbol """

FOLDER_BADGE_GEAR = Symbol("folder.badge.gear")
""" 'folder.badge.gear' symbol """

FOLDER_FILL_BADGE_GEAR = Symbol("folder.fill.badge.gear")
""" 'folder.fill.badge.gear' symbol """

PLUS_RECTANGLE_ON_FOLDER = Symbol("plus.rectangle.on.folder")
""" 'plus.rectangle.on.folder' symbol """

PLUS_RECTANGLE_FILL_ON_FOLDER_FILL = Symbol("plus.rectangle.fill.on.folder.fill")
""" 'plus.rectangle.fill.on.folder.fill' symbol """

QUESTIONMARK_FOLDER = Symbol("questionmark.folder")
""" 'questionmark.folder' symbol """

QUESTIONMARK_FOLDER_FILL = Symbol("questionmark.folder.fill")
""" 'questionmark.folder.fill' symbol """

PAPERPLANE = Symbol("paperplane")
""" 'paperplane' symbol """

PAPERPLANE_FILL = Symbol("paperplane.fill")
""" 'paperplane.fill' symbol """

PAPERPLANE_CIRCLE = Symbol("paperplane.circle")
""" 'paperplane.circle' symbol """

PAPERPLANE_CIRCLE_FILL = Symbol("paperplane.circle.fill")
""" 'paperplane.circle.fill' symbol """

TRAY = Symbol("tray")
""" 'tray' symbol """

TRAY_FILL = Symbol("tray.fill")
""" 'tray.fill' symbol """

TRAY_CIRCLE = Symbol("tray.circle")
""" 'tray.circle' symbol """

TRAY_CIRCLE_FILL = Symbol("tray.circle.fill")
""" 'tray.circle.fill' symbol """

TRAY_AND_ARROW_UP = Symbol("tray.and.arrow.up")
""" 'tray.and.arrow.up' symbol """

TRAY_AND_ARROW_UP_FILL = Symbol("tray.and.arrow.up.fill")
""" 'tray.and.arrow.up.fill' symbol """

TRAY_AND_ARROW_DOWN = Symbol("tray.and.arrow.down")
""" 'tray.and.arrow.down' symbol """

TRAY_AND_ARROW_DOWN_FILL = Symbol("tray.and.arrow.down.fill")
""" 'tray.and.arrow.down.fill' symbol """

TRAY_2 = Symbol("tray.2")
""" 'tray.2' symbol """

TRAY_2_FILL = Symbol("tray.2.fill")
""" 'tray.2.fill' symbol """

TRAY_FULL = Symbol("tray.full")
""" 'tray.full' symbol """

TRAY_FULL_FILL = Symbol("tray.full.fill")
""" 'tray.full.fill' symbol """

EXTERNALDRIVE = Symbol("externaldrive")
""" 'externaldrive' symbol """

EXTERNALDRIVE_FILL = Symbol("externaldrive.fill")
""" 'externaldrive.fill' symbol """

EXTERNALDRIVE_BADGE_PLUS = Symbol("externaldrive.badge.plus")
""" 'externaldrive.badge.plus' symbol """

EXTERNALDRIVE_FILL_BADGE_PLUS = Symbol("externaldrive.fill.badge.plus")
""" 'externaldrive.fill.badge.plus' symbol """

EXTERNALDRIVE_BADGE_MINUS = Symbol("externaldrive.badge.minus")
""" 'externaldrive.badge.minus' symbol """

EXTERNALDRIVE_FILL_BADGE_MINUS = Symbol("externaldrive.fill.badge.minus")
""" 'externaldrive.fill.badge.minus' symbol """

EXTERNALDRIVE_BADGE_CHECKMARK = Symbol("externaldrive.badge.checkmark")
""" 'externaldrive.badge.checkmark' symbol """

EXTERNALDRIVE_FILL_BADGE_CHECKMARK = Symbol("externaldrive.fill.badge.checkmark")
""" 'externaldrive.fill.badge.checkmark' symbol """

EXTERNALDRIVE_BADGE_XMARK = Symbol("externaldrive.badge.xmark")
""" 'externaldrive.badge.xmark' symbol """

EXTERNALDRIVE_FILL_BADGE_XMARK = Symbol("externaldrive.fill.badge.xmark")
""" 'externaldrive.fill.badge.xmark' symbol """

EXTERNALDRIVE_BADGE_PERSON_CROP = Symbol("externaldrive.badge.person.crop")
""" 'externaldrive.badge.person.crop' symbol """

EXTERNALDRIVE_FILL_BADGE_PERSON_CROP = Symbol("externaldrive.fill.badge.person.crop")
""" 'externaldrive.fill.badge.person.crop' symbol """

EXTERNALDRIVE_BADGE_ICLOUD = Symbol("externaldrive.badge.icloud")
""" 'externaldrive.badge.icloud' symbol """

EXTERNALDRIVE_FILL_BADGE_ICLOUD = Symbol("externaldrive.fill.badge.icloud")
""" 'externaldrive.fill.badge.icloud' symbol """

EXTERNALDRIVE_BADGE_WIFI = Symbol("externaldrive.badge.wifi")
""" 'externaldrive.badge.wifi' symbol """

EXTERNALDRIVE_FILL_BADGE_WIFI = Symbol("externaldrive.fill.badge.wifi")
""" 'externaldrive.fill.badge.wifi' symbol """

EXTERNALDRIVE_BADGE_TIMEMACHINE = Symbol("externaldrive.badge.timemachine")
""" 'externaldrive.badge.timemachine' symbol """

EXTERNALDRIVE_FILL_BADGE_TIMEMACHINE = Symbol("externaldrive.fill.badge.timemachine")
""" 'externaldrive.fill.badge.timemachine' symbol """

INTERNALDRIVE = Symbol("internaldrive")
""" 'internaldrive' symbol """

INTERNALDRIVE_FILL = Symbol("internaldrive.fill")
""" 'internaldrive.fill' symbol """

OPTICALDISCDRIVE = Symbol("opticaldiscdrive")
""" 'opticaldiscdrive' symbol """

OPTICALDISCDRIVE_FILL = Symbol("opticaldiscdrive.fill")
""" 'opticaldiscdrive.fill' symbol """

EXTERNALDRIVE_CONNECTED_TO_LINE_BELOW = Symbol("externaldrive.connected.to.line.below")
""" 'externaldrive.connected.to.line.below' symbol """

EXTERNALDRIVE_CONNECTED_TO_LINE_BELOW_FILL = Symbol("externaldrive.connected.to.line.below.fill")
""" 'externaldrive.connected.to.line.below.fill' symbol """

ARCHIVEBOX = Symbol("archivebox")
""" 'archivebox' symbol """

ARCHIVEBOX_FILL = Symbol("archivebox.fill")
""" 'archivebox.fill' symbol """

ARCHIVEBOX_CIRCLE = Symbol("archivebox.circle")
""" 'archivebox.circle' symbol """

ARCHIVEBOX_CIRCLE_FILL = Symbol("archivebox.circle.fill")
""" 'archivebox.circle.fill' symbol """

XMARK_BIN = Symbol("xmark.bin")
""" 'xmark.bin' symbol """

XMARK_BIN_FILL = Symbol("xmark.bin.fill")
""" 'xmark.bin.fill' symbol """

XMARK_BIN_CIRCLE = Symbol("xmark.bin.circle")
""" 'xmark.bin.circle' symbol """

XMARK_BIN_CIRCLE_FILL = Symbol("xmark.bin.circle.fill")
""" 'xmark.bin.circle.fill' symbol """

ARROW_UP_BIN = Symbol("arrow.up.bin")
""" 'arrow.up.bin' symbol """

ARROW_UP_BIN_FILL = Symbol("arrow.up.bin.fill")
""" 'arrow.up.bin.fill' symbol """

DOC = Symbol("doc")
""" 'doc' symbol """

DOC_FILL = Symbol("doc.fill")
""" 'doc.fill' symbol """

DOC_CIRCLE = Symbol("doc.circle")
""" 'doc.circle' symbol """

DOC_CIRCLE_FILL = Symbol("doc.circle.fill")
""" 'doc.circle.fill' symbol """

DOC_BADGE_PLUS = Symbol("doc.badge.plus")
""" 'doc.badge.plus' symbol """

DOC_FILL_BADGE_PLUS = Symbol("doc.fill.badge.plus")
""" 'doc.fill.badge.plus' symbol """

DOC_BADGE_GEARSHAPE = Symbol("doc.badge.gearshape")
""" 'doc.badge.gearshape' symbol """

DOC_BADGE_GEARSHAPE_FILL = Symbol("doc.badge.gearshape.fill")
""" 'doc.badge.gearshape.fill' symbol """

DOC_BADGE_ELLIPSIS = Symbol("doc.badge.ellipsis")
""" 'doc.badge.ellipsis' symbol """

DOC_FILL_BADGE_ELLIPSIS = Symbol("doc.fill.badge.ellipsis")
""" 'doc.fill.badge.ellipsis' symbol """

LOCK_DOC = Symbol("lock.doc")
""" 'lock.doc' symbol """

LOCK_DOC_FILL = Symbol("lock.doc.fill")
""" 'lock.doc.fill' symbol """

ARROW_UP_DOC = Symbol("arrow.up.doc")
""" 'arrow.up.doc' symbol """

ARROW_UP_DOC_FILL = Symbol("arrow.up.doc.fill")
""" 'arrow.up.doc.fill' symbol """

ARROW_DOWN_DOC = Symbol("arrow.down.doc")
""" 'arrow.down.doc' symbol """

ARROW_DOWN_DOC_FILL = Symbol("arrow.down.doc.fill")
""" 'arrow.down.doc.fill' symbol """

DOC_TEXT = Symbol("doc.text")
""" 'doc.text' symbol """

DOC_TEXT_FILL = Symbol("doc.text.fill")
""" 'doc.text.fill' symbol """

DOC_ZIPPER = Symbol("doc.zipper")
""" 'doc.zipper' symbol """

DOC_ON_DOC = Symbol("doc.on.doc")
""" 'doc.on.doc' symbol """

DOC_ON_DOC_FILL = Symbol("doc.on.doc.fill")
""" 'doc.on.doc.fill' symbol """

DOC_ON_CLIPBOARD = Symbol("doc.on.clipboard")
""" 'doc.on.clipboard' symbol """

ARROW_RIGHT_DOC_ON_CLIPBOARD = Symbol("arrow.right.doc.on.clipboard")
""" 'arrow.right.doc.on.clipboard' symbol """

ARROW_UP_DOC_ON_CLIPBOARD = Symbol("arrow.up.doc.on.clipboard")
""" 'arrow.up.doc.on.clipboard' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH_DOC_ON_CLIPBOARD = Symbol("arrow.triangle.2.circlepath.doc.on.clipboard")
""" 'arrow.triangle.2.circlepath.doc.on.clipboard' symbol """

DOC_ON_CLIPBOARD_FILL = Symbol("doc.on.clipboard.fill")
""" 'doc.on.clipboard.fill' symbol """

DOC_RICHTEXT = Symbol("doc.richtext")
""" 'doc.richtext' symbol """

DOC_RICHTEXT_FILL = Symbol("doc.richtext.fill")
""" 'doc.richtext.fill' symbol """

DOC_PLAINTEXT = Symbol("doc.plaintext")
""" 'doc.plaintext' symbol """

DOC_PLAINTEXT_FILL = Symbol("doc.plaintext.fill")
""" 'doc.plaintext.fill' symbol """

DOC_APPEND = Symbol("doc.append")
""" 'doc.append' symbol """

DOC_APPEND_FILL = Symbol("doc.append.fill")
""" 'doc.append.fill' symbol """

CHART_BAR_DOC_HORIZONTAL = Symbol("chart.bar.doc.horizontal")
""" 'chart.bar.doc.horizontal' symbol """

CHART_BAR_DOC_HORIZONTAL_FILL = Symbol("chart.bar.doc.horizontal.fill")
""" 'chart.bar.doc.horizontal.fill' symbol """

LIST_BULLET_RECTANGLE = Symbol("list.bullet.rectangle")
""" 'list.bullet.rectangle' symbol """

DOC_TEXT_MAGNIFYINGGLASS = Symbol("doc.text.magnifyingglass")
""" 'doc.text.magnifyingglass' symbol """

NOTE = Symbol("note")
""" 'note' symbol """

NOTE_TEXT = Symbol("note.text")
""" 'note.text' symbol """

NOTE_TEXT_BADGE_PLUS = Symbol("note.text.badge.plus")
""" 'note.text.badge.plus' symbol """

CALENDAR = Symbol("calendar")
""" 'calendar' symbol """

CALENDAR_CIRCLE = Symbol("calendar.circle")
""" 'calendar.circle' symbol """

CALENDAR_CIRCLE_FILL = Symbol("calendar.circle.fill")
""" 'calendar.circle.fill' symbol """

CALENDAR_BADGE_PLUS = Symbol("calendar.badge.plus")
""" 'calendar.badge.plus' symbol """

CALENDAR_BADGE_MINUS = Symbol("calendar.badge.minus")
""" 'calendar.badge.minus' symbol """

CALENDAR_BADGE_CLOCK = Symbol("calendar.badge.clock")
""" 'calendar.badge.clock' symbol """

CALENDAR_BADGE_EXCLAMATIONMARK = Symbol("calendar.badge.exclamationmark")
""" 'calendar.badge.exclamationmark' symbol """

ARROWSHAPE_TURN_UP_LEFT = Symbol("arrowshape.turn.up.left")
""" 'arrowshape.turn.up.left' symbol """

ARROWSHAPE_TURN_UP_LEFT_FILL = Symbol("arrowshape.turn.up.left.fill")
""" 'arrowshape.turn.up.left.fill' symbol """

ARROWSHAPE_TURN_UP_LEFT_CIRCLE = Symbol("arrowshape.turn.up.left.circle")
""" 'arrowshape.turn.up.left.circle' symbol """

ARROWSHAPE_TURN_UP_LEFT_CIRCLE_FILL = Symbol("arrowshape.turn.up.left.circle.fill")
""" 'arrowshape.turn.up.left.circle.fill' symbol """

ARROWSHAPE_TURN_UP_RIGHT = Symbol("arrowshape.turn.up.right")
""" 'arrowshape.turn.up.right' symbol """

ARROWSHAPE_TURN_UP_RIGHT_FILL = Symbol("arrowshape.turn.up.right.fill")
""" 'arrowshape.turn.up.right.fill' symbol """

ARROWSHAPE_TURN_UP_RIGHT_CIRCLE = Symbol("arrowshape.turn.up.right.circle")
""" 'arrowshape.turn.up.right.circle' symbol """

ARROWSHAPE_TURN_UP_RIGHT_CIRCLE_FILL = Symbol("arrowshape.turn.up.right.circle.fill")
""" 'arrowshape.turn.up.right.circle.fill' symbol """

ARROWSHAPE_TURN_UP_LEFT_2 = Symbol("arrowshape.turn.up.left.2")
""" 'arrowshape.turn.up.left.2' symbol """

ARROWSHAPE_TURN_UP_LEFT_2_FILL = Symbol("arrowshape.turn.up.left.2.fill")
""" 'arrowshape.turn.up.left.2.fill' symbol """

ARROWSHAPE_TURN_UP_LEFT_2_CIRCLE = Symbol("arrowshape.turn.up.left.2.circle")
""" 'arrowshape.turn.up.left.2.circle' symbol """

ARROWSHAPE_TURN_UP_LEFT_2_CIRCLE_FILL = Symbol("arrowshape.turn.up.left.2.circle.fill")
""" 'arrowshape.turn.up.left.2.circle.fill' symbol """

ARROWSHAPE_ZIGZAG_RIGHT = Symbol("arrowshape.zigzag.right")
""" 'arrowshape.zigzag.right' symbol """

ARROWSHAPE_ZIGZAG_RIGHT_FILL = Symbol("arrowshape.zigzag.right.fill")
""" 'arrowshape.zigzag.right.fill' symbol """

ARROWSHAPE_BOUNCE_RIGHT = Symbol("arrowshape.bounce.right")
""" 'arrowshape.bounce.right' symbol """

ARROWSHAPE_BOUNCE_RIGHT_FILL = Symbol("arrowshape.bounce.right.fill")
""" 'arrowshape.bounce.right.fill' symbol """

BOOK = Symbol("book")
""" 'book' symbol """

BOOK_FILL = Symbol("book.fill")
""" 'book.fill' symbol """

BOOK_CIRCLE = Symbol("book.circle")
""" 'book.circle' symbol """

BOOK_CIRCLE_FILL = Symbol("book.circle.fill")
""" 'book.circle.fill' symbol """

NEWSPAPER = Symbol("newspaper")
""" 'newspaper' symbol """

NEWSPAPER_FILL = Symbol("newspaper.fill")
""" 'newspaper.fill' symbol """

BOOKS_VERTICAL = Symbol("books.vertical")
""" 'books.vertical' symbol """

BOOKS_VERTICAL_FILL = Symbol("books.vertical.fill")
""" 'books.vertical.fill' symbol """

BOOK_CLOSED = Symbol("book.closed")
""" 'book.closed' symbol """

BOOK_CLOSED_FILL = Symbol("book.closed.fill")
""" 'book.closed.fill' symbol """

A_BOOK_CLOSED = Symbol("a.book.closed")
""" 'a.book.closed' symbol """

A_BOOK_CLOSED_FILL = Symbol("a.book.closed.fill")
""" 'a.book.closed.fill' symbol """

TEXT_BOOK_CLOSED = Symbol("text.book.closed")
""" 'text.book.closed' symbol """

TEXT_BOOK_CLOSED_FILL = Symbol("text.book.closed.fill")
""" 'text.book.closed.fill' symbol """

GREETINGCARD = Symbol("greetingcard")
""" 'greetingcard' symbol """

GREETINGCARD_FILL = Symbol("greetingcard.fill")
""" 'greetingcard.fill' symbol """

BOOKMARK = Symbol("bookmark")
""" 'bookmark' symbol """

BOOKMARK_FILL = Symbol("bookmark.fill")
""" 'bookmark.fill' symbol """

BOOKMARK_CIRCLE = Symbol("bookmark.circle")
""" 'bookmark.circle' symbol """

BOOKMARK_CIRCLE_FILL = Symbol("bookmark.circle.fill")
""" 'bookmark.circle.fill' symbol """

BOOKMARK_SLASH = Symbol("bookmark.slash")
""" 'bookmark.slash' symbol """

BOOKMARK_SLASH_FILL = Symbol("bookmark.slash.fill")
""" 'bookmark.slash.fill' symbol """

ROSETTE = Symbol("rosette")
""" 'rosette' symbol """

GRADUATIONCAP = Symbol("graduationcap")
""" 'graduationcap' symbol """

GRADUATIONCAP_FILL = Symbol("graduationcap.fill")
""" 'graduationcap.fill' symbol """

TICKET = Symbol("ticket")
""" 'ticket' symbol """

TICKET_FILL = Symbol("ticket.fill")
""" 'ticket.fill' symbol """

PAPERCLIP = Symbol("paperclip")
""" 'paperclip' symbol """

PAPERCLIP_CIRCLE = Symbol("paperclip.circle")
""" 'paperclip.circle' symbol """

PAPERCLIP_CIRCLE_FILL = Symbol("paperclip.circle.fill")
""" 'paperclip.circle.fill' symbol """

PAPERCLIP_BADGE_ELLIPSIS = Symbol("paperclip.badge.ellipsis")
""" 'paperclip.badge.ellipsis' symbol """

RECTANGLE_AND_PAPERCLIP = Symbol("rectangle.and.paperclip")
""" 'rectangle.and.paperclip' symbol """

RECTANGLE_DASHED_AND_PAPERCLIP = Symbol("rectangle.dashed.and.paperclip")
""" 'rectangle.dashed.and.paperclip' symbol """

LINK = Symbol("link")
""" 'link' symbol """

LINK_CIRCLE = Symbol("link.circle")
""" 'link.circle' symbol """

LINK_CIRCLE_FILL = Symbol("link.circle.fill")
""" 'link.circle.fill' symbol """

LINK_BADGE_PLUS = Symbol("link.badge.plus")
""" 'link.badge.plus' symbol """

PERSONALHOTSPOT = Symbol("personalhotspot")
""" 'personalhotspot' symbol """

LINEWEIGHT = Symbol("lineweight")
""" 'lineweight' symbol """

PERSON = Symbol("person")
""" 'person' symbol """

PERSON_FILL = Symbol("person.fill")
""" 'person.fill' symbol """

PERSON_FILL_TURN_RIGHT = Symbol("person.fill.turn.right")
""" 'person.fill.turn.right' symbol """

PERSON_FILL_TURN_DOWN = Symbol("person.fill.turn.down")
""" 'person.fill.turn.down' symbol """

PERSON_FILL_TURN_LEFT = Symbol("person.fill.turn.left")
""" 'person.fill.turn.left' symbol """

PERSON_FILL_CHECKMARK = Symbol("person.fill.checkmark")
""" 'person.fill.checkmark' symbol """

PERSON_FILL_XMARK = Symbol("person.fill.xmark")
""" 'person.fill.xmark' symbol """

PERSON_FILL_QUESTIONMARK = Symbol("person.fill.questionmark")
""" 'person.fill.questionmark' symbol """

PERSON_CIRCLE = Symbol("person.circle")
""" 'person.circle' symbol """

PERSON_CIRCLE_FILL = Symbol("person.circle.fill")
""" 'person.circle.fill' symbol """

PERSON_BADGE_PLUS = Symbol("person.badge.plus")
""" 'person.badge.plus' symbol """

PERSON_FILL_BADGE_PLUS = Symbol("person.fill.badge.plus")
""" 'person.fill.badge.plus' symbol """

PERSON_BADGE_MINUS = Symbol("person.badge.minus")
""" 'person.badge.minus' symbol """

PERSON_FILL_BADGE_MINUS = Symbol("person.fill.badge.minus")
""" 'person.fill.badge.minus' symbol """

PERSON_AND_ARROW_LEFT_AND_ARROW_RIGHT = Symbol("person.and.arrow.left.and.arrow.right")
""" 'person.and.arrow.left.and.arrow.right' symbol """

PERSON_FILL_AND_ARROW_LEFT_AND_ARROW_RIGHT = Symbol("person.fill.and.arrow.left.and.arrow.right")
""" 'person.fill.and.arrow.left.and.arrow.right' symbol """

PERSON_2 = Symbol("person.2")
""" 'person.2' symbol """

PERSON_2_FILL = Symbol("person.2.fill")
""" 'person.2.fill' symbol """

PERSON_2_CIRCLE = Symbol("person.2.circle")
""" 'person.2.circle' symbol """

PERSON_2_CIRCLE_FILL = Symbol("person.2.circle.fill")
""" 'person.2.circle.fill' symbol """

PERSON_3 = Symbol("person.3")
""" 'person.3' symbol """

PERSON_3_FILL = Symbol("person.3.fill")
""" 'person.3.fill' symbol """

PERSON_CROP_CIRCLE = Symbol("person.crop.circle")
""" 'person.crop.circle' symbol """

PERSON_CROP_CIRCLE_FILL = Symbol("person.crop.circle.fill")
""" 'person.crop.circle.fill' symbol """

PERSON_CROP_CIRCLE_BADGE_PLUS = Symbol("person.crop.circle.badge.plus")
""" 'person.crop.circle.badge.plus' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_PLUS = Symbol("person.crop.circle.fill.badge.plus")
""" 'person.crop.circle.fill.badge.plus' symbol """

PERSON_CROP_CIRCLE_BADGE_MINUS = Symbol("person.crop.circle.badge.minus")
""" 'person.crop.circle.badge.minus' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_MINUS = Symbol("person.crop.circle.fill.badge.minus")
""" 'person.crop.circle.fill.badge.minus' symbol """

PERSON_CROP_CIRCLE_BADGE_CHECKMARK = Symbol("person.crop.circle.badge.checkmark")
""" 'person.crop.circle.badge.checkmark' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_CHECKMARK = Symbol("person.crop.circle.fill.badge.checkmark")
""" 'person.crop.circle.fill.badge.checkmark' symbol """

PERSON_CROP_CIRCLE_BADGE_XMARK = Symbol("person.crop.circle.badge.xmark")
""" 'person.crop.circle.badge.xmark' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_XMARK = Symbol("person.crop.circle.fill.badge.xmark")
""" 'person.crop.circle.fill.badge.xmark' symbol """

PERSON_CROP_CIRCLE_BADGE_QUESTIONMARK = Symbol("person.crop.circle.badge.questionmark")
""" 'person.crop.circle.badge.questionmark' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_QUESTIONMARK = Symbol("person.crop.circle.fill.badge.questionmark")
""" 'person.crop.circle.fill.badge.questionmark' symbol """

PERSON_CROP_CIRCLE_BADGE_EXCLAMATIONMARK = Symbol("person.crop.circle.badge.exclamationmark")
""" 'person.crop.circle.badge.exclamationmark' symbol """

PERSON_CROP_CIRCLE_FILL_BADGE_EXCLAMATIONMARK = Symbol("person.crop.circle.fill.badge.exclamationmark")
""" 'person.crop.circle.fill.badge.exclamationmark' symbol """

PERSON_CROP_SQUARE = Symbol("person.crop.square")
""" 'person.crop.square' symbol """

PERSON_CROP_SQUARE_FILL = Symbol("person.crop.square.fill")
""" 'person.crop.square.fill' symbol """

RECTANGLE_STACK_PERSON_CROP = Symbol("rectangle.stack.person.crop")
""" 'rectangle.stack.person.crop' symbol """

RECTANGLE_STACK_PERSON_CROP_FILL = Symbol("rectangle.stack.person.crop.fill")
""" 'rectangle.stack.person.crop.fill' symbol """

PERSON_2_SQUARE_STACK = Symbol("person.2.square.stack")
""" 'person.2.square.stack' symbol """

PERSON_2_SQUARE_STACK_FILL = Symbol("person.2.square.stack.fill")
""" 'person.2.square.stack.fill' symbol """

PERSON_CROP_SQUARE_FILL_AND_AT_RECTANGLE = Symbol("person.crop.square.fill.and.at.rectangle")
""" 'person.crop.square.fill.and.at.rectangle' symbol """

SQUARE_AND_AT_RECTANGLE = Symbol("square.and.at.rectangle")
""" 'square.and.at.rectangle' symbol """

COMMAND = Symbol("command")
""" 'command' symbol """

COMMAND_CIRCLE = Symbol("command.circle")
""" 'command.circle' symbol """

COMMAND_CIRCLE_FILL = Symbol("command.circle.fill")
""" 'command.circle.fill' symbol """

COMMAND_SQUARE = Symbol("command.square")
""" 'command.square' symbol """

COMMAND_SQUARE_FILL = Symbol("command.square.fill")
""" 'command.square.fill' symbol """

OPTION = Symbol("option")
""" 'option' symbol """

ALT = Symbol("alt")
""" 'alt' symbol """

DELETE_RIGHT = Symbol("delete.right")
""" 'delete.right' symbol """

DELETE_RIGHT_FILL = Symbol("delete.right.fill")
""" 'delete.right.fill' symbol """

CLEAR = Symbol("clear")
""" 'clear' symbol """

CLEAR_FILL = Symbol("clear.fill")
""" 'clear.fill' symbol """

DELETE_LEFT = Symbol("delete.left")
""" 'delete.left' symbol """

DELETE_LEFT_FILL = Symbol("delete.left.fill")
""" 'delete.left.fill' symbol """

SHIFT = Symbol("shift")
""" 'shift' symbol """

SHIFT_FILL = Symbol("shift.fill")
""" 'shift.fill' symbol """

CAPSLOCK = Symbol("capslock")
""" 'capslock' symbol """

CAPSLOCK_FILL = Symbol("capslock.fill")
""" 'capslock.fill' symbol """

ESCAPE = Symbol("escape")
""" 'escape' symbol """

RESTART = Symbol("restart")
""" 'restart' symbol """

RESTART_CIRCLE = Symbol("restart.circle")
""" 'restart.circle' symbol """

SLEEP = Symbol("sleep")
""" 'sleep' symbol """

WAKE = Symbol("wake")
""" 'wake' symbol """

POWER = Symbol("power")
""" 'power' symbol """

DOT_ARROWTRIANGLES_UP_RIGHT_DOWN_LEFT_CIRCLE = Symbol("dot.arrowtriangles.up.right.down.left.circle")
""" 'dot.arrowtriangles.up.right.down.left.circle' symbol """

GLOBE = Symbol("globe")
""" 'globe' symbol """

NETWORK = Symbol("network")
""" 'network' symbol """

SUN_MIN = Symbol("sun.min")
""" 'sun.min' symbol """

SUN_MIN_FILL = Symbol("sun.min.fill")
""" 'sun.min.fill' symbol """

SUN_MAX = Symbol("sun.max")
""" 'sun.max' symbol """

SUN_MAX_FILL = Symbol("sun.max.fill")
""" 'sun.max.fill' symbol """

SUNRISE = Symbol("sunrise")
""" 'sunrise' symbol """

SUNRISE_FILL = Symbol("sunrise.fill")
""" 'sunrise.fill' symbol """

SUNSET = Symbol("sunset")
""" 'sunset' symbol """

SUNSET_FILL = Symbol("sunset.fill")
""" 'sunset.fill' symbol """

SUN_DUST = Symbol("sun.dust")
""" 'sun.dust' symbol """

SUN_DUST_FILL = Symbol("sun.dust.fill")
""" 'sun.dust.fill' symbol """

SUN_HAZE = Symbol("sun.haze")
""" 'sun.haze' symbol """

SUN_HAZE_FILL = Symbol("sun.haze.fill")
""" 'sun.haze.fill' symbol """

MOON = Symbol("moon")
""" 'moon' symbol """

MOON_FILL = Symbol("moon.fill")
""" 'moon.fill' symbol """

MOON_CIRCLE = Symbol("moon.circle")
""" 'moon.circle' symbol """

MOON_CIRCLE_FILL = Symbol("moon.circle.fill")
""" 'moon.circle.fill' symbol """

ZZZ = Symbol("zzz")
""" 'zzz' symbol """

MOON_ZZZ = Symbol("moon.zzz")
""" 'moon.zzz' symbol """

MOON_ZZZ_FILL = Symbol("moon.zzz.fill")
""" 'moon.zzz.fill' symbol """

SPARKLE = Symbol("sparkle")
""" 'sparkle' symbol """

SPARKLES = Symbol("sparkles")
""" 'sparkles' symbol """

MOON_STARS = Symbol("moon.stars")
""" 'moon.stars' symbol """

MOON_STARS_FILL = Symbol("moon.stars.fill")
""" 'moon.stars.fill' symbol """

CLOUD = Symbol("cloud")
""" 'cloud' symbol """

CLOUD_FILL = Symbol("cloud.fill")
""" 'cloud.fill' symbol """

CLOUD_DRIZZLE = Symbol("cloud.drizzle")
""" 'cloud.drizzle' symbol """

CLOUD_DRIZZLE_FILL = Symbol("cloud.drizzle.fill")
""" 'cloud.drizzle.fill' symbol """

CLOUD_RAIN = Symbol("cloud.rain")
""" 'cloud.rain' symbol """

CLOUD_RAIN_FILL = Symbol("cloud.rain.fill")
""" 'cloud.rain.fill' symbol """

CLOUD_HEAVYRAIN = Symbol("cloud.heavyrain")
""" 'cloud.heavyrain' symbol """

CLOUD_HEAVYRAIN_FILL = Symbol("cloud.heavyrain.fill")
""" 'cloud.heavyrain.fill' symbol """

CLOUD_FOG = Symbol("cloud.fog")
""" 'cloud.fog' symbol """

CLOUD_FOG_FILL = Symbol("cloud.fog.fill")
""" 'cloud.fog.fill' symbol """

CLOUD_HAIL = Symbol("cloud.hail")
""" 'cloud.hail' symbol """

CLOUD_HAIL_FILL = Symbol("cloud.hail.fill")
""" 'cloud.hail.fill' symbol """

CLOUD_SNOW = Symbol("cloud.snow")
""" 'cloud.snow' symbol """

CLOUD_SNOW_FILL = Symbol("cloud.snow.fill")
""" 'cloud.snow.fill' symbol """

CLOUD_SLEET = Symbol("cloud.sleet")
""" 'cloud.sleet' symbol """

CLOUD_SLEET_FILL = Symbol("cloud.sleet.fill")
""" 'cloud.sleet.fill' symbol """

CLOUD_BOLT = Symbol("cloud.bolt")
""" 'cloud.bolt' symbol """

CLOUD_BOLT_FILL = Symbol("cloud.bolt.fill")
""" 'cloud.bolt.fill' symbol """

CLOUD_BOLT_RAIN = Symbol("cloud.bolt.rain")
""" 'cloud.bolt.rain' symbol """

CLOUD_BOLT_RAIN_FILL = Symbol("cloud.bolt.rain.fill")
""" 'cloud.bolt.rain.fill' symbol """

CLOUD_SUN = Symbol("cloud.sun")
""" 'cloud.sun' symbol """

CLOUD_SUN_FILL = Symbol("cloud.sun.fill")
""" 'cloud.sun.fill' symbol """

CLOUD_SUN_RAIN = Symbol("cloud.sun.rain")
""" 'cloud.sun.rain' symbol """

CLOUD_SUN_RAIN_FILL = Symbol("cloud.sun.rain.fill")
""" 'cloud.sun.rain.fill' symbol """

CLOUD_SUN_BOLT = Symbol("cloud.sun.bolt")
""" 'cloud.sun.bolt' symbol """

CLOUD_SUN_BOLT_FILL = Symbol("cloud.sun.bolt.fill")
""" 'cloud.sun.bolt.fill' symbol """

CLOUD_MOON = Symbol("cloud.moon")
""" 'cloud.moon' symbol """

CLOUD_MOON_FILL = Symbol("cloud.moon.fill")
""" 'cloud.moon.fill' symbol """

CLOUD_MOON_RAIN = Symbol("cloud.moon.rain")
""" 'cloud.moon.rain' symbol """

CLOUD_MOON_RAIN_FILL = Symbol("cloud.moon.rain.fill")
""" 'cloud.moon.rain.fill' symbol """

CLOUD_MOON_BOLT = Symbol("cloud.moon.bolt")
""" 'cloud.moon.bolt' symbol """

CLOUD_MOON_BOLT_FILL = Symbol("cloud.moon.bolt.fill")
""" 'cloud.moon.bolt.fill' symbol """

SMOKE = Symbol("smoke")
""" 'smoke' symbol """

SMOKE_FILL = Symbol("smoke.fill")
""" 'smoke.fill' symbol """

WIND = Symbol("wind")
""" 'wind' symbol """

WIND_SNOW = Symbol("wind.snow")
""" 'wind.snow' symbol """

SNOW = Symbol("snow")
""" 'snow' symbol """

TORNADO = Symbol("tornado")
""" 'tornado' symbol """

TROPICALSTORM = Symbol("tropicalstorm")
""" 'tropicalstorm' symbol """

HURRICANE = Symbol("hurricane")
""" 'hurricane' symbol """

THERMOMETER_SUN = Symbol("thermometer.sun")
""" 'thermometer.sun' symbol """

THERMOMETER_SUN_FILL = Symbol("thermometer.sun.fill")
""" 'thermometer.sun.fill' symbol """

THERMOMETER_SNOWFLAKE = Symbol("thermometer.snowflake")
""" 'thermometer.snowflake' symbol """

THERMOMETER = Symbol("thermometer")
""" 'thermometer' symbol """

UMBRELLA = Symbol("umbrella")
""" 'umbrella' symbol """

UMBRELLA_FILL = Symbol("umbrella.fill")
""" 'umbrella.fill' symbol """

FLAME = Symbol("flame")
""" 'flame' symbol """

FLAME_FILL = Symbol("flame.fill")
""" 'flame.fill' symbol """

LIGHT_MIN = Symbol("light.min")
""" 'light.min' symbol """

LIGHT_MAX = Symbol("light.max")
""" 'light.max' symbol """

RAYS = Symbol("rays")
""" 'rays' symbol """

SLOWMO = Symbol("slowmo")
""" 'slowmo' symbol """

TIMELAPSE = Symbol("timelapse")
""" 'timelapse' symbol """

CURSORARROW_RAYS = Symbol("cursorarrow.rays")
""" 'cursorarrow.rays' symbol """

CURSORARROW = Symbol("cursorarrow")
""" 'cursorarrow' symbol """

CURSORARROW_SQUARE = Symbol("cursorarrow.square")
""" 'cursorarrow.square' symbol """

CURSORARROW_AND_SQUARE_ON_SQUARE_DASHED = Symbol("cursorarrow.and.square.on.square.dashed")
""" 'cursorarrow.and.square.on.square.dashed' symbol """

CURSORARROW_CLICK = Symbol("cursorarrow.click")
""" 'cursorarrow.click' symbol """

CURSORARROW_CLICK_2 = Symbol("cursorarrow.click.2")
""" 'cursorarrow.click.2' symbol """

CONTEXTUALMENU_AND_CURSORARROW = Symbol("contextualmenu.and.cursorarrow")
""" 'contextualmenu.and.cursorarrow' symbol """

FILEMENU_AND_CURSORARROW = Symbol("filemenu.and.cursorarrow")
""" 'filemenu.and.cursorarrow' symbol """

DOT_CIRCLE_AND_CURSORARROW = Symbol("dot.circle.and.cursorarrow")
""" 'dot.circle.and.cursorarrow' symbol """

CURSORARROW_MOTIONLINES = Symbol("cursorarrow.motionlines")
""" 'cursorarrow.motionlines' symbol """

CURSORARROW_MOTIONLINES_CLICK = Symbol("cursorarrow.motionlines.click")
""" 'cursorarrow.motionlines.click' symbol """

CURSORARROW_CLICK_BADGE_CLOCK = Symbol("cursorarrow.click.badge.clock")
""" 'cursorarrow.click.badge.clock' symbol """

KEYBOARD = Symbol("keyboard")
""" 'keyboard' symbol """

KEYBOARD_BADGE_ELLIPSIS = Symbol("keyboard.badge.ellipsis")
""" 'keyboard.badge.ellipsis' symbol """

KEYBOARD_CHEVRON_COMPACT_DOWN = Symbol("keyboard.chevron.compact.down")
""" 'keyboard.chevron.compact.down' symbol """

KEYBOARD_CHEVRON_COMPACT_LEFT = Symbol("keyboard.chevron.compact.left")
""" 'keyboard.chevron.compact.left' symbol """

KEYBOARD_ONEHANDED_LEFT = Symbol("keyboard.onehanded.left")
""" 'keyboard.onehanded.left' symbol """

KEYBOARD_ONEHANDED_RIGHT = Symbol("keyboard.onehanded.right")
""" 'keyboard.onehanded.right' symbol """

RECTANGLE_3_OFFGRID = Symbol("rectangle.3.offgrid")
""" 'rectangle.3.offgrid' symbol """

RECTANGLE_3_OFFGRID_FILL = Symbol("rectangle.3.offgrid.fill")
""" 'rectangle.3.offgrid.fill' symbol """

SQUARE_GRID_3X2 = Symbol("square.grid.3x2")
""" 'square.grid.3x2' symbol """

SQUARE_GRID_3X2_FILL = Symbol("square.grid.3x2.fill")
""" 'square.grid.3x2.fill' symbol """

RECTANGLE_GRID_3X2 = Symbol("rectangle.grid.3x2")
""" 'rectangle.grid.3x2' symbol """

RECTANGLE_GRID_3X2_FILL = Symbol("rectangle.grid.3x2.fill")
""" 'rectangle.grid.3x2.fill' symbol """

SQUARE_GRID_2X2 = Symbol("square.grid.2x2")
""" 'square.grid.2x2' symbol """

SQUARE_GRID_2X2_FILL = Symbol("square.grid.2x2.fill")
""" 'square.grid.2x2.fill' symbol """

RECTANGLE_GRID_2X2 = Symbol("rectangle.grid.2x2")
""" 'rectangle.grid.2x2' symbol """

RECTANGLE_GRID_2X2_FILL = Symbol("rectangle.grid.2x2.fill")
""" 'rectangle.grid.2x2.fill' symbol """

SQUARE_GRID_3X1_BELOW_LINE_GRID_1X2 = Symbol("square.grid.3x1.below.line.grid.1x2")
""" 'square.grid.3x1.below.line.grid.1x2' symbol """

SQUARE_GRID_3X1_FILL_BELOW_LINE_GRID_1X2 = Symbol("square.grid.3x1.fill.below.line.grid.1x2")
""" 'square.grid.3x1.fill.below.line.grid.1x2' symbol """

SQUARE_GRID_4X3_FILL = Symbol("square.grid.4x3.fill")
""" 'square.grid.4x3.fill' symbol """

RECTANGLE_GRID_1X2 = Symbol("rectangle.grid.1x2")
""" 'rectangle.grid.1x2' symbol """

RECTANGLE_GRID_1X2_FILL = Symbol("rectangle.grid.1x2.fill")
""" 'rectangle.grid.1x2.fill' symbol """

CIRCLE_GRID_2X2 = Symbol("circle.grid.2x2")
""" 'circle.grid.2x2' symbol """

CIRCLE_GRID_2X2_FILL = Symbol("circle.grid.2x2.fill")
""" 'circle.grid.2x2.fill' symbol """

CIRCLE_GRID_3X3 = Symbol("circle.grid.3x3")
""" 'circle.grid.3x3' symbol """

CIRCLE_GRID_3X3_FILL = Symbol("circle.grid.3x3.fill")
""" 'circle.grid.3x3.fill' symbol """

SQUARE_GRID_3X3 = Symbol("square.grid.3x3")
""" 'square.grid.3x3' symbol """

SQUARE_GRID_3X3_FILL = Symbol("square.grid.3x3.fill")
""" 'square.grid.3x3.fill' symbol """

SQUARE_GRID_3X3_TOPLEFT_FILL = Symbol("square.grid.3x3.topleft.fill")
""" 'square.grid.3x3.topleft.fill' symbol """

SQUARE_GRID_3X3_TOPMIDDLE_FILL = Symbol("square.grid.3x3.topmiddle.fill")
""" 'square.grid.3x3.topmiddle.fill' symbol """

SQUARE_GRID_3X3_TOPRIGHT_FILL = Symbol("square.grid.3x3.topright.fill")
""" 'square.grid.3x3.topright.fill' symbol """

SQUARE_GRID_3X3_MIDDLELEFT_FILL = Symbol("square.grid.3x3.middleleft.fill")
""" 'square.grid.3x3.middleleft.fill' symbol """

SQUARE_GRID_3X3_MIDDLE_FILL = Symbol("square.grid.3x3.middle.fill")
""" 'square.grid.3x3.middle.fill' symbol """

SQUARE_GRID_3X3_MIDDLERIGHT_FILL = Symbol("square.grid.3x3.middleright.fill")
""" 'square.grid.3x3.middleright.fill' symbol """

SQUARE_GRID_3X3_BOTTOMLEFT_FILL = Symbol("square.grid.3x3.bottomleft.fill")
""" 'square.grid.3x3.bottomleft.fill' symbol """

SQUARE_GRID_3X3_BOTTOMMIDDLE_FILL = Symbol("square.grid.3x3.bottommiddle.fill")
""" 'square.grid.3x3.bottommiddle.fill' symbol """

SQUARE_GRID_3X3_BOTTOMRIGHT_FILL = Symbol("square.grid.3x3.bottomright.fill")
""" 'square.grid.3x3.bottomright.fill' symbol """

CIRCLES_HEXAGONGRID = Symbol("circles.hexagongrid")
""" 'circles.hexagongrid' symbol """

CIRCLES_HEXAGONGRID_FILL = Symbol("circles.hexagongrid.fill")
""" 'circles.hexagongrid.fill' symbol """

CIRCLES_HEXAGONPATH = Symbol("circles.hexagonpath")
""" 'circles.hexagonpath' symbol """

CIRCLES_HEXAGONPATH_FILL = Symbol("circles.hexagonpath.fill")
""" 'circles.hexagonpath.fill' symbol """

CIRCLE_GRID_CROSS = Symbol("circle.grid.cross")
""" 'circle.grid.cross' symbol """

CIRCLE_GRID_CROSS_FILL = Symbol("circle.grid.cross.fill")
""" 'circle.grid.cross.fill' symbol """

CIRCLE_GRID_CROSS_LEFT_FILL = Symbol("circle.grid.cross.left.fill")
""" 'circle.grid.cross.left.fill' symbol """

CIRCLE_GRID_CROSS_UP_FILL = Symbol("circle.grid.cross.up.fill")
""" 'circle.grid.cross.up.fill' symbol """

CIRCLE_GRID_CROSS_RIGHT_FILL = Symbol("circle.grid.cross.right.fill")
""" 'circle.grid.cross.right.fill' symbol """

CIRCLE_GRID_CROSS_DOWN_FILL = Symbol("circle.grid.cross.down.fill")
""" 'circle.grid.cross.down.fill' symbol """

SEAL = Symbol("seal")
""" 'seal' symbol """

SEAL_FILL = Symbol("seal.fill")
""" 'seal.fill' symbol """

CHECKMARK_SEAL = Symbol("checkmark.seal")
""" 'checkmark.seal' symbol """

CHECKMARK_SEAL_FILL = Symbol("checkmark.seal.fill")
""" 'checkmark.seal.fill' symbol """

XMARK_SEAL = Symbol("xmark.seal")
""" 'xmark.seal' symbol """

XMARK_SEAL_FILL = Symbol("xmark.seal.fill")
""" 'xmark.seal.fill' symbol """

EXCLAMATIONMARK_TRIANGLE = Symbol("exclamationmark.triangle")
""" 'exclamationmark.triangle' symbol """

EXCLAMATIONMARK_TRIANGLE_FILL = Symbol("exclamationmark.triangle.fill")
""" 'exclamationmark.triangle.fill' symbol """

DROP = Symbol("drop")
""" 'drop' symbol """

DROP_FILL = Symbol("drop.fill")
""" 'drop.fill' symbol """

DROP_TRIANGLE = Symbol("drop.triangle")
""" 'drop.triangle' symbol """

DROP_TRIANGLE_FILL = Symbol("drop.triangle.fill")
""" 'drop.triangle.fill' symbol """

PLAY = Symbol("play")
""" 'play' symbol """

PLAY_FILL = Symbol("play.fill")
""" 'play.fill' symbol """

PLAY_CIRCLE = Symbol("play.circle")
""" 'play.circle' symbol """

PLAY_CIRCLE_FILL = Symbol("play.circle.fill")
""" 'play.circle.fill' symbol """

PLAY_RECTANGLE = Symbol("play.rectangle")
""" 'play.rectangle' symbol """

PLAY_RECTANGLE_FILL = Symbol("play.rectangle.fill")
""" 'play.rectangle.fill' symbol """

PLAY_SLASH = Symbol("play.slash")
""" 'play.slash' symbol """

PLAY_SLASH_FILL = Symbol("play.slash.fill")
""" 'play.slash.fill' symbol """

PAUSE = Symbol("pause")
""" 'pause' symbol """

PAUSE_FILL = Symbol("pause.fill")
""" 'pause.fill' symbol """

PAUSE_CIRCLE = Symbol("pause.circle")
""" 'pause.circle' symbol """

PAUSE_CIRCLE_FILL = Symbol("pause.circle.fill")
""" 'pause.circle.fill' symbol """

PAUSE_RECTANGLE = Symbol("pause.rectangle")
""" 'pause.rectangle' symbol """

PAUSE_RECTANGLE_FILL = Symbol("pause.rectangle.fill")
""" 'pause.rectangle.fill' symbol """

STOP = Symbol("stop")
""" 'stop' symbol """

STOP_FILL = Symbol("stop.fill")
""" 'stop.fill' symbol """

STOP_CIRCLE = Symbol("stop.circle")
""" 'stop.circle' symbol """

STOP_CIRCLE_FILL = Symbol("stop.circle.fill")
""" 'stop.circle.fill' symbol """

RECORD_CIRCLE = Symbol("record.circle")
""" 'record.circle' symbol """

RECORD_CIRCLE_FILL = Symbol("record.circle.fill")
""" 'record.circle.fill' symbol """

PLAYPAUSE = Symbol("playpause")
""" 'playpause' symbol """

PLAYPAUSE_FILL = Symbol("playpause.fill")
""" 'playpause.fill' symbol """

BACKWARD = Symbol("backward")
""" 'backward' symbol """

BACKWARD_FILL = Symbol("backward.fill")
""" 'backward.fill' symbol """

FORWARD = Symbol("forward")
""" 'forward' symbol """

FORWARD_FILL = Symbol("forward.fill")
""" 'forward.fill' symbol """

BACKWARD_END = Symbol("backward.end")
""" 'backward.end' symbol """

BACKWARD_END_FILL = Symbol("backward.end.fill")
""" 'backward.end.fill' symbol """

FORWARD_END = Symbol("forward.end")
""" 'forward.end' symbol """

FORWARD_END_FILL = Symbol("forward.end.fill")
""" 'forward.end.fill' symbol """

BACKWARD_END_ALT = Symbol("backward.end.alt")
""" 'backward.end.alt' symbol """

BACKWARD_END_ALT_FILL = Symbol("backward.end.alt.fill")
""" 'backward.end.alt.fill' symbol """

FORWARD_END_ALT = Symbol("forward.end.alt")
""" 'forward.end.alt' symbol """

FORWARD_END_ALT_FILL = Symbol("forward.end.alt.fill")
""" 'forward.end.alt.fill' symbol """

BACKWARD_FRAME = Symbol("backward.frame")
""" 'backward.frame' symbol """

BACKWARD_FRAME_FILL = Symbol("backward.frame.fill")
""" 'backward.frame.fill' symbol """

FORWARD_FRAME = Symbol("forward.frame")
""" 'forward.frame' symbol """

FORWARD_FRAME_FILL = Symbol("forward.frame.fill")
""" 'forward.frame.fill' symbol """

EJECT = Symbol("eject")
""" 'eject' symbol """

EJECT_FILL = Symbol("eject.fill")
""" 'eject.fill' symbol """

EJECT_CIRCLE = Symbol("eject.circle")
""" 'eject.circle' symbol """

EJECT_CIRCLE_FILL = Symbol("eject.circle.fill")
""" 'eject.circle.fill' symbol """

MOUNT = Symbol("mount")
""" 'mount' symbol """

MOUNT_FILL = Symbol("mount.fill")
""" 'mount.fill' symbol """

MEMORIES = Symbol("memories")
""" 'memories' symbol """

MEMORIES_BADGE_PLUS = Symbol("memories.badge.plus")
""" 'memories.badge.plus' symbol """

MEMORIES_BADGE_MINUS = Symbol("memories.badge.minus")
""" 'memories.badge.minus' symbol """

SHUFFLE = Symbol("shuffle")
""" 'shuffle' symbol """

REPEAT = Symbol("repeat")
""" 'repeat' symbol """

REPEAT_1 = Symbol("repeat.1")
""" 'repeat.1' symbol """

INFINITY = Symbol("infinity")
""" 'infinity' symbol """

MEGAPHONE = Symbol("megaphone")
""" 'megaphone' symbol """

MEGAPHONE_FILL = Symbol("megaphone.fill")
""" 'megaphone.fill' symbol """

SPEAKER = Symbol("speaker")
""" 'speaker' symbol """

SPEAKER_FILL = Symbol("speaker.fill")
""" 'speaker.fill' symbol """

SPEAKER_SLASH = Symbol("speaker.slash")
""" 'speaker.slash' symbol """

SPEAKER_SLASH_FILL = Symbol("speaker.slash.fill")
""" 'speaker.slash.fill' symbol """

SPEAKER_SLASH_CIRCLE = Symbol("speaker.slash.circle")
""" 'speaker.slash.circle' symbol """

SPEAKER_SLASH_CIRCLE_FILL = Symbol("speaker.slash.circle.fill")
""" 'speaker.slash.circle.fill' symbol """

SPEAKER_ZZZ = Symbol("speaker.zzz")
""" 'speaker.zzz' symbol """

SPEAKER_ZZZ_FILL = Symbol("speaker.zzz.fill")
""" 'speaker.zzz.fill' symbol """

SPEAKER_WAVE_1 = Symbol("speaker.wave.1")
""" 'speaker.wave.1' symbol """

SPEAKER_WAVE_1_FILL = Symbol("speaker.wave.1.fill")
""" 'speaker.wave.1.fill' symbol """

SPEAKER_WAVE_2 = Symbol("speaker.wave.2")
""" 'speaker.wave.2' symbol """

SPEAKER_WAVE_2_FILL = Symbol("speaker.wave.2.fill")
""" 'speaker.wave.2.fill' symbol """

SPEAKER_WAVE_2_CIRCLE = Symbol("speaker.wave.2.circle")
""" 'speaker.wave.2.circle' symbol """

SPEAKER_WAVE_2_CIRCLE_FILL = Symbol("speaker.wave.2.circle.fill")
""" 'speaker.wave.2.circle.fill' symbol """

SPEAKER_WAVE_3 = Symbol("speaker.wave.3")
""" 'speaker.wave.3' symbol """

SPEAKER_WAVE_3_FILL = Symbol("speaker.wave.3.fill")
""" 'speaker.wave.3.fill' symbol """

BADGE_PLUS_RADIOWAVES_RIGHT = Symbol("badge.plus.radiowaves.right")
""" 'badge.plus.radiowaves.right' symbol """

MUSIC_NOTE = Symbol("music.note")
""" 'music.note' symbol """

MUSIC_NOTE_LIST = Symbol("music.note.list")
""" 'music.note.list' symbol """

MUSIC_QUARTERNOTE_3 = Symbol("music.quarternote.3")
""" 'music.quarternote.3' symbol """

MUSIC_MIC = Symbol("music.mic")
""" 'music.mic' symbol """

ARROW_RECTANGLEPATH = Symbol("arrow.rectanglepath")
""" 'arrow.rectanglepath' symbol """

GOFORWARD = Symbol("goforward")
""" 'goforward' symbol """

GOBACKWARD = Symbol("gobackward")
""" 'gobackward' symbol """

GOFORWARD_10 = Symbol("goforward.10")
""" 'goforward.10' symbol """

GOBACKWARD_10 = Symbol("gobackward.10")
""" 'gobackward.10' symbol """

GOFORWARD_15 = Symbol("goforward.15")
""" 'goforward.15' symbol """

GOBACKWARD_15 = Symbol("gobackward.15")
""" 'gobackward.15' symbol """

GOFORWARD_30 = Symbol("goforward.30")
""" 'goforward.30' symbol """

GOBACKWARD_30 = Symbol("gobackward.30")
""" 'gobackward.30' symbol """

GOFORWARD_45 = Symbol("goforward.45")
""" 'goforward.45' symbol """

GOBACKWARD_45 = Symbol("gobackward.45")
""" 'gobackward.45' symbol """

GOFORWARD_60 = Symbol("goforward.60")
""" 'goforward.60' symbol """

GOBACKWARD_60 = Symbol("gobackward.60")
""" 'gobackward.60' symbol """

GOFORWARD_75 = Symbol("goforward.75")
""" 'goforward.75' symbol """

GOBACKWARD_75 = Symbol("gobackward.75")
""" 'gobackward.75' symbol """

GOFORWARD_90 = Symbol("goforward.90")
""" 'goforward.90' symbol """

GOBACKWARD_90 = Symbol("gobackward.90")
""" 'gobackward.90' symbol """

GOFORWARD_PLUS = Symbol("goforward.plus")
""" 'goforward.plus' symbol """

GOBACKWARD_MINUS = Symbol("gobackward.minus")
""" 'gobackward.minus' symbol """

SWIFT = Symbol("swift")
""" 'swift' symbol """

MAGNIFYINGGLASS = Symbol("magnifyingglass")
""" 'magnifyingglass' symbol """

MAGNIFYINGGLASS_CIRCLE = Symbol("magnifyingglass.circle")
""" 'magnifyingglass.circle' symbol """

MAGNIFYINGGLASS_CIRCLE_FILL = Symbol("magnifyingglass.circle.fill")
""" 'magnifyingglass.circle.fill' symbol """

PLUS_MAGNIFYINGGLASS = Symbol("plus.magnifyingglass")
""" 'plus.magnifyingglass' symbol """

MINUS_MAGNIFYINGGLASS = Symbol("minus.magnifyingglass")
""" 'minus.magnifyingglass' symbol """

N1_MAGNIFYINGGLASS = Symbol("1.magnifyingglass")
""" '1.magnifyingglass' symbol """

ARROW_UP_LEFT_AND_DOWN_RIGHT_MAGNIFYINGGLASS = Symbol("arrow.up.left.and.down.right.magnifyingglass")
""" 'arrow.up.left.and.down.right.magnifyingglass' symbol """

TEXT_MAGNIFYINGGLASS = Symbol("text.magnifyingglass")
""" 'text.magnifyingglass' symbol """

LOUPE = Symbol("loupe")
""" 'loupe' symbol """

MIC = Symbol("mic")
""" 'mic' symbol """

MIC_FILL = Symbol("mic.fill")
""" 'mic.fill' symbol """

MIC_CIRCLE = Symbol("mic.circle")
""" 'mic.circle' symbol """

MIC_CIRCLE_FILL = Symbol("mic.circle.fill")
""" 'mic.circle.fill' symbol """

MIC_SLASH = Symbol("mic.slash")
""" 'mic.slash' symbol """

MIC_SLASH_FILL = Symbol("mic.slash.fill")
""" 'mic.slash.fill' symbol """

LINE_DIAGONAL = Symbol("line.diagonal")
""" 'line.diagonal' symbol """

LINE_DIAGONAL_ARROW = Symbol("line.diagonal.arrow")
""" 'line.diagonal.arrow' symbol """

CIRCLE = Symbol("circle")
""" 'circle' symbol """

CIRCLE_FILL = Symbol("circle.fill")
""" 'circle.fill' symbol """

CIRCLE_LEFTHALF_FILL = Symbol("circle.lefthalf.fill")
""" 'circle.lefthalf.fill' symbol """

CIRCLE_RIGHTHALF_FILL = Symbol("circle.righthalf.fill")
""" 'circle.righthalf.fill' symbol """

CIRCLE_BOTTOMHALF_FILL = Symbol("circle.bottomhalf.fill")
""" 'circle.bottomhalf.fill' symbol """

CIRCLE_TOPHALF_FILL = Symbol("circle.tophalf.fill")
""" 'circle.tophalf.fill' symbol """

LARGECIRCLE_FILL_CIRCLE = Symbol("largecircle.fill.circle")
""" 'largecircle.fill.circle' symbol """

SMALLCIRCLE_FILL_CIRCLE = Symbol("smallcircle.fill.circle")
""" 'smallcircle.fill.circle' symbol """

SMALLCIRCLE_FILL_CIRCLE_FILL = Symbol("smallcircle.fill.circle.fill")
""" 'smallcircle.fill.circle.fill' symbol """

CIRCLE_DASHED = Symbol("circle.dashed")
""" 'circle.dashed' symbol """

CIRCLE_DASHED_INSET_FILL = Symbol("circle.dashed.inset.fill")
""" 'circle.dashed.inset.fill' symbol """

CIRCLEBADGE = Symbol("circlebadge")
""" 'circlebadge' symbol """

CIRCLEBADGE_FILL = Symbol("circlebadge.fill")
""" 'circlebadge.fill' symbol """

SMALLCIRCLE_CIRCLE = Symbol("smallcircle.circle")
""" 'smallcircle.circle' symbol """

SMALLCIRCLE_CIRCLE_FILL = Symbol("smallcircle.circle.fill")
""" 'smallcircle.circle.fill' symbol """

TARGET = Symbol("target")
""" 'target' symbol """

CAPSULE = Symbol("capsule")
""" 'capsule' symbol """

CAPSULE_FILL = Symbol("capsule.fill")
""" 'capsule.fill' symbol """

CAPSULE_PORTRAIT = Symbol("capsule.portrait")
""" 'capsule.portrait' symbol """

CAPSULE_PORTRAIT_FILL = Symbol("capsule.portrait.fill")
""" 'capsule.portrait.fill' symbol """

PLACEHOLDERTEXT_FILL = Symbol("placeholdertext.fill")
""" 'placeholdertext.fill' symbol """

SQUARE = Symbol("square")
""" 'square' symbol """

SQUARE_FILL = Symbol("square.fill")
""" 'square.fill' symbol """

SQUARE_LEFTHALF_FILL = Symbol("square.lefthalf.fill")
""" 'square.lefthalf.fill' symbol """

SQUARE_RIGHTHALF_FILL = Symbol("square.righthalf.fill")
""" 'square.righthalf.fill' symbol """

SQUARE_BOTTOMHALF_FILL = Symbol("square.bottomhalf.fill")
""" 'square.bottomhalf.fill' symbol """

SQUARE_TOPHALF_FILL = Symbol("square.tophalf.fill")
""" 'square.tophalf.fill' symbol """

SQUARE_SLASH = Symbol("square.slash")
""" 'square.slash' symbol """

SQUARE_SLASH_FILL = Symbol("square.slash.fill")
""" 'square.slash.fill' symbol """

DOT_SQUARE = Symbol("dot.square")
""" 'dot.square' symbol """

DOT_SQUARE_FILL = Symbol("dot.square.fill")
""" 'dot.square.fill' symbol """

CIRCLE_SQUARE = Symbol("circle.square")
""" 'circle.square' symbol """

CIRCLE_FILL_SQUARE_FILL = Symbol("circle.fill.square.fill")
""" 'circle.fill.square.fill' symbol """

SQUARE_DASHED = Symbol("square.dashed")
""" 'square.dashed' symbol """

SQUARE_DASHED_INSET_FILL = Symbol("square.dashed.inset.fill")
""" 'square.dashed.inset.fill' symbol """

QUESTIONMARK_SQUARE_DASHED = Symbol("questionmark.square.dashed")
""" 'questionmark.square.dashed' symbol """

SQUARESHAPE = Symbol("squareshape")
""" 'squareshape' symbol """

SQUARESHAPE_FILL = Symbol("squareshape.fill")
""" 'squareshape.fill' symbol """

SQUARESHAPE_DASHED_SQUARESHAPE = Symbol("squareshape.dashed.squareshape")
""" 'squareshape.dashed.squareshape' symbol """

SQUARESHAPE_SQUARESHAPE_DASHED = Symbol("squareshape.squareshape.dashed")
""" 'squareshape.squareshape.dashed' symbol """

DOT_SQUARESHAPE = Symbol("dot.squareshape")
""" 'dot.squareshape' symbol """

DOT_SQUARESHAPE_FILL = Symbol("dot.squareshape.fill")
""" 'dot.squareshape.fill' symbol """

APP = Symbol("app")
""" 'app' symbol """

APP_FILL = Symbol("app.fill")
""" 'app.fill' symbol """

RECTANGLE = Symbol("rectangle")
""" 'rectangle' symbol """

RECTANGLE_FILL = Symbol("rectangle.fill")
""" 'rectangle.fill' symbol """

RECTANGLE_SLASH = Symbol("rectangle.slash")
""" 'rectangle.slash' symbol """

RECTANGLE_SLASH_FILL = Symbol("rectangle.slash.fill")
""" 'rectangle.slash.fill' symbol """

RECTANGLE_PORTRAIT = Symbol("rectangle.portrait")
""" 'rectangle.portrait' symbol """

RECTANGLE_PORTRAIT_FILL = Symbol("rectangle.portrait.fill")
""" 'rectangle.portrait.fill' symbol """

TRIANGLE = Symbol("triangle")
""" 'triangle' symbol """

TRIANGLE_FILL = Symbol("triangle.fill")
""" 'triangle.fill' symbol """

TRIANGLE_LEFTHALF_FILL = Symbol("triangle.lefthalf.fill")
""" 'triangle.lefthalf.fill' symbol """

TRIANGLE_RIGHTHALF_FILL = Symbol("triangle.righthalf.fill")
""" 'triangle.righthalf.fill' symbol """

DIAMOND = Symbol("diamond")
""" 'diamond' symbol """

DIAMOND_FILL = Symbol("diamond.fill")
""" 'diamond.fill' symbol """

OCTAGON = Symbol("octagon")
""" 'octagon' symbol """

OCTAGON_FILL = Symbol("octagon.fill")
""" 'octagon.fill' symbol """

HEXAGON = Symbol("hexagon")
""" 'hexagon' symbol """

HEXAGON_FILL = Symbol("hexagon.fill")
""" 'hexagon.fill' symbol """

SUIT_HEART = Symbol("suit.heart")
""" 'suit.heart' symbol """

SUIT_HEART_FILL = Symbol("suit.heart.fill")
""" 'suit.heart.fill' symbol """

SUIT_CLUB = Symbol("suit.club")
""" 'suit.club' symbol """

SUIT_CLUB_FILL = Symbol("suit.club.fill")
""" 'suit.club.fill' symbol """

SUIT_SPADE = Symbol("suit.spade")
""" 'suit.spade' symbol """

SUIT_SPADE_FILL = Symbol("suit.spade.fill")
""" 'suit.spade.fill' symbol """

SUIT_DIAMOND = Symbol("suit.diamond")
""" 'suit.diamond' symbol """

SUIT_DIAMOND_FILL = Symbol("suit.diamond.fill")
""" 'suit.diamond.fill' symbol """

HEART = Symbol("heart")
""" 'heart' symbol """

HEART_FILL = Symbol("heart.fill")
""" 'heart.fill' symbol """

HEART_CIRCLE = Symbol("heart.circle")
""" 'heart.circle' symbol """

HEART_CIRCLE_FILL = Symbol("heart.circle.fill")
""" 'heart.circle.fill' symbol """

HEART_SLASH = Symbol("heart.slash")
""" 'heart.slash' symbol """

HEART_SLASH_FILL = Symbol("heart.slash.fill")
""" 'heart.slash.fill' symbol """

HEART_SLASH_CIRCLE = Symbol("heart.slash.circle")
""" 'heart.slash.circle' symbol """

HEART_SLASH_CIRCLE_FILL = Symbol("heart.slash.circle.fill")
""" 'heart.slash.circle.fill' symbol """

HEART_TEXT_SQUARE = Symbol("heart.text.square")
""" 'heart.text.square' symbol """

HEART_TEXT_SQUARE_FILL = Symbol("heart.text.square.fill")
""" 'heart.text.square.fill' symbol """

BOLT_HEART = Symbol("bolt.heart")
""" 'bolt.heart' symbol """

BOLT_HEART_FILL = Symbol("bolt.heart.fill")
""" 'bolt.heart.fill' symbol """

RHOMBUS = Symbol("rhombus")
""" 'rhombus' symbol """

RHOMBUS_FILL = Symbol("rhombus.fill")
""" 'rhombus.fill' symbol """

STAR = Symbol("star")
""" 'star' symbol """

STAR_FILL = Symbol("star.fill")
""" 'star.fill' symbol """

STAR_LEFTHALF_FILL = Symbol("star.lefthalf.fill")
""" 'star.lefthalf.fill' symbol """

STAR_CIRCLE = Symbol("star.circle")
""" 'star.circle' symbol """

STAR_CIRCLE_FILL = Symbol("star.circle.fill")
""" 'star.circle.fill' symbol """

STAR_SQUARE = Symbol("star.square")
""" 'star.square' symbol """

STAR_SQUARE_FILL = Symbol("star.square.fill")
""" 'star.square.fill' symbol """

STAR_SLASH = Symbol("star.slash")
""" 'star.slash' symbol """

STAR_SLASH_FILL = Symbol("star.slash.fill")
""" 'star.slash.fill' symbol """

LINE_HORIZONTAL_STAR_FILL_LINE_HORIZONTAL = Symbol("line.horizontal.star.fill.line.horizontal")
""" 'line.horizontal.star.fill.line.horizontal' symbol """

FLAG = Symbol("flag")
""" 'flag' symbol """

FLAG_FILL = Symbol("flag.fill")
""" 'flag.fill' symbol """

FLAG_CIRCLE = Symbol("flag.circle")
""" 'flag.circle' symbol """

FLAG_CIRCLE_FILL = Symbol("flag.circle.fill")
""" 'flag.circle.fill' symbol """

FLAG_SLASH = Symbol("flag.slash")
""" 'flag.slash' symbol """

FLAG_SLASH_FILL = Symbol("flag.slash.fill")
""" 'flag.slash.fill' symbol """

FLAG_SLASH_CIRCLE = Symbol("flag.slash.circle")
""" 'flag.slash.circle' symbol """

FLAG_SLASH_CIRCLE_FILL = Symbol("flag.slash.circle.fill")
""" 'flag.slash.circle.fill' symbol """

FLAG_BADGE_ELLIPSIS = Symbol("flag.badge.ellipsis")
""" 'flag.badge.ellipsis' symbol """

FLAG_BADGE_ELLIPSIS_FILL = Symbol("flag.badge.ellipsis.fill")
""" 'flag.badge.ellipsis.fill' symbol """

LOCATION = Symbol("location")
""" 'location' symbol """

LOCATION_FILL = Symbol("location.fill")
""" 'location.fill' symbol """

LOCATION_SLASH = Symbol("location.slash")
""" 'location.slash' symbol """

LOCATION_SLASH_FILL = Symbol("location.slash.fill")
""" 'location.slash.fill' symbol """

LOCATION_NORTH = Symbol("location.north")
""" 'location.north' symbol """

LOCATION_NORTH_FILL = Symbol("location.north.fill")
""" 'location.north.fill' symbol """

LOCATION_CIRCLE = Symbol("location.circle")
""" 'location.circle' symbol """

LOCATION_CIRCLE_FILL = Symbol("location.circle.fill")
""" 'location.circle.fill' symbol """

LOCATION_NORTH_LINE = Symbol("location.north.line")
""" 'location.north.line' symbol """

LOCATION_NORTH_LINE_FILL = Symbol("location.north.line.fill")
""" 'location.north.line.fill' symbol """

BELL = Symbol("bell")
""" 'bell' symbol """

BELL_FILL = Symbol("bell.fill")
""" 'bell.fill' symbol """

BELL_CIRCLE = Symbol("bell.circle")
""" 'bell.circle' symbol """

BELL_CIRCLE_FILL = Symbol("bell.circle.fill")
""" 'bell.circle.fill' symbol """

BELL_SLASH = Symbol("bell.slash")
""" 'bell.slash' symbol """

BELL_SLASH_FILL = Symbol("bell.slash.fill")
""" 'bell.slash.fill' symbol """

BELL_SLASH_CIRCLE = Symbol("bell.slash.circle")
""" 'bell.slash.circle' symbol """

BELL_SLASH_CIRCLE_FILL = Symbol("bell.slash.circle.fill")
""" 'bell.slash.circle.fill' symbol """

BELL_BADGE = Symbol("bell.badge")
""" 'bell.badge' symbol """

BELL_BADGE_FILL = Symbol("bell.badge.fill")
""" 'bell.badge.fill' symbol """

TAG = Symbol("tag")
""" 'tag' symbol """

TAG_FILL = Symbol("tag.fill")
""" 'tag.fill' symbol """

TAG_CIRCLE = Symbol("tag.circle")
""" 'tag.circle' symbol """

TAG_CIRCLE_FILL = Symbol("tag.circle.fill")
""" 'tag.circle.fill' symbol """

TAG_SLASH = Symbol("tag.slash")
""" 'tag.slash' symbol """

TAG_SLASH_FILL = Symbol("tag.slash.fill")
""" 'tag.slash.fill' symbol """

BOLT = Symbol("bolt")
""" 'bolt' symbol """

BOLT_FILL = Symbol("bolt.fill")
""" 'bolt.fill' symbol """

BOLT_CIRCLE = Symbol("bolt.circle")
""" 'bolt.circle' symbol """

BOLT_CIRCLE_FILL = Symbol("bolt.circle.fill")
""" 'bolt.circle.fill' symbol """

BOLT_SLASH = Symbol("bolt.slash")
""" 'bolt.slash' symbol """

BOLT_SLASH_FILL = Symbol("bolt.slash.fill")
""" 'bolt.slash.fill' symbol """

BOLT_SLASH_CIRCLE = Symbol("bolt.slash.circle")
""" 'bolt.slash.circle' symbol """

BOLT_SLASH_CIRCLE_FILL = Symbol("bolt.slash.circle.fill")
""" 'bolt.slash.circle.fill' symbol """

BOLT_BADGE_A = Symbol("bolt.badge.a")
""" 'bolt.badge.a' symbol """

BOLT_BADGE_A_FILL = Symbol("bolt.badge.a.fill")
""" 'bolt.badge.a.fill' symbol """

BOLT_HORIZONTAL = Symbol("bolt.horizontal")
""" 'bolt.horizontal' symbol """

BOLT_HORIZONTAL_FILL = Symbol("bolt.horizontal.fill")
""" 'bolt.horizontal.fill' symbol """

BOLT_HORIZONTAL_CIRCLE = Symbol("bolt.horizontal.circle")
""" 'bolt.horizontal.circle' symbol """

BOLT_HORIZONTAL_CIRCLE_FILL = Symbol("bolt.horizontal.circle.fill")
""" 'bolt.horizontal.circle.fill' symbol """

EYE = Symbol("eye")
""" 'eye' symbol """

EYE_FILL = Symbol("eye.fill")
""" 'eye.fill' symbol """

EYE_CIRCLE = Symbol("eye.circle")
""" 'eye.circle' symbol """

EYE_CIRCLE_FILL = Symbol("eye.circle.fill")
""" 'eye.circle.fill' symbol """

EYE_SLASH = Symbol("eye.slash")
""" 'eye.slash' symbol """

EYE_SLASH_FILL = Symbol("eye.slash.fill")
""" 'eye.slash.fill' symbol """

EYES = Symbol("eyes")
""" 'eyes' symbol """

EYES_INVERSE = Symbol("eyes.inverse")
""" 'eyes.inverse' symbol """

EYEBROW = Symbol("eyebrow")
""" 'eyebrow' symbol """

NOSE = Symbol("nose")
""" 'nose' symbol """

NOSE_FILL = Symbol("nose.fill")
""" 'nose.fill' symbol """

MUSTACHE = Symbol("mustache")
""" 'mustache' symbol """

MUSTACHE_FILL = Symbol("mustache.fill")
""" 'mustache.fill' symbol """

MOUTH = Symbol("mouth")
""" 'mouth' symbol """

MOUTH_FILL = Symbol("mouth.fill")
""" 'mouth.fill' symbol """

ICLOUD = Symbol("icloud")
""" 'icloud' symbol """

ICLOUD_FILL = Symbol("icloud.fill")
""" 'icloud.fill' symbol """

ICLOUD_CIRCLE = Symbol("icloud.circle")
""" 'icloud.circle' symbol """

ICLOUD_CIRCLE_FILL = Symbol("icloud.circle.fill")
""" 'icloud.circle.fill' symbol """

ICLOUD_SLASH = Symbol("icloud.slash")
""" 'icloud.slash' symbol """

ICLOUD_SLASH_FILL = Symbol("icloud.slash.fill")
""" 'icloud.slash.fill' symbol """

EXCLAMATIONMARK_ICLOUD = Symbol("exclamationmark.icloud")
""" 'exclamationmark.icloud' symbol """

EXCLAMATIONMARK_ICLOUD_FILL = Symbol("exclamationmark.icloud.fill")
""" 'exclamationmark.icloud.fill' symbol """

CHECKMARK_ICLOUD = Symbol("checkmark.icloud")
""" 'checkmark.icloud' symbol """

CHECKMARK_ICLOUD_FILL = Symbol("checkmark.icloud.fill")
""" 'checkmark.icloud.fill' symbol """

XMARK_ICLOUD = Symbol("xmark.icloud")
""" 'xmark.icloud' symbol """

XMARK_ICLOUD_FILL = Symbol("xmark.icloud.fill")
""" 'xmark.icloud.fill' symbol """

LINK_ICLOUD = Symbol("link.icloud")
""" 'link.icloud' symbol """

LINK_ICLOUD_FILL = Symbol("link.icloud.fill")
""" 'link.icloud.fill' symbol """

BOLT_HORIZONTAL_ICLOUD = Symbol("bolt.horizontal.icloud")
""" 'bolt.horizontal.icloud' symbol """

BOLT_HORIZONTAL_ICLOUD_FILL = Symbol("bolt.horizontal.icloud.fill")
""" 'bolt.horizontal.icloud.fill' symbol """

PERSON_ICLOUD = Symbol("person.icloud")
""" 'person.icloud' symbol """

PERSON_ICLOUD_FILL = Symbol("person.icloud.fill")
""" 'person.icloud.fill' symbol """

LOCK_ICLOUD = Symbol("lock.icloud")
""" 'lock.icloud' symbol """

LOCK_ICLOUD_FILL = Symbol("lock.icloud.fill")
""" 'lock.icloud.fill' symbol """

KEY_ICLOUD = Symbol("key.icloud")
""" 'key.icloud' symbol """

KEY_ICLOUD_FILL = Symbol("key.icloud.fill")
""" 'key.icloud.fill' symbol """

ARROW_CLOCKWISE_ICLOUD = Symbol("arrow.clockwise.icloud")
""" 'arrow.clockwise.icloud' symbol """

ARROW_CLOCKWISE_ICLOUD_FILL = Symbol("arrow.clockwise.icloud.fill")
""" 'arrow.clockwise.icloud.fill' symbol """

ARROW_COUNTERCLOCKWISE_ICLOUD = Symbol("arrow.counterclockwise.icloud")
""" 'arrow.counterclockwise.icloud' symbol """

ARROW_COUNTERCLOCKWISE_ICLOUD_FILL = Symbol("arrow.counterclockwise.icloud.fill")
""" 'arrow.counterclockwise.icloud.fill' symbol """

ICLOUD_AND_ARROW_DOWN = Symbol("icloud.and.arrow.down")
""" 'icloud.and.arrow.down' symbol """

ICLOUD_AND_ARROW_DOWN_FILL = Symbol("icloud.and.arrow.down.fill")
""" 'icloud.and.arrow.down.fill' symbol """

ICLOUD_AND_ARROW_UP = Symbol("icloud.and.arrow.up")
""" 'icloud.and.arrow.up' symbol """

ICLOUD_AND_ARROW_UP_FILL = Symbol("icloud.and.arrow.up.fill")
""" 'icloud.and.arrow.up.fill' symbol """

FLASHLIGHT_OFF_FILL = Symbol("flashlight.off.fill")
""" 'flashlight.off.fill' symbol """

FLASHLIGHT_ON_FILL = Symbol("flashlight.on.fill")
""" 'flashlight.on.fill' symbol """

CAMERA = Symbol("camera")
""" 'camera' symbol """

CAMERA_FILL = Symbol("camera.fill")
""" 'camera.fill' symbol """

CAMERA_CIRCLE = Symbol("camera.circle")
""" 'camera.circle' symbol """

CAMERA_CIRCLE_FILL = Symbol("camera.circle.fill")
""" 'camera.circle.fill' symbol """

CAMERA_BADGE_ELLIPSIS = Symbol("camera.badge.ellipsis")
""" 'camera.badge.ellipsis' symbol """

CAMERA_FILL_BADGE_ELLIPSIS = Symbol("camera.fill.badge.ellipsis")
""" 'camera.fill.badge.ellipsis' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH_CAMERA = Symbol("arrow.triangle.2.circlepath.camera")
""" 'arrow.triangle.2.circlepath.camera' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH_CAMERA_FILL = Symbol("arrow.triangle.2.circlepath.camera.fill")
""" 'arrow.triangle.2.circlepath.camera.fill' symbol """

CAMERA_ON_RECTANGLE = Symbol("camera.on.rectangle")
""" 'camera.on.rectangle' symbol """

CAMERA_ON_RECTANGLE_FILL = Symbol("camera.on.rectangle.fill")
""" 'camera.on.rectangle.fill' symbol """

MESSAGE = Symbol("message")
""" 'message' symbol """

MESSAGE_FILL = Symbol("message.fill")
""" 'message.fill' symbol """

MESSAGE_CIRCLE = Symbol("message.circle")
""" 'message.circle' symbol """

MESSAGE_CIRCLE_FILL = Symbol("message.circle.fill")
""" 'message.circle.fill' symbol """

ARROW_UP_MESSAGE = Symbol("arrow.up.message")
""" 'arrow.up.message' symbol """

ARROW_UP_MESSAGE_FILL = Symbol("arrow.up.message.fill")
""" 'arrow.up.message.fill' symbol """

PLUS_MESSAGE = Symbol("plus.message")
""" 'plus.message' symbol """

PLUS_MESSAGE_FILL = Symbol("plus.message.fill")
""" 'plus.message.fill' symbol """

BUBBLE_RIGHT = Symbol("bubble.right")
""" 'bubble.right' symbol """

BUBBLE_RIGHT_FILL = Symbol("bubble.right.fill")
""" 'bubble.right.fill' symbol """

BUBBLE_LEFT = Symbol("bubble.left")
""" 'bubble.left' symbol """

BUBBLE_LEFT_FILL = Symbol("bubble.left.fill")
""" 'bubble.left.fill' symbol """

EXCLAMATIONMARK_BUBBLE = Symbol("exclamationmark.bubble")
""" 'exclamationmark.bubble' symbol """

EXCLAMATIONMARK_BUBBLE_FILL = Symbol("exclamationmark.bubble.fill")
""" 'exclamationmark.bubble.fill' symbol """

QUOTE_BUBBLE = Symbol("quote.bubble")
""" 'quote.bubble' symbol """

QUOTE_BUBBLE_FILL = Symbol("quote.bubble.fill")
""" 'quote.bubble.fill' symbol """

T_BUBBLE = Symbol("t.bubble")
""" 't.bubble' symbol """

T_BUBBLE_FILL = Symbol("t.bubble.fill")
""" 't.bubble.fill' symbol """

TEXT_BUBBLE = Symbol("text.bubble")
""" 'text.bubble' symbol """

TEXT_BUBBLE_FILL = Symbol("text.bubble.fill")
""" 'text.bubble.fill' symbol """

CAPTIONS_BUBBLE = Symbol("captions.bubble")
""" 'captions.bubble' symbol """

CAPTIONS_BUBBLE_FILL = Symbol("captions.bubble.fill")
""" 'captions.bubble.fill' symbol """

PLUS_BUBBLE = Symbol("plus.bubble")
""" 'plus.bubble' symbol """

PLUS_BUBBLE_FILL = Symbol("plus.bubble.fill")
""" 'plus.bubble.fill' symbol """

RECTANGLE_3_OFFGRID_BUBBLE_LEFT = Symbol("rectangle.3.offgrid.bubble.left")
""" 'rectangle.3.offgrid.bubble.left' symbol """

RECTANGLE_3_OFFGRID_BUBBLE_LEFT_FILL = Symbol("rectangle.3.offgrid.bubble.left.fill")
""" 'rectangle.3.offgrid.bubble.left.fill' symbol """

ELLIPSIS_BUBBLE = Symbol("ellipsis.bubble")
""" 'ellipsis.bubble' symbol """

ELLIPSIS_BUBBLE_FILL = Symbol("ellipsis.bubble.fill")
""" 'ellipsis.bubble.fill' symbol """

BUBBLE_MIDDLE_BOTTOM = Symbol("bubble.middle.bottom")
""" 'bubble.middle.bottom' symbol """

BUBBLE_MIDDLE_BOTTOM_FILL = Symbol("bubble.middle.bottom.fill")
""" 'bubble.middle.bottom.fill' symbol """

BUBBLE_MIDDLE_TOP = Symbol("bubble.middle.top")
""" 'bubble.middle.top' symbol """

BUBBLE_MIDDLE_TOP_FILL = Symbol("bubble.middle.top.fill")
""" 'bubble.middle.top.fill' symbol """

BUBBLE_LEFT_AND_BUBBLE_RIGHT = Symbol("bubble.left.and.bubble.right")
""" 'bubble.left.and.bubble.right' symbol """

BUBBLE_LEFT_AND_BUBBLE_RIGHT_FILL = Symbol("bubble.left.and.bubble.right.fill")
""" 'bubble.left.and.bubble.right.fill' symbol """

TRANSLATE = Symbol("translate")
""" 'translate' symbol """

PHONE = Symbol("phone")
""" 'phone' symbol """

PHONE_FILL = Symbol("phone.fill")
""" 'phone.fill' symbol """

PHONE_CIRCLE = Symbol("phone.circle")
""" 'phone.circle' symbol """

PHONE_CIRCLE_FILL = Symbol("phone.circle.fill")
""" 'phone.circle.fill' symbol """

PHONE_BADGE_PLUS = Symbol("phone.badge.plus")
""" 'phone.badge.plus' symbol """

PHONE_FILL_BADGE_PLUS = Symbol("phone.fill.badge.plus")
""" 'phone.fill.badge.plus' symbol """

PHONE_CONNECTION = Symbol("phone.connection")
""" 'phone.connection' symbol """

PHONE_FILL_CONNECTION = Symbol("phone.fill.connection")
""" 'phone.fill.connection' symbol """

PHONE_ARROW_UP_RIGHT = Symbol("phone.arrow.up.right")
""" 'phone.arrow.up.right' symbol """

PHONE_FILL_ARROW_UP_RIGHT = Symbol("phone.fill.arrow.up.right")
""" 'phone.fill.arrow.up.right' symbol """

PHONE_ARROW_DOWN_LEFT = Symbol("phone.arrow.down.left")
""" 'phone.arrow.down.left' symbol """

PHONE_FILL_ARROW_DOWN_LEFT = Symbol("phone.fill.arrow.down.left")
""" 'phone.fill.arrow.down.left' symbol """

PHONE_ARROW_RIGHT = Symbol("phone.arrow.right")
""" 'phone.arrow.right' symbol """

PHONE_FILL_ARROW_RIGHT = Symbol("phone.fill.arrow.right")
""" 'phone.fill.arrow.right' symbol """

PHONE_DOWN = Symbol("phone.down")
""" 'phone.down' symbol """

PHONE_DOWN_FILL = Symbol("phone.down.fill")
""" 'phone.down.fill' symbol """

PHONE_DOWN_CIRCLE = Symbol("phone.down.circle")
""" 'phone.down.circle' symbol """

PHONE_DOWN_CIRCLE_FILL = Symbol("phone.down.circle.fill")
""" 'phone.down.circle.fill' symbol """

TELETYPE = Symbol("teletype")
""" 'teletype' symbol """

TELETYPE_CIRCLE = Symbol("teletype.circle")
""" 'teletype.circle' symbol """

TELETYPE_CIRCLE_FILL = Symbol("teletype.circle.fill")
""" 'teletype.circle.fill' symbol """

TELETYPE_ANSWER = Symbol("teletype.answer")
""" 'teletype.answer' symbol """

VIDEO = Symbol("video")
""" 'video' symbol """

VIDEO_FILL = Symbol("video.fill")
""" 'video.fill' symbol """

VIDEO_CIRCLE = Symbol("video.circle")
""" 'video.circle' symbol """

VIDEO_CIRCLE_FILL = Symbol("video.circle.fill")
""" 'video.circle.fill' symbol """

VIDEO_SLASH = Symbol("video.slash")
""" 'video.slash' symbol """

VIDEO_SLASH_FILL = Symbol("video.slash.fill")
""" 'video.slash.fill' symbol """

VIDEO_BADGE_PLUS = Symbol("video.badge.plus")
""" 'video.badge.plus' symbol """

VIDEO_FILL_BADGE_PLUS = Symbol("video.fill.badge.plus")
""" 'video.fill.badge.plus' symbol """

VIDEO_BADGE_CHECKMARK = Symbol("video.badge.checkmark")
""" 'video.badge.checkmark' symbol """

VIDEO_FILL_BADGE_CHECKMARK = Symbol("video.fill.badge.checkmark")
""" 'video.fill.badge.checkmark' symbol """

ARROW_UP_RIGHT_VIDEO = Symbol("arrow.up.right.video")
""" 'arrow.up.right.video' symbol """

ARROW_UP_RIGHT_VIDEO_FILL = Symbol("arrow.up.right.video.fill")
""" 'arrow.up.right.video.fill' symbol """

ARROW_DOWN_LEFT_VIDEO = Symbol("arrow.down.left.video")
""" 'arrow.down.left.video' symbol """

ARROW_DOWN_LEFT_VIDEO_FILL = Symbol("arrow.down.left.video.fill")
""" 'arrow.down.left.video.fill' symbol """

QUESTIONMARK_VIDEO = Symbol("questionmark.video")
""" 'questionmark.video' symbol """

QUESTIONMARK_VIDEO_FILL = Symbol("questionmark.video.fill")
""" 'questionmark.video.fill' symbol """

ENVELOPE = Symbol("envelope")
""" 'envelope' symbol """

ENVELOPE_FILL = Symbol("envelope.fill")
""" 'envelope.fill' symbol """

ENVELOPE_CIRCLE = Symbol("envelope.circle")
""" 'envelope.circle' symbol """

ENVELOPE_CIRCLE_FILL = Symbol("envelope.circle.fill")
""" 'envelope.circle.fill' symbol """

ENVELOPE_ARROW_TRIANGLE_BRANCH = Symbol("envelope.arrow.triangle.branch")
""" 'envelope.arrow.triangle.branch' symbol """

ENVELOPE_ARROW_TRIANGLE_BRANCH_FILL = Symbol("envelope.arrow.triangle.branch.fill")
""" 'envelope.arrow.triangle.branch.fill' symbol """

ENVELOPE_OPEN = Symbol("envelope.open")
""" 'envelope.open' symbol """

ENVELOPE_OPEN_FILL = Symbol("envelope.open.fill")
""" 'envelope.open.fill' symbol """

ENVELOPE_BADGE = Symbol("envelope.badge")
""" 'envelope.badge' symbol """

ENVELOPE_BADGE_FILL = Symbol("envelope.badge.fill")
""" 'envelope.badge.fill' symbol """

ENVELOPE_BADGE_SHIELD_LEFTHALF_FILL = Symbol("envelope.badge.shield.lefthalf.fill")
""" 'envelope.badge.shield.lefthalf.fill' symbol """

ENVELOPE_FILL_BADGE_SHIELD_RIGHTHALF_FILL = Symbol("envelope.fill.badge.shield.righthalf.fill")
""" 'envelope.fill.badge.shield.righthalf.fill' symbol """

MAIL_STACK = Symbol("mail.stack")
""" 'mail.stack' symbol """

MAIL_STACK_FILL = Symbol("mail.stack.fill")
""" 'mail.stack.fill' symbol """

MAIL = Symbol("mail")
""" 'mail' symbol """

MAIL_FILL = Symbol("mail.fill")
""" 'mail.fill' symbol """

MAIL_AND_TEXT_MAGNIFYINGGLASS = Symbol("mail.and.text.magnifyingglass")
""" 'mail.and.text.magnifyingglass' symbol """

RECTANGLE_AND_TEXT_MAGNIFYINGGLASS = Symbol("rectangle.and.text.magnifyingglass")
""" 'rectangle.and.text.magnifyingglass' symbol """

ARROW_UP_RIGHT_AND_ARROW_DOWN_LEFT_RECTANGLE = Symbol("arrow.up.right.and.arrow.down.left.rectangle")
""" 'arrow.up.right.and.arrow.down.left.rectangle' symbol """

ARROW_UP_RIGHT_AND_ARROW_DOWN_LEFT_RECTANGLE_FILL = Symbol("arrow.up.right.and.arrow.down.left.rectangle.fill")
""" 'arrow.up.right.and.arrow.down.left.rectangle.fill' symbol """

GEAR = Symbol("gear")
""" 'gear' symbol """

GEARSHAPE = Symbol("gearshape")
""" 'gearshape' symbol """

GEARSHAPE_FILL = Symbol("gearshape.fill")
""" 'gearshape.fill' symbol """

GEARSHAPE_2 = Symbol("gearshape.2")
""" 'gearshape.2' symbol """

GEARSHAPE_2_FILL = Symbol("gearshape.2.fill")
""" 'gearshape.2.fill' symbol """

SIGNATURE = Symbol("signature")
""" 'signature' symbol """

LINE_3_CROSSED_SWIRL_CIRCLE = Symbol("line.3.crossed.swirl.circle")
""" 'line.3.crossed.swirl.circle' symbol """

LINE_3_CROSSED_SWIRL_CIRCLE_FILL = Symbol("line.3.crossed.swirl.circle.fill")
""" 'line.3.crossed.swirl.circle.fill' symbol """

SCISSORS = Symbol("scissors")
""" 'scissors' symbol """

SCISSORS_BADGE_ELLIPSIS = Symbol("scissors.badge.ellipsis")
""" 'scissors.badge.ellipsis' symbol """

ELLIPSIS = Symbol("ellipsis")
""" 'ellipsis' symbol """

ELLIPSIS_CIRCLE = Symbol("ellipsis.circle")
""" 'ellipsis.circle' symbol """

ELLIPSIS_CIRCLE_FILL = Symbol("ellipsis.circle.fill")
""" 'ellipsis.circle.fill' symbol """

ELLIPSIS_RECTANGLE = Symbol("ellipsis.rectangle")
""" 'ellipsis.rectangle' symbol """

ELLIPSIS_RECTANGLE_FILL = Symbol("ellipsis.rectangle.fill")
""" 'ellipsis.rectangle.fill' symbol """

BAG = Symbol("bag")
""" 'bag' symbol """

BAG_FILL = Symbol("bag.fill")
""" 'bag.fill' symbol """

BAG_CIRCLE = Symbol("bag.circle")
""" 'bag.circle' symbol """

BAG_CIRCLE_FILL = Symbol("bag.circle.fill")
""" 'bag.circle.fill' symbol """

BAG_BADGE_PLUS = Symbol("bag.badge.plus")
""" 'bag.badge.plus' symbol """

BAG_FILL_BADGE_PLUS = Symbol("bag.fill.badge.plus")
""" 'bag.fill.badge.plus' symbol """

BAG_BADGE_MINUS = Symbol("bag.badge.minus")
""" 'bag.badge.minus' symbol """

BAG_FILL_BADGE_MINUS = Symbol("bag.fill.badge.minus")
""" 'bag.fill.badge.minus' symbol """

CART = Symbol("cart")
""" 'cart' symbol """

CART_FILL = Symbol("cart.fill")
""" 'cart.fill' symbol """

CART_BADGE_PLUS = Symbol("cart.badge.plus")
""" 'cart.badge.plus' symbol """

CART_FILL_BADGE_PLUS = Symbol("cart.fill.badge.plus")
""" 'cart.fill.badge.plus' symbol """

CART_BADGE_MINUS = Symbol("cart.badge.minus")
""" 'cart.badge.minus' symbol """

CART_FILL_BADGE_MINUS = Symbol("cart.fill.badge.minus")
""" 'cart.fill.badge.minus' symbol """

CREDITCARD = Symbol("creditcard")
""" 'creditcard' symbol """

CREDITCARD_FILL = Symbol("creditcard.fill")
""" 'creditcard.fill' symbol """

CREDITCARD_CIRCLE = Symbol("creditcard.circle")
""" 'creditcard.circle' symbol """

CREDITCARD_CIRCLE_FILL = Symbol("creditcard.circle.fill")
""" 'creditcard.circle.fill' symbol """

GIFTCARD = Symbol("giftcard")
""" 'giftcard' symbol """

GIFTCARD_FILL = Symbol("giftcard.fill")
""" 'giftcard.fill' symbol """

WALLET_PASS = Symbol("wallet.pass")
""" 'wallet.pass' symbol """

WALLET_PASS_FILL = Symbol("wallet.pass.fill")
""" 'wallet.pass.fill' symbol """

WAND_AND_RAYS = Symbol("wand.and.rays")
""" 'wand.and.rays' symbol """

WAND_AND_RAYS_INVERSE = Symbol("wand.and.rays.inverse")
""" 'wand.and.rays.inverse' symbol """

WAND_AND_STARS = Symbol("wand.and.stars")
""" 'wand.and.stars' symbol """

WAND_AND_STARS_INVERSE = Symbol("wand.and.stars.inverse")
""" 'wand.and.stars.inverse' symbol """

CROP = Symbol("crop")
""" 'crop' symbol """

CROP_ROTATE = Symbol("crop.rotate")
""" 'crop.rotate' symbol """

DIAL_MIN = Symbol("dial.min")
""" 'dial.min' symbol """

DIAL_MIN_FILL = Symbol("dial.min.fill")
""" 'dial.min.fill' symbol """

DIAL_MAX = Symbol("dial.max")
""" 'dial.max' symbol """

DIAL_MAX_FILL = Symbol("dial.max.fill")
""" 'dial.max.fill' symbol """

GYROSCOPE = Symbol("gyroscope")
""" 'gyroscope' symbol """

NOSIGN = Symbol("nosign")
""" 'nosign' symbol """

GAUGE = Symbol("gauge")
""" 'gauge' symbol """

GAUGE_BADGE_PLUS = Symbol("gauge.badge.plus")
""" 'gauge.badge.plus' symbol """

GAUGE_BADGE_MINUS = Symbol("gauge.badge.minus")
""" 'gauge.badge.minus' symbol """

SPEEDOMETER = Symbol("speedometer")
""" 'speedometer' symbol """

BAROMETER = Symbol("barometer")
""" 'barometer' symbol """

METRONOME = Symbol("metronome")
""" 'metronome' symbol """

METRONOME_FILL = Symbol("metronome.fill")
""" 'metronome.fill' symbol """

AMPLIFIER = Symbol("amplifier")
""" 'amplifier' symbol """

DIE_FACE_1 = Symbol("die.face.1")
""" 'die.face.1' symbol """

DIE_FACE_1_FILL = Symbol("die.face.1.fill")
""" 'die.face.1.fill' symbol """

DIE_FACE_2 = Symbol("die.face.2")
""" 'die.face.2' symbol """

DIE_FACE_2_FILL = Symbol("die.face.2.fill")
""" 'die.face.2.fill' symbol """

DIE_FACE_3 = Symbol("die.face.3")
""" 'die.face.3' symbol """

DIE_FACE_3_FILL = Symbol("die.face.3.fill")
""" 'die.face.3.fill' symbol """

DIE_FACE_4 = Symbol("die.face.4")
""" 'die.face.4' symbol """

DIE_FACE_4_FILL = Symbol("die.face.4.fill")
""" 'die.face.4.fill' symbol """

DIE_FACE_5 = Symbol("die.face.5")
""" 'die.face.5' symbol """

DIE_FACE_5_FILL = Symbol("die.face.5.fill")
""" 'die.face.5.fill' symbol """

DIE_FACE_6 = Symbol("die.face.6")
""" 'die.face.6' symbol """

DIE_FACE_6_FILL = Symbol("die.face.6.fill")
""" 'die.face.6.fill' symbol """

SQUARE_GRID_3X3_FILL_SQUARE = Symbol("square.grid.3x3.fill.square")
""" 'square.grid.3x3.fill.square' symbol """

PIANOKEYS = Symbol("pianokeys")
""" 'pianokeys' symbol """

TUNINGFORK = Symbol("tuningfork")
""" 'tuningfork' symbol """

PAINTBRUSH = Symbol("paintbrush")
""" 'paintbrush' symbol """

PAINTBRUSH_FILL = Symbol("paintbrush.fill")
""" 'paintbrush.fill' symbol """

PAINTBRUSH_POINTED = Symbol("paintbrush.pointed")
""" 'paintbrush.pointed' symbol """

PAINTBRUSH_POINTED_FILL = Symbol("paintbrush.pointed.fill")
""" 'paintbrush.pointed.fill' symbol """

BANDAGE = Symbol("bandage")
""" 'bandage' symbol """

BANDAGE_FILL = Symbol("bandage.fill")
""" 'bandage.fill' symbol """

RULER = Symbol("ruler")
""" 'ruler' symbol """

RULER_FILL = Symbol("ruler.fill")
""" 'ruler.fill' symbol """

LEVEL = Symbol("level")
""" 'level' symbol """

LEVEL_FILL = Symbol("level.fill")
""" 'level.fill' symbol """

WRENCH = Symbol("wrench")
""" 'wrench' symbol """

WRENCH_FILL = Symbol("wrench.fill")
""" 'wrench.fill' symbol """

HAMMER = Symbol("hammer")
""" 'hammer' symbol """

HAMMER_FILL = Symbol("hammer.fill")
""" 'hammer.fill' symbol """

EYEDROPPER = Symbol("eyedropper")
""" 'eyedropper' symbol """

EYEDROPPER_HALFFULL = Symbol("eyedropper.halffull")
""" 'eyedropper.halffull' symbol """

EYEDROPPER_FULL = Symbol("eyedropper.full")
""" 'eyedropper.full' symbol """

WRENCH_AND_SCREWDRIVER = Symbol("wrench.and.screwdriver")
""" 'wrench.and.screwdriver' symbol """

WRENCH_AND_SCREWDRIVER_FILL = Symbol("wrench.and.screwdriver.fill")
""" 'wrench.and.screwdriver.fill' symbol """

APPLESCRIPT = Symbol("applescript")
""" 'applescript' symbol """

APPLESCRIPT_FILL = Symbol("applescript.fill")
""" 'applescript.fill' symbol """

SCROLL = Symbol("scroll")
""" 'scroll' symbol """

SCROLL_FILL = Symbol("scroll.fill")
""" 'scroll.fill' symbol """

STETHOSCOPE = Symbol("stethoscope")
""" 'stethoscope' symbol """

PRINTER = Symbol("printer")
""" 'printer' symbol """

PRINTER_FILL = Symbol("printer.fill")
""" 'printer.fill' symbol """

PRINTER_FILL_AND_PAPER_FILL = Symbol("printer.fill.and.paper.fill")
""" 'printer.fill.and.paper.fill' symbol """

PRINTER_DOTMATRIX = Symbol("printer.dotmatrix")
""" 'printer.dotmatrix' symbol """

PRINTER_DOTMATRIX_FILL = Symbol("printer.dotmatrix.fill")
""" 'printer.dotmatrix.fill' symbol """

PRINTER_DOTMATRIX_FILL_AND_PAPER_FILL = Symbol("printer.dotmatrix.fill.and.paper.fill")
""" 'printer.dotmatrix.fill.and.paper.fill' symbol """

SCANNER = Symbol("scanner")
""" 'scanner' symbol """

SCANNER_FILL = Symbol("scanner.fill")
""" 'scanner.fill' symbol """

FAXMACHINE = Symbol("faxmachine")
""" 'faxmachine' symbol """

BRIEFCASE = Symbol("briefcase")
""" 'briefcase' symbol """

BRIEFCASE_FILL = Symbol("briefcase.fill")
""" 'briefcase.fill' symbol """

CASE = Symbol("case")
""" 'case' symbol """

CASE_FILL = Symbol("case.fill")
""" 'case.fill' symbol """

LATCH_2_CASE = Symbol("latch.2.case")
""" 'latch.2.case' symbol """

LATCH_2_CASE_FILL = Symbol("latch.2.case.fill")
""" 'latch.2.case.fill' symbol """

CROSS_CASE = Symbol("cross.case")
""" 'cross.case' symbol """

CROSS_CASE_FILL = Symbol("cross.case.fill")
""" 'cross.case.fill' symbol """

PUZZLEPIECE = Symbol("puzzlepiece")
""" 'puzzlepiece' symbol """

PUZZLEPIECE_FILL = Symbol("puzzlepiece.fill")
""" 'puzzlepiece.fill' symbol """

HOMEKIT = Symbol("homekit")
""" 'homekit' symbol """

HOUSE = Symbol("house")
""" 'house' symbol """

HOUSE_FILL = Symbol("house.fill")
""" 'house.fill' symbol """

HOUSE_CIRCLE = Symbol("house.circle")
""" 'house.circle' symbol """

HOUSE_CIRCLE_FILL = Symbol("house.circle.fill")
""" 'house.circle.fill' symbol """

MUSIC_NOTE_HOUSE = Symbol("music.note.house")
""" 'music.note.house' symbol """

MUSIC_NOTE_HOUSE_FILL = Symbol("music.note.house.fill")
""" 'music.note.house.fill' symbol """

BUILDING_COLUMNS = Symbol("building.columns")
""" 'building.columns' symbol """

BUILDING_COLUMNS_FILL = Symbol("building.columns.fill")
""" 'building.columns.fill' symbol """

SQUARE_SPLIT_BOTTOMRIGHTQUARTER = Symbol("square.split.bottomrightquarter")
""" 'square.split.bottomrightquarter' symbol """

SQUARE_SPLIT_BOTTOMRIGHTQUARTER_FILL = Symbol("square.split.bottomrightquarter.fill")
""" 'square.split.bottomrightquarter.fill' symbol """

BUILDING = Symbol("building")
""" 'building' symbol """

BUILDING_FILL = Symbol("building.fill")
""" 'building.fill' symbol """

BUILDING_2 = Symbol("building.2")
""" 'building.2' symbol """

BUILDING_2_FILL = Symbol("building.2.fill")
""" 'building.2.fill' symbol """

BUILDING_2_CROP_CIRCLE = Symbol("building.2.crop.circle")
""" 'building.2.crop.circle' symbol """

BUILDING_2_CROP_CIRCLE_FILL = Symbol("building.2.crop.circle.fill")
""" 'building.2.crop.circle.fill' symbol """

LOCK = Symbol("lock")
""" 'lock' symbol """

LOCK_FILL = Symbol("lock.fill")
""" 'lock.fill' symbol """

LOCK_CIRCLE = Symbol("lock.circle")
""" 'lock.circle' symbol """

LOCK_CIRCLE_FILL = Symbol("lock.circle.fill")
""" 'lock.circle.fill' symbol """

LOCK_SQUARE = Symbol("lock.square")
""" 'lock.square' symbol """

LOCK_SQUARE_FILL = Symbol("lock.square.fill")
""" 'lock.square.fill' symbol """

LOCK_SQUARE_STACK = Symbol("lock.square.stack")
""" 'lock.square.stack' symbol """

LOCK_SQUARE_STACK_FILL = Symbol("lock.square.stack.fill")
""" 'lock.square.stack.fill' symbol """

LOCK_RECTANGLE = Symbol("lock.rectangle")
""" 'lock.rectangle' symbol """

LOCK_RECTANGLE_FILL = Symbol("lock.rectangle.fill")
""" 'lock.rectangle.fill' symbol """

LOCK_RECTANGLE_STACK = Symbol("lock.rectangle.stack")
""" 'lock.rectangle.stack' symbol """

LOCK_RECTANGLE_STACK_FILL = Symbol("lock.rectangle.stack.fill")
""" 'lock.rectangle.stack.fill' symbol """

LOCK_RECTANGLE_ON_RECTANGLE = Symbol("lock.rectangle.on.rectangle")
""" 'lock.rectangle.on.rectangle' symbol """

LOCK_RECTANGLE_ON_RECTANGLE_FILL = Symbol("lock.rectangle.on.rectangle.fill")
""" 'lock.rectangle.on.rectangle.fill' symbol """

LOCK_SHIELD = Symbol("lock.shield")
""" 'lock.shield' symbol """

LOCK_SHIELD_FILL = Symbol("lock.shield.fill")
""" 'lock.shield.fill' symbol """

LOCK_SLASH = Symbol("lock.slash")
""" 'lock.slash' symbol """

LOCK_SLASH_FILL = Symbol("lock.slash.fill")
""" 'lock.slash.fill' symbol """

LOCK_OPEN = Symbol("lock.open")
""" 'lock.open' symbol """

LOCK_OPEN_FILL = Symbol("lock.open.fill")
""" 'lock.open.fill' symbol """

LOCK_ROTATION = Symbol("lock.rotation")
""" 'lock.rotation' symbol """

LOCK_ROTATION_OPEN = Symbol("lock.rotation.open")
""" 'lock.rotation.open' symbol """

KEY = Symbol("key")
""" 'key' symbol """

KEY_FILL = Symbol("key.fill")
""" 'key.fill' symbol """

WIFI = Symbol("wifi")
""" 'wifi' symbol """

WIFI_SLASH = Symbol("wifi.slash")
""" 'wifi.slash' symbol """

WIFI_EXCLAMATIONMARK = Symbol("wifi.exclamationmark")
""" 'wifi.exclamationmark' symbol """

PIN = Symbol("pin")
""" 'pin' symbol """

PIN_FILL = Symbol("pin.fill")
""" 'pin.fill' symbol """

PIN_CIRCLE = Symbol("pin.circle")
""" 'pin.circle' symbol """

PIN_CIRCLE_FILL = Symbol("pin.circle.fill")
""" 'pin.circle.fill' symbol """

PIN_SLASH = Symbol("pin.slash")
""" 'pin.slash' symbol """

PIN_SLASH_FILL = Symbol("pin.slash.fill")
""" 'pin.slash.fill' symbol """

MAPPIN = Symbol("mappin")
""" 'mappin' symbol """

MAPPIN_CIRCLE = Symbol("mappin.circle")
""" 'mappin.circle' symbol """

MAPPIN_CIRCLE_FILL = Symbol("mappin.circle.fill")
""" 'mappin.circle.fill' symbol """

MAPPIN_SLASH = Symbol("mappin.slash")
""" 'mappin.slash' symbol """

MAPPIN_AND_ELLIPSE = Symbol("mappin.and.ellipse")
""" 'mappin.and.ellipse' symbol """

MAP = Symbol("map")
""" 'map' symbol """

MAP_FILL = Symbol("map.fill")
""" 'map.fill' symbol """

SAFARI = Symbol("safari")
""" 'safari' symbol """

SAFARI_FILL = Symbol("safari.fill")
""" 'safari.fill' symbol """

MOVE_3D = Symbol("move.3d")
""" 'move.3d' symbol """

SCALE_3D = Symbol("scale.3d")
""" 'scale.3d' symbol """

ROTATE_3D = Symbol("rotate.3d")
""" 'rotate.3d' symbol """

ROTATE_LEFT = Symbol("rotate.left")
""" 'rotate.left' symbol """

ROTATE_LEFT_FILL = Symbol("rotate.left.fill")
""" 'rotate.left.fill' symbol """

ROTATE_RIGHT = Symbol("rotate.right")
""" 'rotate.right' symbol """

ROTATE_RIGHT_FILL = Symbol("rotate.right.fill")
""" 'rotate.right.fill' symbol """

SELECTION_PIN_IN_OUT = Symbol("selection.pin.in.out")
""" 'selection.pin.in.out' symbol """

TIMELINE_SELECTION = Symbol("timeline.selection")
""" 'timeline.selection' symbol """

CPU = Symbol("cpu")
""" 'cpu' symbol """

MEMORYCHIP = Symbol("memorychip")
""" 'memorychip' symbol """

OPTICALDISC = Symbol("opticaldisc")
""" 'opticaldisc' symbol """

TV = Symbol("tv")
""" 'tv' symbol """

TV_FILL = Symbol("tv.fill")
""" 'tv.fill' symbol """

TV_CIRCLE = Symbol("tv.circle")
""" 'tv.circle' symbol """

TV_CIRCLE_FILL = Symbol("tv.circle.fill")
""" 'tv.circle.fill' symbol """

N4K_TV = Symbol("4k.tv")
""" '4k.tv' symbol """

N4K_TV_FILL = Symbol("4k.tv.fill")
""" '4k.tv.fill' symbol """

TV_MUSIC_NOTE = Symbol("tv.music.note")
""" 'tv.music.note' symbol """

TV_MUSIC_NOTE_FILL = Symbol("tv.music.note.fill")
""" 'tv.music.note.fill' symbol """

TV_AND_HIFISPEAKER_FILL = Symbol("tv.and.hifispeaker.fill")
""" 'tv.and.hifispeaker.fill' symbol """

DISPLAY = Symbol("display")
""" 'display' symbol """

DISPLAY_TRIANGLEBADGE_EXCLAMATIONMARK = Symbol("display.trianglebadge.exclamationmark")
""" 'display.trianglebadge.exclamationmark' symbol """

DISPLAY_2 = Symbol("display.2")
""" 'display.2' symbol """

DESKTOPCOMPUTER = Symbol("desktopcomputer")
""" 'desktopcomputer' symbol """

PC = Symbol("pc")
""" 'pc' symbol """

MACPRO_GEN1 = Symbol("macpro.gen1")
""" 'macpro.gen1' symbol """

MACPRO_GEN2 = Symbol("macpro.gen2")
""" 'macpro.gen2' symbol """

MACPRO_GEN2_FILL = Symbol("macpro.gen2.fill")
""" 'macpro.gen2.fill' symbol """

MACPRO_GEN3 = Symbol("macpro.gen3")
""" 'macpro.gen3' symbol """

SERVER_RACK = Symbol("server.rack")
""" 'server.rack' symbol """

XSERVE = Symbol("xserve")
""" 'xserve' symbol """

MACPRO_GEN3_SERVER = Symbol("macpro.gen3.server")
""" 'macpro.gen3.server' symbol """

LAPTOPCOMPUTER = Symbol("laptopcomputer")
""" 'laptopcomputer' symbol """

LAPTOPCOMPUTER_AND_IPHONE = Symbol("laptopcomputer.and.iphone")
""" 'laptopcomputer.and.iphone' symbol """

MACMINI = Symbol("macmini")
""" 'macmini' symbol """

MACMINI_FILL = Symbol("macmini.fill")
""" 'macmini.fill' symbol """

AIRPORT_EXPRESS = Symbol("airport.express")
""" 'airport.express' symbol """

AIRPORT_EXTREME_TOWER = Symbol("airport.extreme.tower")
""" 'airport.extreme.tower' symbol """

AIRPORT_EXTREME = Symbol("airport.extreme")
""" 'airport.extreme' symbol """

IPOD = Symbol("ipod")
""" 'ipod' symbol """

FLIPPHONE = Symbol("flipphone")
""" 'flipphone' symbol """

CANDYBARPHONE = Symbol("candybarphone")
""" 'candybarphone' symbol """

IPHONE_HOMEBUTTON = Symbol("iphone.homebutton")
""" 'iphone.homebutton' symbol """

IPHONE_HOMEBUTTON_RADIOWAVES_LEFT_AND_RIGHT = Symbol("iphone.homebutton.radiowaves.left.and.right")
""" 'iphone.homebutton.radiowaves.left.and.right' symbol """

IPHONE_HOMEBUTTON_SLASH = Symbol("iphone.homebutton.slash")
""" 'iphone.homebutton.slash' symbol """

IPHONE = Symbol("iphone")
""" 'iphone' symbol """

IPHONE_RADIOWAVES_LEFT_AND_RIGHT = Symbol("iphone.radiowaves.left.and.right")
""" 'iphone.radiowaves.left.and.right' symbol """

IPHONE_SLASH = Symbol("iphone.slash")
""" 'iphone.slash' symbol """

ARROW_TURN_UP_RIGHT_IPHONE = Symbol("arrow.turn.up.right.iphone")
""" 'arrow.turn.up.right.iphone' symbol """

ARROW_TURN_UP_RIGHT_IPHONE_FILL = Symbol("arrow.turn.up.right.iphone.fill")
""" 'arrow.turn.up.right.iphone.fill' symbol """

APPS_IPHONE = Symbol("apps.iphone")
""" 'apps.iphone' symbol """

APPS_IPHONE_BADGE_PLUS = Symbol("apps.iphone.badge.plus")
""" 'apps.iphone.badge.plus' symbol """

APPS_IPHONE_LANDSCAPE = Symbol("apps.iphone.landscape")
""" 'apps.iphone.landscape' symbol """

IPODTOUCH = Symbol("ipodtouch")
""" 'ipodtouch' symbol """

IPODSHUFFLE_GEN1 = Symbol("ipodshuffle.gen1")
""" 'ipodshuffle.gen1' symbol """

IPODSHUFFLE_GEN2 = Symbol("ipodshuffle.gen2")
""" 'ipodshuffle.gen2' symbol """

IPODSHUFFLE_GEN3 = Symbol("ipodshuffle.gen3")
""" 'ipodshuffle.gen3' symbol """

IPODSHUFFLE_GEN4 = Symbol("ipodshuffle.gen4")
""" 'ipodshuffle.gen4' symbol """

IPAD_HOMEBUTTON = Symbol("ipad.homebutton")
""" 'ipad.homebutton' symbol """

IPAD = Symbol("ipad")
""" 'ipad' symbol """

APPS_IPAD = Symbol("apps.ipad")
""" 'apps.ipad' symbol """

IPAD_HOMEBUTTON_LANDSCAPE = Symbol("ipad.homebutton.landscape")
""" 'ipad.homebutton.landscape' symbol """

IPAD_LANDSCAPE = Symbol("ipad.landscape")
""" 'ipad.landscape' symbol """

APPS_IPAD_LANDSCAPE = Symbol("apps.ipad.landscape")
""" 'apps.ipad.landscape' symbol """

APPLEWATCH = Symbol("applewatch")
""" 'applewatch' symbol """

APPLEWATCH_WATCHFACE = Symbol("applewatch.watchface")
""" 'applewatch.watchface' symbol """

APPLEWATCH_RADIOWAVES_LEFT_AND_RIGHT = Symbol("applewatch.radiowaves.left.and.right")
""" 'applewatch.radiowaves.left.and.right' symbol """

APPLEWATCH_SLASH = Symbol("applewatch.slash")
""" 'applewatch.slash' symbol """

AIRPODS = Symbol("airpods")
""" 'airpods' symbol """

EARPODS = Symbol("earpods")
""" 'earpods' symbol """

AIRPODSPRO = Symbol("airpodspro")
""" 'airpodspro' symbol """

HOMEPOD = Symbol("homepod")
""" 'homepod' symbol """

HOMEPOD_FILL = Symbol("homepod.fill")
""" 'homepod.fill' symbol """

HIFISPEAKER = Symbol("hifispeaker")
""" 'hifispeaker' symbol """

HIFISPEAKER_FILL = Symbol("hifispeaker.fill")
""" 'hifispeaker.fill' symbol """

RADIO = Symbol("radio")
""" 'radio' symbol """

RADIO_FILL = Symbol("radio.fill")
""" 'radio.fill' symbol """

APPLETV = Symbol("appletv")
""" 'appletv' symbol """

APPLETV_FILL = Symbol("appletv.fill")
""" 'appletv.fill' symbol """

SIGNPOST_RIGHT = Symbol("signpost.right")
""" 'signpost.right' symbol """

SIGNPOST_RIGHT_FILL = Symbol("signpost.right.fill")
""" 'signpost.right.fill' symbol """

AIRPLAYVIDEO = Symbol("airplayvideo")
""" 'airplayvideo' symbol """

AIRPLAYAUDIO = Symbol("airplayaudio")
""" 'airplayaudio' symbol """

DOT_RADIOWAVES_LEFT_AND_RIGHT = Symbol("dot.radiowaves.left.and.right")
""" 'dot.radiowaves.left.and.right' symbol """

DOT_RADIOWAVES_RIGHT = Symbol("dot.radiowaves.right")
""" 'dot.radiowaves.right' symbol """

WAVE_3_LEFT = Symbol("wave.3.left")
""" 'wave.3.left' symbol """

WAVE_3_LEFT_CIRCLE = Symbol("wave.3.left.circle")
""" 'wave.3.left.circle' symbol """

WAVE_3_LEFT_CIRCLE_FILL = Symbol("wave.3.left.circle.fill")
""" 'wave.3.left.circle.fill' symbol """

WAVE_3_RIGHT = Symbol("wave.3.right")
""" 'wave.3.right' symbol """

WAVE_3_RIGHT_CIRCLE = Symbol("wave.3.right.circle")
""" 'wave.3.right.circle' symbol """

WAVE_3_RIGHT_CIRCLE_FILL = Symbol("wave.3.right.circle.fill")
""" 'wave.3.right.circle.fill' symbol """

ANTENNA_RADIOWAVES_LEFT_AND_RIGHT = Symbol("antenna.radiowaves.left.and.right")
""" 'antenna.radiowaves.left.and.right' symbol """

PIP = Symbol("pip")
""" 'pip' symbol """

PIP_FILL = Symbol("pip.fill")
""" 'pip.fill' symbol """

PIP_EXIT = Symbol("pip.exit")
""" 'pip.exit' symbol """

PIP_ENTER = Symbol("pip.enter")
""" 'pip.enter' symbol """

PIP_SWAP = Symbol("pip.swap")
""" 'pip.swap' symbol """

PIP_REMOVE = Symbol("pip.remove")
""" 'pip.remove' symbol """

RECTANGLE_ARROWTRIANGLE_2_OUTWARD = Symbol("rectangle.arrowtriangle.2.outward")
""" 'rectangle.arrowtriangle.2.outward' symbol """

RECTANGLE_ARROWTRIANGLE_2_INWARD = Symbol("rectangle.arrowtriangle.2.inward")
""" 'rectangle.arrowtriangle.2.inward' symbol """

RECTANGLE_PORTRAIT_ARROWTRIANGLE_2_OUTWARD = Symbol("rectangle.portrait.arrowtriangle.2.outward")
""" 'rectangle.portrait.arrowtriangle.2.outward' symbol """

RECTANGLE_PORTRAIT_ARROWTRIANGLE_2_INWARD = Symbol("rectangle.portrait.arrowtriangle.2.inward")
""" 'rectangle.portrait.arrowtriangle.2.inward' symbol """

GUITARS = Symbol("guitars")
""" 'guitars' symbol """

GUITARS_FILL = Symbol("guitars.fill")
""" 'guitars.fill' symbol """

CAR = Symbol("car")
""" 'car' symbol """

CAR_FILL = Symbol("car.fill")
""" 'car.fill' symbol """

CAR_CIRCLE = Symbol("car.circle")
""" 'car.circle' symbol """

CAR_CIRCLE_FILL = Symbol("car.circle.fill")
""" 'car.circle.fill' symbol """

BOLT_CAR = Symbol("bolt.car")
""" 'bolt.car' symbol """

BOLT_CAR_FILL = Symbol("bolt.car.fill")
""" 'bolt.car.fill' symbol """

CAR_2 = Symbol("car.2")
""" 'car.2' symbol """

CAR_2_FILL = Symbol("car.2.fill")
""" 'car.2.fill' symbol """

BUS = Symbol("bus")
""" 'bus' symbol """

BUS_FILL = Symbol("bus.fill")
""" 'bus.fill' symbol """

BUS_DOUBLEDECKER = Symbol("bus.doubledecker")
""" 'bus.doubledecker' symbol """

BUS_DOUBLEDECKER_FILL = Symbol("bus.doubledecker.fill")
""" 'bus.doubledecker.fill' symbol """

TRAM = Symbol("tram")
""" 'tram' symbol """

TRAM_FILL = Symbol("tram.fill")
""" 'tram.fill' symbol """

TRAM_TUNNEL_FILL = Symbol("tram.tunnel.fill")
""" 'tram.tunnel.fill' symbol """

BICYCLE = Symbol("bicycle")
""" 'bicycle' symbol """

BED_DOUBLE = Symbol("bed.double")
""" 'bed.double' symbol """

BED_DOUBLE_FILL = Symbol("bed.double.fill")
""" 'bed.double.fill' symbol """

LUNGS = Symbol("lungs")
""" 'lungs' symbol """

LUNGS_FILL = Symbol("lungs.fill")
""" 'lungs.fill' symbol """

PILLS = Symbol("pills")
""" 'pills' symbol """

PILLS_FILL = Symbol("pills.fill")
""" 'pills.fill' symbol """

CROSS = Symbol("cross")
""" 'cross' symbol """

CROSS_FILL = Symbol("cross.fill")
""" 'cross.fill' symbol """

CROSS_CIRCLE = Symbol("cross.circle")
""" 'cross.circle' symbol """

CROSS_CIRCLE_FILL = Symbol("cross.circle.fill")
""" 'cross.circle.fill' symbol """

HARE = Symbol("hare")
""" 'hare' symbol """

HARE_FILL = Symbol("hare.fill")
""" 'hare.fill' symbol """

TORTOISE = Symbol("tortoise")
""" 'tortoise' symbol """

TORTOISE_FILL = Symbol("tortoise.fill")
""" 'tortoise.fill' symbol """

ANT = Symbol("ant")
""" 'ant' symbol """

ANT_FILL = Symbol("ant.fill")
""" 'ant.fill' symbol """

ANT_CIRCLE = Symbol("ant.circle")
""" 'ant.circle' symbol """

ANT_CIRCLE_FILL = Symbol("ant.circle.fill")
""" 'ant.circle.fill' symbol """

LEAF = Symbol("leaf")
""" 'leaf' symbol """

LEAF_FILL = Symbol("leaf.fill")
""" 'leaf.fill' symbol """

LEAF_ARROW_TRIANGLE_CIRCLEPATH = Symbol("leaf.arrow.triangle.circlepath")
""" 'leaf.arrow.triangle.circlepath' symbol """

FILM = Symbol("film")
""" 'film' symbol """

FILM_FILL = Symbol("film.fill")
""" 'film.fill' symbol """

SPORTSCOURT = Symbol("sportscourt")
""" 'sportscourt' symbol """

SPORTSCOURT_FILL = Symbol("sportscourt.fill")
""" 'sportscourt.fill' symbol """

FACE_SMILING = Symbol("face.smiling")
""" 'face.smiling' symbol """

FACE_SMILING_FILL = Symbol("face.smiling.fill")
""" 'face.smiling.fill' symbol """

FACE_DASHED = Symbol("face.dashed")
""" 'face.dashed' symbol """

FACE_DASHED_FILL = Symbol("face.dashed.fill")
""" 'face.dashed.fill' symbol """

CROWN = Symbol("crown")
""" 'crown' symbol """

CROWN_FILL = Symbol("crown.fill")
""" 'crown.fill' symbol """

COMB = Symbol("comb")
""" 'comb' symbol """

COMB_FILL = Symbol("comb.fill")
""" 'comb.fill' symbol """

QRCODE = Symbol("qrcode")
""" 'qrcode' symbol """

BARCODE = Symbol("barcode")
""" 'barcode' symbol """

VIEWFINDER = Symbol("viewfinder")
""" 'viewfinder' symbol """

VIEWFINDER_CIRCLE = Symbol("viewfinder.circle")
""" 'viewfinder.circle' symbol """

VIEWFINDER_CIRCLE_FILL = Symbol("viewfinder.circle.fill")
""" 'viewfinder.circle.fill' symbol """

BARCODE_VIEWFINDER = Symbol("barcode.viewfinder")
""" 'barcode.viewfinder' symbol """

QRCODE_VIEWFINDER = Symbol("qrcode.viewfinder")
""" 'qrcode.viewfinder' symbol """

PLUS_VIEWFINDER = Symbol("plus.viewfinder")
""" 'plus.viewfinder' symbol """

CAMERA_VIEWFINDER = Symbol("camera.viewfinder")
""" 'camera.viewfinder' symbol """

FACEID = Symbol("faceid")
""" 'faceid' symbol """

DOC_TEXT_VIEWFINDER = Symbol("doc.text.viewfinder")
""" 'doc.text.viewfinder' symbol """

DOC_TEXT_FILL_VIEWFINDER = Symbol("doc.text.fill.viewfinder")
""" 'doc.text.fill.viewfinder' symbol """

LOCATION_VIEWFINDER = Symbol("location.viewfinder")
""" 'location.viewfinder' symbol """

LOCATION_FILL_VIEWFINDER = Symbol("location.fill.viewfinder")
""" 'location.fill.viewfinder' symbol """

RECTANGLE_INSET_FILL = Symbol("rectangle.inset.fill")
""" 'rectangle.inset.fill' symbol """

RECTANGLE_LEFTHALF_INSET_FILL = Symbol("rectangle.lefthalf.inset.fill")
""" 'rectangle.lefthalf.inset.fill' symbol """

RECTANGLE_RIGHTHALF_INSET_FILL = Symbol("rectangle.righthalf.inset.fill")
""" 'rectangle.righthalf.inset.fill' symbol """

RECTANGLE_BOTTOMTHIRD_INSET_FILL = Symbol("rectangle.bottomthird.inset.fill")
""" 'rectangle.bottomthird.inset.fill' symbol """

RECTANGLE_LEFTTHIRD_INSET_FILL = Symbol("rectangle.leftthird.inset.fill")
""" 'rectangle.leftthird.inset.fill' symbol """

RECTANGLE_RIGHTTHIRD_INSET_FILL = Symbol("rectangle.rightthird.inset.fill")
""" 'rectangle.rightthird.inset.fill' symbol """

RECTANGLE_CENTER_INSET_FILL = Symbol("rectangle.center.inset.fill")
""" 'rectangle.center.inset.fill' symbol """

RECTANGLE_INSET_TOPLEFT_FILL = Symbol("rectangle.inset.topleft.fill")
""" 'rectangle.inset.topleft.fill' symbol """

RECTANGLE_INSET_TOPRIGHT_FILL = Symbol("rectangle.inset.topright.fill")
""" 'rectangle.inset.topright.fill' symbol """

RECTANGLE_INSET_BOTTOMLEFT_FILL = Symbol("rectangle.inset.bottomleft.fill")
""" 'rectangle.inset.bottomleft.fill' symbol """

RECTANGLE_INSET_BOTTOMRIGHT_FILL = Symbol("rectangle.inset.bottomright.fill")
""" 'rectangle.inset.bottomright.fill' symbol """

RECTANGLE_LEFTHALF_INSET_FILL_ARROW_LEFT = Symbol("rectangle.lefthalf.inset.fill.arrow.left")
""" 'rectangle.lefthalf.inset.fill.arrow.left' symbol """

RECTANGLE_RIGHTHALF_INSET_FILL_ARROW_RIGHT = Symbol("rectangle.righthalf.inset.fill.arrow.right")
""" 'rectangle.righthalf.inset.fill.arrow.right' symbol """

RECTANGLE_LEFTHALF_FILL = Symbol("rectangle.lefthalf.fill")
""" 'rectangle.lefthalf.fill' symbol """

RECTANGLE_RIGHTHALF_FILL = Symbol("rectangle.righthalf.fill")
""" 'rectangle.righthalf.fill' symbol """

PERSON_CROP_RECTANGLE = Symbol("person.crop.rectangle")
""" 'person.crop.rectangle' symbol """

PERSON_CROP_RECTANGLE_FILL = Symbol("person.crop.rectangle.fill")
""" 'person.crop.rectangle.fill' symbol """

ARROW_UP_AND_PERSON_RECTANGLE_PORTRAIT = Symbol("arrow.up.and.person.rectangle.portrait")
""" 'arrow.up.and.person.rectangle.portrait' symbol """

ARROW_UP_AND_PERSON_RECTANGLE_TURN_RIGHT = Symbol("arrow.up.and.person.rectangle.turn.right")
""" 'arrow.up.and.person.rectangle.turn.right' symbol """

ARROW_UP_AND_PERSON_RECTANGLE_TURN_LEFT = Symbol("arrow.up.and.person.rectangle.turn.left")
""" 'arrow.up.and.person.rectangle.turn.left' symbol """

PHOTO = Symbol("photo")
""" 'photo' symbol """

PHOTO_FILL = Symbol("photo.fill")
""" 'photo.fill' symbol """

CHECKERBOARD_RECTANGLE = Symbol("checkerboard.rectangle")
""" 'checkerboard.rectangle' symbol """

CAMERA_METERING_CENTER_WEIGHTED_AVERAGE = Symbol("camera.metering.center.weighted.average")
""" 'camera.metering.center.weighted.average' symbol """

CAMERA_METERING_CENTER_WEIGHTED = Symbol("camera.metering.center.weighted")
""" 'camera.metering.center.weighted' symbol """

CAMERA_METERING_MATRIX = Symbol("camera.metering.matrix")
""" 'camera.metering.matrix' symbol """

CAMERA_METERING_MULTISPOT = Symbol("camera.metering.multispot")
""" 'camera.metering.multispot' symbol """

CAMERA_METERING_NONE = Symbol("camera.metering.none")
""" 'camera.metering.none' symbol """

CAMERA_METERING_PARTIAL = Symbol("camera.metering.partial")
""" 'camera.metering.partial' symbol """

CAMERA_METERING_SPOT = Symbol("camera.metering.spot")
""" 'camera.metering.spot' symbol """

CAMERA_METERING_UNKNOWN = Symbol("camera.metering.unknown")
""" 'camera.metering.unknown' symbol """

CAMERA_APERTURE = Symbol("camera.aperture")
""" 'camera.aperture' symbol """

RECTANGLE_DASHED = Symbol("rectangle.dashed")
""" 'rectangle.dashed' symbol """

RECTANGLE_DASHED_BADGE_RECORD = Symbol("rectangle.dashed.badge.record")
""" 'rectangle.dashed.badge.record' symbol """

RECTANGLE_BADGE_PLUS = Symbol("rectangle.badge.plus")
""" 'rectangle.badge.plus' symbol """

RECTANGLE_FILL_BADGE_PLUS = Symbol("rectangle.fill.badge.plus")
""" 'rectangle.fill.badge.plus' symbol """

RECTANGLE_BADGE_MINUS = Symbol("rectangle.badge.minus")
""" 'rectangle.badge.minus' symbol """

RECTANGLE_FILL_BADGE_MINUS = Symbol("rectangle.fill.badge.minus")
""" 'rectangle.fill.badge.minus' symbol """

RECTANGLE_BADGE_CHECKMARK = Symbol("rectangle.badge.checkmark")
""" 'rectangle.badge.checkmark' symbol """

RECTANGLE_FILL_BADGE_CHECKMARK = Symbol("rectangle.fill.badge.checkmark")
""" 'rectangle.fill.badge.checkmark' symbol """

RECTANGLE_BADGE_XMARK = Symbol("rectangle.badge.xmark")
""" 'rectangle.badge.xmark' symbol """

RECTANGLE_FILL_BADGE_XMARK = Symbol("rectangle.fill.badge.xmark")
""" 'rectangle.fill.badge.xmark' symbol """

SIDEBAR_LEFT = Symbol("sidebar.left")
""" 'sidebar.left' symbol """

SIDEBAR_RIGHT = Symbol("sidebar.right")
""" 'sidebar.right' symbol """

MACWINDOW = Symbol("macwindow")
""" 'macwindow' symbol """

MACWINDOW_BADGE_PLUS = Symbol("macwindow.badge.plus")
""" 'macwindow.badge.plus' symbol """

DOCK_RECTANGLE = Symbol("dock.rectangle")
""" 'dock.rectangle' symbol """

DOCK_ARROW_UP_RECTANGLE = Symbol("dock.arrow.up.rectangle")
""" 'dock.arrow.up.rectangle' symbol """

DOCK_ARROW_DOWN_RECTANGLE = Symbol("dock.arrow.down.rectangle")
""" 'dock.arrow.down.rectangle' symbol """

MENUBAR_RECTANGLE = Symbol("menubar.rectangle")
""" 'menubar.rectangle' symbol """

MENUBAR_DOCK_RECTANGLE = Symbol("menubar.dock.rectangle")
""" 'menubar.dock.rectangle' symbol """

MENUBAR_DOCK_RECTANGLE_BADGE_RECORD = Symbol("menubar.dock.rectangle.badge.record")
""" 'menubar.dock.rectangle.badge.record' symbol """

MENUBAR_ARROW_UP_RECTANGLE = Symbol("menubar.arrow.up.rectangle")
""" 'menubar.arrow.up.rectangle' symbol """

MENUBAR_ARROW_DOWN_RECTANGLE = Symbol("menubar.arrow.down.rectangle")
""" 'menubar.arrow.down.rectangle' symbol """

MACWINDOW_ON_RECTANGLE = Symbol("macwindow.on.rectangle")
""" 'macwindow.on.rectangle' symbol """

TEXT_AND_COMMAND_MACWINDOW = Symbol("text.and.command.macwindow")
""" 'text.and.command.macwindow' symbol """

KEYBOARD_MACWINDOW = Symbol("keyboard.macwindow")
""" 'keyboard.macwindow' symbol """

UIWINDOW_SPLIT_2X1 = Symbol("uiwindow.split.2x1")
""" 'uiwindow.split.2x1' symbol """

RECTANGLE_SPLIT_3X1 = Symbol("rectangle.split.3x1")
""" 'rectangle.split.3x1' symbol """

RECTANGLE_SPLIT_3X1_FILL = Symbol("rectangle.split.3x1.fill")
""" 'rectangle.split.3x1.fill' symbol """

SQUARE_SPLIT_2X1 = Symbol("square.split.2x1")
""" 'square.split.2x1' symbol """

SQUARE_SPLIT_2X1_FILL = Symbol("square.split.2x1.fill")
""" 'square.split.2x1.fill' symbol """

SQUARE_SPLIT_1X2 = Symbol("square.split.1x2")
""" 'square.split.1x2' symbol """

SQUARE_SPLIT_1X2_FILL = Symbol("square.split.1x2.fill")
""" 'square.split.1x2.fill' symbol """

SQUARE_SPLIT_2X2 = Symbol("square.split.2x2")
""" 'square.split.2x2' symbol """

SQUARE_SPLIT_2X2_FILL = Symbol("square.split.2x2.fill")
""" 'square.split.2x2.fill' symbol """

SQUARE_SPLIT_DIAGONAL_2X2 = Symbol("square.split.diagonal.2x2")
""" 'square.split.diagonal.2x2' symbol """

SQUARE_SPLIT_DIAGONAL_2X2_FILL = Symbol("square.split.diagonal.2x2.fill")
""" 'square.split.diagonal.2x2.fill' symbol """

SQUARE_SPLIT_DIAGONAL = Symbol("square.split.diagonal")
""" 'square.split.diagonal' symbol """

SQUARE_SPLIT_DIAGONAL_FILL = Symbol("square.split.diagonal.fill")
""" 'square.split.diagonal.fill' symbol """

MOSAIC = Symbol("mosaic")
""" 'mosaic' symbol """

MOSAIC_FILL = Symbol("mosaic.fill")
""" 'mosaic.fill' symbol """

SQUARES_BELOW_RECTANGLE = Symbol("squares.below.rectangle")
""" 'squares.below.rectangle' symbol """

RECTANGLE_SPLIT_3X3 = Symbol("rectangle.split.3x3")
""" 'rectangle.split.3x3' symbol """

RECTANGLE_SPLIT_3X3_FILL = Symbol("rectangle.split.3x3.fill")
""" 'rectangle.split.3x3.fill' symbol """

RECTANGLE_SPLIT_2X1 = Symbol("rectangle.split.2x1")
""" 'rectangle.split.2x1' symbol """

RECTANGLE_SPLIT_2X1_FILL = Symbol("rectangle.split.2x1.fill")
""" 'rectangle.split.2x1.fill' symbol """

RECTANGLE_SPLIT_1X2 = Symbol("rectangle.split.1x2")
""" 'rectangle.split.1x2' symbol """

RECTANGLE_SPLIT_1X2_FILL = Symbol("rectangle.split.1x2.fill")
""" 'rectangle.split.1x2.fill' symbol """

RECTANGLE_SPLIT_2X2 = Symbol("rectangle.split.2x2")
""" 'rectangle.split.2x2' symbol """

RECTANGLE_SPLIT_2X2_FILL = Symbol("rectangle.split.2x2.fill")
""" 'rectangle.split.2x2.fill' symbol """

TABLECELLS = Symbol("tablecells")
""" 'tablecells' symbol """

TABLECELLS_FILL = Symbol("tablecells.fill")
""" 'tablecells.fill' symbol """

TABLECELLS_BADGE_ELLIPSIS = Symbol("tablecells.badge.ellipsis")
""" 'tablecells.badge.ellipsis' symbol """

TABLECELLS_BADGE_ELLIPSIS_FILL = Symbol("tablecells.badge.ellipsis.fill")
""" 'tablecells.badge.ellipsis.fill' symbol """

RECTANGLE_ON_RECTANGLE = Symbol("rectangle.on.rectangle")
""" 'rectangle.on.rectangle' symbol """

RECTANGLE_FILL_ON_RECTANGLE_FILL = Symbol("rectangle.fill.on.rectangle.fill")
""" 'rectangle.fill.on.rectangle.fill' symbol """

RECTANGLE_FILL_ON_RECTANGLE_FILL_CIRCLE = Symbol("rectangle.fill.on.rectangle.fill.circle")
""" 'rectangle.fill.on.rectangle.fill.circle' symbol """

RECTANGLE_FILL_ON_RECTANGLE_FILL_CIRCLE_FILL = Symbol("rectangle.fill.on.rectangle.fill.circle.fill")
""" 'rectangle.fill.on.rectangle.fill.circle.fill' symbol """

RECTANGLE_ON_RECTANGLE_SLASH = Symbol("rectangle.on.rectangle.slash")
""" 'rectangle.on.rectangle.slash' symbol """

RECTANGLE_FILL_ON_RECTANGLE_FILL_SLASH_FILL = Symbol("rectangle.fill.on.rectangle.fill.slash.fill")
""" 'rectangle.fill.on.rectangle.fill.slash.fill' symbol """

PLUS_RECTANGLE_ON_RECTANGLE = Symbol("plus.rectangle.on.rectangle")
""" 'plus.rectangle.on.rectangle' symbol """

PLUS_RECTANGLE_FILL_ON_RECTANGLE_FILL = Symbol("plus.rectangle.fill.on.rectangle.fill")
""" 'plus.rectangle.fill.on.rectangle.fill' symbol """

PHOTO_ON_RECTANGLE = Symbol("photo.on.rectangle")
""" 'photo.on.rectangle' symbol """

PHOTO_FILL_ON_RECTANGLE_FILL = Symbol("photo.fill.on.rectangle.fill")
""" 'photo.fill.on.rectangle.fill' symbol """

RECTANGLE_ON_RECTANGLE_ANGLED = Symbol("rectangle.on.rectangle.angled")
""" 'rectangle.on.rectangle.angled' symbol """

RECTANGLE_FILL_ON_RECTANGLE_ANGLED_FILL = Symbol("rectangle.fill.on.rectangle.angled.fill")
""" 'rectangle.fill.on.rectangle.angled.fill' symbol """

PHOTO_ON_RECTANGLE_ANGLED = Symbol("photo.on.rectangle.angled")
""" 'photo.on.rectangle.angled' symbol """

RECTANGLE_STACK = Symbol("rectangle.stack")
""" 'rectangle.stack' symbol """

RECTANGLE_STACK_FILL = Symbol("rectangle.stack.fill")
""" 'rectangle.stack.fill' symbol """

RECTANGLE_STACK_BADGE_PLUS = Symbol("rectangle.stack.badge.plus")
""" 'rectangle.stack.badge.plus' symbol """

RECTANGLE_STACK_FILL_BADGE_PLUS = Symbol("rectangle.stack.fill.badge.plus")
""" 'rectangle.stack.fill.badge.plus' symbol """

RECTANGLE_STACK_BADGE_MINUS = Symbol("rectangle.stack.badge.minus")
""" 'rectangle.stack.badge.minus' symbol """

RECTANGLE_STACK_FILL_BADGE_MINUS = Symbol("rectangle.stack.fill.badge.minus")
""" 'rectangle.stack.fill.badge.minus' symbol """

RECTANGLE_STACK_BADGE_PERSON_CROP = Symbol("rectangle.stack.badge.person.crop")
""" 'rectangle.stack.badge.person.crop' symbol """

RECTANGLE_STACK_FILL_BADGE_PERSON_CROP = Symbol("rectangle.stack.fill.badge.person.crop")
""" 'rectangle.stack.fill.badge.person.crop' symbol """

R_SQUARE_ON_SQUARE = Symbol("r.square.on.square")
""" 'r.square.on.square' symbol """

R_SQUARE_FILL_ON_SQUARE_FILL = Symbol("r.square.fill.on.square.fill")
""" 'r.square.fill.on.square.fill' symbol """

J_SQUARE_ON_SQUARE = Symbol("j.square.on.square")
""" 'j.square.on.square' symbol """

J_SQUARE_FILL_ON_SQUARE_FILL = Symbol("j.square.fill.on.square.fill")
""" 'j.square.fill.on.square.fill' symbol """

H_SQUARE_ON_SQUARE = Symbol("h.square.on.square")
""" 'h.square.on.square' symbol """

H_SQUARE_FILL_ON_SQUARE_FILL = Symbol("h.square.fill.on.square.fill")
""" 'h.square.fill.on.square.fill' symbol """

SQUARE_ON_SQUARE = Symbol("square.on.square")
""" 'square.on.square' symbol """

SQUARE_FILL_ON_SQUARE_FILL = Symbol("square.fill.on.square.fill")
""" 'square.fill.on.square.fill' symbol """

SQUARE_ON_SQUARE_DASHED = Symbol("square.on.square.dashed")
""" 'square.on.square.dashed' symbol """

PLUS_SQUARE_ON_SQUARE = Symbol("plus.square.on.square")
""" 'plus.square.on.square' symbol """

PLUS_SQUARE_FILL_ON_SQUARE_FILL = Symbol("plus.square.fill.on.square.fill")
""" 'plus.square.fill.on.square.fill' symbol """

SQUARE_ON_CIRCLE = Symbol("square.on.circle")
""" 'square.on.circle' symbol """

SQUARE_FILL_ON_CIRCLE_FILL = Symbol("square.fill.on.circle.fill")
""" 'square.fill.on.circle.fill' symbol """

SQUARE_ON_SQUARE_SQUARESHAPE_CONTROLHANDLES = Symbol("square.on.square.squareshape.controlhandles")
""" 'square.on.square.squareshape.controlhandles' symbol """

SQUARESHAPE_CONTROLHANDLES_ON_SQUARESHAPE_CONTROLHANDLES = Symbol("squareshape.controlhandles.on.squareshape.controlhandles")
""" 'squareshape.controlhandles.on.squareshape.controlhandles' symbol """

SQUARE_STACK = Symbol("square.stack")
""" 'square.stack' symbol """

SQUARE_STACK_FILL = Symbol("square.stack.fill")
""" 'square.stack.fill' symbol """

PANO = Symbol("pano")
""" 'pano' symbol """

PANO_FILL = Symbol("pano.fill")
""" 'pano.fill' symbol """

SQUARE_AND_LINE_VERTICAL_AND_SQUARE = Symbol("square.and.line.vertical.and.square")
""" 'square.and.line.vertical.and.square' symbol """

SQUARE_FILL_AND_LINE_VERTICAL_SQUARE_FILL = Symbol("square.fill.and.line.vertical.square.fill")
""" 'square.fill.and.line.vertical.square.fill' symbol """

SQUARE_FILL_AND_LINE_VERTICAL_AND_SQUARE = Symbol("square.fill.and.line.vertical.and.square")
""" 'square.fill.and.line.vertical.and.square' symbol """

SQUARE_AND_LINE_VERTICAL_AND_SQUARE_FILL = Symbol("square.and.line.vertical.and.square.fill")
""" 'square.and.line.vertical.and.square.fill' symbol """

FLOWCHART = Symbol("flowchart")
""" 'flowchart' symbol """

FLOWCHART_FILL = Symbol("flowchart.fill")
""" 'flowchart.fill' symbol """

RECTANGLE_CONNECTED_TO_LINE_BELOW = Symbol("rectangle.connected.to.line.below")
""" 'rectangle.connected.to.line.below' symbol """

SHIELD = Symbol("shield")
""" 'shield' symbol """

SHIELD_FILL = Symbol("shield.fill")
""" 'shield.fill' symbol """

SHIELD_SLASH = Symbol("shield.slash")
""" 'shield.slash' symbol """

SHIELD_SLASH_FILL = Symbol("shield.slash.fill")
""" 'shield.slash.fill' symbol """

SHIELD_LEFTHALF_FILL = Symbol("shield.lefthalf.fill")
""" 'shield.lefthalf.fill' symbol """

SWITCH_2 = Symbol("switch.2")
""" 'switch.2' symbol """

POINT_TOPLEFT_DOWN_CURVEDTO_POINT_BOTTOMRIGHT_UP = Symbol("point.topleft.down.curvedto.point.bottomright.up")
""" 'point.topleft.down.curvedto.point.bottomright.up' symbol """

POINT_FILL_TOPLEFT_DOWN_CURVEDTO_POINT_FILL_BOTTOMRIGHT_UP = Symbol("point.fill.topleft.down.curvedto.point.fill.bottomright.up")
""" 'point.fill.topleft.down.curvedto.point.fill.bottomright.up' symbol """

SLIDER_HORIZONTAL_3 = Symbol("slider.horizontal.3")
""" 'slider.horizontal.3' symbol """

SLIDER_HORIZONTAL_BELOW_RECTANGLE = Symbol("slider.horizontal.below.rectangle")
""" 'slider.horizontal.below.rectangle' symbol """

SLIDER_VERTICAL_3 = Symbol("slider.vertical.3")
""" 'slider.vertical.3' symbol """

CUBE = Symbol("cube")
""" 'cube' symbol """

CUBE_FILL = Symbol("cube.fill")
""" 'cube.fill' symbol """

CUBE_TRANSPARENT = Symbol("cube.transparent")
""" 'cube.transparent' symbol """

SHIPPINGBOX = Symbol("shippingbox")
""" 'shippingbox' symbol """

SHIPPINGBOX_FILL = Symbol("shippingbox.fill")
""" 'shippingbox.fill' symbol """

ARKIT = Symbol("arkit")
""" 'arkit' symbol """

SQUARE_STACK_3D_DOWN_RIGHT = Symbol("square.stack.3d.down.right")
""" 'square.stack.3d.down.right' symbol """

SQUARE_STACK_3D_DOWN_RIGHT_FILL = Symbol("square.stack.3d.down.right.fill")
""" 'square.stack.3d.down.right.fill' symbol """

SQUARE_STACK_3D_UP = Symbol("square.stack.3d.up")
""" 'square.stack.3d.up' symbol """

SQUARE_STACK_3D_UP_FILL = Symbol("square.stack.3d.up.fill")
""" 'square.stack.3d.up.fill' symbol """

SQUARE_STACK_3D_UP_SLASH = Symbol("square.stack.3d.up.slash")
""" 'square.stack.3d.up.slash' symbol """

SQUARE_STACK_3D_UP_SLASH_FILL = Symbol("square.stack.3d.up.slash.fill")
""" 'square.stack.3d.up.slash.fill' symbol """

SQUARE_STACK_3D_UP_BADGE_A = Symbol("square.stack.3d.up.badge.a")
""" 'square.stack.3d.up.badge.a' symbol """

SQUARE_STACK_3D_UP_BADGE_A_FILL = Symbol("square.stack.3d.up.badge.a.fill")
""" 'square.stack.3d.up.badge.a.fill' symbol """

SQUARE_STACK_3D_DOWN_DOTTEDLINE = Symbol("square.stack.3d.down.dottedline")
""" 'square.stack.3d.down.dottedline' symbol """

LIVEPHOTO = Symbol("livephoto")
""" 'livephoto' symbol """

LIVEPHOTO_SLASH = Symbol("livephoto.slash")
""" 'livephoto.slash' symbol """

LIVEPHOTO_BADGE_A = Symbol("livephoto.badge.a")
""" 'livephoto.badge.a' symbol """

LIVEPHOTO_PLAY = Symbol("livephoto.play")
""" 'livephoto.play' symbol """

SCOPE = Symbol("scope")
""" 'scope' symbol """

HELM = Symbol("helm")
""" 'helm' symbol """

CLOCK = Symbol("clock")
""" 'clock' symbol """

CLOCK_FILL = Symbol("clock.fill")
""" 'clock.fill' symbol """

DESKCLOCK = Symbol("deskclock")
""" 'deskclock' symbol """

DESKCLOCK_FILL = Symbol("deskclock.fill")
""" 'deskclock.fill' symbol """

ALARM = Symbol("alarm")
""" 'alarm' symbol """

ALARM_FILL = Symbol("alarm.fill")
""" 'alarm.fill' symbol """

STOPWATCH = Symbol("stopwatch")
""" 'stopwatch' symbol """

STOPWATCH_FILL = Symbol("stopwatch.fill")
""" 'stopwatch.fill' symbol """

TIMER = Symbol("timer")
""" 'timer' symbol """

TIMER_SQUARE = Symbol("timer.square")
""" 'timer.square' symbol """

CLOCK_ARROW_CIRCLEPATH = Symbol("clock.arrow.circlepath")
""" 'clock.arrow.circlepath' symbol """

GAMECONTROLLER = Symbol("gamecontroller")
""" 'gamecontroller' symbol """

GAMECONTROLLER_FILL = Symbol("gamecontroller.fill")
""" 'gamecontroller.fill' symbol """

L_JOYSTICK = Symbol("l.joystick")
""" 'l.joystick' symbol """

L_JOYSTICK_FILL = Symbol("l.joystick.fill")
""" 'l.joystick.fill' symbol """

R_JOYSTICK = Symbol("r.joystick")
""" 'r.joystick' symbol """

R_JOYSTICK_FILL = Symbol("r.joystick.fill")
""" 'r.joystick.fill' symbol """

L_JOYSTICK_DOWN = Symbol("l.joystick.down")
""" 'l.joystick.down' symbol """

L_JOYSTICK_DOWN_FILL = Symbol("l.joystick.down.fill")
""" 'l.joystick.down.fill' symbol """

R_JOYSTICK_DOWN = Symbol("r.joystick.down")
""" 'r.joystick.down' symbol """

R_JOYSTICK_DOWN_FILL = Symbol("r.joystick.down.fill")
""" 'r.joystick.down.fill' symbol """

DPAD = Symbol("dpad")
""" 'dpad' symbol """

DPAD_FILL = Symbol("dpad.fill")
""" 'dpad.fill' symbol """

DPAD_LEFT_FILL = Symbol("dpad.left.fill")
""" 'dpad.left.fill' symbol """

DPAD_UP_FILL = Symbol("dpad.up.fill")
""" 'dpad.up.fill' symbol """

DPAD_RIGHT_FILL = Symbol("dpad.right.fill")
""" 'dpad.right.fill' symbol """

DPAD_DOWN_FILL = Symbol("dpad.down.fill")
""" 'dpad.down.fill' symbol """

CIRCLE_CIRCLE = Symbol("circle.circle")
""" 'circle.circle' symbol """

CIRCLE_CIRCLE_FILL = Symbol("circle.circle.fill")
""" 'circle.circle.fill' symbol """

SQUARE_CIRCLE = Symbol("square.circle")
""" 'square.circle' symbol """

SQUARE_CIRCLE_FILL = Symbol("square.circle.fill")
""" 'square.circle.fill' symbol """

TRIANGLE_CIRCLE = Symbol("triangle.circle")
""" 'triangle.circle' symbol """

TRIANGLE_CIRCLE_FILL = Symbol("triangle.circle.fill")
""" 'triangle.circle.fill' symbol """

RECTANGLE_ROUNDEDTOP = Symbol("rectangle.roundedtop")
""" 'rectangle.roundedtop' symbol """

RECTANGLE_ROUNDEDTOP_FILL = Symbol("rectangle.roundedtop.fill")
""" 'rectangle.roundedtop.fill' symbol """

RECTANGLE_ROUNDEDBOTTOM = Symbol("rectangle.roundedbottom")
""" 'rectangle.roundedbottom' symbol """

RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("rectangle.roundedbottom.fill")
""" 'rectangle.roundedbottom.fill' symbol """

L_RECTANGLE_ROUNDEDBOTTOM = Symbol("l.rectangle.roundedbottom")
""" 'l.rectangle.roundedbottom' symbol """

L_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("l.rectangle.roundedbottom.fill")
""" 'l.rectangle.roundedbottom.fill' symbol """

L1_RECTANGLE_ROUNDEDBOTTOM = Symbol("l1.rectangle.roundedbottom")
""" 'l1.rectangle.roundedbottom' symbol """

L1_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("l1.rectangle.roundedbottom.fill")
""" 'l1.rectangle.roundedbottom.fill' symbol """

L2_RECTANGLE_ROUNDEDTOP = Symbol("l2.rectangle.roundedtop")
""" 'l2.rectangle.roundedtop' symbol """

L2_RECTANGLE_ROUNDEDTOP_FILL = Symbol("l2.rectangle.roundedtop.fill")
""" 'l2.rectangle.roundedtop.fill' symbol """

R_RECTANGLE_ROUNDEDBOTTOM = Symbol("r.rectangle.roundedbottom")
""" 'r.rectangle.roundedbottom' symbol """

R_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("r.rectangle.roundedbottom.fill")
""" 'r.rectangle.roundedbottom.fill' symbol """

R1_RECTANGLE_ROUNDEDBOTTOM = Symbol("r1.rectangle.roundedbottom")
""" 'r1.rectangle.roundedbottom' symbol """

R1_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("r1.rectangle.roundedbottom.fill")
""" 'r1.rectangle.roundedbottom.fill' symbol """

R2_RECTANGLE_ROUNDEDTOP = Symbol("r2.rectangle.roundedtop")
""" 'r2.rectangle.roundedtop' symbol """

R2_RECTANGLE_ROUNDEDTOP_FILL = Symbol("r2.rectangle.roundedtop.fill")
""" 'r2.rectangle.roundedtop.fill' symbol """

LB_RECTANGLE_ROUNDEDBOTTOM = Symbol("lb.rectangle.roundedbottom")
""" 'lb.rectangle.roundedbottom' symbol """

LB_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("lb.rectangle.roundedbottom.fill")
""" 'lb.rectangle.roundedbottom.fill' symbol """

RB_RECTANGLE_ROUNDEDBOTTOM = Symbol("rb.rectangle.roundedbottom")
""" 'rb.rectangle.roundedbottom' symbol """

RB_RECTANGLE_ROUNDEDBOTTOM_FILL = Symbol("rb.rectangle.roundedbottom.fill")
""" 'rb.rectangle.roundedbottom.fill' symbol """

LT_RECTANGLE_ROUNDEDTOP = Symbol("lt.rectangle.roundedtop")
""" 'lt.rectangle.roundedtop' symbol """

LT_RECTANGLE_ROUNDEDTOP_FILL = Symbol("lt.rectangle.roundedtop.fill")
""" 'lt.rectangle.roundedtop.fill' symbol """

RT_RECTANGLE_ROUNDEDTOP = Symbol("rt.rectangle.roundedtop")
""" 'rt.rectangle.roundedtop' symbol """

RT_RECTANGLE_ROUNDEDTOP_FILL = Symbol("rt.rectangle.roundedtop.fill")
""" 'rt.rectangle.roundedtop.fill' symbol """

ZL_RECTANGLE_ROUNDEDTOP = Symbol("zl.rectangle.roundedtop")
""" 'zl.rectangle.roundedtop' symbol """

ZL_RECTANGLE_ROUNDEDTOP_FILL = Symbol("zl.rectangle.roundedtop.fill")
""" 'zl.rectangle.roundedtop.fill' symbol """

ZR_RECTANGLE_ROUNDEDTOP = Symbol("zr.rectangle.roundedtop")
""" 'zr.rectangle.roundedtop' symbol """

ZR_RECTANGLE_ROUNDEDTOP_FILL = Symbol("zr.rectangle.roundedtop.fill")
""" 'zr.rectangle.roundedtop.fill' symbol """

PAINTPALETTE = Symbol("paintpalette")
""" 'paintpalette' symbol """

PAINTPALETTE_FILL = Symbol("paintpalette.fill")
""" 'paintpalette.fill' symbol """

FIGURE_WALK = Symbol("figure.walk")
""" 'figure.walk' symbol """

FIGURE_WALK_CIRCLE = Symbol("figure.walk.circle")
""" 'figure.walk.circle' symbol """

FIGURE_WALK_CIRCLE_FILL = Symbol("figure.walk.circle.fill")
""" 'figure.walk.circle.fill' symbol """

FIGURE_WALK_DIAMOND = Symbol("figure.walk.diamond")
""" 'figure.walk.diamond' symbol """

FIGURE_WALK_DIAMOND_FILL = Symbol("figure.walk.diamond.fill")
""" 'figure.walk.diamond.fill' symbol """

FIGURE_WAVE = Symbol("figure.wave")
""" 'figure.wave' symbol """

FIGURE_WAVE_CIRCLE = Symbol("figure.wave.circle")
""" 'figure.wave.circle' symbol """

FIGURE_WAVE_CIRCLE_FILL = Symbol("figure.wave.circle.fill")
""" 'figure.wave.circle.fill' symbol """

EAR = Symbol("ear")
""" 'ear' symbol """

EAR_BADGE_CHECKMARK = Symbol("ear.badge.checkmark")
""" 'ear.badge.checkmark' symbol """

EAR_TRIANGLEBADGE_EXCLAMATIONMARK = Symbol("ear.trianglebadge.exclamationmark")
""" 'ear.trianglebadge.exclamationmark' symbol """

EAR_FILL = Symbol("ear.fill")
""" 'ear.fill' symbol """

HEARINGAID_EAR = Symbol("hearingaid.ear")
""" 'hearingaid.ear' symbol """

HAND_RAISED = Symbol("hand.raised")
""" 'hand.raised' symbol """

HAND_RAISED_FILL = Symbol("hand.raised.fill")
""" 'hand.raised.fill' symbol """

HAND_RAISED_SLASH = Symbol("hand.raised.slash")
""" 'hand.raised.slash' symbol """

HAND_RAISED_SLASH_FILL = Symbol("hand.raised.slash.fill")
""" 'hand.raised.slash.fill' symbol """

HAND_THUMBSUP = Symbol("hand.thumbsup")
""" 'hand.thumbsup' symbol """

HAND_THUMBSUP_FILL = Symbol("hand.thumbsup.fill")
""" 'hand.thumbsup.fill' symbol """

HAND_THUMBSDOWN = Symbol("hand.thumbsdown")
""" 'hand.thumbsdown' symbol """

HAND_THUMBSDOWN_FILL = Symbol("hand.thumbsdown.fill")
""" 'hand.thumbsdown.fill' symbol """

HAND_POINT_UP_LEFT = Symbol("hand.point.up.left")
""" 'hand.point.up.left' symbol """

HAND_POINT_UP_LEFT_FILL = Symbol("hand.point.up.left.fill")
""" 'hand.point.up.left.fill' symbol """

HAND_DRAW = Symbol("hand.draw")
""" 'hand.draw' symbol """

HAND_DRAW_FILL = Symbol("hand.draw.fill")
""" 'hand.draw.fill' symbol """

HAND_TAP = Symbol("hand.tap")
""" 'hand.tap' symbol """

HAND_TAP_FILL = Symbol("hand.tap.fill")
""" 'hand.tap.fill' symbol """

HAND_POINT_LEFT = Symbol("hand.point.left")
""" 'hand.point.left' symbol """

HAND_POINT_LEFT_FILL = Symbol("hand.point.left.fill")
""" 'hand.point.left.fill' symbol """

HAND_POINT_RIGHT = Symbol("hand.point.right")
""" 'hand.point.right' symbol """

HAND_POINT_RIGHT_FILL = Symbol("hand.point.right.fill")
""" 'hand.point.right.fill' symbol """

HAND_POINT_UP = Symbol("hand.point.up")
""" 'hand.point.up' symbol """

HAND_POINT_UP_FILL = Symbol("hand.point.up.fill")
""" 'hand.point.up.fill' symbol """

HAND_POINT_UP_BRAILLE = Symbol("hand.point.up.braille")
""" 'hand.point.up.braille' symbol """

HAND_POINT_UP_BRAILLE_FILL = Symbol("hand.point.up.braille.fill")
""" 'hand.point.up.braille.fill' symbol """

HAND_POINT_DOWN = Symbol("hand.point.down")
""" 'hand.point.down' symbol """

HAND_POINT_DOWN_FILL = Symbol("hand.point.down.fill")
""" 'hand.point.down.fill' symbol """

HAND_WAVE = Symbol("hand.wave")
""" 'hand.wave' symbol """

HAND_WAVE_FILL = Symbol("hand.wave.fill")
""" 'hand.wave.fill' symbol """

RECTANGLE_COMPRESS_VERTICAL = Symbol("rectangle.compress.vertical")
""" 'rectangle.compress.vertical' symbol """

RECTANGLE_EXPAND_VERTICAL = Symbol("rectangle.expand.vertical")
""" 'rectangle.expand.vertical' symbol """

RECTANGLE_AND_ARROW_UP_RIGHT_AND_ARROW_DOWN_LEFT = Symbol("rectangle.and.arrow.up.right.and.arrow.down.left")
""" 'rectangle.and.arrow.up.right.and.arrow.down.left' symbol """

RECTANGLE_AND_ARROW_UP_RIGHT_AND_ARROW_DOWN_LEFT_SLASH = Symbol("rectangle.and.arrow.up.right.and.arrow.down.left.slash")
""" 'rectangle.and.arrow.up.right.and.arrow.down.left.slash' symbol """

SQUARE_2_STACK_3D = Symbol("square.2.stack.3d")
""" 'square.2.stack.3d' symbol """

SQUARE_2_STACK_3D_TOP_FILL = Symbol("square.2.stack.3d.top.fill")
""" 'square.2.stack.3d.top.fill' symbol """

SQUARE_2_STACK_3D_BOTTOM_FILL = Symbol("square.2.stack.3d.bottom.fill")
""" 'square.2.stack.3d.bottom.fill' symbol """

SQUARE_3_STACK_3D = Symbol("square.3.stack.3d")
""" 'square.3.stack.3d' symbol """

SQUARE_3_STACK_3D_TOP_FILL = Symbol("square.3.stack.3d.top.fill")
""" 'square.3.stack.3d.top.fill' symbol """

SQUARE_3_STACK_3D_MIDDLE_FILL = Symbol("square.3.stack.3d.middle.fill")
""" 'square.3.stack.3d.middle.fill' symbol """

SQUARE_3_STACK_3D_BOTTOM_FILL = Symbol("square.3.stack.3d.bottom.fill")
""" 'square.3.stack.3d.bottom.fill' symbol """

CYLINDER_SPLIT_1X2 = Symbol("cylinder.split.1x2")
""" 'cylinder.split.1x2' symbol """

CYLINDER_SPLIT_1X2_FILL = Symbol("cylinder.split.1x2.fill")
""" 'cylinder.split.1x2.fill' symbol """

CHART_BAR = Symbol("chart.bar")
""" 'chart.bar' symbol """

CHART_BAR_FILL = Symbol("chart.bar.fill")
""" 'chart.bar.fill' symbol """

CHART_PIE = Symbol("chart.pie")
""" 'chart.pie' symbol """

CHART_PIE_FILL = Symbol("chart.pie.fill")
""" 'chart.pie.fill' symbol """

CHART_BAR_XAXIS = Symbol("chart.bar.xaxis")
""" 'chart.bar.xaxis' symbol """

DOT_SQUARESHAPE_SPLIT_2X2 = Symbol("dot.squareshape.split.2x2")
""" 'dot.squareshape.split.2x2' symbol """

SQUARESHAPE_SPLIT_2X2 = Symbol("squareshape.split.2x2")
""" 'squareshape.split.2x2' symbol """

SQUARESHAPE_SPLIT_3X3 = Symbol("squareshape.split.3x3")
""" 'squareshape.split.3x3' symbol """

BURST = Symbol("burst")
""" 'burst' symbol """

BURST_FILL = Symbol("burst.fill")
""" 'burst.fill' symbol """

WAVEFORM_PATH_ECG = Symbol("waveform.path.ecg")
""" 'waveform.path.ecg' symbol """

WAVEFORM_PATH_ECG_RECTANGLE = Symbol("waveform.path.ecg.rectangle")
""" 'waveform.path.ecg.rectangle' symbol """

WAVEFORM_PATH_ECG_RECTANGLE_FILL = Symbol("waveform.path.ecg.rectangle.fill")
""" 'waveform.path.ecg.rectangle.fill' symbol """

WAVEFORM_PATH = Symbol("waveform.path")
""" 'waveform.path' symbol """

WAVEFORM_PATH_BADGE_PLUS = Symbol("waveform.path.badge.plus")
""" 'waveform.path.badge.plus' symbol """

WAVEFORM_PATH_BADGE_MINUS = Symbol("waveform.path.badge.minus")
""" 'waveform.path.badge.minus' symbol """

WAVEFORM = Symbol("waveform")
""" 'waveform' symbol """

WAVEFORM_CIRCLE = Symbol("waveform.circle")
""" 'waveform.circle' symbol """

WAVEFORM_CIRCLE_FILL = Symbol("waveform.circle.fill")
""" 'waveform.circle.fill' symbol """

STAROFLIFE = Symbol("staroflife")
""" 'staroflife' symbol """

STAROFLIFE_FILL = Symbol("staroflife.fill")
""" 'staroflife.fill' symbol """

STAROFLIFE_CIRCLE = Symbol("staroflife.circle")
""" 'staroflife.circle' symbol """

STAROFLIFE_CIRCLE_FILL = Symbol("staroflife.circle.fill")
""" 'staroflife.circle.fill' symbol """

SIMCARD = Symbol("simcard")
""" 'simcard' symbol """

SIMCARD_FILL = Symbol("simcard.fill")
""" 'simcard.fill' symbol """

SIMCARD_2 = Symbol("simcard.2")
""" 'simcard.2' symbol """

SIMCARD_2_FILL = Symbol("simcard.2.fill")
""" 'simcard.2.fill' symbol """

SDCARD = Symbol("sdcard")
""" 'sdcard' symbol """

SDCARD_FILL = Symbol("sdcard.fill")
""" 'sdcard.fill' symbol """

TOUCHID = Symbol("touchid")
""" 'touchid' symbol """

BONJOUR = Symbol("bonjour")
""" 'bonjour' symbol """

ATOM = Symbol("atom")
""" 'atom' symbol """

SCALEMASS = Symbol("scalemass")
""" 'scalemass' symbol """

SCALEMASS_FILL = Symbol("scalemass.fill")
""" 'scalemass.fill' symbol """

HEADPHONES = Symbol("headphones")
""" 'headphones' symbol """

HEADPHONES_CIRCLE = Symbol("headphones.circle")
""" 'headphones.circle' symbol """

HEADPHONES_CIRCLE_FILL = Symbol("headphones.circle.fill")
""" 'headphones.circle.fill' symbol """

GIFT = Symbol("gift")
""" 'gift' symbol """

GIFT_FILL = Symbol("gift.fill")
""" 'gift.fill' symbol """

GIFT_CIRCLE = Symbol("gift.circle")
""" 'gift.circle' symbol """

GIFT_CIRCLE_FILL = Symbol("gift.circle.fill")
""" 'gift.circle.fill' symbol """

PLUS_APP = Symbol("plus.app")
""" 'plus.app' symbol """

PLUS_APP_FILL = Symbol("plus.app.fill")
""" 'plus.app.fill' symbol """

ARROW_UP_RIGHT_APP = Symbol("arrow.up.right.app")
""" 'arrow.up.right.app' symbol """

ARROW_UP_RIGHT_APP_FILL = Symbol("arrow.up.right.app.fill")
""" 'arrow.up.right.app.fill' symbol """

ARROW_DOWN_APP = Symbol("arrow.down.app")
""" 'arrow.down.app' symbol """

ARROW_DOWN_APP_FILL = Symbol("arrow.down.app.fill")
""" 'arrow.down.app.fill' symbol """

APP_BADGE = Symbol("app.badge")
""" 'app.badge' symbol """

APP_BADGE_FILL = Symbol("app.badge.fill")
""" 'app.badge.fill' symbol """

APP_GIFT = Symbol("app.gift")
""" 'app.gift' symbol """

APP_GIFT_FILL = Symbol("app.gift.fill")
""" 'app.gift.fill' symbol """

AIRPLANE = Symbol("airplane")
""" 'airplane' symbol """

AIRPLANE_CIRCLE = Symbol("airplane.circle")
""" 'airplane.circle' symbol """

AIRPLANE_CIRCLE_FILL = Symbol("airplane.circle.fill")
""" 'airplane.circle.fill' symbol """

STUDENTDESK = Symbol("studentdesk")
""" 'studentdesk' symbol """

HOURGLASS = Symbol("hourglass")
""" 'hourglass' symbol """

HOURGLASS_BADGE_PLUS = Symbol("hourglass.badge.plus")
""" 'hourglass.badge.plus' symbol """

HOURGLASS_BOTTOMHALF_FILL = Symbol("hourglass.bottomhalf.fill")
""" 'hourglass.bottomhalf.fill' symbol """

HOURGLASS_TOPHALF_FILL = Symbol("hourglass.tophalf.fill")
""" 'hourglass.tophalf.fill' symbol """

BANKNOTE = Symbol("banknote")
""" 'banknote' symbol """

BANKNOTE_FILL = Symbol("banknote.fill")
""" 'banknote.fill' symbol """

PARAGRAPHSIGN = Symbol("paragraphsign")
""" 'paragraphsign' symbol """

PURCHASED = Symbol("purchased")
""" 'purchased' symbol """

PURCHASED_CIRCLE = Symbol("purchased.circle")
""" 'purchased.circle' symbol """

PURCHASED_CIRCLE_FILL = Symbol("purchased.circle.fill")
""" 'purchased.circle.fill' symbol """

PERSPECTIVE = Symbol("perspective")
""" 'perspective' symbol """

ASPECTRATIO = Symbol("aspectratio")
""" 'aspectratio' symbol """

ASPECTRATIO_FILL = Symbol("aspectratio.fill")
""" 'aspectratio.fill' symbol """

CAMERA_FILTERS = Symbol("camera.filters")
""" 'camera.filters' symbol """

SKEW = Symbol("skew")
""" 'skew' symbol """

ARROW_LEFT_AND_RIGHT_RIGHTTRIANGLE_LEFT_RIGHTTRIANGLE_RIGHT = Symbol("arrow.left.and.right.righttriangle.left.righttriangle.right")
""" 'arrow.left.and.right.righttriangle.left.righttriangle.right' symbol """

ARROW_LEFT_AND_RIGHT_RIGHTTRIANGLE_LEFT_RIGHTTRIANGLE_RIGHT_FILL = Symbol("arrow.left.and.right.righttriangle.left.righttriangle.right.fill")
""" 'arrow.left.and.right.righttriangle.left.righttriangle.right.fill' symbol """

ARROW_UP_AND_DOWN_RIGHTTRIANGLE_UP_RIGHTTRIANGLE_DOWN = Symbol("arrow.up.and.down.righttriangle.up.righttriangle.down")
""" 'arrow.up.and.down.righttriangle.up.righttriangle.down' symbol """

ARROW_UP_AND_DOWN_RIGHTTRIANGLE_UP_FILL_RIGHTTRIANGLE_DOWN_FILL = Symbol("arrow.up.and.down.righttriangle.up.fill.righttriangle.down.fill")
""" 'arrow.up.and.down.righttriangle.up.fill.righttriangle.down.fill' symbol """

ARROWTRIANGLE_LEFT_AND_LINE_VERTICAL_AND_ARROWTRIANGLE_RIGHT = Symbol("arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
""" 'arrowtriangle.left.and.line.vertical.and.arrowtriangle.right' symbol """

ARROWTRIANGLE_LEFT_FILL_AND_LINE_VERTICAL_AND_ARROWTRIANGLE_RIGHT_FILL = Symbol("arrowtriangle.left.fill.and.line.vertical.and.arrowtriangle.right.fill")
""" 'arrowtriangle.left.fill.and.line.vertical.and.arrowtriangle.right.fill' symbol """

ARROWTRIANGLE_RIGHT_AND_LINE_VERTICAL_AND_ARROWTRIANGLE_LEFT = Symbol("arrowtriangle.right.and.line.vertical.and.arrowtriangle.left")
""" 'arrowtriangle.right.and.line.vertical.and.arrowtriangle.left' symbol """

ARROWTRIANGLE_RIGHT_FILL_AND_LINE_VERTICAL_AND_ARROWTRIANGLE_LEFT_FILL = Symbol("arrowtriangle.right.fill.and.line.vertical.and.arrowtriangle.left.fill")
""" 'arrowtriangle.right.fill.and.line.vertical.and.arrowtriangle.left.fill' symbol """

GRID = Symbol("grid")
""" 'grid' symbol """

GRID_CIRCLE = Symbol("grid.circle")
""" 'grid.circle' symbol """

GRID_CIRCLE_FILL = Symbol("grid.circle.fill")
""" 'grid.circle.fill' symbol """

BURN = Symbol("burn")
""" 'burn' symbol """

LIFEPRESERVER = Symbol("lifepreserver")
""" 'lifepreserver' symbol """

LIFEPRESERVER_FILL = Symbol("lifepreserver.fill")
""" 'lifepreserver.fill' symbol """

RECORDINGTAPE = Symbol("recordingtape")
""" 'recordingtape' symbol """

EYEGLASSES = Symbol("eyeglasses")
""" 'eyeglasses' symbol """

BINOCULARS = Symbol("binoculars")
""" 'binoculars' symbol """

BINOCULARS_FILL = Symbol("binoculars.fill")
""" 'binoculars.fill' symbol """

BATTERY_100 = Symbol("battery.100")
""" 'battery.100' symbol """

BATTERY_25 = Symbol("battery.25")
""" 'battery.25' symbol """

BATTERY_0 = Symbol("battery.0")
""" 'battery.0' symbol """

BATTERY_100_BOLT = Symbol("battery.100.bolt")
""" 'battery.100.bolt' symbol """

MINUS_PLUS_BATTERYBLOCK = Symbol("minus.plus.batteryblock")
""" 'minus.plus.batteryblock' symbol """

MINUS_PLUS_BATTERYBLOCK_FILL = Symbol("minus.plus.batteryblock.fill")
""" 'minus.plus.batteryblock.fill' symbol """

BOLT_FILL_BATTERYBLOCK = Symbol("bolt.fill.batteryblock")
""" 'bolt.fill.batteryblock' symbol """

BOLT_FILL_BATTERYBLOCK_FILL = Symbol("bolt.fill.batteryblock.fill")
""" 'bolt.fill.batteryblock.fill' symbol """

LIGHTBULB = Symbol("lightbulb")
""" 'lightbulb' symbol """

LIGHTBULB_FILL = Symbol("lightbulb.fill")
""" 'lightbulb.fill' symbol """

LIGHTBULB_SLASH = Symbol("lightbulb.slash")
""" 'lightbulb.slash' symbol """

LIGHTBULB_SLASH_FILL = Symbol("lightbulb.slash.fill")
""" 'lightbulb.slash.fill' symbol """

FIBERCHANNEL = Symbol("fiberchannel")
""" 'fiberchannel' symbol """

SQUARE_FILL_TEXT_GRID_1X2 = Symbol("square.fill.text.grid.1x2")
""" 'square.fill.text.grid.1x2' symbol """

LIST_DASH = Symbol("list.dash")
""" 'list.dash' symbol """

LIST_BULLET = Symbol("list.bullet")
""" 'list.bullet' symbol """

LIST_TRIANGLE = Symbol("list.triangle")
""" 'list.triangle' symbol """

LIST_BULLET_INDENT = Symbol("list.bullet.indent")
""" 'list.bullet.indent' symbol """

LIST_NUMBER = Symbol("list.number")
""" 'list.number' symbol """

LIST_STAR = Symbol("list.star")
""" 'list.star' symbol """

INCREASE_INDENT = Symbol("increase.indent")
""" 'increase.indent' symbol """

DECREASE_INDENT = Symbol("decrease.indent")
""" 'decrease.indent' symbol """

DECREASE_QUOTELEVEL = Symbol("decrease.quotelevel")
""" 'decrease.quotelevel' symbol """

INCREASE_QUOTELEVEL = Symbol("increase.quotelevel")
""" 'increase.quotelevel' symbol """

LIST_BULLET_BELOW_RECTANGLE = Symbol("list.bullet.below.rectangle")
""" 'list.bullet.below.rectangle' symbol """

TEXT_BADGE_PLUS = Symbol("text.badge.plus")
""" 'text.badge.plus' symbol """

TEXT_BADGE_MINUS = Symbol("text.badge.minus")
""" 'text.badge.minus' symbol """

TEXT_BADGE_CHECKMARK = Symbol("text.badge.checkmark")
""" 'text.badge.checkmark' symbol """

TEXT_BADGE_XMARK = Symbol("text.badge.xmark")
""" 'text.badge.xmark' symbol """

TEXT_BADGE_STAR = Symbol("text.badge.star")
""" 'text.badge.star' symbol """

TEXT_INSERT = Symbol("text.insert")
""" 'text.insert' symbol """

TEXT_APPEND = Symbol("text.append")
""" 'text.append' symbol """

TEXT_QUOTE = Symbol("text.quote")
""" 'text.quote' symbol """

TEXT_ALIGNLEFT = Symbol("text.alignleft")
""" 'text.alignleft' symbol """

TEXT_ALIGNCENTER = Symbol("text.aligncenter")
""" 'text.aligncenter' symbol """

TEXT_ALIGNRIGHT = Symbol("text.alignright")
""" 'text.alignright' symbol """

TEXT_JUSTIFY = Symbol("text.justify")
""" 'text.justify' symbol """

TEXT_JUSTIFYLEFT = Symbol("text.justifyleft")
""" 'text.justifyleft' symbol """

TEXT_JUSTIFYRIGHT = Symbol("text.justifyright")
""" 'text.justifyright' symbol """

TEXT_REDACTION = Symbol("text.redaction")
""" 'text.redaction' symbol """

LIST_AND_FILM = Symbol("list.and.film")
""" 'list.and.film' symbol """

LINE_HORIZONTAL_3 = Symbol("line.horizontal.3")
""" 'line.horizontal.3' symbol """

LINE_HORIZONTAL_3_DECREASE = Symbol("line.horizontal.3.decrease")
""" 'line.horizontal.3.decrease' symbol """

LINE_HORIZONTAL_3_DECREASE_CIRCLE = Symbol("line.horizontal.3.decrease.circle")
""" 'line.horizontal.3.decrease.circle' symbol """

LINE_HORIZONTAL_3_DECREASE_CIRCLE_FILL = Symbol("line.horizontal.3.decrease.circle.fill")
""" 'line.horizontal.3.decrease.circle.fill' symbol """

LINE_HORIZONTAL_3_CIRCLE = Symbol("line.horizontal.3.circle")
""" 'line.horizontal.3.circle' symbol """

LINE_HORIZONTAL_3_CIRCLE_FILL = Symbol("line.horizontal.3.circle.fill")
""" 'line.horizontal.3.circle.fill' symbol """

LINE_HORIZONTAL_2_DECREASE_CIRCLE = Symbol("line.horizontal.2.decrease.circle")
""" 'line.horizontal.2.decrease.circle' symbol """

LINE_HORIZONTAL_2_DECREASE_CIRCLE_FILL = Symbol("line.horizontal.2.decrease.circle.fill")
""" 'line.horizontal.2.decrease.circle.fill' symbol """

A = Symbol("a")
""" 'a' symbol """

ABC = Symbol("abc")
""" 'abc' symbol """

TEXTFORMAT_ALT = Symbol("textformat.alt")
""" 'textformat.alt' symbol """

TEXTFORMAT = Symbol("textformat")
""" 'textformat' symbol """

TEXTFORMAT_SIZE = Symbol("textformat.size")
""" 'textformat.size' symbol """

TEXTFORMAT_SUBSCRIPT = Symbol("textformat.subscript")
""" 'textformat.subscript' symbol """

TEXTFORMAT_SUPERSCRIPT = Symbol("textformat.superscript")
""" 'textformat.superscript' symbol """

BOLD = Symbol("bold")
""" 'bold' symbol """

ITALIC = Symbol("italic")
""" 'italic' symbol """

UNDERLINE = Symbol("underline")
""" 'underline' symbol """

STRIKETHROUGH = Symbol("strikethrough")
""" 'strikethrough' symbol """

SHADOW = Symbol("shadow")
""" 'shadow' symbol """

BOLD_ITALIC_UNDERLINE = Symbol("bold.italic.underline")
""" 'bold.italic.underline' symbol """

BOLD_UNDERLINE = Symbol("bold.underline")
""" 'bold.underline' symbol """

VIEW_2D = Symbol("view.2d")
""" 'view.2d' symbol """

VIEW_3D = Symbol("view.3d")
""" 'view.3d' symbol """

TEXT_CURSOR = Symbol("text.cursor")
""" 'text.cursor' symbol """

FX = Symbol("fx")
""" 'fx' symbol """

F_CURSIVE = Symbol("f.cursive")
""" 'f.cursive' symbol """

F_CURSIVE_CIRCLE = Symbol("f.cursive.circle")
""" 'f.cursive.circle' symbol """

F_CURSIVE_CIRCLE_FILL = Symbol("f.cursive.circle.fill")
""" 'f.cursive.circle.fill' symbol """

K = Symbol("k")
""" 'k' symbol """

SUM = Symbol("sum")
""" 'sum' symbol """

PERCENT = Symbol("percent")
""" 'percent' symbol """

FUNCTION = Symbol("function")
""" 'function' symbol """

TEXTFORMAT_ABC = Symbol("textformat.abc")
""" 'textformat.abc' symbol """

TEXTFORMAT_ABC_DOTTEDUNDERLINE = Symbol("textformat.abc.dottedunderline")
""" 'textformat.abc.dottedunderline' symbol """

FN = Symbol("fn")
""" 'fn' symbol """

TEXTFORMAT_123 = Symbol("textformat.123")
""" 'textformat.123' symbol """

TEXTBOX = Symbol("textbox")
""" 'textbox' symbol """

A_MAGNIFY = Symbol("a.magnify")
""" 'a.magnify' symbol """

INFO = Symbol("info")
""" 'info' symbol """

INFO_CIRCLE = Symbol("info.circle")
""" 'info.circle' symbol """

INFO_CIRCLE_FILL = Symbol("info.circle.fill")
""" 'info.circle.fill' symbol """

AT = Symbol("at")
""" 'at' symbol """

AT_CIRCLE = Symbol("at.circle")
""" 'at.circle' symbol """

AT_CIRCLE_FILL = Symbol("at.circle.fill")
""" 'at.circle.fill' symbol """

AT_BADGE_PLUS = Symbol("at.badge.plus")
""" 'at.badge.plus' symbol """

AT_BADGE_MINUS = Symbol("at.badge.minus")
""" 'at.badge.minus' symbol """

QUESTIONMARK = Symbol("questionmark")
""" 'questionmark' symbol """

QUESTIONMARK_CIRCLE = Symbol("questionmark.circle")
""" 'questionmark.circle' symbol """

QUESTIONMARK_CIRCLE_FILL = Symbol("questionmark.circle.fill")
""" 'questionmark.circle.fill' symbol """

QUESTIONMARK_SQUARE = Symbol("questionmark.square")
""" 'questionmark.square' symbol """

QUESTIONMARK_SQUARE_FILL = Symbol("questionmark.square.fill")
""" 'questionmark.square.fill' symbol """

QUESTIONMARK_DIAMOND = Symbol("questionmark.diamond")
""" 'questionmark.diamond' symbol """

QUESTIONMARK_DIAMOND_FILL = Symbol("questionmark.diamond.fill")
""" 'questionmark.diamond.fill' symbol """

EXCLAMATIONMARK = Symbol("exclamationmark")
""" 'exclamationmark' symbol """

EXCLAMATIONMARK_2 = Symbol("exclamationmark.2")
""" 'exclamationmark.2' symbol """

EXCLAMATIONMARK_3 = Symbol("exclamationmark.3")
""" 'exclamationmark.3' symbol """

EXCLAMATIONMARK_CIRCLE = Symbol("exclamationmark.circle")
""" 'exclamationmark.circle' symbol """

EXCLAMATIONMARK_CIRCLE_FILL = Symbol("exclamationmark.circle.fill")
""" 'exclamationmark.circle.fill' symbol """

EXCLAMATIONMARK_SQUARE = Symbol("exclamationmark.square")
""" 'exclamationmark.square' symbol """

EXCLAMATIONMARK_SQUARE_FILL = Symbol("exclamationmark.square.fill")
""" 'exclamationmark.square.fill' symbol """

EXCLAMATIONMARK_OCTAGON = Symbol("exclamationmark.octagon")
""" 'exclamationmark.octagon' symbol """

EXCLAMATIONMARK_OCTAGON_FILL = Symbol("exclamationmark.octagon.fill")
""" 'exclamationmark.octagon.fill' symbol """

EXCLAMATIONMARK_SHIELD = Symbol("exclamationmark.shield")
""" 'exclamationmark.shield' symbol """

EXCLAMATIONMARK_SHIELD_FILL = Symbol("exclamationmark.shield.fill")
""" 'exclamationmark.shield.fill' symbol """

PLUS = Symbol("plus")
""" 'plus' symbol """

PLUS_CIRCLE = Symbol("plus.circle")
""" 'plus.circle' symbol """

PLUS_CIRCLE_FILL = Symbol("plus.circle.fill")
""" 'plus.circle.fill' symbol """

PLUS_SQUARE = Symbol("plus.square")
""" 'plus.square' symbol """

PLUS_SQUARE_FILL = Symbol("plus.square.fill")
""" 'plus.square.fill' symbol """

PLUS_RECTANGLE = Symbol("plus.rectangle")
""" 'plus.rectangle' symbol """

PLUS_RECTANGLE_FILL = Symbol("plus.rectangle.fill")
""" 'plus.rectangle.fill' symbol """

PLUS_RECTANGLE_PORTRAIT = Symbol("plus.rectangle.portrait")
""" 'plus.rectangle.portrait' symbol """

PLUS_RECTANGLE_PORTRAIT_FILL = Symbol("plus.rectangle.portrait.fill")
""" 'plus.rectangle.portrait.fill' symbol """

PLUS_DIAMOND = Symbol("plus.diamond")
""" 'plus.diamond' symbol """

PLUS_DIAMOND_FILL = Symbol("plus.diamond.fill")
""" 'plus.diamond.fill' symbol """

MINUS = Symbol("minus")
""" 'minus' symbol """

MINUS_CIRCLE = Symbol("minus.circle")
""" 'minus.circle' symbol """

MINUS_CIRCLE_FILL = Symbol("minus.circle.fill")
""" 'minus.circle.fill' symbol """

MINUS_SQUARE = Symbol("minus.square")
""" 'minus.square' symbol """

MINUS_SQUARE_FILL = Symbol("minus.square.fill")
""" 'minus.square.fill' symbol """

MINUS_RECTANGLE = Symbol("minus.rectangle")
""" 'minus.rectangle' symbol """

MINUS_RECTANGLE_FILL = Symbol("minus.rectangle.fill")
""" 'minus.rectangle.fill' symbol """

MINUS_RECTANGLE_PORTRAIT = Symbol("minus.rectangle.portrait")
""" 'minus.rectangle.portrait' symbol """

MINUS_RECTANGLE_PORTRAIT_FILL = Symbol("minus.rectangle.portrait.fill")
""" 'minus.rectangle.portrait.fill' symbol """

MINUS_DIAMOND = Symbol("minus.diamond")
""" 'minus.diamond' symbol """

MINUS_DIAMOND_FILL = Symbol("minus.diamond.fill")
""" 'minus.diamond.fill' symbol """

PLUSMINUS = Symbol("plusminus")
""" 'plusminus' symbol """

PLUSMINUS_CIRCLE = Symbol("plusminus.circle")
""" 'plusminus.circle' symbol """

PLUSMINUS_CIRCLE_FILL = Symbol("plusminus.circle.fill")
""" 'plusminus.circle.fill' symbol """

PLUS_SLASH_MINUS = Symbol("plus.slash.minus")
""" 'plus.slash.minus' symbol """

MINUS_SLASH_PLUS = Symbol("minus.slash.plus")
""" 'minus.slash.plus' symbol """

MULTIPLY = Symbol("multiply")
""" 'multiply' symbol """

MULTIPLY_CIRCLE = Symbol("multiply.circle")
""" 'multiply.circle' symbol """

MULTIPLY_CIRCLE_FILL = Symbol("multiply.circle.fill")
""" 'multiply.circle.fill' symbol """

MULTIPLY_SQUARE = Symbol("multiply.square")
""" 'multiply.square' symbol """

MULTIPLY_SQUARE_FILL = Symbol("multiply.square.fill")
""" 'multiply.square.fill' symbol """

XMARK_RECTANGLE = Symbol("xmark.rectangle")
""" 'xmark.rectangle' symbol """

XMARK_RECTANGLE_FILL = Symbol("xmark.rectangle.fill")
""" 'xmark.rectangle.fill' symbol """

XMARK_RECTANGLE_PORTRAIT = Symbol("xmark.rectangle.portrait")
""" 'xmark.rectangle.portrait' symbol """

XMARK_RECTANGLE_PORTRAIT_FILL = Symbol("xmark.rectangle.portrait.fill")
""" 'xmark.rectangle.portrait.fill' symbol """

XMARK_DIAMOND = Symbol("xmark.diamond")
""" 'xmark.diamond' symbol """

XMARK_DIAMOND_FILL = Symbol("xmark.diamond.fill")
""" 'xmark.diamond.fill' symbol """

XMARK_SHIELD = Symbol("xmark.shield")
""" 'xmark.shield' symbol """

XMARK_SHIELD_FILL = Symbol("xmark.shield.fill")
""" 'xmark.shield.fill' symbol """

XMARK_OCTAGON = Symbol("xmark.octagon")
""" 'xmark.octagon' symbol """

XMARK_OCTAGON_FILL = Symbol("xmark.octagon.fill")
""" 'xmark.octagon.fill' symbol """

DIVIDE = Symbol("divide")
""" 'divide' symbol """

DIVIDE_CIRCLE = Symbol("divide.circle")
""" 'divide.circle' symbol """

DIVIDE_CIRCLE_FILL = Symbol("divide.circle.fill")
""" 'divide.circle.fill' symbol """

DIVIDE_SQUARE = Symbol("divide.square")
""" 'divide.square' symbol """

DIVIDE_SQUARE_FILL = Symbol("divide.square.fill")
""" 'divide.square.fill' symbol """

EQUAL = Symbol("equal")
""" 'equal' symbol """

EQUAL_CIRCLE = Symbol("equal.circle")
""" 'equal.circle' symbol """

EQUAL_CIRCLE_FILL = Symbol("equal.circle.fill")
""" 'equal.circle.fill' symbol """

EQUAL_SQUARE = Symbol("equal.square")
""" 'equal.square' symbol """

EQUAL_SQUARE_FILL = Symbol("equal.square.fill")
""" 'equal.square.fill' symbol """

LESSTHAN = Symbol("lessthan")
""" 'lessthan' symbol """

LESSTHAN_CIRCLE = Symbol("lessthan.circle")
""" 'lessthan.circle' symbol """

LESSTHAN_CIRCLE_FILL = Symbol("lessthan.circle.fill")
""" 'lessthan.circle.fill' symbol """

LESSTHAN_SQUARE = Symbol("lessthan.square")
""" 'lessthan.square' symbol """

LESSTHAN_SQUARE_FILL = Symbol("lessthan.square.fill")
""" 'lessthan.square.fill' symbol """

GREATERTHAN = Symbol("greaterthan")
""" 'greaterthan' symbol """

GREATERTHAN_CIRCLE = Symbol("greaterthan.circle")
""" 'greaterthan.circle' symbol """

GREATERTHAN_CIRCLE_FILL = Symbol("greaterthan.circle.fill")
""" 'greaterthan.circle.fill' symbol """

GREATERTHAN_SQUARE = Symbol("greaterthan.square")
""" 'greaterthan.square' symbol """

GREATERTHAN_SQUARE_FILL = Symbol("greaterthan.square.fill")
""" 'greaterthan.square.fill' symbol """

CHEVRON_LEFT_SLASH_CHEVRON_RIGHT = Symbol("chevron.left.slash.chevron.right")
""" 'chevron.left.slash.chevron.right' symbol """

CURLYBRACES = Symbol("curlybraces")
""" 'curlybraces' symbol """

CURLYBRACES_SQUARE = Symbol("curlybraces.square")
""" 'curlybraces.square' symbol """

CURLYBRACES_SQUARE_FILL = Symbol("curlybraces.square.fill")
""" 'curlybraces.square.fill' symbol """

NUMBER = Symbol("number")
""" 'number' symbol """

NUMBER_CIRCLE = Symbol("number.circle")
""" 'number.circle' symbol """

NUMBER_CIRCLE_FILL = Symbol("number.circle.fill")
""" 'number.circle.fill' symbol """

NUMBER_SQUARE = Symbol("number.square")
""" 'number.square' symbol """

NUMBER_SQUARE_FILL = Symbol("number.square.fill")
""" 'number.square.fill' symbol """

X_SQUAREROOT = Symbol("x.squareroot")
""" 'x.squareroot' symbol """

XMARK = Symbol("xmark")
""" 'xmark' symbol """

XMARK_CIRCLE = Symbol("xmark.circle")
""" 'xmark.circle' symbol """

XMARK_CIRCLE_FILL = Symbol("xmark.circle.fill")
""" 'xmark.circle.fill' symbol """

XMARK_SQUARE = Symbol("xmark.square")
""" 'xmark.square' symbol """

XMARK_SQUARE_FILL = Symbol("xmark.square.fill")
""" 'xmark.square.fill' symbol """

CHECKMARK = Symbol("checkmark")
""" 'checkmark' symbol """

CHECKMARK_CIRCLE = Symbol("checkmark.circle")
""" 'checkmark.circle' symbol """

CHECKMARK_CIRCLE_FILL = Symbol("checkmark.circle.fill")
""" 'checkmark.circle.fill' symbol """

CHECKMARK_SQUARE = Symbol("checkmark.square")
""" 'checkmark.square' symbol """

CHECKMARK_SQUARE_FILL = Symbol("checkmark.square.fill")
""" 'checkmark.square.fill' symbol """

CHECKMARK_RECTANGLE = Symbol("checkmark.rectangle")
""" 'checkmark.rectangle' symbol """

CHECKMARK_RECTANGLE_FILL = Symbol("checkmark.rectangle.fill")
""" 'checkmark.rectangle.fill' symbol """

CHECKMARK_RECTANGLE_PORTRAIT = Symbol("checkmark.rectangle.portrait")
""" 'checkmark.rectangle.portrait' symbol """

CHECKMARK_RECTANGLE_PORTRAIT_FILL = Symbol("checkmark.rectangle.portrait.fill")
""" 'checkmark.rectangle.portrait.fill' symbol """

CHECKMARK_SHIELD = Symbol("checkmark.shield")
""" 'checkmark.shield' symbol """

CHECKMARK_SHIELD_FILL = Symbol("checkmark.shield.fill")
""" 'checkmark.shield.fill' symbol """

CHEVRON_UP = Symbol("chevron.up")
""" 'chevron.up' symbol """

CHEVRON_UP_CIRCLE = Symbol("chevron.up.circle")
""" 'chevron.up.circle' symbol """

CHEVRON_UP_CIRCLE_FILL = Symbol("chevron.up.circle.fill")
""" 'chevron.up.circle.fill' symbol """

CHEVRON_UP_SQUARE = Symbol("chevron.up.square")
""" 'chevron.up.square' symbol """

CHEVRON_UP_SQUARE_FILL = Symbol("chevron.up.square.fill")
""" 'chevron.up.square.fill' symbol """

CHEVRON_DOWN = Symbol("chevron.down")
""" 'chevron.down' symbol """

CHEVRON_DOWN_CIRCLE = Symbol("chevron.down.circle")
""" 'chevron.down.circle' symbol """

CHEVRON_DOWN_CIRCLE_FILL = Symbol("chevron.down.circle.fill")
""" 'chevron.down.circle.fill' symbol """

CHEVRON_DOWN_SQUARE = Symbol("chevron.down.square")
""" 'chevron.down.square' symbol """

CHEVRON_DOWN_SQUARE_FILL = Symbol("chevron.down.square.fill")
""" 'chevron.down.square.fill' symbol """

CHEVRON_LEFT = Symbol("chevron.left")
""" 'chevron.left' symbol """

CHEVRON_LEFT_CIRCLE = Symbol("chevron.left.circle")
""" 'chevron.left.circle' symbol """

CHEVRON_LEFT_CIRCLE_FILL = Symbol("chevron.left.circle.fill")
""" 'chevron.left.circle.fill' symbol """

CHEVRON_LEFT_SQUARE = Symbol("chevron.left.square")
""" 'chevron.left.square' symbol """

CHEVRON_LEFT_SQUARE_FILL = Symbol("chevron.left.square.fill")
""" 'chevron.left.square.fill' symbol """

CHEVRON_RIGHT = Symbol("chevron.right")
""" 'chevron.right' symbol """

CHEVRON_RIGHT_CIRCLE = Symbol("chevron.right.circle")
""" 'chevron.right.circle' symbol """

CHEVRON_RIGHT_CIRCLE_FILL = Symbol("chevron.right.circle.fill")
""" 'chevron.right.circle.fill' symbol """

CHEVRON_RIGHT_SQUARE = Symbol("chevron.right.square")
""" 'chevron.right.square' symbol """

CHEVRON_RIGHT_SQUARE_FILL = Symbol("chevron.right.square.fill")
""" 'chevron.right.square.fill' symbol """

CHEVRON_LEFT_2 = Symbol("chevron.left.2")
""" 'chevron.left.2' symbol """

CHEVRON_RIGHT_2 = Symbol("chevron.right.2")
""" 'chevron.right.2' symbol """

CONTROL = Symbol("control")
""" 'control' symbol """

PROJECTIVE = Symbol("projective")
""" 'projective' symbol """

CHEVRON_UP_CHEVRON_DOWN = Symbol("chevron.up.chevron.down")
""" 'chevron.up.chevron.down' symbol """

CHEVRON_COMPACT_UP = Symbol("chevron.compact.up")
""" 'chevron.compact.up' symbol """

CHEVRON_COMPACT_DOWN = Symbol("chevron.compact.down")
""" 'chevron.compact.down' symbol """

CHEVRON_COMPACT_LEFT = Symbol("chevron.compact.left")
""" 'chevron.compact.left' symbol """

CHEVRON_COMPACT_RIGHT = Symbol("chevron.compact.right")
""" 'chevron.compact.right' symbol """

ARROW_UP = Symbol("arrow.up")
""" 'arrow.up' symbol """

ARROW_UP_CIRCLE = Symbol("arrow.up.circle")
""" 'arrow.up.circle' symbol """

ARROW_UP_CIRCLE_FILL = Symbol("arrow.up.circle.fill")
""" 'arrow.up.circle.fill' symbol """

ARROW_UP_SQUARE = Symbol("arrow.up.square")
""" 'arrow.up.square' symbol """

ARROW_UP_SQUARE_FILL = Symbol("arrow.up.square.fill")
""" 'arrow.up.square.fill' symbol """

ARROW_DOWN = Symbol("arrow.down")
""" 'arrow.down' symbol """

ARROW_DOWN_CIRCLE = Symbol("arrow.down.circle")
""" 'arrow.down.circle' symbol """

ARROW_DOWN_CIRCLE_FILL = Symbol("arrow.down.circle.fill")
""" 'arrow.down.circle.fill' symbol """

ARROW_DOWN_SQUARE = Symbol("arrow.down.square")
""" 'arrow.down.square' symbol """

ARROW_DOWN_SQUARE_FILL = Symbol("arrow.down.square.fill")
""" 'arrow.down.square.fill' symbol """

ARROW_LEFT = Symbol("arrow.left")
""" 'arrow.left' symbol """

ARROW_LEFT_CIRCLE = Symbol("arrow.left.circle")
""" 'arrow.left.circle' symbol """

ARROW_LEFT_CIRCLE_FILL = Symbol("arrow.left.circle.fill")
""" 'arrow.left.circle.fill' symbol """

ARROW_LEFT_SQUARE = Symbol("arrow.left.square")
""" 'arrow.left.square' symbol """

ARROW_LEFT_SQUARE_FILL = Symbol("arrow.left.square.fill")
""" 'arrow.left.square.fill' symbol """

ARROW_RIGHT = Symbol("arrow.right")
""" 'arrow.right' symbol """

ARROW_RIGHT_CIRCLE = Symbol("arrow.right.circle")
""" 'arrow.right.circle' symbol """

ARROW_RIGHT_CIRCLE_FILL = Symbol("arrow.right.circle.fill")
""" 'arrow.right.circle.fill' symbol """

ARROW_RIGHT_SQUARE = Symbol("arrow.right.square")
""" 'arrow.right.square' symbol """

ARROW_RIGHT_SQUARE_FILL = Symbol("arrow.right.square.fill")
""" 'arrow.right.square.fill' symbol """

ARROW_UP_LEFT = Symbol("arrow.up.left")
""" 'arrow.up.left' symbol """

ARROW_UP_LEFT_CIRCLE = Symbol("arrow.up.left.circle")
""" 'arrow.up.left.circle' symbol """

ARROW_UP_LEFT_CIRCLE_FILL = Symbol("arrow.up.left.circle.fill")
""" 'arrow.up.left.circle.fill' symbol """

ARROW_UP_LEFT_SQUARE = Symbol("arrow.up.left.square")
""" 'arrow.up.left.square' symbol """

ARROW_UP_LEFT_SQUARE_FILL = Symbol("arrow.up.left.square.fill")
""" 'arrow.up.left.square.fill' symbol """

ARROW_UP_RIGHT = Symbol("arrow.up.right")
""" 'arrow.up.right' symbol """

ARROW_UP_RIGHT_CIRCLE = Symbol("arrow.up.right.circle")
""" 'arrow.up.right.circle' symbol """

ARROW_UP_RIGHT_CIRCLE_FILL = Symbol("arrow.up.right.circle.fill")
""" 'arrow.up.right.circle.fill' symbol """

ARROW_UP_RIGHT_SQUARE = Symbol("arrow.up.right.square")
""" 'arrow.up.right.square' symbol """

ARROW_UP_RIGHT_SQUARE_FILL = Symbol("arrow.up.right.square.fill")
""" 'arrow.up.right.square.fill' symbol """

ARROW_DOWN_LEFT = Symbol("arrow.down.left")
""" 'arrow.down.left' symbol """

ARROW_DOWN_LEFT_CIRCLE = Symbol("arrow.down.left.circle")
""" 'arrow.down.left.circle' symbol """

ARROW_DOWN_LEFT_CIRCLE_FILL = Symbol("arrow.down.left.circle.fill")
""" 'arrow.down.left.circle.fill' symbol """

ARROW_DOWN_LEFT_SQUARE = Symbol("arrow.down.left.square")
""" 'arrow.down.left.square' symbol """

ARROW_DOWN_LEFT_SQUARE_FILL = Symbol("arrow.down.left.square.fill")
""" 'arrow.down.left.square.fill' symbol """

ARROW_DOWN_RIGHT = Symbol("arrow.down.right")
""" 'arrow.down.right' symbol """

ARROW_DOWN_RIGHT_CIRCLE = Symbol("arrow.down.right.circle")
""" 'arrow.down.right.circle' symbol """

ARROW_DOWN_RIGHT_CIRCLE_FILL = Symbol("arrow.down.right.circle.fill")
""" 'arrow.down.right.circle.fill' symbol """

ARROW_DOWN_RIGHT_SQUARE = Symbol("arrow.down.right.square")
""" 'arrow.down.right.square' symbol """

ARROW_DOWN_RIGHT_SQUARE_FILL = Symbol("arrow.down.right.square.fill")
""" 'arrow.down.right.square.fill' symbol """

ARROW_UP_ARROW_DOWN = Symbol("arrow.up.arrow.down")
""" 'arrow.up.arrow.down' symbol """

ARROW_UP_ARROW_DOWN_CIRCLE = Symbol("arrow.up.arrow.down.circle")
""" 'arrow.up.arrow.down.circle' symbol """

ARROW_UP_ARROW_DOWN_CIRCLE_FILL = Symbol("arrow.up.arrow.down.circle.fill")
""" 'arrow.up.arrow.down.circle.fill' symbol """

ARROW_UP_ARROW_DOWN_SQUARE = Symbol("arrow.up.arrow.down.square")
""" 'arrow.up.arrow.down.square' symbol """

ARROW_UP_ARROW_DOWN_SQUARE_FILL = Symbol("arrow.up.arrow.down.square.fill")
""" 'arrow.up.arrow.down.square.fill' symbol """

ARROW_RIGHT_ARROW_LEFT = Symbol("arrow.right.arrow.left")
""" 'arrow.right.arrow.left' symbol """

ARROW_RIGHT_ARROW_LEFT_CIRCLE = Symbol("arrow.right.arrow.left.circle")
""" 'arrow.right.arrow.left.circle' symbol """

ARROW_RIGHT_ARROW_LEFT_CIRCLE_FILL = Symbol("arrow.right.arrow.left.circle.fill")
""" 'arrow.right.arrow.left.circle.fill' symbol """

ARROW_RIGHT_ARROW_LEFT_SQUARE = Symbol("arrow.right.arrow.left.square")
""" 'arrow.right.arrow.left.square' symbol """

ARROW_RIGHT_ARROW_LEFT_SQUARE_FILL = Symbol("arrow.right.arrow.left.square.fill")
""" 'arrow.right.arrow.left.square.fill' symbol """

ARROW_TURN_RIGHT_UP = Symbol("arrow.turn.right.up")
""" 'arrow.turn.right.up' symbol """

ARROW_TURN_RIGHT_DOWN = Symbol("arrow.turn.right.down")
""" 'arrow.turn.right.down' symbol """

ARROW_TURN_DOWN_LEFT = Symbol("arrow.turn.down.left")
""" 'arrow.turn.down.left' symbol """

ARROW_TURN_DOWN_RIGHT = Symbol("arrow.turn.down.right")
""" 'arrow.turn.down.right' symbol """

ARROW_TURN_LEFT_UP = Symbol("arrow.turn.left.up")
""" 'arrow.turn.left.up' symbol """

ARROW_TURN_LEFT_DOWN = Symbol("arrow.turn.left.down")
""" 'arrow.turn.left.down' symbol """

ARROW_TURN_UP_LEFT = Symbol("arrow.turn.up.left")
""" 'arrow.turn.up.left' symbol """

ARROW_TURN_UP_RIGHT = Symbol("arrow.turn.up.right")
""" 'arrow.turn.up.right' symbol """

ARROW_UTURN_UP = Symbol("arrow.uturn.up")
""" 'arrow.uturn.up' symbol """

ARROW_UTURN_UP_CIRCLE = Symbol("arrow.uturn.up.circle")
""" 'arrow.uturn.up.circle' symbol """

ARROW_UTURN_UP_CIRCLE_FILL = Symbol("arrow.uturn.up.circle.fill")
""" 'arrow.uturn.up.circle.fill' symbol """

ARROW_UTURN_UP_SQUARE = Symbol("arrow.uturn.up.square")
""" 'arrow.uturn.up.square' symbol """

ARROW_UTURN_UP_SQUARE_FILL = Symbol("arrow.uturn.up.square.fill")
""" 'arrow.uturn.up.square.fill' symbol """

ARROW_UTURN_DOWN = Symbol("arrow.uturn.down")
""" 'arrow.uturn.down' symbol """

ARROW_UTURN_DOWN_CIRCLE = Symbol("arrow.uturn.down.circle")
""" 'arrow.uturn.down.circle' symbol """

ARROW_UTURN_DOWN_CIRCLE_FILL = Symbol("arrow.uturn.down.circle.fill")
""" 'arrow.uturn.down.circle.fill' symbol """

ARROW_UTURN_DOWN_SQUARE = Symbol("arrow.uturn.down.square")
""" 'arrow.uturn.down.square' symbol """

ARROW_UTURN_DOWN_SQUARE_FILL = Symbol("arrow.uturn.down.square.fill")
""" 'arrow.uturn.down.square.fill' symbol """

ARROW_UTURN_LEFT = Symbol("arrow.uturn.left")
""" 'arrow.uturn.left' symbol """

ARROW_UTURN_LEFT_CIRCLE = Symbol("arrow.uturn.left.circle")
""" 'arrow.uturn.left.circle' symbol """

ARROW_UTURN_LEFT_CIRCLE_FILL = Symbol("arrow.uturn.left.circle.fill")
""" 'arrow.uturn.left.circle.fill' symbol """

ARROW_UTURN_LEFT_CIRCLE_BADGE_ELLIPSIS = Symbol("arrow.uturn.left.circle.badge.ellipsis")
""" 'arrow.uturn.left.circle.badge.ellipsis' symbol """

ARROW_UTURN_LEFT_SQUARE = Symbol("arrow.uturn.left.square")
""" 'arrow.uturn.left.square' symbol """

ARROW_UTURN_LEFT_SQUARE_FILL = Symbol("arrow.uturn.left.square.fill")
""" 'arrow.uturn.left.square.fill' symbol """

ARROW_UTURN_RIGHT = Symbol("arrow.uturn.right")
""" 'arrow.uturn.right' symbol """

ARROW_UTURN_RIGHT_CIRCLE = Symbol("arrow.uturn.right.circle")
""" 'arrow.uturn.right.circle' symbol """

ARROW_UTURN_RIGHT_CIRCLE_FILL = Symbol("arrow.uturn.right.circle.fill")
""" 'arrow.uturn.right.circle.fill' symbol """

ARROW_UTURN_RIGHT_SQUARE = Symbol("arrow.uturn.right.square")
""" 'arrow.uturn.right.square' symbol """

ARROW_UTURN_RIGHT_SQUARE_FILL = Symbol("arrow.uturn.right.square.fill")
""" 'arrow.uturn.right.square.fill' symbol """

ARROW_UP_AND_DOWN_AND_ARROW_LEFT_AND_RIGHT = Symbol("arrow.up.and.down.and.arrow.left.and.right")
""" 'arrow.up.and.down.and.arrow.left.and.right' symbol """

ARROW_UP_LEFT_AND_DOWN_RIGHT_AND_ARROW_UP_RIGHT_AND_DOWN_LEFT = Symbol("arrow.up.left.and.down.right.and.arrow.up.right.and.down.left")
""" 'arrow.up.left.and.down.right.and.arrow.up.right.and.down.left' symbol """

ARROW_UP_AND_DOWN = Symbol("arrow.up.and.down")
""" 'arrow.up.and.down' symbol """

ARROW_UP_AND_DOWN_CIRCLE = Symbol("arrow.up.and.down.circle")
""" 'arrow.up.and.down.circle' symbol """

ARROW_UP_AND_DOWN_CIRCLE_FILL = Symbol("arrow.up.and.down.circle.fill")
""" 'arrow.up.and.down.circle.fill' symbol """

ARROW_UP_AND_DOWN_SQUARE = Symbol("arrow.up.and.down.square")
""" 'arrow.up.and.down.square' symbol """

ARROW_UP_AND_DOWN_SQUARE_FILL = Symbol("arrow.up.and.down.square.fill")
""" 'arrow.up.and.down.square.fill' symbol """

ARROW_LEFT_AND_RIGHT = Symbol("arrow.left.and.right")
""" 'arrow.left.and.right' symbol """

ARROW_LEFT_AND_RIGHT_CIRCLE = Symbol("arrow.left.and.right.circle")
""" 'arrow.left.and.right.circle' symbol """

ARROW_LEFT_AND_RIGHT_CIRCLE_FILL = Symbol("arrow.left.and.right.circle.fill")
""" 'arrow.left.and.right.circle.fill' symbol """

ARROW_LEFT_AND_RIGHT_SQUARE = Symbol("arrow.left.and.right.square")
""" 'arrow.left.and.right.square' symbol """

ARROW_LEFT_AND_RIGHT_SQUARE_FILL = Symbol("arrow.left.and.right.square.fill")
""" 'arrow.left.and.right.square.fill' symbol """

ARROW_UP_TO_LINE_ALT = Symbol("arrow.up.to.line.alt")
""" 'arrow.up.to.line.alt' symbol """

ARROW_UP_TO_LINE = Symbol("arrow.up.to.line")
""" 'arrow.up.to.line' symbol """

ARROW_DOWN_TO_LINE_ALT = Symbol("arrow.down.to.line.alt")
""" 'arrow.down.to.line.alt' symbol """

ARROW_DOWN_TO_LINE = Symbol("arrow.down.to.line")
""" 'arrow.down.to.line' symbol """

ARROW_LEFT_TO_LINE_ALT = Symbol("arrow.left.to.line.alt")
""" 'arrow.left.to.line.alt' symbol """

ARROW_LEFT_TO_LINE = Symbol("arrow.left.to.line")
""" 'arrow.left.to.line' symbol """

ARROW_RIGHT_TO_LINE_ALT = Symbol("arrow.right.to.line.alt")
""" 'arrow.right.to.line.alt' symbol """

ARROW_RIGHT_TO_LINE = Symbol("arrow.right.to.line")
""" 'arrow.right.to.line' symbol """

RETURN = Symbol("return")
""" 'return' symbol """

ARROW_CLOCKWISE = Symbol("arrow.clockwise")
""" 'arrow.clockwise' symbol """

ARROW_CLOCKWISE_CIRCLE = Symbol("arrow.clockwise.circle")
""" 'arrow.clockwise.circle' symbol """

ARROW_CLOCKWISE_CIRCLE_FILL = Symbol("arrow.clockwise.circle.fill")
""" 'arrow.clockwise.circle.fill' symbol """

ARROW_COUNTERCLOCKWISE = Symbol("arrow.counterclockwise")
""" 'arrow.counterclockwise' symbol """

ARROW_COUNTERCLOCKWISE_CIRCLE = Symbol("arrow.counterclockwise.circle")
""" 'arrow.counterclockwise.circle' symbol """

ARROW_COUNTERCLOCKWISE_CIRCLE_FILL = Symbol("arrow.counterclockwise.circle.fill")
""" 'arrow.counterclockwise.circle.fill' symbol """

ARROW_UP_LEFT_AND_ARROW_DOWN_RIGHT = Symbol("arrow.up.left.and.arrow.down.right")
""" 'arrow.up.left.and.arrow.down.right' symbol """

ARROW_UP_LEFT_AND_ARROW_DOWN_RIGHT_CIRCLE = Symbol("arrow.up.left.and.arrow.down.right.circle")
""" 'arrow.up.left.and.arrow.down.right.circle' symbol """

ARROW_UP_LEFT_AND_ARROW_DOWN_RIGHT_CIRCLE_FILL = Symbol("arrow.up.left.and.arrow.down.right.circle.fill")
""" 'arrow.up.left.and.arrow.down.right.circle.fill' symbol """

ARROW_DOWN_RIGHT_AND_ARROW_UP_LEFT = Symbol("arrow.down.right.and.arrow.up.left")
""" 'arrow.down.right.and.arrow.up.left' symbol """

ARROW_2_SQUAREPATH = Symbol("arrow.2.squarepath")
""" 'arrow.2.squarepath' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH = Symbol("arrow.triangle.2.circlepath")
""" 'arrow.triangle.2.circlepath' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH_CIRCLE = Symbol("arrow.triangle.2.circlepath.circle")
""" 'arrow.triangle.2.circlepath.circle' symbol """

ARROW_TRIANGLE_2_CIRCLEPATH_CIRCLE_FILL = Symbol("arrow.triangle.2.circlepath.circle.fill")
""" 'arrow.triangle.2.circlepath.circle.fill' symbol """

EXCLAMATIONMARK_ARROW_TRIANGLE_2_CIRCLEPATH = Symbol("exclamationmark.arrow.triangle.2.circlepath")
""" 'exclamationmark.arrow.triangle.2.circlepath' symbol """

ARROW_TRIANGLE_CAPSULEPATH = Symbol("arrow.triangle.capsulepath")
""" 'arrow.triangle.capsulepath' symbol """

ARROW_3_TRIANGLEPATH = Symbol("arrow.3.trianglepath")
""" 'arrow.3.trianglepath' symbol """

ARROW_TRIANGLE_TURN_UP_RIGHT_DIAMOND = Symbol("arrow.triangle.turn.up.right.diamond")
""" 'arrow.triangle.turn.up.right.diamond' symbol """

ARROW_TRIANGLE_TURN_UP_RIGHT_DIAMOND_FILL = Symbol("arrow.triangle.turn.up.right.diamond.fill")
""" 'arrow.triangle.turn.up.right.diamond.fill' symbol """

ARROW_TRIANGLE_TURN_UP_RIGHT_CIRCLE = Symbol("arrow.triangle.turn.up.right.circle")
""" 'arrow.triangle.turn.up.right.circle' symbol """

ARROW_TRIANGLE_TURN_UP_RIGHT_CIRCLE_FILL = Symbol("arrow.triangle.turn.up.right.circle.fill")
""" 'arrow.triangle.turn.up.right.circle.fill' symbol """

ARROW_TRIANGLE_MERGE = Symbol("arrow.triangle.merge")
""" 'arrow.triangle.merge' symbol """

ARROW_TRIANGLE_SWAP = Symbol("arrow.triangle.swap")
""" 'arrow.triangle.swap' symbol """

ARROW_TRIANGLE_BRANCH = Symbol("arrow.triangle.branch")
""" 'arrow.triangle.branch' symbol """

ARROW_TRIANGLE_PULL = Symbol("arrow.triangle.pull")
""" 'arrow.triangle.pull' symbol """

ARROWTRIANGLE_UP = Symbol("arrowtriangle.up")
""" 'arrowtriangle.up' symbol """

ARROWTRIANGLE_UP_FILL = Symbol("arrowtriangle.up.fill")
""" 'arrowtriangle.up.fill' symbol """

ARROWTRIANGLE_UP_CIRCLE = Symbol("arrowtriangle.up.circle")
""" 'arrowtriangle.up.circle' symbol """

ARROWTRIANGLE_UP_CIRCLE_FILL = Symbol("arrowtriangle.up.circle.fill")
""" 'arrowtriangle.up.circle.fill' symbol """

ARROWTRIANGLE_UP_SQUARE = Symbol("arrowtriangle.up.square")
""" 'arrowtriangle.up.square' symbol """

ARROWTRIANGLE_UP_SQUARE_FILL = Symbol("arrowtriangle.up.square.fill")
""" 'arrowtriangle.up.square.fill' symbol """

ARROWTRIANGLE_DOWN = Symbol("arrowtriangle.down")
""" 'arrowtriangle.down' symbol """

ARROWTRIANGLE_DOWN_FILL = Symbol("arrowtriangle.down.fill")
""" 'arrowtriangle.down.fill' symbol """

ARROWTRIANGLE_DOWN_CIRCLE = Symbol("arrowtriangle.down.circle")
""" 'arrowtriangle.down.circle' symbol """

ARROWTRIANGLE_DOWN_CIRCLE_FILL = Symbol("arrowtriangle.down.circle.fill")
""" 'arrowtriangle.down.circle.fill' symbol """

ARROWTRIANGLE_DOWN_SQUARE = Symbol("arrowtriangle.down.square")
""" 'arrowtriangle.down.square' symbol """

ARROWTRIANGLE_DOWN_SQUARE_FILL = Symbol("arrowtriangle.down.square.fill")
""" 'arrowtriangle.down.square.fill' symbol """

ARROWTRIANGLE_LEFT = Symbol("arrowtriangle.left")
""" 'arrowtriangle.left' symbol """

ARROWTRIANGLE_LEFT_FILL = Symbol("arrowtriangle.left.fill")
""" 'arrowtriangle.left.fill' symbol """

ARROWTRIANGLE_LEFT_CIRCLE = Symbol("arrowtriangle.left.circle")
""" 'arrowtriangle.left.circle' symbol """

ARROWTRIANGLE_LEFT_CIRCLE_FILL = Symbol("arrowtriangle.left.circle.fill")
""" 'arrowtriangle.left.circle.fill' symbol """

ARROWTRIANGLE_LEFT_SQUARE = Symbol("arrowtriangle.left.square")
""" 'arrowtriangle.left.square' symbol """

ARROWTRIANGLE_LEFT_SQUARE_FILL = Symbol("arrowtriangle.left.square.fill")
""" 'arrowtriangle.left.square.fill' symbol """

ARROWTRIANGLE_RIGHT = Symbol("arrowtriangle.right")
""" 'arrowtriangle.right' symbol """

ARROWTRIANGLE_RIGHT_FILL = Symbol("arrowtriangle.right.fill")
""" 'arrowtriangle.right.fill' symbol """

ARROWTRIANGLE_RIGHT_CIRCLE = Symbol("arrowtriangle.right.circle")
""" 'arrowtriangle.right.circle' symbol """

ARROWTRIANGLE_RIGHT_CIRCLE_FILL = Symbol("arrowtriangle.right.circle.fill")
""" 'arrowtriangle.right.circle.fill' symbol """

ARROWTRIANGLE_RIGHT_SQUARE = Symbol("arrowtriangle.right.square")
""" 'arrowtriangle.right.square' symbol """

ARROWTRIANGLE_RIGHT_SQUARE_FILL = Symbol("arrowtriangle.right.square.fill")
""" 'arrowtriangle.right.square.fill' symbol """

SLASH_CIRCLE = Symbol("slash.circle")
""" 'slash.circle' symbol """

SLASH_CIRCLE_FILL = Symbol("slash.circle.fill")
""" 'slash.circle.fill' symbol """

ASTERISK_CIRCLE = Symbol("asterisk.circle")
""" 'asterisk.circle' symbol """

ASTERISK_CIRCLE_FILL = Symbol("asterisk.circle.fill")
""" 'asterisk.circle.fill' symbol """

A_CIRCLE = Symbol("a.circle")
""" 'a.circle' symbol """

A_CIRCLE_FILL = Symbol("a.circle.fill")
""" 'a.circle.fill' symbol """

A_SQUARE = Symbol("a.square")
""" 'a.square' symbol """

A_SQUARE_FILL = Symbol("a.square.fill")
""" 'a.square.fill' symbol """

B_CIRCLE = Symbol("b.circle")
""" 'b.circle' symbol """

B_CIRCLE_FILL = Symbol("b.circle.fill")
""" 'b.circle.fill' symbol """

B_SQUARE = Symbol("b.square")
""" 'b.square' symbol """

B_SQUARE_FILL = Symbol("b.square.fill")
""" 'b.square.fill' symbol """

C_CIRCLE = Symbol("c.circle")
""" 'c.circle' symbol """

C_CIRCLE_FILL = Symbol("c.circle.fill")
""" 'c.circle.fill' symbol """

C_SQUARE = Symbol("c.square")
""" 'c.square' symbol """

C_SQUARE_FILL = Symbol("c.square.fill")
""" 'c.square.fill' symbol """

D_CIRCLE = Symbol("d.circle")
""" 'd.circle' symbol """

D_CIRCLE_FILL = Symbol("d.circle.fill")
""" 'd.circle.fill' symbol """

D_SQUARE = Symbol("d.square")
""" 'd.square' symbol """

D_SQUARE_FILL = Symbol("d.square.fill")
""" 'd.square.fill' symbol """

E_CIRCLE = Symbol("e.circle")
""" 'e.circle' symbol """

E_CIRCLE_FILL = Symbol("e.circle.fill")
""" 'e.circle.fill' symbol """

E_SQUARE = Symbol("e.square")
""" 'e.square' symbol """

E_SQUARE_FILL = Symbol("e.square.fill")
""" 'e.square.fill' symbol """

F_CIRCLE = Symbol("f.circle")
""" 'f.circle' symbol """

F_CIRCLE_FILL = Symbol("f.circle.fill")
""" 'f.circle.fill' symbol """

F_SQUARE = Symbol("f.square")
""" 'f.square' symbol """

F_SQUARE_FILL = Symbol("f.square.fill")
""" 'f.square.fill' symbol """

G_CIRCLE = Symbol("g.circle")
""" 'g.circle' symbol """

G_CIRCLE_FILL = Symbol("g.circle.fill")
""" 'g.circle.fill' symbol """

G_SQUARE = Symbol("g.square")
""" 'g.square' symbol """

G_SQUARE_FILL = Symbol("g.square.fill")
""" 'g.square.fill' symbol """

H_CIRCLE = Symbol("h.circle")
""" 'h.circle' symbol """

H_CIRCLE_FILL = Symbol("h.circle.fill")
""" 'h.circle.fill' symbol """

H_SQUARE = Symbol("h.square")
""" 'h.square' symbol """

H_SQUARE_FILL = Symbol("h.square.fill")
""" 'h.square.fill' symbol """

I_CIRCLE = Symbol("i.circle")
""" 'i.circle' symbol """

I_CIRCLE_FILL = Symbol("i.circle.fill")
""" 'i.circle.fill' symbol """

I_SQUARE = Symbol("i.square")
""" 'i.square' symbol """

I_SQUARE_FILL = Symbol("i.square.fill")
""" 'i.square.fill' symbol """

J_CIRCLE = Symbol("j.circle")
""" 'j.circle' symbol """

J_CIRCLE_FILL = Symbol("j.circle.fill")
""" 'j.circle.fill' symbol """

J_SQUARE = Symbol("j.square")
""" 'j.square' symbol """

J_SQUARE_FILL = Symbol("j.square.fill")
""" 'j.square.fill' symbol """

K_CIRCLE = Symbol("k.circle")
""" 'k.circle' symbol """

K_CIRCLE_FILL = Symbol("k.circle.fill")
""" 'k.circle.fill' symbol """

K_SQUARE = Symbol("k.square")
""" 'k.square' symbol """

K_SQUARE_FILL = Symbol("k.square.fill")
""" 'k.square.fill' symbol """

L_CIRCLE = Symbol("l.circle")
""" 'l.circle' symbol """

L_CIRCLE_FILL = Symbol("l.circle.fill")
""" 'l.circle.fill' symbol """

L_SQUARE = Symbol("l.square")
""" 'l.square' symbol """

L_SQUARE_FILL = Symbol("l.square.fill")
""" 'l.square.fill' symbol """

M_CIRCLE = Symbol("m.circle")
""" 'm.circle' symbol """

M_CIRCLE_FILL = Symbol("m.circle.fill")
""" 'm.circle.fill' symbol """

M_SQUARE = Symbol("m.square")
""" 'm.square' symbol """

M_SQUARE_FILL = Symbol("m.square.fill")
""" 'm.square.fill' symbol """

N_CIRCLE = Symbol("n.circle")
""" 'n.circle' symbol """

N_CIRCLE_FILL = Symbol("n.circle.fill")
""" 'n.circle.fill' symbol """

N_SQUARE = Symbol("n.square")
""" 'n.square' symbol """

N_SQUARE_FILL = Symbol("n.square.fill")
""" 'n.square.fill' symbol """

O_CIRCLE = Symbol("o.circle")
""" 'o.circle' symbol """

O_CIRCLE_FILL = Symbol("o.circle.fill")
""" 'o.circle.fill' symbol """

O_SQUARE = Symbol("o.square")
""" 'o.square' symbol """

O_SQUARE_FILL = Symbol("o.square.fill")
""" 'o.square.fill' symbol """

P_CIRCLE = Symbol("p.circle")
""" 'p.circle' symbol """

P_CIRCLE_FILL = Symbol("p.circle.fill")
""" 'p.circle.fill' symbol """

P_SQUARE = Symbol("p.square")
""" 'p.square' symbol """

P_SQUARE_FILL = Symbol("p.square.fill")
""" 'p.square.fill' symbol """

Q_CIRCLE = Symbol("q.circle")
""" 'q.circle' symbol """

Q_CIRCLE_FILL = Symbol("q.circle.fill")
""" 'q.circle.fill' symbol """

Q_SQUARE = Symbol("q.square")
""" 'q.square' symbol """

Q_SQUARE_FILL = Symbol("q.square.fill")
""" 'q.square.fill' symbol """

R_CIRCLE = Symbol("r.circle")
""" 'r.circle' symbol """

R_CIRCLE_FILL = Symbol("r.circle.fill")
""" 'r.circle.fill' symbol """

R_SQUARE = Symbol("r.square")
""" 'r.square' symbol """

R_SQUARE_FILL = Symbol("r.square.fill")
""" 'r.square.fill' symbol """

S_CIRCLE = Symbol("s.circle")
""" 's.circle' symbol """

S_CIRCLE_FILL = Symbol("s.circle.fill")
""" 's.circle.fill' symbol """

S_SQUARE = Symbol("s.square")
""" 's.square' symbol """

S_SQUARE_FILL = Symbol("s.square.fill")
""" 's.square.fill' symbol """

T_CIRCLE = Symbol("t.circle")
""" 't.circle' symbol """

T_CIRCLE_FILL = Symbol("t.circle.fill")
""" 't.circle.fill' symbol """

T_SQUARE = Symbol("t.square")
""" 't.square' symbol """

T_SQUARE_FILL = Symbol("t.square.fill")
""" 't.square.fill' symbol """

U_CIRCLE = Symbol("u.circle")
""" 'u.circle' symbol """

U_CIRCLE_FILL = Symbol("u.circle.fill")
""" 'u.circle.fill' symbol """

U_SQUARE = Symbol("u.square")
""" 'u.square' symbol """

U_SQUARE_FILL = Symbol("u.square.fill")
""" 'u.square.fill' symbol """

V_CIRCLE = Symbol("v.circle")
""" 'v.circle' symbol """

V_CIRCLE_FILL = Symbol("v.circle.fill")
""" 'v.circle.fill' symbol """

V_SQUARE = Symbol("v.square")
""" 'v.square' symbol """

V_SQUARE_FILL = Symbol("v.square.fill")
""" 'v.square.fill' symbol """

W_CIRCLE = Symbol("w.circle")
""" 'w.circle' symbol """

W_CIRCLE_FILL = Symbol("w.circle.fill")
""" 'w.circle.fill' symbol """

W_SQUARE = Symbol("w.square")
""" 'w.square' symbol """

W_SQUARE_FILL = Symbol("w.square.fill")
""" 'w.square.fill' symbol """

X_CIRCLE = Symbol("x.circle")
""" 'x.circle' symbol """

X_CIRCLE_FILL = Symbol("x.circle.fill")
""" 'x.circle.fill' symbol """

X_SQUARE = Symbol("x.square")
""" 'x.square' symbol """

X_SQUARE_FILL = Symbol("x.square.fill")
""" 'x.square.fill' symbol """

Y_CIRCLE = Symbol("y.circle")
""" 'y.circle' symbol """

Y_CIRCLE_FILL = Symbol("y.circle.fill")
""" 'y.circle.fill' symbol """

Y_SQUARE = Symbol("y.square")
""" 'y.square' symbol """

Y_SQUARE_FILL = Symbol("y.square.fill")
""" 'y.square.fill' symbol """

Z_CIRCLE = Symbol("z.circle")
""" 'z.circle' symbol """

Z_CIRCLE_FILL = Symbol("z.circle.fill")
""" 'z.circle.fill' symbol """

Z_SQUARE = Symbol("z.square")
""" 'z.square' symbol """

Z_SQUARE_FILL = Symbol("z.square.fill")
""" 'z.square.fill' symbol """

DOLLARSIGN_CIRCLE = Symbol("dollarsign.circle")
""" 'dollarsign.circle' symbol """

DOLLARSIGN_CIRCLE_FILL = Symbol("dollarsign.circle.fill")
""" 'dollarsign.circle.fill' symbol """

DOLLARSIGN_SQUARE = Symbol("dollarsign.square")
""" 'dollarsign.square' symbol """

DOLLARSIGN_SQUARE_FILL = Symbol("dollarsign.square.fill")
""" 'dollarsign.square.fill' symbol """

CENTSIGN_CIRCLE = Symbol("centsign.circle")
""" 'centsign.circle' symbol """

CENTSIGN_CIRCLE_FILL = Symbol("centsign.circle.fill")
""" 'centsign.circle.fill' symbol """

CENTSIGN_SQUARE = Symbol("centsign.square")
""" 'centsign.square' symbol """

CENTSIGN_SQUARE_FILL = Symbol("centsign.square.fill")
""" 'centsign.square.fill' symbol """

YENSIGN_CIRCLE = Symbol("yensign.circle")
""" 'yensign.circle' symbol """

YENSIGN_CIRCLE_FILL = Symbol("yensign.circle.fill")
""" 'yensign.circle.fill' symbol """

YENSIGN_SQUARE = Symbol("yensign.square")
""" 'yensign.square' symbol """

YENSIGN_SQUARE_FILL = Symbol("yensign.square.fill")
""" 'yensign.square.fill' symbol """

STERLINGSIGN_CIRCLE = Symbol("sterlingsign.circle")
""" 'sterlingsign.circle' symbol """

STERLINGSIGN_CIRCLE_FILL = Symbol("sterlingsign.circle.fill")
""" 'sterlingsign.circle.fill' symbol """

STERLINGSIGN_SQUARE = Symbol("sterlingsign.square")
""" 'sterlingsign.square' symbol """

STERLINGSIGN_SQUARE_FILL = Symbol("sterlingsign.square.fill")
""" 'sterlingsign.square.fill' symbol """

FRANCSIGN_CIRCLE = Symbol("francsign.circle")
""" 'francsign.circle' symbol """

FRANCSIGN_CIRCLE_FILL = Symbol("francsign.circle.fill")
""" 'francsign.circle.fill' symbol """

FRANCSIGN_SQUARE = Symbol("francsign.square")
""" 'francsign.square' symbol """

FRANCSIGN_SQUARE_FILL = Symbol("francsign.square.fill")
""" 'francsign.square.fill' symbol """

FLORINSIGN_CIRCLE = Symbol("florinsign.circle")
""" 'florinsign.circle' symbol """

FLORINSIGN_CIRCLE_FILL = Symbol("florinsign.circle.fill")
""" 'florinsign.circle.fill' symbol """

FLORINSIGN_SQUARE = Symbol("florinsign.square")
""" 'florinsign.square' symbol """

FLORINSIGN_SQUARE_FILL = Symbol("florinsign.square.fill")
""" 'florinsign.square.fill' symbol """

TURKISHLIRASIGN_CIRCLE = Symbol("turkishlirasign.circle")
""" 'turkishlirasign.circle' symbol """

TURKISHLIRASIGN_CIRCLE_FILL = Symbol("turkishlirasign.circle.fill")
""" 'turkishlirasign.circle.fill' symbol """

TURKISHLIRASIGN_SQUARE = Symbol("turkishlirasign.square")
""" 'turkishlirasign.square' symbol """

TURKISHLIRASIGN_SQUARE_FILL = Symbol("turkishlirasign.square.fill")
""" 'turkishlirasign.square.fill' symbol """

RUBLESIGN_CIRCLE = Symbol("rublesign.circle")
""" 'rublesign.circle' symbol """

RUBLESIGN_CIRCLE_FILL = Symbol("rublesign.circle.fill")
""" 'rublesign.circle.fill' symbol """

RUBLESIGN_SQUARE = Symbol("rublesign.square")
""" 'rublesign.square' symbol """

RUBLESIGN_SQUARE_FILL = Symbol("rublesign.square.fill")
""" 'rublesign.square.fill' symbol """

EUROSIGN_CIRCLE = Symbol("eurosign.circle")
""" 'eurosign.circle' symbol """

EUROSIGN_CIRCLE_FILL = Symbol("eurosign.circle.fill")
""" 'eurosign.circle.fill' symbol """

EUROSIGN_SQUARE = Symbol("eurosign.square")
""" 'eurosign.square' symbol """

EUROSIGN_SQUARE_FILL = Symbol("eurosign.square.fill")
""" 'eurosign.square.fill' symbol """

DONGSIGN_CIRCLE = Symbol("dongsign.circle")
""" 'dongsign.circle' symbol """

DONGSIGN_CIRCLE_FILL = Symbol("dongsign.circle.fill")
""" 'dongsign.circle.fill' symbol """

DONGSIGN_SQUARE = Symbol("dongsign.square")
""" 'dongsign.square' symbol """

DONGSIGN_SQUARE_FILL = Symbol("dongsign.square.fill")
""" 'dongsign.square.fill' symbol """

INDIANRUPEESIGN_CIRCLE = Symbol("indianrupeesign.circle")
""" 'indianrupeesign.circle' symbol """

INDIANRUPEESIGN_CIRCLE_FILL = Symbol("indianrupeesign.circle.fill")
""" 'indianrupeesign.circle.fill' symbol """

INDIANRUPEESIGN_SQUARE = Symbol("indianrupeesign.square")
""" 'indianrupeesign.square' symbol """

INDIANRUPEESIGN_SQUARE_FILL = Symbol("indianrupeesign.square.fill")
""" 'indianrupeesign.square.fill' symbol """

TENGESIGN_CIRCLE = Symbol("tengesign.circle")
""" 'tengesign.circle' symbol """

TENGESIGN_CIRCLE_FILL = Symbol("tengesign.circle.fill")
""" 'tengesign.circle.fill' symbol """

TENGESIGN_SQUARE = Symbol("tengesign.square")
""" 'tengesign.square' symbol """

TENGESIGN_SQUARE_FILL = Symbol("tengesign.square.fill")
""" 'tengesign.square.fill' symbol """

PESETASIGN_CIRCLE = Symbol("pesetasign.circle")
""" 'pesetasign.circle' symbol """

PESETASIGN_CIRCLE_FILL = Symbol("pesetasign.circle.fill")
""" 'pesetasign.circle.fill' symbol """

PESETASIGN_SQUARE = Symbol("pesetasign.square")
""" 'pesetasign.square' symbol """

PESETASIGN_SQUARE_FILL = Symbol("pesetasign.square.fill")
""" 'pesetasign.square.fill' symbol """

PESOSIGN_CIRCLE = Symbol("pesosign.circle")
""" 'pesosign.circle' symbol """

PESOSIGN_CIRCLE_FILL = Symbol("pesosign.circle.fill")
""" 'pesosign.circle.fill' symbol """

PESOSIGN_SQUARE = Symbol("pesosign.square")
""" 'pesosign.square' symbol """

PESOSIGN_SQUARE_FILL = Symbol("pesosign.square.fill")
""" 'pesosign.square.fill' symbol """

KIPSIGN_CIRCLE = Symbol("kipsign.circle")
""" 'kipsign.circle' symbol """

KIPSIGN_CIRCLE_FILL = Symbol("kipsign.circle.fill")
""" 'kipsign.circle.fill' symbol """

KIPSIGN_SQUARE = Symbol("kipsign.square")
""" 'kipsign.square' symbol """

KIPSIGN_SQUARE_FILL = Symbol("kipsign.square.fill")
""" 'kipsign.square.fill' symbol """

WONSIGN_CIRCLE = Symbol("wonsign.circle")
""" 'wonsign.circle' symbol """

WONSIGN_CIRCLE_FILL = Symbol("wonsign.circle.fill")
""" 'wonsign.circle.fill' symbol """

WONSIGN_SQUARE = Symbol("wonsign.square")
""" 'wonsign.square' symbol """

WONSIGN_SQUARE_FILL = Symbol("wonsign.square.fill")
""" 'wonsign.square.fill' symbol """

LIRASIGN_CIRCLE = Symbol("lirasign.circle")
""" 'lirasign.circle' symbol """

LIRASIGN_CIRCLE_FILL = Symbol("lirasign.circle.fill")
""" 'lirasign.circle.fill' symbol """

LIRASIGN_SQUARE = Symbol("lirasign.square")
""" 'lirasign.square' symbol """

LIRASIGN_SQUARE_FILL = Symbol("lirasign.square.fill")
""" 'lirasign.square.fill' symbol """

AUSTRALSIGN_CIRCLE = Symbol("australsign.circle")
""" 'australsign.circle' symbol """

AUSTRALSIGN_CIRCLE_FILL = Symbol("australsign.circle.fill")
""" 'australsign.circle.fill' symbol """

AUSTRALSIGN_SQUARE = Symbol("australsign.square")
""" 'australsign.square' symbol """

AUSTRALSIGN_SQUARE_FILL = Symbol("australsign.square.fill")
""" 'australsign.square.fill' symbol """

HRYVNIASIGN_CIRCLE = Symbol("hryvniasign.circle")
""" 'hryvniasign.circle' symbol """

HRYVNIASIGN_CIRCLE_FILL = Symbol("hryvniasign.circle.fill")
""" 'hryvniasign.circle.fill' symbol """

HRYVNIASIGN_SQUARE = Symbol("hryvniasign.square")
""" 'hryvniasign.square' symbol """

HRYVNIASIGN_SQUARE_FILL = Symbol("hryvniasign.square.fill")
""" 'hryvniasign.square.fill' symbol """

NAIRASIGN_CIRCLE = Symbol("nairasign.circle")
""" 'nairasign.circle' symbol """

NAIRASIGN_CIRCLE_FILL = Symbol("nairasign.circle.fill")
""" 'nairasign.circle.fill' symbol """

NAIRASIGN_SQUARE = Symbol("nairasign.square")
""" 'nairasign.square' symbol """

NAIRASIGN_SQUARE_FILL = Symbol("nairasign.square.fill")
""" 'nairasign.square.fill' symbol """

GUARANISIGN_CIRCLE = Symbol("guaranisign.circle")
""" 'guaranisign.circle' symbol """

GUARANISIGN_CIRCLE_FILL = Symbol("guaranisign.circle.fill")
""" 'guaranisign.circle.fill' symbol """

GUARANISIGN_SQUARE = Symbol("guaranisign.square")
""" 'guaranisign.square' symbol """

GUARANISIGN_SQUARE_FILL = Symbol("guaranisign.square.fill")
""" 'guaranisign.square.fill' symbol """

COLONCURRENCYSIGN_CIRCLE = Symbol("coloncurrencysign.circle")
""" 'coloncurrencysign.circle' symbol """

COLONCURRENCYSIGN_CIRCLE_FILL = Symbol("coloncurrencysign.circle.fill")
""" 'coloncurrencysign.circle.fill' symbol """

COLONCURRENCYSIGN_SQUARE = Symbol("coloncurrencysign.square")
""" 'coloncurrencysign.square' symbol """

COLONCURRENCYSIGN_SQUARE_FILL = Symbol("coloncurrencysign.square.fill")
""" 'coloncurrencysign.square.fill' symbol """

CEDISIGN_CIRCLE = Symbol("cedisign.circle")
""" 'cedisign.circle' symbol """

CEDISIGN_CIRCLE_FILL = Symbol("cedisign.circle.fill")
""" 'cedisign.circle.fill' symbol """

CEDISIGN_SQUARE = Symbol("cedisign.square")
""" 'cedisign.square' symbol """

CEDISIGN_SQUARE_FILL = Symbol("cedisign.square.fill")
""" 'cedisign.square.fill' symbol """

CRUZEIROSIGN_CIRCLE = Symbol("cruzeirosign.circle")
""" 'cruzeirosign.circle' symbol """

CRUZEIROSIGN_CIRCLE_FILL = Symbol("cruzeirosign.circle.fill")
""" 'cruzeirosign.circle.fill' symbol """

CRUZEIROSIGN_SQUARE = Symbol("cruzeirosign.square")
""" 'cruzeirosign.square' symbol """

CRUZEIROSIGN_SQUARE_FILL = Symbol("cruzeirosign.square.fill")
""" 'cruzeirosign.square.fill' symbol """

TUGRIKSIGN_CIRCLE = Symbol("tugriksign.circle")
""" 'tugriksign.circle' symbol """

TUGRIKSIGN_CIRCLE_FILL = Symbol("tugriksign.circle.fill")
""" 'tugriksign.circle.fill' symbol """

TUGRIKSIGN_SQUARE = Symbol("tugriksign.square")
""" 'tugriksign.square' symbol """

TUGRIKSIGN_SQUARE_FILL = Symbol("tugriksign.square.fill")
""" 'tugriksign.square.fill' symbol """

MILLSIGN_CIRCLE = Symbol("millsign.circle")
""" 'millsign.circle' symbol """

MILLSIGN_CIRCLE_FILL = Symbol("millsign.circle.fill")
""" 'millsign.circle.fill' symbol """

MILLSIGN_SQUARE = Symbol("millsign.square")
""" 'millsign.square' symbol """

MILLSIGN_SQUARE_FILL = Symbol("millsign.square.fill")
""" 'millsign.square.fill' symbol """

SHEQELSIGN_CIRCLE = Symbol("sheqelsign.circle")
""" 'sheqelsign.circle' symbol """

SHEQELSIGN_CIRCLE_FILL = Symbol("sheqelsign.circle.fill")
""" 'sheqelsign.circle.fill' symbol """

SHEQELSIGN_SQUARE = Symbol("sheqelsign.square")
""" 'sheqelsign.square' symbol """

SHEQELSIGN_SQUARE_FILL = Symbol("sheqelsign.square.fill")
""" 'sheqelsign.square.fill' symbol """

MANATSIGN_CIRCLE = Symbol("manatsign.circle")
""" 'manatsign.circle' symbol """

MANATSIGN_CIRCLE_FILL = Symbol("manatsign.circle.fill")
""" 'manatsign.circle.fill' symbol """

MANATSIGN_SQUARE = Symbol("manatsign.square")
""" 'manatsign.square' symbol """

MANATSIGN_SQUARE_FILL = Symbol("manatsign.square.fill")
""" 'manatsign.square.fill' symbol """

RUPEESIGN_CIRCLE = Symbol("rupeesign.circle")
""" 'rupeesign.circle' symbol """

RUPEESIGN_CIRCLE_FILL = Symbol("rupeesign.circle.fill")
""" 'rupeesign.circle.fill' symbol """

RUPEESIGN_SQUARE = Symbol("rupeesign.square")
""" 'rupeesign.square' symbol """

RUPEESIGN_SQUARE_FILL = Symbol("rupeesign.square.fill")
""" 'rupeesign.square.fill' symbol """

BAHTSIGN_CIRCLE = Symbol("bahtsign.circle")
""" 'bahtsign.circle' symbol """

BAHTSIGN_CIRCLE_FILL = Symbol("bahtsign.circle.fill")
""" 'bahtsign.circle.fill' symbol """

BAHTSIGN_SQUARE = Symbol("bahtsign.square")
""" 'bahtsign.square' symbol """

BAHTSIGN_SQUARE_FILL = Symbol("bahtsign.square.fill")
""" 'bahtsign.square.fill' symbol """

LARISIGN_CIRCLE = Symbol("larisign.circle")
""" 'larisign.circle' symbol """

LARISIGN_CIRCLE_FILL = Symbol("larisign.circle.fill")
""" 'larisign.circle.fill' symbol """

LARISIGN_SQUARE = Symbol("larisign.square")
""" 'larisign.square' symbol """

LARISIGN_SQUARE_FILL = Symbol("larisign.square.fill")
""" 'larisign.square.fill' symbol """

BITCOINSIGN_CIRCLE = Symbol("bitcoinsign.circle")
""" 'bitcoinsign.circle' symbol """

BITCOINSIGN_CIRCLE_FILL = Symbol("bitcoinsign.circle.fill")
""" 'bitcoinsign.circle.fill' symbol """

BITCOINSIGN_SQUARE = Symbol("bitcoinsign.square")
""" 'bitcoinsign.square' symbol """

BITCOINSIGN_SQUARE_FILL = Symbol("bitcoinsign.square.fill")
""" 'bitcoinsign.square.fill' symbol """

N0_CIRCLE = Symbol("0.circle")
""" '0.circle' symbol """

N0_CIRCLE_FILL = Symbol("0.circle.fill")
""" '0.circle.fill' symbol """

N0_SQUARE = Symbol("0.square")
""" '0.square' symbol """

N0_SQUARE_FILL = Symbol("0.square.fill")
""" '0.square.fill' symbol """

N1_CIRCLE = Symbol("1.circle")
""" '1.circle' symbol """

N1_CIRCLE_FILL = Symbol("1.circle.fill")
""" '1.circle.fill' symbol """

N1_SQUARE = Symbol("1.square")
""" '1.square' symbol """

N1_SQUARE_FILL = Symbol("1.square.fill")
""" '1.square.fill' symbol """

N2_CIRCLE = Symbol("2.circle")
""" '2.circle' symbol """

N2_CIRCLE_FILL = Symbol("2.circle.fill")
""" '2.circle.fill' symbol """

N2_SQUARE = Symbol("2.square")
""" '2.square' symbol """

N2_SQUARE_FILL = Symbol("2.square.fill")
""" '2.square.fill' symbol """

N3_CIRCLE = Symbol("3.circle")
""" '3.circle' symbol """

N3_CIRCLE_FILL = Symbol("3.circle.fill")
""" '3.circle.fill' symbol """

N3_SQUARE = Symbol("3.square")
""" '3.square' symbol """

N3_SQUARE_FILL = Symbol("3.square.fill")
""" '3.square.fill' symbol """

N4_CIRCLE = Symbol("4.circle")
""" '4.circle' symbol """

N4_CIRCLE_FILL = Symbol("4.circle.fill")
""" '4.circle.fill' symbol """

N4_SQUARE = Symbol("4.square")
""" '4.square' symbol """

N4_SQUARE_FILL = Symbol("4.square.fill")
""" '4.square.fill' symbol """

N4_ALT_CIRCLE = Symbol("4.alt.circle")
""" '4.alt.circle' symbol """

N4_ALT_CIRCLE_FILL = Symbol("4.alt.circle.fill")
""" '4.alt.circle.fill' symbol """

N4_ALT_SQUARE = Symbol("4.alt.square")
""" '4.alt.square' symbol """

N4_ALT_SQUARE_FILL = Symbol("4.alt.square.fill")
""" '4.alt.square.fill' symbol """

N5_CIRCLE = Symbol("5.circle")
""" '5.circle' symbol """

N5_CIRCLE_FILL = Symbol("5.circle.fill")
""" '5.circle.fill' symbol """

N5_SQUARE = Symbol("5.square")
""" '5.square' symbol """

N5_SQUARE_FILL = Symbol("5.square.fill")
""" '5.square.fill' symbol """

N6_CIRCLE = Symbol("6.circle")
""" '6.circle' symbol """

N6_CIRCLE_FILL = Symbol("6.circle.fill")
""" '6.circle.fill' symbol """

N6_SQUARE = Symbol("6.square")
""" '6.square' symbol """

N6_SQUARE_FILL = Symbol("6.square.fill")
""" '6.square.fill' symbol """

N6_ALT_CIRCLE = Symbol("6.alt.circle")
""" '6.alt.circle' symbol """

N6_ALT_CIRCLE_FILL = Symbol("6.alt.circle.fill")
""" '6.alt.circle.fill' symbol """

N6_ALT_SQUARE = Symbol("6.alt.square")
""" '6.alt.square' symbol """

N6_ALT_SQUARE_FILL = Symbol("6.alt.square.fill")
""" '6.alt.square.fill' symbol """

N7_CIRCLE = Symbol("7.circle")
""" '7.circle' symbol """

N7_CIRCLE_FILL = Symbol("7.circle.fill")
""" '7.circle.fill' symbol """

N7_SQUARE = Symbol("7.square")
""" '7.square' symbol """

N7_SQUARE_FILL = Symbol("7.square.fill")
""" '7.square.fill' symbol """

N8_CIRCLE = Symbol("8.circle")
""" '8.circle' symbol """

N8_CIRCLE_FILL = Symbol("8.circle.fill")
""" '8.circle.fill' symbol """

N8_SQUARE = Symbol("8.square")
""" '8.square' symbol """

N8_SQUARE_FILL = Symbol("8.square.fill")
""" '8.square.fill' symbol """

N9_CIRCLE = Symbol("9.circle")
""" '9.circle' symbol """

N9_CIRCLE_FILL = Symbol("9.circle.fill")
""" '9.circle.fill' symbol """

N9_SQUARE = Symbol("9.square")
""" '9.square' symbol """

N9_SQUARE_FILL = Symbol("9.square.fill")
""" '9.square.fill' symbol """

N9_ALT_CIRCLE = Symbol("9.alt.circle")
""" '9.alt.circle' symbol """

N9_ALT_CIRCLE_FILL = Symbol("9.alt.circle.fill")
""" '9.alt.circle.fill' symbol """

N9_ALT_SQUARE = Symbol("9.alt.square")
""" '9.alt.square' symbol """

N9_ALT_SQUARE_FILL = Symbol("9.alt.square.fill")
""" '9.alt.square.fill' symbol """

N00_CIRCLE = Symbol("00.circle")
""" '00.circle' symbol """

N00_CIRCLE_FILL = Symbol("00.circle.fill")
""" '00.circle.fill' symbol """

N00_SQUARE = Symbol("00.square")
""" '00.square' symbol """

N00_SQUARE_FILL = Symbol("00.square.fill")
""" '00.square.fill' symbol """

N01_CIRCLE = Symbol("01.circle")
""" '01.circle' symbol """

N01_CIRCLE_FILL = Symbol("01.circle.fill")
""" '01.circle.fill' symbol """

N01_SQUARE = Symbol("01.square")
""" '01.square' symbol """

N01_SQUARE_FILL = Symbol("01.square.fill")
""" '01.square.fill' symbol """

N02_CIRCLE = Symbol("02.circle")
""" '02.circle' symbol """

N02_CIRCLE_FILL = Symbol("02.circle.fill")
""" '02.circle.fill' symbol """

N02_SQUARE = Symbol("02.square")
""" '02.square' symbol """

N02_SQUARE_FILL = Symbol("02.square.fill")
""" '02.square.fill' symbol """

N03_CIRCLE = Symbol("03.circle")
""" '03.circle' symbol """

N03_CIRCLE_FILL = Symbol("03.circle.fill")
""" '03.circle.fill' symbol """

N03_SQUARE = Symbol("03.square")
""" '03.square' symbol """

N03_SQUARE_FILL = Symbol("03.square.fill")
""" '03.square.fill' symbol """

N04_CIRCLE = Symbol("04.circle")
""" '04.circle' symbol """

N04_CIRCLE_FILL = Symbol("04.circle.fill")
""" '04.circle.fill' symbol """

N04_SQUARE = Symbol("04.square")
""" '04.square' symbol """

N04_SQUARE_FILL = Symbol("04.square.fill")
""" '04.square.fill' symbol """

N05_CIRCLE = Symbol("05.circle")
""" '05.circle' symbol """

N05_CIRCLE_FILL = Symbol("05.circle.fill")
""" '05.circle.fill' symbol """

N05_SQUARE = Symbol("05.square")
""" '05.square' symbol """

N05_SQUARE_FILL = Symbol("05.square.fill")
""" '05.square.fill' symbol """

N06_CIRCLE = Symbol("06.circle")
""" '06.circle' symbol """

N06_CIRCLE_FILL = Symbol("06.circle.fill")
""" '06.circle.fill' symbol """

N06_SQUARE = Symbol("06.square")
""" '06.square' symbol """

N06_SQUARE_FILL = Symbol("06.square.fill")
""" '06.square.fill' symbol """

N07_CIRCLE = Symbol("07.circle")
""" '07.circle' symbol """

N07_CIRCLE_FILL = Symbol("07.circle.fill")
""" '07.circle.fill' symbol """

N07_SQUARE = Symbol("07.square")
""" '07.square' symbol """

N07_SQUARE_FILL = Symbol("07.square.fill")
""" '07.square.fill' symbol """

N08_CIRCLE = Symbol("08.circle")
""" '08.circle' symbol """

N08_CIRCLE_FILL = Symbol("08.circle.fill")
""" '08.circle.fill' symbol """

N08_SQUARE = Symbol("08.square")
""" '08.square' symbol """

N08_SQUARE_FILL = Symbol("08.square.fill")
""" '08.square.fill' symbol """

N09_CIRCLE = Symbol("09.circle")
""" '09.circle' symbol """

N09_CIRCLE_FILL = Symbol("09.circle.fill")
""" '09.circle.fill' symbol """

N09_SQUARE = Symbol("09.square")
""" '09.square' symbol """

N09_SQUARE_FILL = Symbol("09.square.fill")
""" '09.square.fill' symbol """

N10_CIRCLE = Symbol("10.circle")
""" '10.circle' symbol """

N10_CIRCLE_FILL = Symbol("10.circle.fill")
""" '10.circle.fill' symbol """

N10_SQUARE = Symbol("10.square")
""" '10.square' symbol """

N10_SQUARE_FILL = Symbol("10.square.fill")
""" '10.square.fill' symbol """

N11_CIRCLE = Symbol("11.circle")
""" '11.circle' symbol """

N11_CIRCLE_FILL = Symbol("11.circle.fill")
""" '11.circle.fill' symbol """

N11_SQUARE = Symbol("11.square")
""" '11.square' symbol """

N11_SQUARE_FILL = Symbol("11.square.fill")
""" '11.square.fill' symbol """

N12_CIRCLE = Symbol("12.circle")
""" '12.circle' symbol """

N12_CIRCLE_FILL = Symbol("12.circle.fill")
""" '12.circle.fill' symbol """

N12_SQUARE = Symbol("12.square")
""" '12.square' symbol """

N12_SQUARE_FILL = Symbol("12.square.fill")
""" '12.square.fill' symbol """

N13_CIRCLE = Symbol("13.circle")
""" '13.circle' symbol """

N13_CIRCLE_FILL = Symbol("13.circle.fill")
""" '13.circle.fill' symbol """

N13_SQUARE = Symbol("13.square")
""" '13.square' symbol """

N13_SQUARE_FILL = Symbol("13.square.fill")
""" '13.square.fill' symbol """

N14_CIRCLE = Symbol("14.circle")
""" '14.circle' symbol """

N14_CIRCLE_FILL = Symbol("14.circle.fill")
""" '14.circle.fill' symbol """

N14_SQUARE = Symbol("14.square")
""" '14.square' symbol """

N14_SQUARE_FILL = Symbol("14.square.fill")
""" '14.square.fill' symbol """

N15_CIRCLE = Symbol("15.circle")
""" '15.circle' symbol """

N15_CIRCLE_FILL = Symbol("15.circle.fill")
""" '15.circle.fill' symbol """

N15_SQUARE = Symbol("15.square")
""" '15.square' symbol """

N15_SQUARE_FILL = Symbol("15.square.fill")
""" '15.square.fill' symbol """

N16_CIRCLE = Symbol("16.circle")
""" '16.circle' symbol """

N16_CIRCLE_FILL = Symbol("16.circle.fill")
""" '16.circle.fill' symbol """

N16_SQUARE = Symbol("16.square")
""" '16.square' symbol """

N16_SQUARE_FILL = Symbol("16.square.fill")
""" '16.square.fill' symbol """

N17_CIRCLE = Symbol("17.circle")
""" '17.circle' symbol """

N17_CIRCLE_FILL = Symbol("17.circle.fill")
""" '17.circle.fill' symbol """

N17_SQUARE = Symbol("17.square")
""" '17.square' symbol """

N17_SQUARE_FILL = Symbol("17.square.fill")
""" '17.square.fill' symbol """

N18_CIRCLE = Symbol("18.circle")
""" '18.circle' symbol """

N18_CIRCLE_FILL = Symbol("18.circle.fill")
""" '18.circle.fill' symbol """

N18_SQUARE = Symbol("18.square")
""" '18.square' symbol """

N18_SQUARE_FILL = Symbol("18.square.fill")
""" '18.square.fill' symbol """

N19_CIRCLE = Symbol("19.circle")
""" '19.circle' symbol """

N19_CIRCLE_FILL = Symbol("19.circle.fill")
""" '19.circle.fill' symbol """

N19_SQUARE = Symbol("19.square")
""" '19.square' symbol """

N19_SQUARE_FILL = Symbol("19.square.fill")
""" '19.square.fill' symbol """

N20_CIRCLE = Symbol("20.circle")
""" '20.circle' symbol """

N20_CIRCLE_FILL = Symbol("20.circle.fill")
""" '20.circle.fill' symbol """

N20_SQUARE = Symbol("20.square")
""" '20.square' symbol """

N20_SQUARE_FILL = Symbol("20.square.fill")
""" '20.square.fill' symbol """

N21_CIRCLE = Symbol("21.circle")
""" '21.circle' symbol """

N21_CIRCLE_FILL = Symbol("21.circle.fill")
""" '21.circle.fill' symbol """

N21_SQUARE = Symbol("21.square")
""" '21.square' symbol """

N21_SQUARE_FILL = Symbol("21.square.fill")
""" '21.square.fill' symbol """

N22_CIRCLE = Symbol("22.circle")
""" '22.circle' symbol """

N22_CIRCLE_FILL = Symbol("22.circle.fill")
""" '22.circle.fill' symbol """

N22_SQUARE = Symbol("22.square")
""" '22.square' symbol """

N22_SQUARE_FILL = Symbol("22.square.fill")
""" '22.square.fill' symbol """

N23_CIRCLE = Symbol("23.circle")
""" '23.circle' symbol """

N23_CIRCLE_FILL = Symbol("23.circle.fill")
""" '23.circle.fill' symbol """

N23_SQUARE = Symbol("23.square")
""" '23.square' symbol """

N23_SQUARE_FILL = Symbol("23.square.fill")
""" '23.square.fill' symbol """

N24_CIRCLE = Symbol("24.circle")
""" '24.circle' symbol """

N24_CIRCLE_FILL = Symbol("24.circle.fill")
""" '24.circle.fill' symbol """

N24_SQUARE = Symbol("24.square")
""" '24.square' symbol """

N24_SQUARE_FILL = Symbol("24.square.fill")
""" '24.square.fill' symbol """

N25_CIRCLE = Symbol("25.circle")
""" '25.circle' symbol """

N25_CIRCLE_FILL = Symbol("25.circle.fill")
""" '25.circle.fill' symbol """

N25_SQUARE = Symbol("25.square")
""" '25.square' symbol """

N25_SQUARE_FILL = Symbol("25.square.fill")
""" '25.square.fill' symbol """

N26_CIRCLE = Symbol("26.circle")
""" '26.circle' symbol """

N26_CIRCLE_FILL = Symbol("26.circle.fill")
""" '26.circle.fill' symbol """

N26_SQUARE = Symbol("26.square")
""" '26.square' symbol """

N26_SQUARE_FILL = Symbol("26.square.fill")
""" '26.square.fill' symbol """

N27_CIRCLE = Symbol("27.circle")
""" '27.circle' symbol """

N27_CIRCLE_FILL = Symbol("27.circle.fill")
""" '27.circle.fill' symbol """

N27_SQUARE = Symbol("27.square")
""" '27.square' symbol """

N27_SQUARE_FILL = Symbol("27.square.fill")
""" '27.square.fill' symbol """

N28_CIRCLE = Symbol("28.circle")
""" '28.circle' symbol """

N28_CIRCLE_FILL = Symbol("28.circle.fill")
""" '28.circle.fill' symbol """

N28_SQUARE = Symbol("28.square")
""" '28.square' symbol """

N28_SQUARE_FILL = Symbol("28.square.fill")
""" '28.square.fill' symbol """

N29_CIRCLE = Symbol("29.circle")
""" '29.circle' symbol """

N29_CIRCLE_FILL = Symbol("29.circle.fill")
""" '29.circle.fill' symbol """

N29_SQUARE = Symbol("29.square")
""" '29.square' symbol """

N29_SQUARE_FILL = Symbol("29.square.fill")
""" '29.square.fill' symbol """

N30_CIRCLE = Symbol("30.circle")
""" '30.circle' symbol """

N30_CIRCLE_FILL = Symbol("30.circle.fill")
""" '30.circle.fill' symbol """

N30_SQUARE = Symbol("30.square")
""" '30.square' symbol """

N30_SQUARE_FILL = Symbol("30.square.fill")
""" '30.square.fill' symbol """

N31_CIRCLE = Symbol("31.circle")
""" '31.circle' symbol """

N31_CIRCLE_FILL = Symbol("31.circle.fill")
""" '31.circle.fill' symbol """

N31_SQUARE = Symbol("31.square")
""" '31.square' symbol """

N31_SQUARE_FILL = Symbol("31.square.fill")
""" '31.square.fill' symbol """

N32_CIRCLE = Symbol("32.circle")
""" '32.circle' symbol """

N32_CIRCLE_FILL = Symbol("32.circle.fill")
""" '32.circle.fill' symbol """

N32_SQUARE = Symbol("32.square")
""" '32.square' symbol """

N32_SQUARE_FILL = Symbol("32.square.fill")
""" '32.square.fill' symbol """

N33_CIRCLE = Symbol("33.circle")
""" '33.circle' symbol """

N33_CIRCLE_FILL = Symbol("33.circle.fill")
""" '33.circle.fill' symbol """

N33_SQUARE = Symbol("33.square")
""" '33.square' symbol """

N33_SQUARE_FILL = Symbol("33.square.fill")
""" '33.square.fill' symbol """

N34_CIRCLE = Symbol("34.circle")
""" '34.circle' symbol """

N34_CIRCLE_FILL = Symbol("34.circle.fill")
""" '34.circle.fill' symbol """

N34_SQUARE = Symbol("34.square")
""" '34.square' symbol """

N34_SQUARE_FILL = Symbol("34.square.fill")
""" '34.square.fill' symbol """

N35_CIRCLE = Symbol("35.circle")
""" '35.circle' symbol """

N35_CIRCLE_FILL = Symbol("35.circle.fill")
""" '35.circle.fill' symbol """

N35_SQUARE = Symbol("35.square")
""" '35.square' symbol """

N35_SQUARE_FILL = Symbol("35.square.fill")
""" '35.square.fill' symbol """

N36_CIRCLE = Symbol("36.circle")
""" '36.circle' symbol """

N36_CIRCLE_FILL = Symbol("36.circle.fill")
""" '36.circle.fill' symbol """

N36_SQUARE = Symbol("36.square")
""" '36.square' symbol """

N36_SQUARE_FILL = Symbol("36.square.fill")
""" '36.square.fill' symbol """

N37_CIRCLE = Symbol("37.circle")
""" '37.circle' symbol """

N37_CIRCLE_FILL = Symbol("37.circle.fill")
""" '37.circle.fill' symbol """

N37_SQUARE = Symbol("37.square")
""" '37.square' symbol """

N37_SQUARE_FILL = Symbol("37.square.fill")
""" '37.square.fill' symbol """

N38_CIRCLE = Symbol("38.circle")
""" '38.circle' symbol """

N38_CIRCLE_FILL = Symbol("38.circle.fill")
""" '38.circle.fill' symbol """

N38_SQUARE = Symbol("38.square")
""" '38.square' symbol """

N38_SQUARE_FILL = Symbol("38.square.fill")
""" '38.square.fill' symbol """

N39_CIRCLE = Symbol("39.circle")
""" '39.circle' symbol """

N39_CIRCLE_FILL = Symbol("39.circle.fill")
""" '39.circle.fill' symbol """

N39_SQUARE = Symbol("39.square")
""" '39.square' symbol """

N39_SQUARE_FILL = Symbol("39.square.fill")
""" '39.square.fill' symbol """

N40_CIRCLE = Symbol("40.circle")
""" '40.circle' symbol """

N40_CIRCLE_FILL = Symbol("40.circle.fill")
""" '40.circle.fill' symbol """

N40_SQUARE = Symbol("40.square")
""" '40.square' symbol """

N40_SQUARE_FILL = Symbol("40.square.fill")
""" '40.square.fill' symbol """

N41_CIRCLE = Symbol("41.circle")
""" '41.circle' symbol """

N41_CIRCLE_FILL = Symbol("41.circle.fill")
""" '41.circle.fill' symbol """

N41_SQUARE = Symbol("41.square")
""" '41.square' symbol """

N41_SQUARE_FILL = Symbol("41.square.fill")
""" '41.square.fill' symbol """

N42_CIRCLE = Symbol("42.circle")
""" '42.circle' symbol """

N42_CIRCLE_FILL = Symbol("42.circle.fill")
""" '42.circle.fill' symbol """

N42_SQUARE = Symbol("42.square")
""" '42.square' symbol """

N42_SQUARE_FILL = Symbol("42.square.fill")
""" '42.square.fill' symbol """

N43_CIRCLE = Symbol("43.circle")
""" '43.circle' symbol """

N43_CIRCLE_FILL = Symbol("43.circle.fill")
""" '43.circle.fill' symbol """

N43_SQUARE = Symbol("43.square")
""" '43.square' symbol """

N43_SQUARE_FILL = Symbol("43.square.fill")
""" '43.square.fill' symbol """

N44_CIRCLE = Symbol("44.circle")
""" '44.circle' symbol """

N44_CIRCLE_FILL = Symbol("44.circle.fill")
""" '44.circle.fill' symbol """

N44_SQUARE = Symbol("44.square")
""" '44.square' symbol """

N44_SQUARE_FILL = Symbol("44.square.fill")
""" '44.square.fill' symbol """

N45_CIRCLE = Symbol("45.circle")
""" '45.circle' symbol """

N45_CIRCLE_FILL = Symbol("45.circle.fill")
""" '45.circle.fill' symbol """

N45_SQUARE = Symbol("45.square")
""" '45.square' symbol """

N45_SQUARE_FILL = Symbol("45.square.fill")
""" '45.square.fill' symbol """

N46_CIRCLE = Symbol("46.circle")
""" '46.circle' symbol """

N46_CIRCLE_FILL = Symbol("46.circle.fill")
""" '46.circle.fill' symbol """

N46_SQUARE = Symbol("46.square")
""" '46.square' symbol """

N46_SQUARE_FILL = Symbol("46.square.fill")
""" '46.square.fill' symbol """

N47_CIRCLE = Symbol("47.circle")
""" '47.circle' symbol """

N47_CIRCLE_FILL = Symbol("47.circle.fill")
""" '47.circle.fill' symbol """

N47_SQUARE = Symbol("47.square")
""" '47.square' symbol """

N47_SQUARE_FILL = Symbol("47.square.fill")
""" '47.square.fill' symbol """

N48_CIRCLE = Symbol("48.circle")
""" '48.circle' symbol """

N48_CIRCLE_FILL = Symbol("48.circle.fill")
""" '48.circle.fill' symbol """

N48_SQUARE = Symbol("48.square")
""" '48.square' symbol """

N48_SQUARE_FILL = Symbol("48.square.fill")
""" '48.square.fill' symbol """

N49_CIRCLE = Symbol("49.circle")
""" '49.circle' symbol """

N49_CIRCLE_FILL = Symbol("49.circle.fill")
""" '49.circle.fill' symbol """

N49_SQUARE = Symbol("49.square")
""" '49.square' symbol """

N49_SQUARE_FILL = Symbol("49.square.fill")
""" '49.square.fill' symbol """

N50_CIRCLE = Symbol("50.circle")
""" '50.circle' symbol """

N50_CIRCLE_FILL = Symbol("50.circle.fill")
""" '50.circle.fill' symbol """

N50_SQUARE = Symbol("50.square")
""" '50.square' symbol """

N50_SQUARE_FILL = Symbol("50.square.fill")
""" '50.square.fill' symbol """

APPLELOGO = Symbol("applelogo")
""" 'applelogo' symbol """
