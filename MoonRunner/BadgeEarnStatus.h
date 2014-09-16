//
//  BadgeEarnStatus.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 16..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Badge;
@class Run;

@interface BadgeEarnStatus : NSObject

@property (strong, nonatomic) Badge *badge;
@property (strong, nonatomic) Run *earnRun;
@property (strong, nonatomic) Run *silverRun;
@property (strong, nonatomic) Run *goldRun;
@property (strong, nonatomic) Run *bestRun;
@end
