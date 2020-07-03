//
//  UserDefaults.swift
//  Pyto
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

extension UserDefaults {
    
    /// The `UserDefaults` instance shared with app extensions.
    static var shared: UserDefaults? {
        return UserDefaults(suiteName: "group.pyto")
    }
    
    /// Taken from https://stackoverflow.com/a/41814164/7515957
    func set(font: UIFont, forKey key: String) {
        do {
            let data = try NSKeyedArchiver.archivedData(withRootObject: font, requiringSecureCoding: false)
            self.set(data, forKey: key)
        } catch {
            print(error.localizedDescription)
        }
    }

    /// Taken from https://stackoverflow.com/a/41814164/7515957
    func font(forKey key: String) -> UIFont? {
        guard let data = data(forKey: key) else { return nil }
        do {
            return try NSKeyedUnarchiver.unarchivedObject(ofClasses: [UIFont.self], from: data) as? UIFont
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
}
