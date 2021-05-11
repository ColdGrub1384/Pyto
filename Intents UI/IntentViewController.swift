//
//  IntentViewController.swift
//  Intents UI
//
//  Created by Emma Labbé on 02-08-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import IntentsUI

// As an example, this extension's Info.plist has been configured to handle interactions for INSendMessageIntent.
// You will want to replace this or add other intents as appropriate.
// The intents whose interactions you wish to handle must be declared in the extension's Info.plist.

// You can test this example integration by saying things to Siri like:
// "Send a message using <myApp>"

class IntentViewController: UIViewController, INUIHostedViewControlling {
    
    @IBOutlet weak var textView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        var lastOutput = ""
        
        guard let group = FileManager.default.sharedDirectory else {
            return
        }
        
        let fileURL = group.appendingPathComponent("UIIntentsOutput")
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: true, block: { (timer) in
            do {
                
                let ran = FileManager.default.fileExists(atPath: group.appendingPathComponent("ShortcutOutput.txt").path)
                
                let output = try String(contentsOf: fileURL)
                
                if output.isEmpty && !lastOutput.isEmpty {
                    timer.invalidate()
                    return
                }
                
                lastOutput = output
                self.textView.text = output
                self.textView.scrollRangeToVisible(NSRange(location: 0, length: NSString(string: output).length))
                
                if ran {
                    timer.invalidate()
                }
            } catch {}
        })
    }
        
    // MARK: - INUIHostedViewControlling
    
    // Prepare your view controller for the interaction to handle.
    func configureView(for parameters: Set<INParameter>, of interaction: INInteraction, interactiveBehavior: INUIInteractiveBehavior, context: INUIHostedViewContext, completion: @escaping (Bool, Set<INParameter>, CGSize) -> Void) {
        
        completion(true, parameters, CGSize(width: 320, height: 150))
    }
    
}
