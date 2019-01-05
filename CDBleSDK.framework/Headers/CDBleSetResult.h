//
//  CDBleSetResult.h
//  LZAPI
//
//  Created by LELE on 2018/11/20.
//  Copyright © 2018年 rect. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  设置类型操作结果
 */
typedef NS_ENUM(NSInteger,CDBleSetResultType){
    CDBleSetResultTypeSuccess =  0, 
    CDBleSetResultTypeFailue  =  1,
    CDBleSetResultTypeOther   =  2
};
@interface CDBleSetResult : NSObject
@property(nonatomic,assign)CDBleSetResultType resultType;
@end
