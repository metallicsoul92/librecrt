/* freestanding/filesystems/ext4/src/ext4_superblock.c */

#include "../include/ext4_superblock.h"

/* Reads the superblock from the disk */
int ext4_read_superblock(uint16_t io_base, uint8_t drive, ext4_superblock_t* sb) {
    if (!sb) return -1;

    // The superblock is typically located at LBA 2 (block 2)
    return ide_read_sectors(io_base, drive, 2, 1, sb);
}

/* Writes the superblock to the disk */
int ext4_write_superblock(uint16_t io_base, uint8_t drive, const ext4_superblock_t* sb) {
    if (!sb) return -1;

    // The superblock is typically located at LBA 2 (block 2)
    return ide_write_sectors(io_base, drive, 2, 1, sb);
}
