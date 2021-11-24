//
//  RecentDataSource.swift
//  Pyto
//
//  Created by Emma on 13-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

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
    
    var didSetRecent: (() -> Void)?
    
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
                
                DispatchQueue.main.async { [weak self] in
                    self?.didSetRecent?()
                }
            }
        }
    }
}
