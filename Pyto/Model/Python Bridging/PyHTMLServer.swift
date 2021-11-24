//
//  PyHTMLServer.swift
//  Pyto
//
//  Created by Emma on 04-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import GCDWebServer
import Foundation

/// A web server for serving local files while running pyhtml files.
@objc class PyHTMLServer: NSObject {
    
    static var runningPorts = [UInt]()
    
    @objc var server: GCDWebServer!
    
    @objc var port: UInt = 3100
    
    @objc var url: URL {
        URL(string: "http://localhost:\(port)")!
    }
    
    @objc var directory = ""
    
    @objc func start() {
        
        while Self.runningPorts.contains(port) {
            port += 1
        }
        
        Self.runningPorts.append(port)
        DispatchQueue.main.async { [weak self] in
            if self?.server == nil {
                self?.server = GCDWebServer()
            }
            
            self?.server.addDefaultHandler(forMethod: "GET", request: GCDWebServerRequest.self) { request in
                let path = URL(fileURLWithPath: self?.directory ?? "").appendingPathComponent(request.path).path
                
                if FileManager.default.fileExists(atPath: path) {
                                    
                    if path.lowercased().hasSuffix(".pyhtml") {
                        return GCDWebServerDataResponse(html: (try? String(contentsOfFile: path)) ?? "")
                    } else {
                        return GCDWebServerFileResponse(file: path)
                    }
                } else {
                    return GCDWebServerResponse(statusCode: 404)
                }
            }
            
            try? self?.server.start(options: [
                GCDWebServerOption_Port : self?.port ?? 0
            ])
        }
    }
    
    @objc func stop() {
        if let i = Self.runningPorts.firstIndex(of: port) {
            Self.runningPorts.remove(at: i)
        }
        DispatchQueue.main.async { [weak self] in
            if self?.server.isRunning == true {
                self?.server.stop()
            }
        }
    }
}
