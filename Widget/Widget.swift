//
//  Widget.swift
//  Widget
//
//  Created by Adrian Labbé on 25-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WidgetKit
import SwiftUI
import Intents

// TODO: Localize

struct ScriptEntry: TimelineEntry {
    
    var date: Date
    
    var code: String
}

struct Provider: TimelineProvider {
    
    typealias Entry = ScriptEntry
    
    func snapshot(with context: Context, completion: @escaping (Entry) -> ()) {
        let entry = ScriptEntry(date: Date(), code: "")
        completion(entry)
    }

    func timeline(with context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        
        SetupPython()

        let timeline = Timeline(entries: [ScriptEntry(date: Date(), code: "")], policy: .never)
        completion(timeline)
    }
}

struct PlaceholderView : View {
    var body: some View {
        WidgetEntryView(entry: ScriptEntry(date: Date(), code: ""))
    }
}

struct WidgetEntryView : View {
    
    @Environment(\.widgetFamily) var family
    
    var entry: Provider.Entry
    
    @ObservedObject var widget = PyWidget.shared
    
    var body: some View {
                
        SetupPython()
        
        return GeometryReader { (geometry) -> AnyView in
            
            PyWidget.size = geometry.size
            
            if let snapshot = widget.snapshot {
                return AnyView(Image(uiImage: snapshot))
            } else {
                Python.shared.run(code: """
                print("Hello World")

                import pyto_ui as ui
                from pyto import __Class__

                print(ui.COLOR_RED)

                view = ui.View()
                view.background_color = ui.COLOR_RED

                __Class__("PyWidget").setView(view.__py_view__)
                """)
                
                return AnyView(Text(""))
            }
        }
    }
}

@main
struct PytoWidget: Widget {
    private let kind: String = "Script"

    public var body: some WidgetConfiguration {
        StaticConfiguration(kind: kind, provider: Provider(), placeholder: PlaceholderView()) { entry in
            WidgetEntryView(entry: entry)
        }
        .configurationDisplayName("Script")
        .description("See the output of the last script executed with Pyto.")
    }
}


struct Widget_Previews: PreviewProvider {
    
    static var previews: some View {
        Group {
            PlaceholderView()
                .previewContext(WidgetPreviewContext(family: .systemSmall))
            
            PlaceholderView()
                .previewContext(WidgetPreviewContext(family: .systemMedium))
            
            PlaceholderView()
                .previewContext(WidgetPreviewContext(family: .systemLarge))
        }
    }
}
