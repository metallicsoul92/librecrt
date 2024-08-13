/* errno.h */

#ifndef _ERRNO_H
#define _ERRNO_H

extern int errno;

#define EDOM   33 /* Domain error in math functions */
#define ERANGE 34 /* Range error in math functions */
#define EILSEQ 42 /* Illegal byte sequence */
#define ENOMEM 12 /* Out of memory */
#define EINVAL 22 /* Invalid argument */

#endif /* _ERRNO_H */
