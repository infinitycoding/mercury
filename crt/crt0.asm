SECTION .text
extern main
extern environ

global _start
_start:
    mov eax,[esp+8]
    mov [environ],eax
	call main
	mov ebx, eax
	mov eax, 1
	int 0x80
	jmp $

