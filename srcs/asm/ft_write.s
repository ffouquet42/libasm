global  ft_write
extern  __errno_location

section .text

ft_write:
    mov rax, 1
    syscall

	cmp rax, 0
	jl .exit_error
	ret

.exit_error:
	neg rax
	mov r8, rax
	call __errno_location wrt ..plt
	mov [rax], r8
	mov rax, -1
	ret