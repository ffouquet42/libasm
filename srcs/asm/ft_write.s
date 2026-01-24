global  ft_write
extern  __errno_location

section .text

ft_write:
    mov     rax, 1
    syscall
    test    rax, rax
    jns     .ok

    mov     edi, eax
    neg     edi

    sub     rsp, 8
    call    __errno_location wrt ..plt
    add     rsp, 8

    mov     dword [rax], edi
    mov     eax, -1
.ok:
    ret
