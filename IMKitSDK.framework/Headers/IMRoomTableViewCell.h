//
//  ChatRoomListCollectionViewCell.h
//  IMKitSDK
//
//  Created by FUNTEK Inc. on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMTableViewCell.h"

@interface IMRoomTableViewCell : IMTableViewCell

/**
 *  room to show
 */
@property (strong, nonatomic) IMRoom *room;

@property (weak, nonatomic) IBOutlet LOLabel *subTitleLabel;
@property (weak, nonatomic) IBOutlet LOLabel *badgeLabel;

@end
