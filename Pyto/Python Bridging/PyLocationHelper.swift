//
//  PyLocationHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 05-01-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import CoreLocation

/// A class for accessing location from Python.
@objc class PyLocationHelper: NSObject {
    
    /// The latest longitude.
    @objc static var longitude: Float = 0
    
    /// The latest latitude.
    @objc static var latitude: Float =  0
    
    /// The latest altitude.
    @objc static var altitude: Float = 0
    
    /// A boolean indicating whether accessing location is allowed.
    @objc static var isAllowed: Bool {
        return CLLocationManager.authorizationStatus() == .authorizedAlways || CLLocationManager.authorizationStatus() == .authorizedWhenInUse
    }
    
    /// The number of meters from the original geographic coordinate that could yield the user's actual location.
    @objc static var desiredAccuracy: Float {
        get {
            
            let semaphore = DispatchSemaphore(value: 0)
            
            var value: Float = 0 {
                didSet {
                    semaphore.signal()
                }
            }
            
            DispatchQueue.main.async {
                #if WIDGET
                value = Float(ConsoleViewController.locationManager.desiredAccuracy)
                #else
                value = Float((UIApplication.shared.delegate as? AppDelegate)?.locationManager.desiredAccuracy ?? 0)
                #endif
            }
            
            semaphore.wait()
            
            return value
        }
        
        set {
            DispatchQueue.main.async {
                #if WIDGET
                ConsoleViewController.locationManager.desiredAccuracy = Double(newValue)
                #else
                (UIApplication.shared.delegate as? AppDelegate)?.locationManager.desiredAccuracy = Double(newValue)
                #endif
            }
        }
    }
    
    /// Starts updating location.
    @objc static func startUpdating() {
        DispatchQueue.main.async {
            #if WIDGET
            ConsoleViewController.locationManager.requestWhenInUseAuthorization()
            ConsoleViewController.locationManager.startUpdatingLocation()
            #else
            (UIApplication.shared.delegate as? AppDelegate)?.locationManager.requestWhenInUseAuthorization()
            (UIApplication.shared.delegate as? AppDelegate)?.locationManager.startUpdatingLocation()
            #endif
        }
    }
    
    /// Stops updating location.
    @objc static func stopUpdating() {
        DispatchQueue.main.async {
            #if WIDGET
            ConsoleViewController.locationManager.stopUpdatingLocation()
            #else
            (UIApplication.shared.delegate as? AppDelegate)?.locationManager.stopUpdatingLocation()
            #endif
        }
    }
}
