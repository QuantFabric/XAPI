/////////////////////////////////////////////////////////////////////////
///@author 中泰证券股份有限公司
///@file xgw_x_api_query_struct.h
///@brief 定义交易类查询相关数据结构
/////////////////////////////////////////////////////////////////////////
#ifndef _XGW_NG_API_QUERY_STRUCT_H_
#define _XGW_NG_API_QUERY_STRUCT_H_

#include "xoms_x_api_struct.h"

#pragma pack(push)
#pragma pack(1)

namespace XTPX {

	namespace API {
		
		//////////////////////////////////////////////////////////////////////////
		///报单查询
		//////////////////////////////////////////////////////////////////////////
		///报单查询请求-条件查询
		struct XTPQueryOrderReq
		{
			///证券代码，可以为空，如果为空，则默认查询时间段内的所有成交回报
			char      ticker[XTP_TICKER_LEN];
			///格式为YYYYMMDDHHMMSSsss，为0则默认当前交易日0点
			int64_t   begin_time;
			///格式为YYYYMMDDHHMMSSsss，为0则默认当前时间
			int64_t   end_time;  
		};
		
		///报单查询响应结构体
		typedef struct XTPOrderInfo XTPQueryOrderRsp;
		
		
		///查询订单请求-分页查询
		struct XTPQueryOrderByPageReq
		{
			///需要查询的订单条数
			int64_t         req_count;
			///上一次收到的查询订单结果中带回来的索引，如果是从头查询，请置0
			int64_t         reference;
			///保留字段
			int64_t         reserved;
		};
		
		//////////////////////////////////////////////////////////////////////////
		///成交回报查询
		//////////////////////////////////////////////////////////////////////////
		///查询成交报告请求-根据执行编号查询（保留字段）
		struct XTPQueryReportByExecIdReq
		{
			///XTP订单系统ID
			uint64_t  order_xtp_id;  
			///成交执行编号
			char      exec_id[XTP_EXEC_ID_LEN];
			/// 预留
			char      unused[6];
		};
		
		///查询成交回报请求-查询条件
		struct XTPQueryTraderReq
		{
			///证券代码，可以为空，如果为空，则默认查询时间段内的所有成交回报
			char      ticker[XTP_TICKER_LEN];
			///开始时间，格式为YYYYMMDDHHMMSSsss，为0则默认当前交易日0点
			int64_t   begin_time; 
			///结束时间，格式为YYYYMMDDHHMMSSsss，为0则默认当前时间
			int64_t   end_time;  
		};
		
		///成交回报查询响应结构体
		typedef struct XTPTradeReport  XTPQueryTradeRsp;
		
		///查询成交回报请求-分页查询
		struct XTPQueryTraderByPageReq
		{
			///需要查询的成交回报条数
			int64_t         req_count;
			///上一次收到的查询成交回报结果中带回来的索引，如果是从头查询，请置0
			int64_t         reference;
			///保留字段
			int64_t         reserved;
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询股卡情况--响应结构体
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryAccountIdRsp
		{
			///交易市场
			XTP_MARKET_TYPE     market;
			///证券账户（股卡）
			char                account_id[XTP_ACCOUNT_ID_LEN];
			/// 主股东账户标识
			bool                is_main_account;
			/// 预留
			char                unused[2];
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票持仓情况请求结构体
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryStkPositionReq
		{
			///证券代码
			char                ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE     market;
			///证券账户（股卡）
			char                account_id[XTP_ACCOUNT_ID_LEN];
			/// 预留
			char                unused[3];
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票持仓情况
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryStkPositionRsp
		{
			///证券代码
			char                ticker[XTP_TICKER_LEN];
			///证券名称
			char                ticker_name[XTP_TICKER_NAME_LEN];
			///证券账户（股卡）
			char                account_id[XTP_ACCOUNT_ID_LEN];
			///(保留字段)
			char                unused[3];
			///交易市场
			XTP_MARKET_TYPE     market;
			///总持仓
			int64_t             total_qty;
			///可卖持仓
			int64_t             sellable_qty;
			///持仓成本
			double              avg_price;
			///浮动盈亏（保留字段）
			double              unrealized_pnl;
			///昨日持仓
			int64_t             yesterday_position;
			///今日申购赎回数量（申购和赎回数量不可能同时存在，因此可以共用一个字段）
			int64_t             purchase_redeemable_qty;
		
			//以下为期权用户关心字段
			/// 持仓方向
			XTP_POSITION_DIRECTION_TYPE      position_direction;
			///持仓类型(此字段所有账户都可能用到，可以用来区分股份是否为配售)
			XTP_POSITION_SECURITY_TYPE       position_security_type;
			/// 可行权合约
			int64_t             executable_option;
			/// 可锁定标的
			int64_t             lockable_position;
			/// 可行权标的
			int64_t             executable_underlying;
			/// 已锁定标的
			int64_t             locked_position;
			/// 可用已锁定标的
			int64_t             usable_locked_position;
		
			//以下为现货用户关心字段
			///盈亏成本价
			double             profit_price;
			///买入成本
			double             buy_cost;
			///盈亏成本
			double             profit_cost;
			
			///持仓市值（此字段目前只有期权账户有值，其他类型账户为0）
			double             market_value;
			///义务仓占用保证金（此字段目前只有期权账户有值，其他类型账户为0）
			double             margin;
			
			///昨日买入成本
			double             last_buy_cost;
			///昨日盈亏成本
			double             last_profit_cost;
		
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票ETF合约基本情况--请求结构体,
		///请求参数为多条件参数:1,不填则返回所有市场的ETF合约信息。
		///                  2,只填写market,返回该交易市场下结果
		///                   3,填写market及ticker参数,只返回该etf信息。
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryETFBaseReq
		{
			///交易市场
			XTP_MARKET_TYPE    market;
			///ETF买卖代码
			char               ticker[XTP_TICKER_LEN];
			/// 预留
			char               unused[4];    
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票ETF合约基本情况--响应结构体
		//////////////////////////////////////////////////////////////////////////
		typedef struct XTPQueryETFBaseRsp
		{
			XTP_MARKET_TYPE     market;                             ///<交易市场
			char                etf[XTP_TICKER_LEN];                ///<etf代码,买卖,申赎统一使用该代码
			char                subscribe_redemption_ticker[XTP_TICKER_LEN];    ///<etf申购赎回代码
			int32_t             unit;                               ///<最小申购赎回单位对应的ETF份数,例如上证"50ETF"就是900000
			int32_t             subscribe_status;                   ///<是否允许申购,1-允许,0-禁止
			int32_t             redemption_status;                  ///<是否允许赎回,1-允许,0-禁止
			double              max_cash_ratio;                     ///<最大现金替代比例,小于1的数值   TODO 是否采用double
			double              estimate_amount;                    ///<T日预估金额差额
			double              cash_component;                     ///<T-X日现金差额
			double              net_value;                          ///<基金单位净值
			double              total_amount;                       ///<最小申赎单位净值总金额=net_value*unit
		}XTPQueryETFBaseRsp;
		
		
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票ETF合约成分股信息--请求结构体,请求参数为:交易市场+ETF买卖代码
		//////////////////////////////////////////////////////////////////////////
		typedef struct XTPQueryETFComponentReq
		{
			///ETF买卖代码
			char               ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE    market;
			/// 预留
			char               unused[4]; 
		}XTPQueryETFComponentReq;
		
		
		//////////////////////////////////////////////////////////////////////////
		///查询股票ETF成分股信息--响应结构体
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryETFComponentRsp
		{
			///ETF代码
			char                ticker[XTP_TICKER_LEN];
			///成份股代码
			char                component_ticker[XTP_TICKER_LEN];
			///成份股名称
			char                component_name[XTP_TICKER_NAME_LEN];
			///成份股数量
			int64_t             quantity;
			///交易市场
			XTP_MARKET_TYPE     market;
			///成份股交易市场
			XTP_MARKET_TYPE     component_market;
			///溢价比例
			double              premium_ratio;
			///成分股替代标识为必须现金替代时候的总金额
			double              amount;
			///申购溢价比例
			double              creation_premium_ratio;
			///赎回溢价比例
			double              redemption_discount_ratio;
			///申购时，成分股替代标识为必须现金替代时候的总金额
			double              creation_amount;
			///赎回时，成分股替代标识为必须现金替代时候的总金额
			double              redemption_amount;
			///成份股替代标识
			ETF_REPLACE_TYPE    replace_type;
			/// 预留
			char                unused[4];
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询债转股信息-------请求结构体
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryBondSwapStockReq
		{
			// 证券代码
			char               ticker[XTP_TICKER_LEN];
			// 交易市场
			XTP_MARKET_TYPE    market;
			/// 预留
			char               unused[4];   
		};
		
		//////////////////////////////////////////////////////////////////////////
		///查询债转股信息-------响应结构体
		//////////////////////////////////////////////////////////////////////////
		typedef struct XTPQueryBondSwapStockRsp
		{
			char              ticker[XTP_TICKER_LEN];// 债券证券代码
			char              underlying_ticker[XTP_TICKER_LEN];// 转股后的股票证券代码
			XTP_MARKET_TYPE   market;// 交易市场
			int32_t           unit;// 转换数量单位（张）
			int64_t           qty_min;// 最小下单量（张）
			int64_t           qty_max;// 最大下单量（张）
			double            swap_price;// 转股价格
			int32_t           swap_flag;// 是否处于转股期；0: 不可转股；1：可转股；
			char              unused[4];// 预留
		}XTPQueryBondSwapStockRsp;
		
		//////////////////////////////////////////////////////////////////////////
		///查询当日可申购新股信息
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryIPOTickerRsp {
			///交易市场
			XTP_MARKET_TYPE     market;
			///申购代码
			char                ticker[XTP_TICKER_LEN];
			///申购股票名称
			char                ticker_name[XTP_TICKER_NAME_LEN]; 
			/// 证券类别
			XTP_TICKER_TYPE     ticker_type;
			///申购价格
			double              price;
			///申购单元         
			int32_t             unit;
			///最大允许申购数量
			int32_t             qty_upper_limit;
			///<是否尚未盈利(仅适用创业板股票，创新企业股票及存托凭证)
			bool                is_noprofit;
			///预留
			char                unused[31];
		};
		
		
		//////////////////////////////////////////////////////////////////////////
		///查询用户申购额度-包含创业板额度
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryIPOQuotaRsp {
			///交易市场
			XTP_MARKET_TYPE     market;
			///可申购额度
			int32_t             quantity;
			/// 上海科创板额度
			int32_t             tech_quantity;
			/// 保留
			int32_t             unused;
		};
		
	}//API
}//XTPX

#pragma pack(pop)

#endif //_XGW_NG_API_QUERY_STRUCT_H_

