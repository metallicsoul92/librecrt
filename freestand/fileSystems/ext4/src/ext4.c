/* freestanding/filesystems/ext4/src/ext4.c */

#include "../include/ext4.h"
#include "../../../crt/include/string.h"
#include "../../../crt/include/stdlib.h"

/* Initialize the Ext4 filesystem on the specified drive */
int ext4_initialize(ext4_fs_t *fs, uint16_t io_base, uint8_t drive) {
    if (!fs) return -1;

    fs->io_base = io_base;
    fs->drive = drive;

    // Read the superblock
    if (ext4_read_superblock(io_base, drive, &fs->superblock) != 0) {
        return -1;
    }

    // Check the magic number
    if (fs->superblock.s_magic != 0xEF53) {
        return -1;  // Not an Ext4 filesystem
    }

    return 0;
}

/* Read a file from the Ext4 filesystem */
int ext4_read_file(ext4_fs_t *fs, const char *path, void *buffer, size_t size) {
    if (!fs || !path || !buffer) return -1;

    // Locate the inode for the file (simplified: assuming direct lookup)
    ext4_inode_t inode;
    if (ext4_read_inode(fs->io_base, fs->drive, 2 /*root inode*/, &inode) != 0) {
        return -1;
    }

    // For simplicity, assume the file is small and located in a single block
    uint32_t block = inode.i_block[0];
    if (ide_read_sectors(fs->io_base, fs->drive, block, 1, buffer) != 0) {
        return -1;
    }

    return inode.i_size_lo > size ? size : inode.i_size_lo;
}

/* Write a file to the Ext4 filesystem */
int ext4_write_file(ext4_fs_t *fs, const char *path, const void *buffer, size_t size) {
    if (!fs || !path || !buffer) return -1;

    // Locate the inode for the file (simplified: assuming direct lookup)
    ext4_inode_t inode;
    if (ext4_read_inode(fs->io_base, fs->drive, 2 /*root inode*/, &inode) != 0) {
        return -1;
    }

    // For simplicity, assume the file is small and fits in a single block
    uint32_t block = inode.i_block[0];
    if (ide_write_sectors(fs->io_base, fs->drive, block, 1, buffer) != 0) {
        return -1;
    }

    inode.i_size_lo = size;
    if (ext4_write_inode(fs->io_base, fs->drive, 2 /*root inode*/, &inode) != 0) {
        return -1;
    }

    return size;
}

/* Create a directory in the Ext4 filesystem */
int ext4_create_directory(ext4_fs_t *fs, const char *path) {
    if (!fs || !path) return -1;

    // Simplified: Assume creating a directory with default permissions and a new inode
    ext4_inode_t new_inode;
    memset(&new_inode, 0, sizeof(ext4_inode_t));
    new_inode.i_mode = 0x4000;  // Directory
    new_inode.i_links_count = 2;  // Parent and self
    new_inode.i_size_lo = 1024;  // Default directory size

    // Write the inode to the disk
    if (ext4_write_inode(fs->io_base, fs->drive, 3 /*new inode number*/, &new_inode) != 0) {
        return -1;
    }

    return 0;
}

/* List the contents of a directory in the Ext4 filesystem */
int ext4_list_directory(ext4_fs_t *fs, const char *path, void *buffer, size_t size) {
    if (!fs || !path || !buffer) return -1;

    // Locate the inode for the directory (simplified: assuming direct lookup)
    ext4_inode_t inode;
    if (ext4_read_inode(fs->io_base, fs->drive, 2 /*root inode*/, &inode) != 0) {
        return -1;
    }

    // For simplicity, assume the directory is small and located in a single block
    uint32_t block = inode.i_block[0];
    if (ide_read_sectors(fs->io_base, fs->drive, block, 1, buffer) != 0) {
        return -1;
    }

    return size;
}
