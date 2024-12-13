/* time.h */

#ifndef _TIME_H
#define _TIME_H

#ifndef __HAS_STDDEF
#define __HAS_STDDEF
#include "stddef.h"
#endif

#ifndef __HAS_STDINT
#define __HAS_STDINT
#include "stdint.h"
#endif

/**
 * @brief Defines types and functions for manipulating time.
 *
 * This header provides the `time_t` type and the `struct tm` structure, along with function prototypes for working with time and dates.
 */

/* Define types for time_t and struct tm */
typedef int64_t time_t; /**< Represents the calendar time */

/**
 * @brief Structure representing a broken-down time.
 *
 * This structure holds the components of a calendar time, such as year, month, day, etc.
 */
struct tm {
    int tm_sec;    /**< Seconds after the minute - [0, 60] including leap second */
    int tm_min;    /**< Minutes after the hour - [0, 59] */
    int tm_hour;   /**< Hours since midnight - [0, 23] */
    int tm_mday;   /**< Day of the month - [1, 31] */
    int tm_mon;    /**< Months since January - [0, 11] */
    int tm_year;   /**< Years since 1900 */
    int tm_wday;   /**< Days since Sunday - [0, 6] */
    int tm_yday;   /**< Days since January 1 - [0, 365] */
    int tm_isdst;  /**< Daylight savings time flag */
};

/* Function prototypes */
time_t time(time_t *t); /**< Returns the current calendar time */
struct tm *gmtime(const time_t *timer); /**< Converts calendar time to UTC */
struct tm *localtime(const time_t *timer); /**< Converts calendar time to local time */
char *asctime(const struct tm *timeptr); /**< Converts broken-down time to a string */
char *ctime(const time_t *timer); /**< Converts calendar time to a string */

/**
 * @brief Helper function to convert integers to strings.
 *
 * This function converts an integer to a string representation in the specified base.
 *
 * @param value The integer value to convert.
 * @param str The buffer to store the string representation.
 * @param base The base for the conversion (e.g., 10 for decimal, 16 for hexadecimal).
 */
static void itoa(int value, char *str, int base);

#endif /* _TIME_H */
