//
//  PyComplication.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 27-09-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import ClockKit
import WatchConnectivity

@available(iOS 14.0, *)
@objc class PyComplication: NSObject, Codable {
    
    enum Family: Int {
        case circular = 0
        case circularExtraLarge = 1
        case rectangular = 2
    }
    
    @objc static var updateInterval: Double = 0
    
    @objc var timestamp: Double = 0
    
    @objc static var sendObject: Any?
    
    @objc var views = [Int:WidgetView]()
    
    var date: Date? {
        if timestamp == 0 {
            return nil
        } else {
            return .init(timeIntervalSince1970: timestamp)
        }
    }
    
    @objc func addView(_ view: WidgetView, family: Int) {
        views[family] = view
    }
    
    @objc static func reload() {
        #if os(iOS)
        WCSession.default.transferCurrentComplicationUserInfo(["Reload":"All"])
        #endif
    }
    
    @objc static func reloadDescriptors() {
        #if os(iOS)
        WCSession.default.transferCurrentComplicationUserInfo(["Reload":"Descriptors"])
        #endif
    }
    
    enum Key: CodingKey {
        case views
        case timestamp
    }
    
    override init() {}
    
    required init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Key.self)
        views = try container.decode([Int:WidgetView].self, forKey: .views)
        timestamp = try container.decode(Double.self, forKey: .timestamp)
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Key.self)
<<<<<<< HEAD
        
        func encode() {
            try? container.encode(views, forKey: .views)
            try? container.encode(timestamp, forKey: .timestamp)
        }
        
        #if os(iOS)
        UITraitCollection(userInterfaceStyle: .dark).performAsCurrent {
            encode()
        }
        #else
        encode()
        #endif
=======
        try container.encode(views, forKey: .views)
        try container.encode(timestamp, forKey: .timestamp)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    }
}
