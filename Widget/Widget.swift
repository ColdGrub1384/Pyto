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

struct Provider: IntentTimelineProvider {
    
    typealias Intent = ScriptIntent
    
    typealias Entry = ScriptEntry
        
    func snapshot(for configuration: Intent, with context: Context, completion: @escaping (ScriptEntry) -> ()) {
        
        let entry = ScriptEntry(date: Date(), output: "No output", snapshots: [:])
        completion(entry)
    }

    func timeline(for configuration: ScriptIntent, with context: Context, completion: @escaping (Timeline<ScriptEntry>) -> ()) {
        
        if let category = configuration.category {
            
            guard let data = Data(base64Encoded: category.identifier ?? "") else {
                return
            }
            
            do {
                let entry = try JSONDecoder().decode(ScriptEntry.self, from: data)
                completion(Timeline(entries: [entry], policy: .never))
            } catch {
                print(error.localizedDescription)
            }
        } else {
            let id = UUID().uuidString
            
            guard let bookmarkData = configuration.script?.data else {
                return
            }
            
            do {
                var isStale = false
                let url = try URL(resolvingBookmarkData: bookmarkData, bookmarkDataIsStale: &isStale)
                _ = url.startAccessingSecurityScopedResource()
                
                let data = try Data(contentsOf: url)
                let script = try JSONDecoder().decode(IntentScript.self, from: data)
                PyWidget.widgetCode = script.code
                
                let code = """
                import widgets
                import sys
                import io
                import traceback
                from pyto import __Class__
                from outputredirector import Reader

                PyWidget = __Class__("PyWidget")

                console = ""

                def read(text):
                    global console
                    console += text
                    PyWidget.breakpoint(text)
                
                write = read

                standardOutput = Reader(read)
                standardOutput._buffer = io.BufferedWriter(standardOutput)
                standardOutput.buffer.write = write

                standardError = Reader(read)
                standardError._buffer = io.BufferedWriter(standardError)
                standardError.buffer.write = write

                sys.stdout = standardOutput
                sys.stderr = standardError

                widgets.__shown_view__ = False
                widgets.__widget_id__ = \"\(id)\"

                PyWidget.breakpoint("Will run")

                try:
                    exec(str(PyWidget.widgetCode))
                except:
                    console += traceback.format_exc()+"\\n"

                PyWidget.breakpoint("Doneeee")

                if not widgets.__shown_view__:
                    widget = PyWidget.alloc().init()
                    
                    if console.endswith("\\n"):
                        console = console[:-1]

                    widget.output = console
                    PyWidget.updateTimeline(\"\(id)\", widget=widget)
                """
                
                url.stopAccessingSecurityScopedResource()
                
                SetupPython()
                
                PyWidget.makeTimeline[id] = completion
                PyWidget.codeToRun.add(NSArray(array: [code, id]))
            } catch {
                print(error.localizedDescription)
            }
        }
    }
}

struct PlaceholderView : View {
    var body: some View {
        WidgetEntryView(entry: ScriptEntry(date: Date(), output: "No output", snapshots: [:]))
    }
}

struct WidgetEntryView : View {
    
    @Environment(\.widgetFamily) var family
        
    var entry: Provider.Entry
        
    var body: some View {
        HStack { () -> AnyView in
            if let snapshot = entry.snapshots[family] {
                print(snapshot.0.pngData()?.base64EncodedString() ?? "", terminator: "\n\n")
                return AnyView(Image(uiImage: snapshot.0).resizable().scaledToFill())
            } else {
                return AnyView(Text(entry.output).padding())
            }
        }.padding().background(Color(entry.snapshots[family]?.1 ?? UIColor.systemBackground))
    }
}

@main
struct PytoWidget: Widget {
    private let kind: String = "Script"

    public var body: some WidgetConfiguration {
        IntentConfiguration(kind: kind, intent: ScriptIntent.self, provider: Provider(), placeholder: PlaceholderView(), content: { entry in
            WidgetEntryView(entry: entry)
        })
        .configurationDisplayName("Script")
        .description("Two types of configuration are available.\n1) Running a script and showing its content.\n2) Setting the widget content in app.")
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
