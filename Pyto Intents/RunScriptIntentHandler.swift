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
    
    func handle(intent: RunScriptIntent, completion: @escaping (RunScriptIntentResponse) -> Void) {
        let userActivity = NSUserActivity(activityType: "RunScriptIntent")
        do {
            if let fileURL = intent.script?.fileURL {
                let success = fileURL.startAccessingSecurityScopedResource()
                userActivity.userInfo = ["filePath" : try fileURL.bookmarkData(), "arguments" : intent.arguments ?? ""]
                if success {
                    fileURL.stopAccessingSecurityScopedResource()
                }
            }
        } catch {
            print(error.localizedDescription)
        }
        return completion(.init(code: .continueInApp, userActivity: userActivity))
    }
    
    func resolveScript(for intent: RunScriptIntent, with completion: @escaping (INFileResolutionResult) -> Void) {
        guard let file = intent.script else {
            return
        }
        return completion(.success(with: file))
    }
    
    func provideScriptOptions(for intent: RunScriptIntent, with completion: @escaping ([INFile]?, Error?) -> Void) {
        guard let docs = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto")?.appendingPathComponent("Shortcuts") else {
            return completion([], nil)
        }
        
        var files = [INFile]()
        
        do {
            for file in (try FileManager.default.contentsOfDirectory(atURL: docs, sortedBy: .created) ?? []) {
                let fileURL = docs.appendingPathComponent(file)
                files.append(INFile(fileURL: fileURL, filename: fileURL.lastPathComponent, typeIdentifier: "public.pyhon-script"))
            }
        } catch {
            return completion([], error)
        }
        
        completion(files.reversed(), nil)
    }
    
    func resolveArguments(for intent: RunScriptIntent, with completion: @escaping ([INStringResolutionResult]) -> Void) {
        var result = [INStringResolutionResult]()
        
        for arg in intent.arguments ?? [] {
            result.append(.success(with: arg))
        }
        
        completion(result)
    }
}
