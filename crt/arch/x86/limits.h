#ifndef _X86_LIMITS_H
#define _X86_LIMITS_H

/**
 * @brief Defines limits of fundamental data types for the x86 architecture.
 *
 * These limits include the minimum and maximum values that various types can hold,
 * such as `char`, `int`, `long`, etc.
 */

#define CHAR_BIT    8               /**< Number of bits in a `char` */
#define SCHAR_MIN   (-128)           /**< Minimum value for a signed `char` */
#define SCHAR_MAX   127              /**< Maximum value for a signed `char` */
#define UCHAR_MAX   255              /**< Maximum value for an unsigned `char` */
#define CHAR_MIN    SCHAR_MIN        /**< Minimum value for `char` */
#define CHAR_MAX    SCHAR_MAX        /**< Maximum value for `char` */
#define SHRT_MIN    (-32768)         /**< Minimum value for a `short` */
#define SHRT_MAX    32767            /**< Maximum value for a `short` */
#define USHRT_MAX   65535            /**< Maximum value for an unsigned `short` */
#define INT_MIN     (-2147483648)    /**< Minimum value for an `int` */
#define INT_MAX     2147483647       /**< Maximum value for an `int` */
#define UINT_MAX    4294967295U      /**< Maximum value for an unsigned `int` */
#define LONG_MIN    (-2147483648L)   /**< Minimum value for a `long` */
#define LONG_MAX    2147483647L      /**< Maximum value for a `long` */
#define ULONG_MAX   4294967295UL     /**< Maximum value for an unsigned `long` */
#define LLONG_MIN   (-9223372036854775808LL) /**< Minimum value for a `long long` */
#define LLONG_MAX   9223372036854775807LL  /**< Maximum value for a `long long` */
#define ULLONG_MAX  18446744073709551615ULL /**< Maximum value for an unsigned `long long` */

#endif /* _X86_LIMITS_H */
