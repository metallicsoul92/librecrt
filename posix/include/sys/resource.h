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

/**
 * @brief Defines resource limits and functions to manage them.
 *
 * This header provides constants for resource limits and function prototypes for retrieving and setting them.
 */

/* Resource limit types */
#define RLIMIT_CPU     0   /**< CPU time in seconds */
#define RLIMIT_FSIZE   1   /**< Maximum file size */
#define RLIMIT_DATA    2   /**< Maximum data size */
#define RLIMIT_STACK   3   /**< Maximum stack size */
#define RLIMIT_CORE    4   /**< Maximum core file size */

typedef unsigned long rlim_t;  /**< Resource limit type */

/**
 * @brief Structure representing resource limits.
 *
 * This structure holds the current (soft) and maximum (hard) limits for a resource.
 */
struct rlimit {
    rlim_t rlim_cur;  /**< Current (soft) limit */
    rlim_t rlim_max;  /**< Maximum value for rlim_cur */
};

int getrlimit(int resource, struct rlimit *rlim);  /**< Gets resource limits */
int setrlimit(int resource, const struct rlimit *rlim); /**< Sets resource limits */

#endif // SYS_RESOURCE_H
