//
//  SwiftUIBundle.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 22-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

fileprivate class MyClass {}

/// The bundle where localized strings for SwiftUI views are located.
var SwiftUIBundle: Bundle {
    return Bundle(for: MyClass.self)
}
