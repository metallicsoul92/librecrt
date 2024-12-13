/* ctype.h */

#ifndef _CTYPE_H
#define _CTYPE_H

/**
 * @brief Character classification and conversion functions.
 *
 * These functions are used to test characters and convert between uppercase and lowercase.
 */

int isalnum(int c);   /**< Checks if character is alphanumeric */
int isalpha(int c);   /**< Checks if character is alphabetic */
int isdigit(int c);   /**< Checks if character is a digit */
int isxdigit(int c);  /**< Checks if character is a hexadecimal digit */
int isspace(int c);   /**< Checks if character is a whitespace character */
int isprint(int c);   /**< Checks if character is printable */
int ispunct(int c);   /**< Checks if character is a punctuation character */
int tolower(int c);   /**< Converts uppercase character to lowercase */
int toupper(int c);   /**< Converts lowercase character to uppercase */

#endif /* _CTYPE_H */
