SRCS = $(shell find -name '*.c')
SRCS += $(shell find -name '*.asm')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

L_CFLAGS = -m32 -Wall -g -nostdinc -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -I include
ASFLAGS =-felf32


CC = i686-universe-gcc
ASM = nasm
LD = i686-universe-ld

install: all
	cp -R ./include/* $(PREFIX)/usr/include
	cp libc.a $(PREFIX)/usr/lib/

all: libc.a

libc.a: $(OBJS)
	@ar -rcs $@ $^

%.o: %.asm
	${ASM} ${ASFLAGS} -o $@ $^

%.o: %.c
	$(CC) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^


style: $(SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	@rm $(OBJS) -f
	@rm libc.a -f

.PHONY: clean

