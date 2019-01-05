//
//  CDBleManager.h
//  BluethToolDemo
//
//  Created by LELE on 17/5/27.
//  Copyright © 2017年 rect. All rights reserved.
//
/******************************************************************************************
*******************************************************************************************
**                                                                                       **
**               ****  ********                ****      ********        **     ***      **
**              *****  *********             **    **    *********       **    **        **
**             **      **       **          **      **   **       **     **   **         **
**           **        **         **         **          **         **   **  **          **
**          **         **          **         ***        **          **  ** **           **
**          **         **          **            ***     **          **  ** **           **
**           **        **         **               ***   **         **   **  **          **
**            **       **       **         **       **   **       **     **   **         **
**              *****  *********            *********    *********       **    **        **
**               ****  ********               ******     ********        **     ***      **
**                                                                                       **
*******************************************************************************************
******************************************************************************************/
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/**
 *  蓝牙状态的开启与关闭通知中心发出的通知名称和 key 值
 */
static NSString* _Nullable  const CentralManagerDidUpdateStateNotification = @"CentralManagerDidUpdateStateNotification";

@class CDBleDataModel,CDBleManager;

@protocol CDBleManagerDelegate <NSObject>

@optional
/*! @brief 蓝牙开启与关闭状态变化的代理
 * @param state 状态枚举值
 */
-(void)cdbleManagerCenterState:(CBManagerState)state;

/*！@brief 搜索外设
 *  每搜索到一个外设此代理都会调用
 *  @param peripheral 发现的外设
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdbleManager didDiscoverPeripheral:(CBPeripheral*_Nullable)peripheral RSSI:(NSNumber *_Nullable)RSSI;

/*！@brief 已经连接到外设
 *  @param peripheral 已连接的外设
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdbleManager didConnectPeripheral:(nullable CBPeripheral*)peripheral;

/*！@brief 连接到外设失败
 *  @param error 失败原因
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdbleManager didFailToConnectPeripheral:(nullable CBPeripheral*)peripheral error:(nullable NSError*)error;

/*！@brief 外设断开连接
 *  @param peripheral 断开的外设
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdbleManager didDisconnectPeripheral:(nullable CBPeripheral*)peripheral error:(nullable NSError*)error;

/*！@brief 外设响应的数据更新
 *  @param cdBleManager    中心设备管理者
 *  @param CDBleDataModel  解析外设响应的数据模型
 *  @param error           错误信息
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdBleManager didUpdateValueForCharacteristicValue:(CDBleDataModel* _Nullable )dataModel error:(nullable NSError *)error;

/**
 *  向外设写入数据的代理
 */
-(void)cdbleManager:(CDBleManager*_Nullable)cdbleManager didWriteValueForCharacteristic:(nullable CBCharacteristic *)characteristic error:(nullable NSError *)error;

@end

@interface CDBleManager : NSObject


@property(nonatomic,weak) id  <CDBleManagerDelegate>delegate;

/**
 *  已经连接的外设,连接成功之后有值
 */
@property(nonatomic,strong,readonly)CBPeripheral* _Nullable connectedPheral;

/**
 *  写特征
 */
@property(nonatomic,strong)CBCharacteristic* _Nullable writeCharacteristic;

/**
 * 读特征
 */
@property(nonatomic,strong)CBCharacteristic* _Nullable readCharacteristic;

+(instancetype _Nullable )shareManager;


/**
 * 扫描外设
 */
-(void)scanForPeripherals;

/*！@brief 开始连接外设
 *  @param peripheral 需要连接的外设
 */
-(void)startConnectPeripheral:(CBPeripheral*_Nullable)peripheral;

/**
 *  断开外设
 */
-(void)stopConnectPeripheral:(CBPeripheral*_Nullable)peripheral error:(void(^_Nullable)(NSError* _Nullable error))error;

/**
 *  停止扫描外设
 */
-(void)stopScan;

#pragma mark -- 功能部分
/**
 *  开始充电
 */
-(void)startChargingWithError:(void(^_Nullable)(NSError* _Nullable error))error;

/**
 *  停止充电
 */
-(void)stopChargeWithError:(void(^_Nullable)(NSError* _Nullable error))error;

/**
 *  查询充电数据
 */
-(void)queryChargingDataWithError:(void(^_Nullable)(NSError* _Nullable error))error;


/********** 补全剩下的所有功能 ***********/

// 时间同步
-(void)synchroTimeWithError:(void (^_Nullable)(NSError * _Nullable))error;


// 预约/定时 充电
-(void)orderChargerWithStartHour:(NSInteger)startH startMinute:(NSInteger)startM endHour:(NSInteger)endH endMinute:(NSInteger)endM error:(void (^_Nullable)(NSError * _Nullable))error;

// 查询状态（查询桩的状态信息充电状态等）
-(void)queryDeviceRuningStateWithError:(void(^_Nullable)(NSError* _Nullable error))error;

// 查询充电历史记录
-(void)queryChargeHistoryListWithError:(void(^_Nullable)(NSError* _Nullable error))error;

// 查询历史错误日志
-(void)queryHistoryErrorLogListWithError:(void (^_Nullable)(NSError * _Nullable))error;

/**
 * 分页查询历史错误日志
 */
-(void)queryHistoryErrorLogListWithPage:(int)page error:(void(^_Nullable)(NSError* _Nullable error))error;

// 查询累计充电量
-(void)queryTotleElecQuantityWithError:(void(^_Nullable)(NSError* _Nullable error))error;

// 查询桩的运行诊断信息
-(void)queryRunningDiagnosticInfoWithError:(void(^_Nullable)(NSError* _Nullable error))error;

// 设置音量
-(void)setVolumeWithVolumeSize:(NSInteger)size error:(void(^_Nullable)(NSError* _Nullable error))error;


// 查询充电桩系统信息
-(void)queryDeviceSystemInfoWithError:(void(^_Nullable)(NSError* _Nullable error))error;

// 远程升级 分为 2 步，一步是 启动远程升级进行校验 第二步是 开始下发文件进行远程升级

// 启动远程升级
-(void)remoteUpdateWithData:(NSData*_Nullable)fileData checkSum:(NSString*_Nonnull)checkSum error:(void(^_Nullable)(NSError* _Nullable error))error;




@end
