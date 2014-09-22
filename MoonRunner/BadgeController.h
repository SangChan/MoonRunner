//
//  BadgeController.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 15..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Badge;
@interface BadgeController : NSObject

+ (BadgeController *)defaultConroller;
- (NSArray *)earnStatusForRuns:(NSArray *)runArray;
- (Badge *)bestBadgeForDistance:(float)distance;
- (Badge *)nextBadgeForDistance:(float)distance;

@end
