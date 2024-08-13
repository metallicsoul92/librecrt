#ifndef SYS_IOCTL_H
#define SYS_IOCTL_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

int ioctl(int fd, unsigned long request, ...);

#endif // SYS_IOCTL_H
