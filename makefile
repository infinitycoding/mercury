C_SRCS = $(shell find -name '*.c' ! -path './sys/*')
ASM_SRCS = $(shell find -name '*.asm' ! -path './sys/*')
CPP_SRCS = $(shell find -name '*.cpp')

L_CFLAGS = -m32 -Wall -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -I include
ASFLAGS =-felf32

TARGET=linux

ifeq ($(TARGET), universe)
CC = i686-universe-gcc
CCPP = i686-universe-g++
ASM = nasm
LD = i686-universe-ld

C_SRCS += $(shell find -path './sys/universe/*.c')
ASM_SRCS += $(shell find -path './sys/universe/*.asm')
L_CFLAGS += -I include/universe
LIBC_PATH = universe_libc.a
LIBCPP_PATH = universe_libc++.a

else ifeq ($(TARGET), linux)
CC = gcc
CCPP = g++
ASM = nasm
LD = ld

C_SRCS += $(shell find -path './sys/linux/*.c')
ASM_SRCS += $(shell find -path './sys/linux/*.asm')
L_CFLAGS += -I include/linux
LIBC_PATH = linux_libc.a
LIBCPP_PATH = linux_libc++.a

endif

C_OBJS = $(addsuffix .o,$(basename $(C_SRCS)))
CPP_OBJS = $(addsuffix .o,$(basename $(CPP_SRCS)))
ASM_OBJS = $(addsuffix .o,$(basename $(ASM_SRCS)))

all: $(LIBC_PATH) $(LIBCPP_PATH)

$(LIBC_PATH): $(C_OBJS) $(ASM_OBJS)
	ar -rcs $@ $^

$(LIBCPP_PATH): $(C_OBJS) $(ASM_OBJS) $(CPP_OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^

%.o: %.cpp
	$(CCPP) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $^ 

install: all
	cp -R ./crt/*.o $(PREFIX)/usr/lib/
	cp -R ./include/* $(PREFIX)/usr/include
	cp libc.a $(PREFIX)/usr/lib/

style: $(C_SRCS) $(CPP_SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	rm $(C_OBJS) -f
	rm $(CPP_OBJS) -f
	rm $(ASM_OBJS) -f
	rm $(LIBC_PATH) -f
	rm $(LIBCPP_PATH) -f

.PHONY: clean

