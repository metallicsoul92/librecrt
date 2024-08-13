/* arch/x64/stddef.h */

#ifndef _X64_STDDEF_H
#define _X64_STDDEF_H

typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef int wchar_t;

/* Define NULL as a null pointer constant */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(type, member) ((size_t) &(((type *)0)->member))

#endif /* _X64_STDDEF_H */
