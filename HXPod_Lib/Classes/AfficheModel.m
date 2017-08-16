//
//  AfficheModel.m
//  HuaFinancial
//
//  Created by Jney on 2017/4/13.
//  Copyright © 2017年 Jney. All rights reserved.
//

#import "AfficheModel.h"

@implementation NewsTypeModel

+(NSDictionary *)mj_replacedKeyFromPropertyName{
    
    return @{@"iid" :   @"id"};
}

@end

@implementation AfficheModel



+(NSDictionary *)mj_replacedKeyFromPropertyName{
    
    return @{@"iid" :   @"id"};
}
+ (NSDictionary *)mj_objectClassInArray{
    return @{@"newsType" : [NewsTypeModel class]};
}
@end
