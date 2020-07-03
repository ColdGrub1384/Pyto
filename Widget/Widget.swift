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

struct Provider: TimelineProvider {
    
    typealias Entry = SimpleEntry
    
    func snapshot(with context: Context, completion: @escaping (Entry) -> ()) {
        let entry = SimpleEntry(date: Date(), scriptName: "Pyto", console: "", imageData: nil, urlBookmark: nil)
        completion(entry)
    }

    func timeline(with context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        
        var diskEntry: SimpleEntry?
        
        if let data = UserDefaults(suiteName: "group.pyto")?.value(forKey: "widgetEntry") as? Data {
            do {
                diskEntry = try JSONDecoder().decode(SimpleEntry.self, from: data)
            } catch {
                print(error.localizedDescription)
            }
        }
        
        let entry = diskEntry ?? SimpleEntry(date: Date(), scriptName: "Script", console: "", imageData: nil, urlBookmark: nil)

        let timeline = Timeline(entries: [entry], policy: .never)
        completion(timeline)
    }
}

struct PlaceholderView : View {
    var body: some View {
        WidgetEntryView(entry: SimpleEntry(date: Date(), scriptName: "Script", console: "Hello World!", imageData: UIImage(named: "plot")!.pngData(), urlBookmark: nil))
    }
}

struct WidgetEntryView : View {
    
    @Environment(\.widgetFamily) var family
    
    var entry: Provider.Entry

    var plot: some View {
        Image(uiImage: UIImage(data: entry.imageData ?? Data()) ?? UIImage())
            .resizable().aspectRatio(contentMode: .fit)
    }
    
    var contents: some View {
        VStack {
            HStack {
                Text(entry.console)
                    .font(.custom("Menlo", size: 12))
                if family == .systemLarge {
                    Spacer()
                }
            }.padding()
            
            if family == .systemLarge && entry.imageData == nil {
                Spacer()
            }
        }
    }
    
    var body: some View {
        var view = AnyView(VStack {
            
            HStack {
                
                Text(entry.scriptName)
                    .foregroundColor(.black)
                    .fontWeight(.bold)
                    .padding()
                Spacer()
                
            }
            .background(Color.green)
            
            Spacer()
            
            if family != .systemLarge {
                HStack {
                    
                    if family == .systemSmall {
                        if entry.imageData == nil {
                            contents
                        }
                    } else {
                        if entry.console != "" {
                            contents
                        }
                    }
                    
                    if entry.imageData != nil {
                        if family == .systemMedium {
                            Spacer()
                        }
                        plot
                        if family == .systemMedium && entry.console == "" {
                            Spacer()
                        }
                    }
                }
            } else {
                VStack {
                    if entry.console != "" {
                        contents
                    }
                    if entry.imageData != nil {
                        plot
                    }
                }
            }
            
            Spacer()
        })
        
        if let bookmark = entry.urlBookmark {
            view = AnyView(view.widgetURL(URL(string: "pyto://widget/\(bookmark.base64EncodedString().addingPercentEncoding(withAllowedCharacters: .urlPathAllowed) ?? "")")!))
        }
        
        return view
    }
}

@main
struct PytoWidget: Widget {
    private let kind: String = "LastScript"

    public var body: some WidgetConfiguration {
        StaticConfiguration(kind: kind, provider: Provider(), placeholder: PlaceholderView()) { entry in
            WidgetEntryView(entry: entry)
        }
        .configurationDisplayName("Last script")
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
