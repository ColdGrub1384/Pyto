//
//  PyMotionManager.swift
//  Pyto
//
//  Created by Emma Labbé on 07-02-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import CoreMotion

/// A class for accessing motion sensors.
@objc class PyMotionHelper: NSObject {
    
    private static let motionManager = CMMotionManager()
    
    /// Starts receiving updates.
    @objc static func startUpdating() {
        motionManager.startGyroUpdates()
        motionManager.startMagnetometerUpdates()
        motionManager.startAccelerometerUpdates()
        motionManager.startDeviceMotionUpdates()
    }
    
    /// Stops receiving updates.
    @objc static func stopUpdating() {
        motionManager.stopGyroUpdates()
        motionManager.stopMagnetometerUpdates()
        motionManager.stopAccelerometerUpdates()
        motionManager.stopDeviceMotionUpdates()
    }
    
    /// Returns the gravity.
    @objc static var gravity: NSArray {
        guard let gravity = motionManager.deviceMotion?.gravity else {
            return [0, 0, 0]
        }
        return [gravity.x, gravity.y, gravity.z]
    }
    
    /// Returns the rotation.
    @objc static var rotation: NSArray {
        guard let rotation = motionManager.gyroData?.rotationRate else {
            return [0, 0, 0]
        }
        return [rotation.x, rotation.y, rotation.z]
    }
    
    /// Returns the acceleration.
    @objc static var acceleration: NSArray {
        guard let acceleration = motionManager.accelerometerData?.acceleration else {
            return [0, 0, 0]
        }
        return [acceleration.x, acceleration.y, acceleration.z]
    }
    
    /// Returns the magnetic field.
    @objc static var magneticField: NSArray {
        guard let magneticField = motionManager.magnetometerData?.magneticField else {
            return [0, 0, 0]
        }
        return [magneticField.x, magneticField.y, magneticField.z]
    }
    
    /// Returns the attitude.
    @objc static var attitude: NSArray {
        guard let attitude = motionManager.deviceMotion?.attitude else {
            return [0, 0, 0]
        }
        return [attitude.roll, attitude.pitch, attitude.yaw]
    }
}
