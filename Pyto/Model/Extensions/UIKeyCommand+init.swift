//
//  UIKeyCommand+init.swift
//  Pyto
//
//  Created by Emma Labbé on 13-09-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import UIKit

extension UIKeyCommand {
    
    //UIKeyCommand(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)
    
    static func command(input: String, modifierFlags: UIKeyModifierFlags, action: Selector, discoverabilityTitle: String?) -> UIKeyCommand {
        return UIKeyCommand(title: discoverabilityTitle ?? "", image: nil, action: action, input: input, modifierFlags: modifierFlags, propertyList: nil, alternates: [], discoverabilityTitle: discoverabilityTitle, attributes: [], state: .off)
    }
}
