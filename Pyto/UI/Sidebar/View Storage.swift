//
//  View Storage.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 30-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

// MARK: - Storage

/// An item in the Recent section.
@available(iOS 13.4, *)
struct RecentItem {
    
    /// The URL of the file.
    var url: URL
    
    /// The View Controller to show when pressed.
    var viewController: ViewController
}

/// An object storing recent scripts in the disk.
@available(iOS 13.4, *)
public class RecentDataSource: ObservableObject {
    
    /// A block that will be called to create a code editor for editing the passed file.
    public var makeEditor: ((URL) -> UIViewController)?
    
    /// The only and shared instance.
    public static let shared = RecentDataSource()
    
    /// The file URLs of recently opened scripts.
    public var recent: [URL] {
        
        get {
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
        
        set {
            DispatchQueue.global().async {
                var data = [Data]()
                var names = [String]()
                
                for url in newValue.reversed() {
                    do {
                        if !names.contains(FileManager.default.displayName(atPath: url.path)) {
                            data.append(try url.bookmarkData())
                            names.append(FileManager.default.displayName(atPath: url.path))
                        }
                    } catch {
                        print(error.localizedDescription)
                    }
                }
                
                
                data = data.reversed().suffix(5)
                
                UserDefaults.standard.setValue(data, forKey: "recentScripts")
                
                DispatchQueue.main.async {
                    self.objectWillChange.send()
                }
            }
        }
    }
    
    var recentItems: [RecentItem] {
        var items = [RecentItem]()
        
        for item in recent {
            items.append(RecentItem(url: item, viewController: ViewController(viewController: makeEditor?(item) ?? UIViewController())))
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
    public var vc: UIHostingController<SidebarNavigation>?
}

/// A class storing the current view of the side bar navigation.
@available(iOS 14.0, *)
class CurrentViewStore {
    
    /// The container view.
    var navigation: SidebarNavigation?
    
    /// The current detail view controller.
    var currentView: AnyView?
}
