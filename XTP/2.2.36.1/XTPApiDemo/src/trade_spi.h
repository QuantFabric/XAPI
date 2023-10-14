#pragma once
#include "xtp_trader_api.h"
#include <fstream>

using namespace XTP::API;

class MyTraderSpi : public TraderSpi
{
public:
	MyTraderSpi();
	~MyTraderSpi();

	virtual void OnDisconnected(uint64_t session_id, int reason);

	///报单通知
	virtual void OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id);

	///成交通知
	virtual void OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id);

	virtual void OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id);

	virtual void OnQueryOrderEx(XTPOrderInfoEx *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_idt);

	virtual void OnQueryPosition(XTPQueryStkPositionRsp *investor_position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryAsset(XTPQueryAssetRsp *trading_account, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id);

	virtual void OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnCreditCashRepay(XTPCrdCashRepayRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id);

	virtual void OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo *cash_repay_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryCreditFundInfo(XTPCrdFundInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	virtual void OnQueryCreditDebtInfo(XTPCrdDebtInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id);

	virtual void OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo *assign_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	virtual void OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id);

	void setUserAPI(XTP::API::TraderApi* pApi) { pUserApi = pApi; }

	inline void set_save_to_file(bool save) { save_to_file_ = save; }
	inline void set_ping_pong_test_flag(bool flag) { ping_pang_flag_ = flag; }
	
	
	///算法相关部分
	
	virtual void OnAlgoDisconnected(int reason);
	virtual void OnAlgoConnected();
	virtual void OnQueryStrategy(XTPStrategyInfoStruct* strategy_info, char* strategy_param, XTPRI *error_info, int32_t request_id, bool is_last, uint64_t session_id);
	virtual void OnStrategyStateReport(XTPStrategyStateReportStruct* strategy_state, uint64_t session_id);
	virtual void OnALGOUserEstablishChannel(char* user, XTPRI* error_info, uint64_t session_id);
	virtual void OnInsertAlgoOrder(XTPStrategyInfoStruct* strategy_info, XTPRI *error_info, uint64_t session_id);
	virtual void OnCancelAlgoOrder(XTPStrategyInfoStruct* strategy_info, XTPRI *error_info, uint64_t session_id);
	

private:

	bool IsErrorRspInfo(XTPRI *pRspInfo);

	//初始化落盘文件
	void InitOutputFile();
	//关闭落盘文件
	void CloseOutputFile();

private:

	std::ofstream fout_order;
	std::ofstream fout_trade;
	std::ofstream fout_fund;
	std::ofstream fout_position;
	std::ofstream fout_qry_order;
	std::ofstream fout_qry_trade;
	std::ofstream fout_cancel_order;
	std::ofstream fout_position_count;

	bool save_to_file_;//是否将回报数据落盘文件的标志
	bool ping_pang_flag_;//是否进行乒乓测试的标志

	XTP::API::TraderApi* pUserApi;

};