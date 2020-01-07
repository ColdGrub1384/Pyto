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
