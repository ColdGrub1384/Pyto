//
//  GetObjectDescriptionIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 23-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

class GetObjectDescriptionIntentHandler: NSObject, GetObjectDescriptionIntentHandling {
    
    func handle(intent: GetObjectDescriptionIntent, completion: @escaping (GetObjectDescriptionIntentResponse) -> Void) {
        let res = GetObjectDescriptionIntentResponse(code: .success, userActivity: nil)
        
        let json = (intent.object?.displayString ?? "")?.data(using: .utf8) ?? Data()
        do {
            let object = try JSONDecoder().decode(CodablePythonObject.self, from: json)
            res.output = object.description
        } catch {
            
        }
        
        completion(res)
    }
}
