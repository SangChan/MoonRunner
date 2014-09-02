//
//  DetailViewController.m
//  MoonRunner
//
//  Created by SangChan on 2014. 9. 2..
//  Copyright (c) 2014년 sangchan. All rights reserved.
//

#import "DetailViewController.h"
#import "MathController.h"
#import "Run.h"
#import "Location.h"
#import "MulticolorPolylineSegment.h"

@interface DetailViewController () 
@end

@implementation DetailViewController

- (void)setRun:(Run *)run
{
    if (_run != run) {
        _run = run;
        [self configureView];
    }
}

- (void)configureView
{
    self.distanceLabel.text = [MathController stringifyDistance:self.run.distance.floatValue];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    self.dateLabel.text = [formatter stringFromDate:self.run.timestamp];
    
    self.timeLabel.text = [NSString stringWithFormat:@"Time: %@",[MathController stringifySecondCount:self.run.duration.intValue usingLongFormat:YES]];
    self.paceLabel.text = [NSString stringWithFormat:@"Pace: %@",[MathController stringifyAvgPaceFromDist:self.run.distance.floatValue overTime:self.run.duration.intValue]];
    [self loadMap];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self configureView];
	// Do any additional setup after loading the view, typically from a nib.
}

- (MKCoordinateRegion)mapRegion
{
    MKCoordinateRegion region;
    Location *initialLoc = self.run.locations.firstObject;
    
    float minLat = initialLoc.latitude.floatValue;
    float minLng = initialLoc.longitude.floatValue;
    float maxLat = initialLoc.latitude.floatValue;
    float maxLng = initialLoc.longitude.floatValue;
    
    for (Location *location in self.run.locations) {
        if (location.latitude.floatValue < minLat) {
            minLat = location.latitude.floatValue;
        }
        if (location.longitude.floatValue < minLng) {
            minLng = location.longitude.floatValue;
        }
        if (location.latitude.floatValue > maxLat) {
            maxLat = location.latitude.floatValue;
        }
        if (location.longitude.floatValue > maxLng) {
            maxLng = location.longitude.floatValue;
        }
    }
    
    region.center.latitude = (minLat + maxLat) / 2.0f;
    region.center.longitude = (minLng + maxLng) / 2.0f;
    
    region.span.latitudeDelta = (maxLat - minLat) * 1.1f;
    region.span.longitudeDelta = (maxLng - minLng) * 1.1f;
    
    return region;
}

- (MKOverlayRenderer *)mapView:(MKMapView *)mapView rendererForOverlay:(id<MKOverlay>)overlay
{
    if ([overlay isKindOfClass:[MulticolorPolylineSegment class]]) {
        MulticolorPolylineSegment *polyLine = (MulticolorPolylineSegment *)overlay;
        MKPolylineRenderer *aRenderer = [[MKPolylineRenderer alloc] initWithPolyline:polyLine];
        aRenderer.strokeColor = polyLine.color;
        aRenderer.lineWidth = 3;
        return aRenderer;
    }
    return nil;
}

- (MKPolyline *)polyLine
{
    CLLocationCoordinate2D coords[self.run.locations.count];
    for (int i = 0; i < self.run.locations.count; i++) {
        Location *location = [self.run.locations objectAtIndex:i];
        coords[i] = CLLocationCoordinate2DMake(location.latitude.doubleValue, location.longitude.doubleValue);
    }
    
    return [MKPolyline polylineWithCoordinates:coords count:self.run.locations.count];
}

- (void)loadMap
{
    if (self.run.locations.count > 0 ) {
        self.mapView.hidden = NO;
        [self.mapView setRegion:[self mapRegion]];
        NSArray *colorSegmentArray = [MathController colorSegmentsForLocations:self.run.locations.array];
        [self.mapView addOverlays:colorSegmentArray];
        //[self.mapView addOverlay:[self polyLine]];
    }
    else {
        self.mapView.hidden = YES;
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Sorry, this run has no locations saved." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alertView show];
    }
}

@end
