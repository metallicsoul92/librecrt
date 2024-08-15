#ifndef SYS_TYPES_H
#define SYS_TYPES_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

/**
 * @brief Defines common POSIX data types.
 *
 * This header provides typedefs for various POSIX data types, such as file offsets, process IDs, and sizes.
 */

/* POSIX data types */
typedef long off_t;     /**< File sizes, offsets */
typedef int pid_t;      /**< Process IDs */
typedef unsigned int mode_t; /**< File permissions */
typedef long ssize_t;   /**< Signed size type */
typedef unsigned long time_t;  /**< Time in seconds */

#endif // SYS_TYPES_H
