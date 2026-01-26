global  ft_strdup
extern  ft_strlen
extern  malloc
extern  ft_strcpy

section .text

ft_strdup:
    push    rbx
    sub     rsp, 8
    mov     rbx, rdi
    mov     rdi, rbx
    call    ft_strlen
    inc     rax
    mov     rdi, rax
    call    malloc wrt ..plt
    test    rax, rax
    je      .fail
    mov     rdi, rax
    mov     rsi, rbx
    call    ft_strcpy
    add     rsp, 8
    pop     rbx
    ret

.fail:
    add     rsp, 8
    pop     rbx
    ret