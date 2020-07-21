//
//  Size.swift
//  Pyto
//
//  Created by Adrian Labbé on 18-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import CoreGraphics
import WidgetKit

extension CGSize: Hashable {
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(width)
        hasher.combine(height)
    }
}

@available(iOS 14.0, *)
func size(for mode: WidgetFamily) -> CGSize {
    switch mode {
    case .systemSmall:
        return CGSize(width: 123, height: 123)
    case .systemMedium:
        return CGSize(width: 297, height: 123)
    case .systemLarge:
        return CGSize(width: 297, height: 313)
    default:
        return CGSize(width: 123, height: 123)
    }
}
