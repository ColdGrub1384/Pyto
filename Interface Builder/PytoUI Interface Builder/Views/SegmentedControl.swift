//
//  SegmentedControl.swift
//  InterfaceBuilder
//
//  Created by Emma on 03-09-22.
//

import UIKit

/// An `UISegmentedControl` creating from the interface builder
public class InterfaceBuilderSegmentedControl: UIView {
    
    var segmentedControl: UISegmentedControl!
    
    var selectedSegmentIndex: Int {
        get {
            segmentedControl.selectedSegmentIndex
        }
        
        set {
            segmentedControl.selectedSegmentIndex = newValue
        }
    }
    
    func setupSegmentedControl() {
        
        guard self.segmentedControl == nil else {
            return
        }
        
        let segmentedControl = UISegmentedControl()
        segmentedControl.frame.size.width = frame.height
        segmentedControl.frame.size.width = frame.width
        segmentedControl.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        addSubview(segmentedControl)
        
        self.segmentedControl = segmentedControl
    }
    
    public override var intrinsicContentSize: CGSize {
        segmentedControl?.intrinsicContentSize ?? .zero
    }
    
    public required init?(coder: NSCoder) {
        super.init(coder: coder)
        
        setupSegmentedControl()
        
        if let segments = coder.decodeObject(forKey: "segments") as? [String] {
            segmentedControl.removeAllSegments()
            for segment in segments.reversed() {
                segmentedControl.insertSegment(withTitle: segment, at: 0, animated: true)
            }
        }
        
        if let selectedSegment = coder.decodeObject(forKey: "selectedSegment") as? Int {
            segmentedControl?.selectedSegmentIndex = selectedSegment
        }
    }
    
    public override func encode(with coder: NSCoder) {
        segmentedControl?.removeFromSuperview()
        super.encode(with: coder)
        coder.encode(segmentedControl?.segmentsNames, forKey: "segments")
        coder.encode(segmentedControl?.selectedSegmentIndex, forKey: "selectedSegment")
        if let segmentedControl = segmentedControl {
            addSubview(segmentedControl)
        }
    }
    
    public override init(frame: CGRect) {
        super.init(frame: frame)
        
        setupSegmentedControl()
    }
    
    init() {
        super.init(frame: .zero)
        
        setupSegmentedControl()
    }
}

/// An segmented control.
public struct SegmentedControl: InterfaceBuilderView {
    
    public init() {}
    
    private func config(view: UISegmentedControl) {
        view.insertSegment(withTitle: "First", at: 0, animated: false)
        view.insertSegment(withTitle: "Second", at: 1, animated: false)
    }
    
    public var type: UIView.Type {
        return InterfaceBuilderSegmentedControl.self
    }
    
    public func preview(view: UIView) {
        guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
            return
        }
        
        config(view: segmentedControl)
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
            return
        }
        config(view: segmentedControl)
        segmentedControl.isEnabled = true
    }
    
    public var image: UIImage? {
        UIImage(systemName: "list.bullet")
    }
}

extension UISegmentedControl {
    
    public var segmentsNames: [String] {
        var segments = [String]()
        for i in 0..<numberOfSegments {
            segments.append(titleForSegment(at: i) ?? "")
        }
        return segments
    }
}

extension InterfaceBuilderSegmentedControl {
    
    @objc class var InterfaceBuilderSegmentedControl_properties: [Any] {
        return [
            
            InspectorProperty(name: "Segments",
                              valueType: .array(.string, {
                                  .init(value: "")
                              }),
                              getValue: { view in
                                  guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
                                      return .init(value: nil)
                                  }
                                  
                                  var segments = [String]()
                                  for i in 0..<segmentedControl.numberOfSegments {
                                      segments.append(segmentedControl.titleForSegment(at: i) ?? "")
                                  }
                                  
                                  return .init(value: segments)
                              }, handler: { view, value in
                                  guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
                                      return
                                  }
                                  
                                  guard let segments = value.value as? [String] else {
                                      return
                                  }
                                  
                                  segmentedControl.removeAllSegments()
                                  
                                  var i = 0
                                  for segment in segments {
                                      segmentedControl.insertSegment(withTitle: segment, at: i, animated: false)
                                      i += 1
                                  }
                                  
                                  NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                              }),
            
            InspectorProperty(name: "Selected Segment",
                              valueType: .dynamicEnumeration(.init(handler: { view in
                                  guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
                                      return []
                                  }
                                  
                                  return segmentedControl.segmentsNames+(segmentedControl.segmentsNames.contains("None") ? [] : ["None"])
                              })), getValue: { view in
                                  
                                  guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
                                      return .init(value: nil)
                                  }
                                  
                                  return .init(value: segmentedControl.segmentsNames.indices.contains(segmentedControl.selectedSegmentIndex) ? segmentedControl.segmentsNames[segmentedControl.selectedSegmentIndex] : "None")
                              }, handler: { view, value in
                                  guard let segmentedControl = (view as? InterfaceBuilderSegmentedControl)?.segmentedControl else {
                                      return
                                  }
                                  
                                  guard let name = value.value as? String else {
                                      return
                                  }
                                  
                                  if name == "None" {
                                      segmentedControl.selectedSegmentIndex = UISegmentedControl.noSegment
                                  } else if let i = segmentedControl.segmentsNames.firstIndex(of: name) {
                                      segmentedControl.selectedSegmentIndex = i
                                  }
                                  
                                  segmentedControl.sendActions(for: .valueChanged)
                              })
        ]
    }
    
    @objc class var InterfaceBuilderSegmentedControl_connections: [String] {
        ["action"]
    }
}
