//
//  StringFromParameter.swift
//  Pyto
//
//  Created by Adrian Labbé on 22-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

func StringFromParameter(_ parameter: String) -> String {
    
    do {
        let data = parameter.data(using: .utf8) ?? Data()
        let object = try JSONDecoder().decode(CodablePythonObject.self, from: data)
        return object.description
    } catch {
        return parameter
    }
}
