//
//  ViewController.m
//  TestForSentry
//
//  Created by Shane on 2020/6/2.
//  Copyright © 2020 Shane. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
{
    NSArray *_arrTemp;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _arrTemp = @[@"1", @"2", @"3", @"4"];
}

- (IBAction)clickEvent:(UIButton *)sender {
    NSInteger index = arc4random() % 5;
    NSLog(@"--- %ld", index);
    NSString *str = _arrTemp[index];
    NSLog(@"--- %@", str);
}

@end
