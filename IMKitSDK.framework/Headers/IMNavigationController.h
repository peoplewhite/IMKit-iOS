//
//  IMNavigationController.h
//  Pods
//
//  Created by Kuo-HsunShih on 2016/4/21.
//
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface IMNavigationController : UINavigationController

@property (assign,nonatomic) IBInspectable BOOL UIStatusBarStyleLight;
@property (assign,nonatomic) IBInspectable UIColor* barTintColor;
@property (assign,nonatomic) IBInspectable UIColor* tintColor;

@end
