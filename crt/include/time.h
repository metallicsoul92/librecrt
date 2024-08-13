/* time.h */

#ifndef _TIME_H
#define _TIME_H

#include "stddef.h"
#include "stdint.h"

/* Define types for time_t and struct tm */
typedef int64_t time_t;

struct tm {
    int tm_sec;    /* seconds after the minute - [0, 60] including leap second */
    int tm_min;    /* minutes after the hour - [0, 59] */
    int tm_hour;   /* hours since midnight - [0, 23] */
    int tm_mday;   /* day of the month - [1, 31] */
    int tm_mon;    /* months since January - [0, 11] */
    int tm_year;   /* years since 1900 */
    int tm_wday;   /* days since Sunday - [0, 6] */
    int tm_yday;   /* days since January 1 - [0, 365] */
    int tm_isdst;  /* daylight savings time flag */
};

/* Function prototypes */
time_t time(time_t *t);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
char *asctime(const struct tm *timeptr);
char *ctime(const time_t *timer);

/* Helper function to convert integers to strings */
static void itoa(int value, char *str, int base);

#endif /* _TIME_H */
