/* cmos.h */

#ifndef _CMOS_H
#define _CMOS_H

#include "../../crt/include/stdint.h"

/**
 * @brief Structure representing the time retrieved from the CMOS.
 *
 * This structure holds the time values obtained from the CMOS registers,
 * including seconds, minutes, hours, day, month, year, and century.
 */
typedef struct {
    uint8_t seconds;  /**< Seconds (0-59) */
    uint8_t minutes;  /**< Minutes (0-59) */
    uint8_t hours;    /**< Hours (0-23) */
    uint8_t day;      /**< Day of the month (1-31) */
    uint8_t month;    /**< Month (1-12) */
    uint8_t year;     /**< Year (0-99) */
    uint8_t century;  /**< Century (optional, may be 0 if not supported) */
} CMOS_Time;

/**
 * @brief Retrieves the current time from the CMOS.
 *
 * This function reads the time values from the CMOS registers and populates
 * the provided CMOS_Time structure with these values.
 *
 * @param time A pointer to a CMOS_Time structure where the retrieved time will be stored.
 */
void cmos_get_time(CMOS_Time *time);

#endif /* _CMOS_H */
