//
//  PyNotificationCenter.swift
//  Pyto
//
//  Created by Adrian Labbé on 16-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import UserNotifications

/// A class managing Today widget settings.
@available(iOS 13.0, *) @objc class PyNotificationCenter: NSObject {
    
    #if MAIN
    /// Set to `true` to make the widget able to expand.
    @objc static var canBeExpanded: Bool {
        set {
            #if WIDGET
            ConsoleViewController.visible.canBeExpanded = newValue
            #else
            WidgetSimulatorViewController.canBeExpanded = newValue
            #endif
        }
        
        get {
            #if WIDGET
            return ConsoleViewController.visible.canBeExpanded
            #else
            return WidgetSimulatorViewController.canBeExpanded
            #endif
        }
    }
    
    /// The widget's maximum height.
    @objc static var maximumHeight: Double {
        set {
            #if WIDGET
            ConsoleViewController.visible.maximumHeight = newValue
            #else
            WidgetSimulatorViewController.maximumHeight = newValue
            #endif
        }
        
        get {
            #if WIDGET
            return ConsoleViewController.visible.maximumHeight
            #else
            return WidgetSimulatorViewController.maximumHeight
            #endif
        }
    }
    #endif
    
    @objc static var scheduled: [UNNotificationRequest] {
        
        let semaphore = DispatchSemaphore(value: 0)
        
        var notifications = [UNNotificationRequest]()
        
        UNUserNotificationCenter.current().getPendingNotificationRequests { (requests) in
            for request in requests {
                notifications.append(request)
            }
            semaphore.signal()
        }
        
        semaphore.wait()
        
        return notifications
    }
    
    static func scheduleNotification(title: String, message: String, delay: Double) {
        UNUserNotificationCenter.current().getNotificationSettings { (settings) in
            if settings.authorizationStatus == .notDetermined {
                UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { (_, _) in
                    self.scheduleNotification(title: title, message: message, delay: delay)
                }
            } else {
                
                let notification = UNMutableNotificationContent()
                notification.title = title
                notification.body = message
                notification.sound = UNNotificationSound.default
                
                let trigger = UNTimeIntervalNotificationTrigger(timeInterval: delay, repeats: false)
                let request = UNNotificationRequest(identifier: UUID().uuidString, content: notification, trigger: trigger)
                UNUserNotificationCenter.current().add(request, withCompletionHandler: nil)
            }
        }
    }
    
    @objc static func scheduleNotification(message: String, delay: Double, url: String?, actions: [String:String]?, repeats: Bool) {
        UNUserNotificationCenter.current().getNotificationSettings { (settings) in
            if settings.authorizationStatus == .notDetermined {
                UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { (_, _) in
                    self.scheduleNotification(message: message, delay: delay, url: url, actions: actions, repeats: repeats)
                }
            } else {
                
                UNUserNotificationCenter.current().getNotificationCategories { (categories) in
                    
                    let notification = UNMutableNotificationContent()
                    notification.body = message
                    notification.sound = UNNotificationSound.default
                    notification.userInfo["url"] = url
                    notification.userInfo["actions"] = actions
                    
                    if let actions = actions {
                        var notificationActions = [UNNotificationAction]()
                        
                        for action in actions {
                            notificationActions.append(UNNotificationAction(identifier: action.value, title: action.key, options: .foreground))
                        }
                        
                        let id = UUID().uuidString
                        
                        var newCategories = Array(categories)
                        newCategories.append(UNNotificationCategory(identifier: id, actions: notificationActions, intentIdentifiers: [], hiddenPreviewsBodyPlaceholder: "", options: []))
                        UNUserNotificationCenter.current().setNotificationCategories(Set(newCategories))
                        
                        notification.categoryIdentifier = id
                    }
                    
                    let trigger = UNTimeIntervalNotificationTrigger(timeInterval: delay, repeats: repeats)
                    let request = UNNotificationRequest(identifier: UUID().uuidString, content: notification, trigger: trigger)
                    UNUserNotificationCenter.current().add(request, withCompletionHandler: nil)
                }
            }
        }
    }
}
