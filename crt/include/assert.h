/* assert.h */

#ifndef _ASSERT_H
#define _ASSERT_H

#include <stdio.h>

#ifdef NDEBUG
    #define assert(expr) ((void)0)
#else
    #define assert(expr) \
        if (!(expr)) { \
            printf("Assertion failed: %s, file %s, line %d\n", #expr, __FILE__, __LINE__); \
            while(1); \
        }
#endif

#endif /* _ASSERT_H */
