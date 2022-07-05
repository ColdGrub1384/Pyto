//
//  DocumentationManager.swift
//  Pyto
//
//  Created by Emma on 14-03-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import Foundation
import SwiftSoup
import Zip
import SwiftUI

struct DownloadableDocumentation: Codable, Equatable, Identifiable {
    
    var name: String
    
    var tag: String
    
    var version: String
    
    var filename: String
    
    var id: String {
        tag
    }
}

struct DownloadableDocumentations: Codable {
    
    var recommended: [DownloadableDocumentation]
    
    var other: [DownloadableDocumentation]
}

/// A downloaded documentation.
struct Documentation: Identifiable {
    
    struct Bookmark: Codable, Identifiable {
        
        var id = UUID()
        
        var name: String
        
        var bookmarkData: Data?
        
        var parentBookmarkData: Data?
        
        var isFolder: Bool
        
        var bookmarkURL: URL? {
            get {
                guard let bookmarkData = bookmarkData else {
                    return nil
                }
                
                var isStale = false
                guard let url = try? URL(resolvingBookmarkData: bookmarkData, bookmarkDataIsStale: &isStale) else {
                    return nil
                }
                return url
            }
            
            set {
                guard let data = try? newValue?.bookmarkData() else {
                    bookmarkData = nil
                    return
                }
                
                bookmarkData = data
            }
        }
        
        var parentURL: URL? {
            get {
                guard let bookmarkData = parentBookmarkData else {
                    return nil
                }
                
                var isStale = false
                guard let url = try? URL(resolvingBookmarkData: bookmarkData, bookmarkDataIsStale: &isStale) else {
                    return nil
                }
                return url
            }
            
            set {
                guard let data = try? newValue?.bookmarkData() else {
                    parentBookmarkData = nil
                    return
                }
                
                parentBookmarkData = data
            }
        }
    }
    
    /// The name.
    var name: String
    
    /// The file URL to the index.html file.
    var url: URL
    
    /// The file URL to the selected HTML page or directory.
    var pageURL: URL?
    
    var parent: Any?
    
    var id = UUID()
    
    var title = ""
    
    func getVersion() -> String {
        for doc in (try? FileManager.default.contentsOfDirectory(at: DocumentationManager.documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
            let infoURL = doc.appendingPathComponent("pyto_documentation.json")
            guard let data = try? Data(contentsOf: infoURL) else {
                continue
            }
            guard let info = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                continue
            }
            
            if info.name == name {
                return info.version
            }
        }
        
        return "unknown version"
    }
    
    static var storedTitleCache: [URL:String] {
        get {
            guard let data = UserDefaults.standard.data(forKey: "titleCache") else {
                return [:]
            }
            
            return (try? JSONDecoder().decode([URL:String].self, from: data)) ?? [:]
        }
        
        set {
            guard let data = try? JSONEncoder().encode(newValue) else {
                return
            }
            
            UserDefaults.standard.set(data, forKey: "titleCache")
        }
    }
    
    static var titleCache = [URL:String]()
    
    static func getTitle(from fileURL: URL) -> String? {
        do {
            if let title = self.titleCache[fileURL] {
                return title
            }
            
            let content = try String(contentsOf: fileURL)
            guard let title = content.components(separatedBy: "\n").filter({ $0.contains("<h1") && $0.contains("</h1>")}).first else {
                return nil
            }
            
            let parser = try SwiftSoup.Parser.parseBodyFragment("<body>\(title)</body>", fileURL.absoluteString)
            let returnValue = try parser.getElementsByTag("h1").first()?.text().replacingOccurrences(of: "¶", with: "").replacingOccurrences(of: "", with: "").replacingOccurrences(of: "#", with: "")
            self.titleCache[fileURL] = returnValue
            return returnValue
        } catch {
            return nil
        }
    }
    
    mutating func setTitle() {
        
        let pageURL = self.pageURL ?? url
        
        guard title.isEmpty else {
            return
        }
        
        title = Self.getTitle(from: pageURL) ?? name
    }
    
    var children: [Documentation]? {
        
        guard pageURL == nil else {
            return nil
        }
        
        var children = [Documentation]()
        
        for file in (try? FileManager.default.contentsOfDirectory(at: (pageURL ?? url).deletingLastPathComponent(), includingPropertiesForKeys: nil, options: [])) ?? [] {
            
            var isDir: ObjCBool = false
            
            if file.pathExtension == "html" {
                let doc = Documentation(name: name, url: url, pageURL: file, parent: self)
                children.append(doc)
            } else if FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) && isDir.boolValue && FileManager.default.fileExists(atPath: file.appendingPathComponent("index.html").path) {
                let doc = Documentation(name: file.lastPathComponent, url: file.appendingPathComponent("index.html"), pageURL: nil, parent: self)
                children.append(doc)
            }
        }
        
        children = children.filter({ $0.pageURL?.lastPathComponent.hasPrefix("genindex-") != true })
        
        var docs = children.filter { a in a.pageURL != nil }
        docs = docs.sorted(by: { $0.title.compare($1.title, options: .numeric) == .orderedAscending })
        
        if let i = docs.firstIndex(where: { $0.pageURL?.lastPathComponent == "index.html" }) {
            let doc = docs.remove(at: i)
            docs.insert(doc, at: 0)
        }
        
        var folders = children.filter { a in a.pageURL == nil }
        folders = folders.sorted(by: { $0.title.compare($1.title, options: .numeric) == .orderedAscending })
        
        children = docs+folders
        
        return children.count > 0 ? children : nil
    }
}

class DocumentationManager: ObservableObject {
    
    // ~/Library
    //    / documentations
    //        / pyto
    //                / index.html ...
    //                / pyto_documentation.json
    
    static let documentationsURL = FileManager.default.urls(for: .libraryDirectory, in: .userDomainMask)[0].appendingPathComponent("documentations")
    
    let documentationsURL = documentationsURL
    
    var downloadableDocumentations: DownloadableDocumentations
    
    func update(setTitleCache: Bool = true) async {
        if setTitleCache {
            Documentation.titleCache = Documentation.storedTitleCache
        }
        await MainActor.run {
            downloadedDocumentations = getDownloadedDocumentations()
            nonDownloadedDocumentations = getNonDownloadedDocumentations()
            availableUpdates = getAvailableUpdates()
        }
    }
    
    @Published private(set) var nonDownloadedDocumentations = [DownloadableDocumentation]()
    
    private func getNonDownloadedDocumentations() -> [DownloadableDocumentation] {
        var nonDownloaded = downloadableDocumentations.recommended+downloadableDocumentations.other
        
        for doc in (try? FileManager.default.contentsOfDirectory(at: documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
            let downloadableInfoURL = doc.appendingPathComponent("pyto_documentation.json")
            guard let data = try? Data(contentsOf: downloadableInfoURL) else {
                continue
            }
            
            guard let downloadableInfo = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                continue
            }
            
            if let i = nonDownloaded.firstIndex(where: { $0.tag == downloadableInfo.tag }) {
                nonDownloaded.remove(at: i)
            }
        }
        
        return nonDownloaded
    }
    
    @Published private(set) var downloadedDocumentations = [Documentation]()
    
    private func getDownloadedDocumentations() -> [Documentation] {
        var documentations = [Documentation]()
        for doc in (try? FileManager.default.contentsOfDirectory(at: documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
            
            var isDir: ObjCBool = false
            guard FileManager.default.fileExists(atPath: doc.path, isDirectory: &isDir) && isDir.boolValue else {
                continue
            }
            
            let downloadableInfoURL = doc.appendingPathComponent("pyto_documentation.json")
            guard let data = try? Data(contentsOf: downloadableInfoURL) else {
                continue
            }
            
            guard let downloadableInfo = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                continue
            }
            
            var doc = Documentation(name: downloadableInfo.name, url: doc.appendingPathComponent("index.html"))
            doc.setTitle()
            documentations.append(doc)
        }
        
        return documentations
    }
    
    @Published private(set) var availableUpdates = [DownloadableDocumentation]()
    
    private func getAvailableUpdates() -> [DownloadableDocumentation] {
        var updates = [DownloadableDocumentation]()
        
        for doc in (try? FileManager.default.contentsOfDirectory(at: documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
            let downloadableInfoURL = doc.appendingPathComponent("pyto_documentation.json")
            guard let data = try? Data(contentsOf: downloadableInfoURL) else {
                continue
            }
            
            guard let downloadableInfo = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                continue
            }
            
            for downloadableDocumentation in downloadableDocumentations.recommended+downloadableDocumentations.other {
                if downloadableInfo.version != downloadableDocumentation.version && downloadableInfo.tag == downloadableDocumentation.tag {
                    updates.append(downloadableInfo)
                    break
                }
            }
        }
        
        return updates
    }
    
    func download(documentations: [DownloadableDocumentation], progress: Binding<Progress?>? = nil) async throws {
        let request = NSBundleResourceRequest(tags: Set(documentations.map({ $0.tag })), bundle: .main)
        
        if documentations.count == 1 {
            guard !downloadedDocumentations.contains(where: { $0.name == documentations[0].name }) && !availableUpdates.contains(where: { $0.name == documentations[0].name }) else {
                return
            }
        }
        
        await MainActor.run {
            progress?.wrappedValue = request.progress
        }
        
        if !FileManager.default.fileExists(atPath: documentationsURL.path) {
            try? FileManager.default.createDirectory(at: documentationsURL, withIntermediateDirectories: false, attributes: nil)
        }
        
        try await request.beginAccessingResources()
        for documentation in documentations {
            guard let zipURL = Bundle.main.url(forResource: documentation.filename, withExtension: nil) else {
                return
            }
            
            var directoryURL = try Zip.quickUnzipFile(zipURL)
            let folder = directoryURL
            directoryURL = directoryURL.appendingPathComponent(directoryURL.lastPathComponent)
            let dest = documentationsURL.appendingPathComponent(directoryURL.lastPathComponent)
            try? FileManager.default.removeItem(at: dest)
            try FileManager.default.moveItem(at: directoryURL, to: dest)
            try FileManager.default.removeItem(at: folder)
            
            try JSONEncoder().encode(documentation).write(to: dest.appendingPathComponent("pyto_documentation.json"))
            
            await MainActor.run {
                objectWillChange.send()
            }
            await update()
        }
        
        request.endAccessingResources()
    }
    
    func remove(documentation: DownloadableDocumentation) async throws {
        for doc in (try? FileManager.default.contentsOfDirectory(at: documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
            let downloadableInfoURL = doc.appendingPathComponent("pyto_documentation.json")
            guard let data = try? Data(contentsOf: downloadableInfoURL) else {
                continue
            }
            
            guard let downloadableInfo = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                continue
            }
            
            
            if downloadableInfo.tag == documentation.tag {
                try FileManager.default.removeItem(at: doc)
                break
            }
        }
        
        await MainActor.run {
            objectWillChange.send()
        }
        await update()
    }
    
    var bookmarks: [Documentation.Bookmark] {
        get {
            guard let data = UserDefaults.standard.data(forKey: "documentationBookmarks") else {
                return []
            }
            
            guard let bookmarks = try? JSONDecoder().decode([Documentation.Bookmark].self, from: data) else {
                return []
            }
            
            return bookmarks
        }
        
        set {
            guard let data = try? JSONEncoder().encode(newValue) else {
                return
            }
            
            objectWillChange.send()
            UserDefaults.standard.set(data, forKey: "documentationBookmarks")
        }
    }
    
    init() {
        
        if !FileManager.default.fileExists(atPath: documentationsURL.path) {
            try? FileManager.default.createDirectory(at: documentationsURL, withIntermediateDirectories: false, attributes: nil)
        }
        
        do {
            downloadableDocumentations = try JSONDecoder().decode(DownloadableDocumentations.self, from: try Data(contentsOf: Bundle.main.url(forResource: "docs", withExtension: "json")!))
        } catch {
            downloadableDocumentations = DownloadableDocumentations(recommended: [], other: [])
        }
                
        Task {
            await update()
        }
    }
}
