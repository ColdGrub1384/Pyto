//
//  EditorViewController+Toolbar.swift
//  Pyto
//
//  Created by Emma on 12/27/20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import Dynamic

fileprivate let toolbarItemIdentifiers: [NSString] = ["toolbar.sidebar", "NSToolbarFlexibleSpaceItem", "toolbar.settings", "toolbar.editorActions", "toolbar.debug", "toolbar.run"]

fileprivate var toolbarI = 0

extension EditorViewController {
    
    @objc func windowShouldClose(_ window: NSObject?) -> Bool {
        defer {
            saveAsIfNeeded()
        }
        return (!isScriptInTemporaryLocation && !textView.text.isEmpty) || closeAfterSaving
    }
    
    var appKitWindow: Dynamic {
        let NSApp = Dynamic.NSApplication.sharedApplication
        let windows = NSApp.windows.asArray ?? NSArray()
        for window in windows {
            if Dynamic(window).toolbar.delegate == self {
                return Dynamic(window)
            }
        }
        
        return Dynamic(nil)
    }
    
    func setHasUnsavedChanges(_ flag: Bool) {
        appKitWindow.documentEdited = flag
    }
    
    func setupToolbarIfNeeded(windowScene: UIWindowScene?) {
        guard isiOSAppOnMac else {
            return
        }
        
        let titlebar = Dynamic(windowScene).titlebar
        
        let toolbar = Dynamic.NSToolbar(identifier: "editor.toolbar\(toolbarI)")
        toolbarI += 1
        toolbar.displayMode = 2
        
        toolbar.delegate = self
        
        titlebar.toolbar = toolbar
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
            
            guard self?.appKitWindow.asObject != nil else {
                return
            }
            
            timer.invalidate()
            
            self?.appKitWindow.delegate = self
            
            self?.appKitWindow.representedURL = self?.document?.fileURL
            
            if (self?.parent as? EditorSplitViewController)?.folder == nil {
                if toolbar.items.count == toolbarItemIdentifiers.count {
                    toolbar.removeItem(atIndex: 0)
                    toolbar.removeItem(atIndex: 0)
                }
            }
        })
    }
    
    @objc func toggleSidebar(_ sender: Any) {
        _ = splitViewController?.displayModeButtonItem.target?.perform(splitViewController!.displayModeButtonItem.action!, with: splitViewController?.displayModeButtonItem)
    }
    
    // MARK: - Toolbar delegate
    
    @objc func toolbarDefaultItemIdentifiers(_ toolbar: NSObject) -> [AnyObject] {
        return toolbarItemIdentifiers
    }

    @objc func toolbarAllowedItemIdentifiers(_ toolbar: NSObject) -> [AnyObject] {
        return self.toolbarDefaultItemIdentifiers(toolbar)
    }

    @objc func toolbarSelectableItemIdentifiers(_ toolbar: NSObject) -> [AnyObject] {
        return []
    }
    
    @objc func toolbar(_ toolbar: NSObject, itemForItemIdentifier itemIdentifier: String, willBeInsertedIntoToolbar flag: Bool) -> NSObject? {
        let iconImage: UIImage?
        let label: String
        let action: String
        if itemIdentifier.hasSuffix(".run") {
            if !Python.shared.isScriptRunning(document!.fileURL.path) {
                iconImage = UIImage(systemName: "play")
                label = Localizable.MenuItems.run
                action = "run"
            } else {
                iconImage = UIImage(systemName: "xmark")
                label = Localizable.interrupt
                action = "stop"
            }
        } else if itemIdentifier.hasSuffix(".settings") {
            iconImage = UIImage(systemName: "gear")
            label = Localizable.runtime
            action = "showRuntimeSettings:"
        } else if itemIdentifier.hasSuffix(".debug") {
            iconImage = UIImage(systemName: "ant")
            label = "PDB"
            action = "debug"
        } else if itemIdentifier.hasSuffix(".editorActions") {
            iconImage = UIImage(systemName: "list.bullet")
            label = Localizable.EditorActionsTableViewController.title
            action = "showEditorScripts:"
        } else if itemIdentifier.hasSuffix(".sidebar") {
            iconImage = UIImage(systemName: "sidebar.left")
            label = "Show Sidebar"
            action = "toggleSidebar:"
        } else {
            return nil
        }
                
        let toolbarItem = Dynamic.NSToolbarItem(itemIdentifier: itemIdentifier)
        
        toolbarItem.label = label
        toolbarItem.image = iconImage
        toolbarItem.target = self
        toolbarItem.action = NSSelectorFromString(action)
        
        if itemIdentifier.hasSuffix(".sidebar") {
            toolbarItem.isNavigational = true
        }
        
        if itemIdentifier.hasSuffix(".run") {
            runToolbarItem = toolbarItem.asObject
        }
        
        return toolbarItem.asObject
    }
}
