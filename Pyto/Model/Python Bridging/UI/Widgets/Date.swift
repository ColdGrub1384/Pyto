//
//  Date.swift
//  Pyto
//
//  Created by Adrian Labbé on 27-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

@objc class WidgetDate: WidgetText {
        
    override init() { super.init() }
    
    var date: Date?
    
    @objc func setDate(year: Int, month: Int, day: Int, hour: Int, minute: Int, second: Int) {
        date = Calendar.current.date(from: DateComponents(calendar: .current, timeZone: nil, era: nil, year: year, month: month, day: day, hour: hour, minute: minute, second: second, nanosecond: nil, weekday: nil, weekdayOrdinal: nil, quarter: nil, weekOfMonth: nil, weekOfYear: nil, yearForWeekOfYear: nil))
    }
    
    @objc var style = 0
    
    @available(iOS 14.0, *)
    var dateStyle: Text.DateStyle {
        
        switch style {
        case 0:
            return .date
        case 1:
            return .offset
        case 2:
            return .relative
        case 3:
            return .time
        case 4:
            return .timer
        default:
            return .date
        }
        
    }
    
    override var makeView: AnyView {
        
        #if os(iOS)
        let systemFontSize = UIFont.systemFontSize
        let label = UIColor.label
        #elseif os(watchOS)
        let systemFontSize = CGFloat(17)
        let label = UIColor.white
        #endif
        
        if #available(iOS 14.0, *) {
            return AnyView(Text(date ?? Date(), style: dateStyle)
                            .foregroundColor(Color(color ?? label))
                            .font(Font(font ?? UIFont.systemFont(ofSize: systemFontSize)))
                            .multilineTextAlignment(.center)
                            .background(Color(backgroundColor ?? UIColor.clear))
                            .cornerRadius(CGFloat(cornerRadius)))
        } else {
            return AnyView(Text("Introduced in iOS 14")) // That shouldn't be called anyways
        }
    }
    
    required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
        
        let container = try decoder.container(keyedBy: Keys.self)
        date = try container.decode(Date.self, forKey: .date)
        style = try container.decode(Int.self, forKey: .dateStyle)
    }
    
    override func encode(to encoder: Encoder) throws {
        try super.encode(to: encoder)
        
        var container = encoder.container(keyedBy: Keys.self)
        
        try container.encode(date, forKey: .date)
        try container.encode(style, forKey: .dateStyle)
    }
}

