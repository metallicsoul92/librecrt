/* freestand/io/src/stdio.c */

#include "../include/stdio.h"
#include "../include/io_device.h"
#include <stdarg.h>

int putc(int c) {
    io_device_t *device = get_io_device();
    if (device && device->write) {
        char ch = (char)c;
        return device->write(&ch, 1);
    }
    return -1;  // Return an error if no device is registered
}

int puts(const char *str) {
    io_device_t *device = get_io_device();
    if (device && device->write) {
        while (*str) {
            if (device->write(str, 1) < 0) {
                return -1;  // Return error if write fails
            }
            str++;
        }
        return device->write("\n", 1);  // Append a newline
    }
    return -1;  // Return an error if no device is registered
}

int printf(const char *format, ...) {
    io_device_t *device = get_io_device();
    if (!device || !device->write) {
        return -1;  // Return an error if no device is registered
    }

    va_list args;
    va_start(args, format);
    char buffer[1024];
    int written = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (written > 0) {
        return device->write(buffer, written);
    }

    return -1;  // Return an error if vsnprintf or write fails
}
