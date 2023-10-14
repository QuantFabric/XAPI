#include "quote_spi.h"
#include <iostream>
#include <stdio.h>
using namespace std;

MyQuoteSpi::MyQuoteSpi()
{
}

MyQuoteSpi::~MyQuoteSpi()
{
}

void MyQuoteSpi::OnDisconnected(int reason)
{
	cout << "--->>> " << "OnDisconnected quote" << endl;
	cout << "--->>> Reason = " << reason << endl;
	//断线后，可以重新连接
	//重新连接成功后，需要重新向服务器发起订阅请求
}

void MyQuoteSpi::OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last)
{
 	cout << "OnRspSubMarketData -----" << endl;
}

void MyQuoteSpi::OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last)
{
 	cout << "OnRspUnSubMarketData -----------" << endl;
}

void MyQuoteSpi::OnDepthMarketData(XTPMD * market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count)
{
}

void MyQuoteSpi::OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last)
{

}

void MyQuoteSpi::OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last)
{

}

void MyQuoteSpi::OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last)
{

}

void MyQuoteSpi::OnUnSubTickByTick(XTPST * ticker, XTPRI * error_info, bool is_last)
{
}

void MyQuoteSpi::OnOrderBook(XTPOB *order_book)
{

}

void MyQuoteSpi::OnTickByTick(XTPTBT *tbt_data)
{

}

void MyQuoteSpi::OnQueryAllTickers(XTPQSI * ticker_info, XTPRI * error_info, bool is_last)
{
	cout << "OnQueryAllTickers -----------" << endl;
	if (IsErrorRspInfo(error_info))
	{
		//有错误发生
		return;
	}
}

void MyQuoteSpi::OnQueryTickersPriceInfo(XTPTPI * ticker_info, XTPRI * error_info, bool is_last)
{
}

void MyQuoteSpi::OnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnUnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI * error_info)
{
}

void MyQuoteSpi::OnQueryAllTickersFullInfo(XTPQFI * ticker_info, XTPRI * error_info, bool is_last)
{
	if (IsErrorRspInfo(error_info))
	{
		//有错误发生
		return;
	}
}

void MyQuoteSpi::OnRebuildQuoteServerDisconnected(int reason)
{
	//请不要长时间保持与回补服务器的连接，仅在需要时连接，不用添加重连逻辑，仅记录即可
}

void MyQuoteSpi::OnRequestRebuildQuote(XTPQuoteRebuildResultRsp * rebuild_result)
{
	//请求的回补数据是否已经完全回补完，如果没有完全的话，可以再次发起请求
	switch (rebuild_result->result_code)
	{
	case XTP_REBUILD_RET_COMPLETE:
	{
		//此时回补数据完全
	}
		break;
	case XTP_REBUILD_RET_PARTLY:
	{
		//此时回补数据不完整，需要再次发起请求
	}
		break;
	case XTP_REBUILD_RET_NO_DATA:
	{
		//此时服务器也没有回补数据，此时可能服务器也缺少数据，需要等待一会儿再请求看看
	}
		break;
	case XTP_REBUILD_RET_PARAM_ERR:
	{
		//此时请求的回补数据查询参数错误，需要检查查询参数是否正确
	}
		break;
	case XTP_REBUILD_RET_FREQUENTLY:
	{
		//此时回补数据请求因为请求太频繁，而被服务器限频，请降低请求频率或者等待一会儿再请求
	}
		break;
	default:
		break;
	}
}

void MyQuoteSpi::OnRebuildTickByTick(XTPTBT * tbt_data)
{
}

void MyQuoteSpi::OnRebuildMarketData(XTPMD * md_data)
{
}

bool MyQuoteSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}

