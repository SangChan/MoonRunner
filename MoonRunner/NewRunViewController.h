//
//  NewRunViewController.h
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 2..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import "Run.h"
@interface NewRunViewController : UIViewController<UIActionSheetDelegate, CLLocationManagerDelegate, MKMapViewDelegate>

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong) Run *run;
@property (nonatomic, weak) IBOutlet UILabel *promptLabel;
@property (nonatomic, weak) IBOutlet UILabel *timeLabel;
@property (nonatomic, weak) IBOutlet UILabel *distLabel;
@property (nonatomic, weak) IBOutlet UILabel *paceLabel;
@property (nonatomic, weak) IBOutlet UIButton *startButton;
@property (nonatomic, weak) IBOutlet UIButton *stopButton;
@property (nonatomic, weak) IBOutlet MKMapView *mapView;

- (IBAction)startPressed:(id)sender;
- (IBAction)stopPressed:(id)sender;
@end
