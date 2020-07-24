//
//  GetPropertyIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 21-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

class GetPropertyIntentHandler: NSObject, GetPropertyIntentHandling {
    
    func handle(intent: GetPropertyIntent, completion: @escaping (GetPropertyIntentResponse) -> Void) {
        
        guard let prop = intent.property, let object = intent.object?.identifier else {
            return
        }
        
        ShortcutsRuntimeStore.handler = { id, display in
            let res = GetPropertyIntentResponse(code: id != "Error" ? .success : .failure, userActivity: nil)
            res.returnedProperty = CodablePythonObject(description: display, address: id).shortcutsObject
            completion(res)
        }
        
        ShortcutsRuntimeStore.parameter = StringFromParameter(prop)
        
        Python.shared.run(code: """
        from pyto import __Class__
        import __shortcuts_store__ as store

        ShortcutsRuntimeStore = __Class__("ShortcutsRuntimeStore")

        try:
            mod = store.get_property(str(ShortcutsRuntimeStore.parameter), \"\(object)\")
            ShortcutsRuntimeStore.callHandler(mod[0], repr=mod[1])
        except Exception:
            ShortcutsRuntimeStore.callHandler("Error", repr="")
        """)
    }
}
