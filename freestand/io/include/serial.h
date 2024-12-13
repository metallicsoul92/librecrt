/* freestand/io/include/serial.h */

#ifndef _SERIAL_H
#define _SERIAL_H

#include <stddef.h>
#include "io_device.h"

/**
 * @brief Initializes the serial port.
 *
 * This function initializes the serial port for communication.
 *
 * @param port The I/O port address for the serial device.
 */
void init_serial(uint16_t port);

/**
 * @brief Serial port write function.
 *
 * This function writes data to the serial port.
 *
 * @param buffer Pointer to the data to write.
 * @param size Number of bytes to write.
 * @return Number of bytes written.
 */
int serial_write(const void *buffer, size_t size);

/**
 * @brief Serial port read function.
 *
 * This function reads data from the serial port.
 *
 * @param buffer Pointer to the buffer to read data into.
 * @param size Number of bytes to read.
 * @return Number of bytes read.
 */
int serial_read(void *buffer, size_t size);

/**
 * @brief Serial port flush function.
 *
 * This function flushes the serial port buffer.
 *
 * @return 0 on success, or -1 on error.
 */
int serial_flush(void);

#endif /* _SERIAL_H */
