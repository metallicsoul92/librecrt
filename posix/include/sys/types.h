#ifndef SYS_TYPES_H
#define SYS_TYPES_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

// POSIX data types
typedef long off_t;     // file sizes, offsets
typedef int pid_t;      // process IDs
typedef unsigned int mode_t; // file permissions
typedef long ssize_t;   // signed size type
typedef unsigned long time_t;  // time in seconds

#endif // SYS_TYPES_H
