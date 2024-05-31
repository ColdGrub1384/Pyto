//
//  PyStepper.swift
//  Pyto
//
//  Created by Emma on 27-07-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyStepper: PyControl {
    
    /// The stepper associated with this object.
    @objc public var stepper: UIStepper {
        return get {
            return self.managed as! UIStepper
        }
    }
    
    public override class var pythonName: String {
        return "Stepper"
    }
    
    @objc public var minimumValue: Double {
        get {
            return get {
                return self.stepper.minimumValue
            }
        }
        
        set {
            set {
                self.stepper.minimumValue = newValue
            }
        }
    }
    
    @objc public var maximumValue: Double {
        get {
            return get {
                return self.stepper.maximumValue
            }
        }
        
        set {
            set {
                self.stepper.maximumValue = newValue
            }
        }
    }
    
    @objc public var stepValue: Double {
        get {
            return get {
                return self.stepper.stepValue
            }
        }
        
        set {
            set {
                self.stepper.stepValue = newValue
            }
        }
    }
    
    @objc public var value: Double {
        get {
            return get {
                return self.stepper.value
            }
        }
        
        set {
            set {
                self.stepper.value = newValue
            }
        }
    }
    
    public override var action: PyValue? {
        didSet {
            set {
                if !self.stepper.allTargets.contains(self) {
                    self.stepper.addTarget(self, action: #selector(PyControl.callAction), for: .valueChanged)
                }
            }
        }
    }
    
    @objc override class func newView() -> PyView {
        let pyStepper = PyStepper()
        pyStepper.managed = get {
            let stepper = UIStepper()
            stepper.sizeToFit()
            stepper.addTarget(pyStepper, action: #selector(PyControl.callAction), for: .valueChanged)
            PyView.values[stepper] = pyStepper
            return stepper
        }
        return pyStepper
    }
}

