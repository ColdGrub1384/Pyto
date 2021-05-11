//
//  SetContentInAppIntentHandler.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 22-09-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Intents

@available(iOSApplicationExtension 14.0, *)
class SetContentInAppIntentHandler: NSObject, SetContentInAppIntentHandling {
    
    func provideCategoryOptionsCollection(for intent: SetContentInAppIntent, with completion: @escaping (INObjectCollection<WidgetCategory>?, Error?) -> Void) {
        
        var widgets = [WidgetCategory]()
        
        let saved = InAppWidgetsStore.shared.allEntries
        
        for value in saved {
            widgets.append(WidgetCategory(identifier: value, display: value))
        }
        
        let collection = INObjectCollection(items: widgets)
        completion(collection, nil)
    }
    
}
