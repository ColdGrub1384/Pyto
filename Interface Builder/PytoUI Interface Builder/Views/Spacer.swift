//
//  Spacer.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 02-07-22.
//

import UIKit

class StackViewSpacer: UIView {}

/// A spacer in a Stack view.
public struct Spacer: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return StackViewSpacer.self
    }
    
    public func preview(view: UIView) {}
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
    }
    
    public var image: UIImage? {
        UIImage(systemName: "arrow.up.left.and.arrow.down.right")
    }
    
    public func makeView() -> UIView {
        StackViewSpacer(frame: CGRect(origin: .zero, size: CGSize(width: 50, height: 50)))
    }
}
