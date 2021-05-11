//
//  PyLocationHelper.swift
//  Pyto
//
//  Created by Emma Labbé on 05-01-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import CoreLocation

/// A class for accessing location from Python.
@objc class PyLocationHelper: NSObject {
    
    #if WIDGET && !Xcode11
    /// The shared location manager.
    static let locationManager = CLLocationManager()
    #else
    /// The shared location manager.
    static var locationManager: CLLocationManager {
        #if WIDGET
        return ConsoleViewController.locationManager
        #else
        return AppDelegate.shared.locationManager
        #endif
    }
    #endif
    
    /// The latest longitude.
    @objc static var longitude: Float = 0
    
    /// The latest latitude.
    @objc static var latitude: Float =  0
    
    /// The latest altitude.
    @objc static var altitude: Float = 0
    
    /// A boolean indicating whether accessing location is allowed.
    @objc static var isAllowed: Bool {
        #if Xcode11
        return CLLocationManager.authorizationStatus() == .authorizedAlways || CLLocationManager.authorizationStatus() == .authorizedWhenInUse
        #else
        if #available(iOS 14.0, *) {
            return locationManager.authorizationStatus == .authorizedAlways || locationManager.authorizationStatus == .authorizedWhenInUse
        } else {
            return CLLocationManager.authorizationStatus() == .authorizedAlways || CLLocationManager.authorizationStatus() == .authorizedWhenInUse
        }
        #endif
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
                value = Float(locationManager.desiredAccuracy)
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
                locationManager.desiredAccuracy = Double(newValue)
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
            #if !Xcode11
            if locationManager.delegate == nil {
                let manager = PyLocationHelper()
                locationManager.delegate = manager
            }
            #endif
            locationManager.requestWhenInUseAuthorization()
            locationManager.startUpdatingLocation()
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
            locationManager.stopUpdatingLocation()
            #else
            (UIApplication.shared.delegate as? AppDelegate)?.locationManager.stopUpdatingLocation()
            #endif
        }
    }
}

#if WIDGET && !Xcode11
extension PyLocationHelper: CLLocationManagerDelegate {
    
    // MARK: - Location manager delegate
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.last else {
            return
        }
        
        PyLocationHelper.altitude = Float(location.altitude)
        PyLocationHelper.longitude = Float(location.coordinate.longitude)
        PyLocationHelper.latitude = Float(location.coordinate.latitude)
    }
}
#endif
