//
//  Size.swift
//  Pyto
//
//  Created by Emma Labbé on 18-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import WidgetKit
import SwiftUI

extension CGSize: Hashable {
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(width)
        hasher.combine(height)
    }
}

@available(iOS 14.0, *)
func size(for mode: WidgetFamily, size: UserInterfaceSizeClass = .regular) -> CGSize {
    if size == .regular {
        switch mode {
        case .systemSmall:
            return CGSize(width: 169, height: 169)
        case .systemMedium:
            return CGSize(width: 360, height: 169)
        case .systemLarge:
            return CGSize(width: 360, height: 379)
        default:
            return CGSize(width: 169, height: 379)
        }
    } else {
        switch mode {
        case .systemSmall:
            return CGSize(width: 141, height: 141)
        case .systemMedium:
            return CGSize(width: 292, height: 141)
        case .systemLarge:
            return CGSize(width: 292, height: 311)
        default:
            return CGSize(width: 141, height: 141)
        }
    }
}
