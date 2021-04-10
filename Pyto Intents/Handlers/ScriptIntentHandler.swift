//
//  ScriptIntentHandler.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 18-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Intents

@available(iOSApplicationExtension 14.0, *)
class ScriptIntentHandler: NSObject, ScriptIntentHandling {
    
    func resolveScript(for intent: ScriptIntent, with completion: @escaping (INFileResolutionResult) -> Void) {
        
        guard let file = intent.script else {
            return completion(.disambiguation(with: RunScriptIntentHandler.getCode()))
        }
        return completion(.success(with: file))
    }
    
    @available(iOS 14.0, *)
    func provideScriptOptionsCollection(for intent: ScriptIntent, with completion: @escaping (INObjectCollection<INFile>?, Error?) -> Void) {
        let collection = INObjectCollection(items: RunScriptIntentHandler.getCode())
        return completion(collection, nil)
    }
}
