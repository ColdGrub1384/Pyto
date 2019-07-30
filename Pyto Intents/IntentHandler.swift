//
//  IntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 30-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Intents

class IntentHandler: INExtension {
    
    override func handler(for intent: INIntent) -> Any {
        // This is the default implementation.  If you want different objects to handle different intents,
        // you can override this and return the handler you want for that particular intent.
        
        if intent is RunScriptIntent {
            return RunScriptIntentHandler()
        } else if intent is RunCodeIntent {
            return RunCodeIntentsHandler()
        } else {
            return self
        }
    }
    
}
