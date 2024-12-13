/* posix/src/endian.c */

#include "../include/endian.h"

/* Host to big-endian conversion */
uint16_t htobe16(uint16_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_16(x);
#else
    return x;
#endif
}

uint32_t htobe32(uint32_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_32(x);
#else
    return x;
#endif
}

uint64_t htobe64(uint64_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_64(x);
#else
    return x;
#endif
}

/* Host to little-endian conversion */
uint16_t htole16(uint16_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_16(x);
#else
    return x;
#endif
}

uint32_t htole32(uint32_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_32(x);
#else
    return x;
#endif
}

uint64_t htole64(uint64_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_64(x);
#else
    return x;
#endif
}

/* Big-endian to host conversion */
uint16_t be16toh(uint16_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_16(x);
#else
    return x;
#endif
}

uint32_t be32toh(uint32_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_32(x);
#else
    return x;
#endif
}

uint64_t be64toh(uint64_t x) {
#if BYTE_ORDER == LITTLE_ENDIAN
    return __bswap_64(x);
#else
    return x;
#endif
}

/* Little-endian to host conversion */
uint16_t le16toh(uint16_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_16(x);
#else
    return x;
#endif
}

uint32_t le32toh(uint32_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_32(x);
#else
    return x;
#endif
}

uint64_t le64toh(uint64_t x) {
#if BYTE_ORDER == BIG_ENDIAN
    return __bswap_64(x);
#else
    return x;
#endif
}
