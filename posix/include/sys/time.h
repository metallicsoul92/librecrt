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

/**
 * @brief Defines structures and functions for time and date operations.
 *
 * This header provides structures for representing time and functions to retrieve the current time.
 */

/**
 * @brief Structure representing the time of day.
 *
 * This structure holds the number of seconds and microseconds since the Epoch.
 */
struct timeval {
    time_t tv_sec;  /**< Seconds */
    long tv_usec;   /**< Microseconds */
};

/**
 * @brief Structure representing the timezone.
 *
 * This structure holds information about the time zone, including the minutes west of Greenwich and daylight saving time.
 */
struct timezone {
    int tz_minuteswest; /**< Minutes west of Greenwich */
    int tz_dsttime;     /**< Type of DST correction */
};

int gettimeofday(struct timeval *tv, struct timezone *tz); /**< Retrieves the current time of day */

#endif // SYS_TIME_H
