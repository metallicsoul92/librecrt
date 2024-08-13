/* cmos.h */

#ifndef _CMOS_H
#define _CMOS_H

#include "../crt/include/stdint.h"

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
    uint8_t century;
} CMOS_Time;

void cmos_get_time(CMOS_Time *time);

#endif /* _CMOS_H */
