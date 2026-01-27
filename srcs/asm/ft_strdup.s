; rax = returned value
; rdi = const char *str

global  ft_strdup

extern  ft_strlen
extern  malloc
extern  ft_strcpy

section .text

ft_strdup:
    push rbx					; non-volatile register, save original value on stack
    mov rbx, rdi				; stock str in rbx (non-volatile register) because rdi will be erased by calls

    call ft_strlen				; rax = strlen(str)
    inc rax						; + 1 for null byte

    mov rdi, rax				; put size to malloc in rdi (first argument)
    call malloc wrt ..plt		; rax = ptr if malloc success, 0 if fail

    test rax, rax				; check if malloc fail (rax == 0) (ZF = 1)
    je .malloc_fail				; jump if malloc fail (ZF == 1)

    mov rdi, rax				; setup dest for strcpy (malloc ptr)
    mov rsi, rbx				; setup src for strcpy (original str)
    call ft_strcpy				; rax = dest (malloc ptr)

    pop rbx						; restore original value of rbx
    ret							; return malloc ptr

.malloc_fail:
    pop rbx						; restore original value of rbx
    ret							; return 0

; section .note.GNU-stack noalloc noexec

; This function makes several calls I need a non-volatile register to keep a value across calls (rbx)
; I cannot know if it is already used, I save original value on the stack, use it as a local variable, then restore it