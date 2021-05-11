//
//  PyImageView.swift
//  Pyto
//
//  Created by Emma Labbé on 07-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

extension UIImage {
    
    @objc public var data: Data? {
        return pngData()
    }
}

@available(iOS 13.0, *) @objc public class PyImageView: PyView {
    
    @objc public var image: UIImage? {
        get {
            return get {
                return self.imageView.image
            }
        }
        
        set {
            set {
                self.imageView.image = newValue
            }
        }
    }
    
    public override class var pythonName: String {
        return "ImageView"
    }
    
    /// The Image view associated with this object.
    @objc public var imageView: UIImageView {
        return get {
            return self.managed as! UIImageView
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyImageView(managed: get {
            return UIImageView()
        })
    }
}
