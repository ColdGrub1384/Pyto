//
//  PySegmentedControl.swift
//  Pyto
//
//  Created by Emma Labbé on 17-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import InterfaceBuilder

@available(iOS 13.0, *) @objc public class PySegmentedControl: PyControl {
    
    /// The segmented control associated with this object.
    @objc public var segmentedControl: UISegmentedControl {
        return get {
            return ((self.managed as? UIView)?.subviews.first(where: { $0 is UISegmentedControl }) as? UISegmentedControl) ?? self.managed as! UISegmentedControl
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
    
    public override var action: PyValue? {
        didSet {
            set {
                if !self.segmentedControl.allTargets.contains(self) {
                    self.segmentedControl.addTarget(self, action: #selector(PyControl.callAction), for: .valueChanged)
                }
            }
        }
    }
    
    public required init(managed: NSObject!) {
        super.init(managed: managed)
        
        if !self.segmentedControl.allTargets.contains(self) {
            self.segmentedControl.addTarget(self, action: #selector(PyControl.callAction), for: .valueChanged)
        }
    }
    
    init() {
        super.init()
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
