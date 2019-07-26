//
//  PyNotificationCenter.swift
//  Pyto
//
//  Created by Adrian Labbé on 16-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class managing Today widget settings.
@available(iOS 13.0, *) @objc class PyNotificationCenter: NSObject {
    
    /// Set to `true` to make the widget able to expand.
    @objc static var canBeExpanded: Bool {
        set {
            #if WIDGET
            ConsoleViewController.visible.canBeExpanded = newValue
            #else
            WidgetSimulatorViewController.canBeExpanded = newValue
            #endif
        }
        
        get {
            #if WIDGET
            return ConsoleViewController.visible.canBeExpanded
            #else
            return WidgetSimulatorViewController.canBeExpanded
            #endif
        }
    }
    
    /// The widget's maximum height.
    @objc static var maximumHeight: Double {
        set {
            #if WIDGET
            ConsoleViewController.visible.maximumHeight = newValue
            #else
            WidgetSimulatorViewController.maximumHeight = newValue
            #endif
        }
        
        get {
            #if WIDGET
            return ConsoleViewController.visible.maximumHeight
            #else
            return WidgetSimulatorViewController.maximumHeight
            #endif
        }
    }
}
