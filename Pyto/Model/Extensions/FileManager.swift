//
//  FileManager.swift
//  Pyto
//
//  Created by Emma Labbé on 2/3/19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import Foundation

@objc extension FileManager {
    
    /// Returns the `URL` of the directory shared between targets.
    @objc var sharedDirectory: URL? {
        guard let url = containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Documents") else {
            return nil
        }
        
        if !fileExists(atPath: url.path) {
            do {
                try createDirectory(at: url, withIntermediateDirectories: true, attributes: nil)
            } catch {
                print(error.localizedDescription)
            }
        }
        
        return url
    }
}
