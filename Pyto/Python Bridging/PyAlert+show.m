//
//  PyAlert+show.m
//  Pyto
//
//  Created by Adrian Labbé on 1/25/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

#import <Pyto-Swift.h>
#import <Foundation/Foundation.h>

@implementation PyAlert (show)

    - (NSString *) show {
        self.response = NULL;
        self.semaphore = dispatch_semaphore_create(0);
        dispatch_async(dispatch_get_main_queue(), ^{
            UIAlertController *alert = [UIAlertController alertControllerWithTitle:self.title message:self.message preferredStyle:UIAlertControllerStyleAlert];
            
            for (UIAlertAction *action in self.actions) {
                [alert addAction:action];
            }
            
            [UIApplication.sharedApplication.keyWindow.topViewController presentViewController:alert animated:YES completion:NULL];
        });
        
        dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
        
        return self.response;
    }
    
@end
