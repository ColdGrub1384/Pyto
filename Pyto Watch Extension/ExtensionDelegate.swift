//
//  ExtensionDelegate.swift
//  Pyto Watch Extension
//
//  Created by Emma Labbé on 04-02-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
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
    
    func applicationWillEnterForeground() {
        if PyWatchUI.cachedView != nil {
            PyWatchUI.showView()
        }
        
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
    
    func applicationDidEnterBackground() {
        WCSession.default.sendMessageData("Stop".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
        WKExtension.shared().visibleInterfaceController?.dismiss()
    }
    
    func handle(_ backgroundTasks: Set<WKRefreshBackgroundTask>) {
        for task in backgroundTasks {
            switch task {
            case let backgroundTask as WKApplicationRefreshBackgroundTask:
                
                lastScheduledRefresh = nil
                
                WCSession.default.sendMessage(["Called": "handle"], replyHandler: nil, errorHandler: nil)
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
