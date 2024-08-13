#ifndef SYS_EPOLL_H
#define SYS_EPOLL_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

#define EPOLLIN  0x001
#define EPOLLOUT 0x004

int epoll_create(int size);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

#endif // SYS_EPOLL_H
