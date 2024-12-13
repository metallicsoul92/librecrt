#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_DIR_ENTRY_H
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_DIR_ENTRY_H

#include "../../../crt/include/stdint.h"

/* Ext4 Directory Entry Structure */
typedef struct {
    uint32_t inode;         /* Inode number */
    uint16_t rec_len;       /* Length of this record */
    uint8_t  name_len;      /* Length of the file name */
    uint8_t  file_type;     /* Type of the file */
    char     name[255];     /* File name (up to 255 characters) */
} ext4_dir_entry_t;

/* Function Prototypes */
int ext4_read_dir_entry(uint16_t io_base, uint8_t drive, uint32_t block, ext4_dir_entry_t* entry);
int ext4_write_dir_entry(uint16_t io_base, uint8_t drive, uint32_t block, const ext4_dir_entry_t* entry);


#endif
