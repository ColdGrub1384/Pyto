//
//  IntentScript.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 19-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

/// A script bookmark stored in the disk.
struct IntentScript: Codable {
    
    /// The bookmark data.
    var bookmarkData: Data
    
    /// The script content.
    var code: String
}
