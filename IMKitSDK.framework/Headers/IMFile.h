//
//  IMFile.h
//  demoapp
//
//  Created by FUNTEK Inc. on 2015/11/11.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"

@interface IMFile : IMObject
@property (strong, nonatomic) NSString *fileName;
@property (strong, nonatomic) NSString *type;
@property (assign, nonatomic) NSUInteger size;
@property (assign, nonatomic) BOOL isPublic;
@property (strong, nonatomic) NSString *room;
@end
