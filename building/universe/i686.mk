
#CC  = gcc
#CXX = g++
#AS  = nasm
#LD  = ld

AS_SRCS    += $(shell find -path './sys/universe/I686/*.asm')
C_SRCS      = $(shell find -name '*.c' ! -path './sys/*' ! -path './test/*' ! -path './stdio/osdep/*' $(C_SRC_SEARCH_EX))
C_SRCS     += $(shell find -path './sys/universe/I686/*.c' )
CFLAGS     += -m32 -Iinclude/sys/universe/I686/
CXXFLAGS   += -m32 -Iinclude/sys/universe/I686/
LIBC_PATH   = $(LIBEXT)universe_libc.a
LIBCXX_PATH = $(LIBEXT)universe_libc++.a
