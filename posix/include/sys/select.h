#ifndef SYS_SELECT_H
#define SYS_SELECT_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

typedef struct {
    int fd_count;
    fd_set fd_array[FD_SETSIZE];
} fd_set;

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

#endif // SYS_SELECT_H
