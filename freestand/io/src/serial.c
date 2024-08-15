/* freestand/io/src/serial.c */

#include "../include/serial.h"
#include "../include/portio.h"

static uint16_t serial_port = 0;

void init_serial(uint16_t port) {
    serial_port = port;

    // Initialize the serial port
    outb(serial_port + 1, 0x00);    // Disable all interrupts
    outb(serial_port + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(serial_port + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(serial_port + 1, 0x00);    //                  (hi byte)
    outb(serial_port + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(serial_port + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(serial_port + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

int serial_write(const void *buffer, size_t size) {
    const char *data = (const char *)buffer;
    for (size_t i = 0; i < size; i++) {
        while ((inb(serial_port + 5) & 0x20) == 0);
        outb(serial_port, data[i]);
    }
    return size;
}

int serial_read(void *buffer, size_t size) {
    char *data = (char *)buffer;
    size_t bytes_read = 0;
    for (size_t i = 0; i < size; i++) {
        while ((inb(serial_port + 5) & 0x01) == 0);
        data[i] = inb(serial_port);
        bytes_read++;
    }
    return bytes_read;
}

int serial_flush(void) {
    while ((inb(serial_port + 5) & 0x40) == 0);
    return 0;
}
