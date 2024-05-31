from dataclasses import dataclass
import json
from .data import PRODUCTS_DATA_PATH

@dataclass
class Product:
    """ A product and its info. """
    
    name: str
    processor: str
    url: str
    symbol: str
    release: str
    product_line: str


@dataclass
class ProductLine:
    """
    A line of products (iPhone, iPad, Mac...)
    """
    
    name: str
    url: str
    products: tuple[Product]
    

def object_hook(dictionary):
    """
    Converts the given dictionary to an array of product lines.
    """
    
    if isinstance(dictionary, list):
        # A list, convert its content
        return list(map(object_hook, dictionary))
    elif isinstance(dictionary, dict):
        # A dictionary, parse it and convert it to a Product or ProductLine
        if "products" in dictionary:
            name = dictionary["name"]
            url = dictionary["url"]
            products = object_hook(dictionary["products"])
            return ProductLine(name, url, products)
        else:
            name = dictionary["name"]
            processor = dictionary["processor"]
            url = dictionary["url"]
            symbol = dictionary["symbol"]
            release = dictionary["release"]
            product_line = dictionary["product_line"]
            return Product(name, processor, url, symbol, release, product_line)
    else:
        return dictionary


with open(PRODUCTS_DATA_PATH, "r") as f:
    PRODUCTS = json.load(f, object_hook=object_hook)


IPHONE = PRODUCTS[0]
IPAD   = PRODUCTS[1]
MAC    = PRODUCTS[2]


ALL = ProductLine(
    "All", 
    "https://apple.com",
    IPHONE.products + IPAD.products + MAC.products
)
