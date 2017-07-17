
CC  = clang
CXX = clang++
AS  = nasm
LD  = ld
 

C_SRCS      = $(shell find -name '*.c' ! -path './sys/*' ! -path './test/*' ! -path './stdio/osdep/*' ! -path './stdlib/    malloc.c'  $$C_SRC_SEARCH_EX)
C_TEST_SRC  = $(shell find -name '*.c' -path './test/noos/*' )
CXX_SRCS    = $(shell find -name '*.cpp' ! -path './test/*' ! -path './stdio/*' ! -path './stdlib/malloc.c' $$CXX_SRCS_S    EARCH_EX)
LIBC_PATH   = $(LIBEXT)noos_libc.a
LIBCXX_PATH = $(LIBEXT)noos_libc++.a

