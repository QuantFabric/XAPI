#include "ydExample.h"

// 本示例展现了如何使用报单组的概念
// 报单组有多种用途
// 1) 对于一个报单组的报单的OrderRef进行严格的管理，确保OrderRef的递增性和唯一性，以便应对在UDP报单时可能出现的丢单或者重复发送的问题
// 2) 对于报单组内的报单，可以使用OrderRef撤单，不需要OrderSysID，也就是可以在收到报单回报前撤单
// 3) 各个报单组的OrderRef都独自管理，当一个账号需要多个程序同时登录和交易时，可以互不影响

// 要使用报单组，需要有一个报单组号。目前易达支持的报单组号的范围是[1,63]。如果报单组号为0，表示不使用报单组，OrderRef就没有必要递增和唯一了，也不可以用OrderRef撤单
// 请不要使用其他报单组号，其结果是不确定的
static const int s_orderGroupID=5;

class YDExample9Listener: public YDListener
{
private:
	YDApi *m_pApi;
	const char *m_username,*m_password,*m_instrumentID;
	int m_maxPosition;
	int m_maxOrderRef;

	// 指向希望交易的品种
	const YDInstrument *m_pInstrument;

	// 指向希望交易的品种的账户品种信息
	const YDAccountInstrumentInfo *m_pAccountInstrumentInfo;

	// 说明当前是否有挂单
	bool m_hasOrder;
public:
	YDExample9Listener(YDApi *pApi,const char *username,const char *password,const char *instrumentID,int maxPosition)
	{
		m_pApi=pApi;
		m_username=username;
		m_password=password;
		m_instrumentID=instrumentID;
		m_maxPosition=maxPosition;
		m_maxOrderRef=0;
		m_hasOrder=false;
	}
	virtual void notifyReadyForLogin(bool hasLoginFailed)
	{
		// 当API准备登录时，发出此消息，用户需要在此时发出登录指令
		// 如果发生了断线重连，也会发出此消息，让用户重新发出登录指令，但是此时不允许换成另外的用户登录
		if (!m_pApi->login(m_username,m_password,NULL,NULL))
		{
			printf("can not login\n");
			exit(1);
		}
	}
	virtual void notifyLogin(int errorNo,int maxOrderRef,bool isMonitor)
	{
		// 每次登录响应，都会获得此消息，用户应当根据errorNo来判断是否登录成功
		if (errorNo==0)
		{
			printf("login successfully\n");
		}
		else
		{
			// 如果登录失败，有可能是服务器端尚未启动，所以可以选择不终止程序，但是不需要在这里再次发出登录请求。
			// Api会稍过一会儿再次给出notifyReadyForLogin消息，应当在那时发出登录请求
			printf("login failed, errorNo=%d\n",errorNo);
			exit(1);
		}
	}
	virtual void notifyGroupMaxOrderRef(const int groupMaxOrderRef[])
	{
		// 每次登录成功后，都会回调此方法，应当记录当前的要使用的报单组的最大报单引用，在报单时用更大的数作为报单引用，以便程序通过报单引用来识别报单
		m_maxOrderRef=groupMaxOrderRef[s_orderGroupID];
	}
	virtual void notifyFinishInit(void)
	{
		// notifyFinishInit是在第一次登录成功后一小段时间发出的消息，表示API已经收到了今天的所有初始化信息，
		// 包括所有的产品合约信息，昨行情和今日的固定行情（例如涨跌停板）信息，账号的日初信息，保证金率信息，
		// 手续费率信息，昨持仓信息，但是还没有获得登录前已经发生的报单和成交信息，日内的出入金信息
		// 这个时候，用户程序已经可以安全地访问所有API管理的数据结构了
		// 用户程序获得所有YDSystemParam，YDExchange，YDProduct，YDInstrument，YDCombPositionDef，YDAccount，
		// YDPrePosition，YDMarginRate，YDCommissionRate，YDAccountExchangeInfo，YDAccountProductInfo，
		// YDAccountInstrumentInfo和YDMarketData的指针，都可以在未来长期安全使用，API不会改变其地址
		// 但是API消息中的YDOrder、YDTrade、YDInputOrder、YDQuote、YDInputQuote和YDCombPosition的地址都是
		// 临时的，在该消息处理完成后将不再有效
		m_pInstrument=m_pApi->getInstrumentByID(m_instrumentID);
		if (m_pInstrument==NULL)
		{
			printf("can not find instrument %s\n",m_instrumentID);
			exit(1);
		}
		m_pAccountInstrumentInfo=m_pApi->getAccountInstrumentInfo(m_pInstrument);
		// 下面这个循环展示了如何根据历史持仓信息，计算该品种的当前持仓。如果用户风控忽略历史持仓，可以不使用
		for (int i=0;i<m_pApi->getPrePositionCount();i++)
		{
			const YDPrePosition *pPrePosition=m_pApi->getPrePosition(i);
			if (pPrePosition->m_pInstrument==m_pInstrument)
			{
				if (pPrePosition->PositionDirection==YD_PD_Long)
				{
					// 所有各个结构中的UserInt1，UserInt2，UserFloat，pUser都是供用户自由使用的，其初值都是0
					// 在本例子中，我们使用账户合约信息中的UserInt1保存当前的持仓信息
					m_pAccountInstrumentInfo->UserInt1+=pPrePosition->PrePosition;
				}
				else
				{
					m_pAccountInstrumentInfo->UserInt1-=pPrePosition->PrePosition;
				}
			}
		}
		printf("Position=%d\n",m_pAccountInstrumentInfo->UserInt1);
		m_pApi->subscribe(m_pInstrument);
	}
	virtual void notifyMarketData(const YDMarketData *pMarketData)
	{
		if (m_pInstrument->m_pMarketData!=pMarketData)
		{
			// 由于各个品种的pMarketData的地址是固定的，所以可以用此方法忽略非本品种的行情
			return;
		}
		if ((pMarketData->AskVolume==0)||(pMarketData->BidVolume==0))
		{
			// 忽略停板行情
			return;
		}
		if (pMarketData->BidVolume-pMarketData->AskVolume>100)
		{
			// 根据策略条件，需要买入
			tryTrade(YD_D_Buy);
		}
		else if (pMarketData->AskVolume-pMarketData->BidVolume>100)
		{
			// 根据策略条件，需要卖出
			tryTrade(YD_D_Sell);
		}
	}
	void tryTrade(int direction)
	{
		if (m_hasOrder)
		{
			// 如果有挂单，就不做了
			return;
		}
		YDInputOrder inputOrder;
		// inputOrder中的所有不用的字段，应当统一清0
		memset(&inputOrder,0,sizeof(inputOrder));
		if (direction==YD_D_Buy)
		{
			if (m_pAccountInstrumentInfo->UserInt1>=m_maxPosition)
			{
				// 控制是否达到了限仓
				return;
			}
			if (m_pAccountInstrumentInfo->UserInt1>=0)
			{
				// 控制开平仓，这个例子中没有处理SHFE和INE的区分今昨仓的情况
				inputOrder.OffsetFlag=YD_OF_Open;
			}
			else
			{
				inputOrder.OffsetFlag=YD_OF_Close;
			}
			// 由于本例子使用的不是市价单，所以需要指定价格
			inputOrder.Price=m_pInstrument->m_pMarketData->AskPrice;
		}
		else
		{
			if (m_pAccountInstrumentInfo->UserInt1<=-m_maxPosition)
			{
				return;
			}
			if (m_pAccountInstrumentInfo->UserInt1<=0)
			{
				inputOrder.OffsetFlag=YD_OF_Open;
			}
			else
			{
				inputOrder.OffsetFlag=YD_OF_Close;
			}
			inputOrder.Price=m_pInstrument->m_pMarketData->BidPrice;
		}
		inputOrder.Direction=direction;
		inputOrder.HedgeFlag=YD_HF_Speculation;
		inputOrder.OrderVolume=1;

		// 使用本报单组的下一个报单引用
		inputOrder.OrderGroupID=s_orderGroupID;
		inputOrder.OrderRef=++m_maxOrderRef;
		// 如果GroupOrderRefControl是YD_GORF_Increase，表示希望ydServer检查OrderRef的递增性
		// 如果GroupOrderRefControl是YD_GORF_IncreaseOne，表示希望ydServer检查OrderRef必需是前一个加一
		// 这两种方式都可以防止UDP重复，区别是如何应对UDP丢单：
		//    YD_GORF_Increase表示希望ydServer尽力处理后面的报单
		//    YD_GORF_IncreaseOne表示希望ydServer停止处理本报单组的报单，待人工处理后再继续
		inputOrder.GroupOrderRefControl=YD_GORF_Increase;

		// 这个例子使用限价单
		inputOrder.OrderType=YD_ODT_Limit;
		// 说明是普通报单
		inputOrder.YDOrderFlag=YD_YOF_Normal;
		// 说明如何选择连接
		inputOrder.ConnectionSelectionType=YD_CS_Any;
		// 如果ConnectionSelectionType不是YD_CS_Any，需要指定ConnectionID，范围是0到对应的YDExchange中的ConnectionCount-1
		inputOrder.ConnectionID=0;
		// inputOrder中的RealConnectionID和ErrorNo是在返回时由服务器填写的
		if (m_pApi->insertOrder(&inputOrder,m_pInstrument))
		{
			m_hasOrder=true;

			// 在使用报单组时，可以不等报单回报，直接撤单。不过如果此时ydServer还没有收到交易所的报单回报，能够撤单取决于交易所是否支持使用本地号撤单
			YDCancelOrder cancelOrder;
			memset(&cancelOrder,0,sizeof(cancelOrder));
			cancelOrder.OrderGroupID=s_orderGroupID;
			cancelOrder.OrderRef=inputOrder.OrderRef;
			m_pApi->cancelOrder(&cancelOrder,m_pInstrument->m_pExchange);
		}
	}
	virtual void notifyOrder(const YDOrder *pOrder,const YDInstrument *pInstrument,const YDAccount *pAccount)
	{
		if ((pOrder->OrderGroupID==s_orderGroupID) && (pOrder->OrderStatus!=YD_OS_Queuing))
		{
			m_hasOrder=false;
		}
	}
	virtual void notifyTrade(const YDTrade *pTrade,const YDInstrument *pInstrument,const YDAccount *pAccount)
	{
		if (pTrade->OrderGroupID!=s_orderGroupID)
		{
			return;
		}
		if (pTrade->Direction==YD_D_Buy)
		{
			// 根据成交，调整持仓
			m_pAccountInstrumentInfo->UserInt1+=pTrade->Volume;
		}
		else
		{
			m_pAccountInstrumentInfo->UserInt1-=pTrade->Volume;
		}
		printf("%s %s %d at %g\n",(pTrade->Direction==YD_D_Buy?"buy":"sell"),(pTrade->OffsetFlag==YD_OF_Open?"open":"close"),pTrade->Volume,pTrade->Price);
		printf("Position=%d\n",m_pAccountInstrumentInfo->UserInt1);
	}
};

void startExample9(const char *configFilename,const char *username,const char *password,const char *instrumentID)
{
	/// 所有YDApi的启动都由下列三步构成

	// 创建YDApi
	YDApi *pApi=makeYDApi(configFilename);
	if (pApi==NULL)
	{
		printf("can not create API\n");
		exit(1);
	}
	// 创建Api的监听器
	YDExample9Listener *pListener=new YDExample9Listener(pApi,username,password,instrumentID,3);
	/// 启动Api
	if (!pApi->start(pListener))
	{
		printf("can not start API\n");
		exit(1);
	}
}
