//
//  ParseArgs.swift
//  Pyto
//
//  Created by Emma Labbé on 11-01-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

/// Parses an array of arguments separated with space.
func ParseArgs(_ args: inout [String]) {
    
    enum QuoteType: String {
        case double = "\""
        case single = "'"
    }
    
    func parseArgs(_ args: inout [String], quoteType: QuoteType) {
        
        var parsedArgs = [String]()
        
        var currentArg = ""
        
        for arg in args {
            
            if arg.hasPrefix("\(quoteType.rawValue)") {
                
                if currentArg.isEmpty {
                    
                    currentArg = arg
                    currentArg.removeFirst()
                    
                } else {
                    
                    currentArg.append(" " + arg)
                    
                }
                
            } else if arg.hasSuffix("\(quoteType.rawValue)") {
                
                if currentArg.isEmpty {
                    
                    currentArg.append(arg)
                    
                } else {
                    
                    currentArg.append(" " + arg)
                    currentArg.removeLast()
                    parsedArgs.append(currentArg)
                    currentArg = ""
                    
                }
                
            } else {
                
                if currentArg.isEmpty {
                    parsedArgs.append(arg)
                } else {
                    currentArg.append(" " + arg)
                }
                
            }
        }
        
        if !currentArg.isEmpty {
            if currentArg.hasSuffix("\(quoteType.rawValue)") {
                currentArg.removeLast()
            }
            parsedArgs.append(currentArg)
        }
        
        args = parsedArgs
    }
    
    parseArgs(&args, quoteType: .single)
    parseArgs(&args, quoteType: .double)
}
