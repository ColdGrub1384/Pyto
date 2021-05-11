//
//  LoadingPythonView.swift
//  Pyto
//
//  Created by Emma Labbé on 23-10-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
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
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.4, repeats: true, block: { [weak self] (timer) in
            
            guard let self = self else {
                return
            }
            
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
