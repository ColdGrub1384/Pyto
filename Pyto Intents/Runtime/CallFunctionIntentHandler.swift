//
//  CallFunctionIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 22-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

class CallFunctionIntentHandler: NSObject, CallFunctionIntentHandling {
    
    func handle(intent: CallFunctionIntent, completion: @escaping (CallFunctionIntentResponse) -> Void) {
        
        ShortcutsRuntimeStore.handler = { id, display in
            let res = CallFunctionIntentResponse(code: id != "Error" ? .success : .failure, userActivity: nil)
            res.returnValue = CodablePythonObject(description: display, address: id).shortcutsObject
            completion(res)
        }
        
        var params = [FunctionParameter]()
        for param in intent.parameters ?? ["/Developer"] {
            do {
                let data = param.data(using: .utf8) ?? Data()
                let object = try JSONDecoder().decode(CodablePythonObject.self, from: data)
                params.append(FunctionParameter(stringValue: nil, address: object.address))
            } catch {
                params.append(FunctionParameter(stringValue: param, address: nil))
            }
        }
        
        ShortcutsRuntimeStore.parameters = NSMutableArray(array: params)
        ShortcutsRuntimeStore.parameter = intent.function?.identifier
        
        Python.shared.run(code: """
        from pyto import __Class__
        import __shortcuts_store__ as store

        ShortcutsRuntimeStore = __Class__("ShortcutsRuntimeStore")

        try:
            ret = store.call_function(str(ShortcutsRuntimeStore.parameter), list(ShortcutsRuntimeStore.parameters))
            ShortcutsRuntimeStore.callHandler(ret[0], repr=ret[1])
        except Exception:
            ShortcutsRuntimeStore.callHandler("Error", repr="")
        """)
    }
}
