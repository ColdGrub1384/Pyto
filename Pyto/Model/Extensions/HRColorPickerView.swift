//
//  HRColorPickerView.swift
//  Pyto
//
//  Created by Emma Labbé on 13-10-19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import Color_Picker_for_iOS

extension HRColorPickerView {
    
    private struct HandlerHolder {
        
        static var values = [HRColorPickerView:(((UIColor) -> Void)?)]()
    }
    
    /// Code called when selected color changed.
    var handler: ((UIColor) -> Void)? {
        get {
            return HandlerHolder.values[self] ?? nil
        }
        
        set {
            HandlerHolder.values[self] = newValue
        }
    }
    
    @objc private func valueDidChange(_ sender: HRColorPickerView) {
        handler?(sender.color)
    }
    
    override open func didMoveToWindow() {
        super.didMoveToWindow()
        
        addTarget(self, action: #selector(valueDidChange(_:)), for: .valueChanged)
    }
}
