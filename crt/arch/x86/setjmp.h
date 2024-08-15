#ifndef _X86_SETJMP_H
#define _X86_SETJMP_H

/**
 * @brief Provides declarations for functions and macros related to non-local jumps.
 *
 * This header provides the structure and functions for saving and restoring
 * execution context, typically used for error handling and exception handling.
 */

typedef struct {
    long __jmpbuf[6]; /**< Buffer for saving the CPU registers (specific to x86) */
} jmp_buf;

/**
 * @brief Saves the current execution context (setjmp) to be used by longjmp.
 *
 * @param env The buffer to store the execution context.
 * @return 0 if returning directly, non-zero if returning via longjmp.
 */
int setjmp(jmp_buf env);

/**
 * @brief Restores a saved execution context, causing the program to return to the point set by setjmp.
 *
 * @param env The buffer containing the saved context.
 * @param val The value to return from setjmp.
 */
void longjmp(jmp_buf env, int val);

#endif /* _X86_SETJMP_H */
