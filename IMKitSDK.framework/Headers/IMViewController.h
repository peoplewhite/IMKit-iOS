//
//  SuperViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IMKit.h"

#ifdef DEBUG
#define NSLog(s, ...) NSLog(@"<%@:%d> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ## __VA_ARGS__])
#else
#define NSLog(s, ...)
#endif

@interface IMViewController : UIViewController
- (void)setNavigationBarTitle:(NSString *)title;


- (void)keyboardWillChangeToFrame:(CGRect)frame duration:(CGFloat)duration;


@end
