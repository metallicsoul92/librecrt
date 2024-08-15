/* float.h */

#ifndef _FLOAT_H
#define _FLOAT_H

/**
 * @brief Defines constants for floating-point arithmetic.
 *
 * This header includes architecture-specific floating-point limits and properties.
 */

#if defined(__x86__)
    #include "../arch/x86/float.h"
#elif defined(__x64__)
    #include "../arch/x64/float.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _FLOAT_H */
