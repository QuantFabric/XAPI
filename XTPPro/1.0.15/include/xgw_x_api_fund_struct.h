/////////////////////////////////////////////////////////////////////////
///@author 中泰证券股份有限公司
///@file xgw_x_api_fund_struct.h
///@brief 定义资金划拨相关结构体类型
/////////////////////////////////////////////////////////////////////////
#ifndef XGW_NG_API_FUND_STRUCT_H_
#define XGW_NG_API_FUND_STRUCT_H_

#include "xtrade_x_api_data_type.h"

#pragma pack(push)
#pragma pack(1)

namespace XTPX {

	namespace API {
		
		/////////////////////////////////////////////////////////////////////////
		///用户资金划转请求结构体
		/////////////////////////////////////////////////////////////////////////
		struct XTPFundTransferReq
		{
			///资金内转编号，无需用户填写，类似于xtp_id
			uint64_t    serial_id;
			///资金账户代码
			char        fund_account[XTP_ACCOUNT_NAME_LEN];
			///金额
			double      amount;
			///内转类型
			XTP_FUND_TRANSFER_TYPE    transfer_type;
			///转入或转出的目标服务器对应的节点类型（双中心用户跨节点划拨时必填）
			XTP_TRANSFER_SITE_TYPE    site;
			///货币种类
			XTP_CURRENCY_TYPE        currency_type; 
			///预留字段
			char                     unused[4];
		};
		
		/////////////////////////////////////////////////////////////////////////
		///资金内转流水通知
		/////////////////////////////////////////////////////////////////////////
		struct XTPFundTransferNotice
		{
			///资金内转编号
			uint64_t                serial_id;
			///金额
			double	                amount;
			///内转类型
			XTP_FUND_TRANSFER_TYPE  transfer_type;
			///操作结果 
			XTP_FUND_OPER_STATUS    oper_status;
			///操作时间
			uint64_t	            transfer_time;
			///转入或转出的目标服务器对应的节点类型
			XTP_TRANSFER_SITE_TYPE  site;
			///货币种类
			XTP_CURRENCY_TYPE       currency_type;
		
		};
		
		/////////////////////////////////////////////////////////////////////////
		///用户资金划转请求的响应-复用资金通知结构体
		/////////////////////////////////////////////////////////////////////////
		typedef struct XTPFundTransferNotice XTPFundTransferAck;
		
		/////////////////////////////////////////////////////////////////////////
		///用户资金查询请求结构体
		/////////////////////////////////////////////////////////////////////////
		struct XTPFundQueryReq
		{
			///资金账户代码
			char        fund_account[XTP_ACCOUNT_NAME_LEN];
			///查询类型
			XTP_FUND_QUERY_TYPE    query_type;
			///需要查询的服务器对应的节点类型（双中心用户查询时必填）
			XTP_TRANSFER_SITE_TYPE query_site;
			///货币种类
			XTP_CURRENCY_TYPE      currency_type;
			///预留字段
			char                   unused[4];
		
		};
		
		/////////////////////////////////////////////////////////////////////////
		///用户资金查询响应结构体
		/////////////////////////////////////////////////////////////////////////
		struct XTPFundQueryRsp
		{
			///金额
			double        amount;
			///查询类型
			XTP_FUND_QUERY_TYPE    query_type;
			///对应的交易市场
			XTP_TRANSFER_SITE_TYPE query_site;
			///货币种类
			XTP_CURRENCY_TYPE      currency_type;
			///预留字段
			char                   unused[4];
		
		};
		
		/////////////////////////////////////////////////////////////////////////
		///根据内转编号查询资金内转流水
		/////////////////////////////////////////////////////////////////////////
		struct XTPQueryFundTransferLogReq {
			///资金内转编号
			uint64_t    serial_id;
		
		};
		
		/////////////////////////////////////////////////////////////////////////
		///资金内转流水记录结构体
		/////////////////////////////////////////////////////////////////////////
		typedef struct XTPFundTransferNotice XTPFundTransferLog;
		
		
		/////////////////////////////////////////////////////////////////////////
		///分页查询资金内转流水
		/////////////////////////////////////////////////////////////////////////
		struct XTPQueryFundTransferByPageReq
		{
			///需要查询的资金流水条数
			int64_t         req_count;
			///上一次收到的查询结果中带回来的索引，如果是从头查询，请置0
			int64_t         reference;
			///保留字段
			int64_t         reserved;
		};
		
	}//API
}//XTPX

#pragma pack(pop)

#endif