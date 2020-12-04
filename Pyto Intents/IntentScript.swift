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
<<<<<<< HEAD
    
    /// The widget ID for runtime.
    var widgetID: String?
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
}
