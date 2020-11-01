//
//  SamplesView.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 31-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

/// A class holding information about the selected item of a `SamplesView`.
@available(iOS 13.0, *)
class SelectedItemStore: ObservableObject {
    
    /// The window scene containing the samples view.
    var scene: UIWindowScene?
    
    private var item: URL?
    
    /// The selected folder's URL.
    var selectedItem: URL? {
        get {
            return item
        }
        
        set {
            let state = scene?.activationState
            if !(newValue == nil && (state != .foregroundActive && state != .foregroundInactive)) {
                item = newValue
                objectWillChange.send()
            }
        }
    }
}

var exampleShortcuts: [Shortcut] {
    do {
        let url: URL?
        if #available(iOS 14.0, *) {
            url = Bundle.main.url(forResource: "Shortcuts iOS 14", withExtension: "json")
        } else {
            url = Bundle.main.url(forResource: "Shortcuts", withExtension: "json")
        }
        
        guard let shortcutsURL = url else {
            return []
        }
        let shortcutsJSON = try Data(contentsOf: shortcutsURL)
        
        return try JSONDecoder().decode([Shortcut].self, from: shortcutsJSON)
    } catch {
        return []
    }
}

@available(iOS 13.4, *)
public struct SamplesView: View {
    
    public let hostController: UIViewController?
    
    public let shortcuts: [Shortcut]
    
    public let url: URL
    
    public let selectScript: ((URL) -> Void)
    
    public let title: String
    
    let displayMode: NavigationBarItem.TitleDisplayMode
    
    let contents: [URL]
    
    @ObservedObject var selectedItemStore = SelectedItemStore()
    
    public init(url: URL, title: String? = nil, selectScript: @escaping ((URL) -> Void), shortcuts: [Shortcut]? = nil, hostController: UIViewController? = nil) {
        
        self.url = url
        self.title = title ?? NSLocalizedString("samplesTitle", comment: "The title of the examples gallery")
        self.selectScript = selectScript
        self.shortcuts = shortcuts ?? exampleShortcuts
        self.hostController = hostController
        
        var samples = (try? FileManager.default.contentsOfDirectory(at: url, includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
        samples.sort { (a, _) -> Bool in
            return SamplesView.isDirectory(a)
        }
        
        if shortcuts?.isEmpty == false {
            samples.insert(URL(fileURLWithPath: "/Shortcuts"), at: 0)
        }
        
        self.contents = samples
        self.displayMode = (title == nil) ? .large : .inline
    }
    
    static func isDirectory(_ url: URL) -> Bool {
        var isDir: ObjCBool = false
        _ = FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir)
        return isDir.boolValue
    }
    
    public var body: some View {
        
        List(self.contents, id: \.path) { item in
            
            if item.path == "/Shortcuts" {
                ShortcutsView(shortcuts: self.shortcuts, hostController: self.hostController)
            } else {
                if SamplesView.isDirectory(item) {
                    NavigationLink(destination: SamplesView(url: item, title: item.lastPathComponent, selectScript: self.selectScript, shortcuts: [], hostController: self.hostController), tag: item, selection: self.$selectedItemStore.selectedItem) {
                        Image(systemName: "folder.fill")
                        Text(item.lastPathComponent)
                    }
                } else {
                    Button(action: {
                         self.selectScript(item)
                    }) {
                        HStack {
                            Image(systemName: "doc.fill").font(.system(size: 20))
                            Text(item.lastPathComponent)
                        }
                    }.onDrag { () -> NSItemProvider in
                        let provider = NSItemProvider(contentsOf: item) ?? NSItemProvider()
                        let activity = NSUserActivity(activityType: "PythonScript")
                        do {
                            activity.addUserInfoEntries(from: ["bookmarkData" : try item.bookmarkData()])
                        } catch {}
                        provider.registerObject(activity, visibility: .all)
                        return provider
                    }
                }
            }
        }.navigationBarTitle(Text(title), displayMode: displayMode)
    }
}

@available(iOS 13.4, *)
public struct SamplesNavigationView: View {
        
    public let hostController: UIViewController?
        
    public let url: URL
                
    public let shortcuts: [Shortcut]
    
    public let selectScript: ((URL) -> Void)
    
    public init(url: URL, selectScript: @escaping ((URL) -> Void), shortcuts: [Shortcut]? = nil, hostController: UIViewController? = nil) {
        self.url = url
        self.selectScript = selectScript
        self.shortcuts = shortcuts ?? exampleShortcuts
        self.hostController = hostController
        self.withoutNavigation = SamplesView(url: self.url, selectScript: self.selectScript, shortcuts: self.shortcuts, hostController: self.hostController)
    }
    
    let withoutNavigation: SamplesView
        
    public var body: some View {
        NavigationView {
            withoutNavigation.navigationBarItems(trailing: Button(action: {
                self.hostController?.dismiss(animated: true, completion: nil)
            }, label: {
                Text("done").fontWeight(.bold)
            }).hoverEffect())

        }
        .navigationViewStyle(StackNavigationViewStyle())
    }
}

@available(iOS 13.4, *)
public struct SamplesView_Previews: PreviewProvider {
    public static var previews: some View {
        SamplesNavigationView(url: URL(fileURLWithPath: "/Users/adrianlabbe/Desktop/Pyto/Pyto/Samples"), selectScript: { _ in }, shortcuts: [
            Shortcut(name: "Download Video", icon: UIImage(named: "download_video")!, sfSymbol: "square.and.arrow.down.fill", description: "Downloads a video with youtube_dl. youtube_dl must be installed from PyPi.", url: URL(string: "https://www.icloud.com/shortcuts/dc4b14506c5b487196366d1aa9b7cde7")!)
        ])
    }
}
