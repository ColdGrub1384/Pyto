//
//  PyPiPackage.swift
//  Pyto
//
//  Created by Adrian Labbé on 3/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

/// A PyPi package.
struct PyPiPackage {
    
    /// The package name.
    let name: String
    
    /// The package's author.
    let author: String?
    
    /// The author's email.
    let authorEmail: String?
    
    /// The package's description.
    let description: String?
    
    /// The homepage.
    let homepage: String?
    
    /// The package's version.
    let version: String?
}
