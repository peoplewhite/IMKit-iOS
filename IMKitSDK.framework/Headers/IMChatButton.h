//
//  IMChatButton.h
//  Pods
//
//  Created by Kuo-HsunShih on 2016/4/19.
//
//

#import <LOUIKit/LOUIKit.h>

IB_DESIGNABLE
@interface IMChatButton : LOButton

@property (assign,nonatomic) IBInspectable BOOL stausBarLight;
@property (strong,nonatomic) IBInspectable UIColor* primaryColor;
@property (strong,nonatomic) IBInspectable UIColor* secondColor;

@property (assign,nonatomic) NSUInteger badgeNumber;

@end
