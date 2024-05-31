import pyto_ui as ui
from .product_page import product_view
from ..data import PRODUCTS_UI_PATH
from ..products import IPHONE, IPAD, MAC, ALL, ProductLine, Product


class MainView(ui.View):
    """
    The list of products.
    """
    
    selection = ALL
    
    table_view: ui.TableView
    segmented_control: ui.SegmentedControl
    
    def make_cell(self, product: Product):
        """
        Returns a cell for the given product.
        """
             
        cell = ui.TableViewCell()
        cell.text_label.text = product.name
        cell.detail_text_label.text = product.url
        cell.image_view.image = ui.image_with_system_name(product.symbol)
        cell.accessory_type = ui.AccessoryType.DISCLOSURE_INDICATOR
        return cell
    
    def select_product_line(self, product_line: ProductLine):
        """
        Changes the content of the list to the given product line.
        """
        
        cells = list(map(self.make_cell, product_line.products))
        self.table_view.set_cells(cells)
    
    def ib_init(self):
        self.select_product_line(self.selection)
    
    @ui.ib_action
    def did_change_selection(self, sender: ui.SegmentedControl):
        """
        Change to content of the list to match selection.
        """
        
        match sender.selected_segment:
            case 0:
                self.selection = ALL
            case 1:
                self.selection = IPHONE
            case 2:
                self.selection = IPAD
            case 3:
                self.selection = MAC
        
        self.select_product_line(self.selection)
    
    @ui.ib_action
    def did_select_cell(self, section: ui.TableViewSection, index: int):
        section.table_view.deselect_row()
        
        # Open the product page
        product = self.selection.products[index]
        product_page = product_view(product)
        self.navigation_view.push(product_page)


def show_products():
    view = ui.read(PRODUCTS_UI_PATH)
    view.size = ui.SheetSize.FORM
    ui.show_view(view, ui.PresentationMode.NEW_SCENE)