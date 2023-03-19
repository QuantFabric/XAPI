#include "FMTLogger.hpp"
#include <chrono>

int main(int argc, char* argv[]) 
{
    FMTLog::Logger::Init("./", "Test");
    FMTLog::Logger::SetDebugLevel(true);
    // 延迟测试
    const int RECORDS = 10000;
    std::chrono::high_resolution_clock::time_point t0, t1, t2;
    t0 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < RECORDS; ++i) 
    {
        FMTLOG(fmtlog::INF, "{2} fotmat, int:{0:d}; hex:{0:#x}; oct:{0:#o}; bin:{0:#b} {1:.6f}", 42, 3.1415927, "Hello");
    }
    t1 = std::chrono::high_resolution_clock::now();
    double diff = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
    FMTLOG(fmtlog::INF, "front-end latency is {:.1f} ns/msg average.", (diff / RECORDS) * 1e9);

    // 指定日志级别
    FMTLOG(fmtlog::DBG, "The answer is {}.", 42);
    FMTLOG(fmtlog::INF, "The answer is {}.", 42);
    FMTLOG(fmtlog::WRN, "The answer is {}.", 42);
    FMTLOG(fmtlog::ERR, "The answer is {}.", 42);
    // 指定日志级别，时间限制
    FMTLOG_LIMIT(10, fmtlog::DBG, "The answer is {}.", 42);
    FMTLOG_LIMIT(10, fmtlog::INF, "The answer is {}.", 42);
    FMTLOG_LIMIT(10, fmtlog::WRN, "The answer is {}.", 42);
    FMTLOG_LIMIT(10, fmtlog::ERR, "The answer is {}.", 42);
    // 格式化示例
    FMTLOG(fmtlog::INF, "{1} fotmat, int:{0:d}; hex:{0:#x}; hex:{0:#X}; oct:{0:#o}; bin:{0:#b} {0:.6f}", 42, 3.1415927, "Hello");
    FMTLOG(fmtlog::INF, "{} dynamic precision fotmat {:.{}f}", "Hello", 3.14, 3);
}
// g++ -std=c++17 -O2 FMTLoggerTest.cpp FMTLogger.hpp -o test -lfmtlog -lfmt -pthread -I. -L../lib/
// g++ -std=c++17 -DFMT_HEADER_ONLY -DFMTLOG_HEADER_ONLY -O2 FMTLoggerTest.cpp -o test -pthread -I.