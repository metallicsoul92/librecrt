#ifndef SYS_SELECT_H
#define SYS_SELECT_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines structures and functions for selecting file descriptors.
 *
 * The select function is used to monitor multiple file descriptors to see if any are ready for I/O operations.
 */

/**
 * @brief Structure representing a file descriptor set.
 *
 * This structure holds the file descriptors to be monitored by the select function.
 */
typedef struct {
    int fd_count;              /**< Number of file descriptors in the set */
    fd_set fd_array[FD_SETSIZE]; /**< Array of file descriptors */
} fd_set;

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout); /**< Monitors file descriptors for I/O readiness */

#endif // SYS_SELECT_H
