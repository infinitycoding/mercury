
CC  = gcc
CXX = g++
AS  = nasm
LD  = ld

AS_SRCS    += $(shell find -path './sys/linux/AMD64/*.asm')
C_SRCS     += $(shell find -path './sys/linux/AMD64/*.c')
CFLAGS     += -Iinclude/sys/linux/AMD64/
CXXFLAGS   += -Iinclude/sys/linux/AMD64/
LIBC_PATH   = $(LIBEXT)linux_libc.a
LIBCXX_PATH = $(LIBEXT)linux_libc++.a
