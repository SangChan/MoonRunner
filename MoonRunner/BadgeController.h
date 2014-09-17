//
//  BadgeController.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 15..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

extern float const silverMulitiplier = 1.05;
extern float const goldMulitiplier = 1.10;


@interface BadgeController : NSObject

+ (BadgeController *)defaultConroller;
- (NSArray *)earnStatusForRuns:(NSArray *)runArray;

@end
