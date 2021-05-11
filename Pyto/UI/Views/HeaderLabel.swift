//
//  HeaderLabel.swift
//  Pyto
//
//  Created by Emma Labbé on 08-11-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// A label to display on top of a Table view.
class HeaderLabel: UILabel {
    
    override func drawText(in rect: CGRect) {
        super.drawText(in: rect.inset(by: UIEdgeInsets.init(top: 0, left: 10, bottom: 0, right: 10)))
    }
}
