"""
Edit a text file.

usage: [path]
    
"""

import pyto_ui as ui
import argparse
import os
from UIKit import UITextView, NSLayoutManager, NSTextContainer
from rubicon.objc import ObjCClass
from rubicon.objc.types import CGRect, CGRectMake
from mainthread import mainthread

CodeAttributedString = ObjCClass("CodeAttributedString")

class EditorContainerView(ui.View):
    
    def __init__(self, text_view: ui.TextView):
        super().__init__()
        
        self.background_color = ui.COLOR_SYSTEM_BACKGROUND
        
        text_view.flex = [ui.FLEXIBLE_WIDTH, ui.FLEXIBLE_HEIGHT]
        text_view.size = self.size
        self.add_subview(text_view)

class EditorTextView(ui.TextView):
    
    def __init__(self, file: str):
        super().__init__()
        self.file = file
        self.init()
        
        while self.__py_view__ is None:
            continue
        
        self.font = ui.Font("Menlo", 17)
        self.autocapitalization_type = ui.AUTO_CAPITALIZE_NONE
        self.autocorrection = False
        self.smart_quotes = False
        self.smart_dashes = False
        
        self.background_color = ui.Color.rgb(30/255, 30/255, 30/255)
    
    @mainthread
    def init(self):
        
        zero = CGRectMake(0, 0, 0, 0)
        
        storage = CodeAttributedString.alloc().init()
        storage.highlightr.setThemeToName("vs2015")
        
        name, extension = os.path.splitext(self.file)
        extension = extension[1:]
        storage.language = extension
        
        layout_manager = NSLayoutManager.alloc().init()
        storage.addLayoutManager(layout_manager)
        
        container = NSTextContainer.alloc().initWithSize(zero.size)
        layout_manager.addTextContainer(container)
        
        object = UITextView.alloc().initWithFrame(zero, textContainer=container)
        
        self.__py_view__.managed = object

def main():
    
    parser = argparse.ArgumentParser()
    parser.add_argument("file")
    args = parser.parse_args()
    file = args.file
    path = os.path.abspath(file)
    
    text_view = EditorTextView(file)
    text_view.title = file
    
    try:
        with open(path, "r") as f:
            text_view.text = f.read()
    except FileNotFoundError:
        pass
    
    ui.show_view(EditorContainerView(text_view), ui.PRESENTATION_MODE_FULLSCREEN)
    new_path = input(f"Save as [{file}] (^c to not save): ")
    new_path.replace(" ", "")
    new_path.replace("\t", "")
    
    if new_path != "":
        file = new_path
    
    with open(path, "w+") as f:
        f.write(text_view.text)
    
if __name__ == "__main__":
    main()