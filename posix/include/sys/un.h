#ifndef SYS_UN_H
#define SYS_UN_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

struct sockaddr_un {
    sa_family_t sun_family;
    char sun_path[108];
};

#endif // SYS_UN_H
