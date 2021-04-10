//
//  View Storage.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 30-06-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import SwiftUI

// MARK: - Storage

/// An item in the Recent section.
@available(iOS 14.0, *)
struct RecentItem {
    
    /// The URL of the file.
    var url: URL
    
    /// The View Controller to show when pressed.
    var makeViewController: ((ViewControllerStore?) -> ViewController)
}

/// An object storing recent scripts in the disk.
@available(iOS 14.0, *)
public class RecentDataSource: ObservableObject {
    
    /// A block that will be called to create a code editor for editing the passed file.
    public var makeEditor: ((URL) -> UIViewController)?
    
    /// The only and shared instance.
    public static let shared = RecentDataSource()
    
    private func makeRecents() -> [URL] {
        var urls = [URL]()
        for recent in UserDefaults.standard.array(forKey: "recentScripts") ?? [] {
            guard let data = recent as? Data else {
                continue
            }
            
            var isStale = false
            do {
                urls.append(try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale))
            } catch {
                print(error.localizedDescription)
            }
        }
        
        return urls
    }
    
    private var _recents: [URL]?
    
    var silent = false
    
    /// The file URLs of recently opened scripts.
    public var recent: [URL] {
        
        get {
            if let recents = _recents {
                return recents
            } else {
                _recents = makeRecents()
                return _recents!
            }
        }
        
        set {
            DispatchQueue.global().async {
                var data = [Data]()
                var names = [String]()
                
                for url in newValue.reversed() {
                    do {
                        if !names.contains(FileManager.default.displayName(atPath: url.path)) {
                            #if !SCREENSHOTS
                            data.append(try url.bookmarkData())
                            #endif
                            names.append(FileManager.default.displayName(atPath: url.path))
                        }
                    } catch {
                        print(error.localizedDescription)
                    }
                }
                
                
                data = data.reversed().suffix(5)
                
                UserDefaults.standard.setValue(data, forKey: "recentScripts")
                
                self._recents = self.makeRecents()
                
                if !self.silent {
                    DispatchQueue.main.async { [weak self] in
                        self?.objectWillChange.send()
                    }
                } else {
                    self.silent = false
                }
            }
        }
    }
    
    /// Returns the recent scripts.
    var recentItems: [RecentItem] {
        var items = [RecentItem]()
        
        for item in recent {
            items.append(RecentItem(url: item, makeViewController: { store in
                return ViewController(viewController: self.makeEditor?(item) ?? UIViewController(), viewControllerStore: store)
            }))
        }
        
        return items
    }
}

/// An object storing each sidebar's section expansion state in the disk.
@available(iOS 14.0, *)
class ExpansionState: ObservableObject {
    
    @AppStorage("sidebar.recentExpanded") var isRecentExpanded = true {
        didSet {
            objectWillChange.send()
        }
    }
    
    @AppStorage("sidebar.pythonExpanded") var isPythonExpanded = true {
        didSet {
            objectWillChange.send()
        }
    }
    
    @AppStorage("sidebar.resourcesExpanded") var isResourcesExpanded = true {
        didSet {
            objectWillChange.send()
        }
    }
    
    @AppStorage("sidebar.moreExpanded") var isMoreExpanded = false {
        didSet {
            objectWillChange.send()
        }
    }
}

/// An object for storing the View Controller associated with a SwiftUI view.
@available(iOS 14.0, *)
public class ViewControllerStore {
    
    /// The View Controller containing the SwiftUI view.
    public weak var vc: UIHostingController<AnyView>?
    
    /// A boolean indicating whether the sidebar is showing.
    public var showSidebar = false
    
    /// The window scene where the sidebar navigation is shown.
    public var scene: UIWindowScene?
}

/// A class storing the current view of the side bar navigation.
@available(iOS 14.0, *)
class CurrentViewStore {
    
    /// The container view.
    var navigation: SidebarNavigation?
    
    /// A boolean indicating whether the current view is an editor.
    var isEditor = false
    
    /// The current detail view controller.
    var currentView: AnyView?
    
    /// The scene state store.
    var sceneStateStore: SceneStateStore?
    
    /// Stored editors per URL.
    var editors = [URL: ViewController]()
}
