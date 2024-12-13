/* assert.h */

#ifndef _ASSERT_H
#define _ASSERT_H

#ifndef ASSERT_BUFFER_SIZE
#define ASSERT_BUFFER_SIZE 256 /**< Default buffer size for storing assertion failure messages */
#endif

/**
 * @brief Macro for runtime assertion checking.
 *
 * If the expression evaluates to false, an error message is stored in a buffer,
 * and the program enters an infinite loop. The buffer can be read later using
 * the `readAssertBuffer()` function.
 * The macro is disabled if NDEBUG is defined.
 *
 * @param expr Expression to be evaluated.
 */
#ifdef NDEBUG
    #define assert(expr) ((void)0)
#else
    #define assert(expr) __assert_failed(#expr, __FILE__, __LINE__)
#endif

/**
 * @brief Reads the assertion failure message from the buffer.
 *
 * @return A pointer to the assertion buffer, or NULL if no message is available.
 */
const char* readAssertBuffer(void);

/**
 * @brief Function called when an assertion fails.
 *
 * This function stores the assertion failure message in the buffer and enters
 * an infinite loop to halt the program.
 *
 * @param expr The expression that failed.
 * @param file The source file where the assertion failed.
 * @param line The line number where the assertion failed.
 */
void __assert_failed(const char* expr, const char* file, int line);

#endif /* _ASSERT_H */
