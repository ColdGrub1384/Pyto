//
//  PyWidget.swift
//  WidgetExtension
//
//  Created by Adrian Labbé on 11-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

@objc class PyWidget: NSObject, ObservableObject {
    
    static let shared = PyWidget()
    
    var snapshot: UIImage?
        
    static var size = CGSize.zero
    
    @objc static func setView(_ view: PyView) {
        
        DispatchQueue.main.async {
            
            view.view.frame.size = self.size
            
            let renderer = UIGraphicsImageRenderer(bounds: view.view.bounds)
            shared.snapshot = renderer.image { rendererContext in
                view.view.layer.render(in: rendererContext.cgContext)
            }
            
        }
    }
}
