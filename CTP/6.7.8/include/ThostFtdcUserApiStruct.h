/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ThostFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20060106	�Ժ��		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(THOST_FTDCSTRUCT_H)
#define THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ThostFtdcUserApiDataType.h"

///��Ϣ�ַ�
struct CThostFtdcDisseminationField
{
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
};

///�û���¼����
struct CThostFtdcReqUserLoginField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��̬����
	TThostFtdcPasswordType	OneTimePassword;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
};

///�û���¼Ӧ��
struct CThostFtdcRspUserLoginField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TThostFtdcTimeType	LoginTime;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ϵͳ����
	TThostFtdcSystemNameType	SystemName;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///��󱨵�����
	TThostFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TThostFtdcTimeType	SHFETime;
	///������ʱ��
	TThostFtdcTimeType	DCETime;
	///֣����ʱ��
	TThostFtdcTimeType	CZCETime;
	///�н���ʱ��
	TThostFtdcTimeType	FFEXTime;
	///��Դ����ʱ��
	TThostFtdcTimeType	INETime;
	///��̨�汾��Ϣ
	TThostFtdcSysVersionType	SysVersion;
	///������ʱ��
	TThostFtdcTimeType	GFEXTime;
	///��ǰ��¼���ĺ�
	TThostFtdcDRIdentityIDType	LoginDRIdentityID;
	///�û��������ĺ�
	TThostFtdcDRIdentityIDType	UserDRIdentityID;
};

///�û��ǳ�����
struct CThostFtdcUserLogoutField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///ǿ�ƽ���Ա�˳�
struct CThostFtdcForceUserLogoutField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///�ͻ�����֤����
struct CThostFtdcReqAuthenticateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///��֤��
	TThostFtdcAuthCodeType	AuthCode;
	///App����
	TThostFtdcAppIDType	AppID;
};

///�ͻ�����֤��Ӧ
struct CThostFtdcRspAuthenticateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///App����
	TThostFtdcAppIDType	AppID;
	///App����
	TThostFtdcAppTypeType	AppType;
};

///�ͻ�����֤��Ϣ
struct CThostFtdcAuthenticationInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///��֤��Ϣ
	TThostFtdcAuthInfoType	AuthInfo;
	///�Ƿ�Ϊ��֤���
	TThostFtdcBoolType	IsResult;
	///App����
	TThostFtdcAppIDType	AppID;
	///App����
	TThostFtdcAppTypeType	AppType;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
};

///�û���¼Ӧ��2
struct CThostFtdcRspUserLogin2Field
{
	///������
	TThostFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TThostFtdcTimeType	LoginTime;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ϵͳ����
	TThostFtdcSystemNameType	SystemName;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///��󱨵�����
	TThostFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TThostFtdcTimeType	SHFETime;
	///������ʱ��
	TThostFtdcTimeType	DCETime;
	///֣����ʱ��
	TThostFtdcTimeType	CZCETime;
	///�н���ʱ��
	TThostFtdcTimeType	FFEXTime;
	///��Դ����ʱ��
	TThostFtdcTimeType	INETime;
	///�����
	TThostFtdcRandomStringType	RandomString;
};

///����ת�ʱ���ͷ
struct CThostFtdcTransferHeaderField
{
	///�汾�ţ�������1.0
	TThostFtdcVersionType	Version;
	///���״��룬����
	TThostFtdcTradeCodeType	TradeCode;
	///�������ڣ������ʽ��yyyymmdd
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ�䣬�����ʽ��hhmmss
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ�ţ�N/A
	TThostFtdcTradeSerialType	TradeSerial;
	///�ڻ���˾���룬����
	TThostFtdcFutureIDType	FutureID;
	///���д��룬���ݲ�ѯ���еõ�������
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ��룬���ݲ�ѯ���еõ�������
	TThostFtdcBankBrchIDType	BankBrchID;
	///����Ա��N/A
	TThostFtdcOperNoType	OperNo;
	///�����豸���ͣ�N/A
	TThostFtdcDeviceIDType	DeviceID;
	///��¼����N/A
	TThostFtdcRecordNumType	RecordNum;
	///�Ự��ţ�N/A
	TThostFtdcSessionIDType	SessionID;
	///�����ţ�N/A
	TThostFtdcRequestIDType	RequestID;
};

///�����ʽ�ת�ڻ�����TradeCode=202001
struct CThostFtdcTransferBankToFutureReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TThostFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TThostFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///�����ʽ�ת�ڻ�������Ӧ
struct CThostFtdcTransferBankToFutureRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TThostFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TThostFtdcMoneyType	CustFee;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///�ڻ��ʽ�ת��������TradeCode=202002
struct CThostFtdcTransferFutureToBankReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TThostFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TThostFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///�ڻ��ʽ�ת����������Ӧ
struct CThostFtdcTransferFutureToBankRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TThostFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TThostFtdcMoneyType	CustFee;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ�����ʽ�����TradeCode=204002
struct CThostFtdcTransferQryBankReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ�����ʽ�������Ӧ
struct CThostFtdcTransferQryBankRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�������
	TThostFtdcMoneyType	TradeAmt;
	///���п������
	TThostFtdcMoneyType	UseAmt;
	///���п�ȡ���
	TThostFtdcMoneyType	FetchAmt;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ���н�����ϸ����TradeCode=204999
struct CThostFtdcTransferQryDetailReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
};

///��ѯ���н�����ϸ������Ӧ
struct CThostFtdcTransferQryDetailRspField
{
	///��������
	TThostFtdcDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///���״���
	TThostFtdcTradeCodeType	TradeCode;
	///�ڻ���ˮ��
	TThostFtdcTradeSerialNoType	FutureSerial;
	///�ڻ���˾����
	TThostFtdcFutureIDType	FutureID;
	///�ʽ��ʺ�
	TThostFtdcFutureAccountType	FutureAccount;
	///������ˮ��
	TThostFtdcTradeSerialNoType	BankSerial;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///�����˺�
	TThostFtdcBankAccountType	BankAccount;
	///֤������
	TThostFtdcCertCodeType	CertCode;
	///���Ҵ���
	TThostFtdcCurrencyCodeType	CurrencyCode;
	///�������
	TThostFtdcMoneyType	TxAmount;
	///��Ч��־
	TThostFtdcTransferValidFlagType	Flag;
};

///��Ӧ��Ϣ
struct CThostFtdcRspInfoField
{
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///������
struct CThostFtdcExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������
	TThostFtdcExchangeNameType	ExchangeName;
	///����������
	TThostFtdcExchangePropertyType	ExchangeProperty;
};

///��Ʒ
struct CThostFtdcProductField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Ʒ����
	TThostFtdcProductNameType	ProductName;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
	///��Լ��������
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TThostFtdcPriceType	PriceTick;
	///�м۵�����µ���
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///�ֲ�����
	TThostFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TThostFtdcPositionDateTypeType	PositionDateType;
	///ƽ�ִ�������
	TThostFtdcCloseDealTypeType	CloseDealType;
	///���ױ�������
	TThostFtdcCurrencyIDType	TradeCurrencyID;
	///��Ѻ�ʽ���÷�Χ
	TThostFtdcMortgageFundUseRangeType	MortgageFundUseRange;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///��Լ������Ʒ����
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��������Ʒ����
	TThostFtdcInstrumentIDType	ExchangeProductID;
	///��������������
	TThostFtdcOpenLimitControlLevelType	OpenLimitControlLevel;
	///����Ƶ�ʿ�������
	TThostFtdcOrderFreqControlLevelType	OrderFreqControlLevel;
};

///��Լ
struct CThostFtdcInstrumentField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentNameType	InstrumentName;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve3;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
	///�������
	TThostFtdcYearType	DeliveryYear;
	///������
	TThostFtdcMonthType	DeliveryMonth;
	///�м۵�����µ���
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///��Լ��������
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TThostFtdcPriceType	PriceTick;
	///������
	TThostFtdcDateType	CreateDate;
	///������
	TThostFtdcDateType	OpenDate;
	///������
	TThostFtdcDateType	ExpireDate;
	///��ʼ������
	TThostFtdcDateType	StartDelivDate;
	///����������
	TThostFtdcDateType	EndDelivDate;
	///��Լ��������״̬
	TThostFtdcInstLifePhaseType	InstLifePhase;
	///��ǰ�Ƿ���
	TThostFtdcBoolType	IsTrading;
	///�ֲ�����
	TThostFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TThostFtdcPositionDateTypeType	PositionDateType;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatio;
	///�Ƿ�ʹ�ô��߱�֤���㷨
	TThostFtdcMaxMarginSideAlgorithmType	MaxMarginSideAlgorithm;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve4;
	///ִ�м�
	TThostFtdcPriceType	StrikePrice;
	///��Ȩ����
	TThostFtdcOptionsTypeType	OptionsType;
	///��Լ������Ʒ����
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�������
	TThostFtdcCombinationTypeType	CombinationType;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///������Ʒ����
	TThostFtdcInstrumentIDType	UnderlyingInstrID;
};

///���͹�˾
struct CThostFtdcBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾���
	TThostFtdcBrokerAbbrType	BrokerAbbr;
	///���͹�˾����
	TThostFtdcBrokerNameType	BrokerName;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
};

///����������Ա
struct CThostFtdcTraderField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ����
	TThostFtdcInstallCountType	InstallCount;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����ʱѡ��ϯλ�㷨
	TThostFtdcOrderCancelAlgType	OrderCancelAlg;
	///���ױ��̰�װ����
	TThostFtdcInstallCountType	TradeInstallCount;
	///���鱨�̰�װ����
	TThostFtdcInstallCountType	MDInstallCount;
};

///Ͷ����
struct CThostFtdcInvestorField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TThostFtdcPartyNameType	InvestorName;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ֻ�
	TThostFtdcMobileType	Mobile;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
	///�Ƿ�Ƶ�ʿ���
	TThostFtdcEnumBoolType	IsOrderFreq;
	///�Ƿ񿪲�����
	TThostFtdcEnumBoolType	IsOpenVolLimit;
};

///���ױ���
struct CThostFtdcTradingCodeField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///ҵ������
	TThostFtdcBizTypeType	BizType;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///��Ա����;��͹�˾������ձ�
struct CThostFtdcPartBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
};

///�����û�
struct CThostFtdcSuperUserField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û�����
	TThostFtdcUserNameType	UserName;
	///����
	TThostFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
};

///�����û�����Ȩ��
struct CThostFtdcSuperUserFunctionField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���ܴ���
	TThostFtdcFunctionCodeType	FunctionCode;
};

///Ͷ������
struct CThostFtdcInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

///�ʽ��˻�
struct CThostFtdcTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TThostFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TThostFtdcMoneyType	PreCredit;
	///�ϴδ���
	TThostFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///��Ϣ����
	TThostFtdcMoneyType	InterestBase;
	///��Ϣ����
	TThostFtdcMoneyType	Interest;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TThostFtdcMoneyType	WithdrawQuota;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ö��
	TThostFtdcMoneyType	Credit;
	///��Ѻ���
	TThostFtdcMoneyType	Mortgage;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///�����ڻ�����׼����
	TThostFtdcMoneyType	ReserveBalance;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ϴλ���������
	TThostFtdcMoneyType	PreFundMortgageIn;
	///�ϴλ����ʳ����
	TThostFtdcMoneyType	PreFundMortgageOut;
	///����������
	TThostFtdcMoneyType	FundMortgageIn;
	///�����ʳ����
	TThostFtdcMoneyType	FundMortgageOut;
	///������Ѻ���
	TThostFtdcMoneyType	FundMortgageAvailable;
	///����Ѻ���ҽ��
	TThostFtdcMoneyType	MortgageableFund;
	///�����Ʒռ�ñ�֤��
	TThostFtdcMoneyType	SpecProductMargin;
	///�����Ʒ���ᱣ֤��
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///�����Ʒ������
	TThostFtdcMoneyType	SpecProductCommission;
	///�����Ʒ����������
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///�����Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///�����Ʒƽ��ӯ��
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///�����Ʒ��������֤��
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	///ҵ������
	TThostFtdcBizTypeType	BizType;
	///��ʱ���㶳����
	TThostFtdcMoneyType	FrozenSwap;
	///ʣ�໻����
	TThostFtdcMoneyType	RemainSwap;
};

///Ͷ���ֲ߳�
struct CThostFtdcInvestorPositionField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TThostFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TThostFtdcVolumeType	YdPosition;
	///���ճֲ�
	TThostFtdcVolumeType	Position;
	///��ͷ����
	TThostFtdcVolumeType	LongFrozen;
	///��ͷ����
	TThostFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TThostFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TThostFtdcMoneyType	ShortFrozenAmount;
	///������
	TThostFtdcVolumeType	OpenVolume;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///���ֽ��
	TThostFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TThostFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TThostFtdcMoneyType	OpenCost;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TThostFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TThostFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TThostFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TThostFtdcVolumeType	TodayPosition;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///ִ�ж���
	TThostFtdcVolumeType	StrikeFrozen;
	///ִ�ж�����
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TThostFtdcVolumeType	AbandonFrozen;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ�ж�������
	TThostFtdcVolumeType	YdStrikeFrozen;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ֲֳɱ���ֵ
	TThostFtdcMoneyType	PositionCostOffset;
	///tas�ֲ�����
	TThostFtdcVolumeType	TasPosition;
	///tas�ֲֳɱ�
	TThostFtdcMoneyType	TasPositionCost;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Լ��֤����
struct CThostFtdcInstrumentMarginRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Լ��������
struct CThostFtdcInstrumentCommissionRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ҵ������
	TThostFtdcBizTypeType	BizType;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�������
struct CThostFtdcDepthMarketDataField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
	///������
	TThostFtdcPriceType	ClosePrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///�����һ
	TThostFtdcPriceType	BidPrice1;
	///������һ
	TThostFtdcVolumeType	BidVolume1;
	///������һ
	TThostFtdcPriceType	AskPrice1;
	///������һ
	TThostFtdcVolumeType	AskVolume1;
	///����۶�
	TThostFtdcPriceType	BidPrice2;
	///��������
	TThostFtdcVolumeType	BidVolume2;
	///�����۶�
	TThostFtdcPriceType	AskPrice2;
	///��������
	TThostFtdcVolumeType	AskVolume2;
	///�������
	TThostFtdcPriceType	BidPrice3;
	///��������
	TThostFtdcVolumeType	BidVolume3;
	///��������
	TThostFtdcPriceType	AskPrice3;
	///��������
	TThostFtdcVolumeType	AskVolume3;
	///�������
	TThostFtdcPriceType	BidPrice4;
	///��������
	TThostFtdcVolumeType	BidVolume4;
	///��������
	TThostFtdcPriceType	AskPrice4;
	///��������
	TThostFtdcVolumeType	AskVolume4;
	///�������
	TThostFtdcPriceType	BidPrice5;
	///��������
	TThostFtdcVolumeType	BidVolume5;
	///��������
	TThostFtdcPriceType	AskPrice5;
	///��������
	TThostFtdcVolumeType	AskVolume5;
	///���վ���
	TThostFtdcPriceType	AveragePrice;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///�ϴ���
	TThostFtdcPriceType	BandingUpperPrice;
	///�´���
	TThostFtdcPriceType	BandingLowerPrice;
};

///Ͷ���ߺ�Լ����Ȩ��
struct CThostFtdcInstrumentTradingRightField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���͹�˾�û�
struct CThostFtdcBrokerUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û�����
	TThostFtdcUserNameType	UserName;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///�Ƿ�ʹ������
	TThostFtdcBoolType	IsUsingOTP;
	///�Ƿ�ǿ���ն���֤
	TThostFtdcBoolType	IsAuthForce;
};

///���͹�˾�û�����
struct CThostFtdcBrokerUserPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�ϴ��޸�ʱ��
	TThostFtdcDateTimeType	LastUpdateTime;
	///�ϴε�½ʱ��
	TThostFtdcDateTimeType	LastLoginTime;
	///�������ʱ��
	TThostFtdcDateType	ExpireDate;
	///���������ʱ��
	TThostFtdcDateType	WeakExpireDate;
};

///���͹�˾�û�����Ȩ��
struct CThostFtdcBrokerUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���͹�˾���ܴ���
	TThostFtdcBrokerFunctionCodeType	BrokerFunctionCode;
};

///����������Ա���̻�
struct CThostFtdcTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TThostFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TThostFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�����������
	TThostFtdcDateType	ConnectDate;
	///�������ʱ��
	TThostFtdcTimeType	ConnectTime;
	///��������
	TThostFtdcDateType	StartDate;
	///����ʱ��
	TThostFtdcTimeType	StartTime;
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TThostFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
	///����ʱѡ��ϯλ�㷨
	TThostFtdcOrderCancelAlgType	OrderCancelAlg;
};

///Ͷ���߽�����
struct CThostFtdcSettlementInfoField
{
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TThostFtdcContentType	Content;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��Լ��֤���ʵ���
struct CThostFtdcInstrumentMarginRateAdjustField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��������֤����
struct CThostFtdcExchangeMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��������֤���ʵ���
struct CThostFtdcExchangeMarginRateAdjustField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///���潻����Ͷ���߶�ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///���潻����Ͷ���߶�ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///���潻����Ͷ���߿�ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///���潻����Ͷ���߿�ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///��������ͷ��֤����
	TThostFtdcRatioType	ExchLongMarginRatioByMoney;
	///��������ͷ��֤���
	TThostFtdcMoneyType	ExchLongMarginRatioByVolume;
	///��������ͷ��֤����
	TThostFtdcRatioType	ExchShortMarginRatioByMoney;
	///��������ͷ��֤���
	TThostFtdcMoneyType	ExchShortMarginRatioByVolume;
	///�����潻����Ͷ���߶�ͷ��֤����
	TThostFtdcRatioType	NoLongMarginRatioByMoney;
	///�����潻����Ͷ���߶�ͷ��֤���
	TThostFtdcMoneyType	NoLongMarginRatioByVolume;
	///�����潻����Ͷ���߿�ͷ��֤����
	TThostFtdcRatioType	NoShortMarginRatioByMoney;
	///�����潻����Ͷ���߿�ͷ��֤���
	TThostFtdcMoneyType	NoShortMarginRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����
struct CThostFtdcExchangeRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Դ���ֵ�λ����
	TThostFtdcCurrencyUnitType	FromCurrencyUnit;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
	///����
	TThostFtdcExchangeRateType	ExchangeRate;
};

///��������
struct CThostFtdcSettlementRefField
{
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
};

///��ǰʱ��
struct CThostFtdcCurrentTimeField
{
	///��ǰ������
	TThostFtdcDateType	CurrDate;
	///��ǰʱ��
	TThostFtdcTimeType	CurrTime;
	///��ǰʱ�䣨���룩
	TThostFtdcMillisecType	CurrMillisec;
	///��Ȼ����
	TThostFtdcDateType	ActionDay;
};

///ͨѶ�׶�
struct CThostFtdcCommPhaseField
{
	///������
	TThostFtdcDateType	TradingDay;
	///ͨѶʱ�α��
	TThostFtdcCommPhaseNoType	CommPhaseNo;
	///ϵͳ���
	TThostFtdcSystemIDType	SystemID;
};

///��¼��Ϣ
struct CThostFtdcLoginInfoField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼����
	TThostFtdcDateType	LoginDate;
	///��¼ʱ��
	TThostFtdcTimeType	LoginTime;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///ϵͳ����
	TThostFtdcSystemNameType	SystemName;
	///����,������
	TThostFtdcPasswordType	PasswordDeprecated;
	///��󱨵�����
	TThostFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TThostFtdcTimeType	SHFETime;
	///������ʱ��
	TThostFtdcTimeType	DCETime;
	///֣����ʱ��
	TThostFtdcTimeType	CZCETime;
	///�н���ʱ��
	TThostFtdcTimeType	FFEXTime;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��̬����
	TThostFtdcPasswordType	OneTimePassword;
	///��Դ����ʱ��
	TThostFtdcTimeType	INETime;
	///��ѯʱ�Ƿ���Ҫ����
	TThostFtdcBoolType	IsQryControl;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///����
	TThostFtdcPasswordType	Password;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��¼��Ϣ
struct CThostFtdcLogoutAllField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///ϵͳ����
	TThostFtdcSystemNameType	SystemName;
};

///ǰ��״̬
struct CThostFtdcFrontStatusField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
};

///�û�������
struct CThostFtdcUserPasswordUpdateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
};

///���뱨��
struct CThostFtdcInputOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿƽ��־
	TThostFtdcBoolType	UserForceClose;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///����
struct CThostFtdcOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�û�ǿƽ��־
	TThostFtdcBoolType	UserForceClose;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///֣�����ɽ�����
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///����������
struct CThostFtdcExchangeOrderField
{
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��������������ʧ��
struct CThostFtdcExchangeOrderInsertErrorField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///���뱨������
struct CThostFtdcInputOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///��������
struct CThostFtdcOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///��������������
struct CThostFtdcExchangeOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��������������ʧ��
struct CThostFtdcExchangeOrderActionErrorField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///�������ɽ�
struct CThostFtdcExchangeTradeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��������
	TThostFtdcDirectionType	Direction;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���׽�ɫ
	TThostFtdcTradingRoleType	TradingRole;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TThostFtdcPriceType	Price;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TThostFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TThostFtdcTimeType	TradeTime;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TThostFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�ɽ���Դ
	TThostFtdcTradeSourceType	TradeSource;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///�ɽ�
struct CThostFtdcTradeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��������
	TThostFtdcDirectionType	Direction;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���׽�ɫ
	TThostFtdcTradingRoleType	TradingRole;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TThostFtdcPriceType	Price;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TThostFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TThostFtdcTimeType	TradeTime;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TThostFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///�ɽ���Դ
	TThostFtdcTradeSourceType	TradeSource;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///�û��Ự
struct CThostFtdcUserSessionField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼����
	TThostFtdcDateType	LoginDate;
	///��¼ʱ��
	TThostFtdcTimeType	LoginTime;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ��󱨵�����
struct CThostFtdcQryMaxOrderVolumeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcDirectionType	Direction;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///���������������
	TThostFtdcVolumeType	MaxVolume;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���߽�����ȷ����Ϣ
struct CThostFtdcSettlementInfoConfirmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ȷ������
	TThostFtdcDateType	ConfirmDate;
	///ȷ��ʱ��
	TThostFtdcTimeType	ConfirmTime;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///�����ͬ��
struct CThostFtdcSyncDepositField
{
	///�������ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����
	TThostFtdcMoneyType	Deposit;
	///�Ƿ�ǿ�ƽ���
	TThostFtdcBoolType	IsForce;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�Ƿ��Ǹ�����Ȩ��ת
	TThostFtdcBoolType	IsFromSopt;
	///�ʽ�����
	TThostFtdcPasswordType	TradingPassword;
	///�Ƿ���������̵���ת
	TThostFtdcBoolType	IsSecAgentTranfer;
};

///������Ѻͬ��
struct CThostFtdcSyncFundMortgageField
{
	///������Ѻ��ˮ��
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///��Ѻ���
	TThostFtdcMoneyType	MortgageAmount;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

///���͹�˾ͬ��
struct CThostFtdcBrokerSyncField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///����ͬ���е�Ͷ����
struct CThostFtdcSyncingInvestorField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TThostFtdcPartyNameType	InvestorName;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ֻ�
	TThostFtdcMobileType	Mobile;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
	///�Ƿ�Ƶ�ʿ���
	TThostFtdcEnumBoolType	IsOrderFreq;
	///�Ƿ񿪲�����
	TThostFtdcEnumBoolType	IsOpenVolLimit;
};

///����ͬ���еĽ��״���
struct CThostFtdcSyncingTradingCodeField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
};

///����ͬ���е�Ͷ���߷���
struct CThostFtdcSyncingInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

///����ͬ���еĽ����˺�
struct CThostFtdcSyncingTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TThostFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TThostFtdcMoneyType	PreCredit;
	///�ϴδ���
	TThostFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///��Ϣ����
	TThostFtdcMoneyType	InterestBase;
	///��Ϣ����
	TThostFtdcMoneyType	Interest;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TThostFtdcMoneyType	WithdrawQuota;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ö��
	TThostFtdcMoneyType	Credit;
	///��Ѻ���
	TThostFtdcMoneyType	Mortgage;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///�����ڻ�����׼����
	TThostFtdcMoneyType	ReserveBalance;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ϴλ���������
	TThostFtdcMoneyType	PreFundMortgageIn;
	///�ϴλ����ʳ����
	TThostFtdcMoneyType	PreFundMortgageOut;
	///����������
	TThostFtdcMoneyType	FundMortgageIn;
	///�����ʳ����
	TThostFtdcMoneyType	FundMortgageOut;
	///������Ѻ���
	TThostFtdcMoneyType	FundMortgageAvailable;
	///����Ѻ���ҽ��
	TThostFtdcMoneyType	MortgageableFund;
	///�����Ʒռ�ñ�֤��
	TThostFtdcMoneyType	SpecProductMargin;
	///�����Ʒ���ᱣ֤��
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///�����Ʒ������
	TThostFtdcMoneyType	SpecProductCommission;
	///�����Ʒ����������
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///�����Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///�����Ʒƽ��ӯ��
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///�����Ʒ��������֤��
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	///��ʱ���㶳����
	TThostFtdcMoneyType	FrozenSwap;
	///ʣ�໻����
	TThostFtdcMoneyType	RemainSwap;
};

///����ͬ���е�Ͷ���ֲ߳�
struct CThostFtdcSyncingInvestorPositionField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TThostFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TThostFtdcVolumeType	YdPosition;
	///���ճֲ�
	TThostFtdcVolumeType	Position;
	///��ͷ����
	TThostFtdcVolumeType	LongFrozen;
	///��ͷ����
	TThostFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TThostFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TThostFtdcMoneyType	ShortFrozenAmount;
	///������
	TThostFtdcVolumeType	OpenVolume;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///���ֽ��
	TThostFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TThostFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TThostFtdcMoneyType	OpenCost;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TThostFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TThostFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TThostFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TThostFtdcVolumeType	TodayPosition;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///ִ�ж���
	TThostFtdcVolumeType	StrikeFrozen;
	///ִ�ж�����
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TThostFtdcVolumeType	AbandonFrozen;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ�ж�������
	TThostFtdcVolumeType	YdStrikeFrozen;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ֲֳɱ���ֵ
	TThostFtdcMoneyType	PositionCostOffset;
	///tas�ֲ�����
	TThostFtdcVolumeType	TasPosition;
	///tas�ֲֳɱ�
	TThostFtdcMoneyType	TasPositionCost;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����ͬ���еĺ�Լ��֤����
struct CThostFtdcSyncingInstrumentMarginRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����ͬ���еĺ�Լ��������
struct CThostFtdcSyncingInstrumentCommissionRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����ͬ���еĺ�Լ����Ȩ��
struct CThostFtdcSyncingInstrumentTradingRightField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ����
struct CThostFtdcQryOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ɽ�
struct CThostFtdcQryTradeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��ʼʱ��
	TThostFtdcTimeType	TradeTimeStart;
	///����ʱ��
	TThostFtdcTimeType	TradeTimeEnd;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯͶ���ֲ߳�
struct CThostFtdcQryInvestorPositionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ʽ��˻�
struct CThostFtdcQryTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ҵ������
	TThostFtdcBizTypeType	BizType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
};

///��ѯͶ����
struct CThostFtdcQryInvestorField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///��ѯ���ױ���
struct CThostFtdcQryTradingCodeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///��ѯͶ������
struct CThostFtdcQryInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///��ѯ��Լ��֤����
struct CThostFtdcQryInstrumentMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ��������
struct CThostFtdcQryInstrumentCommissionRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ��Լ����Ȩ��
struct CThostFtdcQryInstrumentTradingRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���͹�˾
struct CThostFtdcQryBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///��ѯ����Ա
struct CThostFtdcQryTraderField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///��ѯ�����û�����Ȩ��
struct CThostFtdcQrySuperUserFunctionField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///��ѯ�û��Ự
struct CThostFtdcQryUserSessionField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///��ѯ���͹�˾��Ա����
struct CThostFtdcQryPartBrokerField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
};

///��ѯǰ��״̬
struct CThostFtdcQryFrontStatusField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
};

///��ѯ����������
struct CThostFtdcQryExchangeOrderField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///��ѯ��������
struct CThostFtdcQryOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///��ѯ��������������
struct CThostFtdcQryExchangeOrderActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///��ѯ�����û�
struct CThostFtdcQrySuperUserField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///��ѯ������
struct CThostFtdcQryExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///��ѯ��Ʒ
struct CThostFtdcQryProductField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///��ѯ��Լ
struct CThostFtdcQryInstrumentField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve3;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///��ѯ����
struct CThostFtdcQryDepthMarketDataField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
};

///��ѯ���͹�˾�û�
struct CThostFtdcQryBrokerUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///��ѯ���͹�˾�û�Ȩ��
struct CThostFtdcQryBrokerUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///��ѯ����Ա���̻�
struct CThostFtdcQryTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///��ѯ�������ˮ
struct CThostFtdcQrySyncDepositField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�������ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
};

///��ѯͶ���߽�����
struct CThostFtdcQrySettlementInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������
	TThostFtdcDateType	TradingDay;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��ѯ��������֤����
struct CThostFtdcQryExchangeMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ������������֤����
struct CThostFtdcQryExchangeMarginRateAdjustField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ����
struct CThostFtdcQryExchangeRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

///��ѯ������Ѻ��ˮ
struct CThostFtdcQrySyncFundMortgageField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///������Ѻ��ˮ��
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
};

///��ѯ����
struct CThostFtdcQryHisOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ��Ȩ��Լ��С��֤��
struct CThostFtdcOptionInstrMiniMarginField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��λ���֣���Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	MinMargin;
	///ȡֵ��ʽ
	TThostFtdcValueMethodType	ValueMethod;
	///�Ƿ���潻������ȡ
	TThostFtdcBoolType	IsRelative;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ��Ȩ��Լ��֤�����ϵ��
struct CThostFtdcOptionInstrMarginAdjustField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	///������ͷ��֤�����ϵ��
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	///������ͷ��֤�����ϵ��
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	///�Ƿ���潻������ȡ
	TThostFtdcBoolType	IsRelative;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ��Ȩ��Լ�����ѵ���ϸ����
struct CThostFtdcOptionInstrCommRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TThostFtdcRatioType	StrikeRatioByMoney;
	///ִ��������
	TThostFtdcRatioType	StrikeRatioByVolume;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Ȩ���׳ɱ�
struct CThostFtdcOptionInstrTradeCostField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Լ��֤�𲻱䲿��
	TThostFtdcMoneyType	FixedMargin;
	///��Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	MiniMargin;
	///��Ȩ��ԼȨ����
	TThostFtdcMoneyType	Royalty;
	///��������Ȩ��Լ��֤�𲻱䲿��
	TThostFtdcMoneyType	ExchFixedMargin;
	///��������Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	ExchMiniMargin;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Ȩ���׳ɱ���ѯ
struct CThostFtdcQryOptionInstrTradeCostField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Լ����
	TThostFtdcPriceType	InputPrice;
	///��ļ۸�,��0����������
	TThostFtdcPriceType	UnderlyingPrice;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Ȩ�������ʲ�ѯ
struct CThostFtdcQryOptionInstrCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ָ�ֻ�ָ��
struct CThostFtdcIndexPriceField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ָ���ֻ����̼�
	TThostFtdcPriceType	ClosePrice;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�����ִ������
struct CThostFtdcInputExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��,���ֶ��ѷ���
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///����ִ���������
struct CThostFtdcInputExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///ִ������
struct CThostFtdcExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��,���ֶ��ѷ���
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///ִ�������ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///ִ�н��
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerExecOrderSeq;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///ִ���������
struct CThostFtdcExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///ִ�������ѯ
struct CThostFtdcQryExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///������ִ��������Ϣ
struct CThostFtdcExchangeExecOrderField
{
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��,���ֶ��ѷ���
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///ִ�������ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///ִ�н��
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������ִ�������ѯ
struct CThostFtdcQryExchangeExecOrderField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///ִ�����������ѯ
struct CThostFtdcQryExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///������ִ���������
struct CThostFtdcExchangeExecOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����
	TThostFtdcVolumeType	Volume;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///������ִ�����������ѯ
struct CThostFtdcQryExchangeExecOrderActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///����ִ������
struct CThostFtdcErrExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��,���ֶ��ѷ���
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ����ִ������
struct CThostFtdcQryErrExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///����ִ���������
struct CThostFtdcErrExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ����ִ���������
struct CThostFtdcQryErrExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///Ͷ������Ȩ��Լ����Ȩ��
struct CThostFtdcOptionInstrTradingRightField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ��Ȩ��Լ����Ȩ��
struct CThostFtdcQryOptionInstrTradingRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�����ѯ��
struct CThostFtdcInputForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ѯ������
	TThostFtdcOrderRefType	ForQuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///ѯ��
struct CThostFtdcForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ѯ������
	TThostFtdcOrderRefType	ForQuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ѯ�۱��
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///ѯ��״̬
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾ѯ�۱��
	TThostFtdcSequenceNoType	BrokerForQutoSeq;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///ѯ�۲�ѯ
struct CThostFtdcQryForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///������ѯ����Ϣ
struct CThostFtdcExchangeForQuoteField
{
	///����ѯ�۱��
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///ѯ��״̬
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������ѯ�۲�ѯ
struct CThostFtdcQryExchangeForQuoteField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///����ı���
struct CThostFtdcInputQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///��������������
	TThostFtdcOrderRefType	AskOrderRef;
	///�����򱨵�����
	TThostFtdcOrderRefType	BidOrderRef;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������
	TThostFtdcOrderSysIDType	ReplaceSysID;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///���뱨�۲���
struct CThostFtdcInputQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���۲�������
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///����
struct CThostFtdcQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����״̬
	TThostFtdcOrderStatusType	QuoteStatus;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�����������
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///�򷽱������
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾���۱��
	TThostFtdcSequenceNoType	BrokerQuoteSeq;
	///��������������
	TThostFtdcOrderRefType	AskOrderRef;
	///�����򱨵�����
	TThostFtdcOrderRefType	BidOrderRef;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������
	TThostFtdcOrderSysIDType	ReplaceSysID;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///���۲���
struct CThostFtdcQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���۲�������
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///���۲�ѯ
struct CThostFtdcQryQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///������������Ϣ
struct CThostFtdcExchangeQuoteField
{
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����״̬
	TThostFtdcOrderStatusType	QuoteStatus;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�����������
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///�򷽱������
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
};

///���������۲�ѯ
struct CThostFtdcQryExchangeQuoteField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///���۲�����ѯ
struct CThostFtdcQryQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///���������۲���
struct CThostFtdcExchangeQuoteActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///���������۲�����ѯ
struct CThostFtdcQryExchangeQuoteActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///��Ȩ��Լdeltaֵ
struct CThostFtdcOptionInstrDeltaField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Deltaֵ
	TThostFtdcRatioType	Delta;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���������̵�ѯ������
struct CThostFtdcForQuoteRspField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///ѯ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///ѯ��ʱ��
	TThostFtdcTimeType	ForQuoteTime;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ��Ȩ��Լִ��ƫ��ֵ����ϸ����
struct CThostFtdcStrikeOffsetField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ��ƫ��ֵ
	TThostFtdcMoneyType	Offset;
	///ִ��ƫ������
	TThostFtdcStrikeOffsetTypeType	OffsetType;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Ȩִ��ƫ��ֵ��ѯ
struct CThostFtdcQryStrikeOffsetField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����������������
struct CThostFtdcInputBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������������
struct CThostFtdcBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������������������
struct CThostFtdcExchangeBatchOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ������������
struct CThostFtdcQryBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///��Ϻ�Լ��ȫϵ��
struct CThostFtdcCombInstrumentGuardField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///
	TThostFtdcRatioType	GuarantRatio;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Ϻ�Լ��ȫϵ����ѯ
struct CThostFtdcQryCombInstrumentGuardField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///������������
struct CThostFtdcInputCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///�������
	TThostFtdcOrderRefType	CombActionRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///�������
struct CThostFtdcCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///�������
	TThostFtdcOrderRefType	CombActionRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������ϱ��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���״̬
	TThostFtdcOrderActionStatusType	ActionStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��ϱ��
	TThostFtdcTradeIDType	ComTradeID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������ϲ�ѯ
struct CThostFtdcQryCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���������������Ϣ
struct CThostFtdcExchangeCombActionField
{
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������ϱ��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���״̬
	TThostFtdcOrderActionStatusType	ActionStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��ϱ��
	TThostFtdcTradeIDType	ComTradeID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������������ϲ�ѯ
struct CThostFtdcQryExchangeCombActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///��Ʒ���ۻ���
struct CThostFtdcProductExchRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���۱�������
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	///����
	TThostFtdcExchangeRateType	ExchangeRate;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///��Ʒ���ۻ��ʲ�ѯ
struct CThostFtdcQryProductExchRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///��ѯѯ�ۼ۲����
struct CThostFtdcQryForQuoteParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///ѯ�ۼ۲����
struct CThostFtdcForQuoteParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�۲�
	TThostFtdcPriceType	PriceInterval;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ��������Ȩ��Լ�����ѵ���ϸ����
struct CThostFtdcMMOptionInstrCommRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TThostFtdcRatioType	StrikeRatioByMoney;
	///ִ��������
	TThostFtdcRatioType	StrikeRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��������Ȩ�������ʲ�ѯ
struct CThostFtdcQryMMOptionInstrCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�����̺�Լ��������
struct CThostFtdcMMInstrumentCommissionRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�����̺�Լ��������
struct CThostFtdcQryMMInstrumentCommissionRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ǰ���������ѵ���ϸ����
struct CThostFtdcInstrumentOrderCommRateField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcRatioType	OrderCommByVolume;
	///����������
	TThostFtdcRatioType	OrderActionCommByVolume;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcRatioType	OrderCommByTrade;
	///����������
	TThostFtdcRatioType	OrderActionCommByTrade;
};

///�����������ʲ�ѯ
struct CThostFtdcQryInstrumentOrderCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���ײ���
struct CThostFtdcTradeParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������
	TThostFtdcTradeParamIDType	TradeParamID;
	///��������ֵ
	TThostFtdcSettlementParamValueType	TradeParamValue;
	///��ע
	TThostFtdcMemoType	Memo;
};

///��Լ��֤���ʵ���
struct CThostFtdcInstrumentMarginRateULField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�ڻ��ֲ����Ʋ���
struct CThostFtdcFutureLimitPosiParamField
{
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����Ͷ��������������
	TThostFtdcVolumeType	SpecOpenVolume;
	///��������������������
	TThostFtdcVolumeType	ArbiOpenVolume;
	///����Ͷ��+����������������
	TThostFtdcVolumeType	OpenVolume;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///��ֹ��¼IP
struct CThostFtdcLoginForbiddenIPField
{
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///IP�б�
struct CThostFtdcIPListField
{
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///�Ƿ������
	TThostFtdcBoolType	IsWhite;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///�������Ȩ�ԶԳ�
struct CThostFtdcInputOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������Ȩ�ԶԳ����
struct CThostFtdcInputOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ȩ�ԶԳ��������
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��Ȩ�ԶԳ�
struct CThostFtdcOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��Ȩ�ԶԳ��ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///�ԶԳ���
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��Ȩ�ԶԳ����
struct CThostFtdcOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ȩ�ԶԳ��������
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��Ȩ�ԶԳ��ѯ
struct CThostFtdcQryOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��������Ȩ�ԶԳ���Ϣ
struct CThostFtdcExchangeOptionSelfCloseField
{
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��Ȩ�ԶԳ��ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///�ԶԳ���
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��Ȩ�ԶԳ������ѯ
struct CThostFtdcQryOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///��������Ȩ�ԶԳ����
struct CThostFtdcExchangeOptionSelfCloseActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///��ʱ����ͬ��
struct CThostFtdcSyncDelaySwapField
{
	///������ˮ��
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Դ���
	TThostFtdcMoneyType	FromAmount;
	///Դ���㶳����(���ö���)
	TThostFtdcMoneyType	FromFrozenSwap;
	///Դʣ�໻����(���ᶳ��)
	TThostFtdcMoneyType	FromRemainSwap;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
	///Ŀ����
	TThostFtdcMoneyType	ToAmount;
	///�Ƿ��ֹ�����
	TThostFtdcBoolType	IsManualSwap;
	///�Ƿ�������ҵ�ʣ�໻��������Ϊ0
	TThostFtdcBoolType	IsAllRemainSetZero;
};

///��ѯ��ʱ����ͬ��
struct CThostFtdcQrySyncDelaySwapField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��ʱ������ˮ��
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
};

///Ͷ�ʵ�Ԫ
struct CThostFtdcInvestUnitField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///Ͷ���ߵ�Ԫ����
	TThostFtdcPartyNameType	InvestorUnitName;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��ѯͶ�ʵ�Ԫ
struct CThostFtdcQryInvestUnitField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///�����������ʽ�У��ģʽ
struct CThostFtdcSecAgentCheckModeField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����
	TThostFtdcCurrencyIDType	CurrencyID;
	///�����н�����ʽ��ʺ�
	TThostFtdcAccountIDType	BrokerSecAgentID;
	///�Ƿ���ҪУ���Լ����ʽ��˻�
	TThostFtdcBoolType	CheckSelfAccount;
};

///������������Ϣ
struct CThostFtdcSecAgentTradeInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�����н�����ʽ��ʺ�
	TThostFtdcAccountIDType	BrokerSecAgentID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������������
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///�г�����
struct CThostFtdcMarketDataField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
	///������
	TThostFtdcPriceType	ClosePrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///�����������
struct CThostFtdcMarketDataBaseField
{
	///������
	TThostFtdcDateType	TradingDay;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
};

///���龲̬����
struct CThostFtdcMarketDataStaticField
{
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///������
	TThostFtdcPriceType	ClosePrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CThostFtdcMarketDataLastMatchField
{
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CThostFtdcMarketDataBestPriceField
{
	///�����һ
	TThostFtdcPriceType	BidPrice1;
	///������һ
	TThostFtdcVolumeType	BidVolume1;
	///������һ
	TThostFtdcPriceType	AskPrice1;
	///������һ
	TThostFtdcVolumeType	AskVolume1;
};

///�����������������
struct CThostFtdcMarketDataBid23Field
{
	///����۶�
	TThostFtdcPriceType	BidPrice2;
	///��������
	TThostFtdcVolumeType	BidVolume2;
	///�������
	TThostFtdcPriceType	BidPrice3;
	///��������
	TThostFtdcVolumeType	BidVolume3;
};

///������������������
struct CThostFtdcMarketDataAsk23Field
{
	///�����۶�
	TThostFtdcPriceType	AskPrice2;
	///��������
	TThostFtdcVolumeType	AskVolume2;
	///��������
	TThostFtdcPriceType	AskPrice3;
	///��������
	TThostFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CThostFtdcMarketDataBid45Field
{
	///�������
	TThostFtdcPriceType	BidPrice4;
	///��������
	TThostFtdcVolumeType	BidVolume4;
	///�������
	TThostFtdcPriceType	BidPrice5;
	///��������
	TThostFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CThostFtdcMarketDataAsk45Field
{
	///��������
	TThostFtdcPriceType	AskPrice4;
	///��������
	TThostFtdcVolumeType	AskVolume4;
	///��������
	TThostFtdcPriceType	AskPrice5;
	///��������
	TThostFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CThostFtdcMarketDataUpdateTimeField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///�������´���
struct CThostFtdcMarketDataBandingPriceField
{
	///�ϴ���
	TThostFtdcPriceType	BandingUpperPrice;
	///�´���
	TThostFtdcPriceType	BandingLowerPrice;
};

///���齻������������
struct CThostFtdcMarketDataExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///ָ���ĺ�Լ
struct CThostFtdcSpecificInstrumentField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��Լ״̬
struct CThostFtdcInstrumentStatusField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///���������
	TThostFtdcSettlementGroupIDType	SettlementGroupID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///��Լ����״̬
	TThostFtdcInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TThostFtdcTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TThostFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TThostFtdcInstStatusEnterReasonType	EnterReason;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ��Լ״̬
struct CThostFtdcQryInstrumentStatusField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve1;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///Ͷ�����˻�
struct CThostFtdcInvestorAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///����ӯ���㷨
struct CThostFtdcPositionProfitAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///ӯ���㷨
	TThostFtdcAlgorithmType	Algorithm;
	///��ע
	TThostFtdcMemoType	Memo;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��Ա�ʽ��ۿ�
struct CThostFtdcDiscountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ʽ��ۿ۱���
	TThostFtdcRatioType	Discount;
};

///��ѯת������
struct CThostFtdcQryTransferBankField
{
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
};

///ת������
struct CThostFtdcTransferBankField
{
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///��������
	TThostFtdcBankNameType	BankName;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
};

///��ѯͶ���ֲ߳���ϸ
struct CThostFtdcQryInvestorPositionDetailField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲ߳���ϸ
struct CThostFtdcInvestorPositionDetailField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///����
	TThostFtdcVolumeType	Volume;
	///���ּ�
	TThostFtdcPriceType	OpenPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///������
	TThostFtdcPriceType	LastSettlementPrice;
	///�����
	TThostFtdcPriceType	SettlementPrice;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ȿ���ƽʣ������
	TThostFtdcVolumeType	TimeFirstVolume;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///����ֱֲ�־
	TThostFtdcSpecPosiTypeType	SpecPosiType;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

///�ʽ��˻�������
struct CThostFtdcTradingAccountPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///���������鱨�̻�
struct CThostFtdcMDTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TThostFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TThostFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�����������
	TThostFtdcDateType	ConnectDate;
	///�������ʱ��
	TThostFtdcTimeType	ConnectTime;
	///��������
	TThostFtdcDateType	StartDate;
	///����ʱ��
	TThostFtdcTimeType	StartTime;
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TThostFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
	///����ʱѡ��ϯλ�㷨
	TThostFtdcOrderCancelAlgType	OrderCancelAlg;
};

///��ѯ���鱨�̻�
struct CThostFtdcQryMDTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
};

///��ѯ�ͻ�֪ͨ
struct CThostFtdcQryNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///�ͻ�֪ͨ
struct CThostFtdcNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ϣ����
	TThostFtdcContentType	Content;
	///���͹�˾֪ͨ�������к�
	TThostFtdcSequenceLabelType	SequenceLabel;
};

///�û�Ȩ��
struct CThostFtdcUserRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ͻ�Ȩ������
	TThostFtdcUserRightTypeType	UserRightType;
	///�Ƿ��ֹ
	TThostFtdcBoolType	IsForbidden;
};

///��ѯ������Ϣȷ����
struct CThostFtdcQrySettlementInfoConfirmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///װ�ؽ�����Ϣ
struct CThostFtdcLoadSettlementInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///���͹�˾�����ʽ��㷨��
struct CThostFtdcBrokerWithdrawAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�����ʽ��㷨
	TThostFtdcAlgorithmType	WithdrawAlgorithm;
	///�ʽ�ʹ����
	TThostFtdcRatioType	UsingRatio;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	IncludeCloseProfit;
	///�����޲����޳ɽ��ͻ��Ƿ��ܿ����������
	TThostFtdcAllWithoutTradeType	AllWithoutTrade;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///�Ƿ������û��¼�
	TThostFtdcBoolType	IsBrokerUserEvent;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������Ѻ����
	TThostFtdcRatioType	FundMortgageRatio;
	///Ȩ���㷨
	TThostFtdcBalanceAlgorithmType	BalanceAlgorithm;
};

///�ʽ��˻���������
struct CThostFtdcTradingAccountPasswordUpdateV1Field
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
};

///�ʽ��˻���������
struct CThostFtdcTradingAccountPasswordUpdateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��ѯ��Ϻ�Լ����
struct CThostFtdcQryCombinationLegField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���Ⱥ�Լ����
	TThostFtdcInstrumentIDType	LegInstrumentID;
};

///��ѯ��Ϻ�Լ����
struct CThostFtdcQrySyncStatusField
{
	///������
	TThostFtdcDateType	TradingDay;
};

///��Ͻ��׺�Լ�ĵ���
struct CThostFtdcCombinationLegField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///��������
	TThostFtdcDirectionType	Direction;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///��������
	TThostFtdcImplyLevelType	ImplyLevel;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���Ⱥ�Լ����
	TThostFtdcInstrumentIDType	LegInstrumentID;
};

///����ͬ��״̬
struct CThostFtdcSyncStatusField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����ͬ��״̬
	TThostFtdcDataSyncStatusType	DataSyncStatus;
};

///��ѯ��ϵ��
struct CThostFtdcQryLinkManField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///��ϵ��
struct CThostFtdcLinkManField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϵ������
	TThostFtdcPersonTypeType	PersonType;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///����
	TThostFtdcPartyNameType	PersonName;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcZipCodeType	ZipCode;
	///���ȼ�
	TThostFtdcPriorityType	Priority;
	///������������
	TThostFtdcUOAZipCodeType	UOAZipCode;
	///ȫ��
	TThostFtdcInvestorFullNameType	PersonFullName;
};

///��ѯ���͹�˾�û��¼�
struct CThostFtdcQryBrokerUserEventField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��¼�����
	TThostFtdcUserEventTypeType	UserEventType;
};

///��ѯ���͹�˾�û��¼�
struct CThostFtdcBrokerUserEventField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��¼�����
	TThostFtdcUserEventTypeType	UserEventType;
	///�û��¼����
	TThostFtdcSequenceNoType	EventSequenceNo;
	///�¼���������
	TThostFtdcDateType	EventDate;
	///�¼�����ʱ��
	TThostFtdcTimeType	EventTime;
	///�û��¼���Ϣ
	TThostFtdcUserEventInfoType	UserEventInfo;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///������
	TThostFtdcDateType	TradingDay;
};

///��ѯǩԼ��������
struct CThostFtdcQryContractBankField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
};

///��ѯǩԼ������Ӧ
struct CThostFtdcContractBankField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///��������
	TThostFtdcBankNameType	BankName;
};

///Ͷ������ϳֲ���ϸ
struct CThostFtdcInvestorPositionCombineDetailField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������
	TThostFtdcDateType	OpenDate;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϱ��
	TThostFtdcTradeIDType	ComTradeID;
	///��ϱ��
	TThostFtdcTradeIDType	TradeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///�ֲ���
	TThostFtdcVolumeType	TotalAmt;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///�ɽ����
	TThostFtdcTradeGroupIDType	TradeGroupID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��ϳֲֺ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

///Ԥ��
struct CThostFtdcParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿƽ��־
	TThostFtdcBoolType	UserForceClose;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ԥ�񱨵����
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///Ԥ��״̬
	TThostFtdcParkedOrderStatusType	Status;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///����Ԥ�񵥲���
struct CThostFtdcParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ԥ�񳷵������
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///Ԥ�񳷵�״̬
	TThostFtdcParkedOrderStatusType	Status;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯԤ��
struct CThostFtdcQryParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯԤ�񳷵�
struct CThostFtdcQryParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///ɾ��Ԥ��
struct CThostFtdcRemoveParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ԥ�񱨵����
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///ɾ��Ԥ�񳷵�
struct CThostFtdcRemoveParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ԥ�񳷵����
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///���͹�˾�����ʽ��㷨��
struct CThostFtdcInvestorWithdrawAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����ʽ����
	TThostFtdcRatioType	UsingRatio;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������Ѻ����
	TThostFtdcRatioType	FundMortgageRatio;
};

///��ѯ��ϳֲ���ϸ
struct CThostFtdcQryInvestorPositionCombineDetailField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��ϳֲֺ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

///�ɽ�����
struct CThostFtdcMarketDataAveragePriceField
{
	///���վ���
	TThostFtdcPriceType	AveragePrice;
};

///У��Ͷ��������
struct CThostFtdcVerifyInvestorPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����
	TThostFtdcPasswordType	Password;
};

///�û�IP
struct CThostFtdcUserIPField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///IP��ַ����
	TThostFtdcIPAddressType	IPMask;
};

///�û��¼�֪ͨ��Ϣ
struct CThostFtdcTradingNoticeInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///��Ϣ����
	TThostFtdcContentType	FieldContent;
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///�û��¼�֪ͨ
struct CThostFtdcTradingNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TThostFtdcContentType	FieldContent;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///��ѯ�����¼�֪ͨ
struct CThostFtdcQryTradingNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///��ѯ���󱨵�
struct CThostFtdcQryErrOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///���󱨵�
struct CThostFtdcErrOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿƽ��־
	TThostFtdcBoolType	UserForceClose;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///��ѯ���󱨵�����
struct CThostFtdcErrorConditionalOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��������Ч�ֶ�
	TThostFtdcOldExchangeInstIDType	reserve2;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�û�ǿƽ��־
	TThostFtdcBoolType	UserForceClose;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///֣�����ɽ�����
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve3;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ���󱨵�����
struct CThostFtdcQryErrOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///���󱨵�����
struct CThostFtdcErrOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve2;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///���������ֶ�
	TThostFtdcOrderMemoType	OrderMemo;
	///session��������� api�Զ�ά��
	TThostFtdcSequenceNo12Type	SessionReqSeq;
};

///��ѯ������״̬
struct CThostFtdcQryExchangeSequenceField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///������״̬
struct CThostFtdcExchangeSequenceField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///��Լ����״̬
	TThostFtdcInstrumentStatusType	MarketStatus;
};

///���ݼ۸��ѯ��󱨵�����
struct CThostFtdcQryMaxOrderVolumeWithPriceField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcDirectionType	Direction;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///���������������
	TThostFtdcVolumeType	MaxVolume;
	///�����۸�
	TThostFtdcPriceType	Price;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���͹�˾���ײ���
struct CThostFtdcQryBrokerTradingParamsField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
};

///���͹�˾���ײ���
struct CThostFtdcBrokerTradingParamsField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��֤��۸�����
	TThostFtdcMarginPriceTypeType	MarginPriceType;
	///ӯ���㷨
	TThostFtdcAlgorithmType	Algorithm;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��ȨȨ����۸�����
	TThostFtdcOptionRoyaltyPriceTypeType	OptionRoyaltyPriceType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
};

///��ѯ���͹�˾�����㷨
struct CThostFtdcQryBrokerTradingAlgosField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���͹�˾�����㷨
struct CThostFtdcBrokerTradingAlgosField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///�ֲִ����㷨���
	TThostFtdcHandlePositionAlgoIDType	HandlePositionAlgoID;
	///Ѱ�ұ�֤�����㷨���
	TThostFtdcFindMarginRateAlgoIDType	FindMarginRateAlgoID;
	///�ʽ����㷨���
	TThostFtdcHandleTradingAccountAlgoIDType	HandleTradingAccountAlgoID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���͹�˾�ʽ�
struct CThostFtdcQueryBrokerDepositField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
};

///���͹�˾�ʽ�
struct CThostFtdcBrokerDepositField
{
	///��������
	TThostFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
};

///��ѯ��֤����ϵͳ���͹�˾��Կ
struct CThostFtdcQryCFMMCBrokerKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///��֤����ϵͳ���͹�˾��Կ
struct CThostFtdcCFMMCBrokerKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///��Կ��������
	TThostFtdcDateType	CreateDate;
	///��Կ����ʱ��
	TThostFtdcTimeType	CreateTime;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TThostFtdcCFMMCKeyType	CurrentKey;
	///��̬��Կ����
	TThostFtdcCFMMCKeyKindType	KeyKind;
};

///��֤����ϵͳ���͹�˾�ʽ��˻���Կ
struct CThostFtdcCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TThostFtdcCFMMCKeyType	CurrentKey;
};

///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
struct CThostFtdcQryCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///�û���̬���Ʋ���
struct CThostFtdcBrokerUserOTPParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��̬�����ṩ��
	TThostFtdcOTPVendorsIDType	OTPVendorsID;
	///��̬�������к�
	TThostFtdcSerialNumberType	SerialNumber;
	///������Կ
	TThostFtdcAuthKeyType	AuthKey;
	///Ư��ֵ
	TThostFtdcLastDriftType	LastDrift;
	///�ɹ�ֵ
	TThostFtdcLastSuccessType	LastSuccess;
	///��̬��������
	TThostFtdcOTPTypeType	OTPType;
};

///�ֹ�ͬ���û���̬����
struct CThostFtdcManualSyncBrokerUserOTPField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��̬��������
	TThostFtdcOTPTypeType	OTPType;
	///��һ����̬����
	TThostFtdcPasswordType	FirstOTP;
	///�ڶ�����̬����
	TThostFtdcPasswordType	SecondOTP;
};

///Ͷ������������ģ��
struct CThostFtdcCommRateModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///ģ������
	TThostFtdcCommModelNameType	CommModelName;
};

///�����ѯͶ������������ģ��
struct CThostFtdcQryCommRateModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
};

///Ͷ���߱�֤����ģ��
struct CThostFtdcMarginModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
	///ģ������
	TThostFtdcCommModelNameType	MarginModelName;
};

///�����ѯͶ���߱�֤����ģ��
struct CThostFtdcQryMarginModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
};

///�ֵ��۵���Ϣ
struct CThostFtdcEWarrantOffsetField
{
	///��������
	TThostFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��������
	TThostFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcVolumeType	Volume;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ֵ��۵���Ϣ
struct CThostFtdcQryEWarrantOffsetField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///��ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
struct CThostFtdcQryInvestorProductGroupMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///Ʒ��/��Ʒ�ֱ�ʾ
	TThostFtdcInstrumentIDType	ProductGroupID;
};

///Ͷ����Ʒ��/��Ʒ�ֱ�֤��
struct CThostFtdcInvestorProductGroupMarginField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TThostFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TThostFtdcMoneyType	ShortFrozenMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///��ͷ��֤��
	TThostFtdcMoneyType	LongUseMargin;
	///��ͷ��֤��
	TThostFtdcMoneyType	ShortUseMargin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��������ͷ��֤��
	TThostFtdcMoneyType	LongExchMargin;
	///��������ͷ��֤��
	TThostFtdcMoneyType	ShortExchMargin;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///������
	TThostFtdcMoneyType	Commission;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�۵��ܽ��
	TThostFtdcMoneyType	OffsetAmount;
	///��ͷ�۵��ܽ��
	TThostFtdcMoneyType	LongOffsetAmount;
	///��ͷ�۵��ܽ��
	TThostFtdcMoneyType	ShortOffsetAmount;
	///�������۵��ܽ��
	TThostFtdcMoneyType	ExchOffsetAmount;
	///��������ͷ�۵��ܽ��
	TThostFtdcMoneyType	LongExchOffsetAmount;
	///��������ͷ�۵��ܽ��
	TThostFtdcMoneyType	ShortExchOffsetAmount;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///Ʒ��/��Ʒ�ֱ�ʾ
	TThostFtdcInstrumentIDType	ProductGroupID;
};

///��ѯ��������û�����
struct CThostFtdcQueryCFMMCTradingAccountTokenField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

///��������û�����
struct CThostFtdcCFMMCTradingAccountTokenField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬����
	TThostFtdcCFMMCTokenType	Token;
};

///��ѯ��Ʒ��
struct CThostFtdcQryProductGroupField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///Ͷ����Ʒ��/��Ʒ�ֱ�֤���Ʒ��
struct CThostFtdcProductGroupField
{
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve2;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Ʒ�����
	TThostFtdcInstrumentIDType	ProductGroupID;
};

///����������
struct CThostFtdcBulletinField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcBulletinIDType	BulletinID;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��������
	TThostFtdcNewsTypeType	NewsType;
	///�����̶�
	TThostFtdcNewsUrgencyType	NewsUrgency;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///��ϢժҪ
	TThostFtdcAbstractType	Abstract;
	///��Ϣ��Դ
	TThostFtdcComeFromType	ComeFrom;
	///��Ϣ����
	TThostFtdcContentType	Content;
	///WEB��ַ
	TThostFtdcURLLinkType	URLLink;
	///�г�����
	TThostFtdcMarketIDType	MarketID;
};

///��ѯ����������
struct CThostFtdcQryBulletinField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcBulletinIDType	BulletinID;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��������
	TThostFtdcNewsTypeType	NewsType;
	///�����̶�
	TThostFtdcNewsUrgencyType	NewsUrgency;
};

///MulticastInstrument
struct CThostFtdcMulticastInstrumentField
{
	///�����
	TThostFtdcInstallIDType	TopicID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ���
	TThostFtdcInstallIDType	InstrumentNo;
	///��׼��
	TThostFtdcPriceType	CodePrice;
	///��Լ��������
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TThostFtdcPriceType	PriceTick;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///QryMulticastInstrument
struct CThostFtdcQryMulticastInstrumentField
{
	///�����
	TThostFtdcInstallIDType	TopicID;
	///��������Ч�ֶ�
	TThostFtdcOldInstrumentIDType	reserve1;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///App�ͻ���Ȩ�޷���
struct CThostFtdcAppIDAuthAssignField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///App����
	TThostFtdcAppIDType	AppID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///ת�ʿ�������
struct CThostFtdcReqOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///ת����������
struct CThostFtdcReqCancelAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��������˻�����
struct CThostFtdcReqChangeAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TThostFtdcBankAccountType	NewBankAccount;
	///����������
	TThostFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TThostFtdcTIDType	TID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///ת������
struct CThostFtdcReqTransferField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///���з��������ʽ�ת�ڻ���Ӧ
struct CThostFtdcRspTransferField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��������
struct CThostFtdcReqRepealField
{
	///����ʱ����
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TThostFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TThostFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///������Ӧ
struct CThostFtdcRspRepealField
{
	///����ʱ����
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TThostFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TThostFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��ѯ�˻���Ϣ����
struct CThostFtdcReqQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��ѯ�˻���Ϣ��Ӧ
struct CThostFtdcRspQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///����ǩ��ǩ��
struct CThostFtdcFutureSignIOField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
};

///����ǩ����Ӧ
struct CThostFtdcRspFutureSignInField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TThostFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TThostFtdcPasswordKeyType	MacKey;
};

///����ǩ������
struct CThostFtdcReqFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
};

///����ǩ����Ӧ
struct CThostFtdcRspFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///��ѯָ����ˮ�ŵĽ��׽������
struct CThostFtdcReqQueryTradeResultBySerialField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��ˮ��
	TThostFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TThostFtdcOrganCodeType	RefrenceIssure;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��ѯָ����ˮ�ŵĽ��׽����Ӧ
struct CThostFtdcRspQueryTradeResultBySerialField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��ˮ��
	TThostFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TThostFtdcOrganCodeType	RefrenceIssure;
	///ԭʼ���ش���
	TThostFtdcReturnCodeType	OriginReturnCode;
	///ԭʼ����������
	TThostFtdcDescrInfoForReturnCodeType	OriginDescrInfoForReturnCode;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TThostFtdcDigestType	Digest;
};

///�����ļ���������
struct CThostFtdcReqDayEndFileReadyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ļ�ҵ����
	TThostFtdcFileBusinessCodeType	FileBusinessCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
};

///���ؽ��
struct CThostFtdcReturnResultField
{
	///���ش���
	TThostFtdcReturnCodeType	ReturnCode;
	///����������
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///��֤�ڻ��ʽ�����
struct CThostFtdcVerifyFuturePasswordField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ID
	TThostFtdcTIDType	TID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��֤�ͻ���Ϣ
struct CThostFtdcVerifyCustInfoField
{
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
struct CThostFtdcVerifyFuturePasswordAndCustInfoField
{
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
struct CThostFtdcDepositResultInformField
{
	///�������ˮ�ţ�����ˮ��Ϊ���ڱ��̷��ص���ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ش���
	TThostFtdcReturnCodeType	ReturnCode;
	///����������
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///���׺��������ڱ��̷�����Կͬ������
struct CThostFtdcReqSyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
};

///���׺��������ڱ��̷�����Կͬ����Ӧ
struct CThostFtdcRspSyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///��ѯ�˻���Ϣ֪ͨ
struct CThostFtdcNotifyQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///����ת�˽�����ˮ��
struct CThostFtdcTransferSerialField
{
	///ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateSerial;
	///���׷�������
	TThostFtdcTradeDateType	TradeDate;
	///��������
	TThostFtdcDateType	TradingDay;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///���״���
	TThostFtdcTradeCodeType	TradeCode;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///�ڻ���˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///�ڻ���˾�ʺ�����
	TThostFtdcFutureAccTypeType	FutureAccType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���׽��
	TThostFtdcTradeAmountType	TradeAmount;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///��Ч��־
	TThostFtdcAvailabilityFlagType	AvailabilityFlag;
	///����Ա
	TThostFtdcOperatorCodeType	OperatorCode;
	///�������ʺ�
	TThostFtdcBankAccountType	BankNewAccount;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///�����ѯת����ˮ
struct CThostFtdcQryTransferSerialField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///����ǩ��֪ͨ
struct CThostFtdcNotifyFutureSignInField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TThostFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TThostFtdcPasswordKeyType	MacKey;
};

///����ǩ��֪ͨ
struct CThostFtdcNotifyFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///���׺��������ڱ��̷�����Կͬ�����������֪ͨ
struct CThostFtdcNotifySyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///�����ѯ����ǩԼ��ϵ
struct CThostFtdcQryAccountregisterField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///�ͻ���������Ϣ��
struct CThostFtdcAccountregisterField
{
	///��������
	TThostFtdcTradeDateType	TradeDay;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///�ڻ���˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�ڻ���˾��֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���������
	TThostFtdcOpenOrDestroyType	OpenOrDestroy;
	///ǩԼ����
	TThostFtdcTradeDateType	RegDate;
	///��Լ����
	TThostFtdcTradeDateType	OutDate;
	///����ID
	TThostFtdcTIDType	TID;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///���ڿ�����Ϣ
struct CThostFtdcOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///����������Ϣ
struct CThostFtdcCancelAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///���ڱ�������˺���Ϣ
struct CThostFtdcChangeAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TThostFtdcBankAccountType	NewBankAccount;
	///����������
	TThostFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TThostFtdcTIDType	TID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

///������������Ա����Ȩ��
struct CThostFtdcSecAgentACIDMapField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ʽ��˻�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcCurrencyIDType	CurrencyID;
	///�����н�����ʽ��ʺ�
	TThostFtdcAccountIDType	BrokerSecAgentID;
};

///������������Ա����Ȩ�޲�ѯ
struct CThostFtdcQrySecAgentACIDMapField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ʽ��˻�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcCurrencyIDType	CurrencyID;
};

///�ֱ����Ľ���Ȩ��
struct CThostFtdcUserRightsAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///���ù�˾�Ƿ����ڱ���ʾ�Ľ���Ȩ��
struct CThostFtdcBrokerUserRightAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�ܷ���
	TThostFtdcBoolType	Tradeable;
};

///�ֱ�����ת������
struct CThostFtdcDRTransferField
{
	///ԭ�������Ĵ���
	TThostFtdcDRIdentityIDType	OrigDRIdentityID;
	///Ŀ�꽻�����Ĵ���
	TThostFtdcDRIdentityIDType	DestDRIdentityID;
	///ԭӦ�õ�Ԫ����
	TThostFtdcBrokerIDType	OrigBrokerID;
	///Ŀ�����õ�Ԫ����
	TThostFtdcBrokerIDType	DestBrokerID;
};

///Fens�û���Ϣ
struct CThostFtdcFensUserInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼ģʽ
	TThostFtdcLoginModeType	LoginMode;
};

///��ǰ����������������
struct CThostFtdcCurrTransferIdentityField
{
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	IdentityID;
};

///��ֹ��¼�û�
struct CThostFtdcLoginForbiddenUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ��ֹ��¼�û�
struct CThostFtdcQryLoginForbiddenUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///�ʽ��˻�����׼����
struct CThostFtdcTradingAccountReserveField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��ѯ��ֹ��¼IP
struct CThostFtdcQryLoginForbiddenIPField
{
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯIP�б�
struct CThostFtdcQryIPListField
{
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ�û��µ�Ȩ�޷����
struct CThostFtdcQryUserRightsAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///����ԤԼ����ȷ������
struct CThostFtdcReserveOpenAccountConfirmField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcLongIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///����ID
	TThostFtdcTIDType	TID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///ԤԼ����������ˮ��
	TThostFtdcBankSerialType	BankReserveOpenSeq;
	///ԤԼ��������
	TThostFtdcTradeDateType	BookDate;
	///ԤԼ������֤����
	TThostFtdcPasswordType	BookPsw;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///����ԤԼ����
struct CThostFtdcReserveOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcLongIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///����ID
	TThostFtdcTIDType	TID;
	///ԤԼ����״̬
	TThostFtdcReserveOpenAccStasType	ReserveOpenAccStas;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};

///�����˻�����
struct CThostFtdcAccountPropertyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����ͳһ��ʶ����
	TThostFtdcBankIDType	BankID;
	///�����˻�
	TThostFtdcBankAccountType	BankAccount;
	///�����˻��Ŀ���������
	TThostFtdcInvestorFullNameType	OpenName;
	///�����˻��Ŀ�����
	TThostFtdcOpenBankType	OpenBank;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///�˻���Դ
	TThostFtdcAccountSourceTypeType	AccountSourceType;
	///��������
	TThostFtdcDateType	OpenDate;
	///ע������
	TThostFtdcDateType	CancelDate;
	///¼��Ա����
	TThostFtdcOperatorIDType	OperatorID;
	///¼������
	TThostFtdcDateType	OperateDate;
	///¼��ʱ��
	TThostFtdcTimeType	OperateTime;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
};

///��ѯ��ǰ��������
struct CThostFtdcQryCurrDRIdentityField
{
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///��ǰ��������
struct CThostFtdcCurrDRIdentityField
{
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///��ѯ�����������ʽ�У��ģʽ
struct CThostFtdcQrySecAgentCheckModeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///��ѯ������������Ϣ
struct CThostFtdcQrySecAgentTradeInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�����н�����ʽ��ʺ�
	TThostFtdcAccountIDType	BrokerSecAgentID;
};

///�û�������ȡ��ȫ��ȫ��½��������
struct CThostFtdcReqUserAuthMethodField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///�û�������ȡ��ȫ��ȫ��½�����ظ�
struct CThostFtdcRspUserAuthMethodField
{
	///��ǰ�����õ���֤ģʽ
	TThostFtdcCurrentAuthMethodType	UsableAuthMethod;
};

///�û�������ȡ��ȫ��ȫ��½��������
struct CThostFtdcReqGenUserCaptchaField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///���ɵ�ͼƬ��֤����Ϣ
struct CThostFtdcRspGenUserCaptchaField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ͼƬ��Ϣ����
	TThostFtdcCaptchaInfoLenType	CaptchaInfoLen;
	///ͼƬ��Ϣ
	TThostFtdcCaptchaInfoType	CaptchaInfo;
};

///�û�������ȡ��ȫ��ȫ��½��������
struct CThostFtdcReqGenUserTextField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///������֤�����ɵĻظ�
struct CThostFtdcRspGenUserTextField
{
	///������֤�����
	TThostFtdcUserTextSeqType	UserTextSeq;
};

///�û�������ͼ����֤��ĵ�¼��������
struct CThostFtdcReqUserLoginWithCaptchaField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///ͼ����֤�����������
	TThostFtdcPasswordType	Captcha;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
};

///�û�������������֤��ĵ�¼��������
struct CThostFtdcReqUserLoginWithTextField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///������֤����������
	TThostFtdcPasswordType	Text;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
};

///�û���������̬��֤��ĵ�¼��������
struct CThostFtdcReqUserLoginWithOTPField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///OTP����
	TThostFtdcPasswordType	OTPPassword;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
};

///api��������
struct CThostFtdcReqApiHandshakeField
{
	///api��frontͨ����Կ�汾��
	TThostFtdcCryptoKeyVersionType	CryptoKeyVersion;
};

///front����api�����ֻظ�
struct CThostFtdcRspApiHandshakeField
{
	///���ֻظ����ݳ���
	TThostFtdcHandshakeDataLenType	FrontHandshakeDataLen;
	///���ֻظ�����
	TThostFtdcHandshakeDataType	FrontHandshakeData;
	///API��֤�Ƿ���
	TThostFtdcBoolType	IsApiAuthEnabled;
};

///api��front����֤key������
struct CThostFtdcReqVerifyApiKeyField
{
	///���ֻظ����ݳ���
	TThostFtdcHandshakeDataLenType	ApiHandshakeDataLen;
	///���ֻظ�����
	TThostFtdcHandshakeDataType	ApiHandshakeData;
};

///����Ա��֯�ܹ���ϵ
struct CThostFtdcDepartmentUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ͷ���߷�Χ
	TThostFtdcDepartmentRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///��ѯƵ�ʣ�ÿ���ѯ����
struct CThostFtdcQueryFreqField
{
	///��ѯƵ��
	TThostFtdcQueryFreqType	QueryFreq;
	///FTDƵ��
	TThostFtdcQueryFreqType	FTDPkgFreq;
};

///��ֹ��֤IP
struct CThostFtdcAuthForbiddenIPField
{
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ��ֹ��֤IP
struct CThostFtdcQryAuthForbiddenIPField
{
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
};

///������ᶳ��
struct CThostFtdcSyncDelaySwapFrozenField
{
	///������ˮ��
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Դʣ�໻����(���ᶳ��)
	TThostFtdcMoneyType	FromRemainSwap;
	///�Ƿ��ֹ�����
	TThostFtdcBoolType	IsManualSwap;
};

///�û�ϵͳ��Ϣ
struct CThostFtdcUserSystemInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û���ϵͳ�ڲ���Ϣ����
	TThostFtdcSystemInfoLenType	ClientSystemInfoLen;
	///�û���ϵͳ�ڲ���Ϣ
	TThostFtdcClientSystemInfoType	ClientSystemInfo;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///��¼�ɹ�ʱ��
	TThostFtdcTimeType	ClientLoginTime;
	///App����
	TThostFtdcAppIDType	ClientAppID;
	///�û�����IP
	TThostFtdcIPAddressType	ClientPublicIP;
	///�ͻ���¼��ע2
	TThostFtdcClientLoginRemarkType	ClientLoginRemark;
};

///�ն��û�����Ϣ
struct CThostFtdcAuthUserIDField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///App����
	TThostFtdcAppIDType	AppID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///У������
	TThostFtdcAuthTypeType	AuthType;
};

///�û�IP����Ϣ
struct CThostFtdcAuthIPField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///App����
	TThostFtdcAppIDType	AppID;
	///�û�����
	TThostFtdcIPAddressType	IPAddress;
};

///��ѯ�����Լ
struct CThostFtdcQryClassifiedInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Լ����״̬
	TThostFtdcTradingTypeType	TradingType;
	///��Լ��������
	TThostFtdcClassTypeType	ClassType;
};

///��ѯ����Żݱ���
struct CThostFtdcQryCombPromotionParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///����Żݱ���
struct CThostFtdcCombPromotionParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///��Ȩ��ϱ�֤�����
	TThostFtdcDiscountRatioType	Xparameter;
};

///�����û���¼����
struct CThostFtdcReqUserLoginSMField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��̬����
	TThostFtdcPasswordType	OneTimePassword;
	///��������Ч�ֶ�
	TThostFtdcOldIPAddressType	reserve1;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
	///���͹�˾����
	TThostFtdcBrokerNameType	BrokerName;
	///��֤��
	TThostFtdcAuthCodeType	AuthCode;
	///App����
	TThostFtdcAppIDType	AppID;
	///PIN��
	TThostFtdcPasswordType	PIN;
};

///Ͷ���߷��ս���ֲֲ�ѯ
struct CThostFtdcQryRiskSettleInvstPositionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///���ս����Ʒ��ѯ
struct CThostFtdcQryRiskSettleProductStatusField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
};

///Ͷ���߷��ս���ֲ�
struct CThostFtdcRiskSettleInvstPositionField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TThostFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TThostFtdcVolumeType	YdPosition;
	///���ճֲ�
	TThostFtdcVolumeType	Position;
	///��ͷ����
	TThostFtdcVolumeType	LongFrozen;
	///��ͷ����
	TThostFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TThostFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TThostFtdcMoneyType	ShortFrozenAmount;
	///������
	TThostFtdcVolumeType	OpenVolume;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///���ֽ��
	TThostFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TThostFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TThostFtdcMoneyType	OpenCost;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TThostFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TThostFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TThostFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TThostFtdcVolumeType	TodayPosition;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///ִ�ж���
	TThostFtdcVolumeType	StrikeFrozen;
	///ִ�ж�����
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TThostFtdcVolumeType	AbandonFrozen;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ�ж�������
	TThostFtdcVolumeType	YdStrikeFrozen;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ֲֳɱ���ֵ
	TThostFtdcMoneyType	PositionCostOffset;
	///tas�ֲ�����
	TThostFtdcVolumeType	TasPosition;
	///tas�ֲֳɱ�
	TThostFtdcMoneyType	TasPositionCost;
};

///����Ʒ��
struct CThostFtdcRiskSettleProductStatusField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ���
	TThostFtdcInstrumentIDType	ProductID;
	///��Ʒ����״̬
	TThostFtdcProductStatusType	ProductStatus;
};

///���ս���׷ƽ��Ϣ
struct CThostFtdcSyncDeltaInfoField
{
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
	///׷ƽ״̬
	TThostFtdcSyncDeltaStatusType	SyncDeltaStatus;
	///׷ƽ����
	TThostFtdcSyncDescriptionType	SyncDescription;
	///�Ƿ�ֻ���ʽ�׷ƽ
	TThostFtdcBoolType	IsOnlyTrdDelta;
};

///���ս���׷ƽ��Ʒ��Ϣ
struct CThostFtdcSyncDeltaProductStatusField
{
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///�Ƿ���������
	TThostFtdcProductStatusType	ProductStatus;
};

///���ս���׷ƽ�ֲ���ϸ
struct CThostFtdcSyncDeltaInvstPosDtlField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///����
	TThostFtdcVolumeType	Volume;
	///���ּ�
	TThostFtdcPriceType	OpenPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///������
	TThostFtdcPriceType	LastSettlementPrice;
	///�����
	TThostFtdcPriceType	SettlementPrice;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ȿ���ƽʣ������
	TThostFtdcVolumeType	TimeFirstVolume;
	///����ֱֲ�־
	TThostFtdcSpecPosiTypeType	SpecPosiType;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ��ϳֲ���ϸ
struct CThostFtdcSyncDeltaInvstPosCombDtlField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������
	TThostFtdcDateType	OpenDate;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϱ��
	TThostFtdcTradeIDType	ComTradeID;
	///��ϱ��
	TThostFtdcTradeIDType	TradeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///�ֲ���
	TThostFtdcVolumeType	TotalAmt;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///�ɽ����
	TThostFtdcTradeGroupIDType	TradeGroupID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�ʽ�
struct CThostFtdcSyncDeltaTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TThostFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TThostFtdcMoneyType	PreCredit;
	///�ϴδ���
	TThostFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///��Ϣ����
	TThostFtdcMoneyType	InterestBase;
	///��Ϣ����
	TThostFtdcMoneyType	Interest;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TThostFtdcMoneyType	WithdrawQuota;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ö��
	TThostFtdcMoneyType	Credit;
	///��Ѻ���
	TThostFtdcMoneyType	Mortgage;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///�����ڻ�����׼����
	TThostFtdcMoneyType	ReserveBalance;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ϴλ���������
	TThostFtdcMoneyType	PreFundMortgageIn;
	///�ϴλ����ʳ����
	TThostFtdcMoneyType	PreFundMortgageOut;
	///����������
	TThostFtdcMoneyType	FundMortgageIn;
	///�����ʳ����
	TThostFtdcMoneyType	FundMortgageOut;
	///������Ѻ���
	TThostFtdcMoneyType	FundMortgageAvailable;
	///����Ѻ���ҽ��
	TThostFtdcMoneyType	MortgageableFund;
	///�����Ʒռ�ñ�֤��
	TThostFtdcMoneyType	SpecProductMargin;
	///�����Ʒ���ᱣ֤��
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///�����Ʒ������
	TThostFtdcMoneyType	SpecProductCommission;
	///�����Ʒ����������
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///�����Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///�����Ʒƽ��ӯ��
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///�����Ʒ��������֤��
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	///��ʱ���㶳����
	TThostFtdcMoneyType	FrozenSwap;
	///ʣ�໻����
	TThostFtdcMoneyType	RemainSwap;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///Ͷ���߷��ս����ܱ�֤��
struct CThostFtdcSyncDeltaInitInvstMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///׷ƽǰ�ܷ��ձ�֤��
	TThostFtdcMoneyType	LastRiskTotalInvstMargin;
	///׷ƽǰ�������ܷ��ձ�֤��
	TThostFtdcMoneyType	LastRiskTotalExchMargin;
	///����׷ƽƷ���ܱ�֤��
	TThostFtdcMoneyType	ThisSyncInvstMargin;
	///����׷ƽƷ�ֽ������ܱ�֤��
	TThostFtdcMoneyType	ThisSyncExchMargin;
	///����δ׷ƽƷ���ܱ�֤��
	TThostFtdcMoneyType	RemainRiskInvstMargin;
	///����δ׷ƽƷ�ֽ������ܱ�֤��
	TThostFtdcMoneyType	RemainRiskExchMargin;
	///׷ƽǰ�������Ʒ���ձ�֤��
	TThostFtdcMoneyType	LastRiskSpecTotalInvstMargin;
	///׷ƽǰ�������Ʒ���������ձ�֤��
	TThostFtdcMoneyType	LastRiskSpecTotalExchMargin;
	///����׷ƽƷ�������Ʒ�ܱ�֤��
	TThostFtdcMoneyType	ThisSyncSpecInvstMargin;
	///����׷ƽƷ�������Ʒ�������ܱ�֤��
	TThostFtdcMoneyType	ThisSyncSpecExchMargin;
	///����δ׷ƽƷ�������Ʒ�ܱ�֤��
	TThostFtdcMoneyType	RemainRiskSpecInvstMargin;
	///����δ׷ƽƷ�������Ʒ�������ܱ�֤��
	TThostFtdcMoneyType	RemainRiskSpecExchMargin;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ������ȼ�
struct CThostFtdcSyncDeltaDceCombInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///�ɽ����
	TThostFtdcTradeGroupIDType	TradeGroupID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	CombHedgeFlag;
	///�������
	TThostFtdcDceCombinationTypeType	CombinationType;
	///����
	TThostFtdcDirectionType	Direction;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Ȩ��ϱ�֤�����
	TThostFtdcDiscountRatioType	Xparameter;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽͶ�����ڻ���֤����
struct CThostFtdcSyncDeltaInvstMarginRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�������ڻ���֤����
struct CThostFtdcSyncDeltaExchMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�н��ֻ���Ȩ��������֤����
struct CThostFtdcSyncDeltaOptExchMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	///������ͷ��֤�����ϵ��
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	///������ͷ��֤�����ϵ��
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�н��ֻ���ȨͶ���߱�֤����
struct CThostFtdcSyncDeltaOptInvstMarginField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	///������ͷ��֤�����ϵ��
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	///������ͷ��֤�����ϵ��
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	///�Ƿ���潻������ȡ
	TThostFtdcBoolType	IsRelative;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ��Ȩ��ĵ�����֤����
struct CThostFtdcSyncDeltaInvstMarginRateULField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ��Ȩ��������
struct CThostFtdcSyncDeltaOptInvstCommRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TThostFtdcRatioType	StrikeRatioByMoney;
	///ִ��������
	TThostFtdcRatioType	StrikeRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�ڻ���������
struct CThostFtdcSyncDeltaInvstCommRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�������
struct CThostFtdcSyncDeltaProductExchRateField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///���۱�������
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	///����
	TThostFtdcExchangeRateType	ExchangeRate;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ����
struct CThostFtdcSyncDeltaDepthMarketDataField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
	///������
	TThostFtdcPriceType	ClosePrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///�����һ
	TThostFtdcPriceType	BidPrice1;
	///������һ
	TThostFtdcVolumeType	BidVolume1;
	///������һ
	TThostFtdcPriceType	AskPrice1;
	///������һ
	TThostFtdcVolumeType	AskVolume1;
	///����۶�
	TThostFtdcPriceType	BidPrice2;
	///��������
	TThostFtdcVolumeType	BidVolume2;
	///�����۶�
	TThostFtdcPriceType	AskPrice2;
	///��������
	TThostFtdcVolumeType	AskVolume2;
	///�������
	TThostFtdcPriceType	BidPrice3;
	///��������
	TThostFtdcVolumeType	BidVolume3;
	///��������
	TThostFtdcPriceType	AskPrice3;
	///��������
	TThostFtdcVolumeType	AskVolume3;
	///�������
	TThostFtdcPriceType	BidPrice4;
	///��������
	TThostFtdcVolumeType	BidVolume4;
	///��������
	TThostFtdcPriceType	AskPrice4;
	///��������
	TThostFtdcVolumeType	AskVolume4;
	///�������
	TThostFtdcPriceType	BidPrice5;
	///��������
	TThostFtdcVolumeType	BidVolume5;
	///��������
	TThostFtdcPriceType	AskPrice5;
	///��������
	TThostFtdcVolumeType	AskVolume5;
	///���վ���
	TThostFtdcPriceType	AveragePrice;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///�ϴ���
	TThostFtdcPriceType	BandingUpperPrice;
	///�´���
	TThostFtdcPriceType	BandingLowerPrice;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�ֻ�ָ��
struct CThostFtdcSyncDeltaIndexPriceField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ָ���ֻ����̼�
	TThostFtdcPriceType	ClosePrice;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽ�ֵ��۵�
struct CThostFtdcSyncDeltaEWarrantOffsetField
{
	///��������
	TThostFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcVolumeType	Volume;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///SPBM�ڻ���Լ��֤�����
struct CThostFtdcSPBMFutureParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///�ڻ���Լ����
	TThostFtdcVolumeMultipleType	Cvf;
	///�׶α�ʶ
	TThostFtdcTimeRangeType	TimeRange;
	///Ʒ�ֱ�֤���׼
	TThostFtdcRatioType	MarginRate;
	///�ڻ���Լ�ڲ������ַ����ۿ۱���
	TThostFtdcRatioType	LockRateX;
	///��߱�֤���׼
	TThostFtdcRatioType	AddOnRate;
	///������
	TThostFtdcPriceType	PreSettlementPrice;
	///�ڻ���Լ�ڲ������ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnLockRateX2;
};

///SPBM��Ȩ��Լ��֤�����
struct CThostFtdcSPBMOptionParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��Ȩ��Լ����
	TThostFtdcVolumeMultipleType	Cvf;
	///��Ȩ��ּ۸�
	TThostFtdcPriceType	DownPrice;
	///Deltaֵ
	TThostFtdcDeltaType	Delta;
	///������Ȩ����ת�����ֵ
	TThostFtdcDeltaType	SlimiDelta;
	///������
	TThostFtdcPriceType	PreSettlementPrice;
};

///SPBMƷ���ڶ������ۿ۲���
struct CThostFtdcSPBMIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///Ʒ���ں�Լ������ַ����ۿ۱���
	TThostFtdcRatioType	IntraRateY;
	///Ʒ���ں�Լ������ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnIntraRateY2;
};

///SPBM��Ʒ�ֵֿ۲���
struct CThostFtdcSPBMInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ַ����ۿ۱���
	TThostFtdcRatioType	InterRateZ;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
};

///ͬ��SPBM��������
struct CThostFtdcSyncSPBMParameterEndField
{
	///������
	TThostFtdcDateType	TradingDay;
};

///SPBM�ڻ���Լ��֤�������ѯ
struct CThostFtdcQrySPBMFutureParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///SPBM��Ȩ��Լ��֤�������ѯ
struct CThostFtdcQrySPBMOptionParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///SPBMƷ���ڶ������ۿ۲�����ѯ
struct CThostFtdcQrySPBMIntraParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///SPBM��Ʒ�ֵֿ۲�����ѯ
struct CThostFtdcQrySPBMInterParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
};

///��ϱ�֤���ײ�
struct CThostFtdcSPBMPortfDefinitionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ϱ�֤���ײʹ���
	TThostFtdcPortfolioDefIDType	PortfolioDefID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///�Ƿ�����SPBM
	TThostFtdcBoolType	IsSPBM;
};

///Ͷ�����ײ�ѡ��
struct CThostFtdcSPBMInvestorPortfDefField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϱ�֤���ײʹ���
	TThostFtdcPortfolioDefIDType	PortfolioDefID;
};

///Ͷ����������ϱ�֤��ϵ��
struct CThostFtdcInvestorPortfMarginRatioField
{
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա��Ͷ������ȡ�ı�֤��ͽ�������Ͷ������ȡ�ı�֤��ı���
	TThostFtdcRatioType	MarginRatio;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
};

///��ϱ�֤���ײͲ�ѯ
struct CThostFtdcQrySPBMPortfDefinitionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ϱ�֤���ײʹ���
	TThostFtdcPortfolioDefIDType	PortfolioDefID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///Ͷ�����ײ�ѡ���ѯ
struct CThostFtdcQrySPBMInvestorPortfDefField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
};

///Ͷ����������ϱ�֤��ϵ����ѯ
struct CThostFtdcQryInvestorPortfMarginRatioField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
};

///Ͷ���߲�ƷSPBM��ϸ
struct CThostFtdcInvestorProdSPBMDetailField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��Լ�ڶ�����֤��
	TThostFtdcMoneyType	IntraInstrMargin;
	///��鼯��֤��
	TThostFtdcMoneyType	BCollectingMargin;
	///���鼯��֤��
	TThostFtdcMoneyType	SCollectingMargin;
	///Ʒ���ں�Լ�������֤��
	TThostFtdcMoneyType	IntraProdMargin;
	///����֤��
	TThostFtdcMoneyType	NetMargin;
	///��Ʒ�������֤��
	TThostFtdcMoneyType	InterProdMargin;
	///�㱣֤��
	TThostFtdcMoneyType	SingleMargin;
	///���ӱ�֤��
	TThostFtdcMoneyType	AddOnMargin;
	///�����±�֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///������Ȩ��ͷ���
	TThostFtdcMoneyType	CallOptionMinRisk;
	///������Ȩ��ͷ���
	TThostFtdcMoneyType	PutOptionMinRisk;
	///������Ȩ��ͷ���
	TThostFtdcMoneyType	OptionMinRisk;
	///����Ȩ��ּ�ֵ
	TThostFtdcMoneyType	OptionValueOffset;
	///������ȨȨ����
	TThostFtdcMoneyType	OptionRoyalty;
	///��ֵ���
	TThostFtdcMoneyType	RealOptionValueOffset;
	///��֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
};

///Ͷ���߲�ƷSPBM��ϸ��ѯ
struct CThostFtdcQryInvestorProdSPBMDetailField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///�鱣���ײ�������
struct CThostFtdcPortfTradeParamSettingField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����鱣�㷨
	TThostFtdcPortfolioType	Portfolio;
	///�����Ƿ�����
	TThostFtdcBoolType	IsActionVerify;
	///ƽ���Ƿ�����
	TThostFtdcBoolType	IsCloseVerify;
};

///Ͷ���߽���Ȩ������
struct CThostFtdcInvestorTradingRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TThostFtdcInvstTradingRightType	InvstTradingRight;
};

///��Ѻ��Ȳ���
struct CThostFtdcMortgageParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��Ѻ���ϵ��
	TThostFtdcRatioType	MortgageBalance;
	///�����Ƿ���֤��Ѻ���
	TThostFtdcBoolType	CheckMortgageRatio;
};

///������Ʋ���
struct CThostFtdcWithDrawParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��������
	TThostFtdcWithDrawParamIDType	WithDrawParamID;
	///��������ֵ
	TThostFtdcWithDrawParamValueType	WithDrawParamValue;
};

///Thost�ն��û�����Ȩ��
struct CThostFtdcThostUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Thost�ն˹��ܴ���
	TThostFtdcThostFunctionCodeType	ThostFunctionCode;
};

///Thost�ն��û�����Ȩ�޲�ѯ
struct CThostFtdcQryThostUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///SPBM���ӿ�Ʒ�ֵֿ۲���
struct CThostFtdcSPBMAddOnInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnInterRateZ2;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
};

///SPBM���ӿ�Ʒ�ֵֿ۲�����ѯ
struct CThostFtdcQrySPBMAddOnInterParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
};

///Ͷ������Ʒ��SPMM��¼��ѯ
struct CThostFtdcQryInvestorCommoditySPMMMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
};

///Ͷ������ƷȺSPMM��¼��ѯ
struct CThostFtdcQryInvestorCommodityGroupSPMMMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
};

///SPMM��Լ������ѯ
struct CThostFtdcQrySPMMInstParamField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///SPMM��Ʒ������ѯ
struct CThostFtdcQrySPMMProductParamField
{
	///��Ʒ����
	TThostFtdcSPMMProductIDType	ProductID;
};

///Ͷ������Ʒ��SPMM��¼
struct CThostFtdcInvestorCommoditySPMMMarginField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
	///�Żݲ�λӦ�ձ�֤��
	TThostFtdcMoneyType	MarginBeforeDiscount;
	///���Żݲ�λӦ�ձ�֤��
	TThostFtdcMoneyType	MarginNoDiscount;
	///��ͷʵ�ַ���
	TThostFtdcMoneyType	LongPosRisk;
	///��ͷ���ֶ������
	TThostFtdcMoneyType	LongOpenFrozenRisk;
	///��ͷ��ƽ�������
	TThostFtdcMoneyType	LongCloseFrozenRisk;
	///��ͷʵ�ַ���
	TThostFtdcMoneyType	ShortPosRisk;
	///��ͷ���ֶ������
	TThostFtdcMoneyType	ShortOpenFrozenRisk;
	///��ͷ��ƽ�������
	TThostFtdcMoneyType	ShortCloseFrozenRisk;
	///SPMMƷ���ڿ����Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	IntraCommodityRate;
	///SPMM��Ȩ�Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	OptionDiscountRate;
	///ʵ�ֶԳ��Żݽ��
	TThostFtdcMoneyType	PosDiscount;
	///���ֱ����Գ��Żݽ��
	TThostFtdcMoneyType	OpenFrozenDiscount;
	///Ʒ�ַ��վ�ͷ
	TThostFtdcMoneyType	NetRisk;
	///ƽ�ֶ��ᱣ֤��
	TThostFtdcMoneyType	CloseFrozenMargin;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///������
	TThostFtdcMoneyType	Commission;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///��Ȩ�����ʽ�
	TThostFtdcMoneyType	StrikeFrozenMargin;
};

///Ͷ������ƷȺSPMM��¼
struct CThostFtdcInvestorCommodityGroupSPMMMarginField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
	///�Żݲ�λӦ�ձ�֤��
	TThostFtdcMoneyType	MarginBeforeDiscount;
	///���Żݲ�λӦ�ձ�֤��
	TThostFtdcMoneyType	MarginNoDiscount;
	///��ͷ����
	TThostFtdcMoneyType	LongRisk;
	///��ͷ����
	TThostFtdcMoneyType	ShortRisk;
	///��ƷȺƽ�ֶ��ᱣ֤��
	TThostFtdcMoneyType	CloseFrozenMargin;
	///SPMM��Ʒ���Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	InterCommodityRate;
	///��ƷȺ��С��֤�����
	TThostFtdcSPMMDiscountRatioType	MiniMarginRatio;
	///Ͷ���߱�֤��ͽ�������֤��ı���
	TThostFtdcRatioType	AdjustRatio;
	///SPMMƷ�����Żݻ���
	TThostFtdcMoneyType	IntraCommodityDiscount;
	///SPMM��Ʒ���Ż�
	TThostFtdcMoneyType	InterCommodityDiscount;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	InvestorMargin;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///������
	TThostFtdcMoneyType	Commission;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///��Ȩ�����ʽ�
	TThostFtdcMoneyType	StrikeFrozenMargin;
};

///SPMM��Լ����
struct CThostFtdcSPMMInstParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///SPMM��Լ��֤���㷨
	TThostFtdcInstMarginCalIDType	InstMarginCalID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
};

///SPMM��Ʒ����
struct CThostFtdcSPMMProductParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcSPMMProductIDType	ProductID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
};

///ϯλ�뽻�����Ķ�Ӧ��ϵά����ѯ
struct CThostFtdcQryTraderAssignField
{
	///����Ա����
	TThostFtdcTraderIDType	TraderID;
};

///ϯλ�뽻�����Ķ�Ӧ��ϵ
struct CThostFtdcTraderAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

///Ͷ�����걨�ѽ�����ȡ����
struct CThostFtdcInvestorInfoCntSettingField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///�Ƿ���ȡ�걨��
	TThostFtdcBoolType	IsCalInfoComm;
	///�Ƿ�������Ϣ��
	TThostFtdcBoolType	IsLimitInfoMax;
	///��Ϣ�����Ʊ���
	TThostFtdcVolumeType	InfoMaxLimit;
};

///RCAMS��Ʒ�����Ϣ
struct CThostFtdcRCAMSCombProductInfoField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///��Ʒ�����
	TThostFtdcProductIDType	CombProductID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
};

///RCAMSͬ��Լ���նԳ����
struct CThostFtdcRCAMSInstrParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///ͬ��Լ���նԳ����
	TThostFtdcHedgeRateType	HedgeRate;
};

///RCAMSƷ���ڷ��նԳ����
struct CThostFtdcRCAMSIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///Ʒ���ڶԳ����
	TThostFtdcHedgeRateType	HedgeRate;
};

///RCAMS��Ʒ�ַ����۵ֲ���
struct CThostFtdcRCAMSInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
	///���ȼ�
	TThostFtdcRCAMSPriorityType	Priority;
	///�۵���
	TThostFtdcHedgeRateType	CreditRate;
	///��Ʒ��ϴ���1
	TThostFtdcProductIDType	CombProduct1;
	///��Ʒ��ϴ���2
	TThostFtdcProductIDType	CombProduct2;
};

///RCAMS��ͷ��Ȩ���յ�������
struct CThostFtdcRCAMSShortOptAdjustParamField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��Ȩ���յ�����׼
	TThostFtdcAdjustValueType	AdjustValue;
};

///RCAMS������ϳֲ�
struct CThostFtdcRCAMSInvestorCombPositionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///��������Ϻ�Լ����
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///�ֲ���
	TThostFtdcVolumeType	TotalAmt;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
};

///Ͷ����Ʒ��RCAMS��֤��
struct CThostFtdcInvestorProdRCAMSMarginField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
	///Ʒ�����ǰ����
	TThostFtdcMoneyType	RiskBeforeDiscount;
	///ͬ��Լ�Գ����
	TThostFtdcMoneyType	IntraInstrRisk;
	///Ʒ����ֲַ���
	TThostFtdcMoneyType	BPosRisk;
	///Ʒ�����ֲַ���
	TThostFtdcMoneyType	SPosRisk;
	///Ʒ���ڶԳ����
	TThostFtdcMoneyType	IntraProdRisk;
	///Ʒ�־��ֲַ���
	TThostFtdcMoneyType	NetRisk;
	///Ʒ�ּ�Գ����
	TThostFtdcMoneyType	InterProdRisk;
	///��ͷ��Ȩ���յ���
	TThostFtdcMoneyType	ShortOptRiskAdj;
	///��ͷ��ȨȨ����
	TThostFtdcMoneyType	OptionRoyalty;
	///������ƽ�ֶ��ᱣ֤��
	TThostFtdcMoneyType	MMSACloseFrozenMargin;
	///�������ƽ��/��Ȩ���ᱣ֤��
	TThostFtdcMoneyType	CloseCombFrozenMargin;
	///ƽ��/��Ȩ���ᱣ֤��
	TThostFtdcMoneyType	CloseFrozenMargin;
	///�����Ͽ��ֶ��ᱣ֤��
	TThostFtdcMoneyType	MMSAOpenFrozenMargin;
	///�������ڻ����ֶ��ᱣ֤��
	TThostFtdcMoneyType	DeliveryOpenFrozenMargin;
	///���ֶ��ᱣ֤��
	TThostFtdcMoneyType	OpenFrozenMargin;
	///Ͷ���߶��ᱣ֤��
	TThostFtdcMoneyType	UseFrozenMargin;
	///�����Ͻ������ֱֲ�֤��
	TThostFtdcMoneyType	MMSAExchMargin;
	///�������ڻ��������ֱֲ�֤��
	TThostFtdcMoneyType	DeliveryExchMargin;
	///������Ͻ�������֤��
	TThostFtdcMoneyType	CombExchMargin;
	///�������ֱֲ�֤��
	TThostFtdcMoneyType	ExchMargin;
	///Ͷ���ֱֲ߳�֤��
	TThostFtdcMoneyType	UseMargin;
};

///RCAMS��Ʒ�����Ϣ��ѯ
struct CThostFtdcQryRCAMSCombProductInfoField
{
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///��Ʒ�����
	TThostFtdcProductIDType	CombProductID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
};

///RCAMSͬ��Լ���նԳ������ѯ
struct CThostFtdcQryRCAMSInstrParameterField
{
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
};

///RCAMSƷ���ڷ��նԳ������ѯ
struct CThostFtdcQryRCAMSIntraParameterField
{
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
};

///RCAMS��Ʒ�ַ����۵ֲ�����ѯ
struct CThostFtdcQryRCAMSInterParameterField
{
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
	///��Ʒ��ϴ���1
	TThostFtdcProductIDType	CombProduct1;
	///��Ʒ��ϴ���2
	TThostFtdcProductIDType	CombProduct2;
};

///RCAMS��ͷ��Ȩ���յ���������ѯ
struct CThostFtdcQryRCAMSShortOptAdjustParamField
{
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
};

///RCAMS������ϳֲֲ�ѯ
struct CThostFtdcQryRCAMSInvestorCombPositionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

///Ͷ����Ʒ��RCAMS��֤���ѯ
struct CThostFtdcQryInvestorProdRCAMSMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
};

///RULE��Լ��֤�����
struct CThostFtdcRULEInstrParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TThostFtdcInstrumentClassType	InstrumentClass;
	///��׼��Լ
	TThostFtdcInstrumentIDType	StdInstrumentID;
	///Ͷ��������ϵ��
	TThostFtdcRatioType	BSpecRatio;
	///Ͷ��������ϵ��
	TThostFtdcRatioType	SSpecRatio;
	///�ױ�������ϵ��
	TThostFtdcRatioType	BHedgeRatio;
	///�ױ�������ϵ��
	TThostFtdcRatioType	SHedgeRatio;
	///�򸽼ӷ��ձ�֤��
	TThostFtdcMoneyType	BAddOnMargin;
	///�����ӷ��ձ�֤��
	TThostFtdcMoneyType	SAddOnMargin;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
};

///RULEƷ���ڶ������ۿ۲���
struct CThostFtdcRULEIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��׼��Լ
	TThostFtdcInstrumentIDType	StdInstrumentID;
	///��׼��Լ��֤��
	TThostFtdcMoneyType	StdInstrMargin;
	///һ���·ݺ�Լ��ϱ�֤��ϵ��
	TThostFtdcRatioType	UsualIntraRate;
	///�ٽ������Լ��ϱ�֤��ϵ��
	TThostFtdcRatioType	DeliveryIntraRate;
};

///RULE��Ʒ�ֵֿ۲���
struct CThostFtdcRULEInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ַ����ۿ۱���
	TThostFtdcRatioType	InterRate;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
	///��1����ϵ��
	TThostFtdcCommonIntType	Leg1PropFactor;
	///��2����ϵ��
	TThostFtdcCommonIntType	Leg2PropFactor;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
	///��ƷȺ����
	TThostFtdcInstrumentNameType	CommodityGroupName;
};

///RULE��Լ��֤�������ѯ
struct CThostFtdcQryRULEInstrParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};

///RULEƷ���ڶ������ۿ۲�����ѯ
struct CThostFtdcQryRULEIntraParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
};

///RULE��Ʒ�ֵֿ۲�����ѯ
struct CThostFtdcQryRULEInterParameterField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
};

///Ͷ���߲�ƷRULE��֤��
struct CThostFtdcInvestorProdRULEMarginField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��Լ����
	TThostFtdcInstrumentClassType	InstrumentClass;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
	///���׼�ֲ�
	TThostFtdcStdPositionType	BStdPosition;
	///����׼�ֲ�
	TThostFtdcStdPositionType	SStdPosition;
	///���׼���ֶ���
	TThostFtdcStdPositionType	BStdOpenFrozen;
	///����׼���ֶ���
	TThostFtdcStdPositionType	SStdOpenFrozen;
	///���׼ƽ�ֶ���
	TThostFtdcStdPositionType	BStdCloseFrozen;
	///����׼ƽ�ֶ���
	TThostFtdcStdPositionType	SStdCloseFrozen;
	///Ʒ���ڶԳ��׼�ֲ�
	TThostFtdcStdPositionType	IntraProdStdPosition;
	///Ʒ���ڵ��ȱ�׼�ֲ�
	TThostFtdcStdPositionType	NetStdPosition;
	///Ʒ�ּ�Գ��׼�ֲ�
	TThostFtdcStdPositionType	InterProdStdPosition;
	///���ȱ�׼�ֲ�
	TThostFtdcStdPositionType	SingleStdPosition;
	///Ʒ���ڶ�����֤��
	TThostFtdcMoneyType	IntraProdMargin;
	///Ʒ�ּ������֤��
	TThostFtdcMoneyType	InterProdMargin;
	///��Ʒ�ֵ��ȱ�֤��
	TThostFtdcMoneyType	SingleMargin;
	///����Ϻ�Լ��֤��
	TThostFtdcMoneyType	NonCombMargin;
	///���ӱ�֤��
	TThostFtdcMoneyType	AddOnMargin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///���Ӷ��ᱣ֤��
	TThostFtdcMoneyType	AddOnFrozenMargin;
	///���ֶ��ᱣ֤��
	TThostFtdcMoneyType	OpenFrozenMargin;
	///ƽ�ֶ��ᱣ֤��
	TThostFtdcMoneyType	CloseFrozenMargin;
	///Ʒ�ֱ�֤��
	TThostFtdcMoneyType	Margin;
	///���ᱣ֤��
	TThostFtdcMoneyType	FrozenMargin;
};

///Ͷ���߲�ƷRULE��֤���ѯ
struct CThostFtdcQryInvestorProdRULEMarginField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
};

///���ս���׷ƽSPBM��ϱ�֤���ײ�
struct CThostFtdcSyncDeltaSPBMPortfDefinitionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ϱ�֤���ײʹ���
	TThostFtdcPortfolioDefIDType	PortfolioDefID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///�Ƿ�����SPBM
	TThostFtdcBoolType	IsSPBM;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽͶ����SPBM�ײ�ѡ��
struct CThostFtdcSyncDeltaSPBMInvstPortfDefField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϱ�֤���ײʹ���
	TThostFtdcPortfolioDefIDType	PortfolioDefID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPBM�ڻ���Լ��֤�����
struct CThostFtdcSyncDeltaSPBMFutureParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///�ڻ���Լ����
	TThostFtdcVolumeMultipleType	Cvf;
	///�׶α�ʶ
	TThostFtdcTimeRangeType	TimeRange;
	///Ʒ�ֱ�֤���׼
	TThostFtdcRatioType	MarginRate;
	///�ڻ���Լ�ڲ������ַ����ۿ۱���
	TThostFtdcRatioType	LockRateX;
	///��߱�֤���׼
	TThostFtdcRatioType	AddOnRate;
	///������
	TThostFtdcPriceType	PreSettlementPrice;
	///�ڻ���Լ�ڲ������ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnLockRateX2;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPBM��Ȩ��Լ��֤�����
struct CThostFtdcSyncDeltaSPBMOptionParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��Ȩ��Լ����
	TThostFtdcVolumeMultipleType	Cvf;
	///��Ȩ��ּ۸�
	TThostFtdcPriceType	DownPrice;
	///Deltaֵ
	TThostFtdcDeltaType	Delta;
	///������Ȩ����ת�����ֵ
	TThostFtdcDeltaType	SlimiDelta;
	///������
	TThostFtdcPriceType	PreSettlementPrice;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPBMƷ���ڶ������ۿ۲���
struct CThostFtdcSyncDeltaSPBMIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///Ʒ���ں�Լ������ַ����ۿ۱���
	TThostFtdcRatioType	IntraRateY;
	///Ʒ���ں�Լ������ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnIntraRateY2;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPBM��Ʒ�ֵֿ۲���
struct CThostFtdcSyncDeltaSPBMInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ַ����ۿ۱���
	TThostFtdcRatioType	InterRateZ;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPBM���ӿ�Ʒ�ֵֿ۲���
struct CThostFtdcSyncDeltaSPBMAddOnInterParamField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ָ��ӷ����ۿ۱���
	TThostFtdcRatioType	AddOnInterRateZ2;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPMM��Լ����
struct CThostFtdcSyncDeltaSPMMInstParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///SPMM��Լ��֤���㷨
	TThostFtdcInstMarginCalIDType	InstMarginCalID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPMM��Ʒ��ز���
struct CThostFtdcSyncDeltaSPMMProductParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcSPMMProductIDType	ProductID;
	///��Ʒ�����
	TThostFtdcSPMMProductIDType	CommodityID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽͶ����SPMMģ��ѡ��
struct CThostFtdcSyncDeltaInvestorSPMMModelField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///SPMMģ��ID
	TThostFtdcSPMMModelIDType	SPMMModelID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽSPMMģ���������
struct CThostFtdcSyncDeltaSPMMModelParamField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///SPMMģ��ID
	TThostFtdcSPMMModelIDType	SPMMModelID;
	///��ƷȺ����
	TThostFtdcSPMMProductIDType	CommodityGroupID;
	///SPMMƷ���ڿ����Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	IntraCommodityRate;
	///SPMMƷ�ּ��Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	InterCommodityRate;
	///SPMM��Ȩ�Ż�ϵ��
	TThostFtdcSPMMDiscountRatioType	OptionDiscountRate;
	///��ƷȺ��С��֤�����
	TThostFtdcSPMMDiscountRatioType	MiniMarginRatio;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMS��Ʒ�����Ϣ
struct CThostFtdcSyncDeltaRCAMSCombProdInfoField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///��Ʒ�����
	TThostFtdcProductIDType	CombProductID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMSͬ��Լ���նԳ����
struct CThostFtdcSyncDeltaRCAMSInstrParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductIDType	ProductID;
	///ͬ��Լ���նԳ����
	TThostFtdcHedgeRateType	HedgeRate;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMSƷ���ڷ��նԳ����
struct CThostFtdcSyncDeltaRCAMSIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///Ʒ���ڶԳ����
	TThostFtdcHedgeRateType	HedgeRate;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMS��Ʒ�ַ����۵ֲ���
struct CThostFtdcSyncDeltaRCAMSInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ƷȺ����
	TThostFtdcProductIDType	ProductGroupID;
	///���ȼ�
	TThostFtdcRCAMSPriorityType	Priority;
	///�۵���
	TThostFtdcHedgeRateType	CreditRate;
	///��Ʒ��ϴ���1
	TThostFtdcProductIDType	CombProduct1;
	///��Ʒ��ϴ���2
	TThostFtdcProductIDType	CombProduct2;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMS��ͷ��Ȩ���յ�������
struct CThostFtdcSyncDeltaRCAMSSOptAdjParamField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ��ϴ���
	TThostFtdcProductIDType	CombProductID;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��Ȩ���յ�����׼
	TThostFtdcAdjustValueType	AdjustValue;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMS������Ϲ�����ϸ
struct CThostFtdcSyncDeltaRCAMSCombRuleDtlField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���Բ�Ʒ
	TThostFtdcProductIDType	ProdGroup;
	///����id
	TThostFtdcRuleIdType	RuleId;
	///���ȼ�
	TThostFtdcRCAMSPriorityType	Priority;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ϱ�֤���׼
	TThostFtdcMoneyType	CombMargin;
	///��������Ϻ�Լ����
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TThostFtdcInstrumentIDType	LegInstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRCAMS������ϳֲ�
struct CThostFtdcSyncDeltaRCAMSInvstCombPosField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ױ�־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///��������Ϻ�Լ����
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///�ֲ���
	TThostFtdcVolumeType	TotalAmt;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRULE��Լ��֤�����
struct CThostFtdcSyncDeltaRULEInstrParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TThostFtdcInstrumentClassType	InstrumentClass;
	///��׼��Լ
	TThostFtdcInstrumentIDType	StdInstrumentID;
	///Ͷ��������ϵ��
	TThostFtdcRatioType	BSpecRatio;
	///Ͷ��������ϵ��
	TThostFtdcRatioType	SSpecRatio;
	///�ױ�������ϵ��
	TThostFtdcRatioType	BHedgeRatio;
	///�ױ�������ϵ��
	TThostFtdcRatioType	SHedgeRatio;
	///�򸽼ӷ��ձ�֤��
	TThostFtdcMoneyType	BAddOnMargin;
	///�����ӷ��ձ�֤��
	TThostFtdcMoneyType	SAddOnMargin;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRULEƷ���ڶ������ۿ۲���
struct CThostFtdcSyncDeltaRULEIntraParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TThostFtdcInstrumentIDType	ProdFamilyCode;
	///��׼��Լ
	TThostFtdcInstrumentIDType	StdInstrumentID;
	///��׼��Լ��֤��
	TThostFtdcMoneyType	StdInstrMargin;
	///һ���·ݺ�Լ��ϱ�֤��ϵ��
	TThostFtdcRatioType	UsualIntraRate;
	///�ٽ������Լ��ϱ�֤��ϵ��
	TThostFtdcRatioType	DeliveryIntraRate;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///���ս���׷ƽRULE��Ʒ�ֵֿ۲���
struct CThostFtdcSyncDeltaRULEInterParameterField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ȼ�
	TThostFtdcSpreadIdType	SpreadId;
	///Ʒ�ּ�����ַ����ۿ۱���
	TThostFtdcRatioType	InterRate;
	///��һ�ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg1ProdFamilyCode;
	///�ڶ��ȹ���Ʒ��
	TThostFtdcInstrumentIDType	Leg2ProdFamilyCode;
	///��1����ϵ��
	TThostFtdcCommonIntType	Leg1PropFactor;
	///��2����ϵ��
	TThostFtdcCommonIntType	Leg2PropFactor;
	///��ƷȺ��
	TThostFtdcCommodityGroupIDType	CommodityGroupID;
	///��ƷȺ����
	TThostFtdcInstrumentNameType	CommodityGroupName;
	///������־
	TThostFtdcActionDirectionType	ActionDirection;
	///׷ƽ���
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

///�����ַ����
struct CThostFtdcIpAddrParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�����ַ
	TThostFtdcIpAddrType	Address;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///������������
	TThostFtdcDRIdentityNameType	DRIdentityName;
	///���׵�ַOR�����ַ
	TThostFtdcAddrSrvModeType	AddrSrvMode;
	///��ַ�汾
	TThostFtdcAddrVerType	AddrVer;
	///�����ַ���
	TThostFtdcCommonIntType	AddrNo;
	///�����ַ����
	TThostFtdcAddrNameType	AddrName;
	///�Ƿ��ǹ��ܵ�ַ
	TThostFtdcBoolType	IsSM;
	///�Ƿ���������ַ
	TThostFtdcBoolType	IsLocalAddr;
	///��ַ������Ϣ
	TThostFtdcAddrRemarkType	Remark;
};

///�����ַ������ѯ
struct CThostFtdcQryIpAddrParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///�����ַ����
struct CThostFtdcTGIpAddrParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����ַ
	TThostFtdcIpAddrType	Address;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///������������
	TThostFtdcDRIdentityNameType	DRIdentityName;
	///���׵�ַOR�����ַ
	TThostFtdcAddrSrvModeType	AddrSrvMode;
	///��ַ�汾
	TThostFtdcAddrVerType	AddrVer;
	///�����ַ���
	TThostFtdcCommonIntType	AddrNo;
	///�����ַ����
	TThostFtdcAddrNameType	AddrName;
	///�Ƿ��ǹ��ܵ�ַ
	TThostFtdcBoolType	IsSM;
	///�Ƿ���������ַ
	TThostFtdcBoolType	IsLocalAddr;
	///��ַ������Ϣ
	TThostFtdcAddrRemarkType	Remark;
};

///�����ַ������ѯ
struct CThostFtdcQryTGIpAddrParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///TGate�Ự��ѯ״̬
struct CThostFtdcTGSessionQryStatusField
{
	///���30s�Ĳ�ѯƵ��
	TThostFtdcCommonIntType	LastQryFreq;
	///��ѯ״̬
	TThostFtdcTGSessionQryStatusType	QryStatus;
};

///������ַ����
struct CThostFtdcLocalAddrConfigField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�Զ˵�ַ
	TThostFtdcIpAddrType	PeerAddr;
	///��������
	TThostFtdcIpAddrType	NetMask;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///���������ַ
	TThostFtdcIpAddrType	LocalAddress;
};

///������ַ���ò�ѯ
struct CThostFtdcQryLocalAddrConfigField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///��ϯ��ѯ�����ʽ��ʻ���Ϣ����
struct CThostFtdcReqQueryBankAccountBySecField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�����ķ���ת���ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	SecFutureSerial;
};

///��ϯ��ѯ�����ʽ��ʻ���Ϣ�ر�
struct CThostFtdcRspQueryBankAccountBySecField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�����ķ���ת���ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	SecFutureSerial;
};

///�����ķ����ת�ʽ���
struct CThostFtdcReqTransferBySecField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�����ķ���ת���ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	SecFutureSerial;
};

///�����ķ����ת�ʽ��׻ر�
struct CThostFtdcRspTransferBySecField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�����ķ���ת���ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	SecFutureSerial;
};

///��ѯ�����ʽ��ʻ���Ϣ֪ͨ Ҫ������ϯ
struct CThostFtdcNotifyQueryFutureAccountBySecField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///���ͻ�����
	TThostFtdcLongIndividualNameType	LongCustomerName;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�����ķ���ת���ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	SecFutureSerial;
};

///�˳�����״̬����
struct CThostFtdcExitEmergencyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};

///���鱣��֤��ϵ��Ͷ����ģ���Ӧ��ϵ
struct CThostFtdcInvestorPortfMarginModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��֤��ϵ��ģ��
	TThostFtdcInvestorIDType	MarginModelID;
};

///Ͷ�������鱣����
struct CThostFtdcInvestorPortfSettingField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�Ƿ������鱣
	TThostFtdcBoolType	UsePortf;
};

///Ͷ�������鱣���ò�ѯ
struct CThostFtdcQryInvestorPortfSettingField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TThostFtdcInvestorIDType	InvestorID;
};

///���Դ�ϯ���û�������
struct CThostFtdcUserPasswordUpdateFromSecField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
	///��ϯ�Ľ������Ĵ���
	TThostFtdcDRIdentityIDType	FromSec;
};

///���Դ�ϯ�Ľ�����ȷ��
struct CThostFtdcSettlementInfoConfirmFromSecField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ȷ������
	TThostFtdcDateType	ConfirmDate;
	///ȷ��ʱ��
	TThostFtdcTimeType	ConfirmTime;
	///��ϯ�Ľ������Ĵ���
	TThostFtdcDRIdentityIDType	FromSec;
};

///���Դ�ϯ���ʽ��˻�������
struct CThostFtdcTradingAccountPasswordUpdateFromSecField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��ϯ�Ľ������Ĵ���
	TThostFtdcDRIdentityIDType	FromSec;
};

///��ؽ�ֹ�ĺ�Լ����Ȩ��
struct CThostFtdcRiskForbiddenRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ/��Ʒ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�û�����
	TThostFtdcUserIDType	UserID;
};

///Ͷ�����걨�ѽ�����ȡ��¼
struct CThostFtdcInvestorInfoCommRecField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�����ܱ���
	TThostFtdcVolumeType	OrderCount;
	///�����ܱ���
	TThostFtdcVolumeType	OrderActionCount;
	///ѯ���ܴ���
	TThostFtdcVolumeType	ForQuoteCnt;
	///�걨��
	TThostFtdcMoneyType	InfoComm;
	///�Ƿ���Ȩϵ��
	TThostFtdcBoolType	IsOptSeries;
	///Ʒ�ִ���
	TThostFtdcProductIDType	ProductID;
	///��Ϣ������
	TThostFtdcVolumeType	InfoCnt;
};

///Ͷ�����걨�ѽ�����ȡ��¼��ѯ
struct CThostFtdcQryInvestorInfoCommRecField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
};


///ǰ����Ϣ
struct CThostFtdcFrontInfoField
{
	///ǰ�õ�ַ
	TThostFtdcAddressType  FrontAddr;
	///��ѯ����
	TThostFtdcQueryFreqType QryFreq;
	///FTD����
	TThostFtdcQueryFreqType FTDPkgFreq;
};

#endif
