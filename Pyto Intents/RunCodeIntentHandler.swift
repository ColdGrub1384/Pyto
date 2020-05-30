//
//  RunCodeIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 30-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Intents

class RunCodeIntentHandler: NSObject, RunCodeIntentHandling {

    static var isPythonInitialized = false
    
    static let pipe = Pipe()
    
    func handle(intent: RunCodeIntent, completion: @escaping (RunCodeIntentResponse) -> Void) {
        let userActivity = NSUserActivity(activityType: "RunCodeIntent")
        guard let code = intent.code else {
            return completion(.init(code: .failure, userActivity: nil))
        }
        
        userActivity.userInfo = ["code" : code, "arguments" : intent.arguments ?? []]
        
        if intent.runInApp?.boolValue == true {
            
            if let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") {
                do {
                    try FileManager.default.removeItem(at: group.appendingPathComponent("ShortcutOutput.txt"))
                } catch {
                    print(error.localizedDescription)
                }
            }
            
            return completion(.init(code: .continueInApp, userActivity: userActivity))
        } else {
            putenv("PYTHONHOME=\(Bundle.main.bundlePath)".cValue)
            putenv("PYTHONPATH=\(Bundle.main.bundleURL.deletingLastPathComponent().deletingLastPathComponent().appendingPathComponent("Frameworks/Python.framework/python38.zip").path):\(FileManager.default.sharedDirectory?.path ?? "")/modules".cValue)
            putenv("PYTHONOPTIMIZE=".cValue)
            putenv("PYTHONIOENCODING=utf-8".cValue)
            
            var output = ""
            
            let semaphore = DispatchSemaphore(value: 0)
            
            DispatchQueue.global().async {
                if !RunCodeIntentHandler.isPythonInitialized {
                    Py_Initialize()
                    PyRun_SimpleString("import sys, os; out = os.fdopen(\(RunCodeIntentHandler.pipe.fileHandleForWriting.fileDescriptor), 'w'); sys.stdout = out; sys.stderr = out; del sys; del os; del out")
                    RunCodeIntentHandler.isPythonInitialized = true
                }
                
                let args = intent.arguments ?? []
                setArgv(["pyto"]+args)
                
                PyRun_SimpleString(code)
                PyRun_SimpleString("import sys; sys.stdout.flush(); sys.stderr.flush()")
                
                semaphore.signal()
            }
            
            semaphore.wait()
            
            output = String(data: RunCodeIntentHandler.pipe.fileHandleForReading.availableData, encoding: .utf8) ?? ""
            
            if output.hasSuffix("\n") {
                output.removeLast()
            }
                        
            let res = RunCodeIntentResponse(code: .success, userActivity: nil)
            res.output = output
            completion(res)
        }
    }
    
    func resolveCode(for intent: RunCodeIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        return completion(.success(with: intent.code ?? ""))
    }
    
    func resolveArguments(for intent: RunCodeIntent, with completion: @escaping ([INStringResolutionResult]) -> Void) {
        var result = [INStringResolutionResult]()
        
        for arg in intent.arguments ?? [] {
            result.append(.success(with: arg))
        }
        
        completion(result)
    }
    
    func resolveRunInApp(for intent: RunCodeIntent, with completion: @escaping (INBooleanResolutionResult) -> Void) {
        completion(.success(with: intent.runInApp?.boolValue ?? false))
    }
}
