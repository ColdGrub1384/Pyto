//
//  DocumentationViewController+NSWindow.swift
//  Pyto
//
//  Created by Emma Labbé on 13-01-21.
//  Copyright © 2021 Adrian Labbé. All rights reserved.
//

import UIKit
import Dynamic

fileprivate let toolbarItemIdentifiers: [NSString] = ["toolbar.back", "toolbar.forward"]

extension DocumentationViewController {
    
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
    
    func setupToolbarIfNeeded(windowScene: UIWindowScene?) {
        guard isiOSAppOnMac else {
            return
        }
        
        let titlebar = Dynamic(windowScene).titlebar
        
        let toolbar = Dynamic.NSToolbar(identifier: "documentation.toolbar")
        toolbar.displayMode = 2
        
        toolbar.delegate = self
        
        titlebar.toolbar = toolbar
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
            
            guard self?.appKitWindow.asObject != nil else {
                return
            }
            
            timer.invalidate()
            
            self?.appKitWindow.delegate = self
        })
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
        
        let toolbarItem: Dynamic
        
        if itemIdentifier.hasSuffix(".back") {
            toolbarItem = Dynamic.NSToolbarItem.itemWithItemIdentifier(itemIdentifier, barButtonItem: goBackButton)
        } else if itemIdentifier.hasSuffix(".forward") {
            toolbarItem = Dynamic.NSToolbarItem.itemWithItemIdentifier(itemIdentifier, barButtonItem: goForwardButton)
        } else {
            return nil
        }
        
        toolbarItem.isNavigational = true
        
        return toolbarItem.asObject
    }
}
