global ft_strcpy
section .text

ft_strcpy:
	mov rcx, 0

.loop:
	cmp BYTE [rsi + rcx], 0
	je .end
	mov al, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], al
	inc rcx
	jmp .loop

.end:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	mov rax, rdi
	ret