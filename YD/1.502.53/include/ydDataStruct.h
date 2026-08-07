#ifndef YD_DATA_STRUCT_H
#define YD_DATA_STRUCT_H

#include "ydDataType.h"
#include <math.h>
#include <float.h>

/// Data structs for YDApi

class YDSystemParam
{
public:
	YDString Name;
	YDString Target;
	YDString Value;
};

class YDCurrencyInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int CurrencyRef;
	int SystemUse5;
	double Rate;
	char CurrencyCode[8];
};

class YDExtraInstrumentAttrDef
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int EIAID;
	int SystemUse5;
	char EIACode[8];
	char EIADesc[32];
};

class YDExchangeConnectionInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int ExchangeRef;
	int ConnectionID;
	int ConnectionStatus;
	char Info[28];
	char InsertFlowControl[32];
	char CancelFlowControl[32];
	int MaxOnRouteRequests;
	int SystemUse5;
};

class YDExternalTradeFlowInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int ExchangeRef;
	int GroupID;
	int TradeFlowConnectionStatus;
	int ExchangeConnectionStatus;
	char Info[32];
};

class YDExchange
{
public:
	YDExchangeID ExchangeID;		    // Short string identifies the exchange, e.g. "CFFEX", "DCE", "SHFE", ...
	int ExchangeRef;                    // An integer uniquely identifies the exchange
	int ConnectionCount;                // Number of connections(seats) to the exchange
	int ProductRefStart;
	int ProductRefEnd;
	bool UseTodayPosition;              // Whether today and previous positions are traded separately. True for SHFE and INE
	bool UseArbitragePosition;          // Besides speculation and hedge, whether the exchange maintains separate position for arbitrage. True for CFFEX 
	bool CloseTodayFirst;               // When "UseTodayPosition" is false, whether today opened positions are closed first. The commission may be different. True for CFFEX
	bool SingleSideMargin;              // Whether margin is calculated using larger side of the product or product group. True for SHFE, INE, and CFFEX
	int OptionExecutionSupport;         // 0 for not supported, 1 for supported without risk control, 2 for supported with risk control
	int OptionAbandonExecutionSupport;  // 0 for not supported, 1 for supported without risk control, 2 for supported with risk control
	int QuoteVolumeRestriction;         // 0 for allow single side, 1 for allow different volume, 2 for require same volume
	unsigned short ExchangeFlag;		// see constants start with YD_EF_
	bool IsOffline;
	bool TradeStockOptions;	            // whether this exchange is trading stock/etf options(SSE/SZSE)
	long long GlobalExchangeFlag;       // see constants start with YD_GEF_
	int ExternalTradeFlowCount;
	int SystemUse3[5];
	bool IsPublicConnectionID[64];      // Whether this connectionID can be used by every user
	YDExchangeConnectionInfo *ConnectionInfos;	// points to an array of YDExchangeConnectionInfo, array size is ConnectionCount
	YDExternalTradeFlowInfo *ExternalTradeFlowInfos;	// points to an array of YDExternalTradeFlowInfo, array size is ExternalTradeFlowCount
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
};

class YDTradeConstraint
{
public:
	int OpenLimit;
	int CancelLimit;
	int PositionLimit;
	int TradeVolumeLimit;
	int DirectionOpenLimit[2];
	int DirectionPositionLimit[2];
};

class YDProduct
{
public:
	YDProductID ProductID;              // Short string identifies the product, e.g. "cu", "IC", "cu_o", ...
	int ProductRef;
	int ExchangeRef;
	int ProductClass;                   // Refer to "Product Class" section of ydDataType.h
	int Multiple;                       // Contract size
	double Tick;                        // Minimum amount for price change
	double UnderlyingMultiply;          // Volume of corresponding underlying instrument. Used for options, normally equals to 1
	int MaxMarketOrderVolume;
	int MinMarketOrderVolume;
	int MaxLimitOrderVolume;
	int MinLimitOrderVolume;
	int InstrumentRefStart;
	int InstrumentRefEnd;
	int SystemUse7[24];
	int SubProductClass;                // Refer to "Sub Product Class" section of ydDataType.h
	int ProductFlag;                    // Refer to "Product Flag" section of ydDataType.h
	int CancelCountOrderTypes;
	int CurrencyRef;
	int ProductDayStart;
	int ProductDay1;
	int ProductDay2;
	int CancelCountEOAsForMarketOrder;
	YDProductID ProductHint;
	const YDProduct *m_pMarginProduct;  // Points to the product that represents the product group, when single side margin is used
	const YDExchange *m_pExchange;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
	double ExchangeRate;
};

class YDInstrument;

class YDMarketData
{
public:
	int InstrumentRef;
	int TradingDay;
	double PreSettlementPrice;
	double PreClosePrice;
	double PreOpenInterest;
	double UpperLimitPrice;
	double LowerLimitPrice;
	double LastPrice;
	double BidPrice;
	double AskPrice;
	int BidVolume;
	int AskVolume;
	double Turnover;
	double OpenInterest;
	unsigned Volume;
	int TimeStamp;
	double AveragePrice;
	double DynamicBasePrice;
	int LastTradeTimeStamp;
	int MarketDataFlag;                    // Refer to "Market Data Flag" section of ydDataType.h
	const YDInstrument *m_pInstrument;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
};

class YDMarginRate;
class YDCombPositionDef;
class YDPCF;

class YDInstrument
{
public:
	YDInstrumentID InstrumentID;        // Short string identifies the instrument, e.g. "cu2101", "IC2212", "c2103-C-2620", ...
	int InstrumentRef;                  // An integer uniquely identifies the instrument
	int ProductRef;
	int ExchangeRef;
	int ProductClass;                   // Refer to "Product Class" section of ydDataType.h
	int DeliveryYear;
	int DeliveryMonth;
	int MaxMarketOrderVolume;
	int MinMarketOrderVolume;
	int MaxLimitOrderVolume;
	int MinLimitOrderVolume;
	double Tick;                        // Minimum amount for price change
	int Multiple;                       // Contract size
	int ExpireDate;
	double StrikePrice;
	int UnderlyingInstrumentRef;
	int OptionsType;                    // Refer to "Options Type" section of ydDataType.h
	double UnderlyingMultiply;          // Volume of corresponding underlying instrument. Used for options, normally equals to 1
	int SystemUse7[24];
	int SubProductClass;                // Refer to "Sub Product Class" section of ydDataType.h
	int CashInstrumentFlag;             // Refer to "Cash Instrument Flag" section of ydDataType.h
	int TradeControlFlag;				// Refer to "Trade Control Flag" section of ydDataType.h
	int QtyUnit;
	double Interest;
	int SystemUse8[2];
	bool SingleSideMargin;              // Whether margin is calculated using larger side of the product or product group. True for futures of SHFE, INE, and CFFEX
	bool InstrumentSingleSideMargin;    // Whether margin is calculated using larger side of instrument. True for futures of CZCE
	short ExpireTradingDayCount;
	int MarginCalcMethod;               // Option margin calculation method, 1 for CFFEX index, 2 for SSE & SZSE, 3 for CFFEX bond, 0 for others 
	YDInstrumentID InstrumentHint;      // Hint of this instrument, useful for options of SSE/SZSE, e.g. "510050C2009M02350"
	unsigned char EIAIDs[32];
	const YDInstrument *m_pUnderlyingInstrument;  // Points to underlying instrument, only valid for options & convertible bonds
	const YDExchange *m_pExchange;
	const YDProduct *m_pProduct;
	const YDMarketData *m_pMarketData;
	const YDInstrument *m_pLegInstrument[2];
	union
	{
		char LegDirection[2];
		char LegDirction[2];		// for compatibility
	};
	short SystemUse9;
	const YDCombPositionDef *m_pCombPositionDef[2][YD_MaxHedgeFlag];

	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
	int InternalUseInt1;
	int InternalUseInt2;
	const YDPCF *m_pPCF;
	bool AutoSubscribed;
	bool UserSubscribed;
	/// The following fields are only valid when using ydExtendedApi
	bool IsStaticMargin;
	int MarginBasePriceType;
	int OrderPremiumBasePriceType[2];
	int OrderMarginBasePriceType;
	int MarginBasePriceAsUnderlyingType;
	double MarginBasePrice;
	const YDMarginRate *m_pExchangeMarginRate[YD_MaxHedgeFlag];

	inline double getPreSettlementPrice(void) const
	{
		return m_pMarketData->PreSettlementPrice;
	}
	inline double getPreClosePrice(void) const
	{
		return m_pMarketData->PreClosePrice;
	}
	inline double getPreOpenInterest(void) const
	{
		return m_pMarketData->PreOpenInterest;
	}
	inline double getUpperLimitPrice(void) const
	{
		return m_pMarketData->UpperLimitPrice;
	}
	inline double getLowerLimitPrice(void) const
	{
		return m_pMarketData->LowerLimitPrice;
	}
	inline double getLastPrice(void) const
	{
		return m_pMarketData->LastPrice;
	}
	inline double getBidPrice(void) const
	{
		return m_pMarketData->BidPrice;
	}
	inline double getAskPrice(void) const
	{
		return m_pMarketData->AskPrice;
	}
	inline int getBidVolume(void) const
	{
		return m_pMarketData->BidVolume;
	}
	inline int getAskVolume(void) const
	{
		return m_pMarketData->AskVolume;
	}
	inline double getTurnover(void) const
	{
		return m_pMarketData->Turnover;
	}
	inline double getOpenInterest(void) const
	{
		return m_pMarketData->OpenInterest;
	}
	inline int getVolume(void) const
	{
		return m_pMarketData->Volume;
	}
	inline double getAveragePrice(void) const
	{
		return m_pMarketData->AveragePrice;
	}
	inline double getMaxLastPreSettlementPrice(void) const
	{
		if ((m_pMarketData->Volume>0) && isfinite(m_pMarketData->LastPrice) && (m_pMarketData->LastPrice!=DBL_MAX) && (m_pMarketData->LastPrice>m_pMarketData->PreSettlementPrice))
		{
			return m_pMarketData->LastPrice;
		}
		else
		{
			return m_pMarketData->PreSettlementPrice;
		}
	}
	inline bool isEIASet(int EIAID) const
	{
		return EIAIDs[EIAID/8]&(1<<EIAID%8);
	}
};

class YDCombPositionDef
{
public:
	char SystemUse1[32];
	int CombPositionRef;
	int ExchangeRef;
	int Priority;
	short CombHedgeFlag;
	short CombPositionType;
	double Parameter;
	YDLongInstrumentID CombPositionID;
	const YDExchange *m_pExchange;
	const YDInstrument *m_pInstrument[2];
	int LegMultiple[2];
	int PositionDirection[2];
	int HedgeFlag[2];
	int PositionDate[2];
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
};

class YDPCF
{
public:
	int SystemUse[4];
	int InstrumentRef;
	int Operation;
	int Unit;
	int CreationRedemptionMechanism;
	double MaxCashRatio;
	double EstimateCashComponent;
	double NAVperCU;
	double NAV;
	double DividendPerCU;
	int PCFComponentRefStart;
	int PCFComponentRefEnd;
	long long CreationLimitPerUser;
	long long RedemptionLimitPerUser;
	long long NetCreationLimitPerUser;
	long long NetRedemptionLimitPerUser;
	double SubstitutionCashAmount;
};

class YDPCFComponent
{
public:
	int SystemUse1[4];
	int PCFComponentRef;
	int ETFInstrumentRef;
	int InstrumentRef;
	int ComponentShare;
	double PremiumRatio;
	int SubstituteFlag;
	int SystemUse2;
};

class YDAccount
{
public:
	int SystemUse1;
	int AccountRef;
	char SystemUse0[16];
	double PreBalance;
	double WarningLevel1;
	double WarningLevel2;
	YDAccountID AccountID;              // User account name in broker
	double MaxMoneyUsage;               // Rate of fund that can be used for trading, should be less than 1
	double Deposit;
	double Withdraw;
	double FrozenWithdraw;
	int TradingRight;
	int MaxOrderCount;                  // Maximum number of orders that can be placed, read only
	int MaxLoginCount;                  // Maximum number of active logins allowed, read only
	int LoginCount;                     // Number of active logins, read only
	int AccountFlag;                    // Bitmap, refer to "Account Flag" section of ydDataType.h
	int SystemUse3;
	char TradingRightFromSource[YD_TRS_Count];
	int MaxCancelCount;                 // Maximum number of cancel order requests, read only
	short MaxRequestSpeed;
	unsigned short MinRiskRateValue;
	unsigned char TempAccountStatus;    // Bitmap, refer to "Temp Account Status" section of ydDataType.h
	char DefaultLoginRight;				// Refer to "Login Right" section of ydDataType.h
	short SystemUse6;
	int DisconnectedCount;
	int FailedLoginCount;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;

	double MinRiskRate(void) const
	{
		return MinRiskRateValue/10000.0;
	}
};

class YDPrePosition
{
public:
	int SystemUse1;
	int AccountRef;
	int InstrumentRef;
	int PositionDirection;
	int HedgeFlag;
	int PrePosition;
	double PreSettlementPrice;
	double AverageOpenPrice;
	const YDInstrument *m_pInstrument;
	const YDAccount *m_pAccount;
};

class YDPreHolding
{
public:
	int SystemUse1;
	int AccountRef;
	int InstrumentRef;
	int PreHolding;
	double AverageOpenPrice;
	const YDInstrument *m_pInstrument;
	const YDAccount *m_pAccount;
};

class YDRepoHolding
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int InstrumentRef;
	int TradingDay;
	YDLongTradeID TradeID;
	char Direction;
	char Padding1;
	short Padding2;
	int Volume;
	double Price;
};

class YDSpotPrePosition
{
public:
	int SystemUse1;
	int AccountRef;
	int InstrumentRef;
	int Position;
	int ExchangeFrozenVolume;
	int ExecAllocatedVolume;
	double ExecAllocatedAmount;
	int ExecAllocatedFrozenVolume;
	int SystemUse2;
	double ExecAllocatedFrozenAmount;
	const YDInstrument *m_pInstrument;
	const YDAccount *m_pAccount;
};

class YDCombPosition
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int CombPositionRef;
	int Position;
	int CombPositionDetailID;
	int SystemUse6;
};

class YDInputOrder
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int SystemUse5;
	char Direction;                     // Refer to "Direction" section of ydDataType.h
	char OffsetFlag;                    // Refer to "Offset Flag" section of ydDataType.h
	char HedgeFlag;                     // Refer to "Hedge Flag" section of ydDataType.h
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	union
	{
		double Price;                   // Price for limit orders
		struct
		{
			int CombPositionDetailID;   // Set only when YDOrderFlag is YD_YOF_CombPosition, and Direction is YD_D_Split for SSE Option or SZSE Option
			int SystemUse6;
		};
		char TransfereePBUID[8];		// Set only when YDOrderFlag is YD_YOF_Designation for SZSE Cash
	};
	int OrderVolume;
	int OrderRef;                       // User-defined reference of the order. Will be passed back in subsequent order and trade notifications 
	char OrderType;                     // Refer to "Order Type" section of ydDataType.h
	char YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char SystemUse10;
	int ErrorNo;                        // Set by ydAPI, refer to "ydError.h"
	unsigned char OrderGroupID;         // Indicates OrderRef management group, 0 for normal, 1-255 for strict management
	char GroupOrderRefControl;          // OrderRef control method for this order if OrderGroupID is in [1,255], refer to "Order group ref control" section of ydDataType.h
	char OrderTriggerType;              // Refer to "Order trigger type" section of ydDataType.h
	char ExchangeOrderAttribute;        // Refer to "Exchange Order Attribute" section of ydDataType.h
	int UserRef;
	long long SystemUse9;
	double TriggerPrice;                // Trigger price for trigger order
};

/*
Here are field requirements in YDInputOrder for different YDOrderFlag (please set all unused fields to 0)
	Common fields
		pInstrument in insertOrder(): points to YDInstrument, unless using YD_YOF_CombPosition
		pAccount in insertOrder(): points to YDAccount, can ignore or use NULL for traders
		HedgeFlag: hedge flag, must be specified, even if it is meaningless in this kind of order
		OrderRef: user set reference of order, please use positive number, 0 is reserved for YDClient, will be set by system if using checkAndInsertOrder
		ConnectionSelectionType: specify how to select exchange connection
		ConnectionID: if (ConnectionSelectionType==YD_CS_Fixed) || (ConnectionSelectionType==YD_CS_Preferred), specify connectionID,
			must be in IsPublicConnectionID set of YDExchange or IsDedicatedConnectionID set of YDAccountExchange
		ErrorNo: will be set in return message
	YDOrderFlag==YD_YOF_Normal
		Direction: direction, YD_D_Buy or YD_D_Sell
		OffsetFlag: offset flag, YD_OF_Open, YD_OF_Close, YD_OF_CloseToday or YD_OF_CloseYesterday (YD_OF_CloseToday and YD_OF_CloseYesterday are only for SHFE/INE),
			YD_OF_ForceClose can only be used by admin user
		OrderType: order type, YD_ODT_Limit, YD_ODT_FAK, YD_ODT_Market or YD_ODT_FOK
		OrderVolume: order volume
		Price: limit price, useless if OrderType==YD_ODT_Market
		Special Notes:
			if trading on Repo instruments, OrderVolume uses unit of CNY 100
	YDOrderFlag==YD_YOF_OptionExecute
		Direction: useless, will be set to YD_D_Sell by system
		OffsetFlag: specify which position to execute, YD_OF_Close,YD_OF_CloseToday or YD_OF_CloseYesterday (YD_OF_CloseToday and YD_OF_CloseYesterday are only for SHFE/INE)
		OrderType: useless, will be set to YD_ODT_Limit
		for most instruments
			OrderVolume: execute volume
			Price: useless
		for exec using minimal profit (GFEX commodity index option)
			OrderVolume: useless, will be set to 0 by system
			Price: minimal profit
	YDOrderFlag==YD_YOF_OptionAbandonExecute
		Direction: useless, will be set to YD_D_Sell by system
		OffsetFlag: specify which position to abandon execution, YD_OF_Close,YD_OF_CloseToday or YD_OF_CloseYesterday (YD_OF_CloseToday and YD_OF_CloseYesterday are only for SHFE/INE)
		OrderType: useless, will be set to YD_ODT_Limit
		OrderVolume: execute volume
		Price: useless
	YDOrderFlag==YD_YOF_RequestForQuote
		OrderVolume,Direction,OffsetFlag,OrderType,Price: useless
		HedgeFlag: meaningless
		this kind of order has no notification
	YDOrderFlag==YD_YOF_CombPosition
		use insertCombPositionOrder() instead of insertOrder()
		pCombPositionDef: pointer to combine position definition
		Direction: action direction, YD_D_Make or YD_D_Split
		OrderVolume: volume
		CombPositionDetailID: combine position detail ID, only use when Direction==YD_D_Split, and trade on stock exchanges
		OffsetFlag: useless for trader, admin user can use YD_OF_ForceClose to indicate forced split
		OrderType: useless
		HedgeFlag:  meaningless
	YDOrderFlag==YD_YOF_OptionExecuteTogether
		use insertOptionExecTogetherOrder() instead of insertOrder()
		pInstrument2: points to YDInstrument
		OrderVolume: volume
		Direction,OffsetFlag,OrderType: useless
	YDOrderFlag==YD_YOF_Mark
		Direction: action direction, YD_D_Buy for set, YD_D_Sell for cancel
		OrderType: YD_ODT_PositionOffsetMark, YD_ODT_OptionAbandonExecuteMark, YD_ODT_CloseFuturesPositionMark or all YD_ODT_DCE...
		OrderVolume: useless for most of time, except for some OrderType when Direction==YD_D_Buy
		OffsetFlag,Price: useless
		HedgeFlag: meaningless
		Special Note: meanings of pInstrument are different for different OrderTypes, as listed below
			YD_ODT_PositionOffsetMark: target option instrument
			YD_ODT_OptionAbandonExecuteMark: target option instrument
			YD_ODT_CloseFuturesPositionMark: any instrument in target exchange
			YD_ODT_DCEOptOffsetForInstrument:  target option instrument, OrderVolume is useful
			YD_ODT_DCEOptOffsetForOptionSeries: any option instrument in target option series
			YD_ODT_DCEOptOffsetForProduct: any option instrument in target option product
			YD_ODT_DCEExecOffsetForOptionSeries: any option instrument in target option series
			YD_ODT_DCEExecOffsetForProduct: any option instrument in target option product
			YD_ODT_DCEExecOffsetForExchange: any instrument in target exchange
			YD_ODT_DCEPerformOffsetForOptionSeries: any option instrument in target option series
			YD_ODT_DCEPerformOffsetForProduct: any option instrument in target option product
			YD_ODT_DCEPerformOffsetForExchange: any instrument in target exchange
			YD_ODT_DCEFtrOffsetForInstrument: target futures instrument, OrderVolume is useful
			YD_ODT_DCEFtrOffsetForProduct: any futures instrument in target futures product
			YD_ODT_DCEFtrOffsetForExchange: any instrument in target exchange
	YDOrderFlag==YD_YOF_OptionSelfClose
		OrderVolume: volume, can be 0
		OrderType: order type, YD_ODT_CloseSelfOptionPosition, YD_ODT_ReserveOptionPosition or YD_ODT_SellCloseSelfFuturesPosition
		Direction,OffsetFlag,Price: useless
		HedgeFlag: meaningless
	YDOrderFlag==YD_YOF_FreezeUnderlying
		Direction: action direction, YD_D_Freeze or YD_D_Unfreeze
		OrderVolume: volume
		OffsetFlag,OrderType,Price: useless
		HedgeFlag: meaningless
	YDOrderFlag==YD_YOF_Cover (this is not covered order, but conversion between normal and covered positions)
		Direction: action direction, YD_D_Normal2Covered or YD_D_Covered2Normal
		OrderVolume: volume
		OffsetFlag,OrderType,Price: useless
		HedgeFlag: meaningless
	YDOrderFlag==YD_YOF_Designation
		pInstrument is used to specify exchange
		TransfereePBUID: PBU ID of transferee
	YDOrderFlag==YD_YOF_TransDisposal
		Direction: direction, YD_D_TransDisposalTake or YD_D_TransDisposalReturn
		OrderVolume: volume
		OffsetFlag,OrderType,Price: useless
		HedgeFlag: meaningless
	YDOrderFlag==YD_YOF_ETFCreationRedemption
		Direction: direction, YD_D_Creation or YD_D_Redemption
		OffsetFlag: offset flag, YD_OF_Open or YD_OF_Close
		OrderVolume: volume of ETF
		OrderType,Price: useless

For covered order in SSE option/SZSE option, use YDOrderFlag=YD_YOF_Normal and HedgeFlag=YD_HF_Covered
*/

class YDOrder
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int SystemUse5;
	char Direction;                     // Refer to "Direction" section of ydDataType.h
	char OffsetFlag;                    // Refer to "Offset Flag" section of ydDataType.h
	char HedgeFlag;                     // Refer to "Hedge Flag" section of ydDataType.h
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	union
	{
		double Price;                   // Price for limit orders
		struct
		{
			int CombPositionDetailID;   // Useful for SSE or SZSE when YDOrderFlag is YD_YOF_CombPosition
			int SystemUse6;
		};
		char TransfereePBUID[8];
	};
	int OrderVolume;
	int OrderRef;                       // User defined reference of the order
	char OrderType;                     // Refer to "Order Type" section of ydDataType.h
	char YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char RealConnectionID;              // Real connection ID for this order, <0 if from connections of other systems
	int ErrorNo;                        // Set by ydAPI, refer to "ydError.h"
	int ExchangeRef;
	union
	{
		YDSysOrderID OrderSysID;
		int MaxOrderRef;                // When ErrorNo==YD_ERROR_InvalidGroupOrderRef
	};
	int OrderStatus;                    // Refer to "Order Status" section of ydDataType.h
	int TradeVolume;
	int InsertTime;
	YDLocalOrderID OrderLocalID;
	unsigned char OrderGroupID;         // Indicates OrderRef management group, 0 for normal, 1-255 for strict management
	char GroupOrderRefControl;          // OrderRef control method for this order if OrderGroupID is in [1,255], refer to "Order group ref control" section of ydDataType.h
	char OrderTriggerType;              // Refer to "Order trigger type" section of ydDataType.h
	char ExchangeOrderAttribute;        // Refer to "Exchange Order Attribute" section of ydDataType.h
	int UserRef;
	long long SystemUse9;
	double TriggerPrice;                // Trigger price for trigger order
	int OrderTriggerStatus;             // Refer to "Order trigger status" section of ydDataType.h
	int InsertTimeStamp;
	YDLongOrderSysID LongOrderSysID;
	int CancelTimeStamp;
	int SessionID;
	int SystemUse10;
	int _guojun_securities_cash_sno;    // Only for cash trading in guojun securities
	int InsertActionDay;                // Real day, not trading day. May be 0 if exchange doesn't give
	int CancelActionDay;                // Real day, not trading day. May be 0 if exchange doesn't give
	long long InsertActionNSInDay;      // Nano second from 00:00:00
	long long CancelActionNSInDay;      // Nano second from 00:00:00
	int InsertProductDay;
	int CancelProductDay;
	int YDTimeStamp;
	int LoginOption;
};

typedef YDOrder YDMissingOrder;
// in YDMissingOrder, InsertTime is time in ydServer, not time in exchange

class YDCancelOrder
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	union
	{
		YDSysOrderID OrderSysID;
		int OrderRef;                   // When OrderGroupID!=0
	};
	char SystemUse5;
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	unsigned char OrderGroupID;         // If OrderGroupID!=0, use (OrderGroupID,OrderRef) to indicate an order
	char SystemUse6;
	short SystemUse7;
	int SystemUse8;
	YDLongOrderSysID LongOrderSysID;
};

class YDCancelOrderNotice
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	union
	{
		YDSysOrderID OrderSysID;
		int OrderRef;                   // When OrderGroupID!=0
	};
	char ExchangeRef;
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	unsigned char OrderGroupID;         // If OrderGroupID!=0, use (OrderGroupID,OrderRef) to indicate an order
	char SystemUse6;
	short SystemUse7;
	int SystemUse8;
	YDLongOrderSysID LongOrderSysID;
	int SessionID;
	int SystemUse9;
	int SystemUse10;
	int _guojun_securities_cash_sno; // Only for cash trading in guojun securities
};

class YDFailedCancelOrder
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	YDSysOrderID OrderSysID;
	char ExchangeRef;
	unsigned char OrderGroupID;
	char SystemUse7;
	char YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	int ErrorNo;                        // Set by ydAPI, refer to "ydError.h"
	int IsQuote;
	int OrderRef;
	int YDTimeStamp;
	YDLongOrderSysID LongOrderSysID;
};

class YDTrade
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int InstrumentRef;
	char Direction;                     // Refer to "Direction" section of ydDataType.h
	char OffsetFlag;                    // Refer to "Offset Flag" section of ydDataType.h
	char HedgeFlag;                     // Refer to "Hedge Flag" section of ydDataType.h
	char SystemUse6;
	YDTradeID TradeID;
	YDSysOrderID OrderSysID;
	double Price;
	int Volume;
	int TradeTime;
	double Commission;
	YDLocalOrderID OrderLocalID;
	int OrderRef;                       // User defined reference of the order
	unsigned char OrderGroupID;         // Indicates OrderRef management group, 0 for normal, 1-255 for strict management
	char RealConnectionID;
	char YDTradeFlag;                   // Refer to "YD TradeFlag" section of ydDataType.h
	char NoOrderFlag;
	int TradeTimeStamp;
	YDLongOrderSysID LongOrderSysID;
	YDLongTradeID LongTradeID;
	int UserRef;
	int TradeActionDay;
	long long TradeActionNSInDay;
	int ProductDay;
	int SystemUse9;
};

class YDInputQuote
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int SystemUse5;
	char BidOffsetFlag;                 // Refer to "Offset Flag" section of ydDataType.h
	char BidHedgeFlag;                  // Refer to "Hedge Flag" section of ydDataType.h
	char AskOffsetFlag;                 // Refer to "Offset Flag" section of ydDataType.h
	char AskHedgeFlag;                  // Refer to "Hedge Flag" section of ydDataType.h
	double BidPrice;
	double AskPrice;
	int BidVolume;
	int AskVolume;
	int OrderRef;                       // User defined reference of the order. Will be passed back in subsequent order and trade notifications 
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char SystemUse7;
	char YDQuoteFlag;                   // Refer to "YD QuoteFlag" section of ydDataType.h, 
	unsigned char OrderGroupID;         // Indicates OrderRef management group, 0 for normal, 1-255 for strict management
	char GroupOrderRefControl;          // OrderRef control method for this order if OrderGroupID is in [1,255], refer to "Order group ref control" section of ydDataType.h
	char ExchangeQuoteAttribute;        // Refer to "Exchange Order Attribute" section of ydDataType.h
	char SystemUse6;
	int ErrorNo;                        // Set by ydAPI, refer to "ydError.h"
	int UserRef;
	int SystemUse8;
	long long SystemUse9;
	YDLongOrderSysID ReplaceLongQuoteSysID;
};

class YDQuote
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int SystemUse5;
	char BidOffsetFlag;                 // Refer to "Offset Flag" section of ydDataType.h
	char BidHedgeFlag;                  // Refer to "Hedge Flag" section of ydDataType.h
	char AskOffsetFlag;                 // Refer to "Offset Flag" section of ydDataType.h
	char AskHedgeFlag;                  // Refer to "Hedge Flag" section of ydDataType.h
	double BidPrice;
	double AskPrice;
	int BidVolume;
	int AskVolume;
	int OrderRef;                       // User defined reference of the order
	char ConnectionSelectionType;       // Refer to "Connection Selection Type" section of ydDataType.h
	char ConnectionID;                  // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	char RealConnectionID;              // Real connection ID for this quote, <0 if from connections of other systems
	char YDQuoteFlag;                   // Refer to "YD QuoteFlag" section of ydDataType.h, 
	unsigned char OrderGroupID;         // Indicates OrderRef management group, 0 for normal, 1-255 for strict management
	char GroupOrderRefControl;          // OrderRef control method for this order if OrderGroupID is in [1,255], refer to "Order group ref control" section of ydDataType.h
	char ExchangeQuoteAttribute;        // Refer to "Exchange Order Attribute" section of ydDataType.h
	char SystemUse6;
	int ErrorNo;                        // Set by ydAPI, refer to "ydError.h"
	int ExchangeRef;
	union
	{
		YDSysOrderID QuoteSysID;
		int MaxOrderRef;                // When ErrorNo==YD_ERROR_InvalidGroupOrderRef
	};
	YDSysOrderID BidOrderSysID;
	YDSysOrderID AskOrderSysID;
	YDRFQID RequestForQuoteID;
	int SessionID;
	YDLongOrderSysID LongQuoteSysID;
	YDLongOrderSysID LongBidOrderSysID;
	YDLongOrderSysID LongAskOrderSysID;
	YDLongRFQID LongRequestForQuoteID;
	int UserRef;
	int SystemUse8;
	long long SystemUse9;
	YDLongOrderSysID ReplaceLongQuoteSysID;
	int YDTimeStamp;
	int SystemUse10;
};

class YDCancelQuote
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	union
	{
		YDSysOrderID QuoteSysID;
		int OrderRef;                     // When OrderGroupID!=0
		int InstrumentRef;				  // Will be set when calling cancelQuoteByInstrument
	};
	char SystemUse5;
	char ConnectionSelectionType;         // Refer to "Connection Selection Type" section of ydDataType.h
	char ConnectionID;                    // Target connection ID if ConnectionSelectionType is not YD_CS_Any
	unsigned char OrderGroupID;           // If OrderGroupID>0, use (OrderGroupID,OrderRef) to indicate a quote
	YDLongOrderSysID LongQuoteSysID;
	char CancelQuoteByInstrumentType;     // Will be set when calling cancelQuoteByInstrument, refer to "Cancel Quote By Instrument Types" section of ydDataType.h
	char SystemUse6;
	short SystemUse7;
	int SystemUse8;
};

class YDFailedCancelQuote
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	union
	{
		YDSysOrderID QuoteSysID;
		int InstrumentRef;
	};
	char ExchangeRef;
	unsigned char OrderGroupID;
	char CancelQuoteByInstrumentType;  // Refer to "Cancel Quote By Instrument Types" section of ydDataType.h
	char SystemUse8;
	int ErrorNo;                       // Set by ydAPI, refer to "ydError.h"
	int IsQuote;
	int OrderRef;
	int YDTimeStamp;
	YDLongOrderSysID LongQuoteSysID;
};

class YDRequestForQuote
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int InstrumentRef;
	int RequestTime;
	YDRFQID RequestForQuoteID;
	int SystemUse6;
	YDLongRFQID LongRequestForQuoteID;
};

class YDMarginRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int HedgeFlag;                     // Refer to "Hedge Flag" section of ydDataType.h
	int SystemUse5;
	union 
	{
		double LongMarginRatioByMoney;
		double PutMarginRatioByMoney;
	};
	union
	{
		double LongMarginRatioByVolume;
		double PutMarginRatioByVolume;
		double BaseMarginRate;
	};
	union
	{
		double ShortMarginRatioByMoney;
		double CallMarginRatioByMoney;
		double LinearFactor;
	};
	union
	{
		double ShortMarginRatioByVolume;
		double CallMarginRatioByVolume;
		double LowerBoundaryCoef;
	};

	const YDInstrument *m_pInstrument;
	const YDProduct *m_pProduct;
	const YDAccount *m_pAccount;
};

class YDCommissionRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int HedgeFlag;                     // Refer to "Hedge Flag" section of ydDataType.h
	int SystemUse5;
	double OpenRatioByMoney;
	double OpenRatioByVolume;
	double CloseRatioByMoney;
	double CloseRatioByVolume;
	double CloseTodayRatioByMoney;
	double CloseTodayRatioByVolume;
	double OrderCommByVolume;
	double OrderActionCommByVolume;
	double ExecRatioByMoney;
	double ExecRatioByVolume;
	const YDInstrument *m_pInstrument;
	const YDProduct *m_pProduct;
	const YDAccount *m_pAccount;
};

class YDCashCommissionRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SubProductClass;               // Refer to "Sub Product Class" section of ydDataType.h
	int SystemUse3;
	int SystemUse4;
	int SystemUse5;
	int YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	int Direction;
	YDCashCommissionRatePiece RatePiece[YD_CCT_Count];
	const YDInstrument *m_pInstrument;
	const YDProduct *m_pProduct;
	const YDExchange *m_pExchange;
	const YDAccount *m_pAccount;
};

class YDBrokerageFeeRate
{
public:
	int SystemUse1;
	int AccountRef;
	int SubProductClass;               // Refer to "Sub Product Class" section of ydDataType.h
	int ExchangeRef;
	int ProductRef;
	int InstrumentRef;
	int YDOrderFlag;                   // Refer to "YD OrderFlag" section of ydDataType.h
	int Direction;
	YDCashCommissionRatePiece RatePiece;
	int EIAID;
	int LoginOption;
	const YDInstrument *m_pInstrument;
	const YDProduct *m_pProduct;
	const YDExchange *m_pExchange;
	const YDAccount *m_pAccount;
};

class YDCashMessageCommissionRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int ProductRef;
	int Type;
	double TradeRate;
	double NonTradeRate;
};

class YDMessageCommissionRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int ProductRef;
	int MessageCount;
	double OTR;
	double CommissionRate;
};

class YDMarginModelParam
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	int MarginModelID;
	int SystemUse5;
	char ParamName[256];
	char ParamValue[32];
};

class YDIDFromExchange
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int ExchangeRef;
	int IDType;                         // Refer to "IDType in IDFromExchange" section of ydDataType.h
	int IDInSystem;
	int SystemUse6;
	char IDFromExchange[24];
	YDLongOrderSysID LongIDInSystem;
};

class YDUpdateMarginRate
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int ProductRef;
	int InstrumentRef;
	int UnderlyingInstrumentRef;
	int HedgeFlagSet;
	int ExpireDate;
	int Multiple;
	int OptionTypeSet;
	int SystemUse4;
	union
	{
		double LongMarginRatioByMoney;
		double PutMarginRatioByMoney;
	};
	union
	{
		double LongMarginRatioByVolume;
		double PutMarginRatioByVolume;
		double BaseMarginRate;
	};
	union
	{
		double ShortMarginRatioByMoney;
		double CallMarginRatioByMoney;
		double LinearFactor;
	};
	union
	{
		double ShortMarginRatioByVolume;
		double CallMarginRatioByVolume;
		double LowerBoundaryCoef;
	};
};

class YDUpdateMessageCommissionConfig
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int ExchangeRef;
	int ProductRef;
	int InstrumentRef;
	int MaxMessage;
	int SystemUse4;
	int SystemUse5;
};

class YDAdjustCashTradingConstraint
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int ExchangeRef;
	int ProductRef;
	int InstrumentRef;
	int SystemUse4;
	int IsSetting;
	int CashTradingConstraint;
	int SystemUse5;
};

class YDAdjustAccount
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int RequestID;
	int SystemUse4;
	double PreBalance;
};

class YDAccountExchangeInfo
{
public:
	int SystemUse1;
	int AccountRef;
	int ExchangeRef;
	int TradingRight;                   // Refer to "Trade Right" section of ydDataType.h
	char TradingRightFromSource[YD_TRS_Count];
	int SystemUse2;
	bool IsDedicatedConnectionID[64];   // Whether this connectionID is dedicated to this account
	YDTradingCode TradingCode[YD_MaxHedgeFlag];
	const YDAccount *m_pAccount;
	const YDExchange *m_pExchange;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
};

class YDAccountProductInfo
{
public:
	int SystemUse1;
	int AccountRef;
	int ProductRef;
	int TradingRight;                   // Refer to "Trade Right" section of ydDataType.h
	char TradingRightFromSource[YD_TRS_Count];
	int SystemUse2;
	YDTradeConstraint TradingConstraints[YD_MaxHedgeFlag];
	const YDAccount *m_pAccount;
	const YDProduct *m_pProduct;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
};

class YDAccountInstrumentInfo
{
public:
	int SystemUse1;
	int AccountRef;
	int InstrumentRef;
	int TradingRight;					// Refer to "Trade Right" section of ydDataType.h
	unsigned short RFQCount;			// only valid for SHFE/INE options and message commission calculation is required, 0 for otherwise
	char ExemptMessageCommissionYDOrderFlag;	// don't calculate message commission if YDOrderFlag>ExemptMessageCommissionYDOrderFlag
	char SystemUse2;
	char TradingRightFromSource[YD_TRS_Count];
	int MaxMessage;
	int SystemUse3;
	YDTradeConstraint TradingConstraints[YD_MaxHedgeFlag];
	const YDAccount *m_pAccount;
	const YDInstrument *m_pInstrument;
	const YDMarginRate *m_pMarginRate[YD_MaxHedgeFlag];
	const YDCommissionRate *m_pCommissionRate[YD_MaxHedgeFlag];
	const YDCashCommissionRate *m_pCashCommissionRate[YD_UsefulCashCommissionRatesInAccountInstrumentInfo];
	const YDBrokerageFeeRate *m_pBrokerageFeeRate[YD_UsefulCashCommissionRatesInAccountInstrumentInfo];
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
	void *pInternalUse;
};

class YDAccountMarginModelInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int MarginModelID;
	int CloseVerify;
	double MarginRatio;
	char ProductRange[256];
	int SystemUse4;
	int SystemUse5;

	const YDAccount *m_pAccount;
	mutable void *pUser;
	mutable double UserFloat;
	mutable int UserInt1;
	mutable int UserInt2;
};

class YDAccountProductGroupMarginModelParam
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int MarginModelID;
	int SystemUse4;
	char ProductGroupName[32];
	double MarginRatio;
};

class YDGeneralRiskParam
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int GeneralRiskParamType;
	int ExtendedRef;
	double FloatValue;
	int IntValue1;
	int IntValue2;
};

class YDTradingSegmentDetail
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int SystemUse4;
	short ExchangeRef;
	short ProductRef;
	int InstrumentRef;
	int SegmentTime;
	int TradingStatus;                  // Refer to "Trade Status" section of ydDataType.h
	const YDExchange *m_pExchange;
	const YDProduct *m_pProduct;
	const YDInstrument *m_pInstrument;
};

class YDHoldingAdjustStatus
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	int InstrumentRef;
	int SystemUse4;
	int TotalTransferInVolume;
	int TotalTransferOutVolume;
	double TotalTransferInPrice;
	double TotalTransferOutPrice;
};

class YDServerNotice
{
public:
	long long SystemUse1;
	int ServerNoticeType;
	int SystemUse2;
	union
	{
		char Buffer[256];
		struct
		{
			int RemainDayCount;
		}	PasswordNearExpirationInfo;
	};
};

class YDRelayClientInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int AccountRef;
	int RequestID;
	char EncryptedClientReport[1024];
	char ClientIP[40];
	char ClientPort[8];
	char ClientLoginTime[24];
	char ClientAppID[32];
};

class YDAccountLoginInfo
{
public:
	int SystemUse1;
	int SystemUse2;
	int SystemUse3;
	int AccountRef;
	char IP[16];
	unsigned CurLoginCount;
	unsigned TotalLoginCount;
	unsigned CurFailedLoginCount;
	unsigned TotalFailedLoginCount;
	int LoginRightStatus;                  // Refer to "Login Right Status" section of ydDataType.h
	int SystemUse4;
};

/// Data structs for YDExtendedApi

class YDExtendedOrder: public YDOrder
{
public:
	union
	{
		const YDInstrument *m_pInstrument;
		const YDCombPositionDef *m_pCombPositionDef;
	};
	const YDAccount *m_pAccount;
	const YDInstrument *m_pInstrument2;
};

class YDExtendedTrade: public YDTrade
{
public:
	const YDInstrument *m_pInstrument;
	const YDAccount *m_pAccount;
};

class YDExtendedQuote: public YDQuote
{
public:
	bool BidOrderFinished,AskOrderFinished;
	const YDInstrument *m_pInstrument;
	const YDAccount *m_pAccount;
};

class YDExtendedRequestForQuote: public YDRequestForQuote
{
public:
	const YDInstrument *m_pInstrument;
};

class YDExtendedAccount
{
public:
	double CloseProfit;
	double CashIn;
	double OtherCloseProfit;
	double Commission;
	double Margin;
	double PositionProfit;
	double Balance;
	double Available;
	unsigned UsedOrderCount;
	int Useless;
	const YDAccount *m_pAccount;
	double ExecMargin;
	double OptionLongPositionCost;
	double OptionLongPositionCostLimit;
	double PrePositionMarketValue;
	// The init value of PositionMarketValue is the same as PrePositionMarketValue. It will only be changed after calling recalcPositionMarketValue()
	double PositionMarketValue;
	double ExecAllocatedAmount;
	double ExecAllocatedFrozenAmount;
	double MessageCommission;

	double usable(void) const
	{
		if ((PositionProfit>0) && !(m_pAccount->AccountFlag&YD_AF_UsePositionProfit))
		{
			return Available;
		}
		else
		{
			return Available+PositionProfit;
		}
	}
	double useable(void) const
	{
		return usable();
	}
	bool canUse(double value) const
	{
		return usable()>value;
	}
	double staticCashBalance(void) const
	{
		return m_pAccount->PreBalance+m_pAccount->Deposit-m_pAccount->Withdraw;
	}
	double dynamicCashBalance(void) const
	{
		return CloseProfit+PositionProfit+CashIn-Commission;
	}
	double cashBalance(void) const
	{
		return staticCashBalance()*m_pAccount->MaxMoneyUsage+dynamicCashBalance();
	}
	double marketValue(void) const
	{
		return cashBalance()+PositionMarketValue;
	}
	double preCashBalance(void) const
	{
		return m_pAccount->PreBalance*m_pAccount->MaxMoneyUsage;
	}
	double preMarketValue(void) const
	{
		return preCashBalance()+PrePositionMarketValue;
	}
};

class YDExtendedAccountExchangeInfo
{
public:
	union
	{
		const YDAccountExchangeInfo *m_pAccountExchangeInfo;
		const YDAccountExchangeInfo *m_pAccountExcangeInfo;
	};
	double OptionLongPositionCost;
	double OptionLongPositionCostLimit;
	int TradeControlFlag;
	int SystemUse1;
};

class YDExtendedAccountProductInfo
{
public:
	const YDAccountProductInfo *m_pAccountProductInfo;
	int MarginModelID;
	int SystemUse;
};

class YDExtendedAccountInstrumentInfo
{
public:
	const YDAccountInstrumentInfo *m_pAccountInstrumentInfo;
	double MessageCommission;
	int CashTradingConstraint;
	unsigned MaxCashBuyVolume;
	int MaxOrderVolume;
	unsigned HoldingLimit;
	double CashMessageCommissionTradeRate;
	double CashMessageCommissionNonTradeRate;
};

class YDExtendedPosition
{
public:
	class CPositionDetail
	{
	public:
		CPositionDetail *m_pNext;
		double Price;
		// TradeID<0 indicates history position
		union
		{
			YDTradeID TradeID;
			YDLongTradeID LongTradeID;
		};
		int Volume;
		char YDTradeFlag;
	};
	
	int PositionDate;
	int PositionDirection;
	int HedgeFlag;
	int TotalCombPositions;
	int Position;
	int OpenFrozen;
	int CloseFrozen;
	int ExecFrozen;
	int AbandonExecFrozen;
	int PositionByOrder;
	double SystemUse1[3];
	// Yesterday position used for commission calculation only, based on each exchange's commission rules.
	int YDPositionForCommission;
	int PossibleOpenVolume;
	double TotalOpenPrice;
	double Margin;
	double PositionProfit;
	// MarginPerLot is margin when price is preSettlementPrice
	double MarginPerLot;
	double CloseProfit;
	double OtherCloseProfit;
	double TotalOriginalOpenPrice;
	const YDAccountInstrumentInfo *m_pAccountInstrumentInfo;
	CPositionDetail *PositionDetailList;
	void *Padding1;
	unsigned CombPositionCount;

	const YDAccount *getAccount(void) const
	{
		return m_pAccountInstrumentInfo->m_pAccount;
	}
	const YDInstrument *getInstrument(void) const
	{
		return m_pAccountInstrumentInfo->m_pInstrument;
	}
	const YDMarginRate *getMarginRate(void) const
	{
		return m_pAccountInstrumentInfo->m_pMarginRate[HedgeFlag-1];
	}
	const YDCommissionRate *getCommissionRate(void) const
	{
		return m_pAccountInstrumentInfo->m_pCommissionRate[HedgeFlag-1];
	}

	//DEPRECATED: This function is deprecated and will be removed in future release. Use getOpenPrice() instead
	double OpenPrice(void) const
	{
		return getOpenPrice();
	}

	// getOpenPrice() is based on "first open, first close" rule
	double getOpenPrice(void) const
	{
		if (Position>0)
		{
			return TotalOpenPrice/Position;
		}
		else
		{
			return 0;
		}
	}
	// getOriginalOpenPrice() is based on keeping average open price unchanged during closing
	double getOriginalOpenPrice(void) const
	{
		if (Position>0)
		{
			return TotalOriginalOpenPrice/Position;
		}
		else
		{
			return 0;
		}
	}

	// Return yesterday position calculated according to "first open, first close" rule
	int getYDPosition(void) const
	{
		int position=0;
		CPositionDetail *p=PositionDetailList;
		while (p && (p->LongTradeID<0))
		{
			position+=p->Volume;
			p = p->m_pNext;
		}
		return position;
	}
};

class YDExtendedHolding
{
public:
	const YDAccountInstrumentInfo *m_pAccountInstrumentInfo;
	YDHoldingPiece HoldingPiece[YD_CHT_Count];
	YDHoldingPiece TotalHolding;
	int ExternalSellFrozen;
	int SystemUse1;
	YDHoldingAdjustStatus HoldingAdjustStatus;

	const YDAccount *getAccount(void) const
	{
		return m_pAccountInstrumentInfo->m_pAccount;
	}
	const YDInstrument *getInstrument(void) const
	{
		return m_pAccountInstrumentInfo->m_pInstrument;
	}
};

class YDExtendedSpotPosition
{
public:
	int SystemUse1;
	int Position;
	int ExchangeFrozenVolume;
	int ExecAllocatedVolume;
	double ExecAllocatedAmount;
	int CoveredVolume;
	int ExecVolume;
	int ExecAllocatedFrozenVolume;
	int TransDisposalFrozenVolume;
	double ExecAllocatedFrozenAmount;
	const YDAccountInstrumentInfo *m_pAccountInstrumentInfo;

	const YDAccount *getAccount(void) const
	{
		return m_pAccountInstrumentInfo->m_pAccount;
	}
	const YDInstrument *getInstrument(void) const
	{
		return m_pAccountInstrumentInfo->m_pInstrument;
	}
};

class YDExtendedCombPositionDetail
{
public:
	const YDAccount *m_pAccount;
	const YDCombPositionDef *m_pCombPositionDef;
	int Position;
	int CombPositionDetailID;
};

class YDExtendedPositionFilter
{
public:
	/// -1 in the following 3 fields indicates any
	int PositionDate;
	int PositionDirection;
	int HedgeFlag;

	/// NULL in the following 4 fields indicates any
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDExtendedHoldingFilter
{
public:
	/// NULL in the following 4 fields indicates any
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDExtendedSpotPositionFilter
{
public:
	/// NULL in the following 4 fields indicates any
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDOrderFilter
{
public:
	/// -1 in the following 2 fields indicates any
	int StartTime;
	int EndTime;

	/// Bitwise OR of several (1<<YDOrderFlag)
	int YDOrderFlags;

	/// NULL in the following 5 fields indicates any
	const YDCombPositionDef *pCombPositionDef;
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDQuoteFilter
{
public:
	/// -1 in the following 2 fields indicates any
	int StartTime;
	int EndTime;

	/// NULL in the following 4 fields indicates any
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDTradeFilter
{
public:
	/// -1 in the following 2 fields indicates any
	int StartTime;
	int EndTime;

	/// NULL in the following 4 fields indicates any
	const YDInstrument *pInstrument;
	const YDProduct *pProduct;
	const YDExchange *pExchange;
	const YDAccount *pAccount;
};

class YDTradeFilter2: public YDTradeFilter
{
public:
	/// Bitwise OR of several (1<<YDTradeFlag)
	int YDTradeFlags;
};

class YDCombPositionDetailFilter
{
public:
	/// NULL or 0 in the following 4 fields indicates any
	const YDCombPositionDef *pCombPositionDef;
	const YDAccount *pAccount;
	/// If the following 2 fields are specified, they should match one leg of this combination position
	const YDInstrument *pInstrument;
	int PositionDirection;
	/// If IncludeSplit is false, only current valid combPositions are included
	bool IncludeSplit;
};

template<class T> class YDQueryResult
{
protected:
	virtual ~YDQueryResult(void)
	{
	}
public:
	virtual int getCount(void) const=0;
	virtual const T *get(int pos) const=0;
	virtual void destroy(void)=0;
};


#endif
