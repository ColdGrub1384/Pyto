//
//  Breakpoint.swift
//  Pyto
//
//  Created by Emma on 20-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import Foundation

import SwiftUI

struct BreakpointsStore: Codable {
    var breakpoints: [Data: [Breakpoint]]
    
    static var shared: BreakpointsStore {
        get {
            let url = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("breakpoints.json")
            guard let data = try? Data(contentsOf: url) else {
                return BreakpointsStore(breakpoints: [:])
            }
            return (try? JSONDecoder().decode(BreakpointsStore.self, from: data)) ?? BreakpointsStore(breakpoints: [:])
        }
        
        set {
            let url = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("breakpoints.json")
            guard let data = try? JSONEncoder().encode(newValue) else {
                return
            }
            try? data.write(to: url)
        }
    }
    
    static func breakpoints(for url: URL) -> [Breakpoint] {
        for file in shared.breakpoints {
            do {
                var isStale = false
                let breakpointURL = try URL(resolvingBookmarkData: file.key, bookmarkDataIsStale: &isStale)
                
                if breakpointURL.resolvingSymlinksInPath().path == url.resolvingSymlinksInPath().path {
                    return file.value
                }
            } catch {
                continue
            }
        }
        
        return []
    }
    
    static func set(breakpoints: [Breakpoint], for url: URL) {
        var bookmarkData: Data!
        
        for file in shared.breakpoints {
            do {
                var isStale = false
                let breakpointURL = try URL(resolvingBookmarkData: file.key, bookmarkDataIsStale: &isStale)
                
                if url.resolvingSymlinksInPath().path == breakpointURL.resolvingSymlinksInPath().path {
                    bookmarkData = file.key
                    break
                }
            } catch {
                continue
            }
        }
        
        if bookmarkData == nil {
            guard let _bookmarkData = try? url.bookmarkData() else {
                return
            }
            
            bookmarkData = _bookmarkData
        }
        
        var store = shared
        store.breakpoints[bookmarkData] = breakpoints
        shared = store
    }
}

struct Breakpoint: Codable, Identifiable, Equatable {
    
    struct PythonBreakpoint: Codable {
        var file_path: String
        var lineno: Int
    }
    
    var pythonBreakpoint: PythonBreakpoint {
        guard let path = url?.path else {
            return PythonBreakpoint(file_path: "", lineno: lineno)
        }
        
        return PythonBreakpoint(file_path: path, lineno: lineno)
    }
    
    init(url: URL, lineno: Int, isEnabled: Bool = true) throws {
        urlBookmarkData = try url.bookmarkData()
        self.lineno = lineno
        self.isEnabled = isEnabled
    }
    
    var urlBookmarkData: Data
    var lineno: Int
    var isEnabled: Bool
    
    var url: URL? {
        var isStale = false
        return try? URL(resolvingBookmarkData: urlBookmarkData, bookmarkDataIsStale: &isStale)
    }
    
    var line: String? {
        guard let url = url else {
            return nil
        }
        
        do {
            _ = try url.checkResourceIsReachable()
        } catch {
            _ = url.startAccessingSecurityScopedResource()
        }
        
        guard let string = try? String(contentsOf: url) else {
            return nil
        }
        
        let components = string.components(separatedBy: "\n")
        guard components.indices.contains(lineno-1) else {
            return nil
        }
        
        var line = components[lineno-1]
        while line.hasPrefix(" ") || line.hasPrefix("\t") {
            line.removeFirst()
        }
        
        return line
    }
    
    var id = UUID()
}
