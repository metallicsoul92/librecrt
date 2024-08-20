#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_GROUP_DESC_H
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_GROUP_DESC_H


#include "../../../crt/include/stdint.h"

/* Ext4 Block Group Descriptor Structure */
typedef struct {
    uint32_t bg_block_bitmap_lo;     /* Lower 32 bits of block bitmap block */
    uint32_t bg_inode_bitmap_lo;     /* Lower 32 bits of inode bitmap block */
    uint32_t bg_inode_table_lo;      /* Lower 32 bits of inode table block */
    uint16_t bg_free_blocks_count_lo;/* Lower 16 bits of free blocks count */
    uint16_t bg_free_inodes_count_lo;/* Lower 16 bits of free inodes count */
    uint16_t bg_used_dirs_count_lo;  /* Lower 16 bits of directories count */
    uint16_t bg_flags;               /* Block group flags */
    uint32_t bg_reserved[2];         /* Reserved for future use */
    uint16_t bg_itable_unused_lo;    /* Lower 16 bits of unused inodes */
    uint16_t bg_checksum;            /* Group descriptor checksum */
} ext4_group_desc_t;

/* Function Prototypes */
int ext4_read_group_desc(uint16_t io_base, uint8_t drive, uint32_t group_number, ext4_group_desc_t* desc);
int ext4_write_group_desc(uint16_t io_base, uint8_t drive, uint32_t group_number, const ext4_group_desc_t* desc);


#endif
