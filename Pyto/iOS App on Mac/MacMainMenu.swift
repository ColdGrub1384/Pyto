//
//  setMacMainMenu.swift
//  Pyto
//
//  Created by administrator on 12/13/20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

@objc class MenuItem: NSObject {
    
    @objc var title: String
    
    @objc var key: String
    
    @objc var action: String
        
    init(title: String, key: String, action: String) {
        self.title = title
        self.key = key
        self.action = action
    }
}

@objc class MacMainMenu: UIResponder {
    
    @objc static let shared = MacMainMenu()
    
    private override init() {
        if #available(iOS 14.0, *) {
            self.objcEditorMenu = NSArray(array: MacMainMenu.editorMenu)
        } else {
            self.objcEditorMenu = NSArray(array: [])
        }
        
        super.init()
    }
    
    @available(iOS 14.0, *)
    static var editorMenu: [MenuItem] {
        return [
            MenuItem(title: Localizable.MenuItems.run, key: "r", action: "run:"),
            MenuItem(title: Localizable.Help.documentation, key: "d", action: "showDocs:"),
            MenuItem(title: Localizable.find, key: "f", action: "find:"),
        ]
    }
    
    @objc var objcEditorMenu: NSArray
    
    @available(iOS 14.0, *)
    var keyEditor: EditorSplitViewController? {
        for scene in UIApplication.shared.connectedScenes {
            guard let windowScene = scene as? UIWindowScene else {
                continue
            }
            
            if windowScene.activationState == .foregroundActive {
                return EditorView.EditorStore.perScene[windowScene]?.editor?.viewController as? EditorSplitViewController
            }
        }
        
        return nil
    }
    
    override func responds(to aSelector: Selector!) -> Bool {
        
        guard #available(iOS 14.0, *) else {
            return super.responds(to: aSelector)
        }
        
        if aSelector == #selector(run(_:)) {
            if let path = keyEditor?.editor?.document?.fileURL.path {
                return !Python.shared.isScriptRunning(path)
            } else {
                return false
            }
        } else if aSelector == #selector(showDocs(_:)) || aSelector == #selector(find(_:)) {
            return keyEditor != nil
        } else {
            return super.responds(to: aSelector)
        }
    }
    
    @objc func run(_ sender: Any) {
        if #available(iOS 14.0, *) {
            keyEditor?.runScript(sender)
        }
    }
    
    @objc func showDocs(_ sender: Any) {
        if #available(iOS 14.0, *) {
            keyEditor?.showDocs()
        }
    }
    
    @objc func find(_ sender: Any) {
        if #available(iOS 14.0, *) {
            keyEditor?.search()
        }
    }
}

func setMacMainMenu() {
    if #available(iOS 14.0, *) {
        guard ProcessInfo.processInfo.isiOSAppOnMac && Python.shared.isSetup else {
            return
        }
    } else {
        return
    }
    
    Python.shared.run(code: "from _set_mac_main_menu import set_menu; set_menu()")
}
