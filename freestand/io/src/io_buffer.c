/* freestand/io/src/io_buffer.c */

#include "../include/io_buffer.h"
#include "../include/string.h"  // For memcpy and memset

void init_io_buffer(io_buffer_t *buffer, char *memory, size_t size) {
    buffer->buffer = memory;
    buffer->size = size;
    buffer->position = 0;
}

int io_buffer_write(io_buffer_t *buffer, const void *data, size_t size) {
    if (buffer->position + size > buffer->size) {
        size = buffer->size - buffer->position;  // Truncate to remaining buffer space
    }
    memcpy(buffer->buffer + buffer->position, data, size);
    buffer->position += size;
    return size;
}

int io_buffer_read(io_buffer_t *buffer, void *data, size_t size) {
    if (buffer->position + size > buffer->size) {
        size = buffer->size - buffer->position;  // Truncate to remaining buffer content
    }
    memcpy(data, buffer->buffer + buffer->position, size);
    buffer->position += size;
    return size;
}

void io_buffer_flush(io_buffer_t *buffer) {
    memset(buffer->buffer, 0, buffer->size);
    buffer->position = 0;
}
