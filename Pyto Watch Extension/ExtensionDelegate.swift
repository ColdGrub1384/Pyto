//
//  ExtensionDelegate.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 04-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WatchKit
import WatchConnectivity
import ClockKit

/// The delegate of the Watch extension.
class ExtensionDelegate: NSObject, WKExtensionDelegate {

    override init() {
        super.init()
        
        WCSession.default.delegate = SessionDelegate.shared
        WCSession.default.activate()
    }
<<<<<<< HEAD
    
    func applicationWillEnterForeground() {
        if PyWatchUI.cachedView != nil {
            PyWatchUI.showView()
        }
=======

    func applicationDidBecomeActive() {
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
        
        if WCSession.default.activationState != .activated {
            
            SessionDelegate.shared.didActivate = {
                (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText("")
                SessionDelegate.shared.console = ""
                WCSession.default.sendMessageData("Run".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: { error in
                    (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(error.localizedDescription)
                })
            }
            
            WCSession.default.delegate = SessionDelegate.shared
            WCSession.default.activate()
        } else {
            (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText("")
            SessionDelegate.shared.console = ""
            WCSession.default.sendMessageData("Run".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
        }
    }
<<<<<<< HEAD
    
    func applicationDidEnterBackground() {
        WCSession.default.sendMessageData("Stop".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
        WKExtension.shared().visibleInterfaceController?.dismiss()
    }
    
=======

    func applicationWillResignActive() {
        WCSession.default.sendMessageData("Stop".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
    }

>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    func handle(_ backgroundTasks: Set<WKRefreshBackgroundTask>) {
        for task in backgroundTasks {
            switch task {
            case let backgroundTask as WKApplicationRefreshBackgroundTask:
<<<<<<< HEAD
                
                lastScheduledRefresh = nil
                
                WCSession.default.sendMessage(["Called": "handle"], replyHandler: nil, errorHandler: nil)
=======
                WCSession.default.sendMessage(["Called": "handle"], replyHandler: nil, errorHandler: nil)
                ComplicationController.cache = [:]
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
                for complication in CLKComplicationServer.sharedInstance().activeComplications ?? [] {
                    CLKComplicationServer.sharedInstance().extendTimeline(for: complication)
                }
                backgroundTask.setTaskCompletedWithSnapshot(false)
            default:
                task.setTaskCompletedWithSnapshot(false)
            }
        }
    }

}
