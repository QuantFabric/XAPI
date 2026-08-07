#ifndef YD_UTIL_H
#define YD_UTIL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include "ydDataType.h"

#if defined(WINDOWS) | defined(WIN32)
#pragma  warning(disable:4996)
#endif

#define START_HOUR 17

/// Please use pApi->getTimeFormatDesc() for the following 4 functions
/// Or use corresponding functions in api instead

inline unsigned string2TimeID(const char *timeBuffer,const CTimeFormatDesc *pTimeFormatDesc)
{
	if (*timeBuffer=='\0')
	{
		return 0;
	}
	int dayStartSecond=START_HOUR*3600;
	if (pTimeFormatDesc!=nullptr)
	{
		dayStartSecond=pTimeFormatDesc->DayStartSecond;
	}
	const int timeAdjust='0'*(36000+3600+600+60+10+1);
	int tmp=(timeBuffer[0]*36000+timeBuffer[1]*3600+timeBuffer[3]*600+timeBuffer[4]*60+timeBuffer[6]*10+timeBuffer[7]);
	if (tmp>dayStartSecond+timeAdjust)
	{
		tmp-=dayStartSecond+timeAdjust;
	}
	else
	{
		tmp+=86400-dayStartSecond-timeAdjust;
	}
	return tmp;
}

inline unsigned string2TimeStamp(const char *timeBuffer,const CTimeFormatDesc *pTimeFormatDesc)
{
	unsigned timeID=string2TimeID(timeBuffer,pTimeFormatDesc);
	unsigned millisec=0;
	if ((strlen(timeBuffer)>9)&&(timeBuffer[8]=='.'))
	{
		millisec=atoi(timeBuffer+9);
	}
	return timeID*1000+millisec;
}

inline const char *timeID2String(unsigned timeID, char *buffer,const CTimeFormatDesc *pTimeFormatDesc)
{
	if ((int)timeID<=0)
	{
		return "";
	}
	int dayStartSecond=START_HOUR*3600;
	if (pTimeFormatDesc!=nullptr)
	{
		dayStartSecond=pTimeFormatDesc->DayStartSecond;
	}
	timeID+=dayStartSecond;
	timeID%=86400;
	sprintf(buffer,"%02d:%02d:%02d",timeID/3600%24,timeID/60%60,timeID%60);
	return buffer;
}

inline const char *timeStamp2String(unsigned timeStamp,char *buffer,const CTimeFormatDesc *pTimeFormatDesc)
{
	if ((int)timeStamp<=0)
	{
		return "";
	}
	timeID2String(timeStamp/1000,buffer,pTimeFormatDesc);
	sprintf(buffer+8,".%03d",timeStamp%1000);
	return buffer;
}

inline void dumpField(FILE *output,int value)
{
	fprintf(output,"%d ",value);
}

inline void dumpField(FILE *output,unsigned value)
{
	fprintf(output,"%u ",value);
}

inline void dumpField(FILE *output,short value)
{
	fprintf(output,"%d ",value);
}

inline void dumpField(FILE *output,unsigned short value)
{
	fprintf(output,"%u ",(unsigned)value);
}

inline void dumpField(FILE *output,char value)
{
	fprintf(output,"%d ",value);
}

inline void dumpField(FILE *output,unsigned char value)
{
	fprintf(output,"%u ",(unsigned)value);
}

inline void dumpField(FILE *output,unsigned long long value)
{
	fprintf(output,"%llu ",value);
}

inline void dumpField(FILE *output,long long value)
{
	fprintf(output,"%lld ",value);
}

inline void dumpField(FILE *output,bool value)
{
	fprintf(output,"%s ",(value?"true":"false"));
}

inline void dumpField(FILE *output,double value)
{
	char buffer[1000];
	if (value!=DBL_MAX)
	{
		sprintf(buffer,"%.12f",value);
		if (strchr(buffer,'.'))
		{
			char *p=buffer+strlen(buffer)-1;
			while ((p>=buffer)&&(*p=='0'))
			{
				*p='\0';
				p--;
			}
			if ((p>=buffer)&&(*p=='.'))
			{
				*p='\0';
			}
		}
		if (buffer[0]=='\0')
		{
			strcpy(buffer,"0");
		}
		else if (buffer[0]=='-')
		{
			if (buffer[1]=='\0')
			{
				strcpy(buffer,"0");
			}
			else if ((buffer[1]=='0')&&(buffer[2]=='\0'))
			{
				strcpy(buffer,"0");
			}
		}
	}
	else
	{
		buffer[0]='\0';
	}

	fprintf(output,"%s(",buffer);
	unsigned char *p=(unsigned char *)&value;
	for (unsigned i=0;i<sizeof(double);i++)
	{
		fprintf(output,"%02X",p[i]);
	}
	fprintf(output,") ");
}

inline void dumpField(FILE *output,const char *value)
{
	if (value!=nullptr)
	{
		fprintf(output,"%s ",value);
	}
	else
	{
		fprintf(output," ");
	}
}

inline void dumpTimeField(FILE *output,int value,const CTimeFormatDesc *pTimeFormatDesc)
{
	char buffer[16];
	fprintf(output,"%s ",timeID2String(value,buffer,pTimeFormatDesc));
}

inline void dumpTimeStampField(FILE *output,int value,const CTimeFormatDesc *pTimeFormatDesc)
{
	char buffer[16];
	fprintf(output,"%s ",timeStamp2String(value,buffer,pTimeFormatDesc));
}

inline void dumpFlagSetField(FILE *output,const unsigned char *flags,int size)
{
	bool isFirst=true;
	for (int i=0;i<size;i++)
	{
		for (int bit=0;bit<8;bit++)
		{
			if (flags[i]&(1<<bit))
			{
				if (isFirst)
				{
					isFirst=false;
				}
				else
				{
					fprintf(output,",");
				}
				fprintf(output,"%d",i*8+bit);
			}
		}
	}
	fprintf(output," ");
}

#endif
