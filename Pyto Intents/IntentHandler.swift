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
            #if !Xcode11
            return RunCodeIntentHandler()
            #else
            return RunCodeIntentsHandler()
            #endif
        } else if intent is GetScriptOutputIntent {
            return GetScriptOutputIntentHandler()
        } else {
            
            #if !Xcode11
            if #available(iOSApplicationExtension 14.0, *), intent is ScriptIntent {
                return ScriptIntentHandler()
            } else if #available(iOSApplicationExtension 14.0, *), intent is SetContentInAppIntent {
                return SetContentInAppIntentHandler()
<<<<<<< HEAD
            } else if #available(iOSApplicationExtension 14.0, *), intent is ReloadWidgetsIntent {
               return ReloadWidgetsIntentHandler()
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
            }
            #endif
            
            return self
        }
    }
    
}
