//
//  StartHandlingWidgetsInAppIntentHandler.swift
//  Pyto
//
//  Created by Adrian Labbé on 14-10-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

@available(iOS 14.0, *)
class StartHandlingWidgetsInAppIntentHandler: NSObject, StartHandlingWidgetsInAppIntentHandling {
    
    func handle(intent: StartHandlingWidgetsInAppIntent, completion: @escaping (StartHandlingWidgetsInAppIntentResponse) -> Void) {
        RuntimeCommunicator.shared.listen()
        completion(.init(code: .success, userActivity: nil))
    }
}
