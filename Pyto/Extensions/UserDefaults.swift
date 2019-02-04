//
//  UserDefaults.swift
//  Pyto
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

extension UserDefaults {
    
    /// The `UserDefaults` instance shared with app extensions.
    static var shared: UserDefaults? {
        return UserDefaults(suiteName: "group.pyto")
    }
}
