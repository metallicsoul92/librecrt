/* freestand/io/include/io_device.h */

#ifndef _IO_DEVICE_H
#define _IO_DEVICE_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Structure representing a generic I/O device.
 *
 * This structure provides function pointers for basic I/O operations that
 * can be implemented by any specific device (e.g., serial port, memory buffer).
 */
typedef struct {
    int (*write)(const void *buffer, size_t size); /**< Function pointer to write data to the device */
    int (*read)(void *buffer, size_t size);        /**< Function pointer to read data from the device */
    int (*flush)(void);                            /**< Function pointer to flush the device's buffer */
} io_device_t;

/**
 * @brief Registers an I/O device for global use.
 *
 * This function registers a global I/O device that can be used by
 * standard I/O functions like putc, puts, etc.
 *
 * @param device Pointer to the io_device_t structure representing the device.
 */
void register_io_device(io_device_t *device);

/**
 * @brief Gets the currently registered I/O device.
 *
 * @return Pointer to the io_device_t structure representing the currently registered device.
 */
io_device_t* get_io_device(void);

#endif /* _IO_DEVICE_H */
