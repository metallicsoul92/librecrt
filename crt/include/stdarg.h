/* stdarg.h */

#ifndef _STDARG_H
#define _STDARG_H

#if defined(__x86__)
    #include "../arch/x86/stdarg.h"
#elif defined(__x64__)
    #include "../arch/x64/stdarg.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _STDARG_H */
