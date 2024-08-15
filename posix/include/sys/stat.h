#ifndef SYS_STAT_H
#define SYS_STAT_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

/**
 * @brief Defines structures and macros for file status information.
 *
 * This header provides macros for file types and permissions, as well as function prototypes for obtaining file status information.
 */

/* File type macros */
#define S_IFMT  0170000  /**< Type of file */
#define S_IFDIR 0040000  /**< Directory */
#define S_IFCHR 0020000  /**< Character special */
#define S_IFBLK 0060000  /**< Block special */
#define S_IFREG 0100000  /**< Regular file */

/* Permission macros */
#define S_IRUSR 00400  /**< Read permission, owner */
#define S_IWUSR 00200  /**< Write permission, owner */
#define S_IXUSR 00100  /**< Execute/search permission, owner */

/**
 * @brief Structure representing file status.
 *
 * This structure holds information about a file, such as its type, size, and modification times.
 */
struct stat {
    mode_t st_mode;     /**< Protection */
    off_t st_size;      /**< Total size, in bytes */
    time_t st_atime;    /**< Time of last access */
    time_t st_mtime;    /**< Time of last modification */
    time_t st_ctime;    /**< Time of last status change */
};

int stat(const char *path, struct stat *buf); /**< Retrieves file status information */
int fstat(int fd, struct stat *buf); /**< Retrieves file status information by file descriptor */
int mkdir(const char *pathname, mode_t mode); /**< Creates a directory */

#endif // SYS_STAT_H
