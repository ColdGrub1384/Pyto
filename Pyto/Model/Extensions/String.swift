//
//  String.swift
//  Pyto
//
//  Created by Emma Labbé on 9/9/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

@objc extension NSString {
    
    /// Replaces the first occurrence of the given `String` with another `String`.
    ///
    /// - Parameters:
    ///     - string: String to replace.
    ///     - replacement: Replacement of `string`.
    ///
    /// - Returns: This string replacing the first occurrence of `string` with `replacement`.
    @objc func replacingFirstOccurrence(of string: String, with replacement: String) -> String {
        return (self as String).replacingFirstOccurrence(of: string, with: replacement)
    }
}


extension String {
    
    /// Replaces the first occurrence of the given `String` with another `String`.
    ///
    /// - Parameters:
    ///     - string: String to replace.
    ///     - replacement: Replacement of `string`.
    ///
    /// - Returns: This string replacing the first occurrence of `string` with `replacement`.
    func replacingFirstOccurrence(of string: String, with replacement: String) -> String {
        guard let range = self.range(of: string) else { return self }
        return replacingCharacters(in: range, with: replacement)
    }
    
    /// Get string between two strings.
    ///
    /// - Returns: Substring between `from` to `to`:
    func slice(from: String, to: String) -> String? {
        
        return (range(of: from)?.upperBound).flatMap { substringFrom in
            (range(of: to, range: substringFrom..<endIndex)?.lowerBound).map { substringTo in
                String(self[substringFrom..<substringTo])
            }
        }
    }
    
    #if MAIN || WIDGET
    /// Returns a `wchar_t` pointer from this String to be used with CPython.
    var cWchar_t: UnsafeMutablePointer<wchar_t> {
        return Py_DecodeLocale(cValue, nil)
    }
    #endif
    
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
    
    /// Taken from https://stackoverflow.com/a/38809531/7515957
    func image() -> UIImage? {
        let size = CGSize(width: 40, height: 40)
        UIGraphicsBeginImageContextWithOptions(size, false, 0)
        UIColor.clear.set()
        let rect = CGRect(origin: .zero, size: size)
        UIRectFill(CGRect(origin: .zero, size: size))
        
        #if MAIN
        let color = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
        #else
        let color = UIColor.black
        #endif
        
        (self as AnyObject).draw(in: rect, withAttributes: [.font: UIFont.systemFont(ofSize: 40), .foregroundColor: color])
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image
    }
    
    func versionCompare(_ otherVersion: String) -> ComparisonResult {
        return self.compare(otherVersion, options: .numeric)
    }
}
