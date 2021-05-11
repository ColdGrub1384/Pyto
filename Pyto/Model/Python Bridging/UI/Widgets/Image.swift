//
//  Image.swift
//  Pyto
//
//  Created by Emma Labbé on 25-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@objc class WidgetImage: WidgetComponent {
    
    override init() { super.init() }
    
    @objc var image: UIImage?
    
    @objc var fill = false
    
    override var makeView: AnyView {
        return AnyView(Image(uiImage: image ?? UIImage())
                        .resizable()
                        .aspectRatio(contentMode: fill ? .fill : .fit)
                        .background(Color(backgroundColor ?? UIColor.clear))
                        .cornerRadius(CGFloat(cornerRadius)))
    }
    
    required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
        
        let container = try decoder.container(keyedBy: Keys.self)
        fill = try container.decode(Bool.self, forKey: .fill)
        
        do {
            image = UIImage(data: try container.decode(Data.self, forKey: .image))
        } catch {
            image = nil
        }
    }
    
    override func encode(to encoder: Encoder) throws {
        try super.encode(to: encoder)
        
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(fill, forKey: .fill)
        try container.encode(image?.pngData(), forKey: .image)
    }
}
