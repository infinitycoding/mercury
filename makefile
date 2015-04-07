C_SRCS = $(shell find -name '*.c')
SRCS = $(C_SRCS)
SRCS += $(shell find -name '*.asm')

L_CFLAGS = -m32 -Wall -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -I include
ASFLAGS =-felf32

TARGET=linux

ifeq ($(TARGET), universe)
CC = i686-universe-gcc
ASM = nasm
LD = i686-universe-ld

SRCS += $(shell find -path './sys/universe/*.c')
SRCS += $(shell find -path './sys/universe/*.asm')
LIBPATH = universe_libc.a

else ifeq ($(TARGET), linux)
CC = gcc
ASM = nasm
LD = ld

SRCS += $(shell find -path './sys/linux/*.c')
SRCS += $(shell find -path './sys/linux/*.asm')
LIBPATH = linux_libc.a

endif

OBJS = $(addsuffix .o,$(basename $(SRCS)))

all: $(LIBPATH)

$(LIBPATH): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $^ 

install: all
	cp -R ./crt/*.o $(PREFIX)/usr/lib/
	cp -R ./include/* $(PREFIX)/usr/include
	cp libc.a $(PREFIX)/usr/lib/

style: $(C_SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	rm $(OBJS) -f
	rm $(LIBPATH) -f

.PHONY: clean

