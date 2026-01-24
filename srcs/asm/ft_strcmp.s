global ft_strcmp
section .text

ft_strcmp:
	mov rcx, 0

.loop:
	mov al, BYTE [rdi + rcx]
	mov dl, BYTE [rsi + rcx]

	cmp al, dl
	jne .end

	test al, al
	je .end

	inc rcx
	jmp .loop

.end:
	movzx eax, al
	movzx edx, dl
	sub eax, edx
	ret