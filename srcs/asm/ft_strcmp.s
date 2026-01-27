; rax = returned value
; rdi = const char *s1
; rsi = const char *s2

global ft_strcmp
section .text

ft_strcmp:
	mov rcx, 0

.loop:
	mov al, [rdi + rcx]
	mov dl, [rsi + rcx]

	cmp al, dl				; if al != dl -> ZF = 0
	jne .end				; if ZF == 0, jump to end

	test al, al				; check if al == 0 (null terminator) -> ZF = 1
	je .end					; if ZF == 1, jump to end

	inc rcx
	jmp .loop

.end:
	movzx eax, al			 
	movzx edx, dl
	sub eax, edx
	ret

; section .note.GNU-stack noalloc noexec

; MOve with Zero eXtend / copy little value to bigger register, filling high bits with zeros (left side)
; al, dl 8 bits
; eax, edx 32 bits
; strcmp return integer: int
; int don't fit in 8 bits (char), need at least 32 bits (int)