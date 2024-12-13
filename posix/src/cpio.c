/* posix/src/cpio.c */

#include "../include/cpio.h"

uint32_t cpio_hex_to_int(const char *hex_str) {
    uint32_t value = 0;
    while (*hex_str) {
        value = (value << 4) | (*hex_str >= 'a' ? (*hex_str - 'a' + 10) : (*hex_str - '0'));
        hex_str++;
    }
    return value;
}

struct cpio_header* cpio_parse_header(const char *buffer) {
    return (struct cpio_header*)buffer;
}
