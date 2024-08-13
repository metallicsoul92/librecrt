/* arch/x86/setjmp.h */

#ifndef _X86_SETJMP_H
#define _X86_SETJMP_H

typedef struct {
    /* x86 registers to be saved */
    unsigned int ebx;
    unsigned int esi;
    unsigned int edi;
    unsigned int ebp;
    unsigned int esp;
    unsigned int eip;
} jmp_buf[1];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#endif /* _X86_SETJMP_H */
