#ifndef _X86_STDINT_H
#define _X86_STDINT_H

/**
 * @brief Defines exact-width integer types and the corresponding limits.
 *
 * This header provides typedefs for integer types with specified widths, such as
 * `int8_t`, `int16_t`, `int32_t`, and `int64_t`, along with their unsigned counterparts,
 * specifically for the x86 architecture.
 */

/* Exact-width integer types */
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

/* Limits of exact-width integer types */
#define INT8_MIN   (-128)
#define INT8_MAX   (127)
#define UINT8_MAX  (255)

#define INT16_MIN  (-32768)
#define INT16_MAX  (32767)
#define UINT16_MAX (65535)

#define INT32_MIN  (-2147483648)
#define INT32_MAX  (2147483647)
#define UINT32_MAX (4294967295U)

#define INT64_MIN  (-9223372036854775808LL)
#define INT64_MAX  (9223372036854775807LL)
#define UINT64_MAX (18446744073709551615ULL)

/* Least-width integer types */
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

/* Fastest minimum-width integer types */
typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

/* Integer types capable of holding object pointers */
typedef int intptr_t;
typedef unsigned int uintptr_t;

/* Greatest-width integer types */
typedef int64_t intmax_t;
typedef uint64_t uintmax_t;

#endif /* _X86_STDINT_H */
