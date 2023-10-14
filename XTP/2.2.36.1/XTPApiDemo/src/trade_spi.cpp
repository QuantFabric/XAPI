#include "trade_spi.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#ifndef _WIN32
#include <sys/time.h>
#include <unistd.h>
#else
#include <windows.h>
#endif
#include <sstream>
#include <map>
#include "FileUtils.h"

using namespace std;

extern bool is_connected_;
extern std::string trade_server_ip;
extern int trade_server_port;
extern std::map<uint64_t, uint64_t> map_session;
extern uint64_t* session_arrary;
extern FileUtils* fileUtils;
extern XTPOrderInsertInfo* orderList;

MyTraderSpi::MyTraderSpi()
{

	InitOutputFile();

	save_to_file_ = false;
	ping_pang_flag_ = false;
}

MyTraderSpi::~MyTraderSpi()
{
	CloseOutputFile();
}

void MyTraderSpi::OnDisconnected(uint64_t session_id, int reason)
{
	cout << "-------------------- OnDisconnected -------------------------" << endl;
	uint64_t aid = 0;
	std::map<uint64_t, uint64_t>::iterator pos = map_session.find(session_id);
	if (pos != map_session.end())
	{
		aid = pos->second;
		map_session.erase(pos);
	}

	//断线后，等待3s，再重新连接
	is_connected_ = false;
	uint64_t temp_session_id_ = 0;
	do
	{
#ifdef _WIN32
		Sleep(3000);
#else
		sleep(3);
#endif // WIN32
		std::string account_name = fileUtils->stdStringForKey("account[%d].user", aid);
		std::string account_pw = fileUtils->stdStringForKey("account[%d].password", aid);
		temp_session_id_ = pUserApi->Login(trade_server_ip.c_str(), trade_server_port, account_name.c_str(), account_pw.c_str(), XTP_PROTOCOL_TCP);

	} while (temp_session_id_ == 0);

	//重新登录成功后更新映射关系
	map_session.insert(std::make_pair(temp_session_id_, aid));
	is_connected_ = true;
	session_arrary[aid] = temp_session_id_;
}

void MyTraderSpi::OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id)
{
	if (save_to_file_)
	{
#ifdef _WIN32
		SYSTEMTIME wtm;
		GetLocalTime(&wtm);
		fout_order << "[" << wtm.wHour << ":" << wtm.wMinute << ":" << wtm.wSecond << "." << wtm.wMilliseconds << "],";
#else
		struct timeval start;
		gettimeofday(&start, 0);
		struct tm *ptr;
		time_t lt;
		lt = time(NULL);
		ptr = localtime(&lt);
		fout_order << "[" << ptr->tm_hour << ":" << ptr->tm_min << ":" << ptr->tm_sec << "." << start.tv_usec << "],";
#endif // _WIN32

		fout_order << "xtp_id:" << order_info->order_xtp_id << ",client_id:" << order_info->order_client_id << ",status:" << order_info->order_status << ",cancel_xtp_id:" << order_info->order_cancel_xtp_id << ",cancel_client_id:" << order_info->order_cancel_client_id;
		fout_order << ",order_submit_status:" << order_info->order_submit_status << ",ticker:" << order_info->ticker << ",market:" << order_info->market << ",price:" << order_info->price;
		fout_order << ",quantity:" << order_info->quantity << ",price_type:" << order_info->price_type << ",side:" << (int)(order_info->side) << ",qty_traded:" << order_info->qty_traded << ",qty_left:" << order_info->qty_left;
		fout_order << ",insert_time:" << order_info->insert_time << ",update_time:" << order_info->update_time << ",cancel_time:" << order_info->cancel_time << ",trade_amount:" << order_info->trade_amount;
		fout_order << ",position_effect:" << (int)(order_info->position_effect) << ",business_type:" << order_info->business_type;
		fout_order << ",order_local_id:" << order_info->order_local_id << ",order_type:" << order_info->order_type << ",error_id:" << error_info->error_id << ",error_msg:" << error_info->error_msg << endl;
	}

	//检测demo是否开启乒乓报单测试，如果开启则继续后续逻辑，否则将只报一单
	if (!ping_pang_flag_)
	{
		return;
	}

	//此后为乒乓报单测试逻辑
	//根据报单响应情况来处理，当不是最终状态时，发起撤单，如果是最终状态，就再下一单
	switch (order_info->order_status)
	{
	case XTP_ORDER_STATUS_NOTRADEQUEUEING:
	{
		pUserApi->CancelOrder(order_info->order_xtp_id, session_id);
		break;
	}
	case XTP_ORDER_STATUS_ALLTRADED:
	case XTP_ORDER_STATUS_PARTTRADEDNOTQUEUEING:
	case XTP_ORDER_STATUS_CANCELED:
	case XTP_ORDER_STATUS_REJECTED:
	{
		int i = order_info->order_client_id;
		pUserApi->InsertOrder(&(orderList[i]), session_id);
		break;
	}

	default:
		break;
	}


}

void MyTraderSpi::OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id)
{
	if (save_to_file_)
	{
#ifdef _WIN32
		SYSTEMTIME wtm;
		GetLocalTime(&wtm);
		fout_trade << "[" << wtm.wHour << ":" << wtm.wMinute << ":" << wtm.wSecond << "." << wtm.wMilliseconds << "],";
#else
		struct timeval start;
		gettimeofday(&start, 0);
		struct tm *ptr;
		time_t lt;
		lt = time(NULL);
		ptr = localtime(&lt);
		fout_trade << "[" << ptr->tm_hour << ":" << ptr->tm_min << ":" << ptr->tm_sec << "." << start.tv_usec << "],";
#endif // _WIN32
		fout_trade << "xtp_id:" << trade_info->order_xtp_id << ",client_id:" << trade_info->order_client_id;
		fout_trade << ",ticker:" << trade_info->ticker << ",market:" << trade_info->market << ",price:" << trade_info->price;
		fout_trade << ",quantity:" << trade_info->quantity << ",side:" << (int)(trade_info->side) << ",trade_time:" << trade_info->trade_time << ",trade_amount:" << trade_info->trade_amount;
		fout_trade << ",position_effect:" << (int)(trade_info->position_effect) << ",business_type:" << trade_info->business_type;
		fout_trade << ",exec_id:" << trade_info->exec_id << ",report_index:" << trade_info->report_index << ",order_exch_id:" << trade_info->order_exch_id;
		fout_trade << ",trade_type:" << trade_info->trade_type << ",branch_pbu:" << trade_info->branch_pbu << endl;
	}


}

void MyTraderSpi::OnCancelOrderError(XTPOrderCancelInfo * cancel_info, XTPRI * error_info, uint64_t session_id)
{
	if (save_to_file_)
	{
		fout_cancel_order << "cancel_order_xtp_id:" << cancel_info->order_cancel_xtp_id << ",order_xtp_id:" << cancel_info->order_xtp_id << ",error_id:" << error_info->error_id << ",msg:" << error_info->error_msg << endl;
	}
}

void MyTraderSpi::OnQueryOrderEx(XTPOrderInfoEx *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id)
{
	if (error_info && error_info->error_id != 0)
	{
		//查询出错
		if (error_info->error_id == 11000350)
		{
			//账户没有下过订单
			cout << "------------------- No Order.-----------" << endl;
		}
		else
		{
			//真正的出错
		}
		return;
	}

	if (save_to_file_)
	{
		fout_qry_order << "xtp_id:" << order_info->order_xtp_id << ",client_id:" << order_info->order_client_id << ",status:" << order_info->order_status << ",cancel_xtp_id:" << order_info->order_cancel_xtp_id << ",cancel_client_id:" << order_info->order_cancel_client_id;
		fout_qry_order << ",order_submit_status:" << order_info->order_submit_status << ",ticker:" << order_info->ticker << ",market:" << order_info->market << ",price:" << order_info->price;
		fout_qry_order << ",quantity:" << order_info->quantity << ",price_type:" << order_info->price_type << ",side:" << (int)(order_info->side) << ",qty_traded:" << order_info->qty_traded << ",qty_left:" << order_info->qty_left;
		fout_qry_order << ",insert_time:" << order_info->insert_time << ",update_time:" << order_info->update_time << ",cancel_time:" << order_info->cancel_time << ",trade_amount:" << order_info->trade_amount;
		fout_qry_order << ",position_effect:" << (int)(order_info->position_effect) << ",business_type:" << order_info->business_type;
		fout_qry_order << ",order_local_id:" << order_info->order_local_id << ",order_type:" << order_info->order_type <<",error_id:" << order_info->order_err_t.error_id << ",error_msg:" << order_info->order_err_t.error_msg << endl;
	}
}

void MyTraderSpi::OnQueryTrade(XTPQueryTradeRsp * trade_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
	if (error_info && error_info->error_id != 0)
	{
		//查询出错
		if (error_info->error_id == 11000350)
		{
			//账户没有成交
			cout << "------------------- No Transaction Record.-----------" << endl;
		}
		else
		{
			//真正的出错
		}
		return;
	}


	if (save_to_file_)
	{
		fout_qry_trade << "xtp_id:" << trade_info->order_xtp_id << ",client_id:" << trade_info->order_client_id;
		fout_qry_trade << ",ticker:" << trade_info->ticker << ",market:" << trade_info->market << ",price:" << trade_info->price;
		fout_qry_trade << ",quantity:" << trade_info->quantity << ",side:" << trade_info->side << ",trade_time:" << trade_info->trade_time << ",trade_amount:" << trade_info->trade_amount;
		fout_qry_trade << ",exec_id:" << trade_info->exec_id << ",report_index:" << trade_info->report_index << ",order_exch_id:" << trade_info->order_exch_id;
		fout_qry_trade << ",trade_type:" << trade_info->trade_type << ",branch_pbu:" << trade_info->branch_pbu << endl;
	}
}

void MyTraderSpi::OnQueryPosition(XTPQueryStkPositionRsp * investor_position, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
	if (error_info && error_info->error_id !=0)
	{
		//查询出错
		if (error_info->error_id == 11000350)
		{
			//账户里没有持仓，不算真正的错误
			cout << "------------------- Position is empty.-----------" << endl;
		}
		else
		{
			//真正的出错
		}
		return;
	}


	if (save_to_file_)
	{
		fout_position << "request_id:" << request_id << ",is_last:" << is_last << ",";
		fout_position << "ticker:" << investor_position->ticker << ",ticker_name:" << investor_position->ticker_name;
		fout_position << ",total_qty:" << investor_position->total_qty << ",sellable_qty:" << investor_position->sellable_qty << ",avg_price:" << investor_position->avg_price;
		fout_position << ",unrealized_pnl:" << investor_position->unrealized_pnl << endl;
	}
}

void MyTraderSpi::OnQueryAsset(XTPQueryAssetRsp * trading_account, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
	if (save_to_file_)
	{
		fout_fund << "request_id:" << request_id << ",total_asset:" << setprecision(14) << trading_account->total_asset << ",security_asset:" << setprecision(16) << trading_account->security_asset;
		fout_fund << ",buying_power:" << setprecision(16) << trading_account->buying_power << ",fund_buy_amount:" << setprecision(16) << trading_account->fund_buy_amount;
		fout_fund << ",fund_buy_fee:" << setprecision(16) << trading_account->fund_buy_fee << ",fund_sell_amount:" << setprecision(16) << trading_account->fund_sell_amount << ",fund_sell_fee:" << setprecision(16) << trading_account->fund_sell_fee << endl;
	}
}

void MyTraderSpi::OnQueryStructuredFund(XTPStructuredFundInfo * fund_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryFundTransfer(XTPFundTransferNotice * fund_transfer_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
	if (error_info && error_info->error_id != 0)
	{
		//查询出错
		if (error_info->error_id == 11000350)
		{
			//没有资金划拨记录，不算真正的错误
		}
		else
		{
			//真正的出错
		}
		return;
	}
}

void MyTraderSpi::OnFundTransfer(XTPFundTransferNotice * fund_transfer_info, XTPRI * error_info, uint64_t session_id)
{
	//资金划拨的响应通知

}

void MyTraderSpi::OnQueryETF(XTPQueryETFBaseRsp * etf_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryETFBasket(XTPQueryETFComponentRsp * etf_component_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryIPOInfoList(XTPQueryIPOTickerRsp * ipo_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp * quota_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp * option_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnCreditCashRepay(XTPCrdCashRepayRsp * cash_repay_info, XTPRI * error_info, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo * cash_repay_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditFundInfo(XTPCrdFundInfo * fund_info, XTPRI * error_info, int request_id, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditDebtInfo(XTPCrdDebtInfo * debt_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo * debt_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI * error_info, int request_id, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo * assign_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
}

void MyTraderSpi::OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo * stock_info, XTPRI * error_info, int request_id, uint64_t session_id)
{
}


bool MyTraderSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}

void MyTraderSpi::InitOutputFile()
{
	std::string orderName = "./log/";
	std::string tradeName = "./log/";
	std::string fundName = "./log/";
	std::string positonName = "./log/";
	std::string qryOrderName = "./log/";
	std::string qryTradeName = "./log/";
	std::string cancelOrderName = "./log/";
	std::string positionCountName = "./log/";

	std::string pre;
	stringstream ss;
#ifndef _WIN32
	struct timeval start;
	gettimeofday(&start, 0);
	ss << start.tv_sec;
#else
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	ss << wtm.wDay << wtm.wHour << wtm.wMinute << wtm.wSecond;
#endif
	ss >> pre;

	orderName.append(pre);
	tradeName.append(pre);
	fundName.append(pre);
	positonName.append(pre);
	qryOrderName.append(pre);
	qryTradeName.append(pre);
	cancelOrderName.append(pre);
	positionCountName.append(pre);

	orderName.append("order.txt");
	tradeName.append("tradeReport.txt");
	fundName.append("fund.txt");
	positonName.append("stock_position.txt");
	qryOrderName.append("qry_order.txt");
	qryTradeName.append("qry_tradeReport.txt");
	cancelOrderName.append("cancel_order.txt");
	positionCountName.append("qry_positionCount.txt");

	fout_order.open(orderName.c_str());
	fout_trade.open(tradeName.c_str());
	fout_fund.open(fundName.c_str());
	fout_position.open(positonName.c_str());
	fout_qry_order.open(qryOrderName.c_str());
	fout_qry_trade.open(qryTradeName.c_str());
	fout_cancel_order.open(cancelOrderName.c_str());
	fout_position_count.open(positionCountName.c_str());
}

void MyTraderSpi::CloseOutputFile()
{
	fout_order.close();
	fout_trade.close();
	fout_fund.close();
	fout_position.close();
	fout_qry_order.close();
	fout_qry_trade.close();
	fout_cancel_order.close();
	fout_position_count.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///-------------------------------------以下为算法AlgoX相关部分-------------------------------------------------------------------------------------///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MyTraderSpi::OnAlgoDisconnected(int reason)
{
	cout << "------------------- OnAlgoDisconnected-----------" << endl;
	/// 与算法服务器断线，此时api会自动与算法服务器重连，无需用户重连
}

void MyTraderSpi::OnAlgoConnected()
{
	cout << "------------------- OnAlgoConnected-----------" << endl;
	/// 与算法服务器重新建立起连接，仅在断连重连成功后通知
}

void MyTraderSpi::OnQueryStrategy(XTPStrategyInfoStruct* strategy_info, char* strategy_param, XTPRI *error_info, int32_t request_id, bool is_last, uint64_t session_id)
{
	cout << "------------------- OnQueryStrategy-----------" << endl;
	/// 算法单查询结果通知
	if (error_info->error_id != 0)
	{
		std::cout << "query strategy failed: " << error_info->error_id << error_info->error_msg << std::endl;
		return;
	}

	std::cout << "request_id:" << request_id << ",is_last:" << is_last;
	std::cout << ",strategy:" << strategy_info->m_xtp_strategy_id << ", client id:" << strategy_info->m_client_strategy_id << ", type:" << strategy_info->m_strategy_type << ", status:" << strategy_info->m_strategy_state;//<< std::endl;
	std::cout << ",strategy_param:" << strategy_param << endl;


}

void MyTraderSpi::OnStrategyStateReport(XTPStrategyStateReportStruct * strategy_state, uint64_t session_id)
{
	cout << "------------------- OnStrategyStateReport-----------" << endl;
	
}

void MyTraderSpi::OnALGOUserEstablishChannel(char* user, XTPRI* error_info, uint64_t session_id)
{
	cout << "------------------- OnALGOUserEstablishChannel-----------" << endl;
	/// 建立算法通道的异步通知
	if (error_info->error_id == 0)
	{
		/// 建立算法通道成功后，可以下算法母单
		std::cout << user << " establish channel success." << std::endl;

		/// 读取算法单的参数
		int strategy_type = fileUtils->intForKey("strategy.type");
		int strategy_client_id = fileUtils->intForKey("strategy.client_id");
		std::string strategy_param = fileUtils->stdStringForKey("strategy.param");

		/// 发送算法单
		std::cout << "Begin to insert algo order." << std::endl;
		int ret = pUserApi->InsertAlgoOrder(strategy_type, strategy_client_id, (char*)strategy_param.c_str(), session_id);
		if (ret == 0)
		{
			std::cout <<"Insert algo order send success." << std::endl;
		}
		else
		{
			std::cout << "Failed to insert algo order." << std::endl;
			XTPRI* error_info = pUserApi->GetApiLastError();
			std::cout << "error id: " << error_info->error_id << " error msg: " << error_info->error_msg << std::endl;
		}

	}
	else
	{
		std::cout << user << " verification failed." << std::endl;
	}
}

void MyTraderSpi::OnInsertAlgoOrder(XTPStrategyInfoStruct * strategy_info, XTPRI * error_info, uint64_t session_id)
{
	cout << "------------------- OnInsertAlgoOrder-----------" << endl;
	/// 发送算法单后的异步通知
	if (error_info->error_id != 0)
	{
		std::cout << "Insert algo order failed: " << error_info->error_id << ", "<< error_info->error_msg << std::endl;
		return;
	}

	/// 算法单建立成功
	cout << "Insert algo order success." << endl;
	cout << "strategy:" << strategy_info->m_xtp_strategy_id << ", client id:" << strategy_info->m_client_strategy_id << ", type:" << strategy_info->m_strategy_type << ", status:" << (strategy_info->m_strategy_state - 0) << std::endl;

	/// 需要撤销算法单的时候，可以发送撤销算法单消息
	std::cout << "Begin to cancel algo order." << std::endl;
	int ret = pUserApi->CancelAlgoOrder(true, strategy_info->m_xtp_strategy_id, session_id);
	if (ret == 0)
	{
		std::cout << "Cancel algo order send success." << std::endl;
	}
	else
	{
		std::cout << "Failed to send cancel algo order." << std::endl;
		XTPRI* error_info = pUserApi->GetApiLastError();
		std::cout << "error id: " << error_info->error_id << " error msg: " << error_info->error_msg << std::endl;
	}
}

void MyTraderSpi::OnCancelAlgoOrder(XTPStrategyInfoStruct * strategy_info, XTPRI * error_info, uint64_t session_id)
{
	cout << "------------------- OnCancelAlgoOrder-----------" << endl;
	/// 算法单撤销结果通知
	if (error_info->error_id != 0)
	{
		std::cout << "Cancel algo order failed: " << error_info->error_id << ", " << error_info->error_msg << std::endl;
		return;
	}

	cout << "Cancel algo order success." << endl;
	cout << "strategy:" << strategy_info->m_xtp_strategy_id << ", client id:" << strategy_info->m_client_strategy_id << ", type:" << strategy_info->m_strategy_type << ", status:" << (strategy_info->m_strategy_state-0) << std::endl;

}