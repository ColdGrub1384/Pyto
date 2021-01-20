//
//  AppDelegate+NSWindow.swift
//  Pyto
//
//  Created by Emma Labbé on 12-01-21.
//  Copyright © 2021 Adrian Labbé. All rights reserved.
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
}
