//
//  ComplicationController.swift
//  Pyto Watch Extension
//
//  Created by Emma Labbé on 04-02-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import ClockKit
import WatchConnectivity
import SwiftUI

class ComplicationController: NSObject, CLKComplicationDataSource {
    
    static var cache = [Complication:ComplicationCache]()
    
    static var cachedIDs = [ComplicationWithDate : String]()
    
    func entry(for view: PyComplication, complication: CLKComplication) -> CLKComplicationTimelineEntry? {
        if complication.family == .graphicRectangular, let content = view.views[PyComplication.Family.rectangular.rawValue] {
            let template = CLKComplicationTemplateGraphicRectangularFullView(content.makeView)
            let timelineEntry = CLKComplicationTimelineEntry(date: view.date ?? Date(), complicationTemplate: template)
            return timelineEntry
        } else if complication.family == .graphicExtraLarge, let content = view.views[PyComplication.Family.circularExtraLarge.rawValue] {
            let template = CLKComplicationTemplateGraphicExtraLargeCircularView(content.makeView)
            let timelineEntry = CLKComplicationTimelineEntry(date: view.date ?? Date(), complicationTemplate: template)
            return timelineEntry
        } else if complication.family == .graphicCircular, let content = view.views[PyComplication.Family.circular.rawValue] {
            let template = CLKComplicationTemplateGraphicCircularView(content.makeView)
            let timelineEntry = CLKComplicationTimelineEntry(date: view.date ?? Date(), complicationTemplate: template)
            return timelineEntry
        } else {
            return nil
        }
    }
    
    // MARK: - Timeline Configuration
        
    func getComplicationDescriptors(handler: @escaping ([CLKComplicationDescriptor]) -> Void) {
        let `default` = CLKComplicationDescriptor(identifier: "runScript", displayName: "Run Script", supportedFamilies: [.graphicRectangular, .graphicExtraLarge, .graphicCircular])
        
        WCSession.default.sendMessage(["Get":"Descriptors"], replyHandler: { (result) in
            if let descriptors = result["Descriptors"] as? [String] {
                var clkDescriptors = [`default`]
                
                for descriptor in descriptors {
                    clkDescriptors.append(CLKComplicationDescriptor(identifier: descriptor, displayName: descriptor, supportedFamilies: [.graphicRectangular, .graphicExtraLarge, .graphicCircular]))
                }
                
                DispatchQueue.main.async {
                    handler(clkDescriptors)
                }
            } else {
                DispatchQueue.main.async {
                    handler([`default`])
                }
            }
        }, errorHandler: nil)
    }
    
    func getPrivacyBehavior(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationPrivacyBehavior) -> Void) {
        handler(.hideOnLockScreen)
    }
    
    // MARK: - Timeline Population
    
    func getAlwaysOnTemplate(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTemplate?) -> Void) {
        getLocalizableSampleTemplate(for: complication, withHandler: handler)
    }

    func getTimelineEndDate(for complication: CLKComplication, withHandler handler: @escaping (Date?) -> Void) {
        handler(.distantFuture)
    }
    
    func getTimelineEntries(for complication: CLKComplication, after date: Date, limit: Int, withHandler handler: @escaping ([CLKComplicationTimelineEntry]?) -> Void) {
        
        if complication.identifier == "runScript" || date.timeIntervalSinceNow > 60 {
            return handler(nil)
        }
        
        WCSession.default.sendMessage(["Called": "getTimelineEntries \(complication) \(date)"], replyHandler: nil, errorHandler: nil)
        
        var entries = [CLKComplicationTimelineEntry]()
        for view in ComplicationController.cache[Complication(complication)]?.sortedTimeline ?? [] {
            WCSession.default.sendMessage(["TimeInterval":view.date?.timeIntervalSince(date) ?? 0], replyHandler: nil, errorHandler: nil)
            if let viewDate = view.date, (viewDate.compare(date) == .orderedAscending || (viewDate.timeIntervalSince(date) >= 0 && viewDate.timeIntervalSince(date) < 5)) {
                if let entry = entry(for: view, complication: complication) {
                    if viewDate.timeIntervalSince(date) >= 0 && viewDate.timeIntervalSince(date) < 5 {
                        entry.date = viewDate.addingTimeInterval(5)
                    }
                    entries.append(entry)
                }
                if entries.count == limit {
                    break
                }
            }
        }
        
        if entries.count > 0 {
            WCSession.default.sendMessage(["Entries": entries.count], replyHandler: nil, errorHandler: nil)
            ComplicationController.cache[Complication(complication)]?.cachedTimeline = []
            handler(entries)
            return
        }
        
        let id: String
        let complicationWithDate = ComplicationWithDate(complication: Complication(complication), date: date)
        if let cachedID = ComplicationController.cachedIDs[complicationWithDate] {
            id = cachedID // Duplicated
        } else {
            id = UUID().uuidString
            ComplicationController.cachedIDs[complicationWithDate] = id
            
            WCSession.default.sendMessage([id: [date, limit, complication.identifier]], replyHandler: nil, errorHandler: { error in
                WKExtension.shared().scheduleBackgroundRefresh(withPreferredDate: Date().addingTimeInterval(60*20), userInfo: nil) { (error) in
                    if let error = error {
                        print(error.localizedDescription)
                    }
                }
            })
        }
        
        if SessionDelegate.shared.complicationsHandlers[id] == nil {
            SessionDelegate.shared.complicationsHandlers[id] = []
        }
        
        var handlers = SessionDelegate.shared.complicationsHandlers[id] ?? []
        handlers.append({ data in
            SessionDelegate.shared.complicationsHandlers[id] = nil
            do {
                let views = try JSONDecoder().decode([PyComplication].self, from: data)
                
                if ComplicationController.cache[Complication(complication)] == nil {
                    ComplicationController.cache[Complication(complication)] = ComplicationCache()
                }
                
                ComplicationController.cache[Complication(complication)]?.cachedTimeline = views
                var entries = [CLKComplicationTimelineEntry]()
                for view in views {
                    if let entry = self.entry(for: view, complication: complication) {
                        if entry.date.timeIntervalSince(date) >= 0 && entry.date.timeIntervalSince(date) < 5 {
                            entry.date.addTimeInterval(5)
                        }
                        entries.append(entry)
                    }
                }
                DispatchQueue.main.async {
                    handler(entries)
                }
            } catch {
                WCSession.default.sendMessage(["error":error.localizedDescription], replyHandler: nil, errorHandler: nil)
                DispatchQueue.main.async {
                    handler(nil)
                }
            }
        })
        SessionDelegate.shared.complicationsHandlers[id] = handlers
    }

    func getCurrentTimelineEntry(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTimelineEntry?) -> Void) {
        // Call the handler with the current timeline entry
        
        WCSession.default.sendMessage(["Called":"getCurrentTimelineEntry"], replyHandler: nil, errorHandler: nil)
        
        func passAppIcon() {
            if complication.family == .graphicRectangular {
                let text1 = CLKTextProvider(format: "Pyto")
                let text2 = CLKTextProvider(format: "Run Script.")
                let template = CLKComplicationTemplateGraphicRectangularStandardBody(headerTextProvider: text1, body1TextProvider: text2)
                let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
                handler(timelineEntry)
            } else if complication.family == .graphicExtraLarge {
                let template = CLKComplicationTemplateGraphicExtraLargeCircularImage(imageProvider: CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Extra Large")!))
                let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
                handler(timelineEntry)
            } else if complication.family == .graphicCircular {
                let template = CLKComplicationTemplateGraphicCircularImage(imageProvider: CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Circular")!))
                let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
                handler(timelineEntry)
            } else {
                handler(nil)
            }
        }
        
        func requestComplication() {
            
            if (ComplicationController.cache[Complication(complication)]?.cachedTimeline.count ?? 0) > 0 {
                
                var i = 0
                for view in ComplicationController.cache[Complication(complication)]?.sortedTimeline.reversed() ?? [] {
                    if let date = view.date, date.compare(Date()) == .orderedDescending {
                        handler(entry(for: view, complication: complication))
                        WCSession.default.sendMessage(["sent":i], replyHandler: nil, errorHandler: nil)
                        return
                    }
                    i += 1
                }
            } else {
                passAppIcon()
            }
            
        }
        
        if complication.identifier == "runScript" {
            passAppIcon()
            return
        }
        
        if WCSession.default.delegate == nil {
            SessionDelegate.shared.didActivate = requestComplication
            WCSession.default.delegate = SessionDelegate.shared
            WCSession.default.activate()
        } else {
            requestComplication()
        }
    }
    
    // MARK: - Placeholder Templates
    
    func getLocalizableSampleTemplate(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTemplate?) -> Void) {
        // This method will be called once per supported complication, and the results will be cached
        
        if complication.family == .graphicRectangular {
            let text1 = CLKTextProvider(format: "Pyto")
            let text2 = CLKTextProvider(format: "Run Script.")
            let template = CLKComplicationTemplateGraphicRectangularStandardBody(headerTextProvider: text1, body1TextProvider: text2)
            handler(template)
        } else if complication.family == .graphicExtraLarge {
            let template = CLKComplicationTemplateGraphicExtraLargeCircularImage(imageProvider: CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Extra Large")!))
            handler(template)
        } else if complication.family == .graphicCircular {
            let template = CLKComplicationTemplateGraphicCircularImage(imageProvider: CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Circular")!))
            handler(template)
        } else {
            handler(nil)
        }
    }
    
}
