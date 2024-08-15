#ifndef _X64_STDALIGN_H
#define _X64_STDALIGN_H

/**
 * @brief Defines macros for specifying alignment of objects in memory.
 *
 * These macros are used to control the alignment of variables and types in memory.
 * Proper alignment can improve performance and ensure compatibility with hardware.
 */

#define alignas _Alignas  /**< Macro for specifying alignment of a type or variable */
#define alignof _Alignof  /**< Macro for obtaining the alignment of a type */

#endif /* _X64_STDALIGN_H */
