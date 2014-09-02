//
//  Location.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 2..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Run;

@interface Location : NSManagedObject

@property (nonatomic, retain) NSDate * timeStamp;
@property (nonatomic, retain) NSNumber * longitude;
@property (nonatomic, retain) NSNumber * latitude;
@property (nonatomic, retain) Run *run;

@end
