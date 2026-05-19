#if !defined(Rsa_FTDCSTRUCT_H)
#define Rsa_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcApiDataType.h"

///响应信息
struct CRsaFtdcRspInfoField
{
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
};

///系统用户登录请求
struct CRsaFtdcReqUserLoginField
{
	///交易日
	TRsaFtdcDateType	TradingDay;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///密码
	TRsaFtdcPasswordType	Password;
	///用户端产品信息
	TRsaFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TRsaFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TRsaFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///Mac地址
	TRsaFtdcMacAddressType	MacAddress;
	///数据中心代码
	TRsaFtdcDataCenterIDType	DataCenterID;
	///动态密码
	TRsaFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TRsaFtdcIPAddressType	ClientIPAddress;
	///授权编码
	TRsaFtdcAuthCodeType	AuthCode;
	///自定义字段
	TRsaFtdcFieldContentType	FieldContent;
	///客户端信息采集
	TRsaFtdcClientSystemInfoType	ClientSystemInfo;
};

///系统用户登录应答
struct CRsaFtdcRspUserLoginField
{
	///交易日
	TRsaFtdcDateType	TradingDay;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///登录成功时间
	TRsaFtdcTimeType	LoginTime;
	///用户最大本地报单号
	TRsaFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///交易系统名称
	TRsaFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TRsaFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TRsaFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TRsaFtdcSequenceNoType	UserFlowSize;
	///登录附加信息
	TRsaFtdcLoginInfoType	LoginInfo;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
};

///用户登出请求
struct CRsaFtdcReqUserLogoutField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
};

///用户登出请求
struct CRsaFtdcRspUserLogoutField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
};

///强制用户退出
struct CRsaFtdcForceUserExitField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
};

///用户口令修改
struct CRsaFtdcUserPasswordUpdateField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///旧密码
	TRsaFtdcPasswordType	OldPassword;
	///新密码
	TRsaFtdcPasswordType	NewPassword;
};

///输入报单
struct CRsaFtdcInputOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TRsaFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///有效期类型
	TRsaFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TRsaFtdcDateType	GTDDate;
	///成交量类型
	TRsaFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TRsaFtdcVolumeType	MinVolume;
	///止损价
	TRsaFtdcPriceType	StopPrice;
	///强平原因
	TRsaFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TRsaFtdcBoolType	IsAutoSuspend;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TRsaFtdcBusinessTypeType	BusinessType;
	///数量（小数）
	TRsaFtdcPointVolumeType	VolumeP;
	///策略限制价格
	TRsaFtdcPriceType	AlgoLimitPrice;
	///策略限制tick数量
	TRsaFtdcNumberType	AlgoLimitPriceTick;
	///策略限制时间(ms)
	TRsaFtdcNumberType	AlgoLimitTime;
};

///报单操作
struct CRsaFtdcOrderActionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TRsaFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TRsaFtdcActionFlagType	ActionFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量变化
	TRsaFtdcVolumeType	VolumeChange;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
};

///内存表导出
struct CRsaFtdcMemDBField
{
	///内存表名
	TRsaFtdcMemTableNameType	MemTableName;
};

///投资者资金帐户出入金请求
struct CRsaFtdcReqAccountDepositField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///资金流水号
	TRsaFtdcAccountSeqNoType	AccountSeqNo;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///金额
	TRsaFtdcMoneyType	Amount;
	///出入金方向
	TRsaFtdcAccountDirectionType	AmountDirection;
	///用户代码
	TRsaFtdcUserIDType	UserID;
};

///投资者资金帐户出入金应答
struct CRsaFtdcRspAccountDepositField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///资金流水号
	TRsaFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TRsaFtdcMoneyType	Amount;
	///出入金方向
	TRsaFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TRsaFtdcMoneyType	Available;
	///结算准备金
	TRsaFtdcMoneyType	Balance;
	///用户代码
	TRsaFtdcUserIDType	UserID;
};

///实时上场
struct CRsaFtdcTBCommandField
{
	///DB命令序号
	TRsaFtdcCommandNoType	CommandNo;
	///操作日期
	TRsaFtdcDateType	CommandDate;
	///操作时间
	TRsaFtdcTimeType	CommandTime;
	///DB命令类型
	TRsaFtdcCommandTypeType	CommandType;
	///字段名
	TRsaFtdcFieldNameType	FieldName;
	///字段内容
	TRsaFtdcFieldContentType	FieldContent;
};

///出入金结果
struct CRsaFtdcInvestorAccountDepositResField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///资金流水号
	TRsaFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TRsaFtdcMoneyType	Amount;
	///出入金方向
	TRsaFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TRsaFtdcMoneyType	Available;
	///结算准备金
	TRsaFtdcMoneyType	Balance;
	///用户代码
	TRsaFtdcUserIDType	UserID;
};

///合约状态
struct CRsaFtdcInstrumentStatusField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///品种代码
	TRsaFtdcProductIDType	ProductID;
	///品种名称
	TRsaFtdcProductNameType	ProductName;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TRsaFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TRsaFtdcYearType	DeliveryYear;
	///交割月
	TRsaFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TRsaFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TRsaFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TRsaFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TRsaFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TRsaFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TRsaFtdcPriceTickType	PriceTick;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///多头限仓
	TRsaFtdcVolumeType	LongPosLimit;
	///空头限仓
	TRsaFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TRsaFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TRsaFtdcPriceType	UpperLimitPrice;
	///昨结算
	TRsaFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TRsaFtdcDateType	CreateDate;
	///上市日
	TRsaFtdcDateType	OpenDate;
	///到期日
	TRsaFtdcDateType	ExpireDate;
	///开始交割日
	TRsaFtdcDateType	StartDelivDate;
	///最后交割日
	TRsaFtdcDateType	EndDelivDate;
	///挂牌基准价
	TRsaFtdcPriceType	BasisPrice;
	///当前是否交易
	TRsaFtdcBoolType	IsTrading;
	///基础商品代码
	TRsaFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TRsaFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TRsaFtdcPositionTypeType	PositionType;
	///执行价
	TRsaFtdcPriceType	StrikePrice;
	///期权类型
	TRsaFtdcOptionsTypeType	OptionsType;
	///汇率
	TRsaFtdcRatioType	ExchangeRate;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
	///期权行权方式
	TRsaFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TRsaFtdcMarginCombTypeType	MarginCombType;
	///多头保证金率
	TRsaFtdcRatioType	LongMarginRate;
	///空头保证金率
	TRsaFtdcRatioType	ShortMarginRate;
	///多头保证金按手数
	TRsaFtdcRatioType	LongMarginAmt;
	///空头保证金按手数
	TRsaFtdcRatioType	ShortMarginAmt;
};

///审批模式设置请求
struct CRsaFtdcAdviceRunModeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///自动或者手动
	TRsaFtdcAdviceRunModeType	RunMode;
};

///订阅合约状态
struct CRsaFtdcSubInstrumentStatusField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
	///进入本状态时间
	TRsaFtdcTimeType	EnterTime;
	///进入本状态原因
	TRsaFtdcEnterReasonType	EnterReason;
};

///执行宣告输入
struct CRsaFtdcInputExecOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///数量
	TRsaFtdcVolumeType	Volume;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///执行类型
	TRsaFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TRsaFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TRsaFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TRsaFtdcCloseFlagTypeType	CloseFlag;
	///数量(小数)
	TRsaFtdcPointVolumeType	VolumeP;
};

///执行宣告操作
struct CRsaFtdcExecOrderActionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TRsaFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TRsaFtdcActionFlagType	ActionFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量变化
	TRsaFtdcVolumeType	VolumeChange;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
};

///询价录入
struct CRsaFtdcInputForQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///本地报单编号
	TRsaFtdcOrderLocalIDType	OrderLocalID;
};

///报价录入
struct CRsaFtdcInputQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///应价编号
	TRsaFtdcOrderSysIDType	ForQuoteSysID;
	///卖价格
	TRsaFtdcPriceType	AskPrice;
	///卖数量
	TRsaFtdcVolumeType	AskVolume;
	///卖开平标志
	TRsaFtdcOffsetFlagType	AskOffsetFlag;
	///卖投机套保标志
	TRsaFtdcHedgeFlagType	AskHedgeFlag;
	///买价格
	TRsaFtdcPriceType	BidPrice;
	///买数量
	TRsaFtdcVolumeType	BidVolume;
	///买开平标志
	TRsaFtdcOffsetFlagType	BidOffsetFlag;
	///买投机套保标志
	TRsaFtdcHedgeFlagType	BidHedgeFlag;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///买方本地报单编号
	TRsaFtdcUserOrderLocalIDType	BidOrderRef;
	///卖方本地报单编号
	TRsaFtdcUserOrderLocalIDType	AskOrderRef;
};

///报价操作
struct CRsaFtdcQuoteActionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TRsaFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TRsaFtdcActionFlagType	ActionFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量变化
	TRsaFtdcVolumeType	VolumeChange;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
};

///期权自对冲录入
struct CRsaFtdcInputOptionSelfCloseField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///期权自对冲引用
	TRsaFtdcOrderRefType	OptionSelfCloseRef;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///期权行权的头寸是否自对冲
	TRsaFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TRsaFtdcInvestUnitIDType	InvestUnitID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///客户代码
	TRsaFtdcClientIDType	ClientID;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
};

///期权自对冲操作
struct CRsaFtdcOptionSelfCloseActionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///期权自对冲操作引用
	TRsaFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///期权自对冲引用
	TRsaFtdcOrderRefType	OptionSelfCloseRef;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///期权自对冲操作编号
	TRsaFtdcOrderSysIDType	OptionSelfCloseSysID;
	///报单操作标志
	TRsaFtdcActionFlagType	ActionFlag;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TRsaFtdcInvestUnitIDType	InvestUnitID;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
};

///席位状态切换
struct CRsaFtdcChangeSeatStatusField
{
	///使用哪个通道下单
	TRsaFtdcNumberType	APIID;
	///下单席位号
	TRsaFtdcSeatIDType	SeatID;
	///席位状态方向
	TRsaFtdcSeatDirectionType	SeatDirection;
};

///锁定录入
struct CRsaFtdcInputLockField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///锁定类型
	TRsaFtdcLockTypeType	LockType;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
};

///用户信息采集
struct CRsaFtdcSubmitUserSystemInfoField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///信息长度
	TRsaFtdcContentLengthType	ClientSystemInfoLen;
	///信息内容
	TRsaFtdcClientSystemInfoType	ClientSystemInfo;
	///客户公网ip
	TRsaFtdcIPAddressType	ClientPublicIP;
	///客户端口
	TRsaFtdcPortType	ClientIPPort;
	///登录日期
	TRsaFtdcDateType	ClientLoginDate;
	///登录时间
	TRsaFtdcTimeType	ClientLoginTime;
	///客户认证appid
	TRsaFtdcAppIDType	ClientAppID;
};

///行情基础属性
struct CRsaFtdcMarketDataBaseField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///昨结算
	TRsaFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TRsaFtdcPriceType	PreClosePrice;
	///昨持仓量
	TRsaFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TRsaFtdcRatioType	PreDelta;
};

///行情静态属性
struct CRsaFtdcMarketDataStaticField
{
	///今开盘
	TRsaFtdcPriceType	OpenPrice;
	///最高价
	TRsaFtdcPriceType	HighestPrice;
	///最低价
	TRsaFtdcPriceType	LowestPrice;
	///今收盘
	TRsaFtdcPriceType	ClosePrice;
	///涨停板价
	TRsaFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TRsaFtdcPriceType	LowerLimitPrice;
	///今结算
	TRsaFtdcPriceType	SettlementPrice;
	///今虚实度
	TRsaFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CRsaFtdcMarketDataLastMatchField
{
	///最新价
	TRsaFtdcPriceType	LastPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///成交金额
	TRsaFtdcMoneyType	Turnover;
	///持仓量
	TRsaFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CRsaFtdcMarketDataBestPriceField
{
	///申买价一
	TRsaFtdcPriceType	BidPrice1;
	///申买量一
	TRsaFtdcVolumeType	BidVolume1;
	///申卖价一
	TRsaFtdcPriceType	AskPrice1;
	///申卖量一
	TRsaFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CRsaFtdcMarketDataBid23Field
{
	///申买价二
	TRsaFtdcPriceType	BidPrice2;
	///申买量二
	TRsaFtdcVolumeType	BidVolume2;
	///申买价三
	TRsaFtdcPriceType	BidPrice3;
	///申买量三
	TRsaFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CRsaFtdcMarketDataAsk23Field
{
	///申卖价二
	TRsaFtdcPriceType	AskPrice2;
	///申卖量二
	TRsaFtdcVolumeType	AskVolume2;
	///申卖价三
	TRsaFtdcPriceType	AskPrice3;
	///申卖量三
	TRsaFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CRsaFtdcMarketDataBid45Field
{
	///申买价四
	TRsaFtdcPriceType	BidPrice4;
	///申买量四
	TRsaFtdcVolumeType	BidVolume4;
	///申买价五
	TRsaFtdcPriceType	BidPrice5;
	///申买量五
	TRsaFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CRsaFtdcMarketDataAsk45Field
{
	///申卖价四
	TRsaFtdcPriceType	AskPrice4;
	///申卖量四
	TRsaFtdcVolumeType	AskVolume4;
	///申卖价五
	TRsaFtdcPriceType	AskPrice5;
	///申卖量五
	TRsaFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CRsaFtdcMarketDataUpdateTimeField
{
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TRsaFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TRsaFtdcMillisecType	UpdateMillisec;
};

///深度行情
struct CRsaFtdcDepthMarketDataField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///昨结算
	TRsaFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TRsaFtdcPriceType	PreClosePrice;
	///昨持仓量
	TRsaFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TRsaFtdcRatioType	PreDelta;
	///今开盘
	TRsaFtdcPriceType	OpenPrice;
	///最高价
	TRsaFtdcPriceType	HighestPrice;
	///最低价
	TRsaFtdcPriceType	LowestPrice;
	///今收盘
	TRsaFtdcPriceType	ClosePrice;
	///涨停板价
	TRsaFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TRsaFtdcPriceType	LowerLimitPrice;
	///今结算
	TRsaFtdcPriceType	SettlementPrice;
	///今虚实度
	TRsaFtdcRatioType	CurrDelta;
	///最新价
	TRsaFtdcPriceType	LastPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///成交金额
	TRsaFtdcMoneyType	Turnover;
	///持仓量
	TRsaFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TRsaFtdcPriceType	BidPrice1;
	///申买量一
	TRsaFtdcVolumeType	BidVolume1;
	///申卖价一
	TRsaFtdcPriceType	AskPrice1;
	///申卖量一
	TRsaFtdcVolumeType	AskVolume1;
	///申买价二
	TRsaFtdcPriceType	BidPrice2;
	///申买量二
	TRsaFtdcVolumeType	BidVolume2;
	///申买价三
	TRsaFtdcPriceType	BidPrice3;
	///申买量三
	TRsaFtdcVolumeType	BidVolume3;
	///申卖价二
	TRsaFtdcPriceType	AskPrice2;
	///申卖量二
	TRsaFtdcVolumeType	AskVolume2;
	///申卖价三
	TRsaFtdcPriceType	AskPrice3;
	///申卖量三
	TRsaFtdcVolumeType	AskVolume3;
	///申买价四
	TRsaFtdcPriceType	BidPrice4;
	///申买量四
	TRsaFtdcVolumeType	BidVolume4;
	///申买价五
	TRsaFtdcPriceType	BidPrice5;
	///申买量五
	TRsaFtdcVolumeType	BidVolume5;
	///申卖价四
	TRsaFtdcPriceType	AskPrice4;
	///申卖量四
	TRsaFtdcVolumeType	AskVolume4;
	///申卖价五
	TRsaFtdcPriceType	AskPrice5;
	///申卖量五
	TRsaFtdcVolumeType	AskVolume5;
	///申卖价六
	TRsaFtdcPriceType	AskPrice6;
	///申卖量六
	TRsaFtdcVolumeType	AskVolume6;
	///申卖价七
	TRsaFtdcPriceType	AskPrice7;
	///申卖量七
	TRsaFtdcVolumeType	AskVolume7;
	///申卖价八
	TRsaFtdcPriceType	AskPrice8;
	///申卖量八
	TRsaFtdcVolumeType	AskVolume8;
	///申卖价九
	TRsaFtdcPriceType	AskPrice9;
	///申卖量九
	TRsaFtdcVolumeType	AskVolume9;
	///申买价六
	TRsaFtdcPriceType	BidPrice6;
	///申买量六
	TRsaFtdcVolumeType	BidVolume6;
	///申买价七
	TRsaFtdcPriceType	BidPrice7;
	///申买量七
	TRsaFtdcVolumeType	BidVolume7;
	///申买价八
	TRsaFtdcPriceType	BidPrice8;
	///申买量八
	TRsaFtdcVolumeType	BidVolume8;
	///申买价九
	TRsaFtdcPriceType	BidPrice9;
	///申买量九
	TRsaFtdcVolumeType	BidVolume9;
	///申卖价十
	TRsaFtdcPriceType	AskPrice10;
	///申卖量十
	TRsaFtdcVolumeType	AskVolume10;
	///申买价十
	TRsaFtdcPriceType	BidPrice10;
	///申买量十
	TRsaFtdcVolumeType	BidVolume10;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TRsaFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TRsaFtdcMillisecType	UpdateMillisec;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///总卖出数量
	TRsaFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TRsaFtdcVolumeType	VolumeBidLot;
	///合约状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
	///当前日期
	TRsaFtdcTradingDayType	CalendarDate;
	///组播增量序号
	TRsaFtdcPacketNoType	PacketNo;
	///合约序号
	TRsaFtdcNumberType	InstrumentNo;
	///数据中心代码
	TRsaFtdcDataCenterIDType	DataCenterID;
	///更新时间
	TRsaFtdcInt64Type	UpdateTs;
	///最新成交量
	TRsaFtdcVolumeType	LastTraded;
	///最新成交额
	TRsaFtdcMoneyType	LastTurnover;
};

///订阅合约的相关信息
struct CRsaFtdcSpecificInstrumentField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///投资者权限
struct CRsaFtdcInvestorRightField
{
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///是否使用净持仓报单,投顾账户有效
	TRsaFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TRsaFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TRsaFtdcTradingRightType	TradingRight;
	///是否检查资金
	TRsaFtdcBoolType	CheckAccount;
	///是否检查持仓
	TRsaFtdcBoolType	CheckPosition;
	///报单是否报警
	TRsaFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TRsaFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TRsaFtdcDistributeTypeType	DistributeType;
};

///交易所代码
struct CRsaFtdcMarketDataExchangeIDField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
};

///共享内存行情查询
struct CRsaFtdcShmDepthMarketDataField
{
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///订阅号
	TRsaFtdcTopicIDType	TopicID;
};

///TOPIC查询
struct CRsaFtdcTopicSearchField
{
	///订阅号
	TRsaFtdcTopicIDType	TopicID;
};

///分价行情
struct CRsaFtdcMBLMarketDataField
{
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///价格
	TRsaFtdcPriceType	Price;
	///数量
	TRsaFtdcVolumeType	Volume;
	///最后修改时间
	TRsaFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TRsaFtdcMillisecType	UpdateMillisec;
};

///套利合约买卖总量
struct CRsaFtdcMarketDataCMBVolumeField
{
	///总卖出数量
	TRsaFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TRsaFtdcVolumeType	VolumeBidLot;
};

///合约状态
struct CRsaFtdcQmdInstrumentStateField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
};

///订阅合约的相关信息
struct CRsaFtdcSubSpecificInstrumentField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcSubInstrumentIDType	InstrumentID;
};

///行情申卖六七属性
struct CRsaFtdcMarketDataAsk67Field
{
	///申卖价六
	TRsaFtdcPriceType	AskPrice6;
	///申卖量六
	TRsaFtdcVolumeType	AskVolume6;
	///申卖价七
	TRsaFtdcPriceType	AskPrice7;
	///申卖量七
	TRsaFtdcVolumeType	AskVolume7;
};

///行情申卖八九属性
struct CRsaFtdcMarketDataAsk89Field
{
	///申卖价八
	TRsaFtdcPriceType	AskPrice8;
	///申卖量八
	TRsaFtdcVolumeType	AskVolume8;
	///申卖价九
	TRsaFtdcPriceType	AskPrice9;
	///申卖量九
	TRsaFtdcVolumeType	AskVolume9;
};

///行情申买六七属性
struct CRsaFtdcMarketDataBid67Field
{
	///申买价六
	TRsaFtdcPriceType	BidPrice6;
	///申买量六
	TRsaFtdcVolumeType	BidVolume6;
	///申买价七
	TRsaFtdcPriceType	BidPrice7;
	///申买量七
	TRsaFtdcVolumeType	BidVolume7;
};

///行情申买八九属性
struct CRsaFtdcMarketDataBid89Field
{
	///申买价八
	TRsaFtdcPriceType	BidPrice8;
	///申买量八
	TRsaFtdcVolumeType	BidVolume8;
	///申买价九
	TRsaFtdcPriceType	BidPrice9;
	///申买量九
	TRsaFtdcVolumeType	BidVolume9;
};

///行情申买申卖十属性
struct CRsaFtdcMarketDataAskBid10Field
{
	///申卖价十
	TRsaFtdcPriceType	AskPrice10;
	///申卖量十
	TRsaFtdcVolumeType	AskVolume10;
	///申买价十
	TRsaFtdcPriceType	BidPrice10;
	///申买量十
	TRsaFtdcVolumeType	BidVolume10;
};

///行情合约状态
struct CRsaFtdcMarketDataInstrumentStatusField
{
	///合约状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
};

///Bar行情
struct CRsaFtdcBarMarketDataField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///Bar精度
	TRsaFtdcBarPrecesType	BarPreces;
	///Bar周期
	TRsaFtdcNumberType	BarPeriod;
	///Bar时间
	TRsaFtdcInt64Type	BarTime;
	///更新时间
	TRsaFtdcInt64Type	UpdateTs;
	///最后修改时间
	TRsaFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TRsaFtdcMillisecType	UpdateMillisec;
	///最高价
	TRsaFtdcPriceType	HighestPrice;
	///最低价
	TRsaFtdcPriceType	LowestPrice;
	///开盘价
	TRsaFtdcPriceType	Open;
	///最高价
	TRsaFtdcPriceType	High;
	///最低价
	TRsaFtdcPriceType	Low;
	///收盘价
	TRsaFtdcPriceType	Close;
	///总成交量
	TRsaFtdcVolumeType	Volume;
	///最新成交量
	TRsaFtdcVolumeType	LastTraded;
	///持仓量
	TRsaFtdcLargeVolumeType	OpenInterest;
	///成交额
	TRsaFtdcMoneyType	Turnover;
	///最新成交额
	TRsaFtdcMoneyType	LastTurnover;
};

///查询Bar行情请求
struct CRsaFtdcReqQryBarFromRmdField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///L2Tick行情
struct CRsaFtdcL2TickMarketDataField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///Tick序号
	TRsaFtdcInt64Type	TickIndex;
	///Tick时间
	TRsaFtdcInt64Type	TickTime;
	///Tick类型
	TRsaFtdcTickTypeType	TickType;
	///买方报单编号
	TRsaFtdcOrderSysIDType	BuyOrderSysID;
	///卖方报单编号
	TRsaFtdcOrderSysIDType	SellOrderSysID;
	///价格
	TRsaFtdcPriceType	Price;
	///数量
	TRsaFtdcVolumeType	Volume;
	///Tick买卖标志
	TRsaFtdcTickBSFlagType	TickBSFlag;
	///通道号
	TRsaFtdcNumberType	ChannelID;
};

///成交
struct CRsaFtdcTradeField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///成交编号
	TRsaFtdcTradeIDType	TradeID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///成交价格
	TRsaFtdcPriceType	TradePrice;
	///成交数量
	TRsaFtdcVolumeType	TradeVolume;
	///成交时间
	TRsaFtdcTimeType	TradeTime;
	///清算会员编号
	TRsaFtdcParticipantIDType	ClearingPartID;
	///成交金额
	TRsaFtdcMoneyType	TradeAmnt;
	///交易类型
	TRsaFtdcTradeTypeType	TradeType;
	///成交数量（小数）
	TRsaFtdcPointVolumeType	TradeVolumeP;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///营业部名称
	TRsaFtdcBranchNameType	BranchName;
};

///报单
struct CRsaFtdcOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TRsaFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///有效期类型
	TRsaFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TRsaFtdcDateType	GTDDate;
	///成交量类型
	TRsaFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TRsaFtdcVolumeType	MinVolume;
	///止损价
	TRsaFtdcPriceType	StopPrice;
	///强平原因
	TRsaFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TRsaFtdcBoolType	IsAutoSuspend;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TRsaFtdcBusinessTypeType	BusinessType;
	///数量（小数）
	TRsaFtdcPointVolumeType	VolumeP;
	///策略限制价格
	TRsaFtdcPriceType	AlgoLimitPrice;
	///策略限制tick数量
	TRsaFtdcNumberType	AlgoLimitPriceTick;
	///策略限制时间(ms)
	TRsaFtdcNumberType	AlgoLimitTime;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///报单来源
	TRsaFtdcOrderSourceType	OrderSource;
	///报单状态
	TRsaFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///撤单用户编号
	TRsaFtdcUserIDType	CancelUserID;
	///已经成交数量
	TRsaFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TRsaFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TRsaFtdcVolumeType	VolumeCancled;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TRsaFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TRsaFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///每手手续费
	TRsaFtdcMoneyType	EachFee;
	///每手保证金
	TRsaFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TRsaFtdcMoneyType	EachPremium;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///记录编号
	TRsaFtdcSequenceNoType	RecNum;
	///硬盘序列号
	TRsaFtdcHDSerialIDType	HDSerialID;
	///营业部名称
	TRsaFtdcBranchNameType	BranchName;
	///报单提交状态
	TRsaFtdcOrderSubmitStatusType	OrderSubmitStatus;
};

///数据流回退
struct CRsaFtdcFlowMessageCancelField
{
	///序列系列号
	TRsaFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TRsaFtdcDateType	TradingDay;
	///数据中心代码
	TRsaFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TRsaFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TRsaFtdcSequenceNoType	EndSequenceNo;
};

///信息分发
struct CRsaFtdcDisseminationField
{
	///序列系列号
	TRsaFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TRsaFtdcSequenceNoType	SequenceNo;
};

///警告消息通知
struct CRsaFtdcMessageNotifyField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///累加次数
	TRsaFtdcTotalNumsType	Nums;
	///警告级别
	TRsaFtdcErrorLevelType	WarnLevel;
	///警告编号
	TRsaFtdcErrorIDType	WarnID;
	///警告信息
	TRsaFtdcLargeErrorMsgType	WarnMsg;
	///警告时间
	TRsaFtdcTimeType	WarnTime;
};

///工作流指令通知
struct CRsaFtdcAdviceOrderField
{
	///投顾用户代码
	TRsaFtdcUserIDType	InvestorAdvicer;
	///投资经理
	TRsaFtdcUserIDType	InvestorManager;
	///交易员
	TRsaFtdcUserIDType	UserTrader;
	///冻结数量
	TRsaFtdcVolumeType	VolumeFrozen;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TRsaFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///有效期类型
	TRsaFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TRsaFtdcDateType	GTDDate;
	///成交量类型
	TRsaFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TRsaFtdcVolumeType	MinVolume;
	///止损价
	TRsaFtdcPriceType	StopPrice;
	///强平原因
	TRsaFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TRsaFtdcBoolType	IsAutoSuspend;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TRsaFtdcBusinessTypeType	BusinessType;
	///数量（小数）
	TRsaFtdcPointVolumeType	VolumeP;
	///策略限制价格
	TRsaFtdcPriceType	AlgoLimitPrice;
	///策略限制tick数量
	TRsaFtdcNumberType	AlgoLimitPriceTick;
	///策略限制时间(ms)
	TRsaFtdcNumberType	AlgoLimitTime;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///报单来源
	TRsaFtdcOrderSourceType	OrderSource;
	///报单状态
	TRsaFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///撤单用户编号
	TRsaFtdcUserIDType	CancelUserID;
	///已经成交数量
	TRsaFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TRsaFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TRsaFtdcVolumeType	VolumeCancled;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TRsaFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TRsaFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///每手手续费
	TRsaFtdcMoneyType	EachFee;
	///每手保证金
	TRsaFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TRsaFtdcMoneyType	EachPremium;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///记录编号
	TRsaFtdcSequenceNoType	RecNum;
	///指令单用户信息
	TRsaFtdcAdviceUserInfoType	AdviceUserInfo;
	///硬盘序列号
	TRsaFtdcHDSerialIDType	HDSerialID;
	///营业部名称
	TRsaFtdcBranchNameType	BranchName;
	///报单提交状态
	TRsaFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///父投资者编号
	TRsaFtdcInvestorIDType	ParentInvestorID;
};

///执行宣告通知
struct CRsaFtdcExecOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///数量
	TRsaFtdcVolumeType	Volume;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///执行类型
	TRsaFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TRsaFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TRsaFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TRsaFtdcCloseFlagTypeType	CloseFlag;
	///数量(小数)
	TRsaFtdcPointVolumeType	VolumeP;
	///执行结果
	TRsaFtdcExecResultTypeType	ExecResultType;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///报单来源
	TRsaFtdcOrderSourceType	OrderSource;
	///报单状态
	TRsaFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///撤单用户编号
	TRsaFtdcUserIDType	CancelUserID;
	///已经成交数量
	TRsaFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TRsaFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TRsaFtdcVolumeType	VolumeCancled;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TRsaFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TRsaFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///每手手续费
	TRsaFtdcMoneyType	EachFee;
	///每手保证金
	TRsaFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TRsaFtdcMoneyType	EachPremium;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///记录编号
	TRsaFtdcSequenceNoType	RecNum;
	///报单提交状态
	TRsaFtdcOrderSubmitStatusType	OrderSubmitStatus;
};

///询价流通知
struct CRsaFtdcForQuoteRspField
{
	///交易日
	TRsaFtdcDateType	TradingDay;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///询价编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
};

///报价通知
struct CRsaFtdcQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///应价编号
	TRsaFtdcOrderSysIDType	ForQuoteSysID;
	///卖价格
	TRsaFtdcPriceType	AskPrice;
	///卖数量
	TRsaFtdcVolumeType	AskVolume;
	///卖开平标志
	TRsaFtdcOffsetFlagType	AskOffsetFlag;
	///卖投机套保标志
	TRsaFtdcHedgeFlagType	AskHedgeFlag;
	///买价格
	TRsaFtdcPriceType	BidPrice;
	///买数量
	TRsaFtdcVolumeType	BidVolume;
	///买开平标志
	TRsaFtdcOffsetFlagType	BidOffsetFlag;
	///买投机套保标志
	TRsaFtdcHedgeFlagType	BidHedgeFlag;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///买方本地报单编号
	TRsaFtdcUserOrderLocalIDType	BidOrderRef;
	///卖方本地报单编号
	TRsaFtdcUserOrderLocalIDType	AskOrderRef;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///报单来源
	TRsaFtdcOrderSourceType	OrderSource;
	///报单状态
	TRsaFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///撤单用户编号
	TRsaFtdcUserIDType	CancelUserID;
	///已经成交数量
	TRsaFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TRsaFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TRsaFtdcVolumeType	VolumeCancled;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TRsaFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TRsaFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///每手手续费
	TRsaFtdcMoneyType	EachFee;
	///每手保证金
	TRsaFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TRsaFtdcMoneyType	EachPremium;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///记录编号
	TRsaFtdcSequenceNoType	RecNum;
	///买方系统报单编号
	TRsaFtdcOrderSysIDType	BidOrderSysID;
	///卖方系统报单编号
	TRsaFtdcOrderSysIDType	AskOrderSysID;
	///报单提交状态
	TRsaFtdcOrderSubmitStatusType	OrderSubmitStatus;
};

///期权自对冲
struct CRsaFtdcNtfOptionSelfCloseField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///期权自对冲引用
	TRsaFtdcOrderRefType	OptionSelfCloseRef;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///期权行权的头寸是否自对冲
	TRsaFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///本地期权自对冲编号
	TRsaFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///会员编号
	TRsaFtdcParticipantIDType	ParticipantID;
	///客户代码
	TRsaFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TRsaFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TRsaFtdcTraderIDType	TraderID;
	///安装编号
	TRsaFtdcInstallIDType	InstallID;
	///期权自对冲提交状态
	TRsaFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TRsaFtdcSequenceNoType	NotifySequence;
	///交易日
	TRsaFtdcDateType	TradingDay;
	///结算编号
	TRsaFtdcSettlementIDType	SettlementID;
	///期权自对冲操作编号
	TRsaFtdcOrderSysIDType	OptionSelfCloseSysID;
	///报单日期
	TRsaFtdcDateType	InsertDate;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///自对冲结果
	TRsaFtdcExecResultTypeType	ExecResultType;
	///清算会员编号
	TRsaFtdcParticipantIDType	ClearingPartID;
	///序号
	TRsaFtdcSequenceNoType	SequenceNo;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///用户端产品信息
	TRsaFtdcProductInfoType	UserProductInfo;
	///状态信息
	TRsaFtdcStatusMsgType	StatusMsg;
	///操作用户代码
	TRsaFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	TRsaFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	///营业部编号
	TRsaFtdcBranchIDType	BranchID;
	///投资单元代码
	TRsaFtdcInvestUnitIDType	InvestUnitID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
};

///锁定
struct CRsaFtdcLockField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///锁定类型
	TRsaFtdcLockTypeType	LockType;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///锁定编号
	TRsaFtdcOrderSysIDType	LockSysID;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
	///锁定状态
	TRsaFtdcOrderActionStatusType	LockStatus;
	///撤销时间
	TRsaFtdcTimeType	CancelTime;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///请求编号
	TRsaFtdcRequestIDType	RequestID;
	///下单IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TRsaFtdcMacAddressType	MacAddress;
	///营业部代码
	TRsaFtdcBranchIDType	BranchID;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
	///记录编号
	TRsaFtdcSequenceNoType	RecNum;
};

///报单查询
struct CRsaFtdcQryOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开始时间
	TRsaFtdcTimeType	InsertTimeStart;
	///结束时间
	TRsaFtdcTimeType	InsertTimeEnd;
};

///成交查询
struct CRsaFtdcQryTradeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///成交编号
	TRsaFtdcTradeIDType	TradeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///合约查询
struct CRsaFtdcQryInstrumentField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///产品代码
	TRsaFtdcProductIDType	ProductID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///合约查询应答
struct CRsaFtdcRspInstrumentField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///品种代码
	TRsaFtdcProductIDType	ProductID;
	///品种名称
	TRsaFtdcProductNameType	ProductName;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TRsaFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TRsaFtdcYearType	DeliveryYear;
	///交割月
	TRsaFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TRsaFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TRsaFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TRsaFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TRsaFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TRsaFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TRsaFtdcPriceTickType	PriceTick;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///多头限仓
	TRsaFtdcVolumeType	LongPosLimit;
	///空头限仓
	TRsaFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TRsaFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TRsaFtdcPriceType	UpperLimitPrice;
	///昨结算
	TRsaFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TRsaFtdcDateType	CreateDate;
	///上市日
	TRsaFtdcDateType	OpenDate;
	///到期日
	TRsaFtdcDateType	ExpireDate;
	///开始交割日
	TRsaFtdcDateType	StartDelivDate;
	///最后交割日
	TRsaFtdcDateType	EndDelivDate;
	///挂牌基准价
	TRsaFtdcPriceType	BasisPrice;
	///当前是否交易
	TRsaFtdcBoolType	IsTrading;
	///基础商品代码
	TRsaFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TRsaFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TRsaFtdcPositionTypeType	PositionType;
	///执行价
	TRsaFtdcPriceType	StrikePrice;
	///期权类型
	TRsaFtdcOptionsTypeType	OptionsType;
	///汇率
	TRsaFtdcRatioType	ExchangeRate;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
	///期权行权方式
	TRsaFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TRsaFtdcMarginCombTypeType	MarginCombType;
	///多头保证金率
	TRsaFtdcRatioType	LongMarginRate;
	///空头保证金率
	TRsaFtdcRatioType	ShortMarginRate;
	///多头保证金按手数
	TRsaFtdcRatioType	LongMarginAmt;
	///空头保证金按手数
	TRsaFtdcRatioType	ShortMarginAmt;
};

///投资者资金查询
struct CRsaFtdcQryInvestorAccountField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///投资者资金应答
struct CRsaFtdcRspInvestorAccountField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///上次结算准备金
	TRsaFtdcMoneyType	PreBalance;
	///上日可用资金
	TRsaFtdcMoneyType	PreAvailable;
	///入金金额
	TRsaFtdcMoneyType	Deposit;
	///出金金额
	TRsaFtdcMoneyType	Withdraw;
	///占用保证金
	TRsaFtdcMoneyType	Margin;
	///期权权利金收支
	TRsaFtdcMoneyType	Premium;
	///手续费
	TRsaFtdcMoneyType	Fee;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TRsaFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///可用资金
	TRsaFtdcMoneyType	Available;
	///结算准备金
	TRsaFtdcMoneyType	Balance;
	///多头占用保证金
	TRsaFtdcMoneyType	LongMargin;
	///空头占用保证金
	TRsaFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TRsaFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TRsaFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TRsaFtdcMoneyType	DynamicRights;
	///风险度
	TRsaFtdcRatioType	Risk;
	///其他费用
	TRsaFtdcMoneyType	OtherFee;
	///质押金额
	TRsaFtdcMoneyType	Mortgage;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///可取资金
	TRsaFtdcMoneyType	WithdrawQuota;
	///冻结的资金
	TRsaFtdcMoneyType	FrozenCash;
	///账户余额
	TRsaFtdcMoneyType	CurrentBalance;
	///总资产
	TRsaFtdcMoneyType	AssetBalance;
	///总市值
	TRsaFtdcMoneyType	MarketValue;
	///优先资金
	TRsaFtdcMoneyType	Prioprity;
	///现金资产
	TRsaFtdcMoneyType	FundAsset;
	///上海限购额度
	TRsaFtdcMoneyType	PurQuotaSh;
	///上海可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSh;
	///深圳限购额度
	TRsaFtdcMoneyType	PurQuotaSz;
	///深圳可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSz;
};

///可用投资者查询
struct CRsaFtdcQryUserInvestorField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
};

///可用投资者应答
struct CRsaFtdcRspUserInvestorField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///默认用户代码
	TRsaFtdcUserIDType	NextUserID;
	///是否可下单
	TRsaFtdcAdviceUserOrderModeType	OrderMode;
	///自动或者手动
	TRsaFtdcAdviceRunModeType	RunMode;
	///工作流断线处理标示符
	TRsaFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
	///合约交易权限
	TRsaFtdcTradingRightType	TradingRight;
};

///投资者关系查询
struct CRsaFtdcQryInvestorRelationField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///投资者关系应答
struct CRsaFtdcRspInvestorRelationField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///父投资者编号
	TRsaFtdcInvestorIDType	ParentInvestorID;
	///顺序编号
	TRsaFtdcSequenceNoType	SpecifyNo;
};

///交易所查询请求
struct CRsaFtdcQryExchangeField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
};

///交易所查询应答
struct CRsaFtdcRspExchangeField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TRsaFtdcExchangeNameType	ExchangeName;
};

///投资者持仓查询请求
struct CRsaFtdcQryInvestorPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///投资者持仓查询应答
struct CRsaFtdcRspInvestorPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TRsaFtdcMoneyType	UsedMargin;
	///总持仓量
	TRsaFtdcVolumeType	Position;
	///总持仓成本
	TRsaFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TRsaFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TRsaFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TRsaFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TRsaFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TRsaFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TRsaFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TRsaFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TRsaFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TRsaFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///执行冻结持仓
	TRsaFtdcVolumeType	StrikeFrozenPosition;
	///放弃执行冻结持仓
	TRsaFtdcVolumeType	AbandonFrozenPosition;
	///成本价
	TRsaFtdcPriceType	CostPrice;
	///开仓成本
	TRsaFtdcMoneyType	OpenCost;
	///今持仓(包含冻结)
	TRsaFtdcVolumeType	TodayPosition;
	///今持仓冻结持仓
	TRsaFtdcVolumeType	TodayFrozenClosing;
	///总持仓量(小数)
	TRsaFtdcPointVolumeType	PositionP;
};

///用户查询
struct CRsaFtdcQryUserField
{
	///交易用户代码
	TRsaFtdcUserIDType	StartUserID;
	///交易用户代码
	TRsaFtdcUserIDType	EndUserID;
};

///用户
struct CRsaFtdcRspUserField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户登录密码
	TRsaFtdcPasswordType	Password;
	///是否活跃
	TRsaFtdcIsActiveType	IsActive;
	///用户名称
	TRsaFtdcUserNameType	UserName;
	///用户类型
	TRsaFtdcUserTypeType	UserType;
	///营业部
	TRsaFtdcDepartmentType	Department;
	///授权功能集
	TRsaFtdcGrantFuncSetType	GrantFuncSet;
	///最大在线数
	TRsaFtdcNumberType	MaxOnline;
	///IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///是否检查连接产品
	TRsaFtdcBoolType	CheckProductInfo;
	///Mac地址
	TRsaFtdcMacAddressType	MacAddress;
	///是否检查IP和MAC
	TRsaFtdcBoolType	CheckIPMacAddr;
	///错误登陆次数限制
	TRsaFtdcNumberType	LoginErrorLimit;
	///目前错误登陆次数
	TRsaFtdcNumberType	LoginErrorCount;
	///硬盘序列号
	TRsaFtdcHDSerialIDType	HDSerialID;
	///密码是否更新
	TRsaFtdcIsUpdateType	IsUpdate;
};

///投资者手续费率查询
struct CRsaFtdcQryInvestorFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///投资者手续费率
struct CRsaFtdcRspInvestorFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TRsaFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TRsaFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TRsaFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TRsaFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TRsaFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TRsaFtdcRatioType	OTFeeAmt;
};

///投资者保证金率查询
struct CRsaFtdcQryInvestorMarginField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
};

///投资者保证金率
struct CRsaFtdcRspInvestorMarginField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///多头占用保证金按比例
	TRsaFtdcRatioType	LongMarginRate;
	///多头保证金按手数
	TRsaFtdcRatioType	LongMarginAmt;
	///空头占用保证金按比例
	TRsaFtdcRatioType	ShortMarginRate;
	///空头保证金按手数
	TRsaFtdcRatioType	ShortMarginAmt;
};

///投资者查询
struct CRsaFtdcQryInvestorField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///投资者应答
struct CRsaFtdcRspInvestorField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///投资者名称
	TRsaFtdcInvestorNameType	InvestorName;
	///投资者类型
	TRsaFtdcInvestorTypeType	InvestorType;
	///投资者组编号
	TRsaFtdcInvestorIDType	GroupID;
	///投资者组名
	TRsaFtdcInvestorNameType	GroupName;
	///别名
	TRsaFtdcAliasType	Alias;
	///连接类型
	TRsaFtdcLinkTypeType	LinkType;
	///资金账户编号
	TRsaFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TRsaFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TRsaFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TRsaFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TRsaFtdcTradingRightType	TradingRight;
	///是否检查资金
	TRsaFtdcBoolType	CheckAccount;
	///是否检查持仓
	TRsaFtdcBoolType	CheckPosition;
	///报单是否报警
	TRsaFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TRsaFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TRsaFtdcDistributeTypeType	DistributeType;
	///跟随资金账户编号
	TRsaFtdcInvestorIDType	FollowParentInvestorID;
	///倍率
	TRsaFtdcRatioType	FollowRate;
};

///账号风险状况查询
struct CRsaFtdcQryAccountRiskField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///账号风险状况应答
struct CRsaFtdcRspAccountRiskField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///设置准备金
	TRsaFtdcMoneyType	SetBalance;
	///开仓红线
	TRsaFtdcMoneyType	OpenAvailable;
	///平仓红线
	TRsaFtdcMoneyType	OffsetAvailable;
	///账户状态
	TRsaFtdcAccountStatusType	AccountStatus;
	///动态权益
	TRsaFtdcMoneyType	DynamicRights;
	///账户权限
	TRsaFtdcTradingRightType	TradingRight;
};

///交易用户会话查询
struct CRsaFtdcQryUserSessionField
{
	///交易用户代码
	TRsaFtdcUserIDType	StartUserID;
	///交易用户代码
	TRsaFtdcUserIDType	EndUserID;
};

///交易用户会话应答
struct CRsaFtdcRspUserSessionField
{
	///经纪公司代码
	TRsaFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///交易用户类型
	TRsaFtdcUserTypeType	UserType;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///前置编号
	TRsaFtdcFrontIDType	FrontID;
	///登录时间
	TRsaFtdcTimeType	LoginTime;
	///IP地址
	TRsaFtdcIPAddressType	IPAddress;
	///Mac地址
	TRsaFtdcMacAddressType	MacAddress;
	///用户端产品信息
	TRsaFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TRsaFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TRsaFtdcProtocolInfoType	ProtocolInfo;
	///硬盘序列号
	TRsaFtdcHDSerialIDType	HDSerialID;
};

///行情查询
struct CRsaFtdcQryMarketDataField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///行情应答
struct CRsaFtdcRspMarketDataField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///昨结算
	TRsaFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TRsaFtdcPriceType	PreClosePrice;
	///昨持仓量
	TRsaFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TRsaFtdcRatioType	PreDelta;
	///今开盘
	TRsaFtdcPriceType	OpenPrice;
	///最高价
	TRsaFtdcPriceType	HighestPrice;
	///最低价
	TRsaFtdcPriceType	LowestPrice;
	///今收盘
	TRsaFtdcPriceType	ClosePrice;
	///涨停板价
	TRsaFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TRsaFtdcPriceType	LowerLimitPrice;
	///今结算
	TRsaFtdcPriceType	SettlementPrice;
	///今虚实度
	TRsaFtdcRatioType	CurrDelta;
	///最新价
	TRsaFtdcPriceType	LastPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
	///成交金额
	TRsaFtdcMoneyType	Turnover;
	///持仓量
	TRsaFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TRsaFtdcPriceType	BidPrice1;
	///申买量一
	TRsaFtdcVolumeType	BidVolume1;
	///申卖价一
	TRsaFtdcPriceType	AskPrice1;
	///申卖量一
	TRsaFtdcVolumeType	AskVolume1;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TRsaFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TRsaFtdcMillisecType	UpdateMillisec;
	///合约状态
	TRsaFtdcInstrumentStatusType	InstrumentStatus;
};

///产品查询
struct CRsaFtdcQryProductField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///产品代码
	TRsaFtdcProductIDType	ProductID;
};

///产品应答
struct CRsaFtdcRspProductField
{
	///产品代码
	TRsaFtdcProductIDType	ProductID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者发行的产品名称
	TRsaFtdcProductNameType	ProductName;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
	///数量乘数
	TRsaFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TRsaFtdcPriceTickType	PriceTick;
	///市价单最大下单量
	TRsaFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TRsaFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TRsaFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TRsaFtdcVolumeType	MinLimitOrderVolume;
	///交易节代码
	TRsaFtdcSessionNameType	SessionName;
};

///内部来回消息
struct CRsaFtdcPingPongField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///编号
	TRsaFtdcSequenceNoType	SequenceNo;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
};

///最大可交易数量查询请求
struct CRsaFtdcQryMaxVolumeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
};

///最大可交易数量查询应答
struct CRsaFtdcRspMaxVolumeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开平标志
	TRsaFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///数量
	TRsaFtdcVolumeType	Volume;
};

///工作流交易员查询请求
struct CRsaFtdcQryAdviceTraderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///登录经纪公司编号
	TRsaFtdcBrokerIDType	LogBrokerID;
	///登录用户代码
	TRsaFtdcUserIDType	LogUserID;
	///用户端接口版本
	TRsaFtdcProductInfoType	ApiVersion;
	///用户端程序版本
	TRsaFtdcProductInfoType	UserVersion;
};

///工作流交易员查询应答
struct CRsaFtdcRspAdviceTraderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///关联用户代码
	TRsaFtdcUserIDType	RelationUserID;
	///关联用户名称
	TRsaFtdcUserNameType	RelationUserName;
};

///组合持仓明细查询请求
struct CRsaFtdcQryCmbPositionDetailField
{
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///组合持仓明细查询应答
struct CRsaFtdcRspCmbPositionDetailField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///单腿合约代码
	TRsaFtdcInstrumentIDType	CmbInstrumentID;
	///成交编号
	TRsaFtdcTradeIDType	TradeID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///持仓量
	TRsaFtdcVolumeType	Position;
	///单腿编号
	TRsaFtdcNumberType	LegQty;
	///交易日期
	TRsaFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询请求
struct CRsaFtdcQrySettlementInfoField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易日期
	TRsaFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询应答
struct CRsaFtdcRspSettlementInfoField
{
	///交易日期
	TRsaFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///序号
	TRsaFtdcSequenceNoType	SequenceNo;
	///消息正文
	TRsaFtdcContentType	Content;
};

///查询结果集分页
struct CRsaFtdcQryResultPageField
{
	///结果集编号
	TRsaFtdcSessionIDType	ResultID;
	///总记录数
	TRsaFtdcNumberType	Count;
	///总页数
	TRsaFtdcNumberType	Pages;
	///剩余页数
	TRsaFtdcNumberType	Remain;
};

///查询持仓明细请求
struct CRsaFtdcQryPositionDetailField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///查询持仓明细应答
struct CRsaFtdcRspPositionDetailField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///开仓日期
	TRsaFtdcDateType	OpenDate;
	///成交编号
	TRsaFtdcTradeIDType	TradeID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///开仓价
	TRsaFtdcMoneyType	OpenPrice;
	///交易日
	TRsaFtdcDateType	TradingDay;
	///交易类型
	TRsaFtdcTradeTypeType	TradeType;
	///组合合约代码
	TRsaFtdcInstrumentIDType	CombInstrumentID;
	///逐日盯市平仓盈亏
	TRsaFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TRsaFtdcMoneyType	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	TRsaFtdcMoneyType	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	TRsaFtdcMoneyType	PositionProfitByTrade;
	///投资者保证金
	TRsaFtdcMoneyType	Margin;
	///交易所保证金
	TRsaFtdcMoneyType	ExchMargin;
	///保证金率
	TRsaFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TRsaFtdcMoneyType	MarginRateByVolume;
	///昨结算价
	TRsaFtdcPriceType	LastSettlementPrice;
	///结算价
	TRsaFtdcPriceType	SettlementPrice;
	///平仓量
	TRsaFtdcVolumeType	CloseVolume;
	///平仓金额
	TRsaFtdcMoneyType	CloseAmount;
	///结算编号
	TRsaFtdcSettlementIDType	SettlementID;
	///投资单元代码
	TRsaFtdcInvestUnitIDType	InvestUnitID;
	///持仓明细编号
	TRsaFtdcNumberType	SeqNum;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///持仓明细冻结数量
	TRsaFtdcVolumeType	FrozenVolume;
	///数量(小数)
	TRsaFtdcPointVolumeType	VolumeP;
	///持仓明细冻结数量(小数)
	TRsaFtdcPointVolumeType	FrozenVolumeP;
	///平仓量(小数)
	TRsaFtdcPointVolumeType	CloseVolumeP;
};

///询价查询
struct CRsaFtdcQryForQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
};

///询价查询应答
struct CRsaFtdcForQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///本地报单编号
	TRsaFtdcOrderLocalIDType	OrderLocalID;
	///询价状态
	TRsaFtdcForQuoteStatusTypeType	ForQuoteStatus;
	///交易日
	TRsaFtdcDateType	TradingDay;
	///插入时间
	TRsaFtdcTimeType	InsertTime;
};

///报价查询
struct CRsaFtdcQryQuoteField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///开始时间
	TRsaFtdcTimeType	InsertTimeStart;
	///结束时间
	TRsaFtdcTimeType	InsertTimeEnd;
};

///投资者期权手续费率查询
struct CRsaFtdcQryInvestorOptionFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
};

///投资者期权手续费率
struct CRsaFtdcRspInvestorOptionFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TRsaFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TRsaFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TRsaFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TRsaFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TRsaFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TRsaFtdcRatioType	OTFeeAmt;
	///执行手续费按比例
	TRsaFtdcRatioType	StrikeFeeRate;
	///执行手续费按手数
	TRsaFtdcRatioType	StrikeFeeAmt;
};

///执行宣告查询
struct CRsaFtdcQryExecOrderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///报单编号
	TRsaFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开始时间
	TRsaFtdcTimeType	InsertTimeStart;
	///结束时间
	TRsaFtdcTimeType	InsertTimeEnd;
};

///投资者通知
struct CRsaFtdcRtnInvestorField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///投资者名称
	TRsaFtdcInvestorNameType	InvestorName;
	///投资者类型
	TRsaFtdcInvestorTypeType	InvestorType;
	///投资者组编号
	TRsaFtdcInvestorIDType	GroupID;
	///投资者组名
	TRsaFtdcInvestorNameType	GroupName;
	///别名
	TRsaFtdcAliasType	Alias;
	///连接类型
	TRsaFtdcLinkTypeType	LinkType;
	///资金账户编号
	TRsaFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TRsaFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TRsaFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TRsaFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TRsaFtdcTradingRightType	TradingRight;
	///是否检查资金
	TRsaFtdcBoolType	CheckAccount;
	///是否检查持仓
	TRsaFtdcBoolType	CheckPosition;
	///报单是否报警
	TRsaFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TRsaFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TRsaFtdcDistributeTypeType	DistributeType;
	///跟随资金账户编号
	TRsaFtdcInvestorIDType	FollowParentInvestorID;
	///倍率
	TRsaFtdcRatioType	FollowRate;
};

///投资者资金通知
struct CRsaFtdcRtnInvestorAccountField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///上次结算准备金
	TRsaFtdcMoneyType	PreBalance;
	///上日可用资金
	TRsaFtdcMoneyType	PreAvailable;
	///入金金额
	TRsaFtdcMoneyType	Deposit;
	///出金金额
	TRsaFtdcMoneyType	Withdraw;
	///占用保证金
	TRsaFtdcMoneyType	Margin;
	///期权权利金收支
	TRsaFtdcMoneyType	Premium;
	///手续费
	TRsaFtdcMoneyType	Fee;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TRsaFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///可用资金
	TRsaFtdcMoneyType	Available;
	///结算准备金
	TRsaFtdcMoneyType	Balance;
	///多头占用保证金
	TRsaFtdcMoneyType	LongMargin;
	///空头占用保证金
	TRsaFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TRsaFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TRsaFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TRsaFtdcMoneyType	DynamicRights;
	///风险度
	TRsaFtdcRatioType	Risk;
	///其他费用
	TRsaFtdcMoneyType	OtherFee;
	///质押金额
	TRsaFtdcMoneyType	Mortgage;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///可取资金
	TRsaFtdcMoneyType	WithdrawQuota;
	///冻结的资金
	TRsaFtdcMoneyType	FrozenCash;
	///账户余额
	TRsaFtdcMoneyType	CurrentBalance;
	///总资产
	TRsaFtdcMoneyType	AssetBalance;
	///总市值
	TRsaFtdcMoneyType	MarketValue;
	///优先资金
	TRsaFtdcMoneyType	Prioprity;
	///现金资产
	TRsaFtdcMoneyType	FundAsset;
	///上海限购额度
	TRsaFtdcMoneyType	PurQuotaSh;
	///上海可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSh;
	///深圳限购额度
	TRsaFtdcMoneyType	PurQuotaSz;
	///深圳可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSz;
};

///投资者风控权限通知
struct CRsaFtdcRtnInvestorTradingRightRiskField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买开权限
	TRsaFtdcBoolType	BuyOpen;
	///买平权限
	TRsaFtdcBoolType	BuyClose;
	///卖开权限
	TRsaFtdcBoolType	SellOpen;
	///卖平权限
	TRsaFtdcBoolType	SellClose;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
};

///投资者权限通知
struct CRsaFtdcRtnInvestorTradingRightField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约交易权限
	TRsaFtdcTradingRightType	TradingRight;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
};

///交易汇率查询
struct CRsaFtdcQryExchangeRateField
{
	///币种
	TRsaFtdcCurrencyType	InstCurrency;
	///币种
	TRsaFtdcCurrencyType	AccCurrency;
};

///交易汇率
struct CRsaFtdcRspExchangeRateField
{
	///币种
	TRsaFtdcCurrencyType	InstCurrency;
	///币种
	TRsaFtdcCurrencyType	AccCurrency;
	///汇率
	TRsaFtdcRatioType	ExchangeRate;
};

///交易汇率通知
struct CRsaFtdcRtnExchangeRateField
{
	///币种
	TRsaFtdcCurrencyType	InstCurrency;
	///币种
	TRsaFtdcCurrencyType	AccCurrency;
	///汇率
	TRsaFtdcRatioType	ExchangeRate;
};

///新组合持仓明细查询请求
struct CRsaFtdcQryCombPositionDetailField
{
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///新组合持仓明细查询应答
struct CRsaFtdcRspCombPositionDetailField
{
	///交易日期
	TRsaFtdcTradingDayType	TradingDay;
	///开仓日期
	TRsaFtdcDateType	OpenDate;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///结算编号
	TRsaFtdcSettlementIDType	SettlementID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///组合编号
	TRsaFtdcTradeIDType	ComTradeID;
	///成交编号
	TRsaFtdcTradeIDType	TradeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///持仓量
	TRsaFtdcVolumeType	Position;
	///投资者保证金
	TRsaFtdcMoneyType	Margin;
	///交易所保证金
	TRsaFtdcMoneyType	ExchMargin;
	///保证金率
	TRsaFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TRsaFtdcMoneyType	MarginRateByVolume;
	///单腿编号
	TRsaFtdcLegIDType	LegID;
	///单腿乘数
	TRsaFtdcLegMultipleType	LegMultiple;
	///组合持仓合约代码
	TRsaFtdcInstrumentIDType	CmbInstrumentID;
	///成交组号
	TRsaFtdcTradeGroupIDType	TradeGroupID;
};

///投资者持仓通知
struct CRsaFtdcRtnInvestorPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TRsaFtdcMoneyType	UsedMargin;
	///总持仓量
	TRsaFtdcVolumeType	Position;
	///总持仓成本
	TRsaFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TRsaFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TRsaFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TRsaFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TRsaFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TRsaFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TRsaFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TRsaFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TRsaFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TRsaFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///执行冻结持仓
	TRsaFtdcVolumeType	StrikeFrozenPosition;
	///放弃执行冻结持仓
	TRsaFtdcVolumeType	AbandonFrozenPosition;
	///成本价
	TRsaFtdcPriceType	CostPrice;
	///开仓成本
	TRsaFtdcMoneyType	OpenCost;
	///今持仓(包含冻结)
	TRsaFtdcVolumeType	TodayPosition;
	///今持仓冻结持仓
	TRsaFtdcVolumeType	TodayFrozenClosing;
	///总持仓量(小数)
	TRsaFtdcPointVolumeType	PositionP;
};

///期权自对冲查询
struct CRsaFtdcQryOptionSelfCloseField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///期权自对冲操作编号
	TRsaFtdcOrderSysIDType	OptionSelfCloseSysID;
	///开始时间
	TRsaFtdcTimeType	InsertTimeStart;
	///结束时间
	TRsaFtdcTimeType	InsertTimeEnd;
};

///锁定证券仓位查询
struct CRsaFtdcQryLockPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
};

///锁定证券仓位
struct CRsaFtdcLockPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///会员编号
	TRsaFtdcParticipantIDType	ParticipantID;
	///客户代码
	TRsaFtdcClientIDType	ClientID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///锁仓数量
	TRsaFtdcVolumeType	Volume;
	///冻结数量
	TRsaFtdcVolumeType	FrozenVolume;
	///今日锁定数量
	TRsaFtdcVolumeType	TodayVolume;
};

///投资者其他费率查询
struct CRsaFtdcQryInvestorOtherFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///费率类型
	TRsaFtdcFeeTypeType	FeeType;
};

///投资者其他费率
struct CRsaFtdcRspInvestorOtherFeeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TRsaFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TRsaFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TRsaFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TRsaFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TRsaFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TRsaFtdcRatioType	OTFeeAmt;
	///费率类型
	TRsaFtdcFeeTypeType	FeeType;
};

///用户对应的交易员查询请求
struct CRsaFtdcQryUserTraderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
};

///用户对应的交易员查询应答
struct CRsaFtdcRspUserTraderField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///父投资者编号
	TRsaFtdcInvestorIDType	ParentInvestorID;
	///是否默认
	TRsaFtdcBoolType	IsDefault;
};

///合约组
struct CRsaFtdcInstrumentGroupField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///合约组代码
	TRsaFtdcInstrumentGroupIDType	InstrumentGroupID;
};

///投资者组合保证金类型
struct CRsaFtdcInvestorMarginCombTypeField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约组代码
	TRsaFtdcInstrumentGroupIDType	InstrumentGroupID;
	///保证金组合类型
	TRsaFtdcMarginCombTypeType	MarginCombType;
};

///数据同步状态
struct CRsaFtdcDataSyncStatusField
{
	///系统名称
	TRsaFtdcSObjectType	SystemName;
	///数据同步状态
	TRsaFtdcDataSyncStatusType	DataSyncStatus;
};

///交易节查询请求
struct CRsaFtdcQrySessionInfoField
{
	///交易日
	TRsaFtdcDateType	TradingDay;
};

///交易节查询应答
struct CRsaFtdcRspSessionInfoField
{
	///交易节Json数据
	TRsaFtdcLongJsonDataType	SessionJsonData;
};

///插件交互数据
struct CRsaFtdcQscPluginDataField
{
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///插件字符串标识
	TRsaFtdcPluginIdType	PluginId;
	///指令类型
	TRsaFtdcPluginOrderTypeType	PluginOrderType;
	///指令编号
	TRsaFtdcFunctionIdType	FunctionId;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///会话编号
	TRsaFtdcSessionIDType	SessionID;
	///数据体
	TRsaFtdcJsonDataType	Data;
};

///插件服务创建请求
struct CRsaFtdcQscRegisterPluginServiceField
{
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcPluginIdType	PluginId;
	///服务json描述
	TRsaFtdcJsonDataType	ServiceDesc;
	///指令类型
	TRsaFtdcPluginOrderTypeType	PluginOrderType;
};

///插件服务查询请求
struct CRsaFtdcQryPluginServiceField
{
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcPluginIdType	PluginId;
	///插件状态
	TRsaFtdcPluginStatusTypeType	PluginStatusType;
};

///插件服务
struct CRsaFtdcPluginServiceField
{
	///插件状态
	TRsaFtdcPluginStatusTypeType	PluginStatusType;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcPluginIdType	PluginId;
	///服务json描述
	TRsaFtdcJsonDataType	ServiceDesc;
};

///插件任务查询请求
struct CRsaFtdcQryPluginTaskField
{
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///用户代码
	TRsaFtdcUserIDType	UserID;
};

///插件任务
struct CRsaFtdcPluginTaskField
{
	///插件字符串标识
	TRsaFtdcPluginIdType	PluginId;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///执行功能编号
	TRsaFtdcFunctionIdType	ActionId;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///插件指令类型
	TRsaFtdcPluginOrderTypeType	PluginOrderType;
	///插件运行状态
	TRsaFtdcPluginStatusType	PluginStatus;
	///最新提示
	TRsaFtdcMessageType	LastMsg;
	///数据体
	TRsaFtdcJsonDataType	Data;
};

///插件任务子状态查询请求
struct CRsaFtdcQryPluginTaskSubStatusField
{
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
};

///插件子任务状态
struct CRsaFtdcPluginTaskSubStatusField
{
	///插件字符串标识
	TRsaFtdcPluginIdType	PluginId;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///通知功能编号
	TRsaFtdcFunctionIdType	NotifyId;
	///数据关键字
	TRsaFtdcDataKeyType	DataKey;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///数据体
	TRsaFtdcJsonDataType	Data;
};

///持仓
struct CRsaFtdcInvestorPositionField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TRsaFtdcDirectionType	Direction;
	///投机套保标志
	TRsaFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TRsaFtdcMoneyType	UsedMargin;
	///总持仓量
	TRsaFtdcVolumeType	Position;
	///总持仓成本
	TRsaFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TRsaFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TRsaFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TRsaFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TRsaFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TRsaFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TRsaFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TRsaFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TRsaFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TRsaFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TRsaFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///执行冻结持仓
	TRsaFtdcVolumeType	StrikeFrozenPosition;
	///放弃执行冻结持仓
	TRsaFtdcVolumeType	AbandonFrozenPosition;
	///成本价
	TRsaFtdcPriceType	CostPrice;
	///开仓成本
	TRsaFtdcMoneyType	OpenCost;
	///今持仓(包含冻结)
	TRsaFtdcVolumeType	TodayPosition;
	///今持仓冻结持仓
	TRsaFtdcVolumeType	TodayFrozenClosing;
	///总持仓量(小数)
	TRsaFtdcPointVolumeType	PositionP;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///会员编号
	TRsaFtdcParticipantIDType	ParticipantID;
	///客户代码
	TRsaFtdcClientIDType	ClientID;
	///计算浮动盈亏最新价
	TRsaFtdcPriceType	LastPrice;
	///产品代码
	TRsaFtdcProductIDType	ProductID;
	///期权类型
	TRsaFtdcOptionsTypeType	OptionType;
	///行权价
	TRsaFtdcPriceType	StrikePrice;
	///期权对应的标的合约代码
	TRsaFtdcInstrumentIDType	OptionInstrumentID;
	///短线可平仓量
	TRsaFtdcVolumeType	ShortClose;
};

///资金
struct CRsaFtdcInvestorAccountField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///上次结算准备金
	TRsaFtdcMoneyType	PreBalance;
	///上日可用资金
	TRsaFtdcMoneyType	PreAvailable;
	///入金金额
	TRsaFtdcMoneyType	Deposit;
	///出金金额
	TRsaFtdcMoneyType	Withdraw;
	///占用保证金
	TRsaFtdcMoneyType	Margin;
	///期权权利金收支
	TRsaFtdcMoneyType	Premium;
	///手续费
	TRsaFtdcMoneyType	Fee;
	///冻结的保证金
	TRsaFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TRsaFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TRsaFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TRsaFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TRsaFtdcMoneyType	PositionProfit;
	///可用资金
	TRsaFtdcMoneyType	Available;
	///结算准备金
	TRsaFtdcMoneyType	Balance;
	///多头占用保证金
	TRsaFtdcMoneyType	LongMargin;
	///空头占用保证金
	TRsaFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TRsaFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TRsaFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TRsaFtdcMoneyType	DynamicRights;
	///风险度
	TRsaFtdcRatioType	Risk;
	///其他费用
	TRsaFtdcMoneyType	OtherFee;
	///质押金额
	TRsaFtdcMoneyType	Mortgage;
	///币种
	TRsaFtdcCurrencyType	Currency;
	///可取资金
	TRsaFtdcMoneyType	WithdrawQuota;
	///冻结的资金
	TRsaFtdcMoneyType	FrozenCash;
	///账户余额
	TRsaFtdcMoneyType	CurrentBalance;
	///总资产
	TRsaFtdcMoneyType	AssetBalance;
	///总市值
	TRsaFtdcMoneyType	MarketValue;
	///优先资金
	TRsaFtdcMoneyType	Prioprity;
	///现金资产
	TRsaFtdcMoneyType	FundAsset;
	///上海限购额度
	TRsaFtdcMoneyType	PurQuotaSh;
	///上海可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSh;
	///深圳限购额度
	TRsaFtdcMoneyType	PurQuotaSz;
	///深圳可用限购额度
	TRsaFtdcMoneyType	EnPurQuotaSz;
	///总冻结持仓
	TRsaFtdcVolumeType	TotalFrozenPos;
	///今日出入金
	TRsaFtdcMoneyType	TodayInOut;
	///当日释放保证金
	TRsaFtdcMoneyType	ReleaseMargin;
	///浮盈是否可用
	TRsaFtdcBoolType	IsProfitCanUse;
	///临时冻结资金
	TRsaFtdcMoneyType	ManualFrozen;
	///期权权利金收入
	TRsaFtdcMoneyType	PremiumIn;
	///期权权利金支出
	TRsaFtdcMoneyType	PremiumOut;
	///现货买入冻结资金
	TRsaFtdcMoneyType	SpotFrozen;
	///现货买入成交资金冻结
	TRsaFtdcMoneyType	SpotTradeFrozen;
	///现货卖出成交回笼资金
	TRsaFtdcMoneyType	SpotTradeRelease;
};

///系统状态通知
struct CRsaFtdcSystemStatusField
{
	///系统类型
	TRsaFtdcSysTypeType	SysType;
	///系统标识
	TRsaFtdcSysTagType	SysTag;
	///系统状态
	TRsaFtdcSysStatusType	SysStatus;
};

///插件任务最新状态信息
struct CRsaFtdcPluginTaskInfoField
{
	///插件字符串标识
	TRsaFtdcPluginIdType	PluginId;
	///qsc全局编号
	TRsaFtdcNumberType	QscId;
	///插件标识
	TRsaFtdcNumberType	PluginTaskId;
	///外部标识
	TRsaFtdcOthMarkIdType	OthMarkId;
	///插件运行状态
	TRsaFtdcPluginStatusType	PluginStatus;
	///最新提示
	TRsaFtdcMessageType	LastMsg;
	///数据体
	TRsaFtdcJsonDataType	Data;
};

///账户新股申购额度查询
struct CRsaFtdcQryInvestorAccountIPOField
{
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
};

///账户新股申购额度
struct CRsaFtdcInvestorAccountIPOField
{
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///资金帐号
	TRsaFtdcAccountIDType	AccountID;
	///产品编号
	TRsaFtdcCPBHType	CPBH;
	///股东代码
	TRsaFtdcGDDMType	GDDM;
	///主板申购额度
	TRsaFtdcZBSGEDType	ZBSGED;
	///科创板申购额度
	TRsaFtdcKCBSGEDType	KCBSGED;
};

///客户询价请求
struct CRsaFtdcClientReqQuoteField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///系统询价编号
	TRsaFtdcQuoteIDType	QuoteID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///询价请求时间
	TRsaFtdcTimeType	ReqTime;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
};

///客户询价请求应答
struct CRsaFtdcRspClientReqQuoteField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///系统询价编号
	TRsaFtdcQuoteIDType	QuoteID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///询价请求时间
	TRsaFtdcTimeType	ReqTime;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///库存
	TRsaFtdcVolumeType	Position;
};

///客户询价请求查询请求
struct CRsaFtdcReqQryClientReqQuoteField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///系统询价编号
	TRsaFtdcQuoteIDType	QuoteID;
};

///客户询价请求应答
struct CRsaFtdcRspQryClientReqQuoteField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///系统询价编号
	TRsaFtdcQuoteIDType	QuoteID;
	///用户本地报单号
	TRsaFtdcUserOrderLocalIDType	UserOrderLocalID;
	///询价请求时间
	TRsaFtdcTimeType	ReqTime;
	///用户自定义域
	TRsaFtdcCustomType	UserCustom;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///库存
	TRsaFtdcVolumeType	Position;
	///询价应答时间
	TRsaFtdcTimeType	RspTime;
	///客户询价状态
	TRsaFtdcClientReqQuoteStatusType	ClientReqQuoteStatus;
	///错误代码
	TRsaFtdcErrorIDType	ErrorID;
	///错误信息
	TRsaFtdcErrorMsgType	ErrorMsg;
};

///发送通用消息请求
struct CRsaFtdcComMessageField
{
	///用户代码
	TRsaFtdcUserIDType	UserID;
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///消息类型
	TRsaFtdcMessageTypeType	MessageType;
	///信息内容
	TRsaFtdcMessageType	MessageContent;
};

///共享内存登录消息
struct CRsaFtdcReqShmLoginField
{
	///交易用户代码
	TRsaFtdcUserIDType	UserID;
	///经纪公司编号
	TRsaFtdcBrokerIDType	BrokerID;
	///密码
	TRsaFtdcPasswordType	Password;
};

///切日通知
struct CRsaFtdcUpdTradingDayField
{
	///当前交易日（切日前）
	TRsaFtdcTradingDayType	CurrentTradingDay;
	///下一交易日（切日后）
	TRsaFtdcTradingDayType	NextTradingDay;
	///更新时间
	TRsaFtdcTimeType	UpdTime;
	///是否为交易日结束
	TRsaFtdcBoolType	IsTradingDayEnd;
};

///行情推送结束通知
struct CRsaFtdcNtfMarketDataEndField
{
	///行情开始时间
	TRsaFtdcTradingDayType	StartTradingDay;
	///行情结束时间
	TRsaFtdcTradingDayType	EndTradingDay;
	///时间
	TRsaFtdcTimeType	Time;
};

///回测行情订阅
struct CRsaFtdcBtSubMarketDataField
{
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///Bar精度
	TRsaFtdcBarPrecesType	BarPreces;
	///Bar周期
	TRsaFtdcNumberType	BarPeriod;
};

///主力合约信息查询请求
struct CRsaFtdcQryHotInstrumentField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///基础品种代码
	TRsaFtdcInstrumentIDType	UnderlyingID;
};

///主力合约信息查询应答
struct CRsaFtdcRspHotInstrumentField
{
	///交易日
	TRsaFtdcTradingDayType	TradingDay;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///基础品种代码
	TRsaFtdcInstrumentIDType	UnderlyingID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///产品类型
	TRsaFtdcProductClassType	ProductClass;
	///成交量
	TRsaFtdcVolumeType	Volume;
	///品种最大成交量
	TRsaFtdcVolumeType	MaxVolume;
	///成交金额
	TRsaFtdcMoneyType	Turnover;
	///品种最大成交金额
	TRsaFtdcMoneyType	MaxTurnover;
	///持仓量
	TRsaFtdcLargeVolumeType	OpenInterest;
	///品种最大持仓量
	TRsaFtdcLargeVolumeType	MaxOpenInterest;
	///主力合约等级
	TRsaFtdcVolumeType	Rank;
};

///Cta委托
struct CRsaFtdcCtaOrderField
{
	///投资者编号
	TRsaFtdcInvestorIDType	InvestorID;
	///交易所代码
	TRsaFtdcExchangeIDType	ExchangeID;
	///合约代码
	TRsaFtdcInstrumentIDType	InstrumentID;
	///数量
	TRsaFtdcVolumeType	Volume;
	///报单类型
	TRsaFtdcOrderPriceTypeType	OrderPriceType;
	///开平方式
	TRsaFtdcOpenCloseMethodType	OpenCloseMethod;
	///价格
	TRsaFtdcPriceType	LimitPrice;
	///业务单元
	TRsaFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TRsaFtdcBusinessTypeType	BusinessType;
	///策略限制价格
	TRsaFtdcPriceType	AlgoLimitPrice;
	///策略限制tick数量
	TRsaFtdcNumberType	AlgoLimitPriceTick;
	///策略限制时间(ms)
	TRsaFtdcNumberType	AlgoLimitTime;
};

///订阅组合行情
struct CRsaFtdcSubCombMarketDataField
{
	///组合合约代码
	TRsaFtdcInstrumentIDType	CombInstID;
	///公式
	TRsaFtdcFormulaType	Formula;
	///小数点位数
	TRsaFtdcVolumeType	Precision;
	///腿数
	TRsaFtdcVolumeType	LegNum;
	///Leg1交易所代码
	TRsaFtdcExchangeIDType	Leg1ExchangeID;
	///Leg1合约代码
	TRsaFtdcInstrumentIDType	Leg1InstrumentID;
	///Leg1买卖方向
	TRsaFtdcDirectionType	Leg1Direction;
	///Leg2易所代码
	TRsaFtdcExchangeIDType	Leg2ExchangeID;
	///Leg2合约代码
	TRsaFtdcInstrumentIDType	Leg2InstrumentID;
	///Leg2买卖方向
	TRsaFtdcDirectionType	Leg2Direction;
	///Leg3交易所代码
	TRsaFtdcExchangeIDType	Leg3ExchangeID;
	///Leg3合约代码
	TRsaFtdcInstrumentIDType	Leg3InstrumentID;
	///Leg3买卖方向
	TRsaFtdcDirectionType	Leg3Direction;
	///Leg4交易所代码
	TRsaFtdcExchangeIDType	Leg4ExchangeID;
	///Leg4合约代码
	TRsaFtdcInstrumentIDType	Leg4InstrumentID;
	///Leg4买卖方向
	TRsaFtdcDirectionType	Leg4Direction;
	///Leg5交易所代码
	TRsaFtdcExchangeIDType	Leg5ExchangeID;
	///Leg5合约代码
	TRsaFtdcInstrumentIDType	Leg5InstrumentID;
	///Leg5买卖方向
	TRsaFtdcDirectionType	Leg5Direction;
	///Leg6交易所代码
	TRsaFtdcExchangeIDType	Leg6ExchangeID;
	///Leg6合约代码
	TRsaFtdcInstrumentIDType	Leg6InstrumentID;
	///Leg6买卖方向
	TRsaFtdcDirectionType	Leg6Direction;
	///Bar精度
	TRsaFtdcBarPrecesType	BarPreces;
	///Bar周期
	TRsaFtdcNumberType	BarPeriod;
};

///流水状态
struct CRsaFtdcFlowStatusField
{
	///序列系列号
	TRsaFtdcSequenceSeriesType	SequenceSeries;
	///是否就绪
	TRsaFtdcBoolType	bReady;
};

///行情订阅完成请求
struct CRsaFtdcReqSubMarketDataCompletedField
{
	///当前时间
	TRsaFtdcInt64Type	CurrTime;
};



#endif
