#ifndef HRTIMER_HPP
#define HRTIMER_HPP

#include <cstdio>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#ifndef force_inline
#define force_inline __attribute__ ((__always_inline__))
#endif

namespace TimeUtil
{

class HRTimer 
{
public:
     HRTimer(): m_Start(0) 
     {
          m_NsPerTSC = 1.0;
          SyncTime(m_BaseTSC, m_BaseNs);
          Calibrate();
     }

     force_inline inline void Start() 
     {
          m_Start = RDTSCP();
     }

     force_inline inline uint64_t Stop() 
     {
          uint64_t end = RDTSCP();
          uint64_t nano = (end - m_Start) * m_NsPerTSC;
          m_Start = 0;
          return nano;
     }

     force_inline inline uint64_t GetTimeNs() const
     {
          return TSC2Ns(RDTSCP());
     }

     static force_inline inline const char *GetTimeNs(uint64_t cycles)
     {
          time_t current = cycles / 1e9;
          struct tm timeStamp;
          localtime_r(&current, &timeStamp);
          static char szBuffer[64] = {0};
          strftime(szBuffer, sizeof(szBuffer), "%Y-%m-%d %H:%M:%S", &timeStamp);
          unsigned long mod = 1e9;
          unsigned long ret = cycles % mod;
          sprintf(szBuffer, "%s.%09u", szBuffer, ret);
          return szBuffer;
     }

     static force_inline inline const char *GetTimeUs(uint64_t cycles)
     {
          time_t current = cycles / 1e9;
          struct tm timeStamp;
          localtime_r(&current, &timeStamp);
          static char szBuffer[64] = {0};
          strftime(szBuffer, sizeof(szBuffer), "%Y-%m-%d %H:%M:%S", &timeStamp);
          unsigned long mod = 1e6;
          unsigned long ret = cycles % mod;
          sprintf(szBuffer, "%s.%06u", szBuffer, ret);
          return szBuffer;
     }

     double GetCPUHZ() const
     {
          return 1.0e9 / m_NsPerTSC;
     }
protected:
     static force_inline inline int64_t RDTSC() 
     {
          static uint32_t hi, lo;
          __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
          return ( (uint64_t)lo) | (((uint64_t)hi) << 32);
     }

     static force_inline inline uint64_t RDTSCP() 
     {
          unsigned int d = 0;
          return __builtin_ia32_rdtscp(&d);
     }

     force_inline inline uint64_t TSC2Ns(int64_t cycles) const
     {
          return m_NsOffset + (int64_t)(cycles * m_NsPerTSC);
     }

     void UpdateNsOffset() 
     { 
          m_NsOffset = m_BaseNs - (int64_t)(m_BaseTSC * m_NsPerTSC); 
     }

     int64_t NsOffset() const
     {
          return m_NsOffset;
     }

     static force_inline inline uint64_t GetCurrentTimeNs()
     {
          struct timespec timeStamp = {0, 0};
          clock_gettime(CLOCK_REALTIME, &timeStamp); 
          return timeStamp.tv_sec * 1e9 + timeStamp.tv_nsec;
     }

     void SyncTime(uint64_t& tsc, uint64_t& ns) 
     {
          const int N = 10;
          uint64_t TSCArray[N+1];
          uint64_t NSArray[N+1];

          TSCArray[0] = RDTSCP();
          for(int i = 1; i <= N; i++) 
          {
               NSArray[i] = GetCurrentTimeNs();
               TSCArray[i] = RDTSCP();
          }

          int best = 1;
          for(int i = 2; i <= N; i++) 
          {
               if(TSCArray[i] - TSCArray[i-1] < TSCArray[best] - TSCArray[best-1]) 
                    best = i;
          }
          tsc = (TSCArray[best] + TSCArray[best-1]) >> 1;
          ns = NSArray[best];
     }

     force_inline inline void Calibrate(int64_t min_wait_ns = 250 * 1e6) 
     {
          uint64_t delayed_tsc, delayed_ns;
          do 
          {
               SyncTime(delayed_tsc, delayed_ns);
          }while((delayed_ns - m_BaseNs) < min_wait_ns);
          m_NsPerTSC = (double)(delayed_ns - m_BaseNs) / (delayed_tsc - m_BaseTSC);
          UpdateNsOffset();
     }
protected:
    uint64_t m_Start;
    double m_NsPerTSC;
    int64_t m_NsOffset;
    uint64_t m_BaseNs;
    uint64_t m_BaseTSC;
};

}

#endif // HRTIMER_HPP