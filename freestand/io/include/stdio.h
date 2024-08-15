/* freestand/io/include/stdio.h */

#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>

/**
 * @brief Writes a character to the registered I/O device.
 *
 * @param c The character to write.
 * @return The character written, or -1 on error.
 */
int putc(int c);

/**
 * @brief Writes a string to the registered I/O device.
 *
 * @param str The string to write.
 * @return Non-negative on success, or EOF on error.
 */
int puts(const char *str);

/**
 * @brief Prints a formatted string to the registered I/O device.
 *
 * @param format The format string.
 * @param ... The values to format and print.
 * @return Number of characters printed, or -1 on error.
 */
int printf(const char *format, ...);

#endif /* _STDIO_H */
