//
//  SetContentInAppIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 22-09-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

@available(iOSApplicationExtension 14.0, *)
class SetContentInAppIntentHandler: NSObject, SetContentInAppIntentHandling {
    
    func provideCategoryOptionsCollection(for intent: SetContentInAppIntent, with completion: @escaping (INObjectCollection<WidgetCategory>?, Error?) -> Void) {
        
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
