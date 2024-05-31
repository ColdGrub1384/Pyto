//
//  PyEventHelper.swift
//  Pyto
//
//  Created by Emma on 22-10-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import EventKit

@objc class PyEventHelper: NSObject {
    
    static let store = EKEventStore()
    
    @objc static func saveEvent(_ event: EKEvent) -> String? {
        
        var accessError: String?
        
        let semaphore = Python.Semaphore(value: 0)
        PyWrapper.set {
            store.requestAccess(to: .event) { hasAccess, error in
                
                accessError = error?.localizedDescription
                
                if hasAccess {
                    do {
                        try self.store.save(event, span: .futureEvents)
                    } catch {
                        accessError = error.localizedDescription
                    }
                }
                
                semaphore.signal()
            }
        }
        
        semaphore.wait()
        
        return accessError
    }
    
    @objc static func removeEvent(_ event: EKEvent) -> String? {
        var accessError: String?
        
        let semaphore = Python.Semaphore(value: 0)
        PyWrapper.set {
            store.requestAccess(to: .event) { hasAccess, error in
                
                accessError = error?.localizedDescription
                
                if hasAccess {
                    do {
                        try self.store.remove(event, span: .futureEvents)
                    } catch {
                        accessError = error.localizedDescription
                    }
                }
                
                semaphore.signal()
            }
        }
        
        semaphore.wait()
        
        return accessError
    }
    
    @objc class GetEventsResult: NSObject {
        
        @objc var error: String?
        
        @objc var events = [Any]()
    }
    
    @objc static func getEventsWithStartDate(_ startDate: Date, endDate: Date) -> GetEventsResult {
        var accessError: String?
        var events = [Any]()
        
        let semaphore = Python.Semaphore(value: 0)
        PyWrapper.set {
            if #available(iOS 17.0, *) {
                store.requestFullAccessToEvents(completion: { hasAccess, error in
                    
                    accessError = error?.localizedDescription
                    
                    if hasAccess {
                        let predicate = self.store.predicateForEvents(withStart: startDate, end: endDate, calendars: nil)
                        events = self.store.events(matching: predicate)
                    }
                    
                    semaphore.signal()
                })
            } else {
                store.requestAccess(to: .event) { hasAccess, error in
                    accessError = error?.localizedDescription
                    
                    if hasAccess {
                        let predicate = self.store.predicateForEvents(withStart: startDate, end: endDate, calendars: nil)
                        events = self.store.events(matching: predicate)
                    }
                    
                    semaphore.signal()
                }
            }
        }
        
        semaphore.wait()
        
        let result = GetEventsResult()
        result.error = accessError
        result.events = events
        return result
    }
    
    @objc static func makeEvent() -> EKEvent {
        let event = EKEvent(eventStore: store)
        event.calendar = store.defaultCalendarForNewEvents
        return event
    }
}
