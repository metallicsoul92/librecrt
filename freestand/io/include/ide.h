#ifndef IDE_H
#define IDE_H

#include "../../../crt/include/stdint.h"
#include "../../cpu/include/portio.h"  // Include port I/O functions

/* IDE Base I/O Ports */
#define IDE_PRIMARY_IO_BASE  0x1F0
#define IDE_PRIMARY_CTRL_BASE 0x3F6

/* IDE Commands */
#define IDE_CMD_READ_SECTORS  0x20
#define IDE_CMD_WRITE_SECTORS 0x30

/* Function Prototypes */
void ide_initialize(uint16_t io_base);
int ide_read_sectors(uint16_t io_base, uint8_t drive, uint32_t lba, uint8_t sector_count, void* buffer);
int ide_write_sectors(uint16_t io_base, uint8_t drive, uint32_t lba, uint8_t sector_count, const void* buffer);

#endif /* IDE_H */
