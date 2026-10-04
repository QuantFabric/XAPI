/////////////////////////////////////////////////////////////////////////
///@author 中泰证券股份有限公司
///@file xoms_x_api_struct.h
///@brief 定义交易类相关数据结构
/////////////////////////////////////////////////////////////////////////
#ifndef _XOMS_NG_API4_STRUCT_H_
#define _XOMS_NG_API4_STRUCT_H_

#include "xtrade_x_api_data_type.h"
#include <stddef.h>

#pragma pack(push)
#pragma pack(1)

namespace XTPX {

	namespace API {

		//=====================客户端接口定义=================================
		///新订单请求
		struct XTPOrderInsertInfo
		{
			///XTP系统订单ID，无需用户填写，在XTP系统中唯一
			uint64_t                order_xtp_id;
			///合约代码 客户端请求不带空格，以'\0'结尾
			char                    ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE         market;
			///报单引用，由客户自定义
			uint32_t                order_client_id;
			///价格
			double                  price;
			///数量(股票单位为股，逆回购单位为张)
			int64_t                 quantity;
			///价格类型
			XTP_PRICE_TYPE          price_type;
			///买卖方向
			XTP_SIDE_TYPE           side;
			///开平标志（期权用户使用）
			XTP_POSITION_EFFECT_TYPE    position_effect;
			///算法策略类型（普通用户不填）
			uint16_t                strategy_type;
			///算法母单编号ID（普通用户不填）
			uint64_t                strategy_id;
			///业务类型
			XTP_BUSINESS_TYPE       business_type;
			/// 证券账户（股卡），非必填字段。不填，默认以主股卡报送；填了，即用指定股卡报送。
			char                    account_id[XTP_ACCOUNT_ID_LEN];
			///交易所PBU代码，非必填字段。不填，以默认席位报送；填了，即用指定席位报送。（通常为券结业务客户使用）
			char                    branch_pbu[XTP_BRANCH_PBU_LEN];
			/// 预留
			char                    unused[4];
		};
		
		
		///撤单请求消息
		struct XTPOrderCancelInfo
		{
			///撤单XTPID
			uint64_t                 order_xtp_id;
			///原始订单XTPID
			uint64_t                 orig_order_xtp_id;
			///撤单引用，由客户自定义
			uint32_t                 order_client_id;
			/// 预留
			char                     unused[4];
		};
		
		///撤单失败回报响应结构体
		struct XTPOrderCancelErrorInfo
		{ 
			///撤单订单号
			uint64_t                order_xtp_id;
			///证券代码
			char                    ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE         market;
			///用户自定义字段
			uint32_t                order_client_id;
			///原单号
			uint64_t                orig_order_xtp_id;
			///回报时间
			uint64_t                transact_time;
			///执行报告编号
			uint64_t                report_index; 
			///平台分区号
			int32_t                 set_id;
			///拒单原因代码
			uint32_t                error_code;
			///外部系统拒单原因代码
			uint32_t                extra_error_code; 
			///原始会员内部订单编号
			char                    orig_order_local_id[XTP_LOCAL_ORDER_LEN];
			///本地报单编号 OMS生成的单号，不等同于order_xtp_id，为服务器传到报盘的单号
			char                    order_local_id[XTP_LOCAL_ORDER_LEN];
			/// 预留
			char                    unused[6];
		
		};
		
		
		///报单响应结构体
		struct XTPOrderInfo
		{
			///订单号
			uint64_t                order_xtp_id;
			///证券代码
			char                    ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE         market;
			///用户自定义字段
			uint32_t                order_client_id;
			///本地报单编号 OMS生成的单号，不等同于order_xtp_id，为服务器传到报盘的单号
			char                    order_local_id[XTP_LOCAL_ORDER_LEN];
			///订单执行状态，与交易所回报ExecType字段一致，‘0’-新订单，‘4’-已撤销，‘8’-已拒绝，‘F’-已成交；如果是非交易所的回报，此字段为0
			char                    exec_type;
			///订单状态
			XTP_ORDER_STATUS_TYPE   order_status;
			///交易所订单编号
			char                    order_exch_id[XTP_ORDER_EXCH_LEN];
			///报单类型
			TXTPOrderTypeType       order_type;
			///买卖方向
			XTP_SIDE_TYPE           side;
			///开平标志
			XTP_POSITION_EFFECT_TYPE    position_effect;
			///报单提交状态，可以用来区分是否是撤单
			XTP_ORDER_SUBMIT_STATUS_TYPE   order_submit_status;
			///订单数量
			int64_t                 quantity;
			///订单价格
			double                  price;
			///价格类型
			XTP_PRICE_TYPE          price_type;
			///业务类型
			XTP_BUSINESS_TYPE       business_type;
			///撤单在XTP系统中的id，在XTP系统中唯一（仅撤单成功时有效，此字段为0则表示没有撤单）
			uint64_t                order_cancel_xtp_id;
			///成交金额，为此订单的成交总金额
			double                  trade_amount;
			///今成交数量，为此订单累计成交数量
			int64_t                 qty_traded;
			///剩余数量
			int64_t                 qty_left;
			///预扣金额，为此订单的预扣金额（包含预扣手续费，此金额不会改变，仅供参考）
			double                  order_withhold_amount;
			///预扣手续费，为此订单的预扣手续费（此金额不会改变，仅供参考）
			double                  order_withhold_fee;
			///执行编号
			char                    exec_id[XTP_EXEC_ID_LEN];
			///算法策略类型，仅为算法单时有效
			uint16_t                strategy_type;
			///平台分区号
			int32_t                 set_id;
			///执行报告编号
			uint64_t                report_index;
			///回报时间
			uint64_t                transact_time;
			///委托时间，格式为YYYYMMDDHHMMSSsss
			uint64_t                insert_time;
			///最后修改时间，格式为YYYYMMDDHHMMSSsss
			uint64_t                update_time;
			///撤销时间，格式为YYYYMMDDHHMMSSsss
			uint64_t                cancel_time;
			///算法母单编号ID，仅为算法单时有效
			uint64_t                strategy_id;
			///XTP拒单原因代码
			uint32_t                error_code;
			///外部系统拒单原因代码
			uint32_t                extra_error_code;
			/// 证券账户（股卡）
			char                    account_id[XTP_ACCOUNT_ID_LEN];
			///交易所PBU代码 
			char                    branch_pbu[XTP_BRANCH_PBU_LEN];
			/// 预留
			char                    unused[8];
		};
		
		typedef struct XTPOrderInfo XTPOrderInfoEx;
		
		
		///报单成交结构体
		struct XTPTradeReport
		{
			///XTP系统订单ID，此成交回报相关的订单ID，在XTP系统中唯一
			uint64_t                 order_xtp_id;
			///合约代码
			char                     ticker[XTP_TICKER_LEN];
			///交易市场
			XTP_MARKET_TYPE          market;
			///报单引用
			uint32_t                 order_client_id; 
			///成交时间，格式为YYYYMMDDHHMMSSsss
			uint64_t                 trade_time;
			///交易所交易员代码 
			char                     branch_pbu[XTP_BRANCH_PBU_LEN];
			///成交类型  --成交回报中的执行类型
			TXTPTradeTypeType        trade_type;
			///本地报单编号 OMS生成的单号，不等同于order_xtp_id，为服务器传到报盘的单号
			char                     order_local_id[XTP_LOCAL_ORDER_LEN];
			///买卖方向
			XTP_SIDE_TYPE            side;
			///业务类型
			XTP_BUSINESS_TYPE        business_type;
			///价格，此次成交的价格
			double                   price;
			///数量，此次成交的数量，不是累计数量
			int64_t                  quantity;
			///成交金额，此次成交的总金额 = price*quantity
			double                   trade_amount;
			///报单编号 --交易所单号
			char                     order_exch_id[XTP_ORDER_EXCH_LEN];
			///开平标志
			XTP_POSITION_EFFECT_TYPE    position_effect;
			///算法策略类型
			uint16_t                 strategy_type;
			///平台分区号
			int32_t                  set_id;
			///成交序号 --回报记录号，对于单个账户来说，深交所每个平台（不同交易品种）唯一，上交所唯一，对于多账户来说，不唯一
			uint64_t                 report_index;
			///算法母单编号ID，仅为算法单时有效
			uint64_t                 strategy_id;
			///成交编号，深交所唯一，上交所每笔交易唯一，当发现2笔成交回报拥有相同的exec_id，则可以认为此笔交易自成交
			char                     exec_id[XTP_EXEC_ID_LEN];
			/// 证券账户（股卡） 
			char                     account_id[XTP_ACCOUNT_ID_LEN];
			///预留字段
			char                     unused[5];
		};
		
		
		//////////////////////////////////////////////////////////////////////////
		///报单查询
		//////////////////////////////////////////////////////////////////////////
		///报单查询响应结构体
		typedef struct XTPOrderInfo XTPQueryOrderRsp;
		
		
		//////////////////////////////////////////////////////////////////////////
		///账户资金查询响应结构体
		//////////////////////////////////////////////////////////////////////////
		struct XTPQueryAssetRsp
		{
			///总资产（现货账户/期权账户参考公式：总资产 = 可用资金 + 证券资产（目前为0）+ 预扣的资金），（信用账户参考公式：总资产 = 可用资金 + 融券卖出所得资金余额 + 证券资产+ 预扣的资金）
			double total_asset;
			///可用资金
			double buying_power;
			///证券资产（保留字段，目前为0）
			double security_asset;
			///累计买入成交证券占用资金（仅限现货账户/期权账户，信用账户暂不可用）
			double fund_buy_amount;
			///累计买入成交交易费用（仅限现货账户/期权账户，信用账户暂不可用）
			double fund_buy_fee;
			///累计卖出成交证券所得资金（仅限现货账户/期权账户，信用账户暂不可用）
			double fund_sell_amount;
			///累计卖出成交交易费用（仅限现货账户/期权账户，信用账户暂不可用）
			double fund_sell_fee;
			///XTP系统预扣的资金（包括买卖股票时预扣的交易资金+预扣手续费）
			double withholding_amount;
		
			///冻结的保证金（仅限期权账户）
			double frozen_margin;
			///行权冻结资金（仅限期权账户）
			double frozen_exec_cash;
			///行权费用（仅限期权账户）
			double frozen_exec_fee;
			///垫付资金（仅限期权账户）
			double pay_later;
			///预垫付资金（仅限期权账户）
			double preadva_pay;
			///昨日余额（仅限期权账户）
			double orig_banlance;
			///当前余额（仅限期权账户）
			double banlance;
			///当天出入金（仅限期权账户）
			double deposit_withdraw;
			///当日交易资金轧差（仅限期权账户）
			double trade_netting;
			///资金资产（仅限期权账户）
			double captial_asset;
		
			///强锁资金（仅限期权账户）
			double force_freeze_amount;
			///可取资金（仅限期权账户）
			double preferred_amount;
		
			// 信用业务新增字段开始（数量1）
			///融券卖出所得资金余额（仅限信用账户，只能用于买券还券）
			double repay_stock_aval_banlance;
		
			// 信用业务新增字段结束（数量1）
		
			///累计订单流量费
			double fund_order_data_charges;
			///累计撤单流量费
			double fund_cancel_data_charges;
			//流量费统计新增字段结束（数量2）
		
			///交易所实时风险度（仅限期权账户,后续服务器版本支持，目前为0）
			double exchange_cur_risk_degree;
			///公司实时风险度（仅限期权账户,后续服务器版本支持，目前为0）
			double company_cur_risk_degree;
			//风险度新增字段结束（数量2）
		
			///(保留字段)
			uint64_t unknown[43 - 12 - 1 - 2 - 2];
		
			///账户类型
			XTP_ACCOUNT_TYPE account_type;
			///货币种类
			XTP_CURRENCY_TYPE  currency_type;                                    
		};
		
	}//API
}//XTPX

#pragma pack(pop)

#endif //_XOMS_NG_API4_STRUCT_H_

