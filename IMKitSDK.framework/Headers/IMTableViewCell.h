//
//  IMChatCollectionViewCell.h
//  IMKitSDK
//
//  Created by FUNTEK Inc. on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IMKit.h"
#import <LOUIKit/LOUIKit.h>
@interface IMTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet LOImageView *photoImageView;
@property (weak, nonatomic) IBOutlet LOLabel *titleLabel;

@property (weak, nonatomic) IBOutlet LOLabel *timeLabel;

@end
