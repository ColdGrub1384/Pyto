//
//  AppDelegate+NSWindow.swift
//  Pyto
//
//  Created by Emma Labbé on 12-01-21.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import Dynamic

extension AppDelegate {
    
    func appKitWindowDidBecomeKey(_ notification: Notification) {
        
        guard let object = notification.object else {
            return
        }
        
        guard type(of: notification.object!) == NSClassFromString("NSOpenPanel") else {
            return
        }
        
        let panel = Dynamic(object)
        panel.canChooseDirectories = true
    }
    
    func appKitWindowWillClose(_ notification: Notification) {
        let appKitWindow = Dynamic(notification.object)
        
        for window in UIApplication.shared.windows {
            if let editor = window.topViewController as? EditorSplitViewController {
                if editor.editor?.appKitWindow.asObject == appKitWindow.asObject {
                    editor.dismiss(animated: true, completion: nil)
                }
            }
        }
    }
}
