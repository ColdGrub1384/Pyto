//
//  PytoCore.h
//  PytoCore
//
//  Created by Adrian Labbé on 1/13/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>

void init_pil(void);

@interface BlockBasedSelector : NSObject
    
@end

typedef void (^OBJCBlock)(id _Selector);
typedef void (^OBJCBlockWithSender)(id _Selector, id sender);

void class_addMethodWithBlock(Class class, SEL newSelector, OBJCBlock block);
void class_addMethodWithBlockAndSender(Class class, SEL newSelector, OBJCBlockWithSender block);

/// Should be called instead of `UIApplicationMain` to run the application main loop for a Python script.
///
/// @param scriptPath The path of the script to run.
/// @param argc The count of arguments.
/// @param argv Arguments passed to `sys.argv`.
///
/// @return Returns the `UIApplicationMain` return value.
int PythonApplicationMain(NSString * scriptPath, int argc, char * _Nullable * _Nonnull argv);
