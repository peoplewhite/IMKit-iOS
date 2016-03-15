//
//  ChatRoomListCollectionViewCell.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMTableViewCell.h"

@interface IMRoomTableViewCell : IMTableViewCell
@property (weak, nonatomic) IBOutlet UILabel *subTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *badgeLabel;

@end
