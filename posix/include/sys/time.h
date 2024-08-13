#ifndef SYS_TIME_H
#define SYS_TIME_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

// Structure for time of day
struct timeval {
    time_t tv_sec;  // seconds
    long tv_usec;   // microseconds
};

// Structure for timezone (not really used in freestanding)
struct timezone {
    int tz_minuteswest; // minutes west of Greenwich
    int tz_dsttime;     // type of DST correction
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif // SYS_TIME_H
