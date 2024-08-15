#ifndef _X64_STDARG_H
#define _X64_STDARG_H

/**
 * @brief Provides macros for handling variable argument lists in functions.
 *
 * This header defines macros that are used to access the arguments passed
 * to a function when the number of arguments is variable.
 */

typedef char* va_list;

#define _INTSIZEOF(n)    ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

/**
 * @brief Initializes `ap` to point to the first variable argument.
 *
 * @param ap The `va_list` variable.
 * @param last The last fixed argument before the variable arguments.
 */
#define va_start(ap, last) (ap = (va_list)&last + _INTSIZEOF(last))

/**
 * @brief Retrieves the next argument in the list.
 *
 * @param ap The `va_list` variable.
 * @param type The type of the argument to retrieve.
 */
#define va_arg(ap, type) (*(type*)((ap += _INTSIZEOF(type)) - _INTSIZEOF(type)))

/**
 * @brief Ends the traversal of the variable arguments.
 *
 * @param ap The `va_list` variable.
 */
#define va_end(ap) (ap = (va_list)0)

/**
 * @brief Copies the state of one `va_list` to another.
 *
 * @param dest The destination `va_list`.
 * @param src The source `va_list`.
 */
#define va_copy(dest, src) (dest = src)

#endif /* _X64_STDARG_H */
