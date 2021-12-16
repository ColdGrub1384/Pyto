//
//  PyItemProvider.swift
//  Pyto
//
//  Created by Emma on 06-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import Foundation
import Intents

@objc class PyItemProvider: PyWrapper {
    
    class ItemProvider: NSItemProvider {
        
        var fileURL: URL?
    }
    
    @objc static var shortcutItemProviders = [ItemProvider]()
    
    static func itemProvider(from file: INFile) -> ItemProvider? {
        if let url = file.fileURL {
            let itemProvider = ItemProvider(contentsOf: url)
            itemProvider?.fileURL = url
            itemProvider?.suggestedName = file.filename
            return itemProvider
        } else {
            let itemProvider = ItemProvider(item: file.data as NSSecureCoding, typeIdentifier: file.typeIdentifier ?? "public.item")
            itemProvider.suggestedName = file.filename
            return itemProvider
        }
    }
    
    static func setShortcutsFiles(_ files: [INFile]) {
        shortcutItemProviders = files.compactMap({ itemProvider(from: $0) })
    }
    
    @objc var itemProvider: ItemProvider {
        managed as! ItemProvider
    }
    
    @objc var types: [String] {
        itemProvider.registeredTypeIdentifiers
    }
    
    @objc var suggestedName: String? {
        itemProvider.suggestedName
    }
    
    @objc var path: String? {
        if let url = itemProvider.fileURL {
            do {
                if try !url.checkResourceIsReachable() {
                    _ = url.startAccessingSecurityScopedResource()
                }
            } catch {
                _ = url.startAccessingSecurityScopedResource()
            }
            
            return url.path
        }
        
        return nil
    }
    
    @objc func loadDataForTypeIdentifier(_ type: String) -> String? {
        var path: String?
        let semaphore = Python.Semaphore(value: 0)
        itemProvider.loadFileRepresentation(forTypeIdentifier: type) { url, _ in
            let newURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(url?.lastPathComponent ?? UUID().uuidString)
            if url != nil {
                try? FileManager.default.copyItem(at: url!, to: newURL)
                path = newURL.path
            }
            semaphore.signal()
        }
        semaphore.wait()
        return path
    }
}
