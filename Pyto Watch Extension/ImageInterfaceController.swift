//
//  ImageInterfaceController.swift
//  Pyto Watch Extension
//
//  Created by Emma Labbé on 05-02-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import WatchKit

/// An Interface controller displaying an image in full screen.
class ImageInterfaceController: WKInterfaceController {
   
    /// The image view.
    @IBOutlet weak var image: WKInterfaceImage!
    
    override func awake(withContext context: Any?) {
        super.awake(withContext: context)
        
        if let image = context as? UIImage {
            self.image.setImage(image)
        }
    }
}
