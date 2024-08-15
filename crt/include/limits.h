/* limits.h */

#ifndef _LIMITS_H
#define _LIMITS_H

/**
 * @brief Defines the limits of fundamental data types.
 *
 * This header includes architecture-specific limits for integral types, such as `char`, `int`, and `long`.
 */

/* Detect architecture and include the corresponding limits.h */
#if defined(__x86__)
    #include "../arch/x86/limits.h"
#elif defined(__x64__)
    #include "../arch/x64/limits.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _LIMITS_H */
