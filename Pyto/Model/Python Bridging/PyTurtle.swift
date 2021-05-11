//
//  PyTurtle.swift
//  Pyto
//
//  Created by Emma Labbé on 07-03-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *)
@objc class PyTurtle: NSObject {
    
    @objc var path = UIBezierPath()
    
    @objc var shapeLayer = CAShapeLayer()
    
    @objc var tilt: CGFloat = 0
    
    @objc var speed: Int = 6
    
    override init() {
        super.init()
        
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            self.shapeLayer.strokeColor = self.color.cgColor
            self.shapeLayer.fillColor = self.fillColor.cgColor
            self.shapeLayer.frame.size = self.size
            self.view.backgroundColor = PyColor(managed: UIColor.white)
            self.view.title = "Turtle"
            
            self.path.move(to: CGPoint(x: self.size.width/2, y: self.size.height/2))
            
            self.arrowView.image = UIImage(systemName: "location.north.fill")
            self.arrowView.tintColor = PyColor(managed: self.color)
            self.arrowView.width = 20
            self.arrowView.height = 20
            let transform = CGAffineTransform(rotationAngle: (CGFloat((Double(self.rotation+90)) / 180.0 * Double.pi)))
            self.arrowView.imageView.transform = transform
            self.view.addSubview(self.arrowView)
        }
    }
    
    var lastImage: UIImage?
    
    func drawTurtle() {
        UIGraphicsBeginImageContextWithOptions(self.shapeLayer.frame.size, self.shapeLayer.isOpaque, 0)
        guard let ctx = UIGraphicsGetCurrentContext() else {
            return
        }
        self.shapeLayer.render(in: ctx)
        lastImage?.draw(at: .zero)
        let image = UIGraphicsGetImageFromCurrentImageContext()
        lastImage = image
        self.view.view.layer.contents = image?.cgImage
        UIGraphicsEndImageContext()
    }
    
    @objc func setTiltAngle(_ angle: CGFloat) {
        self.tilt = angle
        DispatchQueue.main.sync {
            let transform = CGAffineTransform(rotationAngle: (CGFloat((Double(angle)) / 180.0 * Double.pi)))
            self.arrowView.imageView.transform = transform
        }
    }
    
    @objc var view = PyView.newView()
    
    @objc var arrowView = PyImageView.newView() as! PyImageView
    
    @objc var rotation: CGFloat = 0 {
        didSet {
            if rotation == -181 {
                rotation = 179
            } else if rotation == 181 {
                rotation = -179
            }
            
            DispatchQueue.main.async { [weak self] in
                
                guard let self = self else {
                    return
                }
                
                let transform = CGAffineTransform(rotationAngle: (CGFloat((Double(self.rotation+90)) / 180.0 * Double.pi)))
                self.arrowView.imageView.transform = transform
            }
        }
    }
    
    @objc var size = CGSize(width: 300, height: 300) {
        didSet {
            DispatchQueue.main.async { [weak self] in
                
                guard let self = self else {
                    return
                }
                
                self.view.width = Double(self.size.width)
                self.view.height = Double(self.size.height)
            }
        }
    }
    
    @objc var _position = CGPoint.zero {
        didSet {
            DispatchQueue.main.async { [weak self] in
                
                guard let self = self else {
                    return
                }
                
                self.arrowView.centerX = Double(self._position.x)
                self.arrowView.centerY = Double(self._position.y)
            }
        }
    }
    
    @objc var penOn = true {
        didSet {
            path.move(to: _position)
        }
    }
    
    @objc var isFilling: Bool {
        return (fillColor != UIColor.clear)
    }
        
    @objc var color = UIColor.black {
        didSet {
            self.shapeLayer.strokeColor = self.color.cgColor
            self.arrowView.tintColor = PyColor(managed: self.color)
        }
    }
    
    @objc var colorValues: NSArray {
        var red: CGFloat = 0
        var green: CGFloat = 0
        var blue: CGFloat = 0
        color.getRed(&red, green: &green, blue: &blue, alpha: nil)
        return NSArray(array: [red*255, green*255, blue*255])
    }
    
    @objc var fillColorValues: NSArray {
        var red: CGFloat = 0
        var green: CGFloat = 0
        var blue: CGFloat = 0
        fillColor.getRed(&red, green: &green, blue: &blue, alpha: nil)
        return NSArray(array: [red*255, green*255, blue*255])
    }
    
    @objc var _fillColor = UIColor.clear
    
    @objc var fillColor = UIColor.clear {
        didSet {
            DispatchQueue.main.async { [weak self] in
                
                guard let self = self else {
                    return
                }
                
                let color: UIColor
                if self.fillColor == UIColor.clear {
                    color = .white
                } else {
                    color = self.fillColor
                }
                self.shapeLayer.fillColor = color.cgColor
            }
        }
    }
    
    @objc func position() -> CGPoint {
        return CGPoint(x: _position.x-(size.width/2), y: _position.y-(size.height/2))
    }
    
    @objc func right(_ degrees: CGFloat) {
        if degrees < 0 {
            return left(-degrees)
        }
        
        rotation += degrees
    }
    
    @objc func left(_ degrees: CGFloat) {
        if degrees < 0 {
            return right(-degrees)
        }
        
        rotation -= degrees
    }
    
    @objc func forward(_ steps: CGFloat) {
        DispatchQueue.main.sync {
            let pos = CGPoint(x: Double(self._position.x)+(cos(Double(self.rotation)*Double.pi/180)*Double(steps)), y: Double(self._position.y)+(sin(Double(self.rotation)*Double.pi/180))*Double(steps))
            self._position = pos
            if self.penOn {
                self.path.addLine(to: pos)
                self.shapeLayer.path = self.path.cgPath
                self.drawTurtle()
            }
        }
        if speed != 0 && speed != 10 {
            var delay = 0.009
            for _ in 1...speed {
                delay -= 0.001
            }
            Thread.sleep(forTimeInterval: delay)
        }
    }
    
    @objc func goto(_ pos: CGPoint) {
        self._position = CGPoint(x: pos.x+(self.size.width/2), y: pos.y+(self.size.width/2))
        self.path.move(to: self._position)
        if self.penOn {
            self.path.addLine(to: self._position)
            self.drawTurtle()
        }
    }
    
    @objc func color(red: CGFloat, green: CGFloat, blue: CGFloat) {
        color = UIColor(displayP3Red: red/255, green: green/255, blue: blue/255, alpha: 1)
    }
    
    @objc func fillColor(red: CGFloat, green: CGFloat, blue: CGFloat) {
        _fillColor = UIColor(displayP3Red: red/255, green: green/255, blue: blue/255, alpha: 1)
    }
    
    @objc func reset() {
        self.rotation = 0
        self._position = .zero
        self.penOn = true
    }
    
    @objc func clear() {
        self.path = UIBezierPath()
        self.shapeLayer = CAShapeLayer()
        self.lastImage = nil
        self.goto(self.position())
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            self.shapeLayer.strokeColor = self.color.cgColor
            self.shapeLayer.fillColor = self.fillColor.cgColor
            self.shapeLayer.frame.size = self.size
            self.view.view.layer.contents = nil
        }
    }
    
    @objc func setPenSize(_ size: CGFloat) {
        self.path.lineWidth = size
        self.shapeLayer.lineWidth = size
    }
}
