//
//  String.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

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
}
