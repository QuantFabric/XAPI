#pragma once
#include "FtdcApiStruct.h"

#ifndef LINUX 
#ifdef LIB_RMD_API_EXPORT
#define RMD_API_EXPORT __declspec(dllexport)
#else
#define RMD_API_EXPORT __declspec(dllimport)
#endif
#else
#define RMD_API_EXPORT 
#endif

class CFtdcMdSpi
{
public:
	virtual void OnMdFrontConnected(){};
	virtual void OnMdFrontDisconnected(int nReason){};
	virtual void OnMdRspUserLogin(CRsaFtdcRspUserLoginField *pRspUserLogin, CRsaFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	virtual void OnRtnDepthMarketData(CRsaFtdcDepthMarketDataField *pDepthMarketData) {};
	virtual void OnRspSubMarketData(CRsaFtdcSpecificInstrumentField *pSpecificInstrument, CRsaFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	virtual void OnRspUnSubMarketData(CRsaFtdcSpecificInstrumentField *pSpecificInstrument, CRsaFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	virtual void OnRtnBarMarketData(CRsaFtdcBarMarketDataField *pBarMarketData) {};
	virtual void OnRspQryMarketData(CRsaFtdcRspMarketDataField *pRspMarketData, CRsaFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	virtual void OnRtnMarketDataEnd(CRsaFtdcNtfMarketDataEndField *pMarketDataEnd) {};
};

class RMD_API_EXPORT CFtdcMdApi
{
public:
	static CFtdcMdApi *CreateFtdcMdApi(const char *pszFrontAddress, const char *pszFlowPath = "", const char *pszUserApiType = "", bool needHistoryTick = false);
	virtual void Release() = 0;
	virtual void Init() = 0;
	virtual int Join() = 0;
	virtual bool ChkCurrentThread() = 0;
	virtual void RegisterNameServer(const char *pszNsAddress) = 0;
	virtual void RegisterSpi(CFtdcMdSpi *pSpi) = 0;
	virtual int ReqUserLogin(CRsaFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	virtual int ReqSubMarketData(char *ppInstrumentID[], int nCount, int nRequestID=-1)=0;
	virtual int ReqUnSubMarketData(char *ppInstrumentID[], int nCount, int nRequestID = -1)=0;
	virtual int ReqQryMarketData(CRsaFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;
	virtual int ReqSendDepthMarketDataRead(CRsaFtdcDepthMarketDataField *pDepthMarketData, int nRequestID) = 0;
	virtual int ReqSendBarMarketDataRead(CRsaFtdcBarMarketDataField *pBarMarketData, int nRequestID) = 0;
	virtual int ReqBtSubMarketData(CRsaFtdcBtSubMarketDataField *ppFiels[], int nCount, int nRequestID = -1) = 0;
	virtual int ReqBtUnSubMarketData(CRsaFtdcBtSubMarketDataField *ppFiels[], int nCount, int nRequestID = -1) = 0;
	virtual int ReqSubMarketDataCompleted() = 0;
	virtual int ReqSubCombMarketData(CRsaFtdcSubCombMarketDataField* ppFiels[], int nCount) = 0;
	virtual int ReqQryBarMarketData(CRsaFtdcBtSubMarketDataField* subMd, CRsaFtdcBarMarketDataField* bars[], int& count) = 0;
	virtual int ReqQryDepthMarketData(CRsaFtdcQryMarketDataField* pQryMarketData, CRsaFtdcDepthMarketDataField* depthMd[], int& count) = 0;
protected:
	~CFtdcMdApi(){};
};
