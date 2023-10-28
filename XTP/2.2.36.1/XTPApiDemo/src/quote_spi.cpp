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
	//���ߺ󣬿�����������
	//�������ӳɹ�����Ҫ���������������������
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
		//�д�����
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
		//�д�����
		return;
	}
}

void MyQuoteSpi::OnRebuildQuoteServerDisconnected(int reason)
{
	//�벻Ҫ��ʱ�䱣����ز������������ӣ�������Ҫʱ���ӣ��������������߼�������¼����
}

void MyQuoteSpi::OnRequestRebuildQuote(XTPQuoteRebuildResultRsp * rebuild_result)
{
	//����Ļز������Ƿ��Ѿ���ȫ�ز��꣬���û����ȫ�Ļ��������ٴη�������
	switch (rebuild_result->result_code)
	{
	case XTP_REBUILD_RET_COMPLETE:
	{
		//��ʱ�ز�������ȫ
	}
		break;
	case XTP_REBUILD_RET_PARTLY:
	{
		//��ʱ�ز����ݲ���������Ҫ�ٴη�������
	}
		break;
	case XTP_REBUILD_RET_NO_DATA:
	{
		//��ʱ������Ҳû�лز����ݣ���ʱ���ܷ�����Ҳȱ�����ݣ���Ҫ�ȴ�һ��������󿴿�
	}
		break;
	case XTP_REBUILD_RET_PARAM_ERR:
	{
		//��ʱ����Ļز����ݲ�ѯ����������Ҫ����ѯ�����Ƿ���ȷ
	}
		break;
	case XTP_REBUILD_RET_FREQUENTLY:
	{
		//��ʱ�ز�����������Ϊ����̫Ƶ����������������Ƶ���뽵������Ƶ�ʻ��ߵȴ�һ���������
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
	// ���ErrorID != 0, ˵���յ��˴������Ӧ
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}
