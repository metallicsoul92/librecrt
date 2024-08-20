/* freestanding/io/src/ide.c */

#include "../include/ide.h"

/* Initialize IDE interface */
void ide_initialize(uint16_t io_base) {
    /* Typically, you might want to reset the IDE controller here,
     * or initialize any buffers or structures required for communication.
     * This is a placeholder as IDE does not usually require explicit init.
     */
}

/* Read sectors from disk using PIO mode */
int ide_read_sectors(uint16_t io_base, uint8_t drive, uint32_t lba, uint8_t sector_count, void* buffer) {
    if (sector_count == 0) return -1;

    outb(io_base + 6, 0xE0 | (drive << 4) | ((lba >> 24) & 0x0F));  // Drive/Head Register
    outb(io_base + 1, 0x00);  // No DMA
    outb(io_base + 2, sector_count);  // Sector Count
    outb(io_base + 3, (uint8_t)(lba & 0xFF));  // LBA Low Byte
    outb(io_base + 4, (uint8_t)((lba >> 8) & 0xFF));  // LBA Mid Byte
    outb(io_base + 5, (uint8_t)((lba >> 16) & 0xFF));  // LBA High Byte
    outb(io_base + 7, IDE_CMD_READ_SECTORS);  // Command: Read Sectors

    // Wait for the drive to be ready
    while (!(inb(io_base + 7) & 0x08));  // Wait for DRQ

    uint16_t* buffer16 = (uint16_t*)buffer;
    for (int i = 0; i < 256 * sector_count; i++) {
        buffer16[i] = inw(io_base);  // Read data from the data port
    }

    return 0;
}

/* Write sectors to disk using PIO mode */
int ide_write_sectors(uint16_t io_base, uint8_t drive, uint32_t lba, uint8_t sector_count, const void* buffer) {
    if (sector_count == 0) return -1;

    outb(io_base + 6, 0xE0 | (drive << 4) | ((lba >> 24) & 0x0F));  // Drive/Head Register
    outb(io_base + 1, 0x00);  // No DMA
    outb(io_base + 2, sector_count);  // Sector Count
    outb(io_base + 3, (uint8_t)(lba & 0xFF));  // LBA Low Byte
    outb(io_base + 4, (uint8_t)((lba >> 8) & 0xFF));  // LBA Mid Byte
    outb(io_base + 5, (uint8_t)((lba >> 16) & 0xFF));  // LBA High Byte
    outb(io_base + 7, IDE_CMD_WRITE_SECTORS);  // Command: Write Sectors

    // Wait for the drive to be ready
    while (!(inb(io_base + 7) & 0x08));  // Wait for DRQ

    const uint16_t* buffer16 = (const uint16_t*)buffer;
    for (int i = 0; i < 256 * sector_count; i++) {
        outw(io_base, buffer16[i]);  // Write data to the data port
    }

    return 0;
}
