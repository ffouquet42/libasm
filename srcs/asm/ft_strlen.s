; rax = returned value
; rdi = const char *s

global ft_strlen			; Make function globally accessible
section .text				; Declare text (code) section

ft_strlen:					; Function entry point
	mov rcx, 0				; Initialize counter

.loop:						; Start of loop
	cmp BYTE [rdi + rcx], 0	; Check for null terminator
	je .end					; If found, exit loop
	inc rcx					; Increment counter	
	jmp .loop				; Repeat

.end:
	mov rax, rcx			; Move counter to rax
	ret						; Return

; section .note.GNU-stack noalloc noexec