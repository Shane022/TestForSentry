//
//  AppDelegate.m
//  TestForSentry
//
//  Created by Shane on 2020/6/2.
//  Copyright © 2020 Shane. All rights reserved.
//

#import "AppDelegate.h"
#import <Sentry.h>
#import <Bugly/Bugly.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Sentry
    [SentrySDK startWithOptions:@{
        @"dsn": @"https://3550c6183ae242539c5fb2aeabf8353d@o401454.ingest.sentry.io/5261049",
        @"debug": @(YES)
    }];
    
    // Bugly
    [Bugly startWithAppId:@"b726daf534"];

        
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
