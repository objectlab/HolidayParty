//
//  BarTender.h
//  HolidayParty
//
//  Created by chris mollis on 11/8/13.
//  Copyright (c) 2013 Eric Mansfield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "HttpClient.h"

/** Bluetooth stuff here:
 
 http://blog.bluetooth.com/apple-raises-the-bluetooth-smart-ready-bar-again/
 
 Read about Apple Notification Center Service (ANCS) and the Preservation and Restoration service. 
*/

extern NSInteger const kBarScoreUpdateNotificationType;
extern NSInteger const kUserWelcomeNotificationType;

@interface BarTender : NSObject <CLLocationManagerDelegate, CBCentralManagerDelegate>

+ (BarTender *)sharedInstance;

@property (nonatomic, copy, readonly) NSUUID *defaultProximityUUID;
@property (nonatomic, copy, readonly) NSString *defaultRegionId;
@property (nonatomic, copy, readonly) NSNumber *defaultPower;
@property (nonatomic, assign, readonly) BOOL needsBarScoreUpdate;
@property (nonatomic, strong, readonly) CLBeaconRegion *barRegion;
@property (nonatomic, strong, readonly) CLCircularRegion *barGPSRegion;
@property (nonatomic, strong) CBCentralManager *centralMgr;
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;
@property (strong, nonatomic) NSTimer *barUpdateTimer;
@property (nonatomic, assign, readonly) BOOL btReady;

- (BOOL) startMonitoring;
- (BOOL) stopMonitoring;
- (BOOL) startUpdateTimer;
- (BOOL) stopUpdateTimer;
- (BOOL) checkForBarProximity:(NSArray*)barBeacons;
- (BOOL) updateBarScore;
- (BOOL) updateBarScoreInBackground;
- (BOOL) userWelcomeMessage;

@end
