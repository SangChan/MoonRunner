//
//  Run.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 2..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Run : NSManagedObject

@property (nonatomic, retain) NSDate * timestamp;
@property (nonatomic, retain) NSNumber * duration;
@property (nonatomic, retain) NSNumber * distance;
@property (nonatomic, retain) NSOrderedSet *locations;
@end

@interface Run (CoreDataGeneratedAccessors)

- (void)insertObject:(NSManagedObject *)value inLocationsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromLocationsAtIndex:(NSUInteger)idx;
- (void)insertLocations:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeLocationsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInLocationsAtIndex:(NSUInteger)idx withObject:(NSManagedObject *)value;
- (void)replaceLocationsAtIndexes:(NSIndexSet *)indexes withLocations:(NSArray *)values;
- (void)addLocationsObject:(NSManagedObject *)value;
- (void)removeLocationsObject:(NSManagedObject *)value;
- (void)addLocations:(NSOrderedSet *)values;
- (void)removeLocations:(NSOrderedSet *)values;
@end
