//
//  SessionDelegate.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 04-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WatchKit
import WatchConnectivity
import ClockKit

/// A delegate for the WatchConnectivity session.
class SessionDelegate: NSObject, WCSessionDelegate {
    
    /// The shared instance.
    static let shared = SessionDelegate()
    
    private override init() {}
    
    /// The console for the current running script.
    var console = ""
    
    /// Code called when the session finished activating.
    var didActivate: (() -> Void)?
    
    var complicationsHandlers = [String: ((Data) -> Void)]()
    
    // MARK: - Session delegate
    
    func session(_ session: WCSession, activationDidCompleteWith activationState: WCSessionActivationState, error: Error?) {
        if let error = error {
            (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(error.localizedDescription)
        } else {
            didActivate?()
        }
    }
    
    func session(_ session: WCSession, didReceiveUserInfo userInfo: [String : Any] = [:]) {
        WCSession.default.sendMessage(["Received":userInfo], replyHandler: nil, errorHandler: nil)
        if (userInfo["Reload"] as? String) == "All" {
            for complication in CLKComplicationServer.sharedInstance().activeComplications ?? [] {
                CLKComplicationServer.sharedInstance().reloadTimeline(for: complication)
            }
        } else if (userInfo["Reload"] as? String) == "Descriptors" {
            CLKComplicationServer.sharedInstance().reloadComplicationDescriptors()
        }
    }
    
    func session(_ session: WCSession, didReceiveMessage message: [String : Any]) {
        
    }
    
    func session(_ session: WCSession, didReceiveMessageData messageData: Data) {
        
        var str = (String(data: messageData, encoding: .utf8) ?? "")
        
        if str.hasPrefix("\r") {
            if console.hasSuffix("\n") {
                str = str.components(separatedBy: "\r").last ?? str
            }
            
            str = "\r\(str.components(separatedBy: "\r").last ?? str)"
            
            if console.contains("\n") || console.contains("\r") {
                var comp = console.components(separatedBy: "\n")
                if comp.count > 0 {
                    comp.removeLast()
                }
                console = comp.joined(separator: "\n")
            }
            
        } else if str.contains("\r") {
            str = str.components(separatedBy: "\r").last ?? str
        }
        
        console += str
        (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(console)
    }
    
    func session(_ session: WCSession, didReceiveMessage message: [String : Any], replyHandler: @escaping ([String : Any]) -> Void) {
        if message["prompt"] != nil {
            DispatchQueue.main.async {
                WKExtension.shared().rootInterfaceController?.presentTextInputController(withSuggestions: (message["suggestions"] as? [String]) ?? ["yes", "no"], allowedInputMode: .plain, completion: { (result) in
                    if let str = result?.first as? String {
                        self.console += "\(str)\n"
                        (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(self.console)
                        replyHandler(["input": str])
                    } else {
                        replyHandler(["input": ""])
                    }
                })
            }
        }
    }
    
    func session(_ session: WCSession, didReceive file: WCSessionFile) {
        if let data = try? Data(contentsOf: file.fileURL) {
            if let image = UIImage(data: data) {
                DispatchQueue.main.async {
                    WKExtension.shared().rootInterfaceController?.pushController(withName: "Image", context: image)
                }
            } else if let id = file.metadata?["id"] as? String {
                complicationsHandlers[id]?(data)
                complicationsHandlers[id] = nil
            } else {
                do {
                    
                    if FileManager.default.fileExists(atPath: PyWatchUI.cacheURL.path) {
                        try? FileManager.default.removeItem(at: PyWatchUI.cacheURL)
                    }
                    
                    if file.metadata?["Remove"] != nil {
                        let controller = WKExtension.shared().visibleInterfaceController
                        if controller is WatchHostingController {
                            controller?.dismiss()
                        }
                    } else if WKExtension.shared().applicationState == .active {
                        try FileManager.default.moveItem(at: file.fileURL, to: PyWatchUI.cacheURL)
                        PyWatchUI.showView()
                    }
                } catch {
                    WCSession.default.sendMessage(["error": error.localizedDescription], replyHandler: nil, errorHandler: nil)
                }
            }
        }
    }
}
