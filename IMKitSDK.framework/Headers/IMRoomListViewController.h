//
//  ChatRoomListViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMViewController.h"
#import "IMChatViewController.h"
#import "IMRoomTableViewCell.h"


@interface IMRoomListViewController : IMViewController

//inherit override if need to custom cell
-(NSString*)cellIDForRoom:(IMRoom*)room;
-(UITableViewCell*)customCellWithIdentifier:(NSString*)cellID room:(IMRoom*)room cell:(IMRoomTableViewCell*)cell;

-(IMChatViewController*)IMRoomListControllerToPushWithRoom:(IMRoom*)room;
@end


