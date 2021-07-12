//
//  FocusSystemObserver.swift
//  Pyto
//
//  Created by Emma Labbé on 27-06-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

fileprivate protocol FileMonitorDelegate: AnyObject {
    func didReceive(changes: String)
}

/// https://swiftrocks.com/dispatchsource-detecting-changes-in-files-and-folders-in-swift.html
fileprivate class FileMonitor {

    let url: URL

    let fileHandle: FileHandle
    let source: DispatchSourceFileSystemObject

    weak var delegate: FileMonitorDelegate?

    init(url: URL) throws {
        self.url = url
        self.fileHandle = try FileHandle(forReadingFrom: url)

        source = DispatchSource.makeFileSystemObjectSource(
            fileDescriptor: fileHandle.fileDescriptor,
            eventMask: .extend,
            queue: DispatchQueue.main
        )

        source.setEventHandler {
            let event = self.source.data
            self.process(event: event)
        }

        source.setCancelHandler {
            try? self.fileHandle.close()
        }

        fileHandle.seekToEndOfFile()
        source.resume()
    }

    deinit {
        source.cancel()
    }

    func process(event: DispatchSource.FileSystemEvent) {
        guard event.contains(.extend) else {
            return
        }
        let newData = self.fileHandle.readDataToEndOfFile()
        let string = String(data: newData, encoding: .utf8)!
        self.delegate?.didReceive(changes: string)
    }
}

/// Observes the focus system state.
class FocusSystemObserver: FileMonitorDelegate {
    
    /// A notification posted when the app is not focused anymore.
    static let focusSystemDidDisableNotification = Notification.Name("focusSystemDidDisableNotification")
    
    /// A notification posted when the app is focused.
    static let focusSystemDidEnableNotification = Notification.Name("focusSystemDidEnableNotification")
    
    func didReceive(changes: String) {
        
        if changes.contains("[UIFocus] Focus system disabled") {
            NotificationCenter.default.post(name: Self.focusSystemDidDisableNotification, object: nil)
        } else if changes.contains("[UIFocus] Focus system enabled") {
            NotificationCenter.default.post(name: Self.focusSystemDidEnableNotification, object: nil)
        }
        
        print(changes, terminator: "")
    }
    
    private static let logURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent("log.txt")
    
    private static var monitor: FileMonitor?
    
    private static let delegate = FocusSystemObserver()
    
    /// Starts observing focus state. Does nothing on iPhone and Mac.
    static func startObserving() {
        
        guard UIDevice.current.userInterfaceIdiom == .pad, !isiOSAppOnMac else {
            return
        }
        
        if FileManager.default.fileExists(atPath: logURL.path) {
            try? FileManager.default.removeItem(atPath: logURL.path)
        }
        
        FileManager.default.createFile(atPath: logURL.path, contents: nil, attributes: nil)
        
        monitor = try? FileMonitor(url: logURL)
        monitor?.delegate = delegate
        
        freopen(NSString(string: logURL.path).utf8String, "w", stderr)
    }
}
