SECTION .bss
global environ
environ: resb 4

SECTION .text
extern main

global _start
_start:
    mov eax,[esp+8]
    mov [environ],eax
	call main
	mov ebx, eax
	mov eax, 1
	int 0x80
	jmp $
