/* errno.h */

#ifndef _ERRNO_H
#define _ERRNO_H

/**
 * @brief Error codes used by system calls and library functions.
 *
 * The `errno` variable holds error codes that indicate the type of error that occurred.
 */

extern int errno;  /**< Variable to store error codes */

/* Error code definitions */
#define EDOM   33 /**< Domain error in math functions */
#define ERANGE 34 /**< Range error in math functions */
#define EILSEQ 42 /**< Illegal byte sequence */
#define ENOMEM 12 /**< Out of memory */
#define EINVAL 22 /**< Invalid argument */

#endif /* _ERRNO_H */
