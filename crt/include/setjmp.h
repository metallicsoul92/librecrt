/* include/setjmp.h */

#ifndef _SETJMP_H
#define _SETJMP_H

#if defined(__x86__)
    #include "../arch/x86/setjmp.h"
#elif defined(__x64__)
    #include "../arch/x64/setjmp.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _SETJMP_H */
