//
//  IntentScript.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 19-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

/// A script bookmark stored in the disk.
struct IntentScript: Codable {
    
    /// The bookmark data.
    var bookmarkData: Data
    
    /// The script content.
    var code: String
    
    /// The widget ID for runtime.
    var widgetID: String?
}
