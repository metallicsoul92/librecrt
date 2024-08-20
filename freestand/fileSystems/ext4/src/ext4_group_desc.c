/* freestand/filesystems/ext4/src/ext4_group_desc.c */

#include "../include/ext4_group_desc.h"
#include "../../../crt/include/string.h"  // For memset, memcpy

/* Reads a block group descriptor from the disk */
int ext4_read_group_desc(uint16_t io_base, uint8_t drive, uint32_t group_number, ext4_group_desc_t* desc) {
    if (!desc) return -1;

    // Group descriptor is typically located after the superblock
    uint32_t lba = 2 + group_number;  // Simplified; adjust for your layout

    uint8_t buffer[512];
    if (ide_read_sectors(io_base, drive, lba, 1, buffer) != 0) {
        return -1;
    }

    memcpy(desc, buffer, sizeof(ext4_group_desc_t));
    return 0;
}

/* Writes a block group descriptor to the disk */
int ext4_write_group_desc(uint16_t io_base, uint8_t drive, uint32_t group_number, const ext4_group_desc_t* desc) {
    if (!desc) return -1;

    // Group descriptor is typically located after the superblock
    uint32_t lba = 2 + group_number;  // Simplified; adjust for your layout

    uint8_t buffer[512];
    memcpy(buffer, desc, sizeof(ext4_group_desc_t));

    return ide_write_sectors(io_base, drive, lba, 1, buffer);
}
