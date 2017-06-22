crt / startup code for usermode applications
========

In this directory are startup modules for usermode programms which are called  by the operating system
before the actual main function of the programm will be started.


crt0
========
This is the minimalistic startup module. It only sets up the enviroment varriable system for the
the rest of the c-library and calls the exit syscall after the main function returns.

boot
========
This is the start up module to boot directly without a operating system and without a bootloader.

multiboot
========
This is the start up module to boot without a operating system from a multiboot compatible bootloader (like Grub)
