//
//  ShortcutsRuntimeStore.swift
//  Pyto
//
//  Created by Adrian Labbé on 21-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Intents

@objc class ShortcutsRuntimeStore: NSObject {
    
    @objc static var parameter: String?
    
    @objc static var parameters = NSMutableArray(array: [])
    
    @objc static var handler: ((String, String) -> Void)?
    
    @objc static func callHandler(_ id: String, repr: String) {
        handler?(id, repr)
    }
}
