/* stddef.h */

#ifndef _STDDEF_H
#define _STDDEF_H

/**
 * @brief Defines common types and macros used in C programs.
 *
 * This header includes architecture-specific definitions for types like `size_t`, `ptrdiff_t`, and the `NULL` macro.
 */

#if defined(__x86__)
    #include "../arch/x86/stddef.h"
#elif defined(__x64__)
    #include "../arch/x64/stddef.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _STDDEF_H */
