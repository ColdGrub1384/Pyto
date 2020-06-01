//
//  UIImage+color.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 31-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

extension UIImage {
    
    var backgroundColor: UIColor {

         var rF: CGFloat = 0
         var gF: CGFloat = 0
         var bF: CGFloat = 0
         var aF: CGFloat = 0
        
        self.getPixelColor(pos: CGPoint(x: 80, y: 80)).getRed(&rF, green: &gF, blue: &bF, alpha: &aF)

        return UIColor(red: rF, green: gF, blue: bF, alpha: 1.0)
    }
    
    func getPixelColor(pos: CGPoint) -> UIColor {

        guard let img = self.cgImage else {
            return .clear
        }
        
        guard let dataProvider = img.dataProvider else {
            return .clear
        }
        
        let pixelData = dataProvider.data
        let data: UnsafePointer<UInt8> = CFDataGetBytePtr(pixelData)

        let pixelInfo: Int = ((Int(self.size.width) * Int(pos.y)) + Int(pos.x)) * 4

        let r = CGFloat(data[pixelInfo]) / CGFloat(255.0)
        let g = CGFloat(data[pixelInfo+1]) / CGFloat(255.0)
        let b = CGFloat(data[pixelInfo+2]) / CGFloat(255.0)
        let a = CGFloat(data[pixelInfo+3]) / CGFloat(255.0)

        return UIColor(red: r, green: g, blue: b, alpha: a)
    }
}
