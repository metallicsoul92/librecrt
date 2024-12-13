#ifndef SYS_MMAN_H
#define SYS_MMAN_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines memory management constants and functions.
 *
 * This header provides function prototypes for memory mapping operations, such as mapping files or devices into memory.
 */

#define PROT_READ  0x1  /**< Pages may be read */
#define PROT_WRITE 0x2  /**< Pages may be written */
#define MAP_SHARED 0x01 /**< Share changes */

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset); /**< Maps files or devices into memory */
int munmap(void* addr, size_t length); /**< Unmaps memory */

#endif // SYS_MMAN_H
