#include "HRTimer.hpp"

#include <time.h>
#include <unistd.h>
#include <cstdio>
#include <stdio.h>
#include <string.h>

static uint64_t getTimeNs()
{
    struct timespec timeStamp = {0, 0};
    clock_gettime(CLOCK_REALTIME, &timeStamp);
    return timeStamp.tv_sec * 1e9 + timeStamp.tv_nsec;
}

int main(int argc, char const *argv[])
{
    char buffer[32] = {0};
    // HRTimer高精度计时器
    TimeUtil::HRTimer timer;
    fprintf(stderr, "HRTimer CPUHZ: %.6f MHZ\n", timer.GetCPUHZ() / 1e6);
    {
        uint64_t start = timer.GetTimeNs();
        memcpy(buffer, "Hello", sizeof(buffer));
        uint64_t end = timer.GetTimeNs();
        uint64_t diff = (end - start);
        fprintf(stderr, "HRTimer: %lu - %lu = %lu\n", end,  start, diff);
    }

    {
        timer.Start();
        memcpy(buffer, "12345", sizeof(buffer));
        uint64_t diff = timer.Stop();
        fprintf(stderr, "HRTimer: %lu\n", diff);
    }

    // GetTimeNs调用延迟
    {
        uint64_t latency;
        const int N = 100;
        uint64_t start = timer.GetTimeNs();
        uint64_t tmp = 0;
        for (int i = 0; i < N; i++) 
        {
            tmp += timer.GetTimeNs();
        }
        uint64_t end = timer.GetTimeNs();
        latency = (end - start) / (N + 1);
        fprintf(stderr, "HRTimer GetTimeNs Latency: %lu\n", latency);
    }

    // Linux CLOCK_REALTIME时钟
    {
        uint64_t start = getTimeNs();
        memcpy(buffer, "56789", sizeof(buffer));
        uint64_t end = getTimeNs();
        uint64_t diff = (end - start);
        fprintf(stderr, "CLOCK_REALTIME: %lu - %lu = %lu\n", end, start, diff);
    }

    return 0;
}

// g++ --std=c++11 -O2 HRTimerTest.cpp -o timer