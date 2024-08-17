/* posix/include/cpio.h */

#ifndef _CPIO_H
#define _CPIO_H

#include "../../crt/include/stdint.h"

/**
 * @brief CPIO header structure.
 *
 * This structure represents the header of a file in a CPIO archive
 * using the "newc" format.
 */
struct cpio_header {
    char c_magic[6];      /**< Magic number field, always "070701" */
    char c_ino[8];        /**< File inode number */
    char c_mode[8];       /**< File mode and permissions */
    char c_uid[8];        /**< File owner's user ID */
    char c_gid[8];        /**< File owner's group ID */
    char c_nlink[8];      /**< Number of links to the file */
    char c_mtime[8];      /**< Modification time */
    char c_filesize[8];   /**< Size of the file in bytes */
    char c_devmajor[8];   /**< Major number of the device */
    char c_devminor[8];   /**< Minor number of the device */
    char c_rdevmajor[8];  /**< Major number of the device if special file */
    char c_rdevminor[8];  /**< Minor number of the device if special file */
    char c_namesize[8];   /**< Length of the filename, including NULL */
    char c_check[8];      /**< Always set to zero in "newc" format */
};

/* Magic numbers for CPIO formats */
#define CPIO_MAGIC        "070707"  /**< "odc" format magic number */
#define CPIO_NEWC_MAGIC   "070701"  /**< "newc" format magic number */
#define CPIO_CRC_MAGIC    "070702"  /**< "crc" format magic number */

/* Maximum filename size in CPIO */
#define CPIO_MAX_NAME     256

/* Special filenames used in CPIO archives */
#define CPIO_TRAILER      "TRAILER!!!"

/* CPIO mode flags */
#define C_ISSOCK 0140000  /**< Socket */
#define C_ISLNK  0120000  /**< Symbolic link */
#define C_ISREG  0100000  /**< Regular file */
#define C_ISBLK  0060000  /**< Block device */
#define C_ISDIR  0040000  /**< Directory */
#define C_ISCHR  0020000  /**< Character device */
#define C_ISFIFO 0010000  /**< FIFO or pipe */

/* Permission bits */
#define C_IRWXU  0000700  /**< Read, write, execute by owner */
#define C_IRUSR  0000400  /**< Read by owner */
#define C_IWUSR  0000200  /**< Write by owner */
#define C_IXUSR  0000100  /**< Execute by owner */
#define C_IRWXG  0000070  /**< Read, write, execute by group */
#define C_IRGRP  0000040  /**< Read by group */
#define C_IWGRP  0000020  /**< Write by group */
#define C_IXGRP  0000010  /**< Execute by group */
#define C_IRWXO  0000007  /**< Read, write, execute by others */
#define C_IROTH  0000004  /**< Read by others */
#define C_IWOTH  0000002  /**< Write by others */
#define C_IXOTH  0000001  /**< Execute by others */

/**
 * @brief Converts a hexadecimal string to an integer.
 *
 * This function reads a hexadecimal string and converts it to
 * an integer value. This is useful for interpreting CPIO headers.
 *
 * @param hex_str The hexadecimal string to convert.
 * @return The integer value of the string.
 */
uint32_t cpio_hex_to_int(const char *hex_str);

/**
 * @brief Reads a CPIO header from a buffer.
 *
 * This function parses the CPIO header from the given buffer.
 *
 * @param buffer The buffer containing the CPIO header data.
 * @return A pointer to the parsed `struct cpio_header`.
 */
struct cpio_header* cpio_parse_header(const char *buffer);

#endif /* _CPIO_H */
