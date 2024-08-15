/* stdint.h */

#ifndef _STDINT_H
#define _STDINT_H

/**
 * @brief Defines exact-width integer types and their corresponding limits.
 *
 * This header includes architecture-specific definitions for integer types with specified widths, such as `int8_t`, `int16_t`, and `int32_t`.
 */

#if defined(__x86__)
    #include "../arch/x86/stdint.h"
#elif defined(__x64__)
    #include "../arch/x64/stdint.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _STDINT_H */
