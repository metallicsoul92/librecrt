#ifndef _X86_FLOAT_H
#define _X86_FLOAT_H

/**
 * @brief Defines various floating-point constants specific to the x86 architecture.
 *
 * These constants are used to define the properties of floating-point types
 * such as `float`, `double`, and `long double`.
 */

#define FLT_RADIX        2       /**< Base of the exponent representation */
#define FLT_MANT_DIG     24      /**< Number of digits in the mantissa */
#define DBL_MANT_DIG     53      /**< Number of digits in the mantissa for double */
#define LDBL_MANT_DIG    64      /**< Number of digits in the mantissa for long double */

#define FLT_DIG          6       /**< Number of decimal digits of precision */
#define DBL_DIG          15      /**< Number of decimal digits of precision for double */
#define LDBL_DIG         18      /**< Number of decimal digits of precision for long double */

#define FLT_MIN_EXP      (-125)  /**< Minimum exponent value */
#define DBL_MIN_EXP      (-1021) /**< Minimum exponent value for double */
#define LDBL_MIN_EXP     (-16381)/**< Minimum exponent value for long double */

#define FLT_MIN_10_EXP   (-37)   /**< Minimum base 10 exponent value */
#define DBL_MIN_10_EXP   (-307)  /**< Minimum base 10 exponent value for double */
#define LDBL_MIN_10_EXP  (-4931) /**< Minimum base 10 exponent value for long double */

#define FLT_MAX_EXP      128     /**< Maximum exponent value */
#define DBL_MAX_EXP      1024    /**< Maximum exponent value for double */
#define LDBL_MAX_EXP     16384   /**< Maximum exponent value for long double */

#define FLT_MAX_10_EXP   38      /**< Maximum base 10 exponent value */
#define DBL_MAX_10_EXP   308     /**< Maximum base 10 exponent value for double */
#define LDBL_MAX_10_EXP  4932    /**< Maximum base 10 exponent value for long double */

#define FLT_MAX          3.40282347e+38F /**< Maximum finite floating-point value */
#define DBL_MAX          1.7976931348623157e+308 /**< Maximum finite double value */
#define LDBL_MAX         1.189731495357231765e+4932L /**< Maximum finite long double value */

#define FLT_EPSILON      1.19209290e-7F  /**< Difference between 1 and the least value greater than 1 that is representable */
#define DBL_EPSILON      2.2204460492503131e-16 /**< Difference between 1 and the least value greater than 1 that is representable for double */
#define LDBL_EPSILON     1.084202172485504434e-19L /**< Difference between 1 and the least value greater than 1 that is representable for long double */

#define FLT_MIN          1.17549435e-38F  /**< Minimum positive normal value */
#define DBL_MIN          2.2250738585072014e-308 /**< Minimum positive normal value for double */
#define LDBL_MIN         3.36210314311209350626e-4932L /**< Minimum positive normal value for long double */

#define FLT_ROUNDS       1 /**< Rounding mode for floating-point addition: nearest */

#endif /* _X86_FLOAT_H */
