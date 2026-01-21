global ft_strlen			;
section .text				;

ft_strlen:					;
	mov rcx, 0				; copy 0 in rcx			| int i = 0

.loop:						;
	cmp BYTE [rdi + rcx], 0	; rdi = arg (str)		| if str[0 + i] == '\0'
	je .end					; jump if equal			| break the loop
	inc rcx					; increment				| i++
	jmp .loop				; jump					| loop again

.end:						;
	mov rax, rcx			; rax = returned value	| rax = i
	ret						; return rax