//
//  EditorViewController+Toolbar.swift
//  Pyto
//
//  Created by Emma on 12/27/20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import Dynamic

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
}
