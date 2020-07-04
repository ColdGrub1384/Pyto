//
//  UIApplication+orientation.swift
//  Pyto
//
//  Created by Adrian Labbé on 04-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

extension UIApplication {
    
    var orientation: UIInterfaceOrientation {
        let keyWindow = UIApplication.shared.connectedScenes
                .filter({$0.activationState == .foregroundActive})
                .map({$0 as? UIWindowScene})
                .compactMap({$0})
                .first?.windows
                .filter({$0.isKeyWindow}).first
        
        return keyWindow?.windowScene?.interfaceOrientation ?? UIInterfaceOrientation(rawValue: 0)!
    }
}
