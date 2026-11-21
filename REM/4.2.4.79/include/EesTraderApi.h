/*! \file EesTraderApi.h
 *  \brief EES交易客户端头文件   
 *  
 *  该文档详细描述了EES交易客户端的接口定义。
*/
#pragma  once 
#include "EesTraderDefine.h"
#include "EesTraderErr.h"
#include <time.h>

#ifdef _EES_TRADE_API_TWO_STRUCT_DEFINE_H_
namespace TraderTwo
{
#endif

#ifdef WIN32
	#ifdef SL_EES_TRADE_EXPORTS
		#define SL_EES_TRADE_CLASS __declspec(dllexport)	  
		#define SL_EES_TRADE_FUN		extern "C" __declspec(dllexport)
	#else
		#define SL_EES_TRADE_CLASS __declspec(dllimport)	  
		#define SL_EES_TRADE_FUN		extern "C" __declspec(dllimport)
	#endif

	/// \brief EES交易客户端动态库名
	#define EES_TRADER_DLL_NAME    "EESTraderApi.dll"
	/// \brief EES交易客户端静态库名
	#define EES_TRADER_LIB_NAME    "EESTraderApi.lib"

	#include <windows.h>

#else	
	#define SL_EES_TRADE_CLASS 
	#define SL_EES_TRADE_FUN  extern "C" 

	#ifndef OUT
		#define OUT
	#endif

	#ifndef NULL
		#define NULL 0
	#endif

	/// \brief EES交易客户端动态库名
	#define EES_TRADER_DLL_NAME    "libEESTraderApi_ef.so"

#endif

/// \brief EES交易客户端回调基类
class  EESTraderEvent
{
public:	
	virtual ~EESTraderEvent()
	{

	}
	/// 连接消息的回调
	
		///	\brief	服务器连接事件
		///	\param  errNo                   连接成功能与否的消息
		///	\param  pErrStr                 错误信息
		///	\return void  
	
	virtual void OnConnection(ERR_NO errNo, const char* pErrStr ){}

	/// 交易连接断开消息的回调
	
		/// \brief	交易服务器主动断开，会收到这个消息
		/// \param  ERR_NO errNo         连接成功能与否的消息
		/// \param  const char* pErrStr  错误信息
		/// \return void  
	
	virtual void OnDisConnection(ERR_NO errNo, const char* pErrStr ){}



	/// 查询连接断开消息的回调

	/// \brief	查询服务器主动断开，会收到这个消息
	/// \param  ERR_NO errNo         连接成功能与否的消息
	/// \param  const char* pErrStr  错误信息
	/// \return void  
	virtual void OnQueryDisConnection(ERR_NO errNo, const char* pErrStr) {}



	///登录消息的回调 连接接口ConnServer 如果为mix_protocol = false,那么不开启混合协议下单撤单，会从当前接口返回 ;
	/// \param  pLogon                  登录成功或是失败的结构
	/// \return void 
	virtual void OnUserLogon(EES_LogonResponse* pLogon) {}

	/// 登录消息的回调 连接接口ConnServer 如果为mix_protocol = true,那么会开启混合协议下单撤单，会从当前接口返回 ;
	/// \param  pLogon                  登录成功或是失败的结构
	/// \param  m_sock
	/// \return void 
	virtual void OnUserLogon(EES_LogonResponse* pLogon, MY_SOCKET m_sock){}


	/// 心跳超时的回调
	/// \param  isTrade  是否交易接口
	/// \param  seconds  心跳超时时间(秒)
	/// \return void 
	virtual void OnHeartBeatTimeout(bool isTrade, int seconds) {}


	/// 修改密码响应回调

	/// \param  nResult                  服务器响应的成功与否返回码
	/// \return void 

	virtual void OnRspChangePassword(EES_ChangePasswordResult nResult){}

	/// 查询用户下面帐户的返回事件
	
		/// \param  pAccountInfo	        帐户的信息
		/// \param  bFinish	                如果没有传输完成，这个值是 false ，如果完成了，那个这个值为 true 
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
		/// \return void 
	
	virtual void OnQueryUserAccount(EES_AccountInfo * pAccoutnInfo, bool bFinish){}

	/// 查询帐户下面期货仓位信息的返回事件	
		/// \param  pAccount	                帐户ID 	
		/// \param  pAccoutnPosition	        帐户的仓位信息					   
		/// \param  nReqId		                发送请求消息时候的ID号。
		/// \param  bFinish	                    如果没有传输完成，这个值是false，如果完成了，那个这个值为 true 
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
		/// \return void 	
	virtual void OnQueryAccountPosition(const char* pAccount, EES_AccountPosition* pAccoutnPosition, int nReqId, bool bFinish){}	

	/// 查询帐户下面期权仓位信息的返回事件, 注意这个回调, 和上一个OnQueryAccountPosition, 会在一次QueryAccountPosition请求后, 分别返回, 先返回期货, 再返回期权, 即使没有期权仓位, 也会返回一条bFinish=true的记录
	/// \param  pAccount	                帐户ID 	
	/// \param  pAccoutnPosition	        帐户的仓位信息					   
	/// \param  nReqId		                发送请求消息时候的ID号。
	/// \param  bFinish	                    如果没有传输完成，这个值是false，如果完成了，那个这个值为 true 
	/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
	/// \return void 	
	virtual void OnQueryAccountOptionPosition(const char* pAccount, EES_AccountOptionPosition* pAccoutnOptionPosition, int nReqId, bool bFinish) {}


	/// 查询帐户下面资金信息的返回事件
	
		/// \param  pAccount	                帐户ID 	
		/// \param  pAccoutnBP	                帐户的资金信息					   
		/// \param  nReqId		                发送请求消息时候的ID号
		/// \return void 
	
	virtual void OnQueryAccountBP(const char* pAccount, EES_AccountBP* pAccoutnBP, int nReqId ){}	

	/// 查询帐户详细资金信息的返回事件

	/// \param  pAccount	                帐户ID 	
	/// \param  pAccoutnBP	                帐户的资金信息					   
	/// \return void 

	virtual void OnQueryAccountBPDetail(const char* pAccount, EES_AccountBPDetail* pAccoutnBP) {}

	/// 发生出入金后主动报告资金信息事件

	/// \param  pAccount	                帐户ID 	
	/// \param  pAccoutnBP	                帐户的资金信息					   
	/// \return void 
	virtual void OnAccountBPReport(const char* pAccount, EES_AccountBP* pAccoutnBP) {}

	/// 出入金明细推送

	/// \param  pAccount	                帐户ID 	
	/// \param  pAccoutCashInout	        帐户的出入金信息					   
	/// \return void 
	virtual void OnAccountCashInoutNotify(const char* pAccount, EES_AccountCashInout* pAccoutCashInout) {}

	/// 查询合约列表的返回事件
	
		/// \param  pSymbol	                    合约信息   
		/// \param  bFinish	                    如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true   
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pSymbol 值无效。
		/// \return void 
	
	virtual void OnQuerySymbol(EES_SymbolField* pSymbol, bool bFinish){}

	/// 查询帐户交易保证金的返回事件
	
	    /// \param  pAccount                    帐户ID 
		/// \param  pSymbolMargin               帐户的保证金信息 
		/// \param  bFinish	                    如果没有传输完成，这个值是 false，如果完成，那个这个值为 true 
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pSymbolMargin 值无效。
		/// \return void 
	
	virtual void OnQueryAccountTradeMargin(const char* pAccount, EES_AccountMargin* pSymbolMargin, bool bFinish ){}

	/// 查询帐户交易费用的返回事件
	
		/// \param  pAccount                    帐户ID 
		/// \param  pSymbolFee	                帐户的费率信息	 
		/// \param  bFinish	                    如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true    
		/// \remark 如果碰到 bFinish == true ，那么是传输结束，并且 pSymbolFee 值无效。
		/// \return void 
	
	virtual void OnQueryAccountTradeFee(const char* pAccount, EES_AccountFee* pSymbolFee, bool bFinish ){}

	/// 下单被柜台系统接受的事件
	
		/// \brief 表示这个订单已经被柜台系统正式的接受
		/// \param  pAccept	                    订单被接受以后的消息体
		/// \return void 
	
	virtual void OnOrderAccept(EES_OrderAcceptField* pAccept ){}


	/// 触发篮子回报
	/// \brief 表示触发篮子回报
	/// \param  pAccept	                   篮子触发以后的消息体
	/// \return void 
	virtual void OnOrigOrderReport(EES_OrigOrderReportField* pAccept) {}


	/// 下单被市场接受的事件

	    /// \brief 表示这个订单已经被交易所正式的接受
	    /// \param  pAccept	                    订单被接受以后的消息体，里面包含了市场订单ID
	    /// \return void 
	virtual void OnOrderMarketAccept(EES_OrderMarketAcceptField* pAccept) {}


	///	下单被柜台系统拒绝的事件
	
		/// \brief	订单被柜台系统拒绝，可以查看语法检查或是风控检查。 
		/// \param  pReject	                    订单被接受以后的消息体
		/// \return void 
	
	virtual void OnOrderReject(EES_OrderRejectField* pReject ){}


	///	下单被市场拒绝的事件

	/// \brief	订单被市场拒绝，可以查看语法检查或是风控检查。 
	/// \param  pReject	                    订单被接受以后的消息体，里面包含了市场订单ID
	/// \return void 

	virtual void OnOrderMarketReject(EES_OrderMarketRejectField* pReject) {}


	///	订单成交的消息事件
	
		/// \brief	成交里面包括了订单市场ID，建议用这个ID查询对应的订单
		/// \param  pExec	                   订单被接受以后的消息体，里面包含了市场订单ID
		/// \return void 
	
	virtual void OnOrderExecution(EES_OrderExecutionField* pExec ){}

	///	订单成功撤销事件
	
		/// \brief	成交里面包括了订单市场ID，建议用这个ID查询对应的订单
		/// \param  pCxled		               订单被接受以后的消息体，里面包含了市场订单ID
		/// \return void 
	
	virtual void OnOrderCxled(EES_OrderCxled* pCxled ){}

	///	撤单被拒绝的消息事件
	
		/// \brief	一般会在发送撤单以后，收到这个消息，表示撤单被拒绝
		/// \param  pReject	                   撤单被拒绝消息体
		/// \return void 
	
	virtual void OnCxlOrderReject(EES_CxlOrderRej* pReject ){}

	///	查询订单的返回事件
	
		/// \brief	查询订单信息时候的回调，这里面也可能包含不是当前用户下的订单
		/// \param  pAccount                 帐户ID 
		/// \param  pQueryOrder	             查询订单的结构
		/// \param  bFinish	                 如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true    
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且 pQueryOrder值无效。
		/// \return void 
	
	virtual void OnQueryTradeOrder(const char* pAccount, EES_QueryAccountOrder* pQueryOrder, bool bFinish  ){} 

	///	查询订单的返回事件
	
		/// \brief	查询订单信息时候的回调，这里面也可能包含不是当前用户下的订单成交
		/// \param  pAccount                        帐户ID 
		/// \param  pQueryOrderExec	                查询订单成交的结构
		/// \param  bFinish	                        如果没有传输完成，这个值是false，如果完成了，那个这个值为 true    
		/// \remark 如果碰到 bFinish == true，那么是传输结束，并且pQueryOrderExec值无效。
		/// \return void 
	
	virtual void OnQueryTradeOrderExec(const char* pAccount, EES_QueryOrderExecution* pQueryOrderExec, bool bFinish  ){}

	///	查询订单成交的返回事件

	/// \brief	查询订单信息时候的回调，这里面也可能包含不是当前用户下的订单成交
	/// \param  pAccount                        帐户ID 
	/// \param  pQueryOrderExec	                查询订单成交的结构
	/// \param  bFinish	                        如果没有传输完成，这个值是false，如果完成了，那个这个值为 true    
	/// \remark 如果碰到 bFinish == true，那么是传输结束，并且pQueryOrderExec值无效。
	/// \return void 

	virtual void OnQueryTradeOrderExecEx(const char* pAccount, EES_QueryOrderExecutionEx* pQueryOrderExec, bool bFinish) {}

	///	接收外部订单的消息
	
		/// \brief	一般会在系统订单出错，进行人工调整的时候用到。
		/// \param  pPostOrder	                    查询订单成交的结构
		/// \return void 
	
	virtual void OnPostOrder(EES_PostOrder* pPostOrder ){}	

	///	接收外部订单成交的消息
	
		/// \brief	一般会在系统订单出错，进行人工调整的时候用到。
		/// \param  pPostOrderExecution	             查询订单成交的结构
		/// \return void 
	
	virtual void OnPostOrderExecution(EES_PostOrderExecution* pPostOrderExecution ){}

	///	查询交易所可用连接的响应

	/// \brief	每个当前系统支持的汇报一次，当bFinish= true时，表示所有交易所的响应都已到达，但本条消息本身不包含有用的信息。
	/// \param  pMarketSession	             查询MarketSession的结构
	/// \return void 
	virtual void OnQueryMarketSession(EES_ExchangeMarketSession* pMarketSession, bool bFinish) {}

	///	交易所连接状态变化报告，

	/// \brief	当交易所连接发生连接/断开时报告此状态
	/// \param  MarketSessionId: 交易所连接代码
	/// \param  ConnectionGood: true表示交易所连接正常，false表示交易所连接断开了。
	/// \return void 
	virtual void OnMarketSessionStatReport(EES_MarketSessionId MarketSessionId, bool ConnectionGood) {}

	///	合约状态变化报告

	/// \brief	当合约状态发生变化时报告
	/// \param  pSymbolStatus: 参见EES_SymbolStatus合约状态结构体定义
	/// \return void 
	virtual void OnSymbolStatusReport(EES_SymbolStatus* pSymbolStatus) {}


	///	合约状态查询响应

	/// \brief  响应合约状态查询请求
	/// \param  pSymbolStatus: 参见EES_SymbolStatus合约状态结构体定义
	/// \param	bFinish: 当为true时，表示查询所有结果返回。此时pSymbolStatus为空指针NULL
	/// \return void 
	virtual void OnQuerySymbolStatus(EES_SymbolStatus* pSymbolStatus, bool bFinish) {}


	/// 席位代号查询响应
	/// \param	pSessionID: 参见EES_SessionID席位代号结构体定义
	/// \return void 
	virtual void OnQuerySessionID(EES_SessionID* pSessionID) {}


	/// 篮子状态查询响应（注意：1313版本开始不支持预埋单功能，这个回调接口暂不支持）	
	/// \param	EES_BasketState: 参见EES_BasketState席位代号结构体定义
	/// \return void 
	virtual void OnQueryBasketState(EES_BasketState* pBasketState, bool bFinish) {}

	/// 推送最后一笔报单时间
	virtual void OnLastOrderTimeReport(EES_LastOrderTimeReport* pReport) {}

};

/// \brief EES交易客户端纯虚基类
class SL_EES_TRADE_CLASS EESTraderApi
{
public:
	virtual ~EESTraderApi()
	{
	}
	///获取API版本号
	/// \return api_verson  Api的版本号，一串字符串，如4.2.4.71
	virtual const char*  GetTradeApiVersion() = 0;

	///是否自动重连，必须在ConnServer之前使用
	/// 开启自动重连之后，交易和查询只要有一个链接发生异常断开，api将重置交易和查询链接，重连成功后返回OnConnection事件，需要重新登录
	/// \return 没有返回值
	virtual void SetAutoReconnect(bool autoConnect) = 0;

	/// 设置交易、查询连接等待事件时间
	/// \param  int trade_wait_time			交易连接等待事件时间
	/// \param  int query_wait_time		    查询连接等待事件时间
	/// \return 没有返回值
	virtual void SetMaxWaitTime(int trade_wait_time, int query_wait_time) = 0;

	/// 获取下单出网卡时间戳
	/// \param  long long timestamps	时间戳数组
	/// \param  int count				数组大小
	/// \return 没有返回值
	virtual void GetTimestamps(long long timestamps[], int& count) = 0;

	/// 连接服务器,支持TCP和UDP两种下单模式
	virtual RESULT	ConnServer(const EES_TradeSvrInfo& param, EESTraderEvent* pEvent, bool mix_protocol = false)  = 0 ;

	/// 连接服务器,支持TCP和UDP两种下单模式(优化参数版本，推荐使用这个)
	virtual RESULT	ConnServer(const EES_TradeSvrInfoEx& param, EESTraderEvent* pEvent, bool mix_protocol = false) = 0;
	
	/// 断开服务器
	
		/// \return RESULT						参考 EesTraderErr.h文件
	
	virtual RESULT	DisConnServer()  = 0 ;

	/// 用户登录
	
		/// \brief	这里输入的不是帐户名，是用户名
		/// \param  const char* logonId			用户名
		/// \param  const char* userPwd		    用户登录密码
		/// \param  const char* app_id		    AppId
		/// \param  const char* auth_code		授权码
		/// \return RESULT			返回值，参考 EesTraderErr.h文件
	
	virtual RESULT UserLogon(const char* logonId, const char* user_pwd, const char* app_id, const char* auth_code) = 0 ;

	/// 用户密码修改

	/// \brief	登录成功后才能使用
	/// \param  const char* oldPwd			老密码
	/// \param  const char* newPwd		    新密码
	/// \return RESULT			返回值，参考 EesTraderErr.h文件

	virtual RESULT ChangePassword(const char* oldPwd, const char* newPwd )  = 0 ;

	/// 查询合约列表
	
		/// \brief	只会返回当天有效的合约
		/// \return RESULT			返回值，参考 EesTraderErr.h文件
	
	virtual RESULT QuerySymbolList( )  = 0 ;


	/// 查询用户包含的帐户
	
		/// \return RESULT			返回值，参考 EesTraderErr.h文件
	
	virtual RESULT QueryUserAccount()  = 0 ;

	/// 查询帐户仓位
	
		/// \brief	
		/// \param  const char* accountId		帐户ID
		/// \param  int   nReqId			    请求查询的ID号
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT QueryAccountPosition(const char* accountId, int nReqId)  = 0 ;

	/// 查询帐户BP
	
		/// \brief	
		/// \param  const char* accountId		帐户ID
		/// \param  int   nReqId				请求查询的ID号
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT QueryAccountBP(const char* accountId, int nReqId)  = 0 ;

	/// 查询帐户详细资金

	/// \brief	
	/// \param  const char* accountId		帐户ID
	/// \return RESULT			返回值，参考EesTraderErr.h文件

	virtual RESULT QueryAccountBPDetail(const char* accountId) = 0;
	/// 查询帐户保证金率
	
		/// \param  const char* accountId		帐户ID
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT QueryAccountTradeMargin(const char* accountId )  = 0 ;

	/// 查询帐户手续费
	
		/// \brief	由于，每一个帐户的费率不一样，最好每一个帐户都查询一下。
		/// \param  const char* accountId		帐户ID
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT QueryAccountTradeFee(const char* accountId, EES_FeeSecType feeSecType = EES_FEE_SecType_future) = 0  ;


	/// 获取订单 最大  token 值
	/// \brief	获取订单 最大  token 值
	/// \param  EES_ClientToken * orderToken	要输出的值
	/// \return RESULT			返回值，参考EesTraderErr.h文件
	virtual RESULT GetMaxToken(OUT EES_ClientToken* orderToken) = 0  ;


	/// 下单
	/// \param  EES_EnterOrderField* pOrder	组织好的订单结构体
	/// \return RESULT			返回值，参考EesTraderErr.h文件
	virtual RESULT	EnterOrder(EES_EnterOrderField* pOrder ) = 0  ;



	/// 触发预埋单
	/// \param  EES_EnterOrigOrderField* pOrder	组织好的订单结构体
	/// \return RESULT			返回值，参考EesTraderErr.h文件
	virtual RESULT	EnterOrigOrder(EES_EnterOrigOrderField* pOrder) = 0;


	/// 下加热单
	virtual void EnterOrderWarm() = 0;

	/// 下加热单，会发到REM柜台，与普通单区别是OrderToken不做校验
	/// \param  EES_EnterOrderField* pOrder	组织好的订单结构体
	/// \return RESULT			返回值，参考EesTraderErr.h文件
	virtual RESULT	EnterOrderWarm(EES_EnterOrderField* pOrder) = 0;

	/// 撤销订单指令
	
		/// \param  EES_CancelOrder* pCxlOrder		撤单结构体
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT	CancelOrder(EES_CancelOrder* pCxlOrder)  = 0 ;

	/// 查询帐户订单信息 
	
		/// \param  const char* accountId		     帐户ID
		/// \param  basketId  0代表查所有普通单 1代表散单 1以上代表篮子号
		/// \param  queryAll  查所有 包括普通单和篮子订单
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	virtual RESULT  QueryAccountOrder(const char* accountId, short basketId = 0, bool queryAll = false)= 0;

	/// 查询帐户成交信息
	
		/// \param  const char* accountId		     帐户ID
		/// \param  unsigned int rewind_flag		 回滚标志 0-应答无合约和买卖方向 1-应答带合约和买卖方向
		/// \return RESULT			返回值，参考EesTraderErr.h文件
	
	virtual RESULT	QueryAccountOrderExecution(const char* accountId, unsigned int rewind_flag = 0) = 0 ;

	/// 发送查询交易所可用席位请求	
	/// \return 没有返回值，响应在EESTraderEvent::OnQueryMarketSession中返回
	virtual RESULT QueryMarketSession() = 0;

	/// 时间戳转换函数，用于将API中所有的EES_Nanosecond类型，转换成C语言标准的struct tm结构体，以及这个时间在一秒内的纳秒数

	/// \param  EES_Nanosecond timeStamp		API多个结构体中的时间戳值
	/// \param  tm& tmResult					用于接收结果的struct tm结构体
	/// \param  unsigned int& nanoSsec 			用于接收结果的纳秒数
	/// \return 没有返回值
	virtual void ConvertFromTimestamp(EES_Nanosecond timeStamp, tm& tmResult, unsigned int& nanoSsec) = 0;

	/// 回报本地日志开关和本地日志文件路径，必须在首次调用ConnServer之前使用
	/// \param  bool bOn		true: 打开本地日志; false: 关闭本地日志，默认为关
	/// \param const char* log_path		本地日志，如果log_path传NULL，则为当前运行路径
	/// \return 没有返回值
	virtual void SetLoggerSwitch(bool bOn, const char* log_path = NULL) = 0;

	/// 发送查询合约状态请求 
	/// \return RESULT 响应在EESTraderEvent::OnQuerySymbolStatus中返回
	virtual RESULT QuerySymbolStatus() = 0;

	/// 立即将缓冲的日志信息写入文件
	/// \return 没有返回值
	virtual void LoggerFlush() = 0;

	/// 批量下单，最多一次下16个报单
	/// 注意每个报单的的OrderToken必须保证在外部就设置好不重复，
	/// pArrOrders: EES_EnterOrderField结构体数组，最多16个，nCount必须 >=1，且 <=16
	/// \return: 成功返回0，任意一个报单有错，则返回非0值，且所有报单都不会被发送
	virtual RESULT EnterMultiOrders(EES_EnterOrderField* pArrOrders, int nCount) = 0;

	/// 批量撤单，最多一次下37个撤单
	/// 注意每个撤单的的OrderToken必须保证在外部就设置好不重复，
	/// pCxlOrders: EES_CancelOrder结构体数组，最多37个，nCount必须 >=1，且 <=37
	/// \return: 成功返回0，任意一个报单有错，则返回非0值，且所有撤单都不会被发送
	virtual RESULT EnterMultiCxlOrders(EES_CancelOrder* pArrCxlOrders, int nCount) = 0;

	/// 调整客户端流控参数
	/// 登录成功后，可从登录返回消息结构EES_LogonResponse中，获取到当前登录的流控参数（单位是每多少毫秒，多少次下单/撤单）
	/// 由于服务端对于下单的控制是根据账号，而我们系统允许一个账号多点登录同时下单，因此实际流控可能会比获得的参数更加严格
	/// 因此提供该接口，客户可以根据自己是否需要多点登录下单，对流控参数进行更加严格的调整，防止触发了服务器的流控从而被断连且熔断登录
	/// 本接口只允许调整下单次数，且只能调得更少，且不能将次数调成0
	/// OrderCount：更新下单次数控制
	/// CancelCount：更新撤单次数控制
	/// 接口不会返回正确还是错误，如果传入了错误的参数，则原参数不会变化
	virtual RESULT ChangeFCParam(unsigned int OrderCount, unsigned int CancelCount) = 0;

	/// 发送查询交易所可用席位请求	
	/// tradeNo: 交易所席位号
	/// exchangeID: 需要填入EES_ExchangeID_shfe等实际交易所代码或者填0,填0表示不校验交易所，填其他值报错
	/// \return 成功返回0，响应在EESTraderEvent::OnQuerySessionID中返回
	virtual RESULT QuerySessionID(const char* tradeNo,EES_ExchangeID exchangeID) = 0;


	/// 发送查询篮子状态（注意：1313版本开始不支持预埋单功能，这个接口暂不支持）	
	/// basketId: 篮子号 如果是0，则查所有，1：查散单篮子 
	/// marketOrderToken: 如果是散单 查询需要填入，如果不是，不需要填
	/// account_id可以填为空，表示当前用户下的篮
	/// \return 成功返回0，响应在EESTraderEvent::OnQueryBasketState中返回
	virtual RESULT QueryBasketState(unsigned short basketId, EES_MarketToken marketOrderToken, const char* account_id) = 0;

	/// 查询帐户出入金

	/// \brief	
	/// \param  const char* accountId		帐户ID
	/// \return RESULT			返回值，参考EesQueryErr.h文件

	virtual RESULT QueryAccountCashInOut(const char* accountId) = 0;

};

/// 创建EES交易客户端实例的函数名
#define CREATE_EES_TRADER_API_NAME ("CreateEESTraderApi")

/// 销毁EES交易客户端实例的函数名
#define DESTROY_EES_TRADER_API_NAME ("DestroyEESTraderApi")

/// 创建EES交易客户端实例函数声明
SL_EES_TRADE_FUN EESTraderApi* CreateEESTraderApi(void) ; 

/// 销毁EES交易客户端实例函数声明
SL_EES_TRADE_FUN void DestroyEESTraderApi(EESTraderApi* pEESTraderApi) ; 

/// 创建EES交易客户端实例函数指针类型
typedef EESTraderApi* (*funcCreateEESTraderApi)(void) ;

/// 销毁EES交易客户端实例函数指针类型
typedef void (*funcDestroyEESTraderApi)(EESTraderApi* pEESTraderApi) ;

#ifdef _EES_TRADE_API_TWO_STRUCT_DEFINE_H_
}
#endif
