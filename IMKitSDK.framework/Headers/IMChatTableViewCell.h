//
//  ChatRoomCollectionViewCell.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMTableViewCell.h"
#import "IMKit.h"
@interface IMChatTableViewCell : IMTableViewCell
@property (assign, nonatomic) IMKitMessageSendingType cellType;

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *indicator;
@property (weak, nonatomic) IBOutlet UITextView *subTextView;
@end
