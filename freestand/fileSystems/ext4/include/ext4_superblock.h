#ifndef LIBRECRT_FREESTANDING_FS_EXT4_EXT4_SUPERBLOCK_H_
#define LIBRECRT_FREESTANDING_FS_EXT4_EXT4_SUPERBLOCK_H_

#include "../../../crt/include/stdint.h"  // For uint32_t, uint16_t, etc.

/* Ext4 Superblock Structure */
typedef struct {
    uint32_t s_inodes_count;          /* Total number of inodes */
    uint32_t s_blocks_count_lo;       /* Total number of blocks */
    uint32_t s_r_blocks_count_lo;     /* Number of reserved blocks */
    uint32_t s_free_blocks_count_lo;  /* Number of free blocks */
    uint32_t s_free_inodes_count;     /* Number of free inodes */
    uint32_t s_first_data_block;      /* ID of the first data block */
    uint32_t s_log_block_size;        /* Block size (logarithmic) */
    uint32_t s_log_cluster_size;      /* Cluster size (logarithmic) */
    uint32_t s_blocks_per_group;      /* Number of blocks per group */
    uint32_t s_clusters_per_group;    /* Number of clusters per group */
    uint32_t s_inodes_per_group;      /* Number of inodes per group */
    uint32_t s_mtime;                 /* Last mount time */
    uint32_t s_wtime;                 /* Last write time */
    uint16_t s_mnt_count;             /* Mount count since last check */
    uint16_t s_max_mnt_count;         /* Max mounts before check */
    uint16_t s_magic;                 /* Magic signature */
    uint16_t s_state;                 /* Filesystem state */
    uint16_t s_errors;                /* Behavior when detecting errors */
    uint16_t s_minor_rev_level;       /* Minor revision level */
    uint32_t s_lastcheck;             /* Time of last check */
    uint32_t s_checkinterval;         /* Max time between checks */
    uint32_t s_creator_os;            /* OS that created the filesystem */
    uint32_t s_rev_level;             /* Revision level */
    uint16_t s_def_resuid;            /* Default UID for reserved blocks */
    uint16_t s_def_resgid;            /* Default GID for reserved blocks */

    /* Extended Superblock Fields (for Ext4) */
    uint32_t s_first_ino;             /* First non-reserved inode */
    uint16_t s_inode_size;            /* Size of inode structure */
    uint16_t s_block_group_nr;        /* Block group number of this superblock */
    uint32_t s_feature_compat;        /* Compatible feature set */
    uint32_t s_feature_incompat;      /* Incompatible feature set */
    uint32_t s_feature_ro_compat;     /* Read-only compatible feature set */
    uint8_t  s_uuid[16];              /* 128-bit UUID for volume */
    char     s_volume_name[16];       /* Volume name */
    char     s_last_mounted[64];      /* Directory where last mounted */
    uint32_t s_algorithm_usage_bitmap;/* For compression */
    uint8_t  s_prealloc_blocks;       /* Number of blocks to preallocate */
    uint8_t  s_prealloc_dir_blocks;   /* Number of preallocate blocks for dirs */
    uint16_t s_reserved_gdt_blocks;   /* Number of reserved GDT entries */

    /* Journaling support */
    uint8_t  s_journal_uuid[16];      /* UUID of the journal superblock */
    uint32_t s_journal_inum;          /* Inode number of the journal file */
    uint32_t s_journal_dev;           /* Device number of the journal file */
    uint32_t s_last_orphan;           /* Start of list of inodes to delete */
    uint32_t s_hash_seed[4];          /* HTREE hash seed */
    uint8_t  s_def_hash_version;      /* Default hash version */
    uint8_t  s_jnl_backup_type;
    uint16_t s_desc_size;             /* Size of group descriptor */
    uint32_t s_default_mount_opts;
    uint32_t s_first_meta_bg;         /* First metablock block group */
    uint32_t s_mkfs_time;             /* When the filesystem was created */
    uint32_t s_jnl_blocks[17];        /* Backup of the journal inode */

    /* 64bit support - valid if EXT4_FEATURE_COMPAT_64BIT */
    uint32_t s_blocks_count_hi;       /* Upper 32 bits of blocks count */
    uint32_t s_r_blocks_count_hi;     /* Upper 32 bits of reserved blocks count */
    uint32_t s_free_blocks_count_hi;  /* Upper 32 bits of free blocks count */
    uint16_t s_min_extra_isize;       /* All inodes have at least this much extra bytes */
    uint16_t s_want_extra_isize;      /* New inodes should reserve this much */
    uint32_t s_flags;                 /* Miscellaneous flags */
    uint16_t s_raid_stride;           /* RAID stride */
    uint16_t s_mmp_interval;          /* # seconds to wait in MMP checking */
    uint64_t s_mmp_block;             /* Block for multi-mount protection */
    uint32_t s_raid_stripe_width;     /* Blocks on all data disks (N * stride) */
    uint8_t  s_log_groups_per_flex;   /* FLEX_BG group size */
    uint8_t  s_checksum_type;         /* Metadata checksum algorithm used */
    uint8_t  s_reserved_pad;
    uint16_t s_kbytes_written;        /* Number of kilobytes written */
    uint32_t s_snapshot_inum;         /* Inode number of active snapshot */
    uint32_t s_snapshot_id;           /* Sequential ID of active snapshot */
    uint64_t s_snapshot_r_blocks_count;/* Reserved blocks for active snapshot's future use */
    uint32_t s_snapshot_list;         /* Inodes of all snapshots stored in this fs */
    uint32_t s_error_count;           /* Number of fs errors */
    uint32_t s_first_error_time;      /* First time an error happened */
    uint32_t s_first_error_ino;       /* Inode involved in first error */
    uint64_t s_first_error_block;     /* Block involved in first error */
    uint8_t  s_first_error_func[32];  /* Function where the error happened */
    uint32_t s_first_error_line;      /* Line number where the error happened */
    uint32_t s_last_error_time;       /* Most recent time of an error */
    uint32_t s_last_error_ino;        /* Inode involved in most recent error */
    uint32_t s_last_error_line;       /* Line number where the error happened */
    uint64_t s_last_error_block;      /* Block involved of most recent error */
    uint8_t  s_last_error_func[32];   /* Function where the most recent error happened */
    uint8_t  s_mount_opts[64];
    uint32_t s_usr_quota_inum;        /* Inode number for tracking user quota */
    uint32_t s_grp_quota_inum;        /* Inode number for tracking group quota */
    uint32_t s_overhead_clusters;     /* Overhead clusters */
    uint32_t s_backup_bgs[2];         /* Groups with sparse superblock backups */
    uint8_t  s_encrypt_algos[4];      /* Encryption algorithms in use */
    uint8_t  s_encrypt_pw_salt[16];   /* Salt used for string2key algorithm */
    uint32_t s_lpf_ino;               /* Location of the lost+found inode */
    uint32_t s_prj_quota_inum;        /* Inode for tracking project quota */
    uint32_t s_checksum_seed;         /* Checksum seed */
    uint32_t s_reserved[98];          /* Padding to the end of the block */
    uint32_t s_checksum;              /* Superblock checksum */
} ext4_superblock_t;

/* Function Prototypes */
int ext4_read_superblock(uint16_t io_base, uint8_t drive, ext4_superblock_t* sb);
int ext4_write_superblock(uint16_t io_base, uint8_t drive, const ext4_superblock_t* sb);


#endif
