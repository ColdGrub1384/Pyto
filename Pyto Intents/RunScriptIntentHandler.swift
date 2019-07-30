//
//  RunScriptIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 30-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Intents

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
    
    func resolveArguments(for intent: RunScriptIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        guard let arguments = intent.arguments else {
            return completion(.success(with: ""))
        }
        
        return completion(.success(with: arguments))
    }
}
