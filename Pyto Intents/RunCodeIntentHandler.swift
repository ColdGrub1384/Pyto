//
//  RunCodeIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 30-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Intents

class RunCodeIntentsHandler: NSObject, RunCodeIntentHandling {
    
    func handle(intent: RunCodeIntent, completion: @escaping (RunCodeIntentResponse) -> Void) {
        let userActivity = NSUserActivity(activityType: "RunCodeIntent")
        if let code = intent.code {
            userActivity.userInfo = ["code" : code, "arguments" : intent.arguments ?? ""]
        }
        return completion(.init(code: .continueInApp, userActivity: userActivity))
    }
    
    func resolveCode(for intent: RunCodeIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        return completion(.success(with: intent.code ?? ""))
    }
    
    func resolveArguments(for intent: RunCodeIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        return completion(.success(with: intent.arguments ?? ""))
    }
}
