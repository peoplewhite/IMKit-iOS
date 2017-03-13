//
//  IMBubbleView.h
//  RichSDKDemo
//
//  Created by FUNTEK Inc. on 2016/3/24.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import <LOUIKit/LOUIKit.h>

IB_DESIGNABLE
@interface IMBubbleView : UIView

@property (assign, nonatomic) IBInspectable BOOL positionLeft;
@property (strong, nonatomic) IBInspectable UIColor *bubbleColor;
@end
