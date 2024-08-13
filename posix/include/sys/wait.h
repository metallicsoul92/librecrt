#ifndef SYS_WAIT_H
#define SYS_WAIT_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);

#define WNOHANG 1

#define WIFEXITED(status) ((status) & 0x7F == 0)
#define WEXITSTATUS(status) (((status) >> 8) & 0xFF)

#endif // SYS_WAIT_H
