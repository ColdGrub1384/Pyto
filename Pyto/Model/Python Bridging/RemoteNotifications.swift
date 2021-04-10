//
//  RemoteNotifications.swift
//  Pyto
//
//  Created by Emma Labbé on 02-05-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import UIKit
import UserNotifications

@objc class RemoteNotifications: NSObject {
    
    @objc static var deviceToken: String?
    
    @objc static var error: String?
    
    @objc static func removeCategory(_ id: String) {
        DispatchQueue.main.async {
            UNUserNotificationCenter.current().getNotificationCategories { categories in
                
                var new = [UNNotificationCategory]()
                
                for category in categories {
                    if category.identifier != id {
                        new.append(category)
                    }
                }
                
                UNUserNotificationCenter.current().setNotificationCategories(Set(new))
            }
        }
    }
    
    @objc static func addCategory(_ id: String, actions: [String:String]) {
        UNUserNotificationCenter.current().getNotificationCategories { categories in
            
            var notificationActions = [UNNotificationAction]()
            
            for action in actions {
                notificationActions.append(UNNotificationAction(identifier: action.value, title: action.key, options: .foreground))
            }
                        
            var new = [UNNotificationCategory]()
            
            for category in categories {
                if category.identifier != id {
                    new.append(category)
                }
            }
            
            let category = UNNotificationCategory(identifier: id, actions: notificationActions, intentIdentifiers: [], hiddenPreviewsBodyPlaceholder: "", options: [])
            
            new.append(category)
            
            UNUserNotificationCenter.current().setNotificationCategories(Set(new))
        }
    }
    
    @objc static func register() {
        DispatchQueue.main.async {
            UNUserNotificationCenter.current().getNotificationSettings { (settings) in
                if settings.authorizationStatus == .denied {
                    RemoteNotifications.error = "Notifications are disabled."
                } else if settings.authorizationStatus == .notDetermined {
                    UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { (success, error) in
                        RemoteNotifications.error = error?.localizedDescription
                        if !success && error == nil {
                            RemoteNotifications.error = "Notifications are disabled."
                        }
                        
                        if RemoteNotifications.error == nil {
                            DispatchQueue.main.async {
                                UIApplication.shared.registerForRemoteNotifications()
                            }
                        }
                    }
                } else {
                    DispatchQueue.main.async {
                        UIApplication.shared.registerForRemoteNotifications()
                    }
                }
            }
        }
    }
}
