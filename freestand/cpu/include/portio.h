/* freestand/cpu/include/portio.h */

#ifndef _PORTIO_H
#define _PORTIO_H

#include "../../crt/include/stdint.h"

/**
 * @brief Reads a byte from the specified I/O port.
 *
 * This function reads a single byte (8 bits) from the given I/O port.
 *
 * @param port The I/O port to read from.
 * @return The byte read from the I/O port.
 */
static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

/**
 * @brief Writes a byte to the specified I/O port.
 *
 * This function writes a single byte (8 bits) to the given I/O port.
 *
 * @param port The I/O port to write to.
 * @param data The byte to write to the I/O port.
 */
static inline void outb(uint16_t port, uint8_t data) {
    __asm__ volatile ("outb %0, %1" : : "a"(data), "Nd"(port));
}

/**
 * @brief Reads a word (2 bytes) from the specified I/O port.
 *
 * This function reads a word (16 bits) from the given I/O port.
 *
 * @param port The I/O port to read from.
 * @return The word read from the I/O port.
 */
static inline uint16_t inw(uint16_t port) {
    uint16_t result;
    __asm__ volatile ("inw %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

/**
 * @brief Writes a word (2 bytes) to the specified I/O port.
 *
 * This function writes a word (16 bits) to the given I/O port.
 *
 * @param port The I/O port to write to.
 * @param data The word to write to the I/O port.
 */
static inline void outw(uint16_t port, uint16_t data) {
    __asm__ volatile ("outw %0, %1" : : "a"(data), "Nd"(port));
}

/**
 * @brief Reads a double word (4 bytes) from the specified I/O port.
 *
 * This function reads a double word (32 bits) from the given I/O port.
 *
 * @param port The I/O port to read from.
 * @return The double word read from the I/O port.
 */
static inline uint32_t inl(uint16_t port) {
    uint32_t result;
    __asm__ volatile ("inl %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

/**
 * @brief Writes a double word (4 bytes) to the specified I/O port.
 *
 * This function writes a double word (32 bits) to the given I/O port.
 *
 * @param port The I/O port to write to.
 * @param data The double word to write to the I/O port.
 */
static inline void outl(uint16_t port, uint32_t data) {
    __asm__ volatile ("outl %0, %1" : : "a"(data), "Nd"(port));
}

#endif /* _PORTIO_H */
