#include "time.h"
#include "freestand/cmos.h"

static int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static int is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

static int day_of_year(int year, int month, int day) {
    int yday = 0;
    for (int i = 0; i < month - 1; i++) {
        yday += days_in_month[i];
    }
    yday += day;
    if (month > 2 && is_leap_year(year)) {
        yday++;
    }
    return yday;
}

time_t time(time_t *t) {
    CMOS_Time cmos_time;
    cmos_get_time_bcd(&cmos_time);

    struct tm tm_time = {
        .tm_sec  = cmos_time.seconds,
        .tm_min  = cmos_time.minutes,
        .tm_hour = cmos_time.hours,
        .tm_mday = cmos_time.day,
        .tm_mon  = cmos_time.month - 1,
        .tm_year = cmos_time.year + 100, // Assuming year is 20xx
        .tm_wday = 0,                    // Not calculated here
        .tm_yday = day_of_year(cmos_time.year + 2000, cmos_time.month, cmos_time.day),
        .tm_isdst = -1                   // Daylight saving time not supported
    };

    time_t time_in_seconds = (tm_time.tm_year - 70) * 365 * 24 * 3600;
    time_in_seconds += tm_time.tm_yday * 24 * 3600;
    time_in_seconds += tm_time.tm_hour * 3600;
    time_in_seconds += tm_time.tm_min * 60;
    time_in_seconds += tm_time.tm_sec;

    if (t) {
        *t = time_in_seconds;
    }
    return time_in_seconds;
}

struct tm *gmtime(const time_t *timer) {
    static struct tm tm_time;
    time_t t = *timer;
    int year = 1970;

    while (t >= 365 * 24 * 3600) {
        t -= 365 * 24 * 3600;
        if (is_leap_year(year)) {
            t -= 24 * 3600;
        }
        year++;
    }

    tm_time.tm_year = year - 1900;
    tm_time.tm_yday = t / (24 * 3600);
    t %= 24 * 3600;
    tm_time.tm_hour = t / 3600;
    t %= 3600;
    tm_time.tm_min = t / 60;
    tm_time.tm_sec = t % 60;
    tm_time.tm_mon = 0; // Not calculated
    tm_time.tm_mday = 0; // Not calculated
    tm_time.tm_wday = 0; // Not calculated
    tm_time.tm_isdst = 0;

    return &tm_time;
}

struct tm *localtime(const time_t *timer) {
    return gmtime(timer); // No timezone support in this implementation
}

static void itoa(int value, char *str, int base) {
    char *p = str;
    char *p1, *p2;
    unsigned int v;

    if (base == 10 && value < 0) {
        v = -value;
        *p++ = '-';
    } else {
        v = (unsigned int)value;
    }

    do {
        int remainder = v % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
    } while (v /= base);

    *p = '\0';

    /* Reverse the string */
    p1 = str;
    if (*str == '-') {
        p1++;
    }
    p2 = p - 1;
    while (p1 < p2) {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
}

char *asctime(const struct tm *timeptr) {
    static char buffer[26];
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    /* Fill buffer with a formatted string: "Day Mon DD HH:MM:SS YYYY\n" */
    int pos = 0;

    /* Day of the week */
    buffer[pos++] = '?';  // Placeholder for day (could be calculated)
    buffer[pos++] = ' ';

    /* Month */
    for (int i = 0; i < 3; i++) {
        buffer[pos++] = months[timeptr->tm_mon][i];
    }
    buffer[pos++] = ' ';

    /* Day of the month */
    itoa(timeptr->tm_mday, &buffer[pos], 10);
    pos += 2;
    buffer[pos++] = ' ';

    /* Hours */
    itoa(timeptr->tm_hour, &buffer[pos], 10);
    pos += 2;
    buffer[pos++] = ':';

    /* Minutes */
    itoa(timeptr->tm_min, &buffer[pos], 10);
    pos += 2;
    buffer[pos++] = ':';

    /* Seconds */
    itoa(timeptr->tm_sec, &buffer[pos], 10);
    pos += 2;
    buffer[pos++] = ' ';

    /* Year */
    itoa(timeptr->tm_year + 1900, &buffer[pos], 10);
    pos += 4;
    buffer[pos++] = '\n';

    buffer[pos] = '\0';

    return buffer;
}

char *ctime(const time_t *timer) {
    return asctime(gmtime(timer));
}
