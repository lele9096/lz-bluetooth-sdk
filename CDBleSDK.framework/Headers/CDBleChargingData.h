//
//  CDBleChargingData.h
//  LZAPI
//
//  Created by LELE on 2018/11/21.
//  Copyright © 2018年 rect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDBleBaseChargeData.h"
@interface CDBleChargingData : CDBleBaseChargeData
/**
 * 桩的状态 字符串
 * 正在充电中、未知
 */

@property(nonatomic,copy)NSString* gunStatus;

/**
 * 错误原因:空字符串时表示无错误原因
 * 过流、过压、欠压、急停按下、未知
 */
@property(nonatomic,copy)NSString* failureReason;

@end
