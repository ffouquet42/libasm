global  ft_read
extern  __errno_location

section .text

ft_read:
	mov		rax, 0
	syscall
	cmp		rax, 0
	jl		.exit_error
	ret

.exit_error:
	neg		rax
	mov		r8, rax
	call	__errno_location wrt ..plt
	mov		[rax], r8
	mov		rax, -1
	ret