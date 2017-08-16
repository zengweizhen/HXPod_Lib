//
//  AfficheModel.h
//  HuaFinancial
//
//  Created by Jney on 2017/4/13.
//  Copyright © 2017年 Jney. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NewsTypeModel : NSObject
@property (nonatomic, strong) NSString *iid;
@property (nonatomic, strong) NSString *createTime;
@property (nonatomic, strong) NSString *createUser;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *remark;

@end

@interface AfficheModel : NSObject

@property (nonatomic, assign) CGFloat  webViewHeight;
@property (nonatomic, assign) CGFloat  cellHeight;
@property (nonatomic, assign) BOOL     openCell;
@property (nonatomic, strong) NSString *iid;
@property (nonatomic, strong) NSString *clickCount;
@property (nonatomic, strong) NSString *content;
@property (nonatomic, strong) NSString *contentType;
@property (nonatomic, strong) NSString *createTime;
@property (nonatomic, strong) NSString *createUser;
@property (nonatomic, strong) NSString *files;
@property (nonatomic, strong) NSString *logo;
@property (nonatomic, strong) NSString *newsTypeId;
@property (nonatomic, strong) NSString *recommend;
@property (nonatomic, strong) NSString *summary;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NewsTypeModel *newsTypeModel;

@end


