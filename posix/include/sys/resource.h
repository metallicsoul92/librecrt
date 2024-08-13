#ifndef SYS_RESOURCE_H
#define SYS_RESOURCE_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

// Resource limit types
#define RLIMIT_CPU     0   // CPU time in seconds
#define RLIMIT_FSIZE   1   // Maximum filesize
#define RLIMIT_DATA    2   // max data size
#define RLIMIT_STACK   3   // max stack size
#define RLIMIT_CORE    4   // max core file size

typedef unsigned long rlim_t;

struct rlimit {
    rlim_t rlim_cur;  // current (soft) limit
    rlim_t rlim_max;  // maximum value for rlim_cur
};

int getrlimit(int resource, struct rlimit *rlim);
int setrlimit(int resource, const struct rlimit *rlim);

#endif // SYS_RESOURCE_H
