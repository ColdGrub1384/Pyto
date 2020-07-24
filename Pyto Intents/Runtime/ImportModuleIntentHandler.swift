//
//  ImportModuleIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 21-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

class ImportModuleIntentHandler: NSObject, ImportModuleIntentHandling {
    
    func handle(intent: ImportModuleIntent, completion: @escaping (ImportModuleIntentResponse) -> Void) {
        
        ShortcutsRuntimeStore.handler = { id, display in
            let res = ImportModuleIntentResponse(code: id != "Error" ? .success : .failure, userActivity: nil)
            res.importedModule = CodablePythonObject(description: display, address: id).shortcutsObject
            completion(res)
        }
        
        if let modName = intent.module {
            
            ShortcutsRuntimeStore.parameter = StringFromParameter(modName)
            
            Python.shared.run(code: """
            from pyto import __Class__
            import __shortcuts_store__ as store

            ShortcutsRuntimeStore = __Class__("ShortcutsRuntimeStore")

            try:
                mod = store.import_module(str(ShortcutsRuntimeStore.parameter))
                ShortcutsRuntimeStore.callHandler(mod[0], repr=mod[1])
            except Exception:
                ShortcutsRuntimeStore.callHandler("Error", repr="")
            """)
        } else if let script = intent.script {
            
            var url = script.fileURL
            
            if url == nil, let data = intent.script?.data {
                do {
                    var isStale = false
                    url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                    _ = url?.startAccessingSecurityScopedResource()
                } catch {
                    completion(ImportModuleIntentResponse(code: .failure, userActivity: nil))
                    return
                }
            }
            
            guard let script = url else {
                return completion(.init(code: .failure, userActivity: nil))
            }
            
            AppDelegate.shared.shortcutScript = script.path
            
            Python.shared.run(code: """
            from rubicon.objc import ObjCClass
            from pyto import PyOutputHelper, Python
            import __shortcuts_store__ as store
            import importlib.util
            import __shortcuts_store__ as store

            ShortcutsRuntimeStore = __Class__("ShortcutsRuntimeStore")

            error_message = None

            try:
                script = str(ObjCClass("Pyto.AppDelegate").shared.shortcutScript) # Get the script to run

                mod = store.import_script(script)
                ShortcutsRuntimeStore.callHandler(mod[0], repr=mod[1])
            except SystemExit:
                pass
            except KeyboardInterrupt:
                pass
            except Exception as e:
                error_message = str(e)
            """)
        }
    }
    
    @available(iOS 14.0, *)
    func provideScriptOptionsCollection(for intent: ImportModuleIntent, with completion: @escaping (INObjectCollection<INFile>?, Error?) -> Void) {
        let collection = INObjectCollection(items: RunScriptIntentHandler.getScripts())
        return completion(collection, nil)
    }
}
