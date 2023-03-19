#ifndef FMTLOGGER_HPP
#define FMTLOGGER_HPP

#include <time.h>
#include "fmtlog.h"

namespace FMTLog
{
class Logger
{
public:
    static void Init(const std::string& path, const std::string& appName)
    {
        char buffer[256] = {0};
        sprintf(buffer, "%s/%s_%s.log", path.c_str(), appName.c_str(), GetCurrentDay());
        // 设置日志文件路径
        fmtlog::setLogFile(buffer);
        // 设置日志头格式
        fmtlog::setHeaderPattern("{YmdHMSF} {s} {l}[{t}] ");
        // 2022-10-23 10:19:49.617437758 FMTLoggerTest.cpp:36 INF[test] The answer is 42.
        // 预分配线程队列
        fmtlog::preallocate();
        // 设置日志刷新级别
        fmtlog::flushOn(fmtlog::WRN);
        // 设置日志刷新时间间隔
        fmtlog::setFlushDelay(10);
        // 设置日志队列满回调函数
        fmtlog::setLogQFullCB(LogQFullCB, NULL);
        // 分配后台轮询线程
        fmtlog::startPollingThread(10);
    }

    // 设置调试级别日志
    static void SetDebugLevel(bool debug = true)
    {
        if(debug)
        {
            // 设置日志系统日志级别
            fmtlog::setLogLevel(fmtlog::DBG);
        }
        else
        {
            // 设置日志系统日志级别
            fmtlog::setLogLevel(fmtlog::INF);
        }
    }
protected:
    static void LogQFullCB(void* userData) 
    {
        FMTLOG(fmtlog::ERR, "Log Queue full.");
    }

    static const char *GetCurrentDay()
    {
        struct timespec timeSpec = {0, 0};
        clock_gettime(CLOCK_REALTIME, &timeSpec);
        time_t current = timeSpec.tv_sec;
        struct tm timeStamp;
        localtime_r(&current, &timeStamp);
        static char szBuffer[64] = {0};
        strftime(szBuffer, sizeof(szBuffer), "%Y-%m-%d-%H-%M-%S", &timeStamp);
        return szBuffer;
    }
private:
    Logger();
    Logger &operator=(const Logger &);
    Logger(const Logger &);
};
}

#endif // FMTLOGGER_HPP