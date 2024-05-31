from ..data import PRODUCT_PAGE_UI_PATH
from ..products import Product
import webbrowser
import pyto_ui as ui


class ProductView(ui.View):
    """
    The view containing the info of a product.
    """

    product: Product

    model_name: ui.Label
    
    symbol: ui.ImageView

    release: ui.Label
    
    processor: ui.Label
    
    link_button: ui.Button

    @ui.ib_action
    def open_link(self, sender: ui.Button):
        webbrowser.open(self.product.url)
    
    def set_product(self, product: Product):
        self.product = product
        self.title = product.product_line
        self.model_name.text = product.name
        self.symbol = ui.image_with_system_name(product.symbol)
        self.release.text = product.release
        self.processor = product.processor


view: ProductView = ui.read(PRODUCT_PAGE_UI_PATH).root_view


def product_view(product: Product) -> ui.View:
    view.set_product(product)
    return view
