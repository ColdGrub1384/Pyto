//
//  RunCommandIntentHandler.swift
//  Pyto
//
//  Created by Emma on 07-03-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import Intents

class RunCommandIntentHandler: NSObject, RunCommandIntentHandling {
    
    func handle(intent: RunCommandIntent, completion: @escaping (RunCommandIntentResponse) -> Void) {
        var arguments = intent.command ?? []
        arguments.insert("_shell", at: 0)
        arguments.insert("-m", at: 0)
        arguments.insert("python", at: 0)
        
        let url = Bundle.main.url(forResource: "command_runner", withExtension: "py")!
        let newURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("Script.py")
        
        if FileManager.default.fileExists(atPath: newURL.path) {
            try? FileManager.default.removeItem(at: newURL)
        }
        
        try? FileManager.default.copyItem(at: url, to: newURL)
        
        #if MAIN
        PyItemProvider.setShortcutsFiles(intent.items ?? [])
        #endif
        
        let scriptIntent = RunScriptIntent()
        scriptIntent.showConsole = intent.showConsole
        scriptIntent.script = INFile(fileURL: newURL, filename: "Script.py", typeIdentifier: "public.python-script")
        scriptIntent.arguments = arguments
        scriptIntent.input = intent.input
        scriptIntent.items = intent.items
        scriptIntent.workingDirectory = intent.workingDirectory
        RunScriptIntentHandler().handle(intent: scriptIntent) { response in
            if response.code == .continueInApp {
                completion(.init(code: .continueInApp, userActivity: response.userActivity))
            } else {
                completion(.init(code: .success, userActivity: response.userActivity))
            }
        }
    }
    
    func resolveShowConsole(for intent: RunCommandIntent, with completion: @escaping (INBooleanResolutionResult) -> Void) {
        completion(.success(with: intent.showConsole?.boolValue ?? false))
    }
    
    func resolveItems(for intent: RunCommandIntent, with completion: @escaping ([INFileResolutionResult]) -> Void) {
        completion(intent.items?.compactMap({ INFileResolutionResult.success(with: $0) }) ?? [])
    }
}
