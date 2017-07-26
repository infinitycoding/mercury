[BITS 64]

global linux_syscall
linux_syscall:
"push %rcx;"
"push %r11;"
"syscall;"
"pop %%r11;"
"pop %%rcx;"
