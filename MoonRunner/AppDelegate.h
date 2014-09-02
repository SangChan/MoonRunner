//
//  AppDelegate.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 2..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HomeViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

@end
