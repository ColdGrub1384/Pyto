//
//  InAppWidgetsStore.swift
//  Pyto
//
//  Created by Emma Labbé on 15-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

@available(iOS 14.0, *)
class InAppWidgetsStore {
    
    static let shared = InAppWidgetsStore()
    
    private init() {}
    
    let directory = FileManager.default.sharedDirectory?.appendingPathComponent("In App Widgets")
    
    var allEntries: [String] {
        guard let dir = directory else {
            return []
        }
        
        var entries = [String]()
        
        for file in (try? FileManager.default.contentsOfDirectory(atPath: dir.path)) ?? [] {
            entries.append(((file as NSString).deletingPathExtension as NSString).lastPathComponent)
        }
        
        return entries
    }
    
    #if WIDGET || MAIN
    
    func get(_ widget: String) -> ScriptEntry? {
        guard let fileURL = directory?.appendingPathComponent(widget).appendingPathExtension("json") else {
            return nil
        }
        
        guard let data = try? Data(contentsOf: fileURL) else {
            return nil
        }
        
        do {
            let entry = try JSONDecoder().decode(ScriptEntry.self, from: data)
            return entry
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    func set(entry: ScriptEntry, id: String) {
        
        guard let url = directory?.appendingPathComponent(id).appendingPathExtension("json") else {
            return
        }
        
        if !FileManager.default.fileExists(atPath: url.deletingLastPathComponent().path) {
            try? FileManager.default.createDirectory(atPath: url.deletingLastPathComponent().path, withIntermediateDirectories: true, attributes: nil)
        }
        
        do {
            let data = try JSONEncoder().encode(entry)
            try data.write(to: url)
        } catch {
            print(error.localizedDescription)
        }
    }
    
    func migrate() {
        
        guard !UserDefaults.standard.bool(forKey: "migratedWidgetsDB") else {
            return
        }
        
        UserDefaults.standard.setValue(true, forKey: "migratedWidgetsDB")
        
        guard let url = FileManager.default.sharedDirectory?.appendingPathComponent("WidgetEntries.json") else {
            return
        }
        
        if !FileManager.default.fileExists(atPath: url.deletingLastPathComponent().path) {
            try? FileManager.default.createDirectory(atPath: url.deletingLastPathComponent().path, withIntermediateDirectories: true, attributes: nil)
        }
        
        guard let data = try? Data(contentsOf: url) else {
            return
        }
        
        do {
            let content = try JSONDecoder().decode([String : Data].self, from: data)
            for data in content {
                do {
                    let entry = try JSONDecoder().decode(ScriptEntry.self, from: data.value)
                    set(entry: entry, id: data.key)
                } catch {
                    continue
                }
            }
        } catch {
            return
        }
    }
    #endif
}
