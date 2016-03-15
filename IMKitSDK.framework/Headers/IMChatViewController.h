//
//  ChatRoomViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMViewController.h"
#import "IMChatTableViewCell.h"

@interface IMChatViewController : IMViewController
@property (strong, nonatomic) IMRoom *room;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputViewToBottomDistance;
@property (weak, nonatomic) IBOutlet UIButton *sendMessageBtn;

//inherit override if need to custom cell
- (NSString *)cellIDForMessage:(IMMessage *)message;
- (UITableViewCell *)customCellWithIdentifier:(NSString *)cellID message:(IMMessage *)message cell:(IMChatTableViewCell *)cell;

@end
