/* arch/x86/stddef.h */

#ifndef _X86_STDDEF_H
#define _X86_STDDEF_H

typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef int wchar_t;

/* Define NULL as a null pointer constant */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(type, member) ((size_t) &(((type *)0)->member))

#endif /* _X86_STDDEF_H */
