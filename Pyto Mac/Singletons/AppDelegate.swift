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
    
    /// The menu item for running script.
    @IBOutlet weak var runMenuItem: NSMenuItem!
    
    /// Runs current editing script.
    @IBAction func run(_ sender: Any) {
        (NSApp.keyWindow?.contentViewController as? EditorViewController)?.run(self)
    }
    
    /// The menu item for stopping current running script.
    @IBOutlet weak var stopMenuItem: NSMenuItem!
    
    /// Stops current running script.
    @IBAction func stop(_ sender: Any) {
        Python.shared.isScriptRunning = false
    }
    
    /// Saves current editing document.
    @IBAction func saveDoc(_ sender: Any) {
        (NSApp.keyWindow?.contentViewController as? EditorViewController)?.document?.save(self)
    }
    
    // MARK: - Application delegate
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        runMenuItem.isEnabled = (!Python.shared.isScriptRunning && NSApp.keyWindow?.contentViewController is EditorViewController && !(NSApp.keyWindow?.contentViewController is REPLViewController))
        stopMenuItem.isEnabled = Python.shared.isScriptRunning
    }
    
    // MARK: - Menu delegate
    
    func menuWillOpen(_ menu: NSMenu) {
        for item in menu.items {
            item.isEnabled = (NSApp.keyWindow?.firstResponder is NSTextView)
        }
    }
}

