/* arch/x86/setjmp.s */

.global setjmp
.global longjmp

setjmp:
    mov [esp+4], ebx      /* Save ebx */
    mov [esp+8], esi      /* Save esi */
    mov [esp+12], edi     /* Save edi */
    mov [esp+16], ebp     /* Save ebp */
    mov [esp+20], esp     /* Save esp */
    mov eax, [esp]        /* Get return address (eip) */
    mov [esp+24], eax     /* Save eip */
    xor eax, eax          /* Return 0 from setjmp */
    ret

longjmp:
    mov ebx, [esp+4]      /* Restore ebx */
    mov esi, [esp+8]      /* Restore esi */
    mov edi, [esp+12]     /* Restore edi */
    mov ebp, [esp+16]     /* Restore ebp */
    mov esp, [esp+20]     /* Restore esp */
    jmp [esp+24]          /* Jump to saved eip */
