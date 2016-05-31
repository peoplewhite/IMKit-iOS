//
//  IMRoomInviteViewController.h
//  Pods
//
//  Created by Kuo-HsunShih on 2016/5/16.
//
//

#import "IMInviteClient.h"
#import "IMViewController.h"
#import "IMRoomInviteTableViewCell.h"

@protocol IMRoomInviteDelegate;

@interface IMRoomInviteViewController : IMViewController
@property (weak, nonatomic) id <IMRoomInviteDelegate> delegate;

@property (strong, nonatomic) NSArray <IMInviteClient *> *dataSource;
@property (strong, nonatomic) UIImage *roomThumbnail;
@property (copy, nonatomic) NSString *roomName;
@end

@protocol IMRoomInviteDelegate <NSObject>
@optional
- (void)inviteClientWithIndex:(NSUInteger)index limit:(NSUInteger)limit Complete:(void (^)(NSMutableArray <IMInviteClient *> *))complete;
@end
