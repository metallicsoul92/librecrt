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

// File access modes
#define O_RDONLY 0x0000  // open for reading only
#define O_WRONLY 0x0001  // open for writing only
#define O_RDWR   0x0002  // open for reading and writing

// File creation flags
#define O_CREAT  0x0100  // create if nonexistent
#define O_TRUNC  0x0200  // truncate to zero length
#define O_APPEND 0x0400  // append on each write

int open(const char *pathname, int flags, mode_t mode);
int close(int fd);
int fcntl(int fd, int cmd, ...);

#endif // SYS_FCNTL_H
