/* freestand/filesystems/ext4/src/ext4_dir_entry.c */

#include "../include/ext4_dir_entry.h"
#include "../../../crt/include/string.h"  // For memset, memcpy, strncpy

/* Reads a directory entry from a block on the disk */
int ext4_read_dir_entry(uint16_t io_base, uint8_t drive, uint32_t block, ext4_dir_entry_t* entry) {
    if (!entry) return -1;

    uint8_t buffer[512];
    if (ide_read_sectors(io_base, drive, block, 1, buffer) != 0) {
        return -1;
    }

    memcpy(entry, buffer, sizeof(ext4_dir_entry_t));
    return 0;
}

/* Writes a directory entry to a block on the disk */
int ext4_write_dir_entry(uint16_t io_base, uint8_t drive, uint32_t block, const ext4_dir_entry_t* entry) {
    if (!entry) return -1;

    uint8_t buffer[512];
    memcpy(buffer, entry, sizeof(ext4_dir_entry_t));

    return ide_write_sectors(io_base, drive, block, 1, buffer);
}
