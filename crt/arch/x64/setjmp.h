/* arch/x64/setjmp.h */

#ifndef _X64_SETJMP_H
#define _X64_SETJMP_H

typedef struct {
    /* x64 registers to be saved */
    unsigned long rbx;
    unsigned long rsp;
    unsigned long rbp;
    unsigned long r12;
    unsigned long r13;
    unsigned long r14;
    unsigned long r15;
    unsigned long rip;
} jmp_buf[1];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#endif /* _X64_SETJMP_H */
