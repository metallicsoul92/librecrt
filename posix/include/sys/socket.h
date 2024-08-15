#ifndef SYS_SOCKET_H
#define SYS_SOCKET_H

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines structures and functions for socket operations.
 *
 * This header provides function prototypes for creating and manipulating sockets, which are endpoints for communication.
 */

#define AF_INET 2       /**< IPv4 Internet protocols */
#define SOCK_STREAM 1   /**< Stream socket */

/**
 * @brief Creates an endpoint for communication.
 *
 * @param domain The communication domain (e.g., AF_INET).
 * @param type The socket type (e.g., SOCK_STREAM).
 * @param protocol The protocol to be used.
 * @return A file descriptor for the new socket, or -1 on error.
 */
int socket(int domain, int type, int protocol);

/**
 * @brief Binds a socket to an address.
 *
 * @param sockfd The file descriptor of the socket.
 * @param addr The address to bind to.
 * @param addrlen The size of the address structure.
 * @return 0 on success, or -1 on error.
 */
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/**
 * @brief Listens for connections on a socket.
 *
 * @param sockfd The file descriptor of the socket.
 * @param backlog The maximum length of the queue of pending connections.
 * @return 0 on success, or -1 on error.
 */
int listen(int sockfd, int backlog);

/**
 * @brief Accepts a connection on a socket.
 *
 * @param sockfd The file descriptor of the socket.
 * @param addr The address of the connecting entity.
 * @param addrlen A pointer to the size of the address structure.
 * @return A file descriptor for the accepted socket, or -1 on error.
 */
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif // SYS_SOCKET_H
