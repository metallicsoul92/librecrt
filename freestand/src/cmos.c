#include "../include/cmos.h"
#include "../crt/include/stdint.h"

static inline uint8_t cmos_read(uint8_t reg) {
    outb(0x70, reg);
    return inb(0x71);
}

static int is_update_in_progress() {
    outb(0x70, 0x0A);
    return inb(0x71) & 0x80;
}

void cmos_get_time(CMOS_Time *time) {
    while (is_update_in_progress());  // Wait for CMOS to be ready

    time->seconds = cmos_read(0x00);
    time->minutes = cmos_read(0x02);
    time->hours   = cmos_read(0x04);
    time->day     = cmos_read(0x07);
    time->month   = cmos_read(0x08);
    time->year    = cmos_read(0x09);
    time->century = cmos_read(0x32);  // Century register (0x32) is often used
}

static uint8_t bcd_to_bin(uint8_t val) {
    return (val & 0x0F) + ((val / 16) * 10);
}

void cmos_get_time_bcd(CMOS_Time *time) {
    cmos_get_time(time);

    time->seconds = bcd_to_bin(time->seconds);
    time->minutes = bcd_to_bin(time->minutes);
    time->hours   = bcd_to_bin(time->hours);
    time->day     = bcd_to_bin(time->day);
    time->month   = bcd_to_bin(time->month);
    time->year    = bcd_to_bin(time->year);
    time->century = bcd_to_bin(time->century);
}
