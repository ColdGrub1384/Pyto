from rubicon.objc import ObjCClass, SEL
from mainthread import mainthread

NSApplication = ObjCClass("NSApplication")
NSMenu = ObjCClass("NSMenu")
NSMenuItem = ObjCClass("NSMenuItem")
MacMainMenu = ObjCClass("Pyto.MacMainMenu")

NSApp = NSApplication.sharedApplication

@mainthread
def set_menu():

    main_menu = NSApp.mainMenu
    
    if main_menu.numberOfItems > 6:
        return
    
    editor_menu_item = NSMenuItem.alloc().init()
    editor_menu = NSMenu.alloc().init()
    editor_menu.title = "Editor"
    editor_menu_item.submenu = editor_menu

    main_menu.insertItem(editor_menu_item, atIndex=4)

    for item in MacMainMenu.shared.objcEditorMenu:
        menu_item = NSMenuItem.alloc().initWithTitle(item.title, action=SEL(str(item.action)), keyEquivalent=item.key)
        menu_item.setTarget(MacMainMenu.shared)
        
        editor_menu.addItem(menu_item)
