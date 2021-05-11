//
//  SwiftUIBundle.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 22-05-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

fileprivate class MyClass {}

/// The bundle where localized strings for SwiftUI views are located.
var SwiftUIBundle: Bundle {
    return Bundle(for: MyClass.self)
}
