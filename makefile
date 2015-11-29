C_SRCS   = $(shell find -name '*.c' ! -path './sys/*')
AS_SRCS  = $(shell find -name '*.asm' ! -path './sys/*')
CXX_SRCS = $(shell find -name '*.cpp')

ARFLAGS   = -rcs
ASFLAGS   = -felf32
CFLAGS   += -m32 -Wall -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -Iinclude
CXXFLAGS += -m32 -Wall -fno-stack-protector -fno-builtin -fno-builtin-log -fno-rtti -fno-exceptions -nostdinc -Iinclude/cpp -Iinclude

TARGET ?= linux
PREFIX ?= /opt/mercury

ifeq ($(TARGET), universe)

CC  = i686-universe-gcc
CXX = i686-universe-g++
AS  = nasm
LD  = i686-universe-ld

AS_SRCS += $(shell find -path './sys/universe/*.asm')
C_SRCS  += $(shell find -path './sys/universe/*.c')
CFLAGS   += -Iinclude/universe
CXXFLAGS += -Iinclude/univers
LIBC_PATH   = universe_libc.a
LIBCXX_PATH = universe_libc++.a

else ifeq ($(TARGET), linux)

CC  = gcc
CXX = g++
AS  = nasm
LD  = ld

AS_SRCS += $(shell find -path './sys/linux/*.asm')
C_SRCS  += $(shell find -path './sys/linux/*.c')
CFLAGS   += -Iinclude/linux
CXXFLAGS += -Iinclude/linux
LIBC_PATH   = linux_libc.a
LIBCXX_PATH = linux_libc++.a

endif

AS_OBJS  = $(addsuffix .o,$(basename $(AS_SRCS)))
C_OBJS   = $(addsuffix .o,$(basename $(C_SRCS)))
CXX_OBJS = $(addsuffix .o,$(basename $(CXX_SRCS)))

define cecho
	@[ -t 1 ] && tput setaf $1 && tput bold || true
	@echo $2
	@[ -t 1 ] && tput sgr0 || true
endef


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

style: $(C_SRCS) $(CXX_SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	$(RM) $(AS_OBJS)
	$(RM) $(C_OBJS)
	$(RM) $(CXX_OBJS)
	$(RM) $(LIBC_PATH)
	$(RM) $(LIBCXX_PATH)

.PHONY: clean
