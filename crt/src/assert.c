/* assert.c */

#include "../include/assert.h"
#include "../include/stddef.h"

/* Static buffer to store the assertion failure message */
static char assert_buffer[ASSERT_BUFFER_SIZE];
static int assert_buffer_written = 0;

void __assert_failed(const char* expr, const char* file, int line) {
    /* Store the assertion message in the buffer */
    assert_buffer_written = snprintf(assert_buffer, ASSERT_BUFFER_SIZE,
        "Assertion failed: %s, file %s, line %d\n", expr, file, line);

    /* Infinite loop to halt execution on assertion failure */
    while (1) {
        /* Optionally, you could add some platform-specific code here
           to signal an error, like flashing an LED on embedded systems
           or triggering a debugger breakpoint. */
    }
}

const char* readAssertBuffer(void) {
    if (assert_buffer_written > 0) {
        return assert_buffer;
    } else {
        return NULL;
    }
}
