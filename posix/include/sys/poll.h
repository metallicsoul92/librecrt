#ifndef SYS_POLL_H
#define SYS_POLL_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines structures and functions for polling file descriptors.
 *
 * The poll function is used to monitor multiple file descriptors to see if any have events pending.
 */

struct pollfd {
    int fd;         /**< File descriptor to poll */
    short events;   /**< Requested events */
    short revents;  /**< Returned events */
};

int poll(struct pollfd *fds, nfds_t nfds, int timeout); /**< Polls for events on file descriptors */

#endif // SYS_POLL_H
