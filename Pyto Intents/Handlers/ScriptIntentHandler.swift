//
//  ScriptIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 18-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

@available(iOSApplicationExtension 14.0, *)
class ScriptIntentHandler: NSObject, ScriptIntentHandling {
    
    func resolveWidgetType(for intent: ScriptIntent, with completion: @escaping (WidgetTypeResolutionResult) -> Void) {
        return completion(WidgetTypeResolutionResult.success(with: intent.widgetType))
    }
    
    func resolveCategory(for intent: ScriptIntent, with completion: @escaping (WidgetCategoryResolutionResult) -> Void) {
        return completion(WidgetCategoryResolutionResult.success(with: intent.category ?? WidgetCategory(identifier: nil, display: "None")))
    }
    
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
    
    @available(iOS 14.0, *)
    func provideCategoryOptionsCollection(for intent: ScriptIntent, with completion: @escaping (INObjectCollection<WidgetCategory>?, Error?) -> Void) {
        
        var widgets = [WidgetCategory]()
        
        guard let saved = UserDefaults.shared?.value(forKey: "savedWidgets") as? [String:Data] else {
            return completion(nil, nil)
        }
        
        for value in saved {
            widgets.append(WidgetCategory(identifier: value.key, display: value.key))
        }
        
        let collection = INObjectCollection(items: widgets)
        completion(collection, nil)
    }
}
