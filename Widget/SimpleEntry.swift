//
//  SimpleEntry.swift
//  Pyto
//
//  Created by Adrian Labbé on 26-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WidgetKit
import Foundation

struct SimpleEntry: TimelineEntry, Codable {
    let date: Date
    
    let scriptName: String
    
    let console: String
    
    let imageData: Data?
    
    let urlBookmark: Data?
}
