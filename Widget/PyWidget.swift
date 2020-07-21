//
//  PyWidget.swift
//  WidgetExtension
//
//  Created by Adrian Labbé on 11-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import WidgetKit

/// A class for managing widgets timelines from Python.
@available(iOS 14.0, *)
@objc class PyWidget: NSObject {
    
    @objc static func breakpoint(_ value: String) {
        print(value)
    }
    
    /// Returns the size of a widget from a widget family.
    ///
    /// - Parameters:
    ///     - family: The raw value of a `WidgetFamily`
    ///
    /// - Returns: The size for the given family.
    @objc static func sizeForFamily(_ family: Int) -> CGSize {
        return size(for: WidgetFamily(rawValue: family) ?? .systemSmall)
    }
    
    /// Removes the given entry from `makeTimeline`.
    ///
    /// - Parameters:
    ///     - widgetID: The ID of the widget.
    @objc static func removeWidgetID(_ widgetID: String) {
        makeTimeline[widgetID] = nil
    }
    
    /// A dictionary of functions for creating timelines per their ID.
    static var makeTimeline = [String:((Timeline<ScriptEntry>) -> ())]()
        
    /// Code to run.
    @objc static var codeToRun = NSMutableArray()
    
    /// The widget actually running.
    @objc static var widgetCode: String?
    
    /// The snapshots associated with this widget.
    var snapshot = [WidgetFamily:(UIImage, UIColor)]()
    
    /// The output of the script associated with this widget.
    @objc var output = ""
    
    /// The view associated with this widget.
    @objc var view: PyView?
    
    /// A time interval indicating when a new timeline will be requested.
    @objc var updateInterval: Double = 0
    
    /// Takes a snapshot of `view` for the given widget family.
    ///
    /// - Parameters:
    ///     - family: The raw value of a `WidgetFamily`
    @objc func setSnapshot(_ family: Int) {
        
        let widgetFamily = WidgetFamily(rawValue: family) ?? .systemSmall
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
            let renderer = UIGraphicsImageRenderer(bounds: CGRect(origin: .zero, size: size(for: widgetFamily)))
            self.snapshot[widgetFamily] = (renderer.image { rendererContext in
                self.view?.view.layer.render(in: rendererContext.cgContext)
            }, self.view?.view.backgroundColor ?? .systemBackground)
                
            semaphore.signal()
        }
        
        semaphore.wait()
    }
    
    /// Generates a timeline for the given widget.
    ///
    /// - Parameters:
    ///     - widgetID: The Widget ID.
    ///     - widget: A `PyWidget` object containing the result of a script.
    @objc static func updateTimeline(_ widgetID: String, widget: PyWidget) {
        
        #if WIDGET
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
            let timeline = Timeline(entries: [ScriptEntry(date: Date(), output: widget.output, snapshots: widget.snapshot)], policy: .after(Date().addingTimeInterval(widget.updateInterval)))
            makeTimeline[widgetID]?(timeline)
            makeTimeline[widgetID] = nil
            
            print(PyWidget.codeToRun.count)
            
            /*if PyWidget.codeToRun.count == 0 || makeTimeline.isEmpty {
                exit(0) // So the next script has more free RAM
            }*/
            
            semaphore.signal()
        }
        
        semaphore.wait()
        #endif
    }
        
    @objc static func addWidget(_ widget: PyWidget, key: String) {
        let entry = ScriptEntry(date: Date(), output: widget.output, snapshots: widget.snapshot)
        do {
            let data = try JSONEncoder().encode(entry)
            
            var saved = (UserDefaults.shared?.value(forKey: "savedWidgets") as? [String:Data]) ?? [String:Data]()
            saved[key] = data
            
            UserDefaults.shared?.setValue(saved, forKey: "savedWidgets")
            
            WidgetCenter.shared.reloadAllTimelines()
        } catch {
            print(error.localizedDescription)
        }
    }
    
    static var savedWidgets: [String : ScriptEntry] {
        
        guard let dict = UserDefaults.shared?.value(forKey: "savedWidgets") as? [String:Data] else {
            return [:]
        }
        
        var savedWidgets = [String:ScriptEntry]()
        do {
            for (key, value) in dict {
                savedWidgets[key] = try JSONDecoder().decode(ScriptEntry.self, from: value)
            }
        } catch {
            print(error.localizedDescription)
        }
        
        return savedWidgets
    }
}
