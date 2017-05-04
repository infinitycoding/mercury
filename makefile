#insert zour target here
TARGET ?= linux
PREFIX ?= /opt/mercury


ifeq ($(noheap),true)
C_SRC_SEARCH_EX       = ! -path './list.c' ! -path './stdlib/malloc.c' ! -path './libgen/*'
CXX_SRCS_SEARCH_EX    = $(C_SRC_SEARCH_EX) ! -path '.cpp/new.cpp'
LIBEXT                =noheap_
endif


C_SRCS      = $(shell find -name '*.c' ! -path './sys/*' ! -path './test/*' $(C_SRC_SEARCH_EX) )
C_TEST_SRC  = $(shell find -name '*.c' -path './test/*' )
AS_SRCS     = $(shell find -name '*.asm' ! -path './sys/*' ! -path './test/*' )
CXX_SRCS    = $(shell find -name '*.cpp' ! -path './test/*' $(CXX_SRCS_SEARCH_EX))

ARFLAGS     = -rcs
ASFLAGS     = -felf32
CFLAGS      = -m32 -Wall -fno-builtin -fno-builtin-log -nostdinc -Iinclude
CXXFLAGS    = -m32 -Wall -fno-builtin -fno-builtin-log -fno-rtti -fno-exceptions -nostdinc -Iinclude/cpp -Iinclude
STYLEFLAGS  = --style=allman

#Operating system switch
#Universe
ifeq ($(TARGET), universe)
CC  = i686-universe-gcc
CXX = i686-universe-g++
AS  = nasm
LD  = i686-universe-ld

AS_SRCS    += $(shell find -path './sys/universe/*.asm')
C_SRCS     += $(shell find -path './sys/universe/*.c')
CFLAGS     += -Iinclude/universe
CXXFLAGS   += -Iinclude/univers
LIBC_PATH   = $(LIBEXT)universe_libc.a
LIBCXX_PATH = $(LIBEXT)universe_libc++.a


#Linux
else ifeq ($(TARGET), linux)
CC  = clang
CXX = clang++
AS  = nasm
LD  = ld

AS_SRCS    += $(shell find -path './sys/linux/*.asm')
C_SRCS     += $(shell find -path './sys/linux/*.c')
CFLAGS     += -Iinclude/linux
CXXFLAGS   += -Iinclude/linux
LIBC_PATH   = $(LIBEXT)linux_libc.a
LIBCXX_PATH = $(LIBEXT)linux_libc++.a


#no operating system
else ifeq ($(TARGET), noos)
CC  = clang
CXX = clang++
AS  = nasm
LD  = ld


C_SRCS      = $(shell find -name '*.c' ! -path './sys/*' ! -path './test/*' ! -path './stdio/osdep/*' ! -path './stdlib/malloc.c'  $$C_SRC_SEARCH_EX)
C_TEST_SRC  = $(shell find -name '*.c' -path './test/noos/*' )
CXX_SRCS    = $(shell find -name '*.cpp' ! -path './test/*' ! -path './stdio/*' ! -path './stdlib/malloc.c' $$CXX_SRCS_SEARCH_EX)
LIBC_PATH   = $(LIBEXT)noos_libc.a
LIBCXX_PATH = $(LIBEXT)noos_libc++.a
endif



AS_OBJS  = $(addsuffix .o,$(basename $(AS_SRCS)))
C_OBJS   = $(addsuffix .o,$(basename $(C_SRCS)))
CXX_OBJS = $(addsuffix .o,$(basename $(CXX_SRCS)))
C_TEST_EXECUTABLES = $(basename $(C_TEST_SRC))


#function for colored output
define cecho
	@[ -t 1 ] && tput setaf $1 && tput bold || true
	@echo $2
	@[ -t 1 ] && tput sgr0 || true
endef


#Targets
all: $(LIBC_PATH) $(LIBCXX_PATH)

$(LIBC_PATH): $(C_OBJS) $(AS_OBJS)
	$(call cecho,2,"--- Create $@ ...")
	@$(AR) $(ARFLAGS) $@ $^

$(LIBCXX_PATH): $(C_OBJS) $(AS_OBJS) $(CXX_OBJS)
	$(call cecho,2,"--- Create $@ ...")
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.asm
	$(call cecho,2,"--- Compiling $< ...")
	@$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(call cecho,2,"--- Compiling $< ...")
	@$(CC) ${CFLAGS} -c -o $@ $<

%.o: %.cpp
	$(call cecho,2,"--- Compiling $< ...")
	@$(CXX) ${CXXFLAGS} -c -o $@ $<

install: all
	$(call cecho,2,"--- Copy binaries to '$(PREFIX)/lib/' ...")
	@mkdir -p "$(PREFIX)/lib"
	@cp ./crt/*.o "$(PREFIX)/lib/"
	@cp "$(LIBC_PATH)" "$(PREFIX)/lib/libc.a"
	@cp "$(LIBCXX_PATH)" "$(PREFIX)/lib/libc++.a"
	$(call cecho,2,"--- Copy includes to '$(PREFIX)/include/' ...")
	@mkdir -p "$(PREFIX)/include"
	@cp -R ./include/* "$(PREFIX)/include/"



$(C_TEST_EXECUTABLES): $(C_TEST_SRC)
			$(call cecho,2,"--- Compiling unit test $< ...")
			$(CC) -nostdlib -nostdinc -m32 -I include/ -O0 -flto -o $@ $< $(LIBC_PATH)
			@chmod +x $(basename $< .c)
			@if [ -a  $(addsuffix .in,$(shell dirname  $<)/$(basename $< .c)) ] ; \
			then \
				./$(basename $< .c)< $(addsuffix .in,$(shell dirname  $<)/$(basename $< .c)) >$(addsuffix .res,$(shell dirname  $<)/$(basename $< .c)) ; \
				@diff $(addsuffix .out,$(shell dirname  $<)/$(basename $< .c)) $(addsuffix .res,$(shell dirname  $<)/$(basename $< .c)) ; \
			else \
			./$(basename $< .c) ; \
			fi;

test: $(C_TEST_EXECUTABLES)
	$(call cecho,2,"--- Testing: done ---")

style: $(C_SRCS) $(CXX_SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	$(RM) $(AS_OBJS)
	$(RM) $(C_OBJS)
	$(RM) $(CXX_OBJS)
	$(RM) $(LIBC_PATH)
	$(RM) $(LIBCXX_PATH)
	$(RM) $(C_TEST_EXECUTABLES)
	$(RM) *_libc.a
	$(RM) *_libc++.a

.PHONY: clean
