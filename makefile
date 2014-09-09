SRCS = $(shell find -name '*.c')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

L_CFLAGS = -m32 -Wall -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -I include
ASFLAGS =-felf32


CC = i686-universe-gcc
ASM = nasm
LD = i686-universe-ld

install: all
	cp -R ./crt/*.o $(PREFIX)/usr/lib/	
	cp -R ./include/* $(PREFIX)/usr/include
	cp libc.a $(PREFIX)/usr/lib/

all: libc.a
	${ASM} ${ASFLAGS} -o crt/crt0.o crt/crt0.asm 

libc.a: $(OBJS)
	@ar -rcs $@ $^

%.o: %.c
	$(CC) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^


style: $(SRCS)
	astyle $(STYLEFLAGS) $^

clean:
	@rm $(OBJS) -f
	@rm libc.a -f

.PHONY: clean

