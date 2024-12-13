#ifndef _X86_STDDEF_H
#define _X86_STDDEF_H

/**
 * @brief Defines various types and macros commonly used in C programs.
 *
 * This header includes definitions for types like `size_t`, `ptrdiff_t`, and
 * the `NULL` pointer macro, specifically tailored for the x86 architecture.
 */

/* Define the NULL pointer value */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Define the size_t type, which represents sizes of objects */
typedef unsigned int size_t;

/* Define the ptrdiff_t type, which represents pointer differences */
typedef int ptrdiff_t;

/* Define the wchar_t type, which is used for wide characters */
typedef int wchar_t;

/* Offset of a structure member */
#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif /* _X86_STDDEF_H */
