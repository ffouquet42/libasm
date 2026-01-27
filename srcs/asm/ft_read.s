; rax = returned value
; rdi = int fd
; rsi = void *buf
; rdx = size_t count

global  ft_read
extern  __errno_location

section .text

ft_read:
	mov rax, 0							; Syscall number for sys_read = 0
	syscall								; Call system read with parameters in rdi, rsi, rdx
										; After syscall, rax contains number of bytes read or error code (negative)
	cmp rax, 0
	jl .error_handling
	ret

.error_handling:
	neg rax

	mov r8d, eax
	call __errno_location wrt ..plt
	mov dword [rax], r8d

	mov rax, -1
	ret

; section .note.GNU-stack noalloc noexec