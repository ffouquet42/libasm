; rax = returned value (can be value or address pointer (64 bits = 8 bytes))
; rdi = char *dest (64 bits address pointer (8 bytes))
; rsi = const char *src (64 bits address pointer (8 bytes))

global ft_strcpy
section .text

ft_strcpy:
	mov rcx, 0

.loop:
	cmp BYTE [rsi + rcx], 0
	je .end
	mov al, [rsi + rcx]			; al = 8 bits = 1 byte = 1 char
	mov [rdi + rcx], al
	inc rcx
	jmp .loop

.end:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	mov rax, rdi
	ret

; section .note.GNU-stack noalloc noexec