; rax = returned value
; rdi = int fd
; rsi = const void *buf
; rdx = size_t count

global  ft_write
extern  __errno_location				; Permit to access C errno variable

section .text

ft_write:
    mov rax, 1							; Syscall number for sys_write = 1
    syscall								; Call system write with parameters in rdi, rsi, rdx
										; After syscall, rax contains number of bytes written or error code (negative)
	cmp rax, 0							; virtual subtraction to set CPU flags (rax = 0 -> ZF = 1 ; rax < 0 -> SF = 1)
	jl .error_handling					; Jump if rax < 0 (negative value) to error handling
	ret									; Return with rax containing number of bytes written

.error_handling:
	neg rax								; Negate rax to get positive error code because errno uses positive values

	mov r8d, eax						; move errno from eax (32 bits from rax) to r8d (free 32 bits register)
	call __errno_location wrt ..plt		; rax = address of errno
	mov dword [rax], r8d				; errno code stored in adress pointed by rax (errno in C)
										; dword = 32 bits, need to precise because rax is 64 bits
	mov rax, -1							; Set return value to -1 to indicate error
	ret

; section .note.GNU-stack noalloc noexec