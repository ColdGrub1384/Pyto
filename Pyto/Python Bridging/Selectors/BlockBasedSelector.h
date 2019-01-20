//
//  BlockBasedSelector.h
//
//  Created by Charlton Provatas on 11/2/17.
//  Copyright © 2017 CharltonProvatas. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BlockBasedSelector : NSObject

@end

typedef void (^OBJCBlock)(id _Selector);
typedef void (^OBJCBlockWithSender)(id _Selector, id sender);

void class_addMethodWithBlock(Class class, SEL newSelector, OBJCBlock block);
void class_addMethodWithBlockAndSender(Class class, SEL newSelector, OBJCBlockWithSender block);
