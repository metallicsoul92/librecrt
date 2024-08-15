#ifndef _X64_STDDEF_H
#define _X64_STDDEF_H

/**
 * @brief Defines various types and macros commonly used in C programs.
 *
 * This header includes definitions for types like `size_t`, `ptrdiff_t`, and
 * the `NULL` pointer macro.
 */

/* Define the NULL pointer value */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Define the size_t type, which represents sizes of objects */
typedef unsigned long size_t;

/* Define the ptrdiff_t type, which represents pointer differences */
typedef long ptrdiff_t;

/* Define the wchar_t type, which is used for wide characters */
typedef int wchar_t;

/* Offset of a structure member */
#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif /* _X64_STDDEF_H */
