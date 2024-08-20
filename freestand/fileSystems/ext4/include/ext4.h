#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_H
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_H

#include "ext4_superblock.h"
#include "ext4_inode.h"
#include "ext4_group_desc.h"
#include "ext4_dir_entry.h"
#include "../../io/include/ide.h"  // Include the IDE interface

/* Ext4 Filesystem Context */
typedef struct {
    uint16_t io_base;
    uint8_t drive;
    ext4_superblock_t superblock;
} ext4_fs_t;

/* Filesystem API */

/**
 * Initialize the Ext4 filesystem on the specified drive.
 * @param fs The filesystem context to initialize.
 * @param io_base The I/O base address of the IDE controller.
 * @param drive The drive number (0x80 for primary master).
 * @return 0 on success, -1 on failure.
 */
int ext4_initialize(ext4_fs_t *fs, uint16_t io_base, uint8_t drive);

/**
 * Read a file from the Ext4 filesystem.
 * @param fs The filesystem context.
 * @param path The file path to read.
 * @param buffer The buffer to read the file data into.
 * @param size The size of the buffer.
 * @return The number of bytes read, or -1 on failure.
 */
int ext4_read_file(ext4_fs_t *fs, const char *path, void *buffer, size_t size);

/**
 * Write a file to the Ext4 filesystem.
 * @param fs The filesystem context.
 * @param path The file path to write.
 * @param buffer The buffer containing the data to write.
 * @param size The number of bytes to write.
 * @return The number of bytes written, or -1 on failure.
 */
int ext4_write_file(ext4_fs_t *fs, const char *path, const void *buffer, size_t size);

/**
 * Create a directory in the Ext4 filesystem.
 * @param fs The filesystem context.
 * @param path The directory path to create.
 * @return 0 on success, -1 on failure.
 */
int ext4_create_directory(ext4_fs_t *fs, const char *path);

/**
 * List the contents of a directory in the Ext4 filesystem.
 * @param fs The filesystem context.
 * @param path The directory path to list.
 * @param buffer The buffer to store directory entries.
 * @param size The size of the buffer.
 * @return The number of entries read, or -1 on failure.
 */
int ext4_list_directory(ext4_fs_t *fs, const char *path, void *buffer, size_t size);

#endif /* EXT4_H */
