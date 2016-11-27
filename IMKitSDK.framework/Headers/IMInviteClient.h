//
//  IMInviteClient.h
//  Pods
//
//  Created by Kuo-HsunShih on 2016/5/17.
//
//

#import <JSONModel/JSONModel.h>

@interface IMInviteClient : JSONModel
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *pictureURLString;
@property (copy, nonatomic) NSString *clientID;
@end
