//
//  CDBleDataModel.h
//  LZAPI
//
//  Created by LELE on 2018/11/19.
//  Copyright © 2018年 rect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDBleSetResult.h"
#import "CDBleChargingData.h"
#import "CDBleRemoteModel.h"
#import "YRunStateModel.h"
#import "CDBleErrorListLog.h"
#import "CDBleTotleElecQuantityModel.h"
#import "CDBleRunDiagnosticInfo.h"
#import "CDBleChargeHistory.h"

typedef NS_ENUM(NSInteger,CDBleCmdType){
    CDBleCmdTypeNore                  =    0, // 普通的
    CDBleCmdTypeSynchroTime           =    1,
    CDBleCmdTypeQuerySystemInfo       =    2,
    CDBleCmdTypeSetVolume             =    3,
    CDBleCmdTypeSetChargingOrderTime  =    4, // 预约充电
    CDBleCmdTypeCharging              =    5,
    CDBleCmdTypeQueryState            =    6,
    CDBleCmdTypeStopCharge            =    7,
    CDBleCmdTypeQueryChargingHistory  =    8,
    CDBleCmdTypeQueryTotalChargingCapacity  = 9,
    CDBleCmdTypeStartRemoteUpgrade    =    10, // 启动远程升级
    CDBleCmdTypeRequestUpgradePackage =    11, // 请求下发升级包
    CDBleCmdTypeUpgradeSuccess        =    12,
    CDBleCmdTypeChargeOperationDiagnosisInfo  =  13, // 桩运行诊断信息
    CDBleCmdTypeQueryChargingData     =    14,
    CDBleCmdTypeQueryHistoryErrorLog  =    15,
    CDBleCmdTypeIdentityAuthentication =    16  // 身份认证
};

/**
 *  蓝牙解析的数据模型
 */
@interface CDBleDataModel : NSObject
/**
 * 设置类型操作（开始充电，结束充电）返回的结果
 */
@property(nonatomic,strong)CDBleSetResult* result;

/**
 * 充电中信息
 */
@property(nonatomic,strong)CDBleChargingData* chargingData;

/**
 * 获取系统信息列表（信息的头部包含在文件列表中）
 */
@property(nonatomic,strong)NSArray* systemInfoList;

/**
 * 充电历史记录中列表
 */
@property(nonatomic,strong)NSArray<CDBleChargeHistory*>* chargeHistoryList;

/**
 * 获取错误日志列表
 */
@property(nonatomic,strong)NSArray<CDBleErrorListLog*>* historyErrorInfoList;

/**
 *  文件升级
 */
@property(nonatomic,strong)CDBleRemoteModel* remoteModel;

/**
 * 获取总的电量
 */
@property(nonatomic,strong)CDBleTotleElecQuantityModel* totleElecQtModel;

/**
 * 桩的运行诊断信息（运行状态）
 */
@property(nonatomic,strong)CDBleRunDiagnosticInfo* runDiagnosticInfo;

/**
 *  操作类型
 */
@property(nonatomic,assign)CDBleCmdType cmdType;


@end
