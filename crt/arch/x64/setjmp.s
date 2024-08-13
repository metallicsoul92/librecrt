/* arch/x64/setjmp.s */

.global setjmp
.global longjmp

setjmp:
    mov [rdi], rbx        /* Save rbx */
    mov [rdi+8], rsp      /* Save rsp */
    mov [rdi+16], rbp     /* Save rbp */
    mov [rdi+24], r12     /* Save r12 */
    mov [rdi+32], r13     /* Save r13 */
    mov [rdi+40], r14     /* Save r14 */
    mov [rdi+48], r15     /* Save r15 */
    mov [rdi+56], [rsp]   /* Save rip */
    xor eax, eax          /* Return 0 from setjmp */
    ret

longjmp:
    mov rbx, [rdi]        /* Restore rbx */
    mov rsp, [rdi+8]      /* Restore rsp */
    mov rbp, [rdi+16]     /* Restore rbp */
    mov r12, [rdi+24]     /* Restore r12 */
    mov r13, [rdi+32]     /* Restore r13 */
    mov r14, [rdi+40]     /* Restore r14 */
    mov r15, [rdi+48]     /* Restore r15 */
    jmp [rdi+56]          /* Jump to saved rip */
