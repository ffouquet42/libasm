; rax = returned value
; rdi = const char *s

global ft_strlen			; Make function globally accessible
section .text				; Declare text (code) section

ft_strlen:
	mov rcx, 0				; Initialize counter

.loop:
	cmp BYTE [rdi + rcx], 0	; Check for null terminator
	je .end					; If found, exit loop
	inc rcx					; Increment counter	
	jmp .loop

.end:
	mov rax, rcx			; Move counter to rax
	ret						; Return rax

; section .note.GNU-stack noalloc noexec

; cmp update CPU flags (zero flag, sign flag, etc.)
; je (jump if equal) checks the zero flag (jump if ZF == 1)