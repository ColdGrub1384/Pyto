//
//  Progress.swift
//  Pyto
//
//  Created by Emma Labbé on 27-09-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 14.0, *)
@objc class WidgetProgress: WidgetComponent {
    
    override init() { super.init() }
    
    @objc var progress: Double = 0
    
    @objc var color: UIColor?
    
    @objc var label: WidgetComponent?
    
    @objc var isCircular = false
    
    override var makeView: AnyView {
        var progressView = AnyView(ProgressView(value: progress) {
            VStack {
                Spacer()
                label?.makeView
                Spacer()
            }
        })
        
        #if os(iOS)
        let labelColor = UIColor.label
        #elseif os(watchOS)
        let labelColor = UIColor.white
        #endif
        
        if isCircular {
            progressView = AnyView(progressView.progressViewStyle(CircularProgressViewStyle(tint: Color(color ?? labelColor))))
        } else {
            progressView = AnyView(progressView.progressViewStyle(LinearProgressViewStyle(tint: Color(color ?? labelColor))))
        }
        
        return AnyView(progressView
            .padding((backgroundColor != nil && backgroundColor != UIColor.clear) ? .all : [])
            .background(Color(backgroundColor ?? UIColor.clear))
            .cornerRadius(CGFloat(cornerRadius)))
    }
    
    required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
        
        let container = try decoder.container(keyedBy: Keys.self)
        progress = try container.decode(Double.self, forKey: .progress)
        isCircular = try container.decode(Bool.self, forKey: .circular)
        do {
            let colorData = try container.decode(Data.self, forKey: .color)
            color = UIColor.color(withData: colorData)
        } catch {
            color = nil
        }
        
        do {
            label = try container.decode(CodableWidgetComponent.self, forKey: .label).makeObject()
        } catch {
            label = nil
        }
    }
    
    override func encode(to encoder: Encoder) throws {
        try super.encode(to: encoder)
        
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(color?.encode(), forKey: .color)
        try container.encode(progress, forKey: .progress)
        try container.encode(isCircular, forKey: .circular)
        
        if let label = label {
            let data = try JSONEncoder().encode(label)
            try container.encode(CodableWidgetComponent(className: "\(type(of: label))", data: data), forKey: .label)
        }
    }
}
