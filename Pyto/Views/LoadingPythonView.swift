//
//  LoadingPythonView.swift
//  Pyto
//
//  Created by Adrian Labbé on 23-10-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A view that is shown while Python is loading.
class LoadingPythonView: UIView {
    
    override func didMoveToWindow() {
        super.didMoveToWindow()
        
        guard window != nil else {
            return
        }
        
        isUserInteractionEnabled = false
        center.x = window!.center.x
        frame.origin.y = window!.safeAreaLayoutGuide.layoutFrame.height-frame.height-20
        autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
        layer.cornerRadius = 16
        (viewWithTag(1) as? UITextView)?.text = Python.shared.version
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.4, repeats: true, block: { (timer) in
            self.frame.origin.y = self.window!.safeAreaLayoutGuide.layoutFrame.height-self.frame.height-20
            if self.window?.subviews.last != self {
                self.window?.bringSubviewToFront(self)
            }
            
            if Python.shared.isSetup {
                self.removeFromSuperview()
                timer.invalidate()
            }
        })
    }
}
