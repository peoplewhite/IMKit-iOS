//
//  ChatRoomListViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMViewController.h"
#import "IMMessageViewController.h"
#import "IMRoomTableViewCell.h"

@protocol IMRoomViewControllerDelegate;


@interface IMRoomViewController : IMViewController

@property (weak,nonatomic) id<IMRoomViewControllerDelegate> delegate;
@property (weak, nonatomic) IBOutlet UITableView *tableview;

-(void)enterRoom:(IMRoom*)room animated:(BOOL)animated;

//inherit override if need to custom cell
-(NSString*)cellIDForRoom:(IMRoom*)room;
-(UITableViewCell*)customCellWithIdentifier:(NSString*)cellID room:(IMRoom*)room cell:(IMRoomTableViewCell*)cell;

-(IMMessageViewController*)IMRoomControllerToPushWithRoom:(IMRoom*)room;
@end


@protocol IMRoomViewControllerDelegate <NSObject>
@optional

-(void)IMRoomViewControllerDidPop;


@end