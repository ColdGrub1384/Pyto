//
//  SessionDelegate.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 04-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WatchKit
import WatchConnectivity

/// A delegate for the WatchConnectivity session.
class SessionDelegate: NSObject, WCSessionDelegate {
    
    /// The shared instance.
    static let shared = SessionDelegate()
    
    private override init() {}
    
    /// The console for the current running script.
    var console = ""
    
    // MARK: - Session delegate
        
    func session(_ session: WCSession, activationDidCompleteWith activationState: WCSessionActivationState, error: Error?) {
                
        if let error = error {
            (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(error.localizedDescription)
        } else {
            (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText("")
            console = ""
            WCSession.default.sendMessageData("Run".data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: { error in
                (WKExtension.shared().rootInterfaceController as? InterfaceController)?.label.setText(error.localizedDescription)
            })
        }
    }
    
    func session(_ session: WCSession, didReceiveMessageData messageData: Data) {
        
        let str = (String(data: messageData, encoding: .utf8) ?? "")
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
        if let data = try? Data(contentsOf: file.fileURL), let image = UIImage(data: data) {
            DispatchQueue.main.async {
                WKExtension.shared().rootInterfaceController?.pushController(withName: "Image", context: image)
            }
        }
    }
}
