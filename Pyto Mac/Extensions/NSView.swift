//
//  NSView.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/12/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

extension NSView {
    
    /// Returns `true` if appearance is dark.
    var isDarkMode: Bool {
        
        if !Thread.current.isMainThread {
            let semaphore = DispatchSemaphore(value: 0)
            var isDarkMode = false
            DispatchQueue.main.async { // Run asynchronously with a semaphore because I think it crashes sometime synchronously
                isDarkMode = self.isDarkMode
                semaphore.signal()
            }
            semaphore.wait()
            return isDarkMode
        }
        
        if #available(OSX 10.14, *) {
            return effectiveAppearance.bestMatch(from: [.darkAqua, .aqua]) == .darkAqua
        }
        return false
    }
    
    /// Notification sent when dark mode is toggled. Passed object is a boolean that is `true` if dark mode is enabled.
    static var AppearanceDidChangeNotification: Notification.Name {
        return .init(rawValue: "NSAppearance did change")
    }
}
