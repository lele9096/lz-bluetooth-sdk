//
//  CDBleChargeHistory.h
//  LZAPI
//
//  Created by LELE on 2018/11/20.
//  Copyright © 2018年 rect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDBleQueryChargerState.h"
@interface CDBleChargeHistory : CDBleQueryChargerState
@property(nonatomic,copy)NSString* startTime;
@property(nonatomic,copy)NSString* endTime;
@property(nonatomic,copy)NSString* orderNum;

@end
