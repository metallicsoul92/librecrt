/* math.h */

#ifndef _MATH_H
#define _MATH_H

/**
 * @brief Provides mathematical constants and function prototypes.
 *
 * This header defines common mathematical constants and declares function prototypes
 * for standard mathematical operations. These operations include basic arithmetic,
 * trigonometry, exponentiation, and logarithmic calculations.
 */

/* Mathematical constants */

/**
 * @brief The base of natural logarithms.
 */
#define M_E        2.71828182845904523536   /**< Base of natural logarithms (e) */

/**
 * @brief The logarithm base 2 of e.
 */
#define M_LOG2E    1.44269504088896340736   /**< log_2(e) */

/**
 * @brief The logarithm base 10 of e.
 */
#define M_LOG10E   0.434294481903251827651  /**< log_10(e) */

/**
 * @brief The natural logarithm of 2.
 */
#define M_LN2      0.693147180559945309417  /**< ln(2) */

/**
 * @brief The natural logarithm of 10.
 */
#define M_LN10     2.30258509299404568402   /**< ln(10) */

/**
 * @brief The value of pi.
 */
#define M_PI       3.14159265358979323846   /**< pi (π) */

/**
 * @brief pi divided by 2.
 */
#define M_PI_2     1.57079632679489661923   /**< pi/2 */

/**
 * @brief pi divided by 4.
 */
#define M_PI_4     0.785398163397448309616  /**< pi/4 */

/**
 * @brief 1 divided by pi.
 */
#define M_1_PI     0.318309886183790671538  /**< 1/pi */

/**
 * @brief 2 divided by pi.
 */
#define M_2_PI     0.636619772367581343076  /**< 2/pi */

/**
 * @brief 2 divided by the square root of pi.
 */
#define M_2_SQRTPI 1.12837916709551257390   /**< 2/sqrt(pi) */

/**
 * @brief The square root of 2.
 */
#define M_SQRT2    1.41421356237309504880   /**< sqrt(2) */

/**
 * @brief The square root of 1/2.
 */
#define M_SQRT1_2  0.707106781186547524401  /**< sqrt(1/2) */


/* Function prototypes for mathematical operations */

/**
 * @brief Computes the square root of a number.
 *
 * @param x The value whose square root is to be computed.
 * @return The square root of x.
 */
double sqrt(double x);

/**
 * @brief Computes the sine of an angle (in radians).
 *
 * @param x The angle in radians.
 * @return The sine of the angle.
 */
double sin(double x);

/**
 * @brief Computes the cosine of an angle (in radians).
 *
 * @param x The angle in radians.
 * @return The cosine of the angle.
 */
double cos(double x);

/**
 * @brief Computes the tangent of an angle (in radians).
 *
 * @param x The angle in radians.
 * @return The tangent of the angle.
 */
double tan(double x);

/**
 * @brief Computes the absolute value of a floating-point number.
 *
 * @param x The value whose absolute value is to be computed.
 * @return The absolute value of x.
 */
double fabs(double x);

/**
 * @brief Computes the value of a number raised to a power.
 *
 * @param base The base value.
 * @param exp The exponent value.
 * @return The result of raising base to the power exp.
 */
double pow(double base, double exp);

/**
 * @brief Computes the base-e exponential of a number.
 *
 * @param x The value whose exponential is to be computed.
 * @return The exponential of x.
 */
double exp(double x);

/**
 * @brief Computes the natural logarithm of a number.
 *
 * @param x The value whose logarithm is to be computed.
 * @return The natural logarithm of x.
 */
double log(double x);

/**
 * @brief Computes the base-10 logarithm of a number.
 *
 * @param x The value whose logarithm is to be computed.
 * @return The base-10 logarithm of x.
 */
double log10(double x);

/**
 * @brief Computes the smallest integer value not less than x.
 *
 * @param x The value to be rounded up.
 * @return The smallest integer value not less than x.
 */
double ceil(double x);

/**
 * @brief Computes the largest integer value not greater than x.
 *
 * @param x The value to be rounded down.
 * @return The largest integer value not greater than x.
 */
double floor(double x);

#endif /* _MATH_H */
