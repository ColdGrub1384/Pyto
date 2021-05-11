//
//  PyMultipeerHelper.swift
//  Pyto
//
//  Created by Emma Labbé on 21-01-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import MultiPeer
import UIKit

@objc class PyMultipeerHelper: NSObject, MultiPeerDelegate {
    
    static let delegate = PyMultipeerHelper()
    
    @objc static var data: String?
    
    @objc static func autoConnect() {
        MultiPeer.instance.initialize(serviceType: "pyto")
        MultiPeer.instance.delegate = delegate
        MultiPeer.instance.autoConnect()
    }
    
    @objc static func disconnect() {
        MultiPeer.instance.disconnect()
    }
    
    @objc static func send(_ data: String) {
        if !MultiPeer.instance.isConnected {
            MultiPeer.instance.autoConnect()
        }
        MultiPeer.instance.send(data: data.data(using: .utf8) ?? Data(), type: 0)
    }
    
    func multiPeer(didReceiveData data: Data, ofType type: UInt32) {
        PyMultipeerHelper.data = String(data: data, encoding: .utf8)
    }
    
    func multiPeer(connectedDevicesChanged devices: [String]) {}
}
