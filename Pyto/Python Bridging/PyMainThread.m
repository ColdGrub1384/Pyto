//
//  NSObject+PyMainThread.m
//  Pyto
//
//  Created by Adrian Labbé on 1/24/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PyMainThread: NSObject
    
+ (void) runAsync:(void (^)(void))block;
+ (void) runSync:(void (^)(void))block;
@end

@implementation PyMainThread
+ (void) runAsync:(void (^)(void))block {
    dispatch_async(dispatch_get_main_queue(), block);
}

+ (void) runSync:(void (^)(void))block {
    dispatch_sync(dispatch_get_main_queue(), block);
}
@end

