//
//  GetScriptOutputIntentHandler.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 29-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents
import UIKit

class GetScriptOutputIntentHandler: NSObject, GetScriptOutputIntentHandling {
    
    func handle(intent: GetScriptOutputIntent, completion: @escaping (GetScriptOutputIntentResponse) -> Void) {
        
        guard let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") else {
            return completion(.init(code: .failure, userActivity: nil))
        }
        
        let outputURL = group.appendingPathComponent("ShortcutOutput.txt")
        
        let imagesURL = group.appendingPathComponent("ShortcutPlots")
        
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
                        PyNotificationCenter.scheduleNotification(title: "Script thrown an exception", message: out, delay: 0.1)
                        res = GetScriptOutputIntentResponse(code: .failure, userActivity: nil)
                    }
                    
                    var output = [INFile]()
                    
                    do {
                        let plots = try NSKeyedUnarchiver.unarchiveTopLevelObjectWithData(try Data(contentsOf: imagesURL)) as? [UIImage]
                        for plot in plots ?? [] {
                            if let data = plot.pngData() {
                                output.append(INFile(data: data, filename: "image.png", typeIdentifier: "public.image"))
                            }
                        }
                    } catch {
                        print(error.localizedDescription)
                    }
                    
                    if out.replacingOccurrences(of: "\n", with: "") != "" {
                        output.append(INFile(data: out.data(using: .utf8) ?? Data(), filename: "console.txt", typeIdentifier: "public.plain-text"))
                    }
                    
                    res.output = output
                    
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
