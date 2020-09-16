//
//  CodableFont.swift
//  Pyto
//
//  Created by Adrian Labbé on 30-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

struct CodableFont: Codable {
    
    var descriptorData: Data
    
    var size: Float
    
    init?(font: UIFont) {
        do {
            descriptorData = try NSKeyedArchiver.archivedData(withRootObject: font.fontDescriptor, requiringSecureCoding: false)
            size = Float(font.pointSize)
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
    
    var uiFont: UIFont {
        
        let system = UIFont.systemFont(ofSize: UIFont.systemFontSize)
        
        do {
            guard let descriptor = try NSKeyedUnarchiver.unarchivedObject(ofClass: UIFontDescriptor.self, from: descriptorData) else {
                return system
            }
            
            return UIFont(descriptor: descriptor, size: CGFloat(size))
        } catch {
            print(error.localizedDescription)
            return system
        }
    }
}
