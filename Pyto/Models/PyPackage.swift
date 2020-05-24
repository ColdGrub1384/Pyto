//
//  PyPackage.swift
//  Pyto
//
//  Created by Adrian Labbé on 08-11-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

fileprivate extension URLSession {

    func synchronousDataTask(with request: URLRequest) throws -> (data: Data?, response: HTTPURLResponse?) {

        let semaphore = DispatchSemaphore(value: 0)

        var responseData: Data?
        var theResponse: URLResponse?
        var theError: Error?

        dataTask(with: request) { (data, response, error) -> Void in

            responseData = data
            theResponse = response
            theError = error

            semaphore.signal()

        }.resume()

        _ = semaphore.wait(timeout: .distantFuture)

        if let error = theError {
            throw error
        }

        return (data: responseData, response: theResponse as! HTTPURLResponse?)

    }

}

/// The representation of a PyPi package.
struct PyPackage {
    
    /// The name of the package.
    var name: String?
    
    /// The summary of the package.
    var description: String?
    
    /// The author of the package.
    var author: String?
    
    /// The maintainer of the package.
    var maintainer: String?
    
    /// All package versions.
    var versions: [String] = []
    
    /// The latest stable version.
    var stableVersion: String?
    
    /// The requirements of the package,
    var requirements: [String] = []
    
    /// Links of the project.
    var links = [(title: String, url: URL)]()
    
    /// Initializes the package from its name. Values will be filled from PyPi API, so don't call this initializer from the main thread.
    ///
    /// - Parameters:
    ///     - name: The name of the package.
    init?(name: String) {
        
        let mirror: String
        if let _mirror = ProcessInfo.processInfo.environment["PYPI_MIRROR"] {
            var splitted = _mirror.components(separatedBy: "/")
            if splitted.last == "" {
                splitted.removeLast()
            }
            if splitted.last == "simple" {
                splitted.removeLast()
            }
            splitted.append("pypi")
            
            mirror = splitted.joined(separator: "/")
        } else {
            mirror = "https://pypi.python.org/pypi"
        }
        
        guard let url = URL(string: "\(mirror)/\(name)/json") else {
            return nil
        }
        
        do {
            let result = try URLSession.shared.synchronousDataTask(with: URLRequest(url: url))
            
            guard let data = result.data else {
                return nil
            }
            
            do {
                guard let jsonResponse = try JSONSerialization.jsonObject(with: data, options: []) as? [String: Any] else {
                    return
                }
                
                guard let info = jsonResponse["info"] as? [String: Any] else {
                    return
                }
                
                self.name = name
                self.description = info["summary"] as? String
                self.author = info["author"] as? String
                self.maintainer = info["maintainer"] as? String
                self.versions = ((jsonResponse["releases"] as? [String: Any])?.keys.sorted() ?? []).sorted(by: { (a, b) -> Bool in
                    let comparaison = a.compare(b, options: .numeric)
                    return (comparaison == .orderedDescending)
                })
                for version in self.versions {
                    if version.rangeOfCharacter(from: CharacterSet.letters) == nil {
                        self.stableVersion = version
                        break
                    }
                }
                var requirements = [String]()
                for requirement in (info["requires_dist"] as? [String] ?? []) {
                    requirements.append(requirement.components(separatedBy: ";")[0])
                }
                self.requirements = requirements
                
                var links = [(title: String, url: URL)]()
                for (title, value) in (info["project_urls"] as? [String:String]) ?? [:] {
                    if let url = URL(string: value) {
                        links.append((title: title, url: url))
                    }
                }
                self.links = links
            } catch {
                return nil
            }
        } catch {
            return nil
        }
    }
}
