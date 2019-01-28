//
//  AppDelegate.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 1/26/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

/// The app's delegate.
@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate, NSMenuDelegate {
    
    /// Opens find panel.
    @IBAction func find(_ sender: Any) {
        NSApp.sendAction(#selector(NSResponder.performTextFinderAction(_:)), to: nil, from: sender)
    }
    
    // MARK: - Application delegate
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        
        NotificationCenter.default.addObserver(EditorViewController.self, selector: #selector(EditorViewController.print(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)        
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }
    
    // MARK: - Menu delegate
    
    func menuWillOpen(_ menu: NSMenu) {
        for item in menu.items {
            item.isEnabled = (NSApp.keyWindow?.firstResponder is NSTextView)
        }
    }
}

