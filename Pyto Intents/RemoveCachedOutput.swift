//
//  RemoveCachedOutput.swift
//  Pyto
//
//  Created by Emma Labbé on 28-06-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

/// Removes output from other shortcuts.
func RemoveCachedOutput() {
    if let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") {
        do {
            try FileManager.default.removeItem(at: group.appendingPathComponent("ShortcutOutput.txt"))
        } catch {
            print(error.localizedDescription)
        }
        
        do {
            try FileManager.default.removeItem(at: group.appendingPathComponent("ShortcutPlots"))
        } catch {
            print(error.localizedDescription)
        }
    }
}
