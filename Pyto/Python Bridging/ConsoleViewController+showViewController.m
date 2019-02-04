//
//  ConsoleViewController+showViewController.m
//  Pyto
//
//  Created by Adrian Labbé on 1/25/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

#if MAIN
#import <Pyto-Swift.h>
#elif WIDGET
#import <Pyto_Widget-Swift.h>
#else
#import <PytoCore/PytoCore-Swift.h>
#endif
#import <UIKit/UIKit.h>

@implementation ConsoleViewController (showViewController)

    - (void) showViewController:(UIViewController *)vc completion:(void (^)(void))completion {
        #if WIDGET
        [self presentViewController:vc animated:NO completion:completion];
        #else
        [self presentViewController:[self viewController:vc] animated:NO completion:completion];
        #endif
    }
    
@end
