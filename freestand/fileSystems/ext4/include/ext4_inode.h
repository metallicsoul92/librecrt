#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_INODE_H
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_INODE_H

#include "../../../crt/include/stdint.h"

/* Ext4 Inode Structure */
typedef struct {
    uint16_t i_mode;        /* File mode */
    uint16_t i_uid;         /* Low 16 bits of Owner UID */
    uint32_t i_size_lo;     /* Size in bytes (lower 32 bits) */
    uint32_t i_atime;       /* Access time */
    uint32_t i_ctime;       /* Creation time */
    uint32_t i_mtime;       /* Modification time */
    uint32_t i_dtime;       /* Deletion time */
    uint16_t i_gid;         /* Low 16 bits of Group ID */
    uint16_t i_links_count; /* Links count */
    uint32_t i_blocks_lo;   /* Blocks count (lower 32 bits) */
    uint32_t i_flags;       /* File flags */
    uint32_t i_osd1;        /* OS-dependent value */
    uint32_t i_block[15];   /* Pointers to blocks */
    uint32_t i_generation;  /* File version (for NFS) */
    uint32_t i_file_acl_lo; /* File ACL (lower 32 bits) */
    uint32_t i_size_hi;     /* Size in bytes (upper 32 bits) */
    uint32_t i_obso_faddr;  /* Obsolete fragment address */
    uint16_t i_osd2[3];     /* OS-dependent value */
    uint16_t i_extra_isize; /* Size of this inode */
    uint16_t i_checksum_hi; /* High 16 bits of checksum */
    uint16_t i_reserved;    /* Reserved for future use */
} ext4_inode_t;

/* Function Prototypes */
int ext4_read_inode(uint16_t io_base, uint8_t drive, uint32_t inode_number, ext4_inode_t* inode);
int ext4_write_inode(uint16_t io_base, uint8_t drive, uint32_t inode_number, const ext4_inode_t* inode);



#endif /* EXT4_INODE_H */
