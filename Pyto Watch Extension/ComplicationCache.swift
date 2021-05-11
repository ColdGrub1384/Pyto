//
//  ComplicationCache.swift
//  Pyto Watch Extension
//
//  Created by Emma Labbé on 05-10-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import WatchKit
import WatchConnectivity

var lastScheduledRefresh: Date? {
    get {
        guard let timestamp = UserDefaults.standard.value(forKey: "lastScheduledRefresh") as? TimeInterval else {
            return nil
        }
        
        return Date(timeIntervalSince1970: timestamp)
    }
    
    set {
        UserDefaults.standard.setValue(newValue?.timeIntervalSince1970, forKey: "lastScheduledRefresh")
    }
}

class ComplicationCache {
    
    var cachedTimeline = [PyComplication]() {
        didSet {
            WCSession.default.sendMessage(["Set": "cachedTimeline"], replyHandler: nil, errorHandler: nil)
            if var date = sortedTimeline.first?.date {
                if date.timeIntervalSinceNow < 20*60 { // Less than 20 minutes
                    date = Date().addingTimeInterval(20*60)
                }
                
                if let refresh = lastScheduledRefresh, date.compare(refresh) != .orderedDescending {
                    WCSession.default.sendMessage(["Nein": [date, refresh]], replyHandler: nil, errorHandler: nil)
                    return
                }
                
                WCSession.default.sendMessage(["Schedule Background Task": date], replyHandler: nil, errorHandler: nil)
                
                lastScheduledRefresh = date
                
                WKExtension.shared().scheduleBackgroundRefresh(withPreferredDate: date, userInfo: nil) { (error) in
                    if let error = error {
                        WCSession.default.sendMessage(["Error": error.localizedDescription], replyHandler: nil, errorHandler: nil)
                    }
                }
            }
        }
    }
    
    var sortedTimeline: [PyComplication] {
        return cachedTimeline.sorted { (a, b) -> Bool in
            guard let aDate = a.date else {
                return false
            }
            
            guard let bDate = a.date else {
                return true
            }
            
            return aDate > bDate
        }.reversed()
    }
}
