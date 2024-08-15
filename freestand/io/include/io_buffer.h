/* freestand/io/include/io_buffer.h */

#ifndef _IO_BUFFER_H
#define _IO_BUFFER_H

#include <stddef.h>

/**
 * @brief Structure representing a simple I/O buffer.
 *
 * This structure holds a buffer in memory, including its size and current position.
 */
typedef struct {
    char *buffer;    /**< Pointer to the buffer memory */
    size_t size;     /**< Total size of the buffer */
    size_t position; /**< Current position in the buffer */
} io_buffer_t;

/**
 * @brief Initializes an I/O buffer.
 *
 * @param buffer Pointer to the io_buffer_t structure to initialize.
 * @param memory Pointer to the memory to use as the buffer.
 * @param size Size of the memory buffer.
 */
void init_io_buffer(io_buffer_t *buffer, char *memory, size_t size);

/**
 * @brief Writes data to an I/O buffer.
 *
 * @param buffer Pointer to the io_buffer_t structure representing the buffer.
 * @param data Pointer to the data to write.
 * @param size Size of the data to write.
 * @return Number of bytes written.
 */
int io_buffer_write(io_buffer_t *buffer, const void *data, size_t size);

/**
 * @brief Reads data from an I/O buffer.
 *
 * @param buffer Pointer to the io_buffer_t structure representing the buffer.
 * @param data Pointer to the memory where data will be read into.
 * @param size Size of the data to read.
 * @return Number of bytes read.
 */
int io_buffer_read(io_buffer_t *buffer, void *data, size_t size);

/**
 * @brief Flushes an I/O buffer (clears its content).
 *
 * @param buffer Pointer to the io_buffer_t structure representing the buffer.
 */
void io_buffer_flush(io_buffer_t *buffer);

#endif /* _IO_BUFFER_H */
