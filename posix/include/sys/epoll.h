#ifndef SYS_EPOLL_H
#define SYS_EPOLL_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines constants and functions for the epoll API.
 *
 * The epoll API is used for scalable I/O event notification on file descriptors.
 */

#define EPOLLIN  0x001  /**< There is data to read */
#define EPOLLOUT 0x004  /**< Writing is possible */

int epoll_create(int size);  /**< Creates an epoll instance */
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event); /**< Controls an epoll instance */
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout); /**< Waits for I/O events */

#endif // SYS_EPOLL_H
