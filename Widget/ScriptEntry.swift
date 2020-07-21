//
//  ScriptEntry.swift
//  Pyto
//
//  Created by Adrian Labbé on 18-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WidgetKit
import UIKit

fileprivate struct ScriptSnapshot: Codable {
    
    var family: Int
    
    var image: Data
    
    var backgroundColor: Data
}

/// A widget entry.
@available(iOS 14.0, *)
struct ScriptEntry: TimelineEntry, Codable {
    
    var date: Date
    
    /// The output of the script.
    var output: String
        
    /// The snapshots.
    var snapshots: [WidgetFamily:(UIImage, UIColor)]
    
    enum Key: CodingKey {
        case snapshots
    }
    
    init(date: Date, output: String, snapshots: [WidgetFamily:(UIImage, UIColor)]) {
        self.date = date
        self.output = output
        self.snapshots = snapshots
    }
    
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Key.self)
        
        var snapshots = [WidgetFamily:(UIImage, UIColor)]()
        
        let savedSnapshots = try container.decode([ScriptSnapshot].self, forKey: .snapshots)
        for snapshot in savedSnapshots {
                        
            let image = UIImage(data: snapshot.image) ?? UIImage()
            let color = UIColor.color(withData: snapshot.backgroundColor)
            
            snapshots[WidgetFamily(rawValue: snapshot.family) ?? .systemSmall] = (image, color)
        }
        
        output = ""
        date = Date()
        self.snapshots = snapshots
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Key.self)
        
        var snapshots = [ScriptSnapshot]()
        for snapshot in self.snapshots {
            snapshots.append(ScriptSnapshot(family: snapshot.key.rawValue, image: snapshot.value.0.pngData() ?? Data(), backgroundColor: snapshot.value.1.encode()))
        }
        
        try container.encode(snapshots, forKey: .snapshots)
    }
}
