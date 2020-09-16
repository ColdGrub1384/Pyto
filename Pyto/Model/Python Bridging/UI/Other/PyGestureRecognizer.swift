//
//  PyGestureRecognizer.swift
//  Pyto
//
//  Created by Adrian Labbé on 15-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A Python wrapper for `UIGestureRecognizer`.
@available(iOS 13.0, *) @objc public class PyGestureRecognizer: PyWrapper {
    
    @objc public var action: PyValue?
    
    @objc public var managedValue: PyValue?
    
    @objc public func callAction(_ sender: UIGestureRecognizer) {
        guard let action = action, let param = managedValue else {
            return
        }
        
        var x = [Float]()
        var y = [Float]()
        
        if sender.numberOfTouches > 0 {
            for i in 0...sender.numberOfTouches-1 {
                let point = sender.location(ofTouch: i, in: view?.view)
                x.append(Float(point.x))
                y.append(Float(point.y))
            }
        } else {
            let point = sender.location(in: nil)
            x.append(Float(point.x))
            y.append(Float(point.y))
        }

        let code = """
        import _values
        
        param = _values.\(param.identifier)
        
        try:
            from pyto_ui import GestureRecognizer
        
            if param.__class__.__name__ == "GestureRecognizer":
                param = GestureRecognizer(param.__py_gesture__)
                param.__number_of_touches__ = \(sender.numberOfTouches)
                param.__state__ = \(sender.state.rawValue)
                param.__x__ = \(x)
                param.__y__ = \(y)
        
        except ImportError:
            pass
        
        _values.\(action.identifier)(param)
        """
        
        Python.shared.run(code: code)
    }
    
    @objc public var view: PyView? {
        return get {
            if let view = self.gestureRecognizer.view {
                return PyView(managed: view)
            } else {
                return nil
            }
        }
    }
    
    @objc public func xLocation() -> Double {
        return get {
            return Double(self.gestureRecognizer.location(in: self.view?.view).x)
        }
    }
    
    @objc public func yLocation() -> Double {
        return get {
            return Double(self.gestureRecognizer.location(in: self.view?.view).y)
        }
    }
    
    @objc public func xLocationOfTouch(_ touch: Int) -> Double {
        return get {
            return Double(self.gestureRecognizer.location(ofTouch: touch, in: self.view?.view).x)
        }
    }
    
    @objc public func yLocationOfTouch(_ touch: Int) -> Double {
        return get {
            return Double(self.gestureRecognizer.location(ofTouch: touch, in: self.view?.view).y)
        }
    }
    
    @objc public var numberOfTouches: Int {
        return get {
            return self.gestureRecognizer.numberOfTouches
        }
    }
    
    @objc public var state: Int {
        return get {
            return self.gestureRecognizer.state.rawValue
        }
    }
    
    @objc public var enabled: Bool {
        get {
            return get {
                return self.gestureRecognizer.isEnabled
            }
        }
        
        set {
            set {
                self.gestureRecognizer.isEnabled = newValue
            }
        }
    }
    
    @objc public var requiresExclusiveTouchType: Bool {
        get {
            return get {
                return self.gestureRecognizer.requiresExclusiveTouchType
            }
        }
        
        set {
            set {
                self.gestureRecognizer.requiresExclusiveTouchType = newValue
            }
        }
    }
    
    @objc public var delaysTouchesEnded: Bool {
        get {
            return get {
                return self.gestureRecognizer.delaysTouchesEnded
            }
        }
        
        set {
            set {
                self.gestureRecognizer.delaysTouchesEnded = newValue
            }
        }
    }
    
    @objc public var delaysTouchesBegan: Bool {
        get {
            return get {
                return self.gestureRecognizer.delaysTouchesBegan
            }
        }
        
        set {
            set {
                self.gestureRecognizer.delaysTouchesBegan = newValue
            }
        }
    }
    
    @objc public var cancelsTouchesInView: Bool {
        get {
            return get {
                return self.gestureRecognizer.cancelsTouchesInView
            }
        }
        
        set {
            set {
                self.gestureRecognizer.cancelsTouchesInView = newValue
            }
        }
    }
    
    @objc public var allowedTouchTypes: NSArray {
        get {
            return get {
                let touches = self.gestureRecognizer.allowedTouchTypes
                var pythonic = [Int]()
                
                for touch in touches {
                    pythonic.append(touch.intValue)
                }
                
                return NSArray(array: pythonic)
            }
        }
        
        set {
            
            guard let newValue = newValue as? [Int] else {
                return
            }
            
            set {
                var touches = [NSNumber]()
                
                for touch in newValue {
                    touches.append(NSNumber(value: touch))
                }
                
                self.gestureRecognizer.allowedTouchTypes = touches
            }
        }
    }
    
    @objc public var minimumDuration: Double {
        get {
            return get {
                return (self.gestureRecognizer as? UILongPressGestureRecognizer)?.minimumPressDuration ?? 0
            }
        }
        
        set {
            set {
                (self.gestureRecognizer as? UILongPressGestureRecognizer)?.minimumPressDuration = newValue
            }
        }
    }
    
    /// The gesture recognizer associated with this object.
    @objc public var gestureRecognizer: UIGestureRecognizer {
        return get {
            return self.managed as! UIGestureRecognizer
        }
    }
    
    override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        DispatchQueue.main.async {
            (managed as? UIGestureRecognizer)?.addTarget(self, action: #selector(self.callAction(_:)))
        }
    }
    
    /// Creates a new gesture recognizer.
    ///
    /// - Returns: A newly initialized gesture recognizer of given class.
    @objc class func newRecognizer(type: UIGestureRecognizer.Type) -> PyGestureRecognizer {
        return PyGestureRecognizer(managed: get {
            return type.init()
        })
    }
    
    @objc public static let TouchTypeDirect = UITouch.TouchType.direct
    
    @objc public static let TouchTypeIndirect = UITouch.TouchType.indirect
    
    @objc public static let TouchTypePencil = UITouch.TouchType.pencil
    
    
    @objc public static let GestureStatePossible = UIGestureRecognizer.State.possible
    
    @objc public static let GestureStateBegan = UIGestureRecognizer.State.began
    
    @objc public static let GestureStateChanged = UIGestureRecognizer.State.changed
    
    @objc public static let GestureStateEnded = UIGestureRecognizer.State.ended
    
    @objc public static let GestureStateCancelled = UIGestureRecognizer.State.cancelled
    
    @objc public  static let GestureStateRecognized = UIGestureRecognizer.State.recognized
}

