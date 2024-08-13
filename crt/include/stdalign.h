/* stdalign.h */

#ifndef _STDALIGN_H
#define _STDALIGN_H

#if defined(__x86__)
    #include "../arch/x86/stdalign.h"
#elif defined(__x64__)
    #include "../arch/x64/stdalign.h"
#else
    #error "Unsupported architecture. Please define either __x86__ or __x64__."
#endif

#endif /* _STDALIGN_H */
