/* string.h */

#ifndef _STRING_H
#define _STRING_H

#ifndef __HAS_STDDEF
#define __HAS_STDDEF
#include "stddef.h"
#endif

/**
 * @brief Declares functions for manipulating C strings and memory blocks.
 *
 * This header provides prototypes for functions such as `memcpy`, `memmove`, `memset`, `strlen`, and others.
 */

/* Memory manipulation functions */
void *memcpy(void *dest, const void *src, size_t n); /**< Copies n bytes from src to dest */
void *memmove(void *dest, const void *src, size_t n); /**< Copies n bytes from src to dest, handling overlap */
void *memset(void *s, int c, size_t n); /**< Fills the first n bytes of s with the byte value c */
int memcmp(const void *s1, const void *s2, size_t n); /**< Compares the first n bytes of s1 and s2 */

/* String manipulation functions */
size_t strlen(const char *s); /**< Returns the length of the string s */
char *strcpy(char *dest, const char *src); /**< Copies the string src to dest */
char *strncpy(char *dest, const char *src, size_t n); /**< Copies up to n characters from src to dest */
int strcmp(const char *s1, const char *s2); /**< Compares the strings s1 and s2 */
int strncmp(const char *s1, const char *s2, size_t n); /**< Compares up to n characters of the strings s1 and s2 */
char *strcat(char *dest, const char *src); /**< Appends the string src to dest */
char *strncat(char *dest, const char *src, size_t n); /**< Appends up to n characters of src to dest */

#endif /* _STRING_H */
