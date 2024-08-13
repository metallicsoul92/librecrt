/* arch/x86/stdarg.h */

#ifndef _X86_STDARG_H
#define _X86_STDARG_H

typedef char* va_list;

#define _VA_ALIGN(type) (((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define va_start(ap, last) (ap = (va_list)&last + _VA_ALIGN(last))
#define va_end(ap)         (ap = (va_list)0)
#define va_arg(ap, type)   (*(type*)((ap += _VA_ALIGN(type)) - _VA_ALIGN(type)))
#define va_copy(dest, src) (dest = src)

#endif /* _X86_STDARG_H */
