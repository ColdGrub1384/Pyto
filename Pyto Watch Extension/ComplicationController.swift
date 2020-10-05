//
//  ComplicationController.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 04-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import ClockKit
import WatchConnectivity
import SwiftUI

class ComplicationController: NSObject, CLKComplicationDataSource {
    
    static var cache = [CLKComplication:ComplicationCache]()
    
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
                
                handler(clkDescriptors)
            } else {
                handler([`default`])
            }
        }, errorHandler: nil)
    }
    
    func getPrivacyBehavior(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationPrivacyBehavior) -> Void) {
        handler(.hideOnLockScreen)
    }
    
    // MARK: - Timeline Population
    
    func getTimelineEndDate(for complication: CLKComplication, withHandler handler: @escaping (Date?) -> Void) {
        handler(.distantFuture)
    }
    
    func getTimelineEntries(for complication: CLKComplication, after date: Date, limit: Int, withHandler handler: @escaping ([CLKComplicationTimelineEntry]?) -> Void) {
        
        if complication.identifier == "runScript" {
            return handler(nil)
        }
        
        WCSession.default.sendMessage(["Called": "getTimelineEntries"], replyHandler: nil, errorHandler: nil)
        
        var entries = [CLKComplicationTimelineEntry]()
        for view in ComplicationController.cache[complication]?.sortedTimeline ?? [] {
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
            handler(entries)
            return
        }
        
        let id = UUID().uuidString
        SessionDelegate.shared.complicationsHandlers[id] = { data in
            SessionDelegate.shared.complicationsHandlers[id] = nil
            do {
                let views = try JSONDecoder().decode([PyComplication].self, from: data)
                
                if ComplicationController.cache[complication] == nil {
                    ComplicationController.cache[complication] = ComplicationCache()
                }
                
                ComplicationController.cache[complication]?.cachedTimeline.append(contentsOf: views)
                var entries = [CLKComplicationTimelineEntry]()
                for view in views {
                    if let entry = self.entry(for: view, complication: complication) {
                        if entry.date.timeIntervalSince(date) >= 0 && entry.date.timeIntervalSince(date) < 5 {
                            entry.date.addTimeInterval(5)
                        }
                        entries.append(entry)
                    }
                }
                handler(entries)
                //CLKComplicationServer.sharedInstance().reloadTimeline(for: complication)
            } catch {
                WCSession.default.sendMessage(["error":error.localizedDescription], replyHandler: nil, errorHandler: nil)
                handler(nil)
            }
        }
        WCSession.default.sendMessage([id: [date, limit, complication.identifier]], replyHandler: nil, errorHandler: nil)
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
            
            if (ComplicationController.cache[complication]?.cachedTimeline.count ?? 0) > 0 {
                
                var i = 0
                for view in ComplicationController.cache[complication]?.sortedTimeline.reversed() ?? [] {
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
