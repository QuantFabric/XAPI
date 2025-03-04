#ifndef YD_API_H
#define YD_API_H

#include "ydDataStruct.h"

#if defined(_WIN32)
#ifdef LIB_YD_API_EXPORT
#define YD_API_EXPORT __declspec(dllexport)
#else
#define YD_API_EXPORT __declspec(dllimport)
#endif
#else
#define YD_API_EXPORT __attribute__ ((visibility ("default")))
#endif

class YDListener
{
public:
	virtual ~YDListener(void)
	{
	}
	virtual void notifyBeforeApiDestroy(void)
	{
	}
	virtual void notifyAfterApiDestroy(void)
	{
	}
	/// In the event of YD_AE_ServerRestarted, this process will exit after return of this method, as all data
	/// recevied may be not valid and data flow may be changed. If user don't want to stop this process, he can
	/// call startDestroy in this method. Then this process will not exit, but start process of self destroying.
	/// User can create new API afterwards to connect to new server.
	virtual void notifyEvent(int apiEvent)
	{
	}
	virtual void notifyReadyForLogin(bool hasLoginFailed)
	{
	}
	virtual void notifyLogin(int errorNo,int maxOrderRef,bool isMonitor)
	{
	}
	virtual void notifyGroupMaxOrderRef(const int groupMaxOrderRef[])
	{
	}
	virtual void notifyServerNotice(const YDServerNotice *pServerNotice)
	{
	}
	/// notifyFinishInit will be only called once in each instance of API.
	/// It is safe to call all api functions then, but all orders and trades haven't been received
	virtual void notifyFinishInit(void)
	{
	}
	/// notifyCaughtUp means api has received all information up to recent login
	/// It will be called once for each successful login
	/// A typical relationship between notifyFinishInit and notifyCaughtUp in a session with disconnection can be show below
	///		start api
	///		notifyFinishInit
	///		notifyCaughtUp
	///		...
	///		disconnected and reconnected
	///		notifyCaughtUp
	virtual void notifyCaughtUp(void)
	{
	}
	virtual void notifyTradingSegment(const YDExchange *pExchange,int segmentTime)
	{
	}
	virtual void notifyTradingSegmentDetail(const YDTradingSegmentDetail *pTradingSegmentDetail)
	{
	}
	virtual void notifyCombPosition(const YDCombPosition *pCombPosition,const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount)
	{
	}
	virtual void notifyOrder(const YDOrder *pOrder,const YDInstrument *pInstrument,const YDAccount *pAccount)
	{
	}
	virtual void notifyTrade(const YDTrade *pTrade,const YDInstrument *pInstrument,const YDAccount *pAccount)
	{
	}
	virtual void notifyFailedCancelOrder(const YDFailedCancelOrder *pFailedCancelOrder,const YDExchange *pExchange,const YDAccount *pAccount)
	{
	}
	virtual void notifyQuote(const YDQuote *pQuote,const YDInstrument *pInstrument,const YDAccount *pAccount)
	{
	}
	virtual void notifyFailedCancelQuote(const YDFailedCancelQuote *pFailedCancelQuote,const YDExchange *pExchange,const YDAccount *pAccount)
	{
	}
	virtual void notifyRequestForQuote(const YDRequestForQuote *pRequestForQuote,const YDInstrument *pInstrument)
	{
	}
	virtual void notifyCombPositionOrder(const YDOrder *pOrder,const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount)
	{
	}
	virtual void notifyOptionExecTogetherOrder(const YDOrder *pOrder,const YDInstrument *pInstrument,const YDInstrument *pInstrument2,const YDAccount *pAccount)
	{
	}
	virtual void notifyMarketData(const YDMarketData *pMarketData)
	{
	}
	virtual void notifyAccount(const YDAccount *pAccount)
	{
	}
	virtual void notifyAccountExchangeInfo(const YDAccountExchangeInfo *pAccountExchangeInfo)
	{
	}
	virtual void notifyAccountProductInfo(const YDAccountProductInfo *pAccountProductInfo)
	{
	}
	virtual void notifyAccountInstrumentInfo(const YDAccountInstrumentInfo *pAccountInstrumentInfo)
	{
	}
	virtual void notifyAccountMarginModelInfo(const YDAccountMarginModelInfo *pAccountMarginModelInfo)
	{
	}
	virtual void notifyIDFromExchange(const YDIDFromExchange *pIDFromExchange,const YDExchange *pExchange)
	{
	}
	virtual void notifyUpdateMarginRate(const YDUpdateMarginRate *pUpdateMarginRate)
	{
	}
	virtual void notifyUpdateMessageCommissionConfig(const YDUpdateMessageCommissionConfig *pUpdateMessageCommissionConfig)
	{
	}
	virtual void notifyAdjustCashTradingConstraint(const YDAdjustCashTradingConstraint *pAdjustCashTradingConstraint)
	{
	}
	virtual void notifySpotPosition(const YDInstrument *pInstrument,const YDAccount *pAccount,int newPosition)
	{
	}
	virtual void notifySpotAlive(const YDExchange *pExchange)
	{
	}
	virtual void notifyHoldingExternalFrozen(const YDInstrument *pInstrument,const YDAccount *pAccount,int newExternalSellFrozen)
	{
	}
	virtual void notifyHoldingAdjustStatus(const YDHoldingAdjustStatus *pHoldingAdjustStatus)
	{
	}
	virtual void notifyMissingOrder(const YDMissingOrder *pMissingOrder)
	{
	}
	virtual void notifyChangePassword(int errorNo)
	{
	}
	virtual void notifyExchangeConnectionInfo(const YDExchangeConnectionInfo *pExchangeConnectionInfo)
	{
	}
	/// both of following notifyResponse will be called for each response, user can use either one
	virtual void notifyResponse(int errorNo,int requestType)
	{
	}
	virtual void notifyResponse(int errorNo,int requestType,int requestID)
	{
	}
	// when using YDApi, this is suggested time for recalculating margin and position profit
	// when using YDExtendedApi, this is after each automatic recalculation
	virtual void notifyRecalcTime(void)
	{
	}
};

class YDApi
{
public:
	virtual ~YDApi(void)
	{
	}
	virtual bool start(YDListener *pListener)=0;
	///	startDestroy will start a process to destroy this api instance
	///	After calling this method, api will try to close all connections and  stop all threads belong to this api.
	///	In this period, all trading functions can not be used any more, and no trading notification will be received,
	/// but all functions of getting data can still be used. At the end of this period, notifyBeforeApiDestroy will 
	/// be sent to listener.
	/// Then start the second period to free all data structure of api. All functions of api cannot be used in
	/// this period, and all data pointers given by api are not valid any more. At the end of second period,
	/// notifyAfterApiDestroy will send to listener, indicating all resources of api are freed. User should not
	/// ever try to delete api, but the listener itself should be deleted by user after this.
	virtual void startDestroy(void)=0;
	virtual void disconnect(void)=0;
	virtual bool login(const char *username,const char *password,const char *appID,const char *authCode)=0;
	virtual bool insertOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	virtual bool cancelOrder(YDCancelOrder *pCancelOrder,const YDExchange *pExchange,const YDAccount *pAccount=NULL)=0;
	virtual bool insertQuote(YDInputQuote *pInputQuote,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	/// cancelQuote is for all futures exchanges
	virtual bool cancelQuote(YDCancelQuote *pCancelQuote,const YDExchange *pExchange,const YDAccount *pAccount=NULL)=0;
	/// cancelQuoteByInstrument is for stock option exchanges
	virtual bool cancelQuoteByInstrument(YDCancelQuote *pCancelQuote,const YDInstrument *pInstrument,int cancelQuoteByInstrumentType,const YDAccount *pAccount=NULL)=0;
	virtual bool insertCombPositionOrder(YDInputOrder *pInputOrder,const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount=NULL)=0;
	virtual bool insertOptionExecTogetherOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDInstrument *pInstrument2,const YDAccount *pAccount=NULL)=0;
	/// send multiple insert orders in same time. inputOrders and instruments must have size of count, return true if all are successful
	/// maximum value of count is 16
	virtual bool insertMultiOrders(unsigned count,YDInputOrder inputOrders[],const YDInstrument *instruments[],const YDAccount *pAccount=NULL)=0;
	/// send multiple cancel orders in same time. cancelOrders and exchanges must have size of count, return true if all are successful
	/// maximum value of count is 16
	virtual bool cancelMultiOrders(unsigned count,YDCancelOrder cancelOrders[],const YDExchange *exchanges[],const YDAccount *pAccount=NULL)=0;
	/// send multiple insert quotes in same time. inputQuotes and instruments must have size of count, return true if all are successful
	/// maximum value of count is 12
	virtual bool insertMultiQuotes(unsigned count,YDInputQuote inputQuotes[],const YDInstrument *instruments[],const YDAccount *pAccount=NULL)=0;
	/// send multiple cancel quotes in same time. cancelQuotes and exchanges must have size of count, return true if all are successful
	/// maximum value of count is 16
	virtual bool cancelMultiQuotes(unsigned count,YDCancelQuote cancelQuotes[],const YDExchange *exchanges[],const YDAccount *pAccount=NULL)=0;
	virtual bool subscribe(const YDInstrument *pInstrument)=0;
	virtual bool unsubscribe(const YDInstrument *pInstrument)=0;
	virtual bool setTradingRight(const YDAccount *pAccount,const YDInstrument *pInstrument,const YDProduct *pProduct,const YDExchange *pExchange,
		int tradingRight,int requestID=0,int tradingRightSource=YD_TRS_AdminPermanent)=0;
	/// following methods can only be used by admin, trader should not call them
	virtual bool alterMoney(const YDAccount *pAccount,int alterMoneyType,double alterValue,int requestID=0)=0;
	virtual bool alterHolding(const YDAccount *pAccount,const YDInstrument *pInstrument,int alterHoldingType,int volume,double totalPrice,int requestID=0)=0;
	virtual bool updateMarginRate(const YDUpdateMarginRate *pUpdateMarginRate,int requestID=0)=0;
	virtual bool updateMessageCommissionConfig(const YDUpdateMessageCommissionConfig *pUpdateMessageCommissionConfig,int requestID=0)=0;
	virtual bool adjustCashTradingConstraint(const YDAdjustCashTradingConstraint *pAdjustCashTradingConstraint,int requestID=0)=0;
	virtual bool adjustAccountMarginModelInfo(const YDAccountMarginModelInfo *pAccountMarginModelInfo,int requestID=0)=0;
	virtual bool updateSpotPosition(const YDAccount *pAccount,const YDInstrument *pInstrument,int position,int requestID=0)=0;
	virtual bool updateSpotAlive(const YDExchange *pExchange,int requestID=0)=0;
	virtual bool updateHoldingExternalFrozen(const YDAccount *pAccount,const YDInstrument *pInstrument,int externalSellFrozen,int requestID=0)=0;
	virtual bool alterAccountStatus(const YDAccount *pAccount,int alterAccountStatusCommand,int requestID=0)=0;
	/// changePassword can be used by both traders and admins
	virtual bool changePassword(const char *username,const char *oldPassword,const char *newPassword,int requestID=0)=0;
	/// tell server how to select connection if use YD_CS_Any, can only be used by administrator or accounts with YD_AF_SelectConnection flag
	/// connectionList is or of serial of 4 bits, lowest one has highest priority, must cover all connections of specified exchange
	virtual bool selectConnections(const YDExchange *pExchange,unsigned long long connectionList,int requestID=0)=0;

	virtual bool hasFinishedInit(void)=0;

	virtual int getSystemParamCount(void)=0;
	virtual const YDSystemParam *getSystemParam(int pos)=0;
	virtual const YDSystemParam *getSystemParamByName(const char *name,const char *target)=0;

	virtual int getExchangeCount(void)=0;
	virtual const YDExchange *getExchange(int pos)=0;
	virtual const YDExchange *getExchangeByID(const char *exchangeID)=0;

	virtual int getProductCount(void)=0;
	virtual const YDProduct *getProduct(int pos)=0;
	virtual const YDProduct *getProductByID(const char *productID)=0;

	virtual int getInstrumentCount(void)=0;
	virtual const YDInstrument *getInstrument(int pos)=0;
	virtual const YDInstrument *getInstrumentByID(const char *instrumentID)=0;

	virtual int getCombPositionDefCount(void)=0;
	virtual const YDCombPositionDef *getCombPositionDef(int pos)=0;
	virtual const YDCombPositionDef *getCombPositionDefByID(const char *combPositionID,int combHedgeFlag)=0;

	/// following 3 functions for YDAccount can only be used by monitor
	virtual int getAccountCount(void)=0;
	virtual const YDAccount *getAccount(int pos)=0;
	virtual const YDAccount *getAccountByID(const char *accountID)=0;
	/// following function for YDAccount can only be used by trader
	virtual const YDAccount *getMyAccount(void)=0;

	virtual int getPrePositionCount(void)=0;
	virtual const YDPrePosition *getPrePosition(int pos)=0;

	virtual int getPreHoldingCount(void)=0;
	virtual const YDPreHolding *getPreHolding(int pos)=0;

	virtual int getSpotPrePositionCount(void)=0;
	virtual const YDSpotPrePosition *getSpotPrePosition(int pos)=0;

	/// it is not neccessary to use following 8 functions, as all these rates can be found in YDAccountInstrumentInfo
	virtual int getMarginRateCount(void)=0;
	virtual const YDMarginRate *getMarginRate(int pos)=0;
	virtual int getCommissionRateCount(void)=0;
	virtual const YDCommissionRate *getCommissionRate(int pos)=0;
	virtual int getCashCommissionRateCount(void)=0;
	virtual const YDCashCommissionRate *getCashCommissionRate(int pos)=0;
	virtual int getBrokerageFeeRateCount(void)=0;
	virtual const YDBrokerageFeeRate *getBrokerageFeeRate(int pos)=0;

	virtual int getMessageCommissionRateCount(void)=0;
	virtual const YDMessageCommissionRate *getMessageCommissionRate(int pos)=0;

	virtual int getMarginModelParamCount(void)=0;
	virtual const YDMarginModelParam *getMarginModelParam(int pos)=0;

	/// when trader call following 8 functions, pAccount should be NULL
	virtual const YDAccountExchangeInfo *getAccountExchangeInfo(const YDExchange *pExchange,const YDAccount *pAccount=NULL)=0;
	virtual const YDAccountProductInfo *getAccountProductInfo(const YDProduct *pProduct,const YDAccount *pAccount=NULL)=0;
	virtual const YDAccountInstrumentInfo *getAccountInstrumentInfo(const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	virtual const YDMarginRate *getInstrumentMarginRate(const YDInstrument *pInstrument,int hedgeFlag,const YDAccount *pAccount=NULL)=0;
	virtual const YDCommissionRate *getInstrumentCommissionRate(const YDInstrument *pInstrument,int hedgeFlag,const YDAccount *pAccount=NULL)=0;
	virtual const YDCashCommissionRate *getInstrumentCashCommissionRate(const YDInstrument *pInstrument,int ydOrderFlag,int direction,const YDAccount *pAccount=NULL)=0;
	virtual const YDBrokerageFeeRate *getInstrumentBrokerageFeeRate(const YDInstrument *pInstrument,int ydOrderFlag,int direction,const YDAccount *pAccount=NULL)=0;
	virtual const YDAccountMarginModelInfo *getAccountMarginModelInfo(int marginModelID,const YDAccount *pAccount=NULL)=0;

	virtual int getAccountProductGroupMarginModelParamCount(void)=0;
	virtual const YDAccountProductGroupMarginModelParam *getAccountProductGroupMarginModelParam(int pos)=0;

	virtual int getGeneralRiskParamCount(void)=0;
	virtual const YDGeneralRiskParam *getGeneralRiskParam(int pos)=0;

	virtual void writeLog(const char *format,...)=0;
	virtual const char *getVersion(void)=0;

	enum YDPacketType
	{
		YD_CLIENT_PACKET_INSERT_ORDER=0,
		YD_CLIENT_PACKET_CANCEL_ORDER=1,
		YD_CLIENT_PACKET_INSERT_QUOTE=2,
		YD_CLIENT_PACKET_CANCEL_QUOTE=3,
		YD_CLIENT_PACKET_INSERT_NORMAL_ORDER=4,
		YD_CLIENT_PACKET_CANCEL_NORMAL_ORDER=5,
		YD_CLIENT_PACKET_INSERT_SPECIAL_ORDER=6,
		YD_CLIENT_PACKET_CANCEL_SPECIAL_ORDER=7
	};
	/// definition of protocolVersion
	///		0: newest protocol version
	///		1: protocol for api version up to 1.188
	///		2: protocol for api version up to 1.386
	///		3: protocol for api version from 1.486, current newest version
	virtual int getClientPacketHeader(YDPacketType type,unsigned char *pHeader,int len,int protocolVersion=0)=0;

	/// can get trading day and sessionID after login successfully
	virtual int getTradingDay(void)=0;
	virtual int getSessionID(void)=0;

	/// get first config using this name in config file (parameter of makeYDApi or makeYDExtendedApi), NULL if not found
	virtual const char *getConfig(const char *name)=0;
	/// get all configs using this name,  user should call destroy method of return object to free memory after using
	virtual YDQueryResult<char> *getConfigs(const char *name)=0;

	/// check whether certain aux service is supported, can be used after finishInit
	/// auxRequestType is is defined in "Aux Request Type" in ydDataType.h
	virtual bool supportAuxService(int auxRequestType)=0;

	/// following aux reqeusts are only available for some brokers, please confirm with your broker before using, or use supportAuxService to check

	/// auxTakeOverSpotPosition will take over spot position from spot trading system for option execution & cover order
	/// it can be used only for ETF options
	/// takeOverType is 0 for take, 1 for return, 2 for take at most
	virtual bool auxTakeOverSpotPosition(const YDInstrument *pInstrument,int takeOverType,int volume,int requestID=0,const YDAccount *pAccount=NULL)=0;

	/// auxTransferFund will call broker interface to transfer fund
	/// transferFundType is 0 for transfer in, 1 for transfer out
	virtual bool auxTransferFund(int transferFundType,double amount,int requestID=0,const YDAccount *pAccount=NULL)=0;

	/// following 2 methods can only be used for admin user doing relay for futures exchanges
	virtual bool reportRelayClientInfo(const YDRelayClientInfo *pRelayClientInfo)=0;
	/// return error message, NULL if error
	virtual const char *verifyClientInfo(const char *encryptedClientReport)=0;

	/// setRelayContext1 can only be used for admin user doint relay
	virtual bool setRelayContext1(const char *clientInfo,int loginOption)=0;
};

class YDExtendedListener
{
public:
	virtual ~YDExtendedListener(void)
	{
	}
	// all address of parameters in following methods are fixed
	virtual void notifyExtendedOrder(const YDExtendedOrder *pOrder)
	{
	}
	virtual void notifyExtendedTrade(const YDExtendedTrade *pTrade)
	{
	}
	virtual void notifyExtendedQuote(const YDExtendedQuote *pQuote)
	{
	}
	virtual void notifyExtendedPosition(const YDExtendedPosition *pPosition)
	{
	}
	virtual void notifyExtendedAccount(const YDExtendedAccount *pAccount)
	{
	}
	// notifyExchangeCombPositionDetail and notifyExtendedSpotPosition will only be used when trading SSE/SZSE
	virtual void notifyExchangeCombPositionDetail(const YDExtendedCombPositionDetail *pCombPositionDetail)
	{
	}
	virtual void notifyExtendedSpotPosition(const YDExtendedSpotPosition *pSpotPosition)
	{
	}
	virtual void notifyExtendedHolding(const YDExtendedHolding *pHolding)
	{
	}
};

class YDExtendedApi: public YDApi
{
public:
	// startExtended method can be used when notification of extended message are required.
	// There is no other difference between start and startExtended.
	// User can also use start method if extended message are not required
	virtual bool startExtended(YDListener *pListener,YDExtendedListener *pExtendedListener)=0;

	// Please use setSessionOrderRef before any order or quote insert, so that getNextOrderRef will ensure a suitable orderRef
	// The lower sessionBitCount bits of suitable orderRef will always be sessionID
	// User should ensure that sessionBitCount<=16, and sessionID only has bit 1 in these lower bits
	// By default, sessionBitCount=0, sessionID=0
	virtual bool setSessionOrderRefRule(unsigned sessionBitCount,unsigned sessionID)=0;
	virtual void getSessionOrderRefRule(unsigned *pSessionBitCount,unsigned *pSessionID)=0;
	virtual int getNextOrderRef(unsigned orderGroupID=0,bool update=true)=0;

	/*
		insertOrder will not do local validation before sending to server.
			YDExtendedApi will not froze position and money until notification of these orders are received
			This may lead to a temporary inaccuracy.
		checkAndInsertOrder will do local validation before sending to server
			Position and money will be frozen if validation and sending is successful
			This will ensure all data are accurate at any moment.
		After first order notification, there is no difference between these two methods
		User can mix-use these two methods, though it is not recommended.
		checkAndInsertOrder will set OrderRef using getNextOrderRef(), and user should get it from pInputOrder after calling
		Both insertOrder and checkAndInsertOrder will set ErrorNo if error occurs
	*/
	virtual bool checkAndInsertOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	///	checkOrder will only check whether pInputOrder is OK, and will not send to server
	/// ErrorNo will be set if check failed
	virtual bool checkOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;

	/*
		Relationship of insertCombPositonOrder and checkAndInsertCombPositionOrder is similar to insertOrder and checkAndInsertOrder
		checkAndInsertCombPositionOrder will set OrderRef using getNextOrderRef(), and user should get it from pInputOrder after calling
	*/
	virtual bool checkAndInsertCombPositionOrder(YDInputOrder *pInputOrder,const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount=NULL)=0;
	virtual bool checkCombPositionOrder(YDInputOrder *pInputOrder,const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount=NULL)=0;

	/*
		Relationship of insertQuote and checkAndInsertQuote is similar to insertOrder and checkAndInsertOrder
		checkAndInsertQuote will set OrderRef using getNextOrderRef(), and user should get it from pInputQuote after calling
	*/
	virtual bool checkAndInsertQuote(YDInputQuote *pInputQuote,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	virtual bool checkQuote(YDInputQuote *pInputQuote,const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;

	/*
		Relationship of insertOptionExecTogetherOrder and checkAndInsertOptionExecTogetherOrder is similar to insertOrder and checkAndInsertOrder
		checkAndInsertOptionExecTogetherOrder will set OrderRef using getNextOrderRef(), and user should get it from pInputQuote after calling
	*/
	virtual bool checkAndInsertOptionExecTogetherOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDInstrument *pInstrument2,const YDAccount *pAccount=NULL)=0;
	virtual bool checkOptionExecTogetherOrder(YDInputOrder *pInputOrder,const YDInstrument *pInstrument,const YDInstrument *pInstrument2,const YDAccount *pAccount=NULL)=0;

	virtual const YDExtendedAccount *getExtendedAccount(const YDAccount *pAccount=NULL)=0;
	virtual const YDExtendedAccountExchangeInfo *getExtendedAccountExchangeInfo(const YDAccountExchangeInfo *pAccountExchangeInfo)=0;
	virtual const YDExtendedAccountProductInfo *getExtendedAccountProductInfo(const YDAccountProductInfo *pAccountProductInfo)=0;
	virtual const YDExtendedAccountInstrumentInfo *getExtendedAccountInstrumentInfo(const YDAccountInstrumentInfo *pAccountInstrumentInfo)=0;

	virtual const YDExtendedPosition *getExtendedPosition(int positionDate,int positionDirection,int hedgeFlag,
		const YDInstrument *pInstrument,const YDAccount *pAccount=NULL,bool create=false)=0;
	/// positions must have spaces of count, return real number of positions(may be greater than count). Only partial will be set if no enough space
	virtual unsigned findExtendedPositions(const YDExtendedPositionFilter *pFilter,unsigned count,const YDExtendedPosition *positions[])=0;
	/// User should call destroy method of return object to free memory after using following method
	virtual YDQueryResult<YDExtendedPosition> *findExtendedPositions(const YDExtendedPositionFilter *pFilter)=0;

	virtual const YDExtendedHolding *getExtendedHolding(const YDInstrument *pInstrument,const YDAccount *pAccount=NULL,bool create=false)=0;
	/// holdings must have sapces of count, return real number of holdings(may be greater than count). Only partial will be set if no enough space
	virtual unsigned findExtendedHoldings(const YDExtendedHoldingFilter *pFilter,unsigned count,const YDExtendedHolding *holdings[])=0;
	virtual YDQueryResult<YDExtendedHolding> *findExtendedHoldings(const YDExtendedHoldingFilter *pFilter)=0;
	virtual int getMaxSellVolume(const YDExtendedHolding *pHolding)=0;

	virtual const YDExtendedSpotPosition *getExtendedSpotPosition(const YDInstrument *pInstrument,const YDAccount *pAccount=NULL,bool create=false)=0;
	/// User should call destroy method of return object to free memory after using following method
	virtual YDQueryResult<YDExtendedSpotPosition> *findExtendedSpotPositions(const YDExtendedSpotPositionFilter *pFilter)=0;

	/// recalculate margin and position profit. if "RecalcMode" is "auto", there is no need to call this method
	virtual void recalcMarginAndPositionProfit(void)=0;

	/// getOrder by orderRef can only be used for orders using checkAndInsertOrder
	virtual const YDExtendedOrder *getOrder(int orderRef,unsigned orderGroupID=0,const YDAccount *pAccount=NULL)=0;
	/// getOrder by orderSysID can only be used for orders have been accepted by exchange
	virtual const YDExtendedOrder *getOrder(int orderSysID,const YDExchange *pExchange,int YDOrderFlag=YD_YOF_Normal)=0;
	virtual const YDExtendedOrder *getOrder(long long longOrderSysID,const YDExchange *pExchange,int YDOrderFlag=YD_YOF_Normal)=0;
	/// orders must have spaces of count, return real number of orders(may be greater than count). Only partial will be set if no enough space
	/// Only orders accepted by exchange can be found in this function
	virtual unsigned findOrders(const YDOrderFilter *pFilter,unsigned count,const YDExtendedOrder *orders[])=0;
	/// User should call destroy method of return object to free memory after using following methods
	virtual YDQueryResult<YDExtendedOrder> *findOrders(const YDOrderFilter *pFilter)=0;
	virtual YDQueryResult<YDExtendedOrder> *findPendingOrders(const YDOrderFilter *pFilter)=0;

	/// getQuote by orderRef can only be used for quotes using checkAndInsertQuote
	virtual const YDExtendedQuote *getQuote(int orderRef,unsigned orderGroupID=0,const YDAccount *pAccount=NULL)=0;
	/// getQuoteDerivedOrder can only be used for orders derived oder by using checkAndInsertQuote
	virtual const YDExtendedOrder *getQuoteDerivedOrder(int orderRef,int direction,unsigned orderGroupID=0,const YDAccount *pAccount=NULL)=0;
	/// getQuote by quoteSysID can only be used for quotes have been accepted by exchange
	virtual const YDExtendedQuote *getQuote(int quoteSysID,const YDExchange *pExchange)=0;
	virtual const YDExtendedQuote *getQuote(long long longQuoteSysID,const YDExchange *pExchange)=0;
	/// quotes must have spaces of count, return real number of quotes(may be greater than count). Only partial will be set if no enough space
	/// Only quotes accepted by exchange can be found in this function
	virtual unsigned findQuotes(const YDQuoteFilter *pFilter,unsigned count,const YDExtendedQuote *quotes[])=0;
	/// User should call destroy method of return object to free memory after using following methods
	virtual YDQueryResult<YDExtendedQuote> *findQuotes(const YDQuoteFilter *pFilter)=0;
	virtual YDQueryResult<YDExtendedQuote> *findPendingQuotes(const YDQuoteFilter *pFilter)=0;

	/// trades must have spaces of count, return real number of trades(may be greater than count). Only partial will be set if no enough space
	virtual unsigned findTrades(const YDTradeFilter *pFilter,unsigned count,const YDExtendedTrade *trades[])=0;
	/// User should call destroy method of return object to free memory after using following method
	virtual YDQueryResult<YDExtendedTrade> *findTrades(const YDTradeFilter *pFilter)=0;

	/// getCombPositionDetail can only be used in SSE/SZSE
	virtual const YDExtendedCombPositionDetail *getCombPositionDetail(int combPositionDetailID)=0;
	/// combPositionDetails must have spaces of count, return real number of combPositionDetails(may be greater than count). Only partial will be set if no enough space
	virtual unsigned findCombPositionDetails(const YDCombPositionDetailFilter *pFilter,unsigned count,const YDExtendedCombPositionDetail *combPositionDetails[])=0;
	/// User should call destroy method of return object to free memory after using following method
	virtual YDQueryResult<YDExtendedCombPositionDetail> *findCombPositionDetails(const YDCombPositionDetailFilter *pFilter)=0;

	/// get original ID from exchange based on ID in yd system, return NULL if there is no real difference between these 2 IDs
	virtual const char *getIDFromExchange(const YDExchange *pExchange,int idType,int idInSystem)=0;
	virtual const char *getLongIDFromExchange(const YDExchange *pExchange,int idType,long long longIdInSystem)=0;

	/// findExtendedPositions, findOrders, findQuotes and findTrades are slow

	virtual double getOptionsShortMarginPerLot(const YDInstrument *pInstrument,int hedgeFlag,bool includePremium,const YDAccount *pAccount=NULL)=0;
	virtual double getCombPositionMarginPerLot(const YDCombPositionDef *pCombPositionDef,const YDAccount *pAccount=NULL)=0;
	/// anyDirection can use Direction or PositionDirection
	virtual double getMarginPerLot(const YDInstrument *pInstrument,int hedgeFlag,int anyDirection,double openPrice,const YDAccount *pAccount=NULL)=0;
	virtual double getMarginPerLot(const YDExtendedPosition *pPosition,double openPrice)=0;
	virtual double getCombPositionMarginSaved(const YDExtendedCombPositionDetail *pCombPositionDetail,double legMargins[])=0;

	/// may return NULL if not exist
	virtual const YDExtendedRequestForQuote *getRequestForQuote(const YDInstrument *pInstrument)=0;

	/// get margin model information
	virtual int getMarginModel(const YDInstrument *pInstrument,const YDAccount *pAccount=NULL)=0;
	virtual int getMarginModel(const YDProduct *pProduct,const YDAccount *pAccount=NULL)=0;
	/// cannot use this CombPositionDef if it is not using YD_MM_Normal
	virtual bool canUseCombPositionDef(const YDCombPositionDef *pDef,const YDAccount *pAccount=NULL)=0;

	/// Search for an opportunity to create a new DCE comb position. "combTypes" is a list of comb position types to be processed.
	/// "combTypes" should be ended with -1 and sorted by priotity. If NULL is given, all types are processed
	/// If an opportunity was found and the order was sent successfully, pointer to the comb position definition is returned. Otherwise NULL is returned
	virtual const YDCombPositionDef *autoCreateCombPosition(const int *combTypes)=0;

	/// recalculate PositionMarketValue in YDExtendedAccount
	virtual void recalcPositionMarketValue(void)=0;

	/// export api data in CSV format, accountIDs are accountID seperated by space, empty accountIDs for all accounts
	virtual bool exportData(const char *dir,const char *accountIDs="")=0;
};

extern "C"
{
YD_API_EXPORT YDApi *makeYDApi(const char *configFilename);
YD_API_EXPORT YDExtendedApi *makeYDExtendedApi(const char *configFilename);

/// Following 2 functions use config strings in memory instead of config file.
/// Config strings in memory should have same contents as in config file, each config item is seprated by '\n'
YD_API_EXPORT YDApi *makeYDApiFromConfig(const char *configDesc);
YD_API_EXPORT YDExtendedApi *makeYDExtendedApiFromConfig(const char *configDesc);

/// Same as getVersion inside YDApi, put here to get version without make api
YD_API_EXPORT const char *getYDVersion(void);
// Returns nanoseconds elapsed since current process starts up
YD_API_EXPORT unsigned long long getYDNanoTimestamp();
}

#endif
