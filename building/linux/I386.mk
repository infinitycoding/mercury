
CC  = gcc
CXX = g++
AS  = nasm
LD  = ld

AS_SRCS    += $(shell find -path './sys/linux/I386/*.asm') 
C_SRCS     += $(shell find -path './sys/linux/I386/*.c')
CFLAGS     += -m32 -Iinclude/linux
CXXFLAGS   += -m32 -Iinclude/linux
LIBC_PATH   = $(LIBEXT)linux_libc.a
LIBCXX_PATH = $(LIBEXT)linux_libc++.a

