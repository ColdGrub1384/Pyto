//
//  SetPropertyIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 23-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

class SetPropertyIntentHandler: NSObject, SetPropertyIntentHandling {
    
    func handle(intent: SetPropertyIntent, completion: @escaping (SetPropertyIntentResponse) -> Void) {
        guard let id = intent.object?.identifier, let property = intent.property, let newValue = intent.newValue else {
            return completion(SetPropertyIntentResponse(code: .failure, userActivity: nil))
        }
        
        ShortcutsRuntimeStore.handler = { id, _ in
            completion(SetPropertyIntentResponse(code: id != "Error" ? .success : .failure, userActivity: nil))
        }
        
        ShortcutsRuntimeStore.parameter = property
        
        Python.shared.run(code: """
        from pyto import __Class__
        import __shortcuts_store__ as store

        ShortcutsRuntimeStore = __Class__("ShortcutsRuntimeStore")

        try:
            value_id = "\(newValue.identifier ?? "")"
            value = store.objects[value_id]

            setattr(store.objects["\(id)"], str(ShortcutsRuntimeStore.parameter), value)
            ShortcutsRuntimeStore.callHandler("", repr="")
        except Exception:
            ShortcutsRuntimeStore.callHandler("Error", repr="")
        """)
    }
}
