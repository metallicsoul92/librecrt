#ifndef SYS_MMAN_H
#define SYS_MMAN_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

#define PROT_READ  0x1  // Pages may be read
#define PROT_WRITE 0x2  // Pages may be written
#define MAP_SHARED 0x01 // Share changes

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t length);

#endif // SYS_MMAN_H
