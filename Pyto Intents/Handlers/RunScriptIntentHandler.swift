//
//  RunScriptIntentHandler.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 30-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Intents

fileprivate extension FileManager {

    enum ContentDate {
        case created, modified, accessed

        var resourceKey: URLResourceKey {
            switch self {
            case .created: return .creationDateKey
            case .modified: return .contentModificationDateKey
            case .accessed: return .contentAccessDateKey
            }
        }
    }

    func contentsOfDirectory(atURL url: URL, sortedBy: ContentDate, ascending: Bool = true, options: FileManager.DirectoryEnumerationOptions = [.skipsHiddenFiles]) throws -> [String]? {

        let key = sortedBy.resourceKey

        var files = try contentsOfDirectory(at: url, includingPropertiesForKeys: [key], options: options)

        try files.sort {

            let values1 = try $0.resourceValues(forKeys: [key])
            let values2 = try $1.resourceValues(forKeys: [key])

            if let date1 = values1.allValues.first?.value as? Date, let date2 = values2.allValues.first?.value as? Date {

                return date1.compare(date2) == (ascending ? .orderedAscending : .orderedDescending)
            }
            return true
        }
        return files.map { $0.lastPathComponent }
    }
}

class RunScriptIntentHandler: NSObject, RunScriptIntentHandling {
    
    static func getScripts(pathExtension: String = "py", includePackages: Bool = true) -> [INFile] {
        guard let docs = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Shortcuts") else {
            return []
        }
        
        var files = [INFile]()
        
        do {
            for file in (try FileManager.default.contentsOfDirectory(atURL: docs, sortedBy: .modified) ?? []) {
                let fileURL = docs.appendingPathComponent(file)
                
                guard fileURL.pathExtension.lowercased() == pathExtension else {
                    continue
                }
                
                if fileURL.lastPathComponent.hasSuffix(")") && fileURL.lastPathComponent.components(separatedBy: " (").first?.hasSuffix(pathExtension) == true, !includePackages {
                    continue
                }
                
                let data = try Data(contentsOf: fileURL)
                do {
                    let script = try JSONDecoder().decode(IntentScript.self, from: data)
                    files.append(INFile(data: script.bookmarkData, filename: fileURL.lastPathComponent, typeIdentifier: nil))
                } catch {
                    files.append(INFile(data: data, filename: fileURL.lastPathComponent, typeIdentifier: nil))
                }
            }
        } catch {
            return []
        }
        
        return files.reversed()
    }
    
    static func getPackages() -> [INFile] {
        guard let docs = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Shortcuts") else {
            return []
        }
        
        var files = [INFile]()
                
        do {
            for file in (try FileManager.default.contentsOfDirectory(atURL: docs, sortedBy: .modified) ?? []) {
                let fileURL = docs.appendingPathComponent(file)
                
                guard fileURL.lastPathComponent.hasSuffix(")") && fileURL.lastPathComponent.components(separatedBy: " (").first?.hasSuffix("py") == true else {
                    continue
                }
                
                let data = try Data(contentsOf: fileURL)
                do {
                    let script = try JSONDecoder().decode(IntentScript.self, from: data)
                    files.append(INFile(data: script.bookmarkData, filename: fileURL.lastPathComponent.slice(from: ".py (", to: ")") ?? fileURL.lastPathComponent, typeIdentifier: nil))
                } catch {
                    files.append(INFile(data: data, filename: fileURL.lastPathComponent, typeIdentifier: nil))
                }
            }
        } catch {
            return []
        }
        
        return files.reversed()
    }
    
    static func getCode() -> [INFile] {
        guard let docs = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Shortcuts") else {
            return []
        }
        
        var files = [INFile]()
        
        do {
            for file in (try FileManager.default.contentsOfDirectory(atURL: docs, sortedBy: .created) ?? []) {
                let fileURL = docs.appendingPathComponent(file)
                files.append(INFile(data: try fileURL.bookmarkData(), filename: fileURL.lastPathComponent, typeIdentifier: nil))
            }
        } catch {
            return []
        }
        
        return files.reversed()
    }
    
    #if !Xcode11
    @available(iOS 14.0, *)
    @available(iOSApplicationExtension 14.0, *)
    func provideScriptOptionsCollection(for intent: RunScriptIntent, with completion: @escaping (INObjectCollection<INFile>?, Error?) -> Void) {
        
        var scripts = Self.getScripts(includePackages: false)
        while scripts.count > 5 {
            scripts.remove(at: scripts.count-1)
        }
        
        let collection = INObjectCollection(sections: [
            INObjectSection(title: "Recents", items: scripts),
            INObjectSection(title: "Packages", items: Self.getPackages())
        ])
        return completion(collection, nil)
    }
    #endif
    
    private var retry = true
    
    func handle(intent: RunScriptIntent, completion: @escaping (RunScriptIntentResponse) -> Void) {
        let userActivity = NSUserActivity(activityType: "RunScriptIntent")
        do {
            if let fileURL = intent.script?.fileURL {
                let success = fileURL.startAccessingSecurityScopedResource()
                userActivity.userInfo = ["filePath" : try fileURL.bookmarkData(), "arguments" : intent.arguments ?? ""]
                if success {
                    fileURL.stopAccessingSecurityScopedResource()
                }
            } else if let data = intent.script?.data {
                userActivity.userInfo = ["filePath" : data, "arguments" : intent.arguments ?? ""]
            }
        } catch {
            print(error.localizedDescription)
        }
        
        RemoveCachedOutput()
        
        #if MAIN
        
        var url = intent.script?.fileURL
        
        if url == nil, let data = intent.script?.data {
            do {
                var isStale = false
                url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                _ = url?.startAccessingSecurityScopedResource()
            } catch {
                print(error.localizedDescription)
            }
        }
        
        if url == nil && retry { // URL from other device
            let scripts = RunScriptIntentHandler.getScripts()
            for script in scripts {
                if script.filename == intent.script?.filename {
                    let newIntent = RunScriptIntent()
                    newIntent.arguments = intent.arguments
                    newIntent.script = script
                    retry = false
                    self.handle(intent: newIntent, completion: completion)
                    return
                }
            }
        }
        
        retry = true
        
        guard url != nil else {
            return completion(RunScriptIntentResponse(code: .failure, userActivity: nil))
        }
        
        PyItemProvider.setShortcutsFiles(intent.items ?? [])
        
        if !Bool(truncating: intent.showConsole ?? 0) {
            guard let script = url else {
                return
            }
            
            RunShortcutsScript(at: script, arguments: intent.arguments ?? [])
            
            return completion(.init(code: .success, userActivity: nil))
        }
        
        #endif
        return completion(.init(code: .continueInApp, userActivity: userActivity))
    }
    
    func resolveScript(for intent: RunScriptIntent, with completion: @escaping (INFileResolutionResult) -> Void) {
        guard let file = intent.script else {
            return completion(.disambiguation(with: RunScriptIntentHandler.getScripts()))
        }
        return completion(.success(with: file))
    }
    
    func resolveArguments(for intent: RunScriptIntent, with completion: @escaping ([INStringResolutionResult]) -> Void) {
        var result = [INStringResolutionResult]()
        
        for arg in intent.arguments ?? [] {
            result.append(.success(with: arg))
        }
        
        completion(result)
    }
    
    func resolveItems(for intent: RunScriptIntent, with completion: @escaping ([INFileResolutionResult]) -> Void) {
        completion((intent.items ?? []).map({ INFileResolutionResult.success(with: $0) }))
    }
}
