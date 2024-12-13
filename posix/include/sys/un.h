#ifndef SYS_UN_H
#define SYS_UN_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines structures for UNIX domain socket addresses.
 *
 * This header provides the `sockaddr_un` structure, which is used to specify addresses for UNIX domain sockets.
 */

/**
 * @brief Structure representing a UNIX domain socket address.
 *
 * This structure holds the address family and the path to the socket.
 */
struct sockaddr_un {
    sa_family_t sun_family;  /**< Address family */
    char sun_path[108];      /**< Path to the socket */
};

#endif // SYS_UN_H
