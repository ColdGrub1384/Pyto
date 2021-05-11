//
//  ReloadWidgetsIntentHandler.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 13-10-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Intents
import WidgetKit

@available(iOSApplicationExtension 14.0, *)
class ReloadWidgetsIntentHandler: NSObject, ReloadWidgetsIntentHandling {
        
    func handle(intent: ReloadWidgetsIntent, completion: @escaping (ReloadWidgetsIntentResponse) -> Void) {
        RuntimeCommunicator.shared.widgetsToBeReloaded = intent.widgets
        WidgetCenter.shared.reloadTimelines(ofKind: "Script")
        completion(.init(code: .success, userActivity: nil))
    }
    
    func provideWidgetsOptionsCollection(for intent: ReloadWidgetsIntent, with completion: @escaping (INObjectCollection<NSString>?, Error?) -> Void) {
        
        WidgetCenter.shared.getCurrentConfigurations { (info) in
            switch info {
            case .success(let widgets):
                var files = [NSString]()
                for widget in widgets {
                    if let script = (widget.configuration as? ScriptIntent)?.script, !files.contains(script.filename as NSString) {
                        files.append(script.filename as NSString)
                    }
                }
                completion(INObjectCollection(items: files), nil)
            case .failure(let error):
                completion(nil, error)
            }
        }
    }
}
