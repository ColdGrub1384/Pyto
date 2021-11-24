//
//  AppDelegate+AppleWatch.swift
//  Pyto
//
//  Created by Emma Labbé on 11-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import WatchConnectivity

extension AppDelegate: WCSessionDelegate {
    
    public func session(_ session: WCSession, activationDidCompleteWith activationState: WCSessionActivationState, error: Error?) {
        
    }
    
    public func sessionDidBecomeInactive(_ session: WCSession) {
        
    }
    
    public func sessionDidDeactivate(_ session: WCSession) {
        
    }
    
    public func session(_ session: WCSession, didReceiveMessage message: [String : Any], replyHandler: @escaping ([String : Any]) -> Void) {
        if (message["Get"] as? String) == "Descriptors" {
            let keys = (UserDefaults.shared?.string(forKey: "userKeys") ?? "").data(using: .utf8) ?? Data()
            
            do {
                let json = try JSONSerialization.jsonObject(with: keys, options: []) as? [AnyHashable:Any]
                if let descriptors = json?["__watch_descriptors__"] as? [String] {
                    replyHandler(["Descriptors":descriptors])
                } else {
                    replyHandler([:])
                }
            } catch {
                print(error.localizedDescription)
                replyHandler([:])
            }
            
        } else {
            replyHandler([:])
        }
    }
    
    public func session(_ session: WCSession, didReceiveMessage message: [String : Any]) {
        print(message)
        for complication in message {
            
            let id = complication.key
            guard let value = complication.value as? [Any], value.count == 3 else {
                break
            }
            
            guard let date = value[0] as? Date else {
                return
            }
            
            guard let limit = value[1] as? Int else {
                return
            }
            
            guard let descriptor = value[2] as? String else {
                return
            }
            
            self.descriptor = descriptor
            
            var isStale = false
            if let data = UserDefaults.standard.data(forKey: "watchScriptPath"), let url = (try? URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)) {
                
                _ = url.startAccessingSecurityScopedResource()
                
                watchScript = url.path
                
                var task: UIBackgroundTaskIdentifier!
                task = UIApplication.shared.beginBackgroundTask {
                    UIApplication.shared.endBackgroundTask(task)
                }
                
                let complicationId = UUID().uuidString
                if #available(iOS 14.0, *) {
                    
                    func replyHandler(_ data: Data) {
                        let file = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("complication.json")
                        FileManager.default.createFile(atPath: file.path, contents: data, attributes: nil)
                        WCSession.default.transferFile(file, metadata: ["id":id])
                        UIApplication.shared.endBackgroundTask(task)
                    }
                    
                    watchComplicationsHandlers[complicationId] = { complications in
                        guard let complications = complications as? [PyComplication] else {
                            return replyHandler(Data())
                        }
                        
                        do {
                            let data = try JSONEncoder().encode(complications)
                             replyHandler(data)
                        } catch {
                            print(error.localizedDescription)
                            replyHandler(Data())
                        }
                    }
                }
                
                func run() {
                    Python.shared.run(script: Python.WatchScript(code: """
                    from threading import Event
                    from rubicon.objc import ObjCClass
                    from pyto import Python
                    from Foundation import NSAutoreleasePool
                    import runpy
                    import watch as wt
                    import sys
                    import os
                    import notifications as nc
                    import traceback as tb
                    import datetime as dt
                    import __watch_script_store__ as store

                    pool = NSAutoreleasePool.alloc().init()

                    wt.__shared_complication__ = None

                    delegate = ObjCClass("Pyto.AppDelegate").shared

                    script = str(delegate.getWatchScript())
                    dir = str(Python.shared.currentWorkingDirectory)
                    os.chdir(dir)
                    sys.path.append(dir)

                    descriptor = str(delegate.descriptor)

                    try:
                        if descriptor in store.providers:
                            provider = store.providers[descriptor]
                        else:
                            runpy.run_path(script)
                            try:
                                provider = store.providers[descriptor]
                            except KeyError:
                                provider = None

                        if provider is not None:
                            complications = provider.__complications__(dt.datetime.fromtimestamp(\(date.timeIntervalSince1970)), \(limit))
                            objc_complications = []
                            for complication in complications:
                                objc = wt.__objc__(complication[1])
                                objc.timestamp = complication[0].timestamp()
                                objc_complications.append(objc)

                            wt.__PyComplication__.sendObject = objc_complications
                        else:
                            wt.__PyComplication__.sendObject = None
                    except Exception as e:
                        print(tb.format_exc())

                        if str(e) != '<run_path>':
                            notif = nc.Notification()
                            notif.message = str(e)
                            nc.send_notification(notif)
                    finally:

                        wt.__cached_ui__ = None

                        complication = wt.__PyComplication__.sendObject
                        delegate.callComplicationHandlerWithId("\(complicationId)", complication=complication)
                        pool.release()
                        Event().wait()

                    """, workingDirectory: directory(for: url).path))
                }
                
                if Python.shared.isSetup {
                    run()
                } else {
                    func wait() {
                        if Python.shared.isSetup {
                            run()
                        } else {
                            DispatchQueue.global().asyncAfter(deadline: .now()+0.01) {
                                wait()
                            }
                        }
                    }
                    wait()
                }
            }
            
            break
        }
    }
    
    public func session(_ session: WCSession, didReceiveMessageData messageData: Data) {
        // Run script
        if messageData == "Run".data(using: .utf8) {
            
            var isStale = false
            if let data = UserDefaults.standard.data(forKey: "watchScriptPath"), let url = (try? URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)) {
                
                _ = url.startAccessingSecurityScopedResource()
                
                watchScript = url.path
                
                func run() {
                    Python.shared.run(script: Python.WatchScript(code: """
                    from rubicon.objc import ObjCClass
                    import runpy

                    script = str(ObjCClass("Pyto.AppDelegate").shared.watchScript)
                    runpy.run_path(script)
                    """, workingDirectory: directory(for: url).path))
                }
                
                if Python.shared.isSetup {
                    run()
                } else {
                    func wait() {
                        if Python.shared.isSetup {
                            run()
                        } else {
                            DispatchQueue.global().asyncAfter(deadline: .now()+0.01) {
                                wait()
                            }
                        }
                    }
                    wait()
                }
            } else {
                func run() {
                    Python.shared.run(script: Python.WatchScript(code: """
                    print("\(Localizable.Errors.noWatchScript)")
                    """, workingDirectory: FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path))
                }
                
                if Python.shared.isSetup {
                    run()
                } else {
                    func wait() {
                        if Python.shared.isSetup {
                            run()
                        } else {
                            DispatchQueue.global().asyncAfter(deadline: .now()+0.01) {
                                wait()
                            }
                        }
                    }
                    wait()
                }
            }
        } else if messageData == "Stop".data(using: .utf8) {
            Python.shared.stop(script: Python.watchScriptURL.path)
        }
    }
}
