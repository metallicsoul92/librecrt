#ifndef SYS_FCNTL_H
#define SYS_FCNTL_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines file control options and functions.
 *
 * This header provides constants for file access modes and function prototypes
 * for performing file control operations, such as opening, closing, and manipulating file descriptors.
 */

/* File access modes */
#define O_RDONLY 0x0000  /**< Open for reading only */
#define O_WRONLY 0x0001  /**< Open for writing only */
#define O_RDWR   0x0002  /**< Open for reading and writing */

/* File creation flags */
#define O_CREAT  0x0100  /**< Create if nonexistent */
#define O_TRUNC  0x0200  /**< Truncate to zero length */
#define O_APPEND 0x0400  /**< Append on each write */

int open(const char *pathname, int flags, mode_t mode); /**< Opens a file */
int close(int fd);  /**< Closes a file descriptor */
int fcntl(int fd, int cmd, ...); /**< Performs operations on file descriptors */

#endif // SYS_FCNTL_H
