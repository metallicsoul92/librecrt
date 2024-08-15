#ifndef SYS_IOCTL_H
#define SYS_IOCTL_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Provides the ioctl function for device-specific input/output operations.
 *
 * The ioctl function is used to manipulate the underlying device parameters of special files.
 */

int ioctl(int fd, unsigned long request, ...);  /**< Performs a control operation on a device */

#endif // SYS_IOCTL_H
