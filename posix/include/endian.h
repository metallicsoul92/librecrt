/* posix/include/endian.h */

#ifndef _ENDIAN_H
#define _ENDIAN_H

#include "../../crt/include/stdint.h"

/* Macros for determining the byte order */
#define LITTLE_ENDIAN  1234
#define BIG_ENDIAN     4321
#define PDP_ENDIAN     3412

/* Detect the system's endianness */
#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
    #define BYTE_ORDER BIG_ENDIAN
#elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
    #define BYTE_ORDER LITTLE_ENDIAN
#else
    #error "Unknown endianness"
#endif

/* Byte swapping macros */
#define __bswap_16(x) ((uint16_t)((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))
#define __bswap_32(x) ((uint32_t)((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                                  (((x) & 0xff00) << 8) | (((x) & 0xff) << 24)))
#define __bswap_64(x) ((uint64_t)((((x) >> 56) & 0xff) | (((x) >> 40) & 0xff00) | \
                                  (((x) >> 24) & 0xff0000) | (((x) >> 8) & 0xff000000) | \
                                  (((x) & 0xff000000) << 8) | (((x) & 0xff0000) << 24) | \
                                  (((x) & 0xff00) << 40) | (((x) & 0xff) << 56)))

/* Functions for converting between host and network byte order */
uint16_t htobe16(uint16_t x);
uint32_t htobe32(uint32_t x);
uint64_t htobe64(uint64_t x);

uint16_t htole16(uint16_t x);
uint32_t htole32(uint32_t x);
uint64_t htole64(uint64_t x);

uint16_t be16toh(uint16_t x);
uint32_t be32toh(uint32_t x);
uint64_t be64toh(uint64_t x);

uint16_t le16toh(uint16_t x);
uint32_t le32toh(uint32_t x);
uint64_t le64toh(uint64_t x);

#endif /* _ENDIAN_H */
