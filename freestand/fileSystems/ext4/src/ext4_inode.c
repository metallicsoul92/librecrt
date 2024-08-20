/* freestand/filesystems/ext4/src/ext4_inode.c */

#include "../include/ext4_inode.h"
#include "../../../crt/include/string.h"  // For memset, memcpy

/* Reads an inode from the disk */
int ext4_read_inode(uint16_t io_base, uint8_t drive, uint32_t inode_number, ext4_inode_t* inode) {
    if (!inode) return -1;

    // Calculate the block and offset within the block where the inode resides
    uint32_t block_group = (inode_number - 1) / 8192;  // Typically 8192 inodes per group
    uint32_t index_within_group = (inode_number - 1) % 8192;
    uint32_t block_within_group = index_within_group / (512 / sizeof(ext4_inode_t));  // Assuming 512 bytes per block
    uint32_t offset_within_block = index_within_group % (512 / sizeof(ext4_inode_t));

    // Calculate the LBA for the block
    uint32_t lba = /* LBA calculation based on block group and block_within_group */;

    uint8_t buffer[512];  // Buffer to read the block
    if (ide_read_sectors(io_base, drive, lba, 1, buffer) != 0) {
        return -1;
    }

    // Copy the inode from the block buffer
    memcpy(inode, &buffer[offset_within_block * sizeof(ext4_inode_t)], sizeof(ext4_inode_t));

    return 0;
}

/* Writes an inode to the disk */
int ext4_write_inode(uint16_t io_base, uint8_t drive, uint32_t inode_number, const ext4_inode_t* inode) {
    if (!inode) return -1;

    // Calculate the block and offset within the block where the inode resides
    uint32_t block_group = (inode_number - 1) / 8192;  // Typically 8192 inodes per group
    uint32_t index_within_group = (inode_number - 1) % 8192;
    uint32_t block_within_group = index_within_group / (512 / sizeof(ext4_inode_t));  // Assuming 512 bytes per block
    uint32_t offset_within_block = index_within_group % (512 / sizeof(ext4_inode_t));

    // Calculate the LBA for the block
    uint32_t lba = /* LBA calculation based on block group and block_within_group */;

    uint8_t buffer[512];  // Buffer to read the block
    if (ide_read_sectors(io_base, drive, lba, 1, buffer) != 0) {
        return -1;
    }

    // Copy the inode into the block buffer
    memcpy(&buffer[offset_within_block * sizeof(ext4_inode_t)], inode, sizeof(ext4_inode_t));

    // Write the modified block back to the disk
    return ide_write_sectors(io_base, drive, lba, 1, buffer);
}
