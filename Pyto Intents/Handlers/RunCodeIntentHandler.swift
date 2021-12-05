//
//  RunCodeIntentHandler.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 30-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Intents
#if MAIN
import UIKit
#endif

class RunCodeIntentHandler: NSObject, RunCodeIntentHandling {
    
    func handle(intent: RunCodeIntent, completion: @escaping (RunCodeIntentResponse) -> Void) {
        
        #if targetEnvironment(simulator)
        return completion(.init(code: .success, userActivity: nil))
        #else
        
        let userActivity = NSUserActivity(activityType: "RunCodeIntent")
        guard let code = intent.code else {
            return completion(.init(code: .failure, userActivity: nil))
        }
        
        userActivity.userInfo = ["code" : code, "arguments" : intent.arguments ?? []]
        
        RemoveCachedOutput()
        
        #if MAIN        
        if !Bool(truncating: intent.showConsole ?? 0) {
            let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Script.py")
            if FileManager.default.fileExists(atPath: url.path) {
                try? FileManager.default.removeItem(at: url)
            }
            FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
            
            RunShortcutsScript(at: url, arguments: intent.arguments ?? [])
            
            return completion(.init(code: .success, userActivity: nil))
        }
        #endif
        
        return completion(.init(code: .continueInApp, userActivity: userActivity))
        #endif
    }
    
    func resolveCode(for intent: RunCodeIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        return completion(.success(with: intent.code ?? ""))
    }
    
    func resolveArguments(for intent: RunCodeIntent, with completion: @escaping ([INStringResolutionResult]) -> Void) {
        var result = [INStringResolutionResult]()
        
        for arg in intent.arguments ?? [] {
            result.append(.success(with: arg))
        }
        
        completion(result)
    }
}
