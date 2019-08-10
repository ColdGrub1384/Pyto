"""
A Table View with edition and navigation.
"""

import pyto_ui as ui
import webbrowser

class Item:
  
  def __init__(self, title, subtitle):
    self.title = title
    self.subtitle = subtitle
    
  def cell(self):
    cell = ui.TableViewCell(ui.TABLE_VIEW_CELL_STYLE_SUBTITLE)
    cell.text_label.text = self.title
    cell.detail_text_label.text = self.subtitle
    cell.accessory_type = ui.ACCESSORY_TYPE_DISCLOSURE_INDICATOR
    cell.removable, cell.movable = True, True
    return cell

def cells(items):
  cells = []
  for item in items:
    cells.append(item.cell())
  return cells

iphones = [
  Item("iPhone XS", "2018"),
  Item("iPhone Xr", "2018"),
  Item("iPhone X", "2017"),
  Item("iPhone 8", "2017"),
  Item("iPhone 7", "2016")
]

ipads = [
  Item("iPad Air", "2019"),
  Item("iPad Mini", "2019"),
  Item("iPad Pro", "2018"),
  Item("iPad 9.7", "2018"),
]

macs = [
  Item("MacBook Air", "2019"),
  Item("MacBook Pro", "2019"),
  Item("Mac Pro", "2019"),
  Item("Mac Mini", "2018"),
  Item("iMac Pro", "2017")
]

all_items = {
  ui.TableViewSection("iPhone", cells(iphones)) : iphones,
  ui.TableViewSection("iPad", cells(ipads)) : ipads,
  ui.TableViewSection("Mac", cells(macs)) : macs
}

def selected(section, cell_index):
  section.table_view.deselect_row()
  item = all_items[section][cell_index]
  
  view = ui.View()
  view.background_color = ui.COLOR_SYSTEM_BACKGROUND
  
  title_label = ui.Label(item.title)
  title_label.font = ui.Font.bold_system_font_of_size(40)
  title_label.size_to_fit()
  title_label.text_alignment = ui.TEXT_ALIGNMENT_CENTER
  title_label.width = view.width
  title_label.flex = [ui.FLEXIBLE_WIDTH]
  title_label.y = 30
  view.add_subview(title_label)
  
  parts = item.title.split()
  url = "https://www.apple.com/"+parts[0].lower()
  try:
    url = url+"-"+parts[1].lower()
  except IndexError:
    pass
  
  def show_more():
    webbrowser.open(url)
  
  button = ui.Button(title="Show more")
  button.size_to_fit()
  button.y = title_label.y+(button.width*2)
  button.center_x = view.width/2
  button.flex = [
    ui.FLEXIBLE_BOTTOM_MARGIN,
    ui.FLEXIBLE_TOP_MARGIN,
    ui.FLEXIBLE_LEFT_MARGIN,
    ui.FLEXIBLE_RIGHT_MARGIN
  ]
  button.action = show_more
  view.add_subview(button)
  
  section.table_view.push(view)
  
def deleted(section, cell_index):
  all_items[section].pop(cell_index)
  
def move(section, source_index, destination_index):
  item = all_items[section].pop(source_index)
  all_items[section].insert(destination_index, item)

for section in all_items.keys():
  section.did_select_cell = selected
  section.did_delete_cell = deleted
  section.did_move_cell = move

table_view = ui.TableView(sections=all_items.keys())
table_view.button_items = [table_view.edit_button_item]
ui.show_view(table_view, ui.PRESENTATION_MODE_SHEET)