//
//  PySegmentedControl.swift
//  Pyto
//
//  Created by Emma Labbé on 17-07-19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PySegmentedControl: PyControl {
    
    /// The segmented control associated with this object.
    @objc public var segmentedControl: UISegmentedControl {
        return get {
            return self.managed as! UISegmentedControl
        }
    }
    
    public override class var pythonName: String {
        return "SegmentedControl"
    }
    
    @objc public var segments: NSArray {
        get {
            return get {
                let num = self.segmentedControl.numberOfSegments
                var segments = [String]()
                for i in 0...num-1 {
                    segments.append(self.segmentedControl.titleForSegment(at: i) ?? "")
                }
                return NSArray(array: segments)
            }
        }
        
        set {
            set {
                self.segmentedControl.removeAllSegments()
                for (i, segment) in newValue.enumerated() {
                    self.segmentedControl.insertSegment(withTitle: (segment as? String) ?? "", at: i, animated: false)
                }
            }
        }
    }
    
    @objc public var selectedSegmentIndex: Int {
        get {
            return get {
                return self.segmentedControl.selectedSegmentIndex
            }
        }
        
        set {
            set {
                self.segmentedControl.selectedSegmentIndex = newValue
            }
        }
    }
    
    @objc override class func newView() -> PyView {
        let pyControl = PySegmentedControl()
        pyControl.managed = get {
            let control = UISegmentedControl()
            control.insertSegment(withTitle: "Foo", at: 0, animated: true)
            control.sizeToFit()
            control.removeAllSegments()
            control.addTarget(pyControl, action: #selector(PyControl.callAction), for: .valueChanged)
            PyView.values[control] = pyControl
            return control
        }
        return pyControl
    }
}
