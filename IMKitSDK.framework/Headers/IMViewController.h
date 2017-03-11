//
//  SuperViewController.h
//  IMKitSDK
//
//  Created by FUNTEK Inc. on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//
#import "IMKit.h"
#import <UIKit/UIKit.h>

#ifdef DEBUG
#define NSLog(s, ...) NSLog(@"<%@:%d> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ## __VA_ARGS__])
#else
#define NSLog(s, ...)
#endif

@interface IMViewController : UIViewController
@property (weak, nonatomic) IBOutlet UITableView *tableview;

- (void)setNavigationBarTitle:(NSString *)title;
- (void)keyboardWillChangeToFrame:(CGRect)frame duration:(CGFloat)duration;
@end
