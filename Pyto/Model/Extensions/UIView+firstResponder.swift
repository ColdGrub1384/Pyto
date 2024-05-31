//
//  UIView+firstResponder.swift
//  Pyto
//
//  Created by Emma on 25-05-24.
//  Copyright © 2024 Emma Labbé. All rights reserved.
//

import UIKit

extension UIView {
    var firstResponder: UIView? {
        guard !isFirstResponder else { return self }

        for subview in subviews {
            if let firstResponder = subview.firstResponder {
                return firstResponder
            }
        }

        return nil
    }
}
