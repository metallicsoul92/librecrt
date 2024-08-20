/* freestand/filesystems/ext4/src/ext4_bitmap.c */

#include "../include/ext4_bitmap.h"
#include "../../../crt/include/stdlib.h"  // For malloc, free
#include "../../../crt/include/string.h"  // For memset, memcpy

/* Function to initialize a bitmap */
void ext4_init_bitmap(ext4_bitmap_t *bitmap, uint32_t size) {
    bitmap->bitmap = malloc(size);
    bitmap->size = size;
    memset(bitmap->bitmap, 0, size);
}

/* Function to read a bitmap from disk (simulated) */
int ext4_read_bitmap(uint32_t block_number, ext4_bitmap_t *bitmap) {
    // This would involve reading the bitmap from a block on disk
    // For this example, we'll simulate the read
    ext4_init_bitmap(bitmap, 4096);  // 4096 bytes for a block bitmap
    return 0;
}

/* Function to write a bitmap to disk (simulated) */
int ext4_write_bitmap(uint32_t block_number, const ext4_bitmap_t *bitmap) {
    // This would involve writing the bitmap to a block on disk
    // For this example, we'll simulate the write
    return 0;
}

/* Function to free a bitmap */
void ext4_free_bitmap(ext4_bitmap_t *bitmap) {
    if (bitmap->bitmap) {
        free(bitmap->bitmap);
        bitmap->bitmap = NULL;
    }
}
