//
//  TemplatesViewController.swift
//  Luade
//
//  Created by Adrian Labbe on 12/9/18.
//  Copyright © 2018 Adrian Labbe. All rights reserved.
//

import UIKit

/// A View controller containing scripts templates.
class TemplatesViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {
    
    /// All chossable templates.
    lazy var templates: [URL] = {
        guard let templatesURL = Bundle.main.url(forResource: "Samples", withExtension: nil), let files = (try? FileManager.default.contentsOfDirectory(at: templatesURL, includingPropertiesForKeys: nil, options: [])) else {
            return []
        }
        
        var scripts = [URL]()
        for file in files {
            if file.pathExtension.lowercased() == "py" {
                scripts.append(file)
            }
        }
        
        return scripts
    }()
    
    // MARK: - Collection view data source
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return templates.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "file", for: indexPath) as? FileCollectionViewCell else {
            return UICollectionViewCell()
        }
        
        cell.file = templates[indexPath.row]
        
        return cell
    }
    
    // MARK: - Collection view delegate
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        guard let docBrowser = DocumentBrowserViewController.visible else {
            return
        }
        
        let templateURL = templates[indexPath.row]
        
        var newURL: URL
        if let iCloudDrive = DocumentBrowserViewController.iCloudContainerURL {
            newURL = iCloudDrive.appendingPathComponent(templateURL.lastPathComponent)
        } else {
            newURL = DocumentBrowserViewController.localContainerURL.appendingPathComponent(templateURL.lastPathComponent)
        }
        
        var i = 2
        let name = newURL.deletingPathExtension().lastPathComponent
        while FileManager.default.fileExists(atPath: newURL.path) {
            newURL = newURL.deletingLastPathComponent().appendingPathComponent("\(name) \(i).py")
            
            i += 1
        }
        
        do {
            try FileManager.default.copyItem(at: templateURL, to: newURL)
            _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
                docBrowser.openDocument(newURL, run: false)
            })
        } catch {
            let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .default, handler: nil))
            present(alert, animated: true, completion: nil)
        }
    }
}
