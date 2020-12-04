//
//  RunScriptIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 30-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
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
    
    static func getScripts() -> [INFile] {
        guard let docs = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Shortcuts") else {
            return []
        }
        
        var files = [INFile]()
        
        do {
            for file in (try FileManager.default.contentsOfDirectory(atURL: docs, sortedBy: .created) ?? []) {
                let fileURL = docs.appendingPathComponent(file)
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
        
        let collection = INObjectCollection(items: RunScriptIntentHandler.getScripts())
        return completion(collection, nil)
    }
    #endif
    
<<<<<<< HEAD
    private var retry = true
    
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
<<<<<<< HEAD
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
        
        if !Bool(truncating: intent.showConsole ?? 0) {
            guard let script = url else {
                return
=======
                completion(RunScriptIntentResponse(code: .failure, userActivity: nil))
                return
            }
        }
        
        if !Bool(truncating: intent.showConsole ?? 0) {
            guard let script = url else {
                return completion(.init(code: .failure, userActivity: nil))
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
    
    func provideScriptOptions(for intent: RunScriptIntent, with completion: @escaping ([INFile]?, Error?) -> Void) {
        completion(RunScriptIntentHandler.getScripts(), nil)
    }
    
    func resolveArguments(for intent: RunScriptIntent, with completion: @escaping ([INStringResolutionResult]) -> Void) {
        var result = [INStringResolutionResult]()
        
        for arg in intent.arguments ?? [] {
            result.append(.success(with: arg))
        }
        
        completion(result)
    }
}
