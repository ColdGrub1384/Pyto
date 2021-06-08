//
//  PyWidget.swift
//  WidgetExtension
//
//  Created by Emma Labbé on 11-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import WidgetKit
#if !WIDGET
import SwiftUI
#endif

/// A class for managing widgets timelines from Python.
@available(iOS 14.0, *)
@objc class PyWidget: NSObject {
    
    @objc static func breakpoint(_ value: String) {
        print(value)
    }
    
    @objc static func reload() {
        WidgetCenter.shared.reloadTimelines(ofKind: "Script")
    }
        
    #if MAIN
    /// Code called after a widget is shown.
    static var completionHandlers = [String:((ScriptEntry) -> Void)]()
    #endif
    
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
        print("Don't remove, I think that's causing bugs")
    }
    
    /// A dictionary of functions for creating timelines per their ID.
    static var makeTimeline = [String:[((Timeline<ScriptEntry>) -> ())]]()
        
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
    
    /// The path of the script running the widget.
    @objc var scriptPath: String?
    
    /// The bookmark data of the script running the widget.
    var bookmarkData: Data? {
        guard let path = scriptPath else {
            return nil
        }
        
        let url = URL(fileURLWithPath: path)
        
        return try? url.bookmarkData()
    }
    
    /// A view contained in the widget.
    var widgetViews: [WidgetFamily:WidgetView]?
    
    @objc func addView(_ view: WidgetView, family: Int) {
        if widgetViews == nil {
            widgetViews = [:]
        }
        if let widgetFamily = WidgetFamily(rawValue: family) {
            widgetViews?[widgetFamily] = view
        }
    }
    
    /// Takes a snapshot of `view` for the given widget family.
    ///
    /// - Parameters:
    ///     - family: The raw value of a `WidgetFamily`
    @objc func setSnapshot(_ family: Int) {
        
        let widgetFamily = WidgetFamily(rawValue: family) ?? .systemSmall
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            let renderer = UIGraphicsImageRenderer(bounds: CGRect(origin: .zero, size: size(for: widgetFamily)))
            self.snapshot[widgetFamily] = (renderer.image { rendererContext in
                self.view?.view.layer.render(in: rendererContext.cgContext)
            }, self.view?.view.backgroundColor ?? .systemBackground)
                
            semaphore.signal()
        }
        
        semaphore.wait()
    }
    
    @objc static func reloadWidgets(_ names: [String]) {
        RuntimeCommunicator.shared.widgetsToBeReloaded = names
        WidgetCenter.shared.reloadTimelines(ofKind: "Script")
    }
    
    private static var ids = [String]()
    
    /// The date of the widget in its timeline.
    @objc var timelineDateTimestamp: TimeInterval = 0
    
    /// Generates a timeline for the given widgets.
    ///
    /// - Parameters:
    ///     - widgetID: The Widget ID.
    ///     - widets: `PyWidget` objects containing the results of the script.
    ///     - reloadAfter: The delay before reloading the widget.
    @objc static func updateTimeline(_ widgetID: String, widgets: [PyWidget], reloadAfter: TimeInterval) {
        #if WIDGET
        guard !ids.contains(widgetID) else {
            return
        }
        
        ids.append(widgetID)
        
        var entries = [ScriptEntry]()
        for widget in widgets {
            entries.append(ScriptEntry(date: Date(timeIntervalSince1970: widget.timelineDateTimestamp), output: widget.output, snapshots: widget.snapshot, view: widget.widgetViews, code: widgetCode ?? "", bookmarkData: widget.bookmarkData))
        }

        let policy: TimelineReloadPolicy
        if reloadAfter == 0 {
            policy = .atEnd
        } else {
            let date = entries.last?.date.addingTimeInterval(reloadAfter) ?? Date()
            policy = .after(date)
        }
        let timeline = Timeline(entries: entries, policy: policy)
        
        for handler in makeTimeline[widgetID] ?? [] {
            handler(timeline)
        }
        
        #else
        
        guard let widget = widgets.first else {
            return
        }
        
        updateTimeline(widgetID, widget: widget)
        #endif
    }
    
    /// Generates a timeline for the given widget.
    ///
    /// - Parameters:
    ///     - widgetID: The Widget ID.
    ///     - widget: A `PyWidget` object containing the result of a script.
    @objc static func updateTimeline(_ widgetID: String, widget: PyWidget) {
        
        #if WIDGET
        guard !ids.contains(widgetID) else {
            return
        }
        
        ids.append(widgetID)
        #endif
        
        if Thread.current.isMainThread {
            DispatchQueue.global().async {
                self.updateTimeline(widgetID, widget: widget)
            }
            return
        }
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
                        
            var entry = ScriptEntry(date: Date(), output: widget.output, snapshots: widget.snapshot, view: widget.widgetViews, code: widgetCode ?? "", bookmarkData: widget.bookmarkData)
            #if MAIN
            entry.updateInterval = widget.updateInterval
            #endif
            let date = Date().addingTimeInterval(widget.updateInterval)
            let timeline = Timeline(entries: [entry], policy: .after(date))
            
            #if WIDGET            
            for handler in makeTimeline[widgetID] ?? [] {
                handler(timeline)
            }
            #elseif MAIN
            
            // Preview
            
            if let handler = PyWidget.completionHandlers[widgetID] {
                handler(entry)
            } else {
                let preview = WidgetPreview(entry: entry)
                let vc = UIHostingController(rootView: AnyView(preview))
                preview.viewControllerStore.vc = vc
                
                for scene in UIApplication.shared.connectedScenes {
                    
                    guard scene.activationState == .foregroundActive || scene.activationState == .foregroundInactive else {
                        continue
                    }
                    
                    if let window = (scene as? UIWindowScene)?.windows.first {
                        
                        window.topViewController?.present(vc, animated: true, completion: nil)
                        
                        break
                    }
                }
                
                reload()
            }
            #endif
            
            semaphore.signal()
        }
        
        semaphore.wait()
    }
    
    @objc static func removeWidget(_ key: String) {
        var saved = (UserDefaults.shared?.value(forKey: "savedWidgets") as? [String:Data]) ?? [String:Data]()
        saved[key] = nil
        UserDefaults.shared?.setValue(saved, forKey: "savedWidgets")
    }
    
    @objc static func addWidget(_ widget: PyWidget, key: String) {
        let entry = ScriptEntry(date: Date(), output: widget.output, snapshots: widget.snapshot, view: widget.widgetViews, code: widgetCode ?? "", bookmarkData: widget.bookmarkData)
        
        InAppWidgetsStore.shared.migrate()
        
        InAppWidgetsStore.shared.set(entry: entry, id: key)
        #if MAIN
        let task = BackgroundTask()
        task.startBackgroundTask()
        #endif
        WidgetCenter.shared.reloadTimelines(ofKind: "SetInApp")
        #if MAIN
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            task.stopBackgroundTask()
        }
        #endif
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
