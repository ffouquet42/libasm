global _ft_strlen
section .text

_ft_strlen:
	mov rcx, 0

.loop:
	cmp BYTE [rdi + rcx], 0
	je .end
	inc rcx
	jmp .loop

.end:
	mov rax, rcx
	ret