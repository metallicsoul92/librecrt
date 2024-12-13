#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_INODE_BITMAP_H
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_INODE_BITMAP_H

#include "../../../crt/include/stdint.h"

/* Ext4 Inode Bitmap Structure */
typedef struct {
    uint8_t *bitmap;      /* Pointer to the bitmap */
    uint32_t size;        /* Size of the bitmap in bytes */
} ext4_inode_bitmap_t;

/* Function prototypes */
void ext4_init_inode_bitmap(ext4_inode_bitmap_t *bitmap, uint32_t size);
int ext4_read_inode_bitmap(uint32_t block_number, ext4_inode_bitmap_t *bitmap);
int ext4_write_inode_bitmap(uint32_t block_number, const ext4_inode_bitmap_t *bitmap);

#endif /* EXT4_INODE_BITMAP_H */
