/* arch/x86/limits.h */

#ifndef _X86_LIMITS_H
#define _X86_LIMITS_H

/* Number of bits in a `char` */
#define CHAR_BIT    8

/* Minimum and maximum values for `signed char` */
#define SCHAR_MIN   (-128)
#define SCHAR_MAX   127

/* Maximum value for `unsigned char` */
#define UCHAR_MAX   255

/* Minimum and maximum values for `char` */
#ifdef __CHAR_UNSIGNED__
    #define CHAR_MIN    0
    #define CHAR_MAX    UCHAR_MAX
#else
    #define CHAR_MIN    SCHAR_MIN
    #define CHAR_MAX    SCHAR_MAX
#endif

/* Minimum and maximum values for `short` */
#define SHRT_MIN    (-32768)
#define SHRT_MAX    32767
#define USHRT_MAX   65535

/* Minimum and maximum values for `int` */
#define INT_MIN     (-2147483648)
#define INT_MAX     2147483647
#define UINT_MAX    4294967295U

/* Minimum and maximum values for `long` */
#define LONG_MIN    (-2147483648L)
#define LONG_MAX    2147483647L
#define ULONG_MAX   4294967295UL

/* Minimum and maximum values for `long long` */
#define LLONG_MIN   (-9223372036854775807LL - 1)
#define LLONG_MAX   9223372036854775807LL
#define ULLONG_MAX  18446744073709551615ULL

/* Minimum and maximum values for `ptrdiff_t` */
#define PTRDIFF_MIN INT_MIN
#define PTRDIFF_MAX INT_MAX

/* Minimum and maximum values for `size_t` */
#define SIZE_MAX    UINT_MAX

/* Minimum and maximum values for `wchar_t` */
#ifdef __WCHAR_UNSIGNED__
    #define WCHAR_MIN   0
    #define WCHAR_MAX   USHRT_MAX
#else
    #define WCHAR_MIN   SHRT_MIN
    #define WCHAR_MAX   SHRT_MAX
#endif

/* Minimum and maximum values for `wint_t` */
#define WINT_MIN    INT_MIN
#define WINT_MAX    INT_MAX

/* Minimum and maximum values for `signed char` bit field */
#define SIG_ATOMIC_MIN INT_MIN
#define SIG_ATOMIC_MAX INT_MAX

/* Minimum and maximum values for `intptr_t` */
#define INTPTR_MIN  INT_MIN
#define INTPTR_MAX  INT_MAX
#define UINTPTR_MAX UINT_MAX

/* Minimum and maximum values for `intmax_t` */
#define INTMAX_MIN  LLONG_MIN
#define INTMAX_MAX  LLONG_MAX
#define UINTMAX_MAX ULLONG_MAX

#endif /* _X86_LIMITS_H */
