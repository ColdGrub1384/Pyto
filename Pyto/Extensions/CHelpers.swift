//
//  CHelpers.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

extension String {
    
    /// Returns a `wchar_t` pointer from this String to be used with CPython.
    var cWchar_t: UnsafeMutablePointer<wchar_t> {
        return Py_DecodeLocale(cValue, nil)
    }
    
    /// Returns a C pointer to pass this `String` to C functions.
    var cValue: UnsafeMutablePointer<Int8> {
        guard let cString = cString(using: .utf8) else {
            let buffer = UnsafeMutablePointer<Int8>.allocate(capacity: 1)
            buffer.pointee = 0
            return buffer
        }
        let buffer = UnsafeMutablePointer<Int8>.allocate(capacity: cString.count)
        memcpy(buffer, cString, cString.count)
        
        return buffer
    }
}
