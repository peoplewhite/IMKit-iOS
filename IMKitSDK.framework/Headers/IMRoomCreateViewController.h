//
//  IMRoomCreateViewController.h
//  Pods
//
//  Created by FUNTEK Inc. on 2016/5/16.
//
//

#import "IMInviteClient.h"
#import "IMRoomInviteViewController.h"
#import "IMViewController.h"

@protocol IMRoomCreateDelegate;

@interface IMRoomCreateViewController : IMViewController
@property (weak, nonatomic) id <IMRoomCreateDelegate> delegate;
@end

@protocol IMRoomCreateDelegate <NSObject>

@end
