//
//  GetScriptOutputIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 29-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

class GetScriptOutputIntentHandler: NSObject, GetScriptOutputIntentHandling {
    
    func handle(intent: GetScriptOutputIntent, completion: @escaping (GetScriptOutputIntentResponse) -> Void) {
        
        guard let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") else {
            return completion(.init(code: .failure, userActivity: nil))
        }
        
        let outputURL = group.appendingPathComponent("ShortcutOutput.txt")
        
        while true {
            if FileManager.default.fileExists(atPath: outputURL.path) {
                do {
                    var out = try String(contentsOf: outputURL)
                    var comp = out.components(separatedBy: "\n")
                    let prefix = comp.removeFirst()
                    out = comp.joined(separator: "\n")
                    
                    let res: GetScriptOutputIntentResponse
                    
                    if prefix == "Success" {
                        res = GetScriptOutputIntentResponse(code: .success, userActivity: nil)
                    } else {
                        res = GetScriptOutputIntentResponse(code: .failure, userActivity: nil)
                    }
                    
                    res.output = out
                    completion(res)
                    break
                } catch {
                    completion(.init(code: .failure, userActivity: nil))
                    break
                }
            }
            sleep(UInt32(0.2))
        }
    }
}
