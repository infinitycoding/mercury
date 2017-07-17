SECTION .bss
global environ
environ: resb 4

SECTION .text
extern main

global _start
_start:
    pop rdi
    pop rsi
    mov rax
    mov [environ],rdx
	call main
	mov rbx, rax
	mov rax, 1
  syscall
hlt
