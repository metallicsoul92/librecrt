#ifndef SYS_WAIT_H
#define SYS_WAIT_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Provides functions for waiting on child processes.
 *
 * This header defines macros and function prototypes for waiting on child processes to change state.
 */

pid_t wait(int *status); /**< Waits for any child process to change state */
pid_t waitpid(pid_t pid, int *status, int options); /**< Waits for a specific child process to change state */

#define WNOHANG 1 /**< Option to return immediately if no child has exited */

/* Macros to examine the status returned by wait or waitpid */
#define WIFEXITED(status) ((status) & 0x7F == 0) /**< True if the child exited normally */
#define WEXITSTATUS(status) (((status) >> 8) & 0xFF) /**< Returns the exit status of the child */

#endif // SYS_WAIT_H
