//
//  ScriptEntry.swift
//  Pyto
//
//  Created by Emma Labbé on 18-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import WidgetKit
#if !os(macOS)
import UIKit
#endif

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
    
    #if !os(macOS)
    /// The snapshots.
    var snapshots: [WidgetFamily:(UIImage, UIColor)]
    
    /// A view contained in the widget.
    var view: [WidgetFamily:WidgetView]?
    #endif
    
    /// The code of the executed script.
    var code: String
    
    /// The bookmark data of the script running the widget.
    var bookmarkData: Data?
    
    /// A boolean indicating whether the console should be rendered as a placeholder.
    var isPlaceholder = false
    
    /// For widgets handled in app, the update interval.
    var updateInterval: TimeInterval?
    
    /// A boolean indicating whether the script content is set in app.
    var inApp = false
    
    /// Returns the URL to open the script.
    ///
    /// - Parameters:
    ///     - viewID: The ID of the view.
    ///
    /// - Returns: A deep link to Pyto.
    func url(viewID: String?) -> URL? {
        
        do {
            if let data = bookmarkData {
                var isStale = false
                let fileURL = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                
                if !fileURL.pathComponents.contains("PluginKitPlugin") {
                    let url = URL(string: "pyto://widget?bookmark=\(data.base64EncodedString().addingPercentEncoding(withAllowedCharacters: .urlHostAllowed) ?? "")\(viewID != nil ? "&link=\(viewID!.addingPercentEncoding(withAllowedCharacters: .urlHostAllowed) ?? viewID!)" : "")")
                    return url
                }                
            }
        } catch {
            print(error.localizedDescription)
        }
        
        let _code = self.code
        
        let code = """
        __name__ = "widget"

        \(viewID != nil ? "import widgets; widgets.link = \"\(viewID!.replacingOccurrences(of: "\"", with: "\\\""))\"; del widgets;" : "")

        \(_code)

        import widgets
        widgets.link = None
        """
        
        let url = URL(string: "pyto://x-callback/?code=\(code.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed) ?? "")")
        return url
    }
    
    enum Key: CodingKey {
        case snapshots
        case view
        case bookmarkData
        case updateInterval
        case output
        case date
        case code
    }
    
    #if !os(macOS)
    init(date: Date, output: String, snapshots: [WidgetFamily:(UIImage, UIColor)] = [:], view: [WidgetFamily:WidgetView]? = nil, code: String = "", bookmarkData: Data? = nil) {
        self.date = date
        self.output = output
        self.snapshots = snapshots
        self.view = view
        self.code = code
        self.bookmarkData = bookmarkData
    }
    #else
    init(date: Date, output: String, code: String = "", bookmarkData: Data? = nil) {
        self.date = date
        self.output = output
        self.code = code
        self.bookmarkData = bookmarkData
    }
    #endif
    
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Key.self)
        
        #if !os(macOS)
        var snapshots = [WidgetFamily:(UIImage, UIColor)]()
        
        let savedSnapshots = try container.decode([ScriptSnapshot].self, forKey: .snapshots)
        for snapshot in savedSnapshots {
                        
            let image = UIImage(data: snapshot.image) ?? UIImage()
            let color = UIColor.color(withData: snapshot.backgroundColor)
            
            snapshots[WidgetFamily(rawValue: snapshot.family) ?? .systemSmall] = (image, color)
        }
        
        do {
            let _view = try container.decode([Int:WidgetView].self, forKey: .view)
            
            var view = [WidgetFamily:WidgetView]()
            
            for __view in _view {
                view[WidgetFamily(rawValue: __view.key) ?? .systemSmall] = __view.value
            }
            
            self.view = view
        } catch {
            self.view = nil
        }
        #endif
        
        do {
            bookmarkData = try container.decode(Data.self, forKey: .bookmarkData)
        } catch {
            bookmarkData = nil
        }
        
        do {
            updateInterval = try container.decode(Double.self, forKey: .updateInterval)
        } catch {
            updateInterval = nil
        }
                
        output = try container.decode(String.self, forKey: .output)
        
        date = try container.decode(Date.self, forKey: .date)
       
        code = try container.decode(String.self, forKey: .code)
       
        #if !os(macOS)
        self.snapshots = snapshots
        #endif
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Key.self)
        
        #if !os(macOS)
        var snapshots = [ScriptSnapshot]()
        for snapshot in self.snapshots {
            snapshots.append(ScriptSnapshot(family: snapshot.key.rawValue, image: snapshot.value.0.pngData() ?? Data(), backgroundColor: snapshot.value.1.encode()))
        }
        
        var views = [Int:WidgetView]()
        for view in self.view ?? [:] {
            views[view.key.rawValue] = view.value
        }
        
        try container.encode(views, forKey: .view)
        try container.encode(snapshots, forKey: .snapshots)
        #endif
        
        try container.encode(bookmarkData, forKey: .bookmarkData)
        try container.encode(updateInterval, forKey: .updateInterval)
        try container.encode(output, forKey: .output)
        try container.encode(date, forKey: .date)
        try container.encode(code, forKey: .code)
    }
}
