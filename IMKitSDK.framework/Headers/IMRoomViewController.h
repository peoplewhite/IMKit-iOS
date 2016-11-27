//
//  ChatRoomListViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMInviteClient.h"
#import "IMMessageViewController.h"
#import "IMRoomCreateViewController.h"
#import "IMRoomTableViewCell.h"
#import "IMViewController.h"

@protocol IMRoomViewControllerDelegate;

@interface IMRoomViewController : IMViewController

@property (weak, nonatomic) id <IMRoomViewControllerDelegate> delegate;
@property (weak, nonatomic) IBOutlet UITableView *tableview;

- (void)enterRoom:(IMRoom *)room animated:(BOOL)animated;
- (void)doActionAfterUpdateRoomDoneWithTotalBadgeNumber:(int)totalBadgeNumber;

- (IBAction)createRoomItemPressed:(UIBarButtonItem *)sender;

//inherit override if need to custom cell
- (NSString *)cellIDForRoom:(IMRoom *)room;
- (UITableViewCell *)customCellWithIdentifier:(NSString *)cellID room:(IMRoom *)room cell:(IMRoomTableViewCell *)cell;

//return nil for default behavier , or cutom
- (id)IMRoomControllerToPushWithRoom:(IMRoom *)room;
@end

@protocol IMRoomViewControllerDelegate <NSObject>
@optional

- (void)IMRoomViewControllerDidPop;
- (NSArray <IMInviteClient *> *)arrayToInvite;

@end
