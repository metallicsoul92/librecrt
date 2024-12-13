/* freestand/io/src/io_device.c */

#include "../include/io_device.h"

static io_device_t *current_io_device = NULL;

void register_io_device(io_device_t *device) {
    current_io_device = device;
}

io_device_t* get_io_device(void) {
    return current_io_device;
}
