/////////////////////////////////////////////////////////////////////////
///@author 中泰证券股份有限公司
///@file xtrade_x_api_data_type.h
///@brief 定义XTP4.0交易使用的数据基本类型
/////////////////////////////////////////////////////////////////////////
#ifndef _XTRADE_NG_API4_DATA_TYPE_H_
#define _XTRADE_NG_API4_DATA_TYPE_H_

#pragma once

#if defined(_MSC_VER) && _MSC_VER<1600

#ifndef _XTP_API_DATA_TYPE_DEFINE_INT_
#define _XTP_API_DATA_TYPE_DEFINE_INT_

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#endif // !_XTP_API_DATA_TYPE_DEFINE_INT_

#else
#include <stdint.h>
#endif

#pragma pack(push)
#pragma pack(1)

namespace XTPX {

	namespace API {

		/// 每个PBU最多被10个TGW使用。
		constexpr uint32_t MAX_TGW_CNT_PER_PBU = 10;

		/// 存放版本号的字符串长度
		constexpr uint32_t XTP_VERSION_LEN = 13;
		/// 版本号类型
		typedef char XTPVersionType[XTP_VERSION_LEN];
		/// 可交易日字符串长度
		constexpr uint32_t XTP_TRADING_DAY_LEN = 9;

		/// 存放证券代码的字符串长度
		constexpr uint32_t XTP_TICKER_LEN = 16;

		/// 存放证券名称的字符串长度
		constexpr uint32_t XTP_TICKER_NAME_LEN = 64;

		/// 用户资金账户的字符串长度
		constexpr uint32_t XTP_ACCOUNT_NAME_LEN = 16;

		/// 用户资金账户的密码字符串长度
		constexpr uint32_t XTP_ACCOUNT_PASSWORD_LEN = 64;


		/// 用户股东账户的字符串长度
		constexpr uint32_t XTP_ACCOUNT_ID_LEN = 17;

		///证书信息的字符串长度
		constexpr uint32_t XTP_CERT_MSG_LEN = 512;

		/// 本地报单编号的字符串长度
		constexpr uint32_t XTP_LOCAL_ORDER_LEN = 11;
		/// 交易所单号的字符串长度
		constexpr uint32_t XTP_ORDER_EXCH_LEN = 17;
		/// 成交执行编号的字符串长度
		constexpr uint32_t XTP_EXEC_ID_LEN = 18;
		/// 交易所交易员代码字符串长度
		constexpr uint32_t XTP_BRANCH_PBU_LEN = 7;
		/// 信用业务合约负债编号长度
		constexpr uint32_t XTP_CREDIT_DEBT_ID_LEN = 33;
		/// IP地址的字符串长度
		constexpr uint32_t XTP_INET_ADDRESS_STR_LEN = 64;
		/// MAC地址的字符串长度
		constexpr uint32_t XTP_MAC_ADDRESS_LEN = 19;
		/// 硬盘序列号的字符串长度
		constexpr uint32_t XTP_HARDDISK_SN_LEN = 33;
		/// MacOS系统序列号的字符串长度
		constexpr uint32_t XTP_MACOS_SNO_LEN = 21;
		/// 移动Android端标识符的字符串长度
		constexpr uint32_t XTP_IMEI_LEN = 16;
		/// 移动ios端标识符的字符串长度
		constexpr uint32_t XTP_IDFV_LEN = 37;
		/// 其他移动端标识符的字符串长度
		constexpr uint32_t XTP_GUID_LEN = 40;
		/// 手机号码的字符串长度
		constexpr uint32_t XTP_TEL_LEN = 12;
		/// 软件开发代码的字符串长度
		constexpr uint32_t XTP_SCD_LEN = 3;

		/// 期权组合策略最多腿数
		constexpr uint32_t XTP_STRATEGE_LEG_NUM = 4;
		/// 期权组合策略代码字符串长度
		constexpr uint32_t XTP_STRATEGY_ID_LEN = 10;
		/// 期权组合策略名称字符串长度
		constexpr uint32_t XTP_STRATEGY_NAME_LEN = 32;
		/// 期权组合策略组合编码字符串长度
		constexpr uint32_t XTP_SECONDARY_ORDER_ID_LEN = 18;

		/// 期权合约可支持的组合策略列表字符串长度
		constexpr uint32_t XTP_CNTRT_COMB_STRA_LIST_LEN = 2048;

		/// 期权行权合并最多成分合约数量
		constexpr uint32_t XTP_COMBINED_EXECUTION_LEG_NUM = 2;


		//////////////////////////////////////////////////////////////////////////
		///@brief XTP_MARKET_TYPE市场类型，交易里使用
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_MARKET_TYPE;

		///初始化值或者未知
		constexpr uint32_t XTP_MKT_INIT = 0;   
		///深圳A股
		constexpr uint32_t XTP_MKT_SZ_A = 1;     
		///上海A股
		constexpr uint32_t XTP_MKT_SH_A = 2;     
		///北京A股
		constexpr uint32_t XTP_MKT_BJ_A = 3;
		///港股    
		constexpr uint32_t XTP_MKT_HK = 4;     
		///港股通上海
		constexpr uint32_t XTP_MKT_SH_HK = 5;     
		///港股通深圳
		constexpr uint32_t XTP_MKT_SZ_HK = 6;     
		///未知交易市场类型
		constexpr uint32_t XTP_MKT_UNKNOWN = 7;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_PRICE_TYPE是价格类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_PRICE_TYPE;

		///限价单-沪 / 深 / 沪期权 / 深期权 （除普通股票业务外，其余未特指的业务均使用此种类型）
		constexpr uint32_t XTP_PRICE_LIMIT = 1;        
		///即时成交剩余转撤销，市价单-深 / 沪期权 / 深期权
		constexpr uint32_t XTP_PRICE_BEST_OR_CANCEL = 2;        
		///最优五档即时成交剩余转限价，市价单-沪
		constexpr uint32_t XTP_PRICE_BEST5_OR_LIMIT = 3;        
		///最优5档即时成交剩余转撤销，市价单-沪深 / 深期权
		constexpr uint32_t XTP_PRICE_BEST5_OR_CANCEL = 4;        
		///全部成交或撤销,市价单-深 / 沪期权 / 深期权
		constexpr uint32_t XTP_PRICE_ALL_OR_CANCEL = 5;        
		///本方最优，市价单-深 / 深期权 / 沪科创板
		constexpr uint32_t XTP_PRICE_FORWARD_BEST = 6; 
		///对方最优剩余转限价，市价单-深 / 沪期权 / 深期权 / 沪科创板       
		constexpr uint32_t XTP_PRICE_REVERSE_BEST_LIMIT = 7;        
		///期权限价申报FOK
		constexpr uint32_t XTP_PRICE_LIMIT_OR_CANCEL = 8;        
		///未知或者无效价格类型
		constexpr uint32_t XTP_PRICE_TYPE_UNKNOWN = 9;       
   



		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_SIDE_TYPE是买卖方向类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint8_t XTP_SIDE_TYPE;

		///买（新股申购，ETF买，配股，信用交易中担保品买）
		constexpr uint32_t XTP_SIDE_BUY = 1;
		///卖（逆回购，ETF卖，信用交易中担保品卖）
		constexpr uint32_t XTP_SIDE_SELL = 2;
		///申购
		constexpr uint32_t XTP_SIDE_PURCHASE = 7;
		///赎回
		constexpr uint32_t XTP_SIDE_REDEMPTION = 8;
		///拆分
		constexpr uint32_t XTP_SIDE_SPLIT = 9;
		///合并
		constexpr uint32_t XTP_SIDE_MERGE = 10;
		///改版之后的side的备兑，暂不支持
		constexpr uint32_t XTP_SIDE_COVER = 11;
		///改版之后的side锁定（对应开平标识为开）/解锁（对应开平标识为平）
		constexpr uint32_t XTP_SIDE_FREEZE = 12;
		/// 融资买入
		constexpr uint32_t XTP_SIDE_MARGIN_TRADE = 21;
		/// 融券卖出
		constexpr uint32_t XTP_SIDE_SHORT_SELL = 22;
		/// 卖券还款
		constexpr uint32_t XTP_SIDE_REPAY_MARGIN = 23;
		/// 买券还券
		constexpr uint32_t XTP_SIDE_REPAY_STOCK = 24;
		/// 现金还款（不放在普通订单协议，另加请求和查询协议）
//		constexpr uint32_t XTP_SIDE_CASH_REPAY_MARGIN = 25;
		/// 现券还券
		constexpr uint32_t XTP_SIDE_STOCK_REPAY_STOCK = 26;
		/// 余券划转
		constexpr uint32_t XTP_SIDE_SURSTK_TRANS = 27;
		/// 担保品转入
		constexpr uint32_t XTP_SIDE_GRTSTK_TRANSIN = 28;
		/// 担保品转出
		constexpr uint32_t XTP_SIDE_GRTSTK_TRANSOUT = 29;

		///组合策略的组合
		constexpr uint32_t XTP_SIDE_OPT_COMBINE = 31; 
		///组合策略的拆分
		constexpr uint32_t XTP_SIDE_OPT_SPLIT = 32; 
		///组合策略的管理员强制拆分
		constexpr uint32_t XTP_SIDE_OPT_SPLIT_FORCE = 33; 
		///组合策略的交易所强制拆分
		constexpr uint32_t XTP_SIDE_OPT_SPLIT_FORCE_EXCH = 34;

		///未知或者无效买卖方向
		constexpr uint32_t XTP_SIDE_UNKNOWN = 50;



		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_POSITION_EFFECT_TYPE是开平标识类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint8_t XTP_POSITION_EFFECT_TYPE;

		/// 初始值或未知值开平标识，除期权外，均使用此值
		constexpr uint32_t XTP_POSITION_EFFECT_INIT = 0;
		/// 开
		constexpr uint32_t XTP_POSITION_EFFECT_OPEN = 1;
		/// 平
		constexpr uint32_t XTP_POSITION_EFFECT_CLOSE = 2;
		/// 强平
		constexpr uint32_t XTP_POSITION_EFFECT_FORCECLOSE = 3;
		/// 平今
		constexpr uint32_t XTP_POSITION_EFFECT_CLOSETODAY = 4;
		/// 平昨
		constexpr uint32_t XTP_POSITION_EFFECT_CLOSEYESTERDAY = 5;
		/// 强减
		constexpr uint32_t XTP_POSITION_EFFECT_FORCEOFF = 6;
		/// 本地强平
		constexpr uint32_t XTP_POSITION_EFFECT_LOCALFORCECLOSE = 7;
		/// 信用业务追保强平
		constexpr uint32_t XTP_POSITION_EFFECT_CREDIT_FORCE_COVER = 8;
		/// 信用业务清偿强平
		constexpr uint32_t XTP_POSITION_EFFECT_CREDIT_FORCE_CLEAR = 9;
		/// 信用业务合约到期强平
		constexpr uint32_t XTP_POSITION_EFFECT_CREDIT_FORCE_DEBT = 10;
		/// 信用业务无条件强平
		constexpr uint32_t XTP_POSITION_EFFECT_CREDIT_FORCE_UNCOND = 11;
		/// 未知的开平标识类型
		constexpr uint32_t XTP_POSITION_EFFECT_UNKNOWN = 12;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_ORDER_ACTION_STATUS_TYPE是报单操作状态类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_ORDER_ACTION_STATUS_TYPE;

		///已经提交
		constexpr uint32_t XTP_ORDER_ACTION_STATUS_SUBMITTED = 1;    
		///已经接受
		constexpr uint32_t XTP_ORDER_ACTION_STATUS_ACCEPTED = 2;      
		///已经被拒绝   
		constexpr uint32_t XTP_ORDER_ACTION_STATUS_REJECTED = 3;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_ORDER_STATUS_TYPE是报单状态类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_ORDER_STATUS_TYPE;

		///初始化
		constexpr uint32_t XTP_ORDER_STATUS_INIT = 0;
		///全部成交
		constexpr uint32_t XTP_ORDER_STATUS_ALLTRADED = 1;           
		///部分成交
		constexpr uint32_t XTP_ORDER_STATUS_PARTTRADEDQUEUEING = 2;
		///部分撤单
		constexpr uint32_t XTP_ORDER_STATUS_PARTTRADEDNOTQUEUEING = 3; 
		///未成交
		constexpr uint32_t XTP_ORDER_STATUS_NOTRADEQUEUEING = 4;   
		///已撤单
		constexpr uint32_t XTP_ORDER_STATUS_CANCELED = 5;  
		///已拒绝
		constexpr uint32_t XTP_ORDER_STATUS_REJECTED = 6; 
		///未知订单状态
		constexpr uint32_t XTP_ORDER_STATUS_UNKNOWN = 7; 


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_ORDER_SUBMIT_STATUS_TYPE是报单提交状态类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_ORDER_SUBMIT_STATUS_TYPE;

		///订单已经提交
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_INSERT_SUBMITTED = 1;
		///订单已经被接受
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_INSERT_ACCEPTED = 2;
		///订单已经被拒绝
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_INSERT_REJECTED = 3;
		///撤单已经提交
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_CANCEL_SUBMITTED = 4;
		///撤单已经被拒绝
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_CANCEL_REJECTED = 5;
		///撤单已经被接受
		constexpr uint32_t XTP_ORDER_SUBMIT_STATUS_CANCEL_ACCEPTED = 6;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_TE_RESUME_TYPE是公有流（订单响应、成交回报）重传方式
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_TE_RESUME_TYPE;

		///从本交易日开始重传
		constexpr uint32_t XTP_TERT_RESTART = 0;    
		///从从上次收到的续传（暂未支持）
		constexpr uint32_t XTP_TERT_RESUME = 1;  
		///只传送登录后公有流（订单响应、成交回报）的内容
		constexpr uint32_t XTP_TERT_QUICK = 2;      


		//////////////////////////////////////////////////////////////////////////
		///@brief ETF_REPLACE_TYPE现金替代标识定义
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t ETF_REPLACE_TYPE;

		///禁止现金替代
		constexpr uint32_t ERT_CASH_FORBIDDEN = 0;            
		///可以现金替代
		constexpr uint32_t ERT_CASH_OPTIONAL = 1;
 		///必须现金替代
		constexpr uint32_t ERT_CASH_MUST = 2;
		///深市退补现金替代
		constexpr uint32_t ERT_CASH_RECOMPUTE_INTER_SZ = 3;
		///深市必须现金替代
		constexpr uint32_t ERT_CASH_MUST_INTER_SZ = 4;         
		///非沪深市场成分证券退补现金替代（不适用于跨沪深港ETF产品）
		constexpr uint32_t ERT_CASH_RECOMPUTE_INTER_OTHER = 5; 
		///表示非沪深市场成份证券必须现金替代（不适用于跨沪深港ETF产品）
		constexpr uint32_t ERT_CASH_MUST_INTER_OTHER = 6;
		///港市退补现金替代（仅适用于跨沪深港ETF产品）
		constexpr uint32_t ERT_CASH_RECOMPUTE_INTER_HK = 7;
		///港市必须现金替代（仅适用于跨沪深港ETF产品）
		constexpr uint32_t ERT_CASH_MUST_INTER_HK = 8;  
		///无效值
		constexpr uint32_t   EPT_INVALID = 9;   


		//////////////////////////////////////////////////////////////////////////
		///@brief XTP_TICKER_TYPE证券类型
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_TICKER_TYPE;

		///普通股票
		constexpr uint32_t XTP_TICKER_TYPE_STOCK = 0;            
		///指数
		constexpr uint32_t XTP_TICKER_TYPE_INDEX = 1;          
		///基金
		constexpr uint32_t XTP_TICKER_TYPE_FUND = 2;         
		///债券
		constexpr uint32_t XTP_TICKER_TYPE_BOND = 3;          
		///期权
		constexpr uint32_t XTP_TICKER_TYPE_OPTION = 4;          
		///科创板股票（上海）
		constexpr uint32_t XTP_TICKER_TYPE_TECH_STOCK = 5;         
		///未知类型
		constexpr uint32_t XTP_TICKER_TYPE_UNKNOWN = 6;           
    

		//////////////////////////////////////////////////////////////////////////
		///@brief XTP_BUSINESS_TYPE证券业务类型
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_BUSINESS_TYPE;

		///普通股票业务（股票买卖，ETF买卖，沪市交易型货币基金等）
		constexpr uint32_t XTP_BUSINESS_TYPE_CASH = 0;            
		///新股申购业务（对应的price type需选择限价类型）
		constexpr uint32_t XTP_BUSINESS_TYPE_IPOS = 1;
		///回购业务（国债逆回购业务对应的price type填为限价，side填为卖）
		constexpr uint32_t XTP_BUSINESS_TYPE_REPO = 2;
		///ETF申赎业务
		constexpr uint32_t XTP_BUSINESS_TYPE_ETF = 3;
		///融资融券业务
		constexpr uint32_t XTP_BUSINESS_TYPE_MARGIN = 4;              
		///转托管（未支持）
		constexpr uint32_t XTP_BUSINESS_TYPE_DESIGNATION = 5;
		///配股业务（对应的price type需选择限价类型,side填为买）
		constexpr uint32_t XTP_BUSINESS_TYPE_ALLOTMENT = 6;
		///分级基金申赎业务
		constexpr uint32_t XTP_BUSINESS_TYPE_STRUCTURED_FUND_PURCHASE_REDEMPTION = 7;      
		///分级基金拆分合并业务（业务已下线，不再支持）
		constexpr uint32_t XTP_BUSINESS_TYPE_STRUCTURED_FUND_SPLIT_MERGE = 8;
		///货币基金申赎业务（暂未支持，沪市交易型货币基金的买卖请使用普通股票业务）
		constexpr uint32_t XTP_BUSINESS_TYPE_MONEY_FUND = 9;
		///期权业务       
		constexpr uint32_t XTP_BUSINESS_TYPE_OPTION = 10;
		///行权
		constexpr uint32_t XTP_BUSINESS_TYPE_EXECUTE = 11;             
		///锁定解锁，暂不支持
		constexpr uint32_t XTP_BUSINESS_TYPE_FREEZE = 12;             
		///期权组合策略 组合和拆分业务
		constexpr uint32_t XTP_BUSINESS_TYPE_OPTION_COMBINE = 13;
		///期权行权合并业务
		constexpr uint32_t XTP_BUSINESS_TYPE_EXECUTE_COMBINE = 14;    
		/// 债转股业务
		constexpr uint32_t XTP_BUSINESS_TYPE_BOND_SWAP_STOCK = 15;  
		///未知类型   
		constexpr uint32_t XTP_BUSINESS_TYPE_UNKNOWN = 16;            


		//////////////////////////////////////////////////////////////////////////
		///@brief XTP_ACCOUNT_TYPE账户类型
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_ACCOUNT_TYPE;

		///普通账户
		constexpr uint32_t XTP_ACCOUNT_NORMAL = 0;    
		///信用账户
		constexpr uint32_t XTP_ACCOUNT_CREDIT = 1;    
		///衍生品账户
		constexpr uint32_t XTP_ACCOUNT_DERIVE = 2;    
		///未知账户类型
		constexpr uint32_t XTP_ACCOUNT_UNKNOWN = 3;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_FUND_TRANSFER_TYPE是资金流转方向类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_FUND_TRANSFER_TYPE;

		///转出 从XTP转出到柜台
		constexpr uint32_t XTP_FUND_TRANSFER_OUT = 0;        
		///转入 从柜台转入XTP
		constexpr uint32_t XTP_FUND_TRANSFER_IN = 1;
		///跨节点转出 从本XTP节点1，转出到对端XTP节点2，XTP服务器之间划拨，只能“一账号两中心”跨节点用户使用
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_OUT = 2;
		///跨节点转入 从对端XTP节点2，转入到本XTP节点1，XTP服务器之间划拨，只能“一账号两中心”跨节点用户使用
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_IN = 3;
		///跨节点转出 融券卖出资金 从本XTP节点1，转出到对端XTP节点2，XTP服务器之间划拨
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_REPAY_OUT = 4;
		///跨节点转入 融券卖出资金 从对端XTP节点2，转入到本XTP节点1，XTP服务器之间划拨
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_REPAY_IN = 5;
		///跨节点转出 授信额度 从本XTP节点1，转出到对端XTP节点2，XTP服务器之间划拨
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_CONTRACT_OUT = 6;
		///跨节点转入 授信额度 从对端XTP节点2，转入到本XTP节点1，XTP服务器之间划拨
		constexpr uint32_t XTP_FUND_INTER_TRANSFER_CONTRACT_IN = 7; 
		///未知类型
		constexpr uint32_t XTP_FUND_TRANSFER_UNKNOWN = 8;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_FUND_QUERY_TYPE是柜台资金查询类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_FUND_QUERY_TYPE;

		///查询金证主柜台可转资金
		constexpr uint32_t XTP_FUND_QUERY_JZ = 0;        
		///查询一账号两中心设置时，对方节点的资金
		constexpr uint32_t XTP_FUND_QUERY_INTERNAL = 1;
		///查询一账号两中心设置时，对方节点的融券卖余额资金
		constexpr uint32_t XTP_FUND_QUERY_INTERNAL_REPAY = 2;  
		///查询一账号两中心设置时，对方节点的授信额度
		constexpr uint32_t XTP_FUND_QUERY_INTERNAL_CONTRACT = 3; 
		///未知类型
		constexpr uint32_t XTP_FUND_QUERY_UNKNOWN = 4;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_FUND_OPER_STATUS柜台资金操作结果
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_FUND_OPER_STATUS;

		///XTP已收到，正在处理中
		constexpr uint32_t XTP_FUND_OPER_PROCESSING = 0;    
		///成功
		constexpr uint32_t XTP_FUND_OPER_SUCCESS = 1;     
		///失败
		constexpr uint32_t XTP_FUND_OPER_FAILED = 2;    
		///划拨服务处理中
		constexpr uint32_t XTP_FUND_OPER_SUBMITTED = 3;   
		///未知
		constexpr uint32_t XTP_FUND_OPER_UNKNOWN = 4;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_DEBT_EXTEND_OPER_STATUS柜台负债展期操作状态
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_DEBT_EXTEND_OPER_STATUS;

		///XTP已收到，正在处理中
		constexpr uint32_t XTP_DEBT_EXTEND_OPER_PROCESSING = 0;    
		///已提交到集中柜台处理
		constexpr uint32_t XTP_DEBT_EXTEND_OPER_SUBMITTED = 1;        
		///成功
		constexpr uint32_t XTP_DEBT_EXTEND_OPER_SUCCESS = 2;      
		///失败
		constexpr uint32_t XTP_DEBT_EXTEND_OPER_FAILED = 3;
		///未知           
		constexpr uint32_t XTP_DEBT_EXTEND_OPER_UNKNOWN = 4;      


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_SPLIT_MERGE_STATUS是一个基金当天拆分合并状态类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_SPLIT_MERGE_STATUS;

		///允许拆分和合并
		constexpr uint32_t XTP_SPLIT_MERGE_STATUS_ALLOW = 0;    
		///只允许拆分，不允许合并
		constexpr uint32_t XTP_SPLIT_MERGE_STATUS_ONLY_SPLIT = 1;
		///只允许合并，不允许拆分
		constexpr uint32_t XTP_SPLIT_MERGE_STATUS_ONLY_MERGE = 2;
		///不允许拆分合并
		constexpr uint32_t XTP_SPLIT_MERGE_STATUS_FORBIDDEN = 3;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_OPT_CALL_OR_PUT_TYPE是一个认沽或认购类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_OPT_CALL_OR_PUT_TYPE;

		///认购
		constexpr uint32_t XTP_OPT_CALL = 1;      
		///认沽
		constexpr uint32_t XTP_OPT_PUT = 2;

		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_OPT_EXERCISE_TYPE_TYPE是一个行权方式类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_OPT_EXERCISE_TYPE_TYPE;

		///欧式
		constexpr uint32_t XTP_OPT_EXERCISE_TYPE_EUR = 1;        
		///美式
		constexpr uint32_t XTP_OPT_EXERCISE_TYPE_AME = 2;        


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_POSITION_DIRECTION_TYPE是一个持仓方向类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_POSITION_DIRECTION_TYPE;

		///净
		constexpr uint32_t XTP_POSITION_DIRECTION_NET = 0;       
		///多（期权则为权利方） 
		constexpr uint32_t XTP_POSITION_DIRECTION_LONG = 1;
		///空（期权则为义务方）
		constexpr uint32_t XTP_POSITION_DIRECTION_SHORT = 2;  
		///备兑（期权则为备兑义务方）
		constexpr uint32_t XTP_POSITION_DIRECTION_COVERED = 3;  


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_OPT_COVERED_OR_UNCOVERED是否备兑的标签
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_OPT_COVERED_OR_UNCOVERED;

		///非备兑
		constexpr uint32_t XTP_POSITION_UNCOVERED = 0;     
		///备兑
		constexpr uint32_t XTP_POSITION_COVERED = 1;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_CRD_CASH_REPAY_STATUS是一个融资融券直接还款状态类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_CRD_CR_STATUS;

		/// 初始、未处理状态
		constexpr uint32_t XTP_CRD_CR_INIT = 0;        
		/// 已成功处理状态
		constexpr uint32_t XTP_CRD_CR_SUCCESS = 1;     
		/// 处理失败状态
		constexpr uint32_t XTP_CRD_CR_FAILED = 2;     


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_OPT_POSITION_TYPE是一个期权持仓类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_OPT_POSITION_TYPE;

		/// 单合约持仓
		constexpr uint32_t XTP_OPT_POSITION_TYPE_CONTRACT = 0;     
		/// 组合策略持仓
		constexpr uint32_t XTP_OPT_POSITION_TYPE_COMBINED = 1;      


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_ORDER_TYPE是一个订单的类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_ORDER_DETAIL_TYPE;

		/// 新订单
		constexpr uint32_t XTP_ORDER_DETAIL_TYPE_NEW_ORDER = 0;                
		/// 新订单撤单
		constexpr uint32_t XTP_ORDER_DETAIL_TYPE_CANCEL_ORDER = 1;                
		/// 组合订单
		constexpr uint32_t XTP_ORDER_DETAIL_TYPE_OPT_COMB_NEW_ORDER = 2;      
		/// 组合订单撤单 
		constexpr uint32_t XTP_ORDER_DETAIL_TYPE_OPT_COMB_CANCEL_ORDER = 3;     


		/////////////////////////////////////////////////////////////////////////
		///TXTPTradeTypeType是成交类型类型
		/////////////////////////////////////////////////////////////////////////
		typedef char TXTPTradeTypeType;

		///普通成交
		constexpr char XTP_TRDT_COMMON = '0';
		///现金替代
		constexpr char XTP_TRDT_CASH = '1';
		///一级市场成交
		constexpr char XTP_TRDT_PRIMARY = '2';
		///跨市场资金成交
		constexpr char XTP_TRDT_CROSS_MKT_CASH = '3';
		///港市资金成交
		constexpr char XTP_TRDT_HK_MKT_CASH = '4';
		///非沪深资金成交
		constexpr char XTP_TRDT_NON_SHSZ_MKT_CASH = '5';

		/////////////////////////////////////////////////////////////////////////
		///TXTPOrderTypeType是报单类型类型
		/////////////////////////////////////////////////////////////////////////
		typedef char TXTPOrderTypeType;

		///正常
		constexpr char XTP_ORDT_Normal = '0';
		///报价衍生
		constexpr char XTP_ORDT_DeriveFromQuote = '1';
		///组合衍生
		constexpr char XTP_ORDT_DeriveFromCombination = '2';
		///组合报单
		constexpr char XTP_ORDT_Combination = '3';
		///条件单
		constexpr char XTP_ORDT_ConditionalOrder = '4';
		///互换单
		constexpr char XTP_ORDT_Swap = '5';


		//////////////////////////////////////////////////////////////////////////
		///@brief XTPTerminalType是一种终端类型，仅供授权系统使用
		//////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTPTerminalType;

		///"PC",PC-windows及MacOS
		constexpr uint32_t  XTP_TERMINAL_PC = 1; 
		///"MA",Mobile-Android           
		constexpr uint32_t   XTP_TERMINAL_ANDROID = 2;          
		///"MI",Mobile-Ios
		constexpr uint32_t   XTP_TERMINAL_IOS = 3;      
		///"MW",Mobile-Windows Phone
		constexpr uint32_t   XTP_TERMINAL_WP = 4;      
		///"WP",无盘站
		constexpr uint32_t   XTP_TERMINAL_STATION = 5;       
		///"TO",电话委托
		constexpr uint32_t   XTP_TERMINAL_TEL = 6;       
		///"OH",PC-linux及其他终端
		constexpr uint32_t   XTP_TERMINAL_PC_LINUX = 7;        


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_EXPIRE_DATE_TYPE是一个期权组合策略合约到期日要求类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_EXPIRE_DATE_TYPE; 

		/// 相同到期日
		constexpr uint32_t XTP_EXP_DATE_SAME = 0;   
		/// 不同到期日
		constexpr uint32_t XTP_EXP_DATE_DIFF = 1;  
		/// 无到期日要求
		constexpr uint32_t XTP_EXP_DATE_NON = 2;    


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_UNDERLYING_TYPE是一个期权组合策略标的要求类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_UNDERLYING_TYPE; 

		///相同标的
		constexpr uint32_t XTP_UNDERLYING_SAME = 0;    
		///不同标的
		constexpr uint32_t XTP_UNDERLYING_DIFF = 1;   
		///无标的要求
		constexpr uint32_t XTP_UNDERLYING_NON = 2;      


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_AUTO_SPLIT_TYPE是一个期权组合策略自动解除类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_AUTO_SPLIT_TYPE; 

		///到期日自动解除
		constexpr uint32_t XTP_AUTO_SPLIT_EXPDAY = 0;
		///E-1日自动解除   
		constexpr uint32_t XTP_AUTO_SPLIT_PREDAY = 1;        
		///E-2日自动解除
		constexpr uint32_t XTP_AUTO_SPLIT_PRE2DAY = 2;      
 		///无效值
		constexpr uint32_t XTP_AUTO_SPLIT_NON = 3;       



		///行权价顺序类型， 从1开始，1表示行权价最高，2次之。如果行权价相同，则填写相同数字，用A表示行权价大于等于B，B大于等于C依次类推（C、D）
		typedef char TXTPExerciseSeqType;


		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_POSITION_SECURITY_TYPE是一个持仓证券类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t  XTP_POSITION_SECURITY_TYPE;

		///普通持仓
		constexpr uint32_t XTP_POSITION_SECURITY_NORMAL = 0;            
		///配售类型的持仓，包含配股、配债等
		constexpr uint32_t XTP_POSITION_SECURITY_PLACEMENT = 1;        
		///未知类型
		constexpr uint32_t XTP_POSITION_SECURITY_UNKNOWN = 2;            

		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_TRANSFER_SITE_TYPE是一个划转节点类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_TRANSFER_SITE_TYPE;

		///主柜台
		constexpr uint32_t XTP_TRANSFER_SITE_COUNTER = 0;
		///上海节点
		constexpr uint32_t XTP_TRANSFER_SITE_SH = 2;
		///深圳节点
		constexpr uint32_t XTP_TRANSFER_SITE_SZ = 4;
		///北京节点
		constexpr uint32_t XTP_TRANSFER_SITE_NQ = 8;
		///香港节点
		constexpr uint32_t XTP_TRANSFER_SITE_HK = 16;
		///未知节点
		constexpr uint32_t XTP_TRANSFER_SITE_UNKNOWN = 256;

		/////////////////////////////////////////////////////////////////////////
		///@brief XTP_CURRENCY_TYPE是一个货币种类类型
		/////////////////////////////////////////////////////////////////////////
		typedef uint32_t XTP_CURRENCY_TYPE;

		///人民币
		constexpr uint32_t XTP_CURRENCY_CNY = 0;
		///美元
		constexpr uint32_t XTP_CURRENCY_USD = 1;
		///港币
		constexpr uint32_t XTP_CURRENCY_HKD = 2;

	}//API
}//XTPX

#pragma pack(pop)

#endif //_XTRADE_NG_API_DATA_TYPE_H_
